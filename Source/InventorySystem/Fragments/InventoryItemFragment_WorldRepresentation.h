// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemFragment.h"
#include "InventoryItemFragment_WorldRepresentation.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInventoryItemFragment_WorldRepresentation : public UInventoryItemFragment
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, blueprintReadOnly, Category = "Mesh")
	TObjectPtr<UStaticMesh> ItemMesh;
	
	UPROPERTY(EditDefaultsOnly, blueprintReadOnly, Category = "Options")
	bool bCanBeDropped = true;
};
