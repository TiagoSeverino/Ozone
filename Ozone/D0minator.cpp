#include "stdafx.h"
#pragma warning ( disable : 4789 )

//#define Test_Mod
#ifndef Test_Mod
	#define _api_url "api.d0minator.xyz"
#else
	#define _api_url "localhost"
#endif // Test_Mod

#define api_url std::string(_api_url)

CMemoryManager* MemoryManager;

float RandomFloat(float min, float max)
{
	float random = ((float)rand()) / (float)RAND_MAX;

	float range = max - min;
	return (random*range) + min;
}

struct Vector
{
	float x, y, z;
	Vector();
	Vector(float _X, float _Y, float _Z);
	Vector operator- (const Vector &A);
	Vector operator+ (const Vector &A);
	Vector operator* (const float A);
	Vector operator/ (const float A);
};

Vector::Vector()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Vector::Vector(float _X, float _Y, float _Z)
{
	this->x = _X;
	this->y = _Y;
	this->z = _Z;
}

Vector Vector::operator* (const float A)
{
	return Vector(this->x * A, this->y * A, this->z * A);
}

Vector Vector::operator/ (const float A)
{
	return Vector(this->x / A, this->y / A, this->z / A);
}

Vector Vector::operator- (const Vector &A)
{
	return Vector(this->x - A.x, this->y - A.y, this->z - A.z);
}

