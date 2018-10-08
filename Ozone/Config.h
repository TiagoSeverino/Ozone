class Config
{
public:
	static std::string Version;
	struct Key
	{
		static int Exit;
		static int Bhop;
		static int Trigger;
		static int RankReveal;
		static int ToggleWH;
		static int ToggleNoFlash;
		static int ToggleTrigger;
		static int ToggleRadar;
		static int ToggleBHop;
		static int ToggleRCS;
		static int ToggleAimbot;
	};

	static bool WHDefault;
	static bool NoFlashDefault;
	static bool TriggerDefault;
	static bool RadarDefault;
	static bool BHopDefault;
	static bool RCSDefault;
	static bool AimbotDefault;

	static int TriggerDelay;
	static int FlashPercentage;
	static int RcsVerticalSmooth;
	static int RcsHorizontalSmooth;
	static int AimbotFOV;
	static int AimbotSmooth;
	static int AimbotBone;
	static bool AimbotMagnet;
};