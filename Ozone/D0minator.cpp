#include "stdafx.h"

CMemoryManager* MemoryManager;

struct Vector
{
	float x, y, z;
};

class NoFlash {
private:
	bool isRunning;
public:
	bool isNoFlash;

	NoFlash(bool isNoFlash = false) {
		this->isNoFlash = isNoFlash;
	}

	void Start() {
		this->isRunning = true;

		while (this->isRunning)
		{
			MemoryManager->Read<DWORD>(Offsets::bClient + Offsets::LocalPlayer, Offsets::LocalBase);

			float FlashAlpha = 0.f;
			MemoryManager->Read<float>(Offsets::LocalBase + Offsets::flFlashMaxAlpha, FlashAlpha);

			float flashAlpha;

			if (this->isNoFlash)
				flashAlpha = float(Config::FlashPercentage / 100.f * 255.f);
			else
				flashAlpha = 255.f;

			if (FlashAlpha != flashAlpha)
				MemoryManager->Write(Offsets::LocalBase + Offsets::flFlashMaxAlpha, flashAlpha);

			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
	}

	void Stop() {
		this->isRunning = false;
	}
};

class ESP {
private:
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
		DWORD myTeam = 0;
		MemoryManager->Read<DWORD>(Offsets::LocalBase + Offsets::iTeam, myTeam);

		for (int i = 0; i <= 64; ++i)
		{
			DWORD player = 0;
			MemoryManager->Read<DWORD>(Offsets::bClient + Offsets::EntityList + (i - 1) * 0x10, player);

			if (this->isRadarHack)
				MemoryManager->Write(player + Offsets::bSpotted, true);

			if (!this->isWallHack)
				continue;

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
	bool isWallHack;
	bool isRadarHack;

	ESP(bool isWallHack = false, bool isRadarHack = false) {
		this->isWallHack = isWallHack;
		this->isRadarHack = isRadarHack;
	}

	void Start() {
		this->isRunning = true;
		while (this->isRunning) {
			ScanPlayers();
			std::this_thread::sleep_for(std::chrono::milliseconds(16));
		}
	}

	void Stop() {
		this->isRunning = false;
	}
};

class BHOP {
private:
	bool isRunning;
public:
	bool isBhop;

	BHOP(bool isBhop = false) {
		this->isBhop = isBhop;
	}

	void Start() {
		this->isRunning = true;

		while (this->isRunning) {
			if (this->isBhop) {
				if (GetAsyncKeyState(Config::Key::Bhop) & 0x8000)
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
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
		}
	}

	void Stop() {
		this->isRunning = false;
	}
};

class TriggerBot {
private:
	bool isRunning;
public:
	bool isTriggerBot;

	TriggerBot(bool isTriggerBot = false) {
		this->isTriggerBot = isTriggerBot;
	}

	void Start() {
		this->isRunning = true;

		while (this->isRunning) {
			if (isTriggerBot) {
				if (GetAsyncKeyState(Config::Key::Trigger) & 0x8000)
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
							std::this_thread::sleep_for(std::chrono::milliseconds(Config::TriggerDelay));
							MemoryManager->Write(Offsets::bClient + Offsets::forceAttack, 1); //Force Shoot
							std::this_thread::sleep_for(std::chrono::milliseconds(10));
							MemoryManager->Write(Offsets::bClient + Offsets::forceAttack, 0); //Stop Shoot
							std::this_thread::sleep_for(std::chrono::milliseconds(5));
						}
					}
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
		}
	}

	void Stop() {
		this->isRunning = false;
	}
};

ESP Esp;
BHOP Bhop;
NoFlash Noflash;
TriggerBot Triggerbot;

bool WebRequest(std::string url, std::string location, std::string &website_HTML) {
	WSADATA wsaData;
	SOCKET Socket;
	SOCKADDR_IN SockAddr;
	int lineCount = 0;
	int rowCount = 0;
	struct hostent *host;
	std::locale local;
	char buffer[10000];
	int i = 0;
	int nDataLength;

	//HTTP GET
	std::string get_http = "GET /" + location + " HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";


	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cout << "WSAStartup failed.\n";
		system("pause");
		return false;
	}

	Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	host = gethostbyname(url.c_str());

	SockAddr.sin_port = htons(80);
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

	if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0) {
		std::cout << "Could not connect to server";
		system("pause");
		return false;
	}

	// send GET / HTTP
	send(Socket, get_http.c_str(), strlen(get_http.c_str()), 0);

	// recieve html
	while ((nDataLength = recv(Socket, buffer, 10000, 0)) > 0) {
		int i = 0;
		while (buffer[i] >= 32 || buffer[i] == '\n' || buffer[i] == '\r') {

			website_HTML += buffer[i];
			i += 1;
		}
	}

	closesocket(Socket);
	WSACleanup();

	return true;
}

