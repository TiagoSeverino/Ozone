#include "stdafx.h"
std::string Config::Version = "0.3";

int Config::Key::Exit = VK_DELETE;
int Config::Key::Bhop = VK_SPACE;
int Config::Key::Trigger = (int)'F';
int Config::Key::ToggleWH = VK_F4;
int Config::Key::ToggleNoFlash = VK_F5;
int Config::Key::ToggleTrigger = VK_F6;
int Config::Key::ToggleRadar = VK_F7;
int Config::Key::ToggleBHop = VK_F8;
int Config::Key::ToggleRCS = VK_F9;
int Config::Key::ToggleAimbot = VK_F10;

bool Config::WHDefault = true;
bool Config::NoFlashDefault = true;
bool Config::TriggerDefault = true;
bool Config::RadarDefault = true;
bool Config::BHopDefault = true;
bool Config::RCSDefault = true;
bool Config::AimbotDefault = true;

int Config::TriggerDelay = 0;
int Config::FlashPercentage = 50;
int Config::RcsVerticalSmooth = 50;
int Config::RcsHorizontalSmooth = 50;
int Config::AimbotFOV = 50;
int Config::AimbotSmooth = 50;
int Config::AimbotBone = 8;