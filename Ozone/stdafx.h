﻿#pragma once
#pragma comment(lib,"ws2_32.lib")

#include <ctime> // For std::chrono
#include <thread> // For std::this_thread

#include <algorithm>
#include <windows.h> //Standard Windows Functions/Data Types
#include <iostream> //Constains Input/Output Functions (cin/cout etc..)
#include <TlHelp32.h> //Contains Read/Write Functions
#include <string> //Support For Strings
#include <sstream> //Supports Data Conversion
#include <vector>

#include <d3dx9.h>

#include <stdio.h>
#include <tchar.h>

#include "CMemoryManager.h"
#include "Offsets.h"
#include "Config.h"
#include "Files.h"
#include "XOR.h"