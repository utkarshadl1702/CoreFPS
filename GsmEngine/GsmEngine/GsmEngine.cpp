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
float fPlayerA = 0.0;

//Mini Map (#-  Walls   .-  Empty space)
int nMapWidth = 16;
int nMapHeight = 16;


float fFOV = 3.14159 / 4; //pi/4 field of view

//A max size of raycast
float fDepth = 16;

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
			//making a raycast on the players POV and chopping it up into pieces
			float fRayAngle = ((fPlayerA - fFOV) / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;
			float fDistanceToWall = 0;
			bool bHitWall = false;
			//need a unit vector of where the player is looking
			float fEyeX = sinf(fRayAngle);
			float fEyeY = cosf(fRayAngle);
			//cast the ray to the distance where it hits a wall 
			while (!bHitWall && fDepth)
			{
				//small steps 0.1
				fDistanceToWall += 0.1f;

				// now check distance in the unit length of eye
				int nTestX = (int)(playerX + fEyeX * fDistanceToWall);
				int nTestY = (int)(playerY + fEyeY * fDistanceToWall);

				//test for  out of bound
				if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
				{
					bHitWall = true;
					fDistanceToWall = fDepth;
				}
				else
				{
					//within bounds so check if ray hits a # 
					if (map[nTestY * nMapWidth + nTestX]=='#')
					{

					}
				}

			}
		}
		//Setting array and showing character on screen
	screen[nScreenWidth * nScreenHeight - 1] = '\0';
	//{0,0} means start writing from top-left
	WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}
    
}

