// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Spline.h"

#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Kismet/KismetMathLibrary.h"

void AOmegaSplineActor::L_SetupMeshComp(UInstancedStaticMeshComponent* comp)
{
    if(comp && Spline)
    {
        comp->SetupAttachment(Spline);
        comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        comp->CastShadow=false;
        comp->bHiddenInGame=true;
    }
}

AOmegaSplineActor::AOmegaSplineActor()
{
    Spline=CreateDefaultSubobject<USplineComponent>("Spline");
    RootComponent=Spline;
    DisplayPoint=CreateOptionalDefaultSubobject<UInstancedStaticMeshComponent>("Display Point");
    L_SetupMeshComp(DisplayPoint);
    DisplayLine=CreateOptionalDefaultSubobject<UInstancedStaticMeshComponent>("Display Line");
    L_SetupMeshComp(DisplayLine);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MatRef(TEXT("/OmegaGameFramework/Meshes/util/OmegaMesh_Sphere.OmegaMesh_Sphere"));
    DisplayPoint->SetStaticMesh(MatRef.Object);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MatBRef(TEXT("/OmegaGameFramework/Meshes/util/OmegaMesh_Pointer.OmegaMesh_Pointer"));
    DisplayLine->SetStaticMesh(MatBRef.Object);
    static ConstructorHelpers::FObjectFinder<UMaterial> nmat_ref(TEXT("/OmegaGameFramework/Materials/Instances/Flats/M_Flat.M_Flat"));
    DynaMat=UKismetMaterialLibrary::CreateDynamicMaterialInstance(this,nmat_ref.Object);
    DisplayLine->bIsEditorOnly=true;
    DisplayPoint->bIsEditorOnly=true;
}

void AOmegaSplineActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    if(Spline && DisplayLine && DisplayPoint)
    {
        DisplayLine->ClearInstances();
        DisplayPoint->ClearInstances();
        DisplayLine->SetMaterial(0,DynaMat);
        DisplayPoint->SetMaterial(0,DynaMat);
        DisplayPoint->SetColorParameterValueOnMaterials("Color",PointColor);
        int32 _points=UKismetMathLibrary::FTrunc(Spline->GetSplineLength()/PointDistance);

        for (int i = 0; i < Spline->GetNumberOfSplinePoints(); ++i)
        {
            FTransform T;
            T.SetLocation(Spline->GetLocationAtSplinePoint(i,ESplineCoordinateSpace::Local));
            DisplayPoint->AddInstance(T);
        }
        
        for (int i = 0; i < _points; ++i)
        {
            float new_dis=i*PointDistance;
            float next_dis=(1+i)*PointDistance;
            FVector loc_0=Spline->GetLocationAtDistanceAlongSpline(new_dis,ESplineCoordinateSpace::Local);
            FVector loc_1=Spline->GetLocationAtDistanceAlongSpline(next_dis,ESplineCoordinateSpace::Local);
            FTransform T;
            T.SetLocation(loc_0);
            FRotator rot=UKismetMathLibrary::FindLookAtRotation(loc_0,loc_1);
            T.SetRotation(rot.Quaternion());
            DisplayLine->AddInstance(T);
        }

    }
}
