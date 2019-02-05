#include "stdafx.h"
DWORD Offsets::bClient;
DWORD Offsets::bEngine;
DWORD Offsets::LocalBase;

DWORD Offsets::LocalPlayer =			XOR(0xCBD6A4);	// dwLocalPlayer
DWORD Offsets::oFlags =					XOR(0x104);		// m_fFlags
DWORD Offsets::forceJump =				XOR(0x5170DF0);	// dwForceJump
DWORD Offsets::forceAttack =			XOR(0x30FF2E0);	// dwForceAttack

DWORD Offsets::bSpotted =				XOR(0x93D);		// m_bSpotted
DWORD Offsets::EntityList =				XOR(0x4CCDC3C);	// dwEntityList
DWORD Offsets::iTeam =					XOR(0xF4);		// m_iTeamNum
DWORD Offsets::iHealth =				XOR(0x100);		// m_iHealth
DWORD Offsets::bIsDefusing =			XOR(0x3914);	// m_bIsDefusing
DWORD Offsets::mMoveType =				XOR(0x25C);		// m_MoveType
DWORD Offsets::mVecVelocity =			XOR(0x114);		// m_vecVelocity

DWORD Offsets::glowObject =				XOR(0x520DA80);	// dwGlowObjectManager
DWORD Offsets::glowIndex =				XOR(0xA3F8);	// m_iGlowIndex
DWORD Offsets::bSpottedMask =			XOR(0x980);		// m_bSpottedByMask

DWORD Offsets::iCrosshairId =			XOR(0xB394);	// m_iCrosshairId

DWORD Offsets::flFlashMaxAlpha =		XOR(0xA3DC);	// m_flFlashMaxAlpha

DWORD Offsets::m_iShotsFired =			XOR(0xA370);	// m_iShotsFired
DWORD Offsets::m_aimPunchAngle =		XOR(0x302C);	// m_aimPunchAngle
DWORD Offsets::dwViewAngles =			XOR(0x4D10);	// dwClientState_ViewAngles
DWORD Offsets::dwClientState =			XOR(0x58ACFC);	// dwClientState 
DWORD Offsets::dwViewMatrix =			XOR(0x4CBF654);	// dwViewMatrix

DWORD Offsets::m_dwBoneMatrix =			XOR(0x26A8);	//m_dwBoneMatrix

DWORD Offsets::dwSensitivityPtr =		XOR(0xCC3060);	// dwSensitivityPtr
DWORD Offsets::dwSensitivity =			XOR(0xCC308C);	// dwSensitivity

DWORD Offsets::dwRadarBase =			XOR(0x510297C);	// dwRadarBase
DWORD Offsets::dwPlayerResource =		XOR(0x30FD69C);	// dwPlayerResource 
DWORD Offsets::iCompetitiveRanking =	XOR(0x1A84);	// m_iCompetitiveRanking
DWORD Offsets::iCompetitiveWins =		XOR(0x1B88);	// iCompetitiveWins

DWORD Offsets::dwGameRulesProxy =		XOR(0x51E3124);	// dwGameRulesProxy
DWORD Offsets::m_SurvivalGameRuleDecisionTypes = XOR(0x1318);