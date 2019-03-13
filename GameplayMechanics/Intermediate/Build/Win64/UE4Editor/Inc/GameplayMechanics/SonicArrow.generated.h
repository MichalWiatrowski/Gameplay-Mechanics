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
struct FHitResult;
struct FVector;
#ifdef GAMEPLAYMECHANICS_SonicArrow_generated_h
#error "SonicArrow.generated.h already included, missing '#pragma once' in SonicArrow.h"
#endif
#define GAMEPLAYMECHANICS_SonicArrow_generated_h

#define GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
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


#define GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
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


#define GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASonicArrow(); \
	friend struct Z_Construct_UClass_ASonicArrow_Statics; \
public: \
	DECLARE_CLASS(ASonicArrow, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(ASonicArrow)


#define GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_INCLASS \
private: \
	static void StaticRegisterNativesASonicArrow(); \
	friend struct Z_Construct_UClass_ASonicArrow_Statics; \
public: \
	DECLARE_CLASS(ASonicArrow, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(ASonicArrow)


#define GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASonicArrow(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASonicArrow) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASonicArrow); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASonicArrow); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASonicArrow(ASonicArrow&&); \
	NO_API ASonicArrow(const ASonicArrow&); \
public:


#define GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASonicArrow(ASonicArrow&&); \
	NO_API ASonicArrow(const ASonicArrow&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASonicArrow); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASonicArrow); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASonicArrow)


#define GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_PRIVATE_PROPERTY_OFFSET
#define GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_14_PROLOG
#define GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_RPC_WRAPPERS \
	GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_INCLASS \
	GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_INCLASS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_SonicArrow_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameplayMechanics_Source_GameplayMechanics_SonicArrow_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