bool getHWID(std::string &hwid) {
	HW_PROFILE_INFO hwProfileInfo;

	if (GetCurrentHwProfile(&hwProfileInfo) != NULL) {
		hwid = hwProfileInfo.szHwProfileGuid;
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	std::string title = "D0minator.xyz Version - " + Config::Version;

	SetConsoleTitle(_T(title.c_str()));

	std::string hwid;

	if (!getHWID(hwid)) {
		std::cout << "Error reading serial";
		system("pause");
		return 0;
	}

	std::hash<std::string> hash_fn;
	size_t str_hash = hash_fn((hwid + "D0minator.xyz"));

	std::string response;

	printf("Connecting to server\n");
	if (!WebRequest("api.d0minator.xyz", ("api/" + std::to_string(str_hash)), response))
		return 0;

	response.erase(std::remove(response.begin(), response.end(), '\r'), response.end());

	std::vector<std::string> results;

	int last_split = 0;
	for (int i = 0; i < response.length(); i++) {

		if (response[i] == '\n') {
			results.push_back(response.substr(last_split, i - last_split));
			last_split = i + 1;
		}
	}

	std::string sCode;
	std::string sStatus;
	std::string sVersion;
	std::string sDaysLeft;

	for (std::string &result : results) {
		if (result.find("Code:") != -1)
			sCode = result.substr(6, result.length());

		if (result.find("Status:") != -1)
			sStatus = result.substr(8, result.length());

		if (result.find("Version:") != -1)
			sVersion = result.substr(9, result.length());

		if (result.find("DaysLeft:") != -1)
			sDaysLeft = result.substr(10, result.length());
	}

	if (!sCode.length() > 0 || !sStatus.length() > 0 && !sVersion.length() > 0 && !sDaysLeft.length() > 0) {
		printf("Error connecting to server");
		system("pause");
		return 0;
	}
	
	system("cls");

	if (strcmp(sVersion.c_str(), Config::Version.c_str())) {
		printf("I'm an obsolete design.\nNew D0minator.xyz is faster, more powerful and more intelligent. It's a far more effective killing machine\n");
		system("pause");
		return 0;
	}

	if (strcmp(sStatus.c_str(), "Activated")) {
		printf("Activate your serial using the following code: %s\n", sCode.c_str());
		system("pause");
		return 0;
	}

	printf("Welcome to D0minator.xyz! You have %s days left!\n", sDaysLeft.c_str());

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


	//std::cout << "Waiting for modules!" << std::endl;

	while (!MemoryManager->GrabModule("client_panorama.dll") || !MemoryManager->GrabModule("engine.dll")) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	}

	//std::cout << "Modules Found" << std::endl;


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

	printf("D0minator.xyz started!\n");
	printf("Come with me if you want to live\n");

	Beep(1000, 200);

	Esp = ESP(Config::WHDefault, Config::RadarDefault);
	Bhop = BHOP(Config::BHopDefault);
	Noflash = NoFlash(Config::NoFlashDefault);
	Triggerbot = TriggerBot(Config::TriggerDefault);

	std::thread tEsp(&ESP::Start, &Esp);
	std::thread tBhop(&BHOP::Start, &Bhop);
	std::thread tNoFlash(&NoFlash::Start, &Noflash);
	std::thread tTriggerBot(&TriggerBot::Start, &Triggerbot);

	while (true)
	{
		if (GetAsyncKeyState(Config::Key::Exit) & 0x8000)
		{
			std::cout << "Hasta la vista, baby!" << std::endl;
			Beep(500, 200);

			Esp.Stop();
			Bhop.Stop();
			Noflash.Stop();
			Triggerbot.Stop();

			tEsp.join();
			tBhop.join();
			tNoFlash.join();
			tTriggerBot.join();

			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;
		}
		if (GetAsyncKeyState(Config::Key::ToggleBHop) & 0x8000)
		{
			Bhop.isBhop = !Bhop.isBhop;

			if (Bhop.isBhop)
				Beep(1000, 200);
			else
				Beep(500, 200);

			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		if (GetAsyncKeyState(Config::Key::ToggleNoFlash) & 0x8000)
		{
			Noflash.isNoFlash = !Noflash.isNoFlash;

			if (Noflash.isNoFlash)
				Beep(1000, 200);
			else
				Beep(500, 200);

			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		if (GetAsyncKeyState(Config::Key::ToggleRadar) & 0x8000)
		{
			Esp.isRadarHack = !Esp.isRadarHack;

			if (Esp.isRadarHack)
				Beep(1000, 200);
			else
				Beep(500, 200);

			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		if (GetAsyncKeyState(Config::Key::ToggleTrigger) & 0x8000)
		{
			Triggerbot.isTriggerBot = !Triggerbot.isTriggerBot;
			
			if (Triggerbot.isTriggerBot)
				Beep(1000, 200);
			else
				Beep(500, 200);

			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		if (GetAsyncKeyState(Config::Key::ToggleWH) & 0x8000)
		{
			Esp.isWallHack = !Esp.isWallHack;

			if (Esp.isWallHack)
				Beep(1000, 200);
			else
				Beep(500, 200);

			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	return 0;
}