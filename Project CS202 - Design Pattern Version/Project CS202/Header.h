#pragma once

#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <deque>
#include <vector>
#include <conio.h>
#include <time.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <string>
#include <thread>

using namespace std;



#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15
#define typeOfObj				4

#define default_ColorCode		7




#endif;

namespace {
	void FixConsoleWindow() {
		HWND consoleWindow = GetConsoleWindow();
		LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
		style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
		SetWindowLong(consoleWindow, GWL_STYLE, style);
	}
	void GotoXY(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void TextColor(int color) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
}