using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Menu
{
    public static class Config
    {
        public static int Exit = (int)Keys.Delete;
        public static int Bhop = (int)Keys.Space;
        public static int Trigger = (int)Keys.F;
        public static int ToggleWH = (int)Keys.F4;
        public static int ToggleNoFlash = (int)Keys.F5;
        public static int ToggleTrigger = (int)Keys.F6;
        public static int ToggleRadar = (int)Keys.F7;
        public static int ToggleBHop = (int)Keys.F8;
        public static int ToggleRCS = (int)Keys.F9;

        public static bool WHDefault = true;
        public static bool NoFlashDefault = true;
        public static bool TriggerDefault = true;
        public static bool RadarDefault = true;
        public static bool BHopDefault = true;
        public static bool RCSDefault = true;

        public static int TriggerDelay = 0;
        public static int FlashPercentage = 50;
        public static int RcsVerticalSmooth = 50;
        public static int RcsHorizontalSmooth = 50;

        public static void ArrayToConfig(string[] config)
        {
            foreach(string line in config)
            {
                string[] param = line.Split('=');

                if (param.Length == 2)
                    switch (param[0])
                    {
                        case "WallHack":
                            Config.WHDefault = (param[1] == "true");
                            break;
                        case "NoFlash":
                            Config.NoFlashDefault = (param[1] == "true");
                            break;
                        case "TriggerBot":
                            Config.TriggerDefault = (param[1] == "true");
                            break;
                        case "RadarHack":
                            Config.RadarDefault = (param[1] == "true");
                            break;
                        case "BHOP":
                            Config.BHopDefault = (param[1] == "true");
                            break;
                        case "RCS":
                            Config.RCSDefault = (param[1] == "true");
                            break;
                        case "ToggleWallHack":
                            Config.ToggleWH = int.Parse(param[1]);
                            break;
                        case "ToggleNoFlash":
                            Config.ToggleNoFlash = int.Parse(param[1]);
                            break;
                        case "ToggleTriggerBot":
                            Config.ToggleTrigger = int.Parse(param[1]);
                            break;
                        case "ToggleRadarHack":
                            Config.ToggleRadar = int.Parse(param[1]);
                            break;
                        case "ToggleBHOP":
                            Config.ToggleBHop = int.Parse(param[1]);
                            break;
                        case "ToggleRCS":
                            Config.ToggleRCS = int.Parse(param[1]);
                            break;
                        case "Exit":
                            Config.Exit = int.Parse(param[1]);
                            break;
                        case "EnableTriggerBot":
                            Config.Trigger = int.Parse(param[1]);
                            break;
                        case "Delay":
                            Config.TriggerDelay = int.Parse(param[1]);
                            break;
                        case "FlashPercentage":
                            Config.FlashPercentage = int.Parse(param[1]);
                            break;
                        case "RcsVerticalSmoothPercentage":
                            Config.RcsVerticalSmooth = int.Parse(param[1]);
                            break;
                        case "RcsHorizontalSmoothPercentage":
                            Config.RcsHorizontalSmooth = int.Parse(param[1]);
                            break;
                    }
            }
        }

        public static string[] ConfigToArray()
        {
            List<string> config = new List<string>();
            config.Add("[Features]");
            config.Add("WallHack" + "=" + (WHDefault ? "true" : "false"));
            config.Add("NoFlash" + "=" + (NoFlashDefault ? "true" : "false"));
            config.Add("TriggerBot" + "=" + (TriggerDefault ? "true" : "false"));
            config.Add("RadarHack" + "=" + (RadarDefault ? "true" : "false"));
            config.Add("BHOP" + "=" + (BHopDefault ? "true" : "false"));
            config.Add("RCS" + "=" + (RCSDefault ? "true" : "false"));

            config.Add("ToggleWallHack" + "=" + ToggleWH.ToString());
            config.Add("ToggleNoFlash" + "=" + ToggleNoFlash.ToString());
            config.Add("ToggleTriggerBot" + "=" + ToggleTrigger.ToString());
            config.Add("ToggleRadarHack" + "=" + ToggleRadar.ToString());
            config.Add("ToggleBHOP" + "=" + ToggleBHop.ToString());
            config.Add("ToggleRCS" + "=" + ToggleRCS.ToString());
            config.Add("Exit" + "=" + Exit.ToString());
            config.Add("EnableTriggerBot" + "=" + Trigger.ToString());

            config.Add("Delay" + "=" + TriggerDelay.ToString());

            config.Add("FlashPercentage" + "=" + FlashPercentage.ToString());

            config.Add("RcsVerticalSmoothPercentage" + "=" + RcsVerticalSmooth.ToString());
            config.Add("RcsHorizontalSmoothPercentage" + "=" + RcsHorizontalSmooth.ToString());

            return config.ToArray();
        }
    }
}