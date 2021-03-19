#pragma once

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

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

void hpbarfunc(int hp, int maxhp)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);
	char hp1 = 219;
	char hp2 = 221;
	double xhp = (maxhp / 20.00);
	string hpbar = "";
	int hpcolor = 2;
	int spaces = 0;
	int half = 0;
	if (hp > (maxhp - xhp)) {
		hpbar = string(10, hp1);
	}
	if ((hp <= (maxhp - xhp))) {
		hpbar = string(9, hp1);
		half = 1;
	}
	if ((hp <= (maxhp - (2 * xhp)))) {
		hpbar = string(9, hp1);
		spaces = 1;
		half = 0;
	}
	if ((hp <= (maxhp - (3 * xhp)))) {
		hpbar = string(8, hp1);
		half = 1;
	}
	if ((hp <= (maxhp - (4 * xhp)))) {
		hpbar = string(8, hp1);
		spaces = 2;
		half = 0;
	}
	if ((hp <= (maxhp - (5 * xhp)))) {
		hpbar = string(7, hp1);
		half = 1;
	}
	if ((hp <= (maxhp - (6 * xhp)))) {
		hpbar = string(7, hp1);
		spaces = 3;
		half = 0;
	}
	if ((hp <= (maxhp - (7 * xhp)))) {
		hpbar = string(6, hp1);
		half = 1;
	}
	if ((hp <= (maxhp - (8 * xhp)))) {
		hpbar = string(6, hp1);
		spaces = 4;
		half = 0;
	}
	if ((hp <= (maxhp - (9 * xhp)))) {
		hpbar = string(5, hp1);
		spaces = 4;
		half = 1;
	}
	if ((hp <= (maxhp - (10 * xhp)))) {
		hpbar = string(5, hp1);
		spaces = 5;
		half = 0;
		hpcolor = 14;
	}
	if ((hp <= (maxhp - (11 * xhp)))) {
		hpbar = string(4, hp1);
		half = 1;
	}
	if ((hp <= (maxhp - (12 * xhp)))) {
		hpbar = string(4, hp1), "      ";
		spaces = 6;
		half = 0;
	}
	if ((hp <= (maxhp - (13 * xhp)))) {
		hpbar = string(3, hp1);
		half = 1;
	}
	if ((hp <= (maxhp - (14 * xhp)))) {
		hpbar = string(3, hp1);
		spaces = 7;
		half = 0;
	}
	if ((hp <= (maxhp - (15 * xhp)))) {
		hpbar = string(2, hp1);
		half = 1;
		hpcolor = 12;
	}
	if ((hp <= (maxhp - (16 * xhp)))) {
		hpbar = string(2, hp1);
		spaces = 8;
		half = 0;
	}
	if ((hp <= (maxhp - (17 * xhp)))) {
		hpbar = hp1;
		half = 1;
	}
	if ((hp <= (maxhp - (18 * xhp)))) {
		hpbar = hp1;
		spaces = 9;
		half = 0;
	}
	if ((hp <= (maxhp - (19 * xhp)))) {
		hpbar = hp2;
	}
	SetConsoleTextAttribute(hConsole, hpcolor);
	cout << hpbar;
	if (half == 1) {
		cout << hp2;
	}
	cout << string(spaces, ' ');
	SetConsoleTextAttribute(hConsole, 7);
}

void battlegui(char *poke, char *epoke, int maxhp, int hp, int emaxhp, int ehp, int lvl, int elvl, string m1, string m2, string m3, string m4, int move1[5], int move1pp, int move2[5], int move2pp, int move3[5], int move3pp, int move4[5], int move4pp)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);
	char tl = 201;
	char tr = 187;
	char t3 = 203;
	char tb = 205;
	char s = 186;
	char l3 = 204;
	char r3 = 185;
	char bl = 200;
	char br = 188;
	char b3 = 202;
	char m = 206;
	char hp1 = 219;
	char hp2 = 221;
	ostringstream hpx;
	ostringstream hpy;
	hpx << " ";
	if ((hp / 100.00) < 1) {
		if ((hp / 10.00) < 1) {
			hpx << string(2, ' ') << hp;
		}
		else {
			hpx << " " << hp;
		}
	}
	else {
		hpx << hp;
	}
	string hpxx = hpx.str();
	if ((maxhp / 100.00) < 1) {
		if ((maxhp / 10.00) < 1) {
			hpy << string(2, ' ') << maxhp;
		}
		else {
			hpy << string(1, ' ') << maxhp;
		}
	}
	else {
		hpy << maxhp;
	}
	string hpyy = hpy.str();
	ostringstream hpz;
	hpz << hpxx << "/" << hpyy;
	string chp = hpz.str();
	ostringstream namex;
	namex << poke;
	int namey = namesize(poke);
	switch (namey) {
	case 1:
		namex << "         ";
		break;
	case 2:
		namex << "        ";
		break;
	case 3:
		namex << "       ";
		break;
	case 4:
		namex << "      ";
		break;
	case 5:
		namex << "     ";
		break;
	case 6:
		namex << "    ";
		break;
	case 7:
		namex << "   ";
		break;
	case 8:
		namex << "  ";
		break;
	case 9:
		namex << " ";
		break;
	case 10:
		break;
	}
	string name = namex.str();
	ostringstream ehpx;
	ostringstream ehpy;
	ehpx << " ";
	if ((ehp / 100.00) < 1) {
		if ((ehp / 10.00) < 1) {
			ehpx << string(2, ' ') << ehp;
		}
		else {
			ehpx << " " << ehp;
		}
	}
	else {
		ehpx << ehp;
	}
	string ehpxx = ehpx.str();
	if ((emaxhp / 100.00) < 1) {
		if ((emaxhp / 10.00) < 1) {
			ehpy << string(3, ' ') << emaxhp;
		}
		else {
			ehpy << string(1, ' ') << emaxhp;
		}
	}
	else {
		ehpy << emaxhp;
	}
	string ehpyy = ehpy.str();
	ostringstream ehpz;
	ehpz << ehpxx << "/" << ehpyy;
	string echp = ehpz.str();
	ostringstream enamex;
	enamex << epoke;
	int enamey = namesize(epoke);
	switch (enamey) {
	case 1:
		enamex << string(9, ' ');
		break;
	case 2:
		enamex << string(8, ' ');
		break;
	case 3:
		enamex << string(7, ' ');
		break;
	case 4:
		enamex << string(6, ' ');
		break;
	case 5:
		enamex << string(5, ' ');
		break;
	case 6:
		enamex << string(4, ' ');
		break;
	case 7:
		enamex << string(3, ' ');
		break;
	case 8:
		enamex << string(2, ' ');
		break;
	case 9:
		enamex << string(1, ' ');
		break;
	case 10:
		break;
	}
	string ename = enamex.str();
	int l = lvl / 10;
	ostringstream level;
	if (l < 1) {
		level << "Lv " << lvl;
	}
	else if (l == 10) {
		level << "L100";
	}
	else {
		level << "Lv" << lvl;
	}
	string lev = level.str();
	int el = elvl / 10;
	ostringstream elevel;
	if (el < 1) {
		elevel << "Lv " << elvl;
	}
	else if (el == 10) {
		elevel << "L100";
	}
	else {
		elevel << "Lv" << elvl;
	}
	string elev = elevel.str();
	cout << string(17, ' ') << tl << string(15, tb) << tr << endl << string(17, ' ') << s << ename << " " << elev << s << endl << string(17, ' ') << s << string(15, ' ') << s << endl << string(17, ' ') << s << echp << string(7, ' ') << s << endl << string(17, ' ') << s << string(3, ' ') << "[";
	hpbarfunc(ehp, emaxhp);
	cout << "]" << s << endl << string(17, ' ') << bl << string(15, tb) << br << endl;
	cout << tl << string(15, tb) << tr << endl << s << name << " " << lev << s << endl << s << string(15, ' ') << s << endl << s << chp << string(7, ' ') << s << endl << s << string(3, ' ') << "[";
	hpbarfunc(hp, maxhp);
	cout << "]" << s << endl << bl << string(15, tb) << br;
}

