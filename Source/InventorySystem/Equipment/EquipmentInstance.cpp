// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InventorySystem/Fragments/Inventoryfragment_Equippable.h"

void UEquipmentInstance::Initialize(UItemInstance* ItemInstance, ACharacter* Character)
{
	if (!ItemInstance) return;

	SourceItemInstance = ItemInstance;

	const UInventoryFragment_Equippable* EquippableFragment = Cast<UInventoryFragment_Equippable>(
		ItemInstance->FindFragmentByClass(UInventoryFragment_Equippable::StaticClass()));

	if (!EquippableFragment) return;

	EquipmentDefinition = EquippableFragment->EquipmentDefinition;

	HandleEquipItem(Character);
}

void UEquipmentInstance::HandleEquipItem(ACharacter* Character)
{
	UEquipmentDefinition* DefinitionCDO = EquipmentDefinition.GetDefaultObject();

	if (!DefinitionCDO) return;

	SpawnedEquipmentActor = GetWorld()->SpawnActor(DefinitionCDO->EquipmentActorClass);

	if (!SpawnedEquipmentActor) return;

	SpawnedEquipmentActor->AttachToComponent(
		Character->GetMesh(),
		FAttachmentTransformRules::SnapToTargetIncludingScale,
		DefinitionCDO->AttachSocketName
	);

	float MovementSpeedIncrease = SourceItemInstance->GetStatValue(
		FGameplayTag::RequestGameplayTag(FName("Item.Stat.MovementSpeed")));
	float ArmorIncrease = SourceItemInstance->GetStatValue(
		FGameplayTag::RequestGameplayTag(FName("Item.Stat.Armor")));
	float StrengthIncrease = SourceItemInstance->GetStatValue(
		FGameplayTag::RequestGameplayTag(FName("Item.Stat.Strength")));

	Character->GetCharacterMovement()->MaxWalkSpeed += MovementSpeedIncrease;
}

void UEquipmentInstance::HandleUnEquipItem(ACharacter* Character)
{
	if (SpawnedEquipmentActor)
	{
		SpawnedEquipmentActor->Destroy();
		SpawnedEquipmentActor = nullptr;
	}
	
	float MovementSpeedIncrease = SourceItemInstance->GetStatValue(
	FGameplayTag::RequestGameplayTag(FName("Item.Stat.MovementSpeed")));

	Character->GetCharacterMovement()->MaxWalkSpeed -= MovementSpeedIncrease;
}