Vector Vector::operator+ (const Vector &A)
{
	return Vector(this->x + A.x, this->y + A.y, this->z + A.z);
}

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

			std::this_thread::sleep_for(std::chrono::milliseconds(100));
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

		DWORD m_iShotsFired = 0xA2C0;
		DWORD m_aimPunchAngle = 0x301C;
		DWORD dwClientState_ViewAngles = 0x4D10;
		DWORD dwClientState = 0x588A74;

		Vector punchAngles;
		Vector viewAngles;
		Vector NewAngles;

		while (this->isRunning) {
			if (this->isBhop) {
				MemoryManager->Read<DWORD>(Offsets::bClient + Offsets::LocalPlayer, Offsets::LocalBase);

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

class RCS {
private:
	bool isRunning;

	Vector punchAngles;
	Vector viewAngles;
	Vector NewAngles;
public:
	bool isRCS;

	RCS(bool isRCS = false) {
		this->isRCS = isRCS;
	}

	void Start() {
		this->isRunning = true;

		bool wasShoot = false;

		while (this->isRunning) {
			if (this->isRCS) {
				std::this_thread::sleep_for(std::chrono::milliseconds(15));

				DWORD player = 0;
				MemoryManager->Read<DWORD>(Offsets::bEngine + Offsets::dwClientState, player);

				MemoryManager->Read<DWORD>(Offsets::bClient + Offsets::LocalPlayer, Offsets::LocalBase);

				int shotsFired = 0;
				MemoryManager->Read<int>(Offsets::LocalBase + Offsets::m_iShotsFired, shotsFired);

				MemoryManager->Read<Vector>(Offsets::LocalBase + Offsets::m_aimPunchAngle, punchAngles);

				if (shotsFired < 2)
				{
					if (wasShoot) {
						wasShoot = !wasShoot;
						MemoryManager->Write(player + Offsets::dwViewAngles, viewAngles);//Sets new Viewangles
					}

					MemoryManager->Read<Vector>(player + Offsets::dwViewAngles, viewAngles);//Gets Viewangles
				}
				else
				{
					if (punchAngles.x == 0.0f && punchAngles.y == 0.0f)//So it doesnt lock xhair when using grenades/knife/c4.
						continue;

					NewAngles = viewAngles;
					NewAngles.x -= punchAngles.x * float(Config::RcsVerticalSmooth / 100.f * 2.f + RandomFloat(-0.1f, 0.1f));
					NewAngles.y -= punchAngles.y * float(Config::RcsHorizontalSmooth / 100.f * 2.f + RandomFloat(-0.1f, 0.1f));
					NewAngles.z = 0.f;

					MemoryManager->Write(player + Offsets::dwViewAngles, NewAngles);//Sets new Viewangles

					wasShoot = true;
				}
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
RCS Rcs;
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
		std::cout << "Could not connect to server\n";
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

VOID startup(LPCTSTR lpApplicationName)
{
	// additional information
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// start the program up
	CreateProcess(lpApplicationName,   // the path
		NULL,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	);
	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

int main()
{
	volatile bool notActivated = true;

	system("cls");
	std::string title = "D0minator.xyz Version - " + Config::Version;

	SetConsoleTitle(_T(title.c_str()));

	g_pFiles->OnSetup("config.cfg", "C:\\D0minator\\");

	char elem[] = "Features";

	bool b = true;
	char field[] = "WallHack";
	Config::WHDefault = g_pFiles->ReadBool(elem, field);
	strcpy(field, "NoFlash");
	Config::NoFlashDefault = g_pFiles->ReadBool(elem, field);
	strcpy(field, "TriggerBot");
	Config::TriggerDefault = g_pFiles->ReadBool(elem, field);
	strcpy(field, "RadarHack");
	Config::RadarDefault = g_pFiles->ReadBool(elem, field);
	strcpy(field, "BHOP");
	Config::BHopDefault = g_pFiles->ReadBool(elem, field);
	strcpy(field, "RCS");
	Config::RCSDefault = g_pFiles->ReadBool(elem, field);

	strcpy(field, "ToggleWallHack");
	Config::Key::ToggleWH = g_pFiles->ReadInt(elem, field);
	strcpy(field, "ToggleNoFlash");
	Config::Key::ToggleNoFlash = g_pFiles->ReadInt(elem, field);
	strcpy(field, "ToggleTriggerBot");
	Config::Key::ToggleTrigger = g_pFiles->ReadInt(elem, field);
	strcpy(field, "ToggleRadarHack");
	Config::Key::ToggleRadar = g_pFiles->ReadInt(elem, field);
	strcpy(field, "ToggleBHOP");
	Config::Key::ToggleBHop = g_pFiles->ReadInt(elem, field);
	strcpy(field, "ToggleRCS");
	Config::Key::ToggleRCS = g_pFiles->ReadInt(elem, field);
	strcpy(field, "Exit");
	Config::Key::Exit = g_pFiles->ReadInt(elem, field);
	strcpy(field, "EnableTriggerBot");
	Config::Key::Trigger = g_pFiles->ReadInt(elem, field);

	strcpy(field, "Delay");
	Config::TriggerDelay = g_pFiles->ReadInt(elem, field);

	strcpy(field, "FlashPercentage");
	Config::FlashPercentage = g_pFiles->ReadInt(elem, field);

	strcpy(field, "RcsVerticalSmoothPercentage");
	Config::RcsVerticalSmooth = g_pFiles->ReadInt(elem, field);
	strcpy(field, "RcsHorizontalSmoothPercentage");
	Config::RcsHorizontalSmooth = g_pFiles->ReadInt(elem, field);

	std::string hwid;

	if (!getHWID(hwid)) {
		std::cout << "Error reading serial" << std::endl;
		system("pause");
		return 0;
	}

	std::hash<std::string> hash_fn;
	size_t str_hash = hash_fn((hwid + "D0minator.xyz"));

	std::string response;

	printf("Connecting to server\n");
	if (!WebRequest(api_url, ("api/" + std::to_string(str_hash)), response)) {
		std::cout << "Error connecting to server" << std::endl;
		system("pause");
		return 0;
	}

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
	std::string sHoursLeft;
	std::string sMinutesLeft;

	for (std::string &result : results) {
		if (result.find("Code:") != -1)
			sCode = result.substr(6, result.length());

		if (result.find("Status:") != -1)
			sStatus = result.substr(8, result.length());

		if (result.find("Version:") != -1)
			sVersion = result.substr(9, result.length());

		if (result.find("DaysLeft:") != -1)
			sDaysLeft = result.substr(10, result.length());

		if (result.find("HoursLeft:") != -1)
			sHoursLeft = result.substr(11, result.length());

		if (result.find("MinutesLeft:") != -1)
			sMinutesLeft = result.substr(13, result.length());
	}

	if (!sCode.length() > 0 || !sStatus.length() > 0 && !sVersion.length() > 0 && !sDaysLeft.length() > 0 && !sHoursLeft.length() > 0 && !sMinutesLeft.length() > 0) {
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
		printf("Insert your serial key: ");

		std::string line;
		std::getline(std::cin, line);

		response.clear();
		WebRequest(api_url, ("api/" + sCode + "/" + line), response);

		response.erase(std::remove(response.begin(), response.end(), '\r'), response.end());

		notActivated = true;

		results.clear();

		last_split = 0;
		for (int i = 0; i < response.length(); i++) {
			if (response[i] == '\n') {
				results.push_back(response.substr(last_split, i - last_split));
				last_split = i + 1;
			}
		}

		std::string res;

		for (std::string &result : results) 
			if (result.find("Res:") != -1)
				res = result.substr(5, result.length());

		printf("%s\n", res.c_str());
		system("pause");


		char myPath[_MAX_PATH + 1];
		GetModuleFileName(NULL, myPath, _MAX_PATH);

		startup(myPath);
		return 0;
	}
	else
	{
		if (!strcmp(sStatus.c_str(), "Activated") && notActivated) {
			notActivated = false;
		}
		else
		{
			printf("Insert your serial key: ");

			std::string line;
			std::getline(std::cin, line);

			response.clear();
			WebRequest(api_url, ("api/" + sCode + "/" + line), response);

			response.erase(std::remove(response.begin(), response.end(), '\r'), response.end());

			notActivated = true;

			results.clear();

			last_split = 0;
			for (int i = 0; i < response.length(); i++) {
				if (response[i] == '\n') {
					results.push_back(response.substr(last_split, i - last_split));
					last_split = i + 1;
				}
			}

			std::string res;

			for (std::string &result : results)
				if (result.find("Res:") != -1)
					res = result.substr(5, result.length());

			printf("%s\n", res.c_str());
			system("pause");


			char myPath[_MAX_PATH + 1];
			GetModuleFileName(NULL, myPath, _MAX_PATH);

			startup(myPath);
			return 0;
		}
	}

	printf("Welcome to D0minator.xyz! You have %s days, %s hours and %s minutes left!\n", sDaysLeft.c_str(), sHoursLeft.c_str(), sMinutesLeft.c_str());

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

	while (!MemoryManager->GrabModule("client_panorama.dll") || !MemoryManager->GrabModule("engine.dll"))
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));

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
	Rcs = RCS(Config::RCSDefault);
	Bhop = BHOP(Config::BHopDefault);
	Noflash = NoFlash(Config::NoFlashDefault);
	Triggerbot = TriggerBot(Config::TriggerDefault);

	std::thread tEsp(&ESP::Start, &Esp);
	std::thread tRcs(&RCS::Start, &Rcs);
	std::thread tBhop(&BHOP::Start, &Bhop);
	std::thread tNoFlash(&NoFlash::Start, &Noflash);
	std::thread tTriggerBot(&TriggerBot::Start, &Triggerbot);

	while (true)
	{
		if (GetAsyncKeyState(Config::Key::Exit) & 0x8000 || !FindWindow(NULL, "Counter-Strike: Global Offensive") || strcmp(sStatus.c_str(), "Activated") || notActivated)
		{
			std::cout << "Hasta la vista, baby!" << std::endl;
			Beep(500, 200);

			Esp.Stop();
			Rcs.Stop();
			Bhop.Stop();
			Noflash.Stop();
			Triggerbot.Stop();

			tEsp.join();
			tRcs.join();
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
		if (GetAsyncKeyState(Config::Key::ToggleRCS) & 0x8000)
		{
			Rcs.isRCS = !Rcs.isRCS;

			if (Rcs.isRCS)
				Beep(1000, 200);
			else
				Beep(500, 200);

			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	return 0;
}