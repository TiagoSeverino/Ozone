// Ozone.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

DWORD bClient, bEngine, LocalBase; // some values
DWORD LocalPlayer = 0xAA6614; // player offset
DWORD oFlags = 0x100; // flags offset
DWORD forceJump = 0x4F1AAF4; // jump offset

DWORD bSpotted = 0x939; // radar point
DWORD EntityList = 0x4A8387C; // all players offset
DWORD iTeam = 0xF0; // team num offset
DWORD oDormant = 0xE9; // offset to check if the object is player

DWORD glowObject = 0x4FA08E8;
DWORD glowIndex = 0xA310;
DWORD bSpottedMask = 0x97C;

CMemoryManager* MemoryManager;

struct player
{
	float r, g, b, a;
	bool backlight;
};

player invisible = player{ 1, 0, 0, 0.75f, true };
player visible = player{ 0, 1, 0, 0.75f, true };

void makelight(int human, player man) // show player
{
	DWORD GlowIndex = 0;
	MemoryManager->Read<DWORD>(human + glowIndex, GlowIndex);
	DWORD GlowObject = 0;
	MemoryManager->Read<DWORD>(bClient + glowObject, GlowObject);
	DWORD calculation = GlowIndex * 0x38 + 0x4;
	MemoryManager->Write(GlowObject + calculation, man.r);
	calculation = GlowIndex * 0x38 + 0x8;
	MemoryManager->Write(GlowObject + calculation, man.g);
	calculation = GlowIndex * 0x38 + 0xC;
	MemoryManager->Write(GlowObject + calculation, man.b);
	calculation = GlowIndex * 0x38 + 0x10;
	MemoryManager->Write(GlowObject + calculation, man.a);
	calculation = GlowIndex * 0x38 + 0x24;
	MemoryManager->Write(GlowObject + calculation, man.backlight);
}

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
	}

	std::cout << "CS:GO Found!" << std::endl;


	std::cout << "Waiting for modules!" << std::endl;

	while (!MemoryManager->GrabModule("client.dll") || !MemoryManager->GrabModule("engine.dll")) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	}

	std::cout << "Modules Found" << std::endl;


	for (auto m : MemoryManager->GetModules())
	{
		if (!strcmp(m.szModule, "client.dll"))
		{
			bClient = reinterpret_cast<DWORD>(m.modBaseAddr);
			break;
		}
	}

	for (auto m : MemoryManager->GetModules())
	{
		if (!strcmp(m.szModule, "engine.dll"))
		{
			bEngine = reinterpret_cast<DWORD>(m.modBaseAddr);
			break;
		}
	}

	std::cout << "Ozone started!" << std::endl;

	Beep(1000, 200);

	while (true)
	{
		MemoryManager->Read<DWORD>(bClient + LocalPlayer, LocalBase);

		DWORD myteam = 0;
		MemoryManager->Read<DWORD>(LocalBase + iTeam, myteam);

		for (int i = 0; i <= 64; ++i)
		{
			DWORD player = 0;
			MemoryManager->Read<DWORD>(bClient + EntityList + (i - 1) * 0x10, player);

			DWORD team = 0;
			MemoryManager->Read<DWORD>(player + iTeam, team);

			bool dormant = false;
			MemoryManager->Read<bool>(player + oDormant, dormant);
			bool isVisible = 0;
			MemoryManager->Read<bool>(player + bSpottedMask, isVisible);

			if (team != myteam && !dormant) // if enemy
			{
				if (isVisible)
					makelight(player, visible);
				else
					makelight(player, invisible);

				MemoryManager->Write(player + bSpotted, 1); // Write 1 to let us see him on radar
			}
		}

		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			BYTE fFlags = 0;
			MemoryManager->Read<BYTE>(LocalBase + oFlags, fFlags);

			if (fFlags & (1 << 0)) // Check for FL_ONGROUND
			{
				MemoryManager->Write(bClient + forceJump, 6); // Will force jump for 1 tick only
			}
		}

		if (GetAsyncKeyState(VK_DELETE) & 0x8000)
		{
			std::cout << "Closing Ozone!" << std::endl;
			Beep(500, 200);
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return 0;
}