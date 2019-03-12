// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAMEPLAYMECHANICS_GameplayMechanicsCharacter_generated_h
#error "GameplayMechanicsCharacter.generated.h already included, missing '#pragma once' in GameplayMechanicsCharacter.h"
#endif
#define GAMEPLAYMECHANICS_GameplayMechanicsCharacter_generated_h

#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_RPC_WRAPPERS
#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameplayMechanicsCharacter(); \
	friend struct Z_Construct_UClass_AGameplayMechanicsCharacter_Statics; \
public: \
	DECLARE_CLASS(AGameplayMechanicsCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(AGameplayMechanicsCharacter)


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_INCLASS \
private: \
	static void StaticRegisterNativesAGameplayMechanicsCharacter(); \
	friend struct Z_Construct_UClass_AGameplayMechanicsCharacter_Statics; \
public: \
	DECLARE_CLASS(AGameplayMechanicsCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(AGameplayMechanicsCharacter)


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_STANDARD_CONSTRUCTORS \
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


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameplayMechanicsCharacter(AGameplayMechanicsCharacter&&); \
	NO_API AGameplayMechanicsCharacter(const AGameplayMechanicsCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameplayMechanicsCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameplayMechanicsCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameplayMechanicsCharacter)


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AGameplayMechanicsCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AGameplayMechanicsCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AGameplayMechanicsCharacter, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__VR_Gun() { return STRUCT_OFFSET(AGameplayMechanicsCharacter, VR_Gun); } \
	FORCEINLINE static uint32 __PPO__VR_MuzzleLocation() { return STRUCT_OFFSET(AGameplayMechanicsCharacter, VR_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AGameplayMechanicsCharacter, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__R_MotionController() { return STRUCT_OFFSET(AGameplayMechanicsCharacter, R_MotionController); } \
	FORCEINLINE static uint32 __PPO__L_MotionController() { return STRUCT_OFFSET(AGameplayMechanicsCharacter, L_MotionController); }


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_17_PROLOG
#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_RPC_WRAPPERS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_INCLASS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_INCLASS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
