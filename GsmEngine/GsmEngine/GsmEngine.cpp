// GsmEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <Windows.h>

//Setting a default height and width of game
int nScreenHeight = 40;
int nScreenWidth = 120;

//Setting player X and Y
float playerX = 0.0;
float playerY = 0.0;
//PLayer angle
float playerA = 0.0;

//Mini Map (#-  Walls   .-  Empty space)
int nMapWidth = 16;
int nMapHeight = 16;


float fFOV=3.14159/4 //pi/4 field of view

int main()
{
	//Setting up variables
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);

	DWORD dwBytesWritten = 0;

	//Uni string for map

	wstring map;
	//Create a map manually
	map += L"################";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"##............##";
	map += L"################";

	//Game loop
	while (1)
	{
		//Not bothered to look up and down so only writing for x-y axis
		for(int x=0;x<nScreenWidth;x++)
			{
			float fRayAngle = ((fPlayerA - fFOV) / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;
		}
		//Setting array and showing character on screen
	screen[nScreenWidth * nScreenHeight - 1] = '\0';
	//{0,0} means start writing from top-left
	WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}
    
}

