#pragma once

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include <sstream>
#include "pokedeps.h"

using namespace std;

void xpbarfunc(int xp, int maxxp)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);
	char xp1 = 219;
	char xp2 = 221;
	double xxp = (maxxp / 20.00);
	string xpbar = "";
	int spaces = 0;
	int half = 0;
	if ((xp >= (maxxp - (19 * xxp)))) {
		xpbar = xp2;
		spaces = 9;
	}
	if ((xp >= (maxxp - (18 * xxp)))) {
		xpbar = xp1;
		spaces = 9;
		half = 0;
	}
	if ((xp >= (maxxp - (17 * xxp)))) {
		xpbar = xp1;
		spaces = 8;
		half = 1;
	}
	if ((xp >= (maxxp - (16 * xxp)))) {
		xpbar = string(2, xp1);
		half = 0;
	}
	if ((xp >= (maxxp - (15 * xxp)))) {
		xpbar = string(2, xp1);
		spaces = 7;
		half = 1;
	}
	if ((xp >= (maxxp - (14 * xxp)))) {
		xpbar = string(3, xp1);
		half = 0;
	}
	if ((xp >= (maxxp - (13 * xxp)))) {
		xpbar = string(3, xp1);
		spaces = 6;
		half = 1;
	}
	if ((xp >= (maxxp - (12 * xxp)))) {
		xpbar = string(4, xp1);
		half = 0;
	}
	if ((xp >= (maxxp - (11 * xxp)))) {
		xpbar = string(4, xp1);
		spaces = 5;
		half = 1;
	}
	if ((xp >= (maxxp - (10 * xxp)))) {
		xpbar = string(5, xp1);
		half = 0;
	}
	if ((xp >= (maxxp - (9 * xxp)))) {
		xpbar = string(5, xp1);
		spaces = 4;
		half = 1;
	}
	if ((xp >= (maxxp - (8 * xxp)))) {
		xpbar = string(6, xp1);
		half = 0;
	}
	if ((xp >= (maxxp - (7 * xxp)))) {
		xpbar = string(6, xp1);
		spaces = 3;
		half = 1;
	}
	if ((xp >= (maxxp - (6 * xxp)))) {
		xpbar = string(7, xp1);
		half = 0;
	}
	if ((xp >= (maxxp - (5 * xxp)))) {
		xpbar = string(7, xp1);
		spaces = 2;
		half = 1;
	}
	if ((xp >= (maxxp - (4 * xxp)))) {
		xpbar = string(8, xp1);
		half = 0;
	}
	if ((xp >= (maxxp - (3 * xxp)))) {
		xpbar = string(8, xp1);
		spaces = 1;
		half = 1;
	}
	if ((xp >= (maxxp - (2 * xxp)))) {
		xpbar = string(9, xp1);
		half = 0;
	}
	if ((xp >= (maxxp - (1 * xxp)))) {
		xpbar = string(9, xp1);
		spaces = 0;
		half = 1;
	}
	if ((xp >= maxxp)) {
		xpbar = string(10, xp1);
		spaces = 0;
		half = 0;
	}
	SetConsoleTextAttribute(hConsole, 9);
	cout << xpbar;
	if (half == 1) {
		cout << xp2;
	}
	cout << string(spaces, ' ');
	SetConsoleTextAttribute(hConsole, 7);
}

int hpstat(double lvl, double iv, double ev, double base)
{
	double hpx = ((((((base + iv) * 2) + ((sqrt(ev)) / 4)) * lvl) / 100) + lvl + 10);
	int hp = hpx;
	return hp;
}

int stat(double lvl, double iv, double ev, double base)
{
	double statx = ((((((base + iv) * 2) + (ev / 4)) * lvl) / 100) + 5);
	int stat = statx;
	return stat;
}

int nlevelrate(int lvl, int lvlrate) {
	int n = lvl + 1;
	int nextl = 0;
	int prel = 0;
	switch (lvlrate) {
	case 1:
		nextl = (4 * (pow(n, 3))) / 5;
		prel = (4 * (pow(lvl, 3))) / 5;
		break;
	case 2:
		nextl = pow(n, 3);
		prel = pow(lvl, 3);
		break;
	case 3:
		nextl = (1.2*(pow(n, 3))) - (15 * (pow(n, 2))) + (100 * n) - 140;
		prel = (1.2*(pow(lvl, 3))) - (15 * (pow(lvl, 2))) + (100 * lvl) - 140;
		break;
	case 4:
		nextl = (5 * (pow(n, 3))) / 4;
		prel = (5 * (pow(lvl, 3))) / 4;
		break;
	}
	return nextl;
}

