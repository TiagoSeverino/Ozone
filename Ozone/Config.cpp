#include "stdafx.h"
std::string Config::Version = "0.2";

int Config::Key::Exit = VK_DELETE;
int Config::Key::Bhop = VK_SPACE;
int Config::Key::Trigger = (int)'F';
int Config::Key::ToggleWH = VK_F4;
int Config::Key::ToggleNoFlash = VK_F5;
int Config::Key::ToggleTrigger = VK_F6;
int Config::Key::ToggleRadar = VK_F7;
int Config::Key::ToggleBHop = VK_F8;

bool Config::WHDefault = true;
bool Config::NoFlashDefault = true;
bool Config::TriggerDefault = true;
bool Config::RadarDefault = true;
bool Config::BHopDefault = true;

int Config::TriggerDelay = 0;
int Config::FlashPercentage = 50;