#pragma once
class Config
{
public:
	static DWORD bClient, bEngine, LocalBase;

	static DWORD LocalPlayer;				// dwLocalPlayer
	static DWORD oFlags;					// m_fFlags
	static DWORD forceJump;					// dwForceJump
	static DWORD forceAttack;				// dwForceAttack

	static DWORD bSpotted;					// m_bSpotted
	static DWORD EntityList;				// dwEntityList
	static DWORD iTeam;						// m_iTeamNum
	static DWORD oDormant;
	static DWORD iHealth;					// m_iHealth
	static DWORD bIsDefusing;				// m_bIsDefusing
	static DWORD mMoveType;					// m_MoveType
	static DWORD mVecVelocity;				// m_vecVelocity

	static DWORD glowObject;				// dwGlowObjectManager
	static DWORD glowIndex;					// m_iGlowIndex
	static DWORD bSpottedMask;				// m_bSpottedByMask

	static DWORD iCrosshairId;				// m_iCrosshairId

	static DWORD flFlashDuration;			// m_flFlashDuration
	static DWORD flFlashMaxAlpha;			// m_flFlashMaxAlpha
};