int bmenu(string o1, string o2, string o3, string o4, char *poke, char *epoke, int maxhp, int hp, int emaxhp, int ehp, int lvl, int elvl, string m1, string m2, string m3, string m4, int move1[5], int move1pp, int move2[5], int move2pp, int move3[5], int move3pp, int move4[5], int move4pp) {
	int c = 0;
	int act = 1;
	int x = 0;
	battlegui(poke, epoke, maxhp, hp, emaxhp, ehp, lvl, elvl, m1, m2, m3, m4, move1, move1pp, move2, move2pp, move3, move3pp, move4, move4pp);
	cout << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3 << "  \n  " << o4;
	while (x == 0) {
		c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			system("cls");
			switch (act) {
			case 1:
				battlegui(poke, epoke, maxhp, hp, emaxhp, ehp, lvl, elvl, m1, m2, m3, m4, move1, move1pp, move2, move2pp, move3, move3pp, move4, move4pp);
				cout << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n> " << o4 << " <";
				act = 4;
				break;
			case 2:
				battlegui(poke, epoke, maxhp, hp, emaxhp, ehp, lvl, elvl, m1, m2, m3, m4, move1, move1pp, move2, move2pp, move3, move3pp, move4, move4pp);
				cout << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3 << "  \n  " << o4;
				act = 1;
				break;
			case 3:
				battlegui(poke, epoke, maxhp, hp, emaxhp, ehp, lvl, elvl, m1, m2, m3, m4, move1, move1pp, move2, move2pp, move3, move3pp, move4, move4pp);
				cout << "\n  " << o1 << "  \n> " << o2 << " <\n  " << o3 << "  \n  " << o4;
				act = 2;
				break;
			case 4:
				battlegui(poke, epoke, maxhp, hp, emaxhp, ehp, lvl, elvl, m1, m2, m3, m4, move1, move1pp, move2, move2pp, move3, move3pp, move4, move4pp);
				cout << "\n  " << o1 << "  \n  " << o2 << "  \n> " << o3 << " <\n  " << o4;
				act = 3;
				break;
			}
			break;
		case KEY_DOWN:
			system("cls");
			switch (act) {
			case 1:
				battlegui(poke, epoke, maxhp, hp, emaxhp, ehp, lvl, elvl, m1, m2, m3, m4, move1, move1pp, move2, move2pp, move3, move3pp, move4, move4pp);
				cout << "\n  " << o1 << "  \n> " << o2 << " <\n  " << o3 << "  \n  " << o4;
				act = 2;
				break;
			case 2:
				battlegui(poke, epoke, maxhp, hp, emaxhp, ehp, lvl, elvl, m1, m2, m3, m4, move1, move1pp, move2, move2pp, move3, move3pp, move4, move4pp);
				cout << "\n  " << o1 << "  \n  " << o2 << "  \n> " << o3 << " <\n  " << o4;
				act = 3;
				break;
			case 3:
				battlegui(poke, epoke, maxhp, hp, emaxhp, ehp, lvl, elvl, m1, m2, m3, m4, move1, move1pp, move2, move2pp, move3, move3pp, move4, move4pp);
				cout << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n> " << o4 << " <";
				act = 4;
				break;
			case 4:
				battlegui(poke, epoke, maxhp, hp, emaxhp, ehp, lvl, elvl, m1, m2, m3, m4, move1, move1pp, move2, move2pp, move3, move3pp, move4, move4pp);
				cout << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3 << "  \n  " << o4;
				act = 1;
				break;
			}
			break;
		case KEY_ENTER:
			x = 1;
			break;
		}
	}
	return act;
}

