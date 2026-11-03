// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "ItemDefinition.generated.h"


class UInventoryItemFragment;

UENUM(NotBlueprintType)
enum class EItemRarity : uint8
{
	None,
	Common,
	Uncommon,
	Rare,
	Epic,
	Legendary
};

/**
 * 
 */
UCLASS(Blueprintable, blueprintType, abstract, Const)
class INVENTORYSYSTEM_API UItemDefinition : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, blueprintReadOnly, Category = "Display")
	FText ItemName;

	UPROPERTY(EditDefaultsOnly, blueprintReadOnly, Category = "Display")
	FText ItemDescription;

	UPROPERTY(EditDefaultsOnly, blueprintReadOnly, Category = "Display")
	TObjectPtr<UTexture2D> ItemIcon;
	
	UPROPERTY(EditDefaultsOnly, blueprintReadOnly, Category = "Display")
	EItemRarity Rarity = EItemRarity::None;
	
	UPROPERTY(EditDefaultsOnly, blueprintReadOnly, Category = "Display")
	FGameplayTagContainer ItemType;

	UPROPERTY(EditDefaultsOnly, blueprintReadOnly, Instanced, Category = "Fragments Array")
	TArray<TObjectPtr<UInventoryItemFragment>> Fragments;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DeterminesOutputType = "FragmentClass"))
	static const UInventoryItemFragment* FindFragmentByClass(const TSubclassOf<UItemDefinition> ItemDefinition,
	                                                         const TSubclassOf<UInventoryItemFragment> FragmentClass);
};
