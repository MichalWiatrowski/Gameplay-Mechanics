// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayMechanics/GameplayMechanicsCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameplayMechanicsCharacter() {}
// Cross Module References
	GAMEPLAYMECHANICS_API UClass* Z_Construct_UClass_AGameplayMechanicsCharacter_NoRegister();
	GAMEPLAYMECHANICS_API UClass* Z_Construct_UClass_AGameplayMechanicsCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_GameplayMechanics();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	void AGameplayMechanicsCharacter::StaticRegisterNativesAGameplayMechanicsCharacter()
	{
	}
	UClass* Z_Construct_UClass_AGameplayMechanicsCharacter_NoRegister()
	{
		return AGameplayMechanicsCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AGameplayMechanicsCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ArrowOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ArrowOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_chargeSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_chargeSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_maxVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_maxVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_minVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_minVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_sonicTimer_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_sonicTimer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_sonicArrowCooldown_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_sonicArrowCooldown;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_scatterTimer_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_scatterTimer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_scatterArrowCooldown_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_scatterArrowCooldown;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_currentArrowsAmmo_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_currentArrowsAmmo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_maxArrowsAmmo_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_maxArrowsAmmo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_sonicArrowMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_sonicArrowMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_scatterArrowMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_scatterArrowMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_standardArrowMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_standardArrowMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_arrowMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_arrowMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bowMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_bowMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FirstPersonCameraComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FirstPersonCameraComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayMechanics,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "GameplayMechanicsCharacter.h" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_ArrowOffset_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
		{ "ToolTip", "Gun muzzle's offset from the characters location" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_ArrowOffset = { UE4CodeGen_Private::EPropertyClass::Struct, "ArrowOffset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, ArrowOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_ArrowOffset_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_ArrowOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_BaseLookUpRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
		{ "ToolTip", "Base look up/down rate, in deg/sec. Other scaling may affect final rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_BaseLookUpRate = { UE4CodeGen_Private::EPropertyClass::Float, "BaseLookUpRate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000020015, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, BaseLookUpRate), METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_BaseLookUpRate_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_BaseLookUpRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_BaseTurnRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_BaseTurnRate = { UE4CodeGen_Private::EPropertyClass::Float, "BaseTurnRate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000020015, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, BaseTurnRate), METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_BaseTurnRate_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_BaseTurnRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_chargeSpeed_MetaData[] = {
		{ "Category", "Custom Settings | Archer Settings" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_chargeSpeed = { UE4CodeGen_Private::EPropertyClass::Float, "chargeSpeed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, chargeSpeed), METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_chargeSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_chargeSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_maxVelocity_MetaData[] = {
		{ "Category", "Custom Settings | Archer Settings" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_maxVelocity = { UE4CodeGen_Private::EPropertyClass::Float, "maxVelocity", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, maxVelocity), METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_maxVelocity_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_maxVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_minVelocity_MetaData[] = {
		{ "Category", "Custom Settings | Archer Settings" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_minVelocity = { UE4CodeGen_Private::EPropertyClass::Float, "minVelocity", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, minVelocity), METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_minVelocity_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_minVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicTimer_MetaData[] = {
		{ "Category", "Custom Settings | ArrowTypes | Sonic Arrow" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicTimer = { UE4CodeGen_Private::EPropertyClass::Float, "sonicTimer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000020015, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, sonicTimer), METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicTimer_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicTimer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicArrowCooldown_MetaData[] = {
		{ "Category", "Custom Settings | ArrowTypes | Sonic Arrow" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicArrowCooldown = { UE4CodeGen_Private::EPropertyClass::Float, "sonicArrowCooldown", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, sonicArrowCooldown), METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicArrowCooldown_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicArrowCooldown_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterTimer_MetaData[] = {
		{ "Category", "Custom Settings | ArrowTypes | Scatter Arrow" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterTimer = { UE4CodeGen_Private::EPropertyClass::Float, "scatterTimer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000020015, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, scatterTimer), METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterTimer_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterTimer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterArrowCooldown_MetaData[] = {
		{ "Category", "Custom Settings | ArrowTypes | Scatter Arrow" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterArrowCooldown = { UE4CodeGen_Private::EPropertyClass::Float, "scatterArrowCooldown", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, scatterArrowCooldown), METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterArrowCooldown_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterArrowCooldown_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_currentArrowsAmmo_MetaData[] = {
		{ "Category", "Custom Settings | ArrowTypes | Standard Arrow" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_currentArrowsAmmo = { UE4CodeGen_Private::EPropertyClass::Int, "currentArrowsAmmo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000020015, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, currentArrowsAmmo), METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_currentArrowsAmmo_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_currentArrowsAmmo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_maxArrowsAmmo_MetaData[] = {
		{ "Category", "Custom Settings | ArrowTypes | Standard Arrow" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_maxArrowsAmmo = { UE4CodeGen_Private::EPropertyClass::Int, "maxArrowsAmmo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, maxArrowsAmmo), METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_maxArrowsAmmo_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_maxArrowsAmmo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicArrowMaterial_MetaData[] = {
		{ "Category", "Custom Settings | ArrowTypes | Sonic Arrow" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicArrowMaterial = { UE4CodeGen_Private::EPropertyClass::Object, "sonicArrowMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, sonicArrowMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicArrowMaterial_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicArrowMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterArrowMaterial_MetaData[] = {
		{ "Category", "Custom Settings | ArrowTypes | Scatter Arrow" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterArrowMaterial = { UE4CodeGen_Private::EPropertyClass::Object, "scatterArrowMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, scatterArrowMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterArrowMaterial_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterArrowMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_standardArrowMaterial_MetaData[] = {
		{ "Category", "Custom Settings | ArrowTypes | Standard Arrow" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_standardArrowMaterial = { UE4CodeGen_Private::EPropertyClass::Object, "standardArrowMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, standardArrowMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_standardArrowMaterial_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_standardArrowMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_arrowMesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_arrowMesh = { UE4CodeGen_Private::EPropertyClass::Object, "arrowMesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000b0009, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, arrowMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_arrowMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_arrowMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_bowMesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
		{ "ToolTip", "Bow model" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_bowMesh = { UE4CodeGen_Private::EPropertyClass::Object, "bowMesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000b0009, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, bowMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_bowMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_bowMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_FirstPersonCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "GameplayMechanicsCharacter.h" },
		{ "ToolTip", "First person camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_FirstPersonCameraComponent = { UE4CodeGen_Private::EPropertyClass::Object, "FirstPersonCameraComponent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(AGameplayMechanicsCharacter, FirstPersonCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_FirstPersonCameraComponent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_FirstPersonCameraComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_ArrowOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_BaseLookUpRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_BaseTurnRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_chargeSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_maxVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_minVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicTimer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicArrowCooldown,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterTimer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterArrowCooldown,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_currentArrowsAmmo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_maxArrowsAmmo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_sonicArrowMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_scatterArrowMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_standardArrowMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_arrowMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_bowMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::NewProp_FirstPersonCameraComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameplayMechanicsCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::ClassParams = {
		&AGameplayMechanicsCharacter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x008000A0u,
		nullptr, 0,
		Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::PropPointers),
		"Game",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGameplayMechanicsCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGameplayMechanicsCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGameplayMechanicsCharacter, 1721840134);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGameplayMechanicsCharacter(Z_Construct_UClass_AGameplayMechanicsCharacter, &AGameplayMechanicsCharacter::StaticClass, TEXT("/Script/GameplayMechanics"), TEXT("AGameplayMechanicsCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameplayMechanicsCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
