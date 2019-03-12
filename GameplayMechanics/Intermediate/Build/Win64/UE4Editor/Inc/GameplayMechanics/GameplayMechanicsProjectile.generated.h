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
#ifdef GAMEPLAYMECHANICS_GameplayMechanicsProjectile_generated_h
#error "GameplayMechanicsProjectile.generated.h already included, missing '#pragma once' in GameplayMechanicsProjectile.h"
#endif
#define GAMEPLAYMECHANICS_GameplayMechanicsProjectile_generated_h

#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_RPC_WRAPPERS \
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


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
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


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameplayMechanicsProjectile(); \
	friend struct Z_Construct_UClass_AGameplayMechanicsProjectile_Statics; \
public: \
	DECLARE_CLASS(AGameplayMechanicsProjectile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(AGameplayMechanicsProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAGameplayMechanicsProjectile(); \
	friend struct Z_Construct_UClass_AGameplayMechanicsProjectile_Statics; \
public: \
	DECLARE_CLASS(AGameplayMechanicsProjectile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayMechanics"), NO_API) \
	DECLARE_SERIALIZER(AGameplayMechanicsProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameplayMechanicsProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameplayMechanicsProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameplayMechanicsProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameplayMechanicsProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameplayMechanicsProjectile(AGameplayMechanicsProjectile&&); \
	NO_API AGameplayMechanicsProjectile(const AGameplayMechanicsProjectile&); \
public:


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameplayMechanicsProjectile(AGameplayMechanicsProjectile&&); \
	NO_API AGameplayMechanicsProjectile(const AGameplayMechanicsProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameplayMechanicsProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameplayMechanicsProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameplayMechanicsProjectile)


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AGameplayMechanicsProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AGameplayMechanicsProjectile, ProjectileMovement); }


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_9_PROLOG
#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_RPC_WRAPPERS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_INCLASS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_INCLASS_NO_PURE_DECLS \
	GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameplayMechanics_Source_GameplayMechanics_GameplayMechanicsProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
