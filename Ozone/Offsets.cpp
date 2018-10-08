#include "stdafx.h"
DWORD Offsets::bClient;
DWORD Offsets::bEngine;
DWORD Offsets::LocalBase;

DWORD Offsets::LocalPlayer = 0xC5F89C;		// dwLocalPlayer
DWORD Offsets::oFlags = 0x100;				// m_fFlags
DWORD Offsets::forceJump = 0x50DF118;		// dwForceJump
DWORD Offsets::forceAttack = 0x307DB6C;		// dwForceAttack

DWORD Offsets::bSpotted = 0x939;			// m_bSpotted
DWORD Offsets::EntityList = 0x4C3C454;		// dwEntityList
DWORD Offsets::iTeam = 0xF0;				// m_iTeamNum
DWORD Offsets::oDormant = 0xE9;				// oDormant
DWORD Offsets::iHealth = 0xFC;				// m_iHealth
DWORD Offsets::bIsDefusing = 0x3898;		// m_bIsDefusing
DWORD Offsets::mMoveType = 0x258;			// m_MoveType
DWORD Offsets::mVecVelocity = 0x110;		// m_vecVelocity

DWORD Offsets::glowObject = 0x517B650;		// dwGlowObjectManager
DWORD Offsets::glowIndex = 0xA320;			// m_iGlowIndex
DWORD Offsets::bSpottedMask = 0x97C;		// m_bSpottedByMask

DWORD Offsets::iCrosshairId = 0xB2B8;		// m_iCrosshairId

DWORD Offsets::flFlashMaxAlpha = 0xA304;	// m_flFlashMaxAlpha

DWORD Offsets::m_iShotsFired = 0xA2C0;		// m_iShotsFired
DWORD Offsets::m_aimPunchAngle = 0x301C;	// m_aimPunchAngle
DWORD Offsets::dwViewAngles = 0x4D10;		// dwClientState_ViewAngles
DWORD Offsets::dwClientState = 0x588A2C;	// dwClientState 
DWORD Offsets::dwViewMatrix = 0x4C2DE84;	// dwViewMatrix

DWORD Offsets::m_dwBoneMatrix = 0x2698;		//m_dwBoneMatrix

DWORD Offsets::dwSensitivityPtr = 0xC650D8;	// dwSensitivityPtr
DWORD Offsets::dwSensitivity = 0xC65104;	// dwSensitivity

DWORD Offsets::dwRadarBase = 0x507113C;		// dwRadarBase
DWORD Offsets::dwPlayerResource = 0x307BECC;// dwPlayerResource 
DWORD Offsets::iCompetitiveRanking = 0x1A84;// m_iCompetitiveRanking
DWORD Offsets::iCompetitiveWins = 0x1B88;	// iCompetitiveWins