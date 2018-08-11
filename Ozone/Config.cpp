#include "stdafx.h"
DWORD Config::bClient;
DWORD Config::bEngine;
DWORD Config::LocalBase;


DWORD Config::LocalPlayer = 0xC5B85C;		// dwLocalPlayer
DWORD Config::oFlags = 0x100;				// m_fFlags
DWORD Config::forceJump = 0x50DAD7C;		// dwForceJump
DWORD Config::forceAttack = 0x30797A8;		// dwForceAttack

DWORD Config::bSpotted = 0x939;				// m_bSpotted
DWORD Config::EntityList = 0x4C380DC;		// dwEntityList
DWORD Config::iTeam = 0xF0;					// m_iTeamNum
DWORD Config::oDormant = 0xE9;
DWORD Config::iHealth = 0xFC;				// m_iHealth
DWORD Config::bIsDefusing = 0x3898;			// m_bIsDefusing
DWORD Config::mMoveType = 0x258;			// m_MoveType
DWORD Config::mVecVelocity = 0x110;			// m_vecVelocity

DWORD Config::glowObject = 0x5177DB0;		// dwGlowObjectManager
DWORD Config::glowIndex = 0xA320;			// m_iGlowIndex
DWORD Config::bSpottedMask = 0x97C;			// m_bSpottedByMask

DWORD Config::iCrosshairId = 0xB2B8;		// m_iCrosshairId

DWORD Config::flFlashDuration = 0xA308;		// m_flFlashDuration
DWORD Config::flFlashMaxAlpha = 0xA304;		// m_flFlashMaxAlpha