class Offsets
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
	static DWORD iHealth;					// m_iHealth
	static DWORD bIsDefusing;				// m_bIsDefusing
	static DWORD mMoveType;					// m_MoveType
	static DWORD mVecVelocity;				// m_vecVelocity

	static DWORD glowObject;				// dwGlowObjectManager
	static DWORD glowIndex;					// m_iGlowIndex
	static DWORD bSpottedMask;				// m_bSpottedByMask

	static DWORD iCrosshairId;				// m_iCrosshairId

	static DWORD flFlashMaxAlpha;			// m_flFlashMaxAlpha

	static DWORD m_iShotsFired;				// m_iShotsFired
	static DWORD m_aimPunchAngle;			// m_aimPunchAngle
	static DWORD dwViewAngles;				// dwClientState_ViewAngles
	static DWORD dwClientState;				// dwClientState
	static DWORD dwViewMatrix;				// dwViewMatrix
	static DWORD m_dwBoneMatrix;			// m_dwBoneMatrix

	static DWORD dwSensitivityPtr;			// dwSensitivityPtr
	static DWORD dwSensitivity;				// dwSensitivity

	static DWORD dwRadarBase;				// dwRadarBase
	static DWORD dwPlayerResource;			// dwPlayerResource
	static DWORD iCompetitiveRanking;		// m_iCompetitiveRanking
	static DWORD iCompetitiveWins;			// m_iCompetitiveWins

	static DWORD dwGameRulesProxy;			// dwGameRulesProxy
	static DWORD m_SurvivalGameRuleDecisionTypes;
};