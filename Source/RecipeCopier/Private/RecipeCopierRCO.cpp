﻿#include "RecipeCopierRCO.h"
#include "RecipeCopierEquipment.h"
#include "Logic/RecipeCopierLogic.h"
#include "Util/Optimize.h"

#include "FGPlayerController.h"

#ifndef OPTIMIZE
#pragma optimize( "", off )
#endif

void URecipeCopierRCO::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(URecipeCopierRCO, dummy);
}

URecipeCopierRCO* URecipeCopierRCO::getRCO(UWorld* world)
{
	return Cast<URecipeCopierRCO>(
		Cast<AFGPlayerController>(world->GetFirstPlayerController())->GetRemoteCallObjectOfClass(URecipeCopierRCO::StaticClass())
		);
}

void URecipeCopierRCO::ApplyFactoryInfo_Implementation
(
	class AFGBuildableFactory* factory,
	TSubclassOf<UFGRecipe> recipe,
	float overclock,
	ERecipeCopyMode copyMode,
	class AFGCharacterPlayer* player,
	class ARecipeCopierEquipment* copier
)
{
	if (!factory->HasAuthority())
	{
		return;
	}

	ARecipeCopierLogic::ApplyFactoryInfo_Server(
		factory,
		recipe,
		overclock,
		copyMode,
		player,
		copier
		);
}

bool URecipeCopierRCO::ApplyFactoryInfo_Validate
(
	class AFGBuildableFactory* factory,
	TSubclassOf<UFGRecipe> recipe,
	float selectedOverclock,
	ERecipeCopyMode copyMode,
	class AFGCharacterPlayer* player,
	class ARecipeCopierEquipment* copier
)
{
	return true;
}

void URecipeCopierRCO::MoveItems_Implementation
(
	UFGInventoryComponent* sourceInventoryComponent,
	UFGInventoryComponent* targetInventoryComponent,
	TSubclassOf<UFGItemDescriptor> item,
	int amount,
	bool dropExcess,
	AFGCharacterPlayer* player
)
{
	ARecipeCopierLogic::MoveItems_Server(
		sourceInventoryComponent,
		targetInventoryComponent,
		item,
		amount,
		dropExcess,
		player
		);
}

bool URecipeCopierRCO::MoveItems_Validate
(
	UFGInventoryComponent* sourceInventoryComponent,
	UFGInventoryComponent* targetInventoryComponent,
	TSubclassOf<UFGItemDescriptor> item,
	int amount,
	bool dropExcess,
	AFGCharacterPlayer* player
)
{
	return true;
}

void URecipeCopierRCO::ApplySmartSplitterInfo_Implementation
(
	class AFGBuildableSplitterSmart* smartSplitter,
	const TArray<FSplitterSortRule>& splitterRules,
	class AFGCharacterPlayer* player,
	class ARecipeCopierEquipment* copier
)
{
	ARecipeCopierLogic::ApplySmartSplitterInfo_Server(
		smartSplitter,
		splitterRules,
		player,
		copier
		);
}

bool URecipeCopierRCO::ApplySmartSplitterInfo_Validate
(
	class AFGBuildableSplitterSmart* smartSplitter,
	const TArray<FSplitterSortRule>& splitterRules,
	class AFGCharacterPlayer* player,
	class ARecipeCopierEquipment* copier
)
{
	return true;
}

void URecipeCopierRCO::ApplyTrainInfo_Implementation
(
	AFGTrain* train,
	const TArray<FTimeTableStop>& trainStops,
	AFGCharacterPlayer* player,
	ARecipeCopierEquipment* copier
)
{
	ARecipeCopierLogic::ApplyTrainInfo_Server(
		train,
		trainStops,
		player,
		copier
		);
}

bool URecipeCopierRCO::ApplyTrainInfo_Validate
(
	AFGTrain* train,
	const TArray<FTimeTableStop>& trainStops,
	AFGCharacterPlayer* player,
	ARecipeCopierEquipment* copier
)
{
	return true;
}

void URecipeCopierRCO::ApplyWidgetSignInfo_Implementation
(
	AFGBuildableWidgetSign* widgetSign,
	const FLinearColor& foregroundColor,
	const FLinearColor& backgroundColor,
	const FLinearColor& auxiliaryColor,
	float emissive,
	float glossiness,
	const TMap<FString, FString>& texts,
	const TMap<FString, int32>& iconIds,
	TSubclassOf<class UFGSignPrefabWidget> prefabLayout,
	TSubclassOf<class UFGSignTypeDescriptor> signTypeDesc,
	int32 signCopyMode,
	AFGCharacterPlayer* player,
	ARecipeCopierEquipment* copier
)
{
	ARecipeCopierLogic::ApplyWidgetSignInfo_Server(
		widgetSign,
		foregroundColor,
		backgroundColor,
		auxiliaryColor,
		emissive,
		glossiness,
		texts,
		iconIds,
		prefabLayout,
		signTypeDesc,
		signCopyMode,
		player,
		copier
		);
}

bool URecipeCopierRCO::ApplyWidgetSignInfo_Validate
(
	AFGBuildableWidgetSign* widgetSign,
	const FLinearColor& foregroundColor,
	const FLinearColor& backgroundColor,
	const FLinearColor& auxiliaryColor,
	float emissive,
	float glossiness,
	const TMap<FString, FString>& texts,
	const TMap<FString, int32>& iconIds,
	TSubclassOf<class UFGSignPrefabWidget> prefabLayout,
	TSubclassOf<class UFGSignTypeDescriptor> signTypeDesc,
	int32 signCopyMode,
	AFGCharacterPlayer* player,
	ARecipeCopierEquipment* copier
)
{
	return true;
}

void URecipeCopierRCO::ApplyLightsControlPanel_Implementation
(
	AFGBuildableLightsControlPanel* lightsControlPanel,
	const FLightSourceControlData& lightSourceControlData,
	bool isLightEnabled,
	AFGCharacterPlayer* player,
	ARecipeCopierEquipment* copier
)
{
	ARecipeCopierLogic::ApplyLightsControlPanel_Server(
		lightsControlPanel,
		lightSourceControlData,
		isLightEnabled,
		player,
		copier
		);
}

bool URecipeCopierRCO::ApplyLightsControlPanel_Validate
(
	AFGBuildableLightsControlPanel* lightsControlPanel,
	const FLightSourceControlData& lightSourceControlData,
	bool isLightEnabled,
	AFGCharacterPlayer* player,
	ARecipeCopierEquipment* copier
)
{
	return true;
}

void URecipeCopierRCO::ApplyValve_Implementation
(
	AFGBuildablePipelinePump* valve,
	float userFlowLimit,
	AFGCharacterPlayer* player,
	ARecipeCopierEquipment* copier
)
{
	ARecipeCopierLogic::ApplyValve_Server(
		valve,
		userFlowLimit,
		player,
		copier
		);
}

bool URecipeCopierRCO::ApplyValve_Validate
(
	AFGBuildablePipelinePump* valve,
	float userFlowLimit,
	AFGCharacterPlayer* player,
	ARecipeCopierEquipment* copier
)
{
	return true;
}

#ifndef OPTIMIZE
#pragma optimize( "", on )
#endif
