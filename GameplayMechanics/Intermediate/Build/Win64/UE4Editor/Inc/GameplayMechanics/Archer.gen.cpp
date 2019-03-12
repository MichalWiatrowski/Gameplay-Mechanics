// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayMechanics/Archer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeArcher() {}
// Cross Module References
	GAMEPLAYMECHANICS_API UClass* Z_Construct_UClass_AArcher_NoRegister();
	GAMEPLAYMECHANICS_API UClass* Z_Construct_UClass_AArcher();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_GameplayMechanics();
// End Cross Module References
	void AArcher::StaticRegisterNativesAArcher()
	{
	}
	UClass* Z_Construct_UClass_AArcher_NoRegister()
	{
		return AArcher::StaticClass();
	}
	struct Z_Construct_UClass_AArcher_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AArcher_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayMechanics,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AArcher_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Archer.h" },
		{ "ModuleRelativePath", "Archer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AArcher_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AArcher>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AArcher_Statics::ClassParams = {
		&AArcher::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AArcher_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AArcher_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AArcher()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AArcher_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AArcher, 2164625423);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AArcher(Z_Construct_UClass_AArcher, &AArcher::StaticClass, TEXT("/Script/GameplayMechanics"), TEXT("AArcher"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AArcher);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
