#include "stdafx.h"
DWORD Offsets::bClient;
DWORD Offsets::bEngine;
DWORD Offsets::LocalBase;

DWORD Offsets::LocalPlayer = 0xC5C85C;		// dwLocalPlayer
DWORD Offsets::oFlags = 0x100;				// m_fFlags
DWORD Offsets::forceJump = 0x50DBDDC;		// dwForceJump
DWORD Offsets::forceAttack = 0x307A7FC;		// dwForceAttack

DWORD Offsets::bSpotted = 0x939;			// m_bSpotted
DWORD Offsets::EntityList = 0x4C3913C;		// dwEntityList
DWORD Offsets::iTeam = 0xF0;				// m_iTeamNum
DWORD Offsets::oDormant = 0xE9;				// oDormant
DWORD Offsets::iHealth = 0xFC;				// m_iHealth
DWORD Offsets::bIsDefusing = 0x3898;		// m_bIsDefusing
DWORD Offsets::mMoveType = 0x258;			// m_MoveType
DWORD Offsets::mVecVelocity = 0x110;		// m_vecVelocity

DWORD Offsets::glowObject = 0x5178E40;		// dwGlowObjectManager
DWORD Offsets::glowIndex = 0xA320;			// m_iGlowIndex
DWORD Offsets::bSpottedMask = 0x97C;		// m_bSpottedByMask

DWORD Offsets::iCrosshairId = 0xB2B8;		// m_iCrosshairId

DWORD Offsets::flFlashDuration = 0xA308;	// m_flFlashDuration
DWORD Offsets::flFlashMaxAlpha = 0xA304;	//m_flFlashMaxAlpha