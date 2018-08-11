﻿#include "stdafx.h"

CMemoryManager* MemoryManager;

struct Vector
{
	float x, y, z;
};

class ESP {
private:
	bool isWallHack;
	bool isRadarHack;
	bool isRunning;

	struct GlowColor
	{
		float r;
		float g;
		float b;
		float a;
		bool backlight;
	};

	GlowColor CGreen = { 0.f, 0.4f, 0.f, 1.f, true };
	GlowColor CYellow = { 0.4f, 0.4f, 0.f, 1.f, true };
	GlowColor CRed = { 0.4f, 0.f, 0.f, 1.f, true };
	GlowColor CBlue = { 0.f, 0.f, 0.4f, 1.f, true };
	GlowColor COrange = { 1.f, 0.5, 0.f, 1.f, true };
	GlowColor CPink = { 1.f, 0.55f, 0.7f, 1.f, true };
	GlowColor CWhite = { 1.f, 1.f, 1.f, 1.f, true };
	GlowColor CTeammate = { 0.3f, 0.1f, 0.8f, 0.4f, true };

	void GlowPlayer(DWORD player, ESP::GlowColor color) // show player
	{
		DWORD GlowIndex = 0;
		MemoryManager->Read<DWORD>(player + Offsets::glowIndex, GlowIndex);
		DWORD GlowObject = 0;
		MemoryManager->Read<DWORD>(Offsets::bClient + Offsets::glowObject, GlowObject);

		float rgba[4] = {
			color.r,
			color.g,
			color.b,
			color.a
		};

		DWORD calculation = GlowIndex * 0x38 + 0x4;
		MemoryManager->Write(GlowObject + calculation, rgba);

		calculation = GlowIndex * 0x38 + 0x24;
		MemoryManager->Write(GlowObject + calculation, color.backlight);
	}

	void ScanPlayers() {

		MemoryManager->Read<DWORD>(Offsets::bClient + Offsets::LocalPlayer, Offsets::LocalBase);

		float FlashDuration = 0.f;
		MemoryManager->Read<float>(Offsets::LocalBase + Offsets::flFlashDuration, FlashDuration);

		if (FlashDuration > 0.f)
			MemoryManager->Write(Offsets::LocalBase + Offsets::flFlashDuration, 0.f);

		/*
		float FlashAlpha = 0.f;
		MemoryManager->Read<float>(LocalBase + flFlashMaxAlpha, FlashAlpha);

		if (FlashAlpha > 0.f)
			MemoryManager->Write(LocalBase + flFlashMaxAlpha, 0.f);
		*/

		DWORD myTeam = 0;
		MemoryManager->Read<DWORD>(Offsets::LocalBase + Offsets::iTeam, myTeam);

		for (int i = 0; i <= 64; ++i)
		{
			DWORD player = 0;
			MemoryManager->Read<DWORD>(Offsets::bClient + Offsets::EntityList + (i - 1) * 0x10, player);

			if (player == 0)
				continue;

			bool dormant = false;
			MemoryManager->Read<bool>(player + Offsets::oDormant, dormant);

			if (dormant)
				continue;

			DWORD team = 0;
			MemoryManager->Read<DWORD>(player + Offsets::iTeam, team);

			if (team != 2 && team != 3)
				continue;

			if (this->isWallHack) {
				if (team == myTeam) {
					GlowPlayer(player, CTeammate);
					continue;
				}

				int health = 0;
				MemoryManager->Read<int>(player + Offsets::iHealth, health);

				bool isDefusing = false;
				if (team == 3)
					MemoryManager->Read<bool>(player + Offsets::bIsDefusing, isDefusing);

				if (isDefusing)
				{
					GlowPlayer(player, CBlue);
				}
				else if (health <= 100 && health > 75)
				{
					GlowPlayer(player, CGreen);
				}
				else if (health <= 75 && health > 50)
				{
					GlowPlayer(player, CYellow);
				}
				else if (health <= 50 && health > 25)
				{
					GlowPlayer(player, COrange);
				}
				else if (health <= 25 && health > 1)
				{
					GlowPlayer(player, CRed);
				}
				else if (health <= 1 && health > 0)
				{
					GlowPlayer(player, CWhite);
				}
			}

			if (!this->isRadarHack)
				continue;

			MemoryManager->Write(player + Offsets::bSpotted, 1); // Write 1 to let us see him on radar
		}
	}
public:
	
	ESP(bool isWallHack = false, bool isRadarHack = false) {
		this->isWallHack = isWallHack;
		this->isRadarHack = isRadarHack;
	}

	void Start() {
		this->isRunning = true;
		while (this->isRunning) {
			ScanPlayers();
			std::this_thread::sleep_for(std::chrono::milliseconds(8));
		}
	}

	void Stop() {
		this->isRunning = false;
	}
};

class BHOP {
private:
	bool isBhop;
	bool isRunning;
public:

	BHOP(bool isBhop = false) {
		this->isBhop = isBhop;
	}

