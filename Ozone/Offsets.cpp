#include "stdafx.h"
DWORD Offsets::bClient;
DWORD Offsets::bEngine;
DWORD Offsets::LocalBase;

DWORD Offsets::LocalPlayer =			XOR(0xC648AC);	// dwLocalPlayer
DWORD Offsets::oFlags =					XOR(0x100);		// m_fFlags
DWORD Offsets::forceJump =				XOR(0x50E444C);	// dwForceJump
DWORD Offsets::forceAttack =			XOR(0x3082DEC);	// dwForceAttack

DWORD Offsets::bSpotted =				XOR(0x939);		// m_bSpotted
DWORD Offsets::EntityList =				XOR(0x4C41704);	// dwEntityList
DWORD Offsets::iTeam =					XOR(0xF0);		// m_iTeamNum
DWORD Offsets::oDormant =				XOR(0xE9);		// oDormant
DWORD Offsets::iHealth =				XOR(0xFC);		// m_iHealth
DWORD Offsets::bIsDefusing =			XOR(0x38B4);	// m_bIsDefusing
DWORD Offsets::mMoveType =				XOR(0x258);		// m_MoveType
DWORD Offsets::mVecVelocity =			XOR(0x110);		// m_vecVelocity

DWORD Offsets::glowObject =				XOR(0x51809B0);	// dwGlowObjectManager
DWORD Offsets::glowIndex =				XOR(0xA344);	// m_iGlowIndex
DWORD Offsets::bSpottedMask =			XOR(0x97C);		// m_bSpottedByMask

DWORD Offsets::iCrosshairId =			XOR(0xB2DC);	// m_iCrosshairId

DWORD Offsets::flFlashMaxAlpha =		XOR(0xA328);	// m_flFlashMaxAlpha

DWORD Offsets::m_iShotsFired =			XOR(0xA2E0);	// m_iShotsFired
DWORD Offsets::m_aimPunchAngle =		XOR(0x301C);	// m_aimPunchAngle
DWORD Offsets::dwViewAngles =			XOR(0x4D10);	// dwClientState_ViewAngles
DWORD Offsets::dwClientState =			XOR(0x589B34);	// dwClientState 
DWORD Offsets::dwViewMatrix =			XOR(0x4C33134);	// dwViewMatrix

DWORD Offsets::m_dwBoneMatrix =			XOR(0x2698);	//m_dwBoneMatrix

DWORD Offsets::dwSensitivityPtr =		XOR(0xC6A0E8);	// dwSensitivityPtr
DWORD Offsets::dwSensitivity =			XOR(0xC6A114);	// dwSensitivity

DWORD Offsets::dwRadarBase =			XOR(0x50763EC);	// dwRadarBase
DWORD Offsets::dwPlayerResource =		XOR(0x308117C);	// dwPlayerResource 
DWORD Offsets::iCompetitiveRanking =	XOR(0x1A84);	// m_iCompetitiveRanking
DWORD Offsets::iCompetitiveWins =		XOR(0x1B88);	// iCompetitiveWins