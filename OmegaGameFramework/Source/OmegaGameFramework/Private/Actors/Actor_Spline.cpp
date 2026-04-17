// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Spline.h"

#include "GeometryScript/MeshBooleanFunctions.h"
#include "Components/DynamicMeshComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Functions/F_DynamicMesh.h"
#include "Functions/F_Spline.h"
#include "Materials/MaterialInterface.h"
#include "GeometryScript/CollisionFunctions.h"
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
    if(Spline && DisplayLine && DisplayPoint && bDrawPreviewPoints)
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

AOmega_DynamicMesh_SplineBlock::AOmega_DynamicMesh_SplineBlock()
{
    bDrawPreviewPoints=false;
    DynamicMeshComponent=CreateOptionalDefaultSubobject<UDynamicMeshComponent>("DynaMesh");
    DynamicMeshComponent->SetupAttachment(RootComponent);
    if (UMaterialInterface* umat=LoadObject<UMaterialInterface>(this,TEXT("/OmegaGameFramework/Materials/Instances/Blocking/mi_OmegaBlock_World.mi_OmegaBlock_World")))
    {
        MeshblockMaterial=umat;
    }
}

void AOmega_DynamicMesh_SplineBlock::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    
    RebuildMesh();
    RebuildCollision();
}

void AOmega_DynamicMesh_SplineBlock::BeginPlay()
{
    Super::BeginPlay();
    RebuildCollision();
}

void AOmega_DynamicMesh_SplineBlock::RebuildCollision()
{
    DynamicMeshComponent->UpdateCollision();
    if (bIsBoolean)
    {
        FGeometryScriptCollisionFromMeshOptions opts;
        opts.Method=EGeometryScriptCollisionGenerationMethod::ConvexHulls;
        opts.ConvexHullTargetFaceCount=1000;
        UGeometryScriptLibrary_CollisionFunctions::SetDynamicMeshCollisionFromMesh(DynamicMeshComponent->GetDynamicMesh(),DynamicMeshComponent,opts);
    }
    else
    {
        
    }
}

void AOmega_DynamicMesh_SplineBlock::RebuildMesh()
{
    FTransform tempTransform;
    FGeometryScriptPrimitiveOptions GeoOptions;
    
    UMaterialInterface* in_mat=MeshblockMaterial;
    
    if (bIsBoolean)
    {
        SetActorHiddenInGame(true);
        DynamicMeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
        if (UMaterialInterface* umat=LoadObject<UMaterialInterface>(this,TEXT("/OmegaGameFramework/Materials/m_trans.m_trans")))
        {
            in_mat=umat;
        }
    }
    else
    {
        SetActorHiddenInGame(false);
        DynamicMeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);   
    }
    
    if (in_mat)
    {
        DynamicMeshComponent->SetMaterial(0,in_mat);
        
    }
    
    DynamicMeshComponent->GetDynamicMesh()->Reset();
    UOmegaFunctions_DynamicMesh::BuildAlongSpline(DynamicMeshComponent->GetDynamicMesh(),Spline,tempTransform,MeshblockHeight,GeoOptions);
    
    if(Spline)
    {
        Spline->SetClosedLoop(bClosedLoop);
        UOmegaFunctions_Spline::ClampTangents(Spline,ClampSplineRange*-1,ClampSplineRange);
    };
    
    if (bIsBoolean)
    {
        for (auto* b : Boolean_Targets)
        {
            FGeometryScriptMeshBooleanOptions _Options; 
            if (b)
            {
                b->RebuildMesh();
                UGeometryScriptLibrary_MeshBooleanFunctions::ApplyMeshBoolean(b->DynamicMeshComponent->GetDynamicMesh(),b->DynamicMeshComponent->GetComponentTransform(),
                    DynamicMeshComponent->GetDynamicMesh(),DynamicMeshComponent->GetComponentTransform(),
                    EGeometryScriptBooleanOperation::Subtract,
                    _Options);
            }
        }
    };
}