int attack(double att, double edef, double power, double bspeed, double lvl, int type, int poketype1, int poketype2, int etype1, int etype2)
{
	double critx = ((bspeed * 100.00) / 512.00);
	double crity = (rand() % 255);
	double crit = 1;
	if (critx > crity) {
		crit = ((2.00 * lvl + 5.00) / (lvl + 5.00));
		cout << "Critical Hit!\n";
	}
	double eff = 1.0;
	switch (type) {
	case 1:
		if ((etype1 == 11) || (etype2 == 11)) {
			eff *= 0.50;
		}
		if ((etype1 == 15) || (etype2 == 15)) {
			eff *= 0.00;
		}
		break;
	case 2:
		if ((etype1 == 13) || (etype2 == 13)) {
			eff *= 2.00;
		}
		if ((etype1 == 6) || (etype2 == 6)) {
			eff *= 2.00;
		}
		if ((etype1 == 12) || (etype2 == 12)) {
			eff *= 2.00;
		}
		if ((etype1 == 14) || (etype2 == 14)) {
			eff *= 0.50;
		}
		if ((etype1 == 4) || (etype2 == 4)) {
			eff *= 0.50;
		}
		if ((etype1 == 2) || (etype2 == 2)) {
			eff *= 0.50;
		}
		if ((etype1 == 11) || (etype2 == 11)) {
			eff *= 0.50;
		}
		break;
	case 3:
		if ((etype1 == 1) || (etype2 == 1)) {
			eff *= 2.00;
		}
		if ((etype1 == 11) || (etype2 == 11)) {
			eff *= 2.00;
		}
		if ((etype1 == 12) || (etype2 == 12)) {
			eff *= 2.00;
		}
		if ((etype1 == 7) || (etype2 == 7)) {
			eff *= 0.50;
		}
		if ((etype1 == 5) || (etype2 == 5)) {
			eff *= 0.50;
		}
		if ((etype1 == 13) || (etype2 == 13)) {
			eff *= 0.50;
		}
		if ((etype1 == 10) || (etype2 == 10)) {
			eff *= 0.50;
		}
		if ((etype1 == 15) || (etype2 == 15)) {
			eff *= 0.00;
		}
		break;
	case 4:
		if ((etype1 == 1) || (etype2 == 1)) {
			eff *= 2.00;
		}
		if ((etype1 == 9) || (etype2 == 9)) {
			eff *= 2.00;
		}
		if ((etype1 == 11) || (etype2 == 11)) {
			eff *= 2.00;
		}
		if ((etype1 == 14) || (etype2 == 14)) {
			eff *= 0.50;
		}
		if ((etype1 == 6) || (etype2 == 6)) {
			eff *= 0.50;
		}
		if ((etype1 == 4) || (etype2 == 4)) {
			eff *= 0.50;
		}
		break;
	case 5:
		if ((etype1 == 13) || (etype2 == 13)) {
			eff *= 2.00;
		}
		if ((etype1 == 3) || (etype2 == 3)) {
			eff *= 2.00;
		}
		if ((etype1 == 6) || (etype2 == 6)) {
			eff *= 2.00;
		}
		if ((etype1 == 8) || (etype2 == 8)) {
			eff *= 0.50;
		}
		if ((etype1 == 11) || (etype2 == 11)) {
			eff *= 0.50;
		}
		break;
	case 6:
		if ((etype1 == 9) || (etype2 == 9)) {
			eff *= 2.00;
		}
		if ((etype1 == 11) || (etype2 == 11)) {
			eff *= 2.00;
		}
		if ((etype1 == 4) || (etype2 == 4)) {
			eff *= 2.00;
		}
		if ((etype1 == 13) || (etype2 == 13)) {
			eff *= 0.50;
		}
		if ((etype1 == 14) || (etype2 == 14)) {
			eff *= 0.50;
		}
		if ((etype1 == 2) || (etype2 == 2)) {
			eff *= 0.50;
		}
		if ((etype1 == 5) || (etype2 == 5)) {
			eff *= 0.50;
		}
		if ((etype1 == 6) || (etype2 == 6)) {
			eff *= 0.50;
		}
		if ((etype1 == 7) || (etype2 == 7)) {
			eff *= 0.50;
		}
		break;
	case 7:
		if ((etype1 == 13) || (etype2 == 13)) {
			eff *= 2.00;
		}
		if ((etype1 == 6) || (etype2 == 6)) {
			eff *= 2.00;
		}
		if ((etype1 == 7) || (etype2 == 7)) {
			eff *= 0.50;
		}
		if ((etype1 == 9) || (etype2 == 9)) {
			eff *= 0.50;
		}
		if ((etype1 == 11) || (etype2 == 11)) {
			eff *= 0.50;
		}
		if ((etype1 == 15) || (etype2 == 15)) {
			eff *= 0.50;
		}
		break;
	case 8:
		if ((etype1 == 5) || (etype2 == 5)) {
			eff *= 2.00;
		}
		if ((etype1 == 4) || (etype2 == 4)) {
			eff *= 2.00;
		}
		if ((etype1 == 14) || (etype2 == 14)) {
			eff *= 0.50;
		}
		if ((etype1 == 8) || (etype2 == 8)) {
			eff *= 0.50;
		}
		if ((etype1 == 6) || (etype2 == 6)) {
			eff *= 0.50;
		}
		if ((etype1 == 9) || (etype2 == 9)) {
			eff *= 0.00;
		}
		break;
	case 9:
		if ((etype1 == 8) || (etype2 == 8)) {
			eff *= 2.00;
		}
		if ((etype1 == 2) || (etype2 == 2)) {
			eff *= 2.00;
		}
		if ((etype1 == 7) || (etype2 == 7)) {
			eff *= 2.00;
		}
		if ((etype1 == 11) || (etype2 == 11)) {
			eff *= 2.00;
		}
		if ((etype1 == 13) || (etype2 == 13)) {
			eff *= 0.50;
		}
		if ((etype1 == 6) || (etype2 == 6)) {
			eff *= 0.50;
		}
		if ((etype1 == 5) || (etype2 == 5)) {
			eff *= 0.00;
		}
		break;
	case 10:
		if ((etype1 == 3) || (etype2 == 3)) {
			eff *= 2.00;
		}
		if ((etype1 == 7) || (etype2 == 7)) {
			eff *= 2.00;
		}
		if ((etype1 == 10) || (etype2 == 10)) {
			eff *= 0.50;
		}
		break;
	case 11:
		if ((etype1 == 13) || (etype2 == 13)) {
			eff *= 2.00;
		}
		if ((etype1 == 2) || (etype2 == 2)) {
			eff *= 2.00;
		}
		if ((etype1 == 5) || (etype2 == 5)) {
			eff *= 2.00;
		}
		if ((etype1 == 12) || (etype2 == 12)) {
			eff *= 2.00;
		}
		if ((etype1 == 3) || (etype2 == 3)) {
			eff *= 0.50;
		}
		if ((etype1 == 9) || (etype2 == 9)) {
			eff *= 0.50;
		}
		break;
	case 12:
		if ((etype1 == 14) || (etype2 == 14)) {
			eff *= 2.00;
		}
		if ((etype1 == 5) || (etype2 == 5)) {
			eff *= 2.00;
		}
		if ((etype1 == 6) || (etype2 == 6)) {
			eff *= 2.00;
		}
		if ((etype1 == 9) || (etype2 == 9)) {
			eff *= 2.00;
		}
		if ((etype1 == 12) || (etype2 == 12)) {
			eff *= 0.50;
		}
		if ((etype1 == 4) || (etype2 == 4)) {
			eff *= 0.50;
		}
		break;
	case 13:
		if ((etype1 == 6) || (etype2 == 6)) {
			eff *= 2.00;
		}
		if ((etype1 == 7) || (etype2 == 7)) {
			eff *= 2.00;
		}
		if ((etype1 == 10) || (etype2 == 10)) {
			eff *= 2.00;
		}
		if ((etype1 == 3) || (etype2 == 3)) {
			eff *= 0.50;
		}
		if ((etype1 == 2) || (etype2 == 2)) {
			eff *= 0.50;
		}
		if ((etype1 == 5) || (etype2 == 5)) {
			eff *= 0.50;
		}
		if ((etype1 == 15) || (etype2 == 15)) {
			eff *= 0.50;
		}
		break;
	case 14:
		if ((etype1 == 14) || (etype2 == 14)) {
			eff *= 2.00;
		}
		break;
	case 15:
		if ((etype1 == 15) || (etype2 == 15)) {
			eff *= 2.00;
		}
		if ((etype1 == 1) || (etype2 == 1)) {
			eff *= 0.00;
		}
		if ((etype1 == 10) || (etype2 == 10)) {
			eff *= 0.00;
		}
		break;
	}
	double ranx = rand() % 16 + 85;
	double ran = ranx / 100;
	double stab;
	if ((poketype1 == type) || (poketype2 == type)) {
		stab = 1.50;
	}
	else {
		stab = 1.00;
	}
	double mod = (stab * eff * crit * ran);
	double damx = ((((2.00 * lvl + 10.00) / 250.00) * (att / edef) * power + 2.00) * mod);
	int dam = damx;
	return dam;
}