	void Start() {
		this->isRunning = true;

		while (this->isRunning) {
			if (GetAsyncKeyState(Config::Key::Bhop) & 0x8000 && this->isBhop)
			{
				MemoryManager->Read<DWORD>(Offsets::bClient + Offsets::LocalPlayer, Offsets::LocalBase);

				Vector velocity;
				MemoryManager->Read<Vector>(Offsets::LocalBase + Offsets::mVecVelocity, velocity);

				if (sqrtf(velocity.x * velocity.x + velocity.y * velocity.y) < 1.f)
					continue;

				DWORD movetype = 0;
				MemoryManager->Read<DWORD>(Offsets::LocalBase + Offsets::mMoveType, movetype);

				if (movetype == 8 || movetype == 9) // MOVETYPE_NOCLIP OR MOVETYPE_LADDER
					continue;

				BYTE fFlags = 0;
				MemoryManager->Read<BYTE>(Offsets::LocalBase + Offsets::oFlags, fFlags);

				if (fFlags & (1 << 0)) // Check for FL_ONGROUND
					MemoryManager->Write(Offsets::bClient + Offsets::forceJump, 6); // Will force jump for 1 tick only
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(0));
		}
	}

	void Stop() {
		this->isRunning = false;
	}
};

class TriggerBot {
private:
	bool isTriggerBot;
	bool isRunning;
public:

	TriggerBot(bool isTriggerBot = false) {
		this->isTriggerBot = isTriggerBot;
	}

	void Start() {
		this->isRunning = true;

		while (this->isRunning) {
			if (GetAsyncKeyState(Config::Key::Trigger) & 0x8000 && isTriggerBot)
			{
				MemoryManager->Read<DWORD>(Offsets::bClient + Offsets::LocalPlayer, Offsets::LocalBase);

				int cross = 0;
				MemoryManager->Read<int>(Offsets::LocalBase + Offsets::iCrosshairId, cross);

				if (cross > 0 && cross <= 64) {
					DWORD myTeam = 0;
					MemoryManager->Read<DWORD>(Offsets::LocalBase + Offsets::iTeam, myTeam);

					DWORD playerInCross = 0;
					MemoryManager->Read<DWORD>(Offsets::bClient + Offsets::EntityList + (cross - 1) * 0x10, playerInCross);

					DWORD teamInCross = 0;
					MemoryManager->Read<DWORD>(playerInCross + Offsets::iTeam, teamInCross);

					bool dormant = false;
					MemoryManager->Read<bool>(playerInCross + Offsets::oDormant, dormant);

					if (teamInCross != myTeam && !dormant) { // if enemy
						MemoryManager->Write(Offsets::bClient + Offsets::forceAttack, 1); //Force Shoot
						std::this_thread::sleep_for(std::chrono::milliseconds(8));
						MemoryManager->Write(Offsets::bClient + Offsets::forceAttack, 0); //Stop Shoot
					}
				}
			}
		}
	}

	void Stop() {
		this->isRunning = false;
	}
};

ESP Esp;
BHOP Bhop;
TriggerBot Triggerbot;

int main()
{
	SetConsoleTitle(_T("Ozone V0.1"));

	std::cout << "Waiting for CS:GO!" << std::endl;

	while (!FindWindow(NULL, "Counter-Strike: Global Offensive"))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	}

	try {
		MemoryManager = new CMemoryManager("csgo.exe");
	}
	catch (...) {
		std::cout << "CS:GO not found!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		return 0;
	}

	std::cout << "CS:GO Found!" << std::endl;


	std::cout << "Waiting for modules!" << std::endl;

	while (!MemoryManager->GrabModule("client_panorama.dll") || !MemoryManager->GrabModule("engine.dll")) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	}

	std::cout << "Modules Found" << std::endl;


	for (auto m : MemoryManager->GetModules())
	{
		if (!strcmp(m.szModule, "client_panorama.dll"))
		{
			Offsets::bClient = reinterpret_cast<DWORD>(m.modBaseAddr);
			break;
		}
	}

	for (auto m : MemoryManager->GetModules())
	{
		if (!strcmp(m.szModule, "engine.dll"))
		{
			Offsets::bEngine = reinterpret_cast<DWORD>(m.modBaseAddr);
			break;
		}
	}

	std::cout << "Ozone started!" << std::endl;

	Beep(1000, 200);

	Esp = ESP(true, true);
	Bhop = BHOP(true);
	Triggerbot = TriggerBot(true);

	std::thread tEsp(&ESP::Start, &Esp);
	std::thread tBhop(&BHOP::Start, &Bhop);
	std::thread tTriggerBot(&TriggerBot::Start, &Triggerbot);

	while (true)
	{
		if (GetAsyncKeyState(Config::Key::Exit) & 0x8000)
		{
			std::cout << "Closing Ozone!" << std::endl;
			Beep(500, 200);

			Esp.Stop();
			Bhop.Stop();
			Triggerbot.Stop();

			tEsp.join();
			tBhop.join();
			tTriggerBot.join();

			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	return 0;
}