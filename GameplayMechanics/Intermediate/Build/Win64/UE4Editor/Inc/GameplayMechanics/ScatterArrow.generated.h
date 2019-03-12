// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef GAMEPLAYMECHANICS_ScatterArrow_generated_h
#error "ScatterArrow.generated.h already included, missing '#pragma once' in ScatterArrow.h"
#endif
#define GAMEPLAYMECHANICS_ScatterArrow_generated_h

#define GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAScatterArrow(); \
	friend struct Z_Construct_UClass_AScatterArrow_Statics; \
public: \
	DECLARE_CLASS(AScatterArrow, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(AScatterArrow)


#define GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAScatterArrow(); \
	friend struct Z_Construct_UClass_AScatterArrow_Statics; \
public: \
	DECLARE_CLASS(AScatterArrow, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(AScatterArrow)


#define GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AScatterArrow(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AScatterArrow) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AScatterArrow); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AScatterArrow); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AScatterArrow(AScatterArrow&&); \
	NO_API AScatterArrow(const AScatterArrow&); \
public:


#define GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AScatterArrow(AScatterArrow&&); \
	NO_API AScatterArrow(const AScatterArrow&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AScatterArrow); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AScatterArrow); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AScatterArrow)


#define GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_PRIVATE_PROPERTY_OFFSET
#define GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_14_PROLOG
#define GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_RPC_WRAPPERS \
	GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_INCLASS \
	GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_INCLASS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameplayMechanics_Source_GameplayMechanics_ScatterArrow_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
