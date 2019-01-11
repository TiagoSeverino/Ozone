#include "stdafx.h"
DWORD Offsets::bClient;
DWORD Offsets::bEngine;
DWORD Offsets::LocalBase;

DWORD Offsets::LocalPlayer =			XOR(0xCBD6B4);	// dwLocalPlayer
DWORD Offsets::oFlags =					XOR(0x104);		// m_fFlags
DWORD Offsets::forceJump =				XOR(0x5170DB0);	// dwForceJump
DWORD Offsets::forceAttack =			XOR(0x30FF2A0);	// dwForceAttack

DWORD Offsets::bSpotted =				XOR(0x93D);		// m_bSpotted
DWORD Offsets::EntityList =				XOR(0x4CCDBFC);	// dwEntityList
DWORD Offsets::iTeam =					XOR(0xF4);		// m_iTeamNum
DWORD Offsets::iHealth =				XOR(0x100);		// m_iHealth
DWORD Offsets::bIsDefusing =			XOR(0x3914);	// m_bIsDefusing
DWORD Offsets::mMoveType =				XOR(0x25C);		// m_MoveType
DWORD Offsets::mVecVelocity =			XOR(0x114);		// m_vecVelocity

DWORD Offsets::glowObject =				XOR(0x520DA28);	// dwGlowObjectManager
DWORD Offsets::glowIndex =				XOR(0xA3F8);	// m_iGlowIndex
DWORD Offsets::bSpottedMask =			XOR(0x980);		// m_bSpottedByMask

DWORD Offsets::iCrosshairId =			XOR(0xB394);	// m_iCrosshairId

DWORD Offsets::flFlashMaxAlpha =		XOR(0xA3DC);	// m_flFlashMaxAlpha

DWORD Offsets::m_iShotsFired =			XOR(0xA370);	// m_iShotsFired
DWORD Offsets::m_aimPunchAngle =		XOR(0x302C);	// m_aimPunchAngle
DWORD Offsets::dwViewAngles =			XOR(0x4D10);	// dwClientState_ViewAngles
DWORD Offsets::dwClientState =			XOR(0x58BCFC);	// dwClientState 
DWORD Offsets::dwViewMatrix =			XOR(0x4CBF614);	// dwViewMatrix

DWORD Offsets::m_dwBoneMatrix =			XOR(0x26A8);	//m_dwBoneMatrix

DWORD Offsets::dwSensitivityPtr =		XOR(0xCC3070);	// dwSensitivityPtr
DWORD Offsets::dwSensitivity =			XOR(0xCC309C);	// dwSensitivity

DWORD Offsets::dwRadarBase =			XOR(0x510293C);	// dwRadarBase
DWORD Offsets::dwPlayerResource =		XOR(0x30FD65C);	// dwPlayerResource 
DWORD Offsets::iCompetitiveRanking =	XOR(0x1A84);	// m_iCompetitiveRanking
DWORD Offsets::iCompetitiveWins =		XOR(0x1B88);	// iCompetitiveWins

DWORD Offsets::dwGameRulesProxy =		XOR(0x51E30E4);	// dwGameRulesProxy
DWORD Offsets::m_SurvivalGameRuleDecisionTypes = XOR(0x1318);