int prelevelrate(int lvl, int lvlrate) {
	int n = lvl + 1;
	int nextl = 0;
	int prel = 0;
	switch (lvlrate) {
	case 1:
		nextl = (4 * (pow(n, 3))) / 5;
		prel = (4 * (pow(lvl, 3))) / 5;
		break;
	case 2:
		nextl = pow(n, 3);
		prel = pow(lvl, 3);
		break;
	case 3:
		nextl = (1.2*(pow(n, 3))) - (15 * (pow(n, 2))) + (100 * n) - 140;
		prel = (1.2*(pow(lvl, 3))) - (15 * (pow(lvl, 2))) + (100 * lvl) - 140;
		break;
	case 4:
		nextl = (5 * (pow(n, 3))) / 4;
		prel = (5 * (pow(lvl, 3))) / 4;
		break;
	}
	return prel;
}

int levelcheck(int lvl, int exp, int lvlrate, string pokename)
{
LEVELCHECK:
	int n = lvl + 1;
	int nextl = nlevelrate(lvl, lvlrate);
	int prel = prelevelrate(lvl, lvlrate);
	if (exp >= nextl) {
		lvl++;
		cout << pokename << " has reached level " << lvl << "!\n";
		goto LEVELCHECK;
	}
	cout << "[";
	xpbarfunc((exp - prel), (nextl - prel));
	cout << "]\n" << (exp - prel) << "/" << (nextl - prel) << endl;
	return lvl;
}

