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
#ifdef GAMEPLAYMECHANICS_VacuumArrow_generated_h
#error "VacuumArrow.generated.h already included, missing '#pragma once' in VacuumArrow.h"
#endif
#define GAMEPLAYMECHANICS_VacuumArrow_generated_h

#define GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_RPC_WRAPPERS \
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


#define GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
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


#define GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVacuumArrow(); \
	friend struct Z_Construct_UClass_AVacuumArrow_Statics; \
public: \
	DECLARE_CLASS(AVacuumArrow, ABaseArrow, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(AVacuumArrow)


#define GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAVacuumArrow(); \
	friend struct Z_Construct_UClass_AVacuumArrow_Statics; \
public: \
	DECLARE_CLASS(AVacuumArrow, ABaseArrow, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(AVacuumArrow)


#define GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVacuumArrow(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVacuumArrow) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVacuumArrow); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVacuumArrow); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVacuumArrow(AVacuumArrow&&); \
	NO_API AVacuumArrow(const AVacuumArrow&); \
public:


#define GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVacuumArrow(AVacuumArrow&&); \
	NO_API AVacuumArrow(const AVacuumArrow&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVacuumArrow); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVacuumArrow); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVacuumArrow)


#define GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_PRIVATE_PROPERTY_OFFSET
#define GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_13_PROLOG
#define GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_RPC_WRAPPERS \
	GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_INCLASS \
	GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_INCLASS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameplayMechanics_Source_GameplayMechanics_VacuumArrow_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
