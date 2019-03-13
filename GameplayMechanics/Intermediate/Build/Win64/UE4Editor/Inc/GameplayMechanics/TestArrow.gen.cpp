// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayMechanics/TestArrow.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestArrow() {}
// Cross Module References
	GAMEPLAYMECHANICS_API UClass* Z_Construct_UClass_ATestArrow_NoRegister();
	GAMEPLAYMECHANICS_API UClass* Z_Construct_UClass_ATestArrow();
	GAMEPLAYMECHANICS_API UClass* Z_Construct_UClass_AStandardArrow();
	UPackage* Z_Construct_UPackage__Script_GameplayMechanics();
// End Cross Module References
	void ATestArrow::StaticRegisterNativesATestArrow()
	{
	}
	UClass* Z_Construct_UClass_ATestArrow_NoRegister()
	{
		return ATestArrow::StaticClass();
	}
	struct Z_Construct_UClass_ATestArrow_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATestArrow_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStandardArrow,
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayMechanics,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATestArrow_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "TestArrow.h" },
		{ "ModuleRelativePath", "TestArrow.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATestArrow_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATestArrow>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATestArrow_Statics::ClassParams = {
		&ATestArrow::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ATestArrow_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATestArrow_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATestArrow()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATestArrow_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATestArrow, 3199395691);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATestArrow(Z_Construct_UClass_ATestArrow, &ATestArrow::StaticClass, TEXT("/Script/GameplayMechanics"), TEXT("ATestArrow"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATestArrow);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
