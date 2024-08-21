// .h 

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Name") FText DisplayName;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Icon") FSlateBrush DisplayIcon;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Description",meta=(MultiLine)) FText DisplayDescription;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Label") FString DisplayLabel;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Category") FGameplayTag CategoryTag;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="General",DisplayName="Tags") FGameplayTagContainer GameplayTags;
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;



// .cpp

FGameplayTag UOmegaAnimationEmote::GetObjectGameplayCategory_Implementation() { return CategoryTag; }
FGameplayTagContainer UOmegaAnimationEmote::GetObjectGameplayTags_Implementation() { return GameplayTags; }
void UOmegaAnimationEmote::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description) { Name=DisplayName; Description=DisplayDescription; }
void UOmegaAnimationEmote::GetGeneralAssetLabel_Implementation(FString& Label) { Label=DisplayLabel; }
void UOmegaAnimationEmote::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) { Brush=DisplayIcon; }