void summary(string pokename, string opokename, int lvl, int exp, int lvlrate, int hp, int stats[5], string mname1, string mname2, string mname3, string mname4, int move1[5], int move2[5], int move3[5], int move4[5]) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);
	cout << pokename << " (" << opokename << ")\n\nSUMMARY:\nLevel - " << lvl << " (" << (exp - prelevelrate(lvl, lvlrate)) << "/" << (nlevelrate(lvl, lvlrate) - prelevelrate(lvl, lvlrate)) << " EXP)" << "\nHP - " << hp << "/" << stats[0] << "\nAttack - " << stats[1] << "\nDefense - " << stats[2] << "\nSpecial - " << stats[3] << "\nSpeed - " << stats[4] << "\n\nMOVES:\n";
	switch (move1[4]) {
	case 1:
		SetConsoleTextAttribute(hConsole, 15);
		break;
	case 2:
		SetConsoleTextAttribute(hConsole, 12);
		break;
	case 3:
		SetConsoleTextAttribute(hConsole, 4);
		break;
	case 4:
		SetConsoleTextAttribute(hConsole, 9);
		break;
	case 5:
		SetConsoleTextAttribute(hConsole, 11);
		break;
	case 6:
		SetConsoleTextAttribute(hConsole, 2);
		break;
	case 7:
		SetConsoleTextAttribute(hConsole, 5);
		break;
	case 8:
		SetConsoleTextAttribute(hConsole, 14);
		break;
	case 9:
		SetConsoleTextAttribute(hConsole, 6);
		break;
	case 10:
		SetConsoleTextAttribute(hConsole, 13);
		break;
	case 11:
		SetConsoleTextAttribute(hConsole, 8);
		break;
	case 12:
		SetConsoleTextAttribute(hConsole, 3);
		break;
	case 13:
		SetConsoleTextAttribute(hConsole, 10);
		break;
	case 14:
		SetConsoleTextAttribute(hConsole, 1);
		break;
	case 15:
		SetConsoleTextAttribute(hConsole, 7);
		break;
	}
	cout << mname1 << endl;
	switch (move2[4]) {
	case 1:
		SetConsoleTextAttribute(hConsole, 15);
		break;
	case 2:
		SetConsoleTextAttribute(hConsole, 12);
		break;
	case 3:
		SetConsoleTextAttribute(hConsole, 4);
		break;
	case 4:
		SetConsoleTextAttribute(hConsole, 9);
		break;
	case 5:
		SetConsoleTextAttribute(hConsole, 11);
		break;
	case 6:
		SetConsoleTextAttribute(hConsole, 2);
		break;
	case 7:
		SetConsoleTextAttribute(hConsole, 5);
		break;
	case 8:
		SetConsoleTextAttribute(hConsole, 14);
		break;
	case 9:
		SetConsoleTextAttribute(hConsole, 6);
		break;
	case 10:
		SetConsoleTextAttribute(hConsole, 13);
		break;
	case 11:
		SetConsoleTextAttribute(hConsole, 8);
		break;
	case 12:
		SetConsoleTextAttribute(hConsole, 3);
		break;
	case 13:
		SetConsoleTextAttribute(hConsole, 10);
		break;
	case 14:
		SetConsoleTextAttribute(hConsole, 1);
		break;
	case 15:
		SetConsoleTextAttribute(hConsole, 7);
		break;
	}
	cout << mname2 << endl;
	switch (move3[4]) {
	case 1:
		SetConsoleTextAttribute(hConsole, 15);
		break;
	case 2:
		SetConsoleTextAttribute(hConsole, 12);
		break;
	case 3:
		SetConsoleTextAttribute(hConsole, 4);
		break;
	case 4:
		SetConsoleTextAttribute(hConsole, 9);
		break;
	case 5:
		SetConsoleTextAttribute(hConsole, 11);
		break;
	case 6:
		SetConsoleTextAttribute(hConsole, 2);
		break;
	case 7:
		SetConsoleTextAttribute(hConsole, 5);
		break;
	case 8:
		SetConsoleTextAttribute(hConsole, 14);
		break;
	case 9:
		SetConsoleTextAttribute(hConsole, 6);
		break;
	case 10:
		SetConsoleTextAttribute(hConsole, 13);
		break;
	case 11:
		SetConsoleTextAttribute(hConsole, 8);
		break;
	case 12:
		SetConsoleTextAttribute(hConsole, 3);
		break;
	case 13:
		SetConsoleTextAttribute(hConsole, 10);
		break;
	case 14:
		SetConsoleTextAttribute(hConsole, 1);
		break;
	case 15:
		SetConsoleTextAttribute(hConsole, 7);
		break;
	}
	cout << mname3 << endl;
	switch (move4[4]) {
	case 1:
		SetConsoleTextAttribute(hConsole, 15);
		break;
	case 2:
		SetConsoleTextAttribute(hConsole, 12);
		break;
	case 3:
		SetConsoleTextAttribute(hConsole, 4);
		break;
	case 4:
		SetConsoleTextAttribute(hConsole, 9);
		break;
	case 5:
		SetConsoleTextAttribute(hConsole, 11);
		break;
	case 6:
		SetConsoleTextAttribute(hConsole, 2);
		break;
	case 7:
		SetConsoleTextAttribute(hConsole, 5);
		break;
	case 8:
		SetConsoleTextAttribute(hConsole, 14);
		break;
	case 9:
		SetConsoleTextAttribute(hConsole, 6);
		break;
	case 10:
		SetConsoleTextAttribute(hConsole, 13);
		break;
	case 11:
		SetConsoleTextAttribute(hConsole, 8);
		break;
	case 12:
		SetConsoleTextAttribute(hConsole, 3);
		break;
	case 13:
		SetConsoleTextAttribute(hConsole, 10);
		break;
	case 14:
		SetConsoleTextAttribute(hConsole, 1);
		break;
	case 15:
		SetConsoleTextAttribute(hConsole, 7);
		break;
	}
	cout << mname4 << endl;
	SetConsoleTextAttribute(hConsole, 7);
	system("pause");
}

void eviv(string pokename, string opokename, int iv[5], int ev[5]) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);
	system("cls");
	cout << pokename << " (" << opokename << ")\n\nEVs:\n" << "\nHP - " << ev[0] << "\nAttack - " << ev[1] << "\nDefense - " << ev[2] << "\nSpecial - " << ev[3] << "\nSpeed - " << ev[4] << "\n\nIVs:\n" << "\nHP - " << iv[0] << "\nAttack - " << iv[1] << "\nDefense - " << iv[2] << "\nSpecial - " << iv[3] << "\nSpeed - " << iv[4] << endl;
	system("pause");
}