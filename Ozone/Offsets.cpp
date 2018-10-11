#include "stdafx.h"
DWORD Offsets::bClient;
DWORD Offsets::bEngine;
DWORD Offsets::LocalBase;

DWORD Offsets::LocalPlayer =			XOR(0xC5F89C);	// dwLocalPlayer
DWORD Offsets::oFlags =					XOR(0x100);		// m_fFlags
DWORD Offsets::forceJump =				XOR(0x50DF1B8);	// dwForceJump
DWORD Offsets::forceAttack =			XOR(0x307DBB8);	// dwForceAttack

DWORD Offsets::bSpotted =				XOR(0x939);		// m_bSpotted
DWORD Offsets::EntityList =				XOR(0x4C3C4F4);	// dwEntityList
DWORD Offsets::iTeam =					XOR(0xF0);		// m_iTeamNum
DWORD Offsets::oDormant =				XOR(0xE9);		// oDormant
DWORD Offsets::iHealth =				XOR(0xFC);		// m_iHealth
DWORD Offsets::bIsDefusing =			XOR(0x38A8);	// m_bIsDefusing
DWORD Offsets::mMoveType =				XOR(0x258);		// m_MoveType
DWORD Offsets::mVecVelocity =			XOR(0x110);		// m_vecVelocity

DWORD Offsets::glowObject =				XOR(0x517B700);	// dwGlowObjectManager
DWORD Offsets::glowIndex =				XOR(0xA330);	// m_iGlowIndex
DWORD Offsets::bSpottedMask =			XOR(0x97C);		// m_bSpottedByMask

DWORD Offsets::iCrosshairId =			XOR(0xB2C8);	// m_iCrosshairId

DWORD Offsets::flFlashMaxAlpha =		XOR(0xA314);	// m_flFlashMaxAlpha

DWORD Offsets::m_iShotsFired =			XOR(0xA2D0);	// m_iShotsFired
DWORD Offsets::m_aimPunchAngle =		XOR(0x301C);	// m_aimPunchAngle
DWORD Offsets::dwViewAngles =			XOR(0x4D10);	// dwClientState_ViewAngles
DWORD Offsets::dwClientState =			XOR(0x589B34);	// dwClientState 
DWORD Offsets::dwViewMatrix =			XOR(0x4C2DF24);	// dwViewMatrix

DWORD Offsets::m_dwBoneMatrix =			XOR(0x2698);	//m_dwBoneMatrix

DWORD Offsets::dwSensitivityPtr =		XOR(0xC650D8);	// dwSensitivityPtr
DWORD Offsets::dwSensitivity =			XOR(0xC65104);	// dwSensitivity

DWORD Offsets::dwRadarBase =			XOR(0x50711DC);	// dwRadarBase
DWORD Offsets::dwPlayerResource =		XOR(0x307BF6C);	// dwPlayerResource 
DWORD Offsets::iCompetitiveRanking =	XOR(0x1A84);	// m_iCompetitiveRanking
DWORD Offsets::iCompetitiveWins =		XOR(0x1B88);	// iCompetitiveWins