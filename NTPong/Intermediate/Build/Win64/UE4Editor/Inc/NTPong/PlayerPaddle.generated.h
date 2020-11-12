// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NTPONG_PlayerPaddle_generated_h
#error "PlayerPaddle.generated.h already included, missing '#pragma once' in PlayerPaddle.h"
#endif
#define NTPONG_PlayerPaddle_generated_h

#define NTPong_Source_NTPong_Public_PlayerPaddle_h_12_SPARSE_DATA
#define NTPong_Source_NTPong_Public_PlayerPaddle_h_12_RPC_WRAPPERS
#define NTPong_Source_NTPong_Public_PlayerPaddle_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define NTPong_Source_NTPong_Public_PlayerPaddle_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerPaddle(); \
	friend struct Z_Construct_UClass_APlayerPaddle_Statics; \
public: \
	DECLARE_CLASS(APlayerPaddle, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NTPong"), NO_API) \
	DECLARE_SERIALIZER(APlayerPaddle)


#define NTPong_Source_NTPong_Public_PlayerPaddle_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerPaddle(); \
	friend struct Z_Construct_UClass_APlayerPaddle_Statics; \
public: \
	DECLARE_CLASS(APlayerPaddle, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NTPong"), NO_API) \
	DECLARE_SERIALIZER(APlayerPaddle)


#define NTPong_Source_NTPong_Public_PlayerPaddle_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerPaddle(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerPaddle) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerPaddle); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerPaddle); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerPaddle(APlayerPaddle&&); \
	NO_API APlayerPaddle(const APlayerPaddle&); \
public:


#define NTPong_Source_NTPong_Public_PlayerPaddle_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerPaddle(APlayerPaddle&&); \
	NO_API APlayerPaddle(const APlayerPaddle&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerPaddle); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerPaddle); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerPaddle)


#define NTPong_Source_NTPong_Public_PlayerPaddle_h_12_PRIVATE_PROPERTY_OFFSET
#define NTPong_Source_NTPong_Public_PlayerPaddle_h_9_PROLOG
#define NTPong_Source_NTPong_Public_PlayerPaddle_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NTPong_Source_NTPong_Public_PlayerPaddle_h_12_PRIVATE_PROPERTY_OFFSET \
	NTPong_Source_NTPong_Public_PlayerPaddle_h_12_SPARSE_DATA \
	NTPong_Source_NTPong_Public_PlayerPaddle_h_12_RPC_WRAPPERS \
	NTPong_Source_NTPong_Public_PlayerPaddle_h_12_INCLASS \
	NTPong_Source_NTPong_Public_PlayerPaddle_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NTPong_Source_NTPong_Public_PlayerPaddle_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NTPong_Source_NTPong_Public_PlayerPaddle_h_12_PRIVATE_PROPERTY_OFFSET \
	NTPong_Source_NTPong_Public_PlayerPaddle_h_12_SPARSE_DATA \
	NTPong_Source_NTPong_Public_PlayerPaddle_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	NTPong_Source_NTPong_Public_PlayerPaddle_h_12_INCLASS_NO_PURE_DECLS \
	NTPong_Source_NTPong_Public_PlayerPaddle_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NTPONG_API UClass* StaticClass<class APlayerPaddle>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NTPong_Source_NTPong_Public_PlayerPaddle_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
