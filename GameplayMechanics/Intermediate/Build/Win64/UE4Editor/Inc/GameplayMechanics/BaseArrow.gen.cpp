// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayMechanics/BaseArrow.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseArrow() {}
// Cross Module References
	GAMEPLAYMECHANICS_API UClass* Z_Construct_UClass_ABaseArrow_NoRegister();
	GAMEPLAYMECHANICS_API UClass* Z_Construct_UClass_ABaseArrow();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_GameplayMechanics();
// End Cross Module References
	void ABaseArrow::StaticRegisterNativesABaseArrow()
	{
	}
	UClass* Z_Construct_UClass_ABaseArrow_NoRegister()
	{
		return ABaseArrow::StaticClass();
	}
	struct Z_Construct_UClass_ABaseArrow_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABaseArrow_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayMechanics,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseArrow_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BaseArrow.h" },
		{ "ModuleRelativePath", "BaseArrow.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABaseArrow_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseArrow>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABaseArrow_Statics::ClassParams = {
		&ABaseArrow::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ABaseArrow_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ABaseArrow_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABaseArrow()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABaseArrow_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABaseArrow, 667277340);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABaseArrow(Z_Construct_UClass_ABaseArrow, &ABaseArrow::StaticClass, TEXT("/Script/GameplayMechanics"), TEXT("ABaseArrow"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseArrow);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
