class Config
{
public:
	static std::string Version;
	struct Key
	{
		static int Exit;
		static int Bhop;
		static int Trigger;
		static int ToggleWH;
		static int ToggleNoFlash;
		static int ToggleTrigger;
		static int ToggleRadar;
		static int ToggleBHop;
	};

	static bool WHDefault;
	static bool NoFlashDefault;
	static bool TriggerDefault;
	static bool RadarDefault;
	static bool BHopDefault;

	static int TriggerDelay;
	static int FlashPercentage;
};