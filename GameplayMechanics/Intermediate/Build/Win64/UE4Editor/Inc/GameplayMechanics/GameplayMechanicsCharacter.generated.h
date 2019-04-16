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
#ifdef GAMEPLAYMECHANICS_GameplayMechanicsCharacter_generated_h
#error "GameplayMechanicsCharacter.generated.h already included, missing '#pragma once' in GameplayMechanicsCharacter.h"
#endif
#define GAMEPLAYMECHANICS_GameplayMechanicsCharacter_generated_h

#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnCapsuleOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnCapsuleOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnCapsuleOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnCapsuleOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnCapsuleOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnCapsuleOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnCapsuleOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnCapsuleOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameplayMechanicsCharacter(); \
	friend struct Z_Construct_UClass_AGameplayMechanicsCharacter_Statics; \
public: \
	DECLARE_CLASS(AGameplayMechanicsCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(AGameplayMechanicsCharacter)


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAGameplayMechanicsCharacter(); \
	friend struct Z_Construct_UClass_AGameplayMechanicsCharacter_Statics; \
public: \
	DECLARE_CLASS(AGameplayMechanicsCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(AGameplayMechanicsCharacter)


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameplayMechanicsCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameplayMechanicsCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameplayMechanicsCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameplayMechanicsCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameplayMechanicsCharacter(AGameplayMechanicsCharacter&&); \
	NO_API AGameplayMechanicsCharacter(const AGameplayMechanicsCharacter&); \
public:


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameplayMechanicsCharacter(AGameplayMechanicsCharacter&&); \
	NO_API AGameplayMechanicsCharacter(const AGameplayMechanicsCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameplayMechanicsCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameplayMechanicsCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameplayMechanicsCharacter)


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AGameplayMechanicsCharacter, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__bowMesh() { return STRUCT_OFFSET(AGameplayMechanicsCharacter, bowMesh); } \
	FORCEINLINE static uint32 __PPO__arrowMesh() { return STRUCT_OFFSET(AGameplayMechanicsCharacter, arrowMesh); }


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_18_PROLOG
#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_RPC_WRAPPERS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_INCLASS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_INCLASS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
