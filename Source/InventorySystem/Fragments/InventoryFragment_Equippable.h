// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemFragment.h"
#include "InventorySystem/Equipment/EquipmentDefinition.h"
#include "InventoryFragment_Equippable.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInventoryFragment_Equippable : public UInventoryItemFragment
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, blueprintReadOnly, Category = "Mesh")
	TSubclassOf<UEquipmentDefinition> EquipmentDefinition;
};