__int64 battle(string poke, string epoke, int bases[5], int ebases[5], int stats[5], int estats[5], int lvl, int elvl, int hp, int move1[5], int move1pp, int move2[5], int move2pp, int move3[5], int move3pp, int move4[5], int move4pp, string mname1, string mname2, string mname3, string mname4, int emoveno, int emove1[5], int emove2[5], int emove3[5], int emove4[5], string emname1, string emname2, string emname3, string emname4, int type[2], int etype[2])
{
	int tempstats[6] = { 0,0,0,0,0,0 };
	int etempstats[6] = { 0,0,0,0,0,0 };
	double statmods[6] = { 1,1,1,1,1,1 };
	double estatmods[6] = { 1,1,1,1,1,1 };
	int moddedstats[4] = { (stats[1] * statmods[0]),(stats[2] * statmods[1]),(stats[3] * statmods[2]),(stats[4] * statmods[3]) };
	int emoddedstats[4] = { (estats[1] * estatmods[0]),(estats[2] * estatmods[1]),(estats[3] * estatmods[2]),(estats[4] * estatmods[3]) };
	int ehp = estats[0];
	cout << "\nA wild " << epoke << " appeared!\n";
	Sleep(2000);
	int act;
	int dam;
	int moveact;
	int usemove[5] = { 0,0,0,0,0 };
	int edam;
	int eusemove[5] = { 0,0,0,0,0 };
	string eusemname;
	string usemname;
	int escattempts = 0;
	int escx = 0;
	int esc = 0;
	double hit;
	double ehit;
	ostringstream bs;
	string battlestatus;
	ostringstream m1;
	ostringstream m2;
	ostringstream m3;
	ostringstream m4;
	string mo1;
	string mo2;
	string mo3;
	string mo4;
	char poken[1024];
	strncpy_s(poken, poke.c_str(), sizeof(poken));
	poken[sizeof(poken) - 1] = 0;
	char epoken[1024];
	strncpy_s(epoken, epoke.c_str(), sizeof(epoken));
	epoken[sizeof(epoken) - 1] = 0;
	system("cls");
	while (ehp > 0) {
	ACTION:
		system("cls");
		act = 0;
		bs.str(string());
		bs.clear();
		m1.str(string());
		m1.clear();
		m2.str(string());
		m2.clear();
		m3.str(string());
		m3.clear();
		m4.str(string());
		m4.clear();
		char poken[1024];
		strcpy_s(poken, poke.c_str());
		poken[sizeof(poken) - 1] = 0;
		char epoken[1024];
		strcpy_s(epoken, epoke.c_str());
		epoken[sizeof(epoken) - 1] = 0;
		act = bmenu("Fight", "Bag (NYI)", "Party (NYI)", "Run", poken, epoken, stats[0], hp, estats[0], ehp, lvl, elvl, mname1, mname2, mname3, mname4, move1, move1pp, move2, move2pp, move3, move3pp, move4, move4pp);
		switch (act) {
		case 1:
			system("cls");
			m1 << mname1 << " " << move1pp << "/" << move1[3];
			m2 << mname2 << " " << move2pp << "/" << move2[3];
			m3 << mname3 << " " << move3pp << "/" << move3[3];
			m4 << mname4 << " " << move4pp << "/" << move4[3];
			mo1 = m1.str();
			mo2 = m2.str();
			mo3 = m3.str();
			mo4 = m4.str();
			moveact = bmenu(mo1, mo2, mo3, mo4, poken, epoken, stats[0], hp, estats[0], ehp, lvl, elvl, mname1, mname2, mname3, mname4, move1, move1pp, move2, move2pp, move3, move3pp, move4, move4pp);
			switch (moveact) {
			case 1:
				if (move1pp == 0) {
					cout << "Out of PP!\n";
					goto ACTION;
				}
				else {
					usemname = mname1;
					usemove[0] = move1[0];
					usemove[1] = move1[1];
					usemove[2] = move1[2];
					usemove[3] = move1[3];
					usemove[4] = move1[4];
					move1pp -= 1;
				}
				break;
			case 2:
				if (move2pp == 0) {
					cout << "Out of PP!\n";
					goto ACTION;
				}
				else {
					usemname = mname2;
					usemove[0] = move2[0];
					usemove[1] = move2[1];
					usemove[2] = move2[2];
					usemove[3] = move2[3];
					usemove[4] = move2[4];
					move2pp -= 1;
				}
				break;
			case 3:
				if (move3pp == 0) {
					cout << "Out of PP!\n";
					goto ACTION;
				}
				else {
					usemname = mname3;
					usemove[0] = move3[0];
					usemove[1] = move3[1];
					usemove[2] = move3[2];
					usemove[3] = move3[3];
					usemove[4] = move3[4];
					move3pp -= 1;
				}
				break;
			case 4:
				if (move4pp == 0) {
					cout << "Out of PP!\n";
					goto ACTION;
				}
				else {
					usemname = mname4;
					usemove[0] = move4[0];
					usemove[1] = move4[1];
					usemove[2] = move4[2];
					usemove[3] = move4[3];
					usemove[4] = move4[4];
					move4pp -= 1;
				}
				break;
			}
			cout << endl << endl << poke << " used " << usemname << "!\n";
			hit = usemove[2] * (statmods[4] / estatmods[5]);
			if (hit >= (rand() % 99)) {
				switch (usemove[0]) {
				case 1:
					dam = attack(moddedstats[0], emoddedstats[1], usemove[1], bases[4], lvl, usemove[4], type[0], type[1], etype[0], etype[1]);
					ehp -= dam;
					break;
				case 2:
					switch (usemove[1]) {
					case 1:
						switch (etempstats[0]) {
						case 6:
							etempstats[0] = 5;
							estatmods[0] = 3.5;
							cout << epoke << "'s Attack fell!\n";
							break;
						case 5:
							etempstats[0] = 4;
							estatmods[0] = 3;
							cout << epoke << "'s Attack fell!\n";
							break;
						case 4:
							etempstats[0] = 3;
							estatmods[0] = 2.5;
							cout << epoke << "'s Attack fell!\n";
							break;
						case 3:
							etempstats[0] = 2;
							estatmods[0] = 2;
							cout << epoke << "'s Attack fell!\n";
							break;
						case 2:
							etempstats[0] = 1;
							estatmods[0] = 1.5;
							cout << epoke << "'s Attack fell!\n";
							break;
						case 1:
							etempstats[0] = 0;
							estatmods[0] = 1;
							cout << epoke << "'s Attack fell!\n";
							break;
						case 0:
							etempstats[0] = -1;
							estatmods[0] = 0.66;
							cout << epoke << "'s Attack fell!\n";
							break;
						case -1:
							etempstats[0] = -2;
							estatmods[0] = 0.5;
							cout << epoke << "'s Attack fell!\n";
							break;
						case -2:
							etempstats[0] = -3;
							estatmods[0] = 0.4;
							cout << epoke << "'s Attack fell!\n";
							break;
						case -3:
							etempstats[0] = -4;
							estatmods[0] = 0.33;
							cout << epoke << "'s Attack fell!\n";
							break;
						case -4:
							etempstats[0] = -5;
							estatmods[0] = 0.28;
							cout << epoke << "'s Attack fell!\n";
							break;
						case -5:
							etempstats[0] = -6;
							estatmods[0] = 0.25;
							cout << epoke << "'s Attack fell!\n";
							break;
						case -6:
							cout << epoke << "'s Attack can't go lower!\n";
							break;
						}
						break;
					case 11:
						switch (etempstats[1]) {
						case 6:
							etempstats[1] = 5;
							estatmods[1] = 3.5;
							cout << epoke << "'s Defense fell!\n";
							break;
						case 5:
							etempstats[1] = 4;
							estatmods[1] = 3;
							cout << epoke << "'s Defense fell!\n";
							break;
						case 4:
							etempstats[1] = 3;
							estatmods[1] = 2.5;
							cout << epoke << "'s Defense fell!\n";
							break;
						case 3:
							etempstats[1] = 2;
							estatmods[1] = 2;
							cout << epoke << "'s Defense fell!\n";
							break;
						case 2:
							etempstats[1] = 1;
							estatmods[1] = 1.5;
							cout << epoke << "'s Defense fell!\n";
							break;
						case 1:
							etempstats[1] = 0;
							estatmods[1] = 1;
							cout << epoke << "'s Defense fell!\n";
							break;
						case 0:
							etempstats[1] = -1;
							estatmods[1] = 0.66;
							cout << epoke << "'s Defense fell!\n";
							break;
						case -1:
							etempstats[1] = -2;
							estatmods[1] = 0.5;
							cout << epoke << "'s Defense fell!\n";
							break;
						case -2:
							etempstats[1] = -3;
							estatmods[1] = 0.4;
							cout << epoke << "'s Defense fell!\n";
							break;
						case -3:
							etempstats[1] = -4;
							estatmods[1] = 0.33;
							cout << epoke << "'s Defense fell!\n";
							break;
						case -4:
							etempstats[1] = -5;
							estatmods[1] = 0.28;
							cout << epoke << "'s Defense fell!\n";
							break;
						case -5:
							etempstats[1] = -6;
							estatmods[1] = 0.25;
							cout << epoke << "'s Defense fell!\n";
							break;
						case -6:
							cout << epoke << "'s Defense can't go lower!\n";
							break;
						}
						break;
					case 21:
						switch (etempstats[2]) {
						case 6:
							etempstats[2] = 5;
							estatmods[2] = 3.5;
							cout << epoke << "'s Special fell!\n";
							break;
						case 5:
							etempstats[2] = 4;
							estatmods[2] = 3;
							cout << epoke << "'s Special fell!\n";
							break;
						case 4:
							etempstats[2] = 3;
							estatmods[2] = 2.5;
							cout << epoke << "'s Special fell!\n";
							break;
						case 3:
							etempstats[2] = 2;
							estatmods[2] = 2;
							cout << epoke << "'s Special fell!\n";
							break;
						case 2:
							etempstats[2] = 1;
							estatmods[2] = 1.5;
							cout << epoke << "'s Special fell!\n";
							break;
						case 1:
							etempstats[2] = 0;
							estatmods[2] = 1;
							cout << epoke << "'s Special fell!\n";
							break;
						case 0:
							etempstats[2] = -1;
							estatmods[2] = 0.66;
							cout << epoke << "'s Special fell!\n";
							break;
						case -1:
							etempstats[2] = -2;
							estatmods[2] = 0.5;
							cout << epoke << "'s Special fell!\n";
							break;
						case -2:
							etempstats[2] = -3;
							estatmods[2] = 0.4;
							cout << epoke << "'s Special fell!\n";
							break;
						case -3:
							etempstats[2] = -4;
							estatmods[2] = 0.33;
							cout << epoke << "'s Special fell!\n";
							break;
						case -4:
							etempstats[2] = -5;
							estatmods[2] = 0.28;
							cout << epoke << "'s Special fell!\n";
							break;
						case -5:
							etempstats[2] = -6;
							estatmods[2] = 0.25;
							cout << epoke << "'s Special fell!\n";
							break;
						case -6:
							cout << epoke << "'s Special can't go lower!\n";
							break;
						}
						break;
					case 31:
						switch (etempstats[3]) {
						case 6:
							etempstats[3] = 5;
							estatmods[3] = 3.5;
							cout << epoke << "'s Speed fell!\n";
							break;
						case 5:
							etempstats[3] = 4;
							estatmods[3] = 3;
							cout << epoke << "'s Speed fell!\n";
							break;
						case 4:
							etempstats[3] = 3;
							estatmods[3] = 2.5;
							cout << epoke << "'s Speed fell!\n";
							break;
						case 3:
							etempstats[3] = 2;
							estatmods[3] = 2;
							cout << epoke << "'s Speed fell!\n";
							break;
						case 2:
							etempstats[3] = 1;
							estatmods[3] = 1.5;
							cout << epoke << "'s Speed fell!\n";
							break;
						case 1:
							etempstats[3] = 0;
							estatmods[3] = 1;
							cout << epoke << "'s Speed fell!\n";
							break;
						case 0:
							etempstats[3] = -1;
							estatmods[3] = 0.66;
							cout << epoke << "'s Speed fell!\n";
							break;
						case -1:
							etempstats[3] = -2;
							estatmods[3] = 0.5;
							cout << epoke << "'s Speed fell!\n";
							break;
						case -2:
							etempstats[3] = -3;
							estatmods[3] = 0.4;
							cout << epoke << "'s Speed fell!\n";
							break;
						case -3:
							etempstats[3] = -4;
							estatmods[3] = 0.33;
							cout << epoke << "'s Speed fell!\n";
							break;
						case -4:
							etempstats[3] = -5;
							estatmods[3] = 0.28;
							cout << epoke << "'s Speed fell!\n";
							break;
						case -5:
							etempstats[3] = -6;
							estatmods[3] = 0.25;
							cout << epoke << "'s Speed fell!\n";
							break;
						case -6:
							cout << epoke << "'s Speed can't go lower!\n";
							break;
						}
						break;
					case 41:
						switch (etempstats[4]) {
						case 6:
							etempstats[4] = 5;
							estatmods[4] = 3.5;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case 5:
							etempstats[4] = 4;
							estatmods[4] = 3;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case 4:
							etempstats[4] = 3;
							estatmods[4] = 2.5;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case 3:
							etempstats[4] = 2;
							estatmods[4] = 2;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case 2:
							etempstats[4] = 1;
							estatmods[4] = 1.5;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case 1:
							etempstats[4] = 0;
							estatmods[4] = 1;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case 0:
							etempstats[4] = -1;
							estatmods[4] = 0.66;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case -1:
							etempstats[4] = -2;
							estatmods[4] = 0.5;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case -2:
							etempstats[4] = -3;
							estatmods[4] = 0.4;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case -3:
							etempstats[4] = -4;
							estatmods[4] = 0.33;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case -4:
							etempstats[4] = -5;
							estatmods[4] = 0.28;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case -5:
							etempstats[4] = -6;
							estatmods[4] = 0.25;
							cout << epoke << "'s Accuracy fell!\n";
							break;
						case -6:
							cout << epoke << "'s Accuracy can't go lower!\n";
							break;
						}
						break;
					case 51:
						switch (etempstats[5]) {
						case 6:
							etempstats[5] = 5;
							estatmods[5] = 3.5;
							cout << epoke << "'s Evade fell!\n";
							break;
						case 5:
							etempstats[5] = 4;
							estatmods[5] = 3;
							cout << epoke << "'s Evade fell!\n";
							break;
						case 4:
							etempstats[5] = 3;
							estatmods[5] = 2.5;
							cout << epoke << "'s Evade fell!\n";
							break;
						case 3:
							etempstats[5] = 2;
							estatmods[5] = 2;
							cout << epoke << "'s Evade fell!\n";
							break;
						case 2:
							etempstats[5] = 1;
							estatmods[5] = 1.5;
							cout << epoke << "'s Evade fell!\n";
							break;
						case 1:
							etempstats[5] = 0;
							estatmods[5] = 1;
							cout << epoke << "'s Evade fell!\n";
							break;
						case 0:
							etempstats[5] = -1;
							estatmods[5] = 0.66;
							cout << epoke << "'s Evade fell!\n";
							break;
						case -1:
							etempstats[5] = -2;
							estatmods[5] = 0.5;
							cout << epoke << "'s Evade fell!\n";
							break;
						case -2:
							etempstats[5] = -3;
							estatmods[5] = 0.4;
							cout << epoke << "'s Evade fell!\n";
							break;
						case -3:
							etempstats[5] = -4;
							estatmods[5] = 0.33;
							cout << epoke << "'s Evade fell!\n";
							break;
						case -4:
							etempstats[5] = -5;
							estatmods[5] = 0.28;
							cout << epoke << "'s Evade fell!\n";
							break;
						case -5:
							etempstats[5] = -6;
							estatmods[5] = 0.25;
							cout << epoke << "'s Evade fell!\n";
							break;
						case -6:
							cout << epoke << "'s Evade can't go lower!\n";
							break;
						}
						break;
					}
					break;
				}
				if (ehp <= 0) {
					goto BATTLEEND;
				}
			}
			else {
				cout << endl << poke << "'s attack missed!\n";
			}
			escattempts = 0;
			break;
		case 2:
			cout << "Items are not yet implemented.\n";
			goto ACTION;
			break;
		case 3:
			cout << "Parties are not yet implemented.\n";
			goto ACTION;
			break;
		case 4:
			escattempts++;
			escx = ((moddedstats[3] * 32) / ((emoddedstats[3] / 4) % 256)) + 30 * (escattempts);
			if (escx > 255 || escx > rand() % 256 || emoddedstats[3] == 0) {
				esc = 1;
				goto BATTLEEND;
			}
			else {
				cout << "Can't escape!\n";
			}
			break;
		}
		int emoveact = rand() % (emoveno);
		switch (emoveact) {
		case 0:
			eusemname = emname1;
			eusemove[0] = emove1[0];
			eusemove[1] = emove1[1];
			eusemove[2] = emove1[2];
			eusemove[3] = emove1[3];
			eusemove[4] = emove1[4];
			break;
		case 1:
			eusemname = emname2;
			eusemove[0] = emove2[0];
			eusemove[1] = emove2[1];
			eusemove[2] = emove2[2];
			eusemove[3] = emove2[3];
			eusemove[4] = emove2[4];
			break;
		case 2:
			eusemname = emname3;
			eusemove[0] = emove3[0];
			eusemove[1] = emove3[1];
			eusemove[2] = emove3[2];
			eusemove[3] = emove3[3];
			eusemove[4] = emove3[4];
			break;
		case 3:
			eusemname = emname4;
			eusemove[0] = emove4[0];
			eusemove[1] = emove4[1];
			eusemove[2] = emove4[2];
			eusemove[3] = emove4[3];
			eusemove[4] = emove4[4];
			break;
		}
		cout << endl << epoke << " used " << eusemname << "!\n";
		ehit = eusemove[2] * (estatmods[4] / statmods[5]);
		if (ehit >= (rand() % 99)) {
			switch (eusemove[0]) {
			case 1:
				edam = attack(emoddedstats[0], moddedstats[1], eusemove[1], ebases[4], elvl, eusemove[4], etype[0], etype[1], type[0], type[1]);
				hp -= edam;
				break;
			case 2:
				switch (eusemove[1]) {
				case 1:
					switch (tempstats[0]) {
					case 6:
						tempstats[0] = 5;
						statmods[0] = 3.5;
						cout << poke << "'s Attack fell!\n";
						break;
					case 5:
						tempstats[0] = 4;
						statmods[0] = 3;
						cout << poke << "'s Attack fell!\n";
						break;
					case 4:
						tempstats[0] = 3;
						statmods[0] = 2.5;
						cout << poke << "'s Attack fell!\n";
						break;
					case 3:
						tempstats[0] = 2;
						statmods[0] = 2;
						cout << poke << "'s Attack fell!\n";
						break;
					case 2:
						tempstats[0] = 1;
						statmods[0] = 1.5;
						cout << poke << "'s Attack fell!\n";
						break;
					case 1:
						tempstats[0] = 0;
						statmods[0] = 1;
						cout << poke << "'s Attack fell!\n";
						break;
					case 0:
						tempstats[0] = -1;
						statmods[0] = 0.66;
						cout << poke << "'s Attack fell!\n";
						break;
					case -1:
						tempstats[0] = -2;
						statmods[0] = 0.5;
						cout << poke << "'s Attack fell!\n";
						break;
					case -2:
						tempstats[0] = -3;
						statmods[0] = 0.4;
						cout << poke << "'s Attack fell!\n";
						break;
					case -3:
						tempstats[0] = -4;
						statmods[0] = 0.33;
						cout << poke << "'s Attack fell!\n";
						break;
					case -4:
						tempstats[0] = -5;
						statmods[0] = 0.28;
						cout << poke << "'s Attack fell!\n";
						break;
					case -5:
						tempstats[0] = -6;
						statmods[0] = 0.25;
						cout << poke << "'s Attack fell!\n";
						break;
					case -6:
						cout << poke << "'s Attack can't go lower!\n";
						break;
					}
					break;
				case 11:
					switch (tempstats[1]) {
					case 6:
						tempstats[1] = 5;
						statmods[1] = 3.5;
						cout << poke << "'s Defense fell!\n";
						break;
					case 5:
						tempstats[1] = 4;
						statmods[1] = 3;
						cout << poke << "'s Defense fell!\n";
						break;
					case 4:
						tempstats[1] = 3;
						statmods[1] = 2.5;
						cout << poke << "'s Defense fell!\n";
						break;
					case 3:
						tempstats[1] = 2;
						statmods[1] = 2;
						cout << poke << "'s Defense fell!\n";
						break;
					case 2:
						tempstats[1] = 1;
						statmods[1] = 1.5;
						cout << poke << "'s Defense fell!\n";
						break;
					case 1:
						tempstats[1] = 0;
						statmods[1] = 1;
						cout << poke << "'s Defense fell!\n";
						break;
					case 0:
						tempstats[1] = -1;
						statmods[1] = 0.66;
						cout << poke << "'s Defense fell!\n";
						break;
					case -1:
						tempstats[1] = -2;
						statmods[1] = 0.5;
						cout << poke << "'s Defense fell!\n";
						break;
					case -2:
						tempstats[1] = -3;
						statmods[1] = 0.4;
						cout << poke << "'s Defense fell!\n";
						break;
					case -3:
						tempstats[1] = -4;
						statmods[1] = 0.33;
						cout << poke << "'s Defense fell!\n";
						break;
					case -4:
						tempstats[1] = -5;
						statmods[1] = 0.28;
						cout << poke << "'s Defense fell!\n";
						break;
					case -5:
						tempstats[1] = -6;
						statmods[1] = 0.25;
						cout << poke << "'s Defense fell!\n";
						break;
					case -6:
						cout << poke << "'s Defense can't go lower!\n";
						break;
					}
					break;
				case 21:
					switch (tempstats[2]) {
					case 6:
						tempstats[2] = 5;
						statmods[2] = 3.5;
						cout << poke << "'s Special fell!\n";
						break;
					case 5:
						tempstats[2] = 4;
						statmods[2] = 3;
						cout << poke << "'s Special fell!\n";
						break;
					case 4:
						tempstats[2] = 3;
						statmods[2] = 2.5;
						cout << poke << "'s Special fell!\n";
						break;
					case 3:
						tempstats[2] = 2;
						statmods[2] = 2;
						cout << poke << "'s Special fell!\n";
						break;
					case 2:
						tempstats[2] = 1;
						statmods[2] = 1.5;
						cout << poke << "'s Special fell!\n";
						break;
					case 1:
						tempstats[2] = 0;
						statmods[2] = 1;
						cout << poke << "'s Special fell!\n";
						break;
					case 0:
						tempstats[2] = -1;
						statmods[2] = 0.66;
						cout << poke << "'s Special fell!\n";
						break;
					case -1:
						tempstats[2] = -2;
						statmods[2] = 0.5;
						cout << poke << "'s Special fell!\n";
						break;
					case -2:
						tempstats[2] = -3;
						statmods[2] = 0.4;
						cout << poke << "'s Special fell!\n";
						break;
					case -3:
						tempstats[2] = -4;
						statmods[2] = 0.33;
						cout << poke << "'s Special fell!\n";
						break;
					case -4:
						tempstats[2] = -5;
						statmods[2] = 0.28;
						cout << poke << "'s Special fell!\n";
						break;
					case -5:
						tempstats[2] = -6;
						statmods[2] = 0.25;
						cout << poke << "'s Special fell!\n";
						break;
					case -6:
						cout << poke << "'s Special can't go lower!\n";
						break;
					}
					break;
				case 31:
					switch (tempstats[3]) {
					case 6:
						tempstats[3] = 5;
						statmods[3] = 3.5;
						cout << poke << "'s Speed fell!\n";
						break;
					case 5:
						tempstats[3] = 4;
						statmods[3] = 3;
						cout << poke << "'s Speed fell!\n";
						break;
					case 4:
						tempstats[3] = 3;
						statmods[3] = 2.5;
						cout << poke << "'s Speed fell!\n";
						break;
					case 3:
						tempstats[3] = 2;
						statmods[3] = 2;
						cout << poke << "'s Speed fell!\n";
						break;
					case 2:
						tempstats[3] = 1;
						statmods[3] = 1.5;
						cout << poke << "'s Speed fell!\n";
						break;
					case 1:
						tempstats[3] = 0;
						statmods[3] = 1;
						cout << poke << "'s Speed fell!\n";
						break;
					case 0:
						tempstats[3] = -1;
						statmods[3] = 0.66;
						cout << poke << "'s Speed fell!\n";
						break;
					case -1:
						tempstats[3] = -2;
						statmods[3] = 0.5;
						cout << poke << "'s Speed fell!\n";
						break;
					case -2:
						tempstats[3] = -3;
						statmods[3] = 0.4;
						cout << poke << "'s Speed fell!\n";
						break;
					case -3:
						tempstats[3] = -4;
						statmods[3] = 0.33;
						cout << poke << "'s Speed fell!\n";
						break;
					case -4:
						tempstats[3] = -5;
						statmods[3] = 0.28;
						cout << poke << "'s Speed fell!\n";
						break;
					case -5:
						tempstats[3] = -6;
						statmods[3] = 0.25;
						cout << poke << "'s Speed fell!\n";
						break;
					case -6:
						cout << poke << "'s Speed can't go lower!\n";
						break;
					}
					break;
				case 41:
					switch (tempstats[4]) {
					case 6:
						tempstats[4] = 5;
						statmods[4] = 3.5;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case 5:
						tempstats[4] = 4;
						statmods[4] = 3;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case 4:
						tempstats[4] = 3;
						statmods[4] = 2.5;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case 3:
						tempstats[4] = 2;
						statmods[4] = 2;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case 2:
						tempstats[4] = 1;
						statmods[4] = 1.5;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case 1:
						tempstats[4] = 0;
						statmods[4] = 1;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case 0:
						tempstats[4] = -1;
						statmods[4] = 0.66;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case -1:
						tempstats[4] = -2;
						statmods[4] = 0.5;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case -2:
						tempstats[4] = -3;
						statmods[4] = 0.4;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case -3:
						tempstats[4] = -4;
						statmods[4] = 0.33;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case -4:
						tempstats[4] = -5;
						statmods[4] = 0.28;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case -5:
						tempstats[4] = -6;
						statmods[4] = 0.25;
						cout << poke << "'s Accuracy fell!\n";
						break;
					case -6:
						cout << poke << "'s Accuracy can't go lower!\n";
						break;
					}
					break;
				case 51:
					switch (tempstats[5]) {
					case 6:
						tempstats[5] = 5;
						statmods[5] = 3.5;
						cout << poke << "'s Evade fell!\n";
						break;
					case 5:
						tempstats[5] = 4;
						statmods[5] = 3;
						cout << poke << "'s Evade fell!\n";
						break;
					case 4:
						tempstats[5] = 3;
						statmods[5] = 2.5;
						cout << poke << "'s Evade fell!\n";
						break;
					case 3:
						tempstats[5] = 2;
						statmods[5] = 2;
						cout << poke << "'s Evade fell!\n";
						break;
					case 2:
						tempstats[5] = 1;
						statmods[5] = 1.5;
						cout << poke << "'s Evade fell!\n";
						break;
					case 1:
						tempstats[5] = 0;
						statmods[5] = 1;
						cout << poke << "'s Evade fell!\n";
						break;
					case 0:
						tempstats[5] = -1;
						statmods[5] = 0.66;
						cout << poke << "'s Evade fell!\n";
						break;
					case -1:
						tempstats[5] = -2;
						statmods[5] = 0.5;
						cout << poke << "'s Evade fell!\n";
						break;
					case -2:
						tempstats[5] = -3;
						statmods[5] = 0.4;
						cout << poke << "'s Evade fell!\n";
						break;
					case -3:
						tempstats[5] = -4;
						statmods[5] = 0.33;
						cout << poke << "'s Evade fell!\n";
						break;
					case -4:
						tempstats[5] = -5;
						statmods[5] = 0.28;
						cout << poke << "'s Evade fell!\n";
						break;
					case -5:
						tempstats[5] = -6;
						statmods[5] = 0.25;
						cout << poke << "'s Evade fell!\n";
						break;
					case -6:
						cout << poke << "'s Evade can't go lower!\n";
						break;
					}
					break;
				}
				break;
			}
			if (hp <= 0) {
				goto BATTLEEND;
			}
		}
		else {
			cout << endl << epoke << "'s attack missed!\n";
		}
		system("pause");
	}
BATTLEEND:
	if (ehp <= 0) {
		cout << endl << epoke << " has fainted!\n\n";
		system("pause");
	}
	else if (hp <= 0) {
		hp = 0;
		cout << endl << poke << " has fainted!\nYou are out of usable Pokemon!\nYou whited out!\n\n";
		system("pause");
	}
	else if (esc == 1) {
		cout << "Got away safely!\n\n";
		system("pause");
	}
	__int64 hppp = (esc * 100000000000) + (hp * 100000000) + (move1pp * 1000000) + (move2pp * 10000) + (move3pp * 100) + move4pp;
	return hppp;
}