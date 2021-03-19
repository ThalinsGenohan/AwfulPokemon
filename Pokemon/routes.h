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
#include "stats.h"
#include "battle.h"
#include "pokedeps.h"
#include "menus.h"
#include "towns.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

void route1() {}

void route2() {}

void routegrind1(int poke, int exp, int lvlrate, string pokename, int bases[5], int ivs[5], int evs[5], int stats[5], int lvl, int hp, int pp[4], int move1[4], int move2[4], int move3[4], int move4[4], string mname1, string mname2, string mname3, string mname4, int type[2]) {
GRIND1:
	bool grindend1 = true;
	int esc = 0;
	int hppp = 0;
	int epoke;
	string epokename;
	int etype[2];
	int elvl;
	int ebases[5];
	int emoveno;
	string emname1;
	int emove1[4];
	string emname2;
	int emove2[4];
	string emname3;
	int emove3[4];
	string emname4;
	int emove4[4];
	int eivs[5] = { rand() % 32, rand() % 32, rand() % 32, rand() % 32, rand() % 32 };
	int enc = rand() % 100;
	if (enc < 45) {
		epoke = 16;
		epokename = "Pidgey";
		etype[0] = 1;
		etype[1] = 5;
		elvl = rand() % 4 + 2;
		ebases[0] = 40;
		ebases[1] = 45;
		ebases[2] = 40;
		ebases[3] = 35;
		ebases[4] = 56;
		emoveno = 2;
		emname1 = "Tackle";
		emove1[0] = 1;
		emove1[1] = 35;
		emove1[2] = 95;
		emove1[3] = 35;
		emname2 = "Sand Attack";
		emove2[0] = 2;
		emove2[1] = 41;
		emove2[3] = 15;
		emove2[4] = 9;
	}
	else if (enc >= 45) {
		epoke = 19;
		epokename = "Rattata";
		etype[0] = 1;
		elvl = rand() % 3 + 2;
		ebases[0] = 30;
		ebases[1] = 56;
		ebases[2] = 35;
		ebases[3] = 25;
		ebases[4] = 72;
		emoveno = 2;
		emname1 = "Tackle";
		emove1[0] = 1;
		emove1[1] = 35;
		emove1[2] = 95;
		emove1[3] = 35;
		emname2 = "Tail Whip";
		emove2[0] = 2;
		emove2[1] = 11;
		emove2[3] = 30;
	}
	int estats[5] = { hpstat(elvl, eivs[0], 0, ebases[0]), stat(elvl, eivs[1], 0, ebases[1]), stat(elvl, eivs[2], 0, ebases[2]), stat(elvl, eivs[3], 0, ebases[3]), stat(elvl, eivs[4], 0, ebases[4]) };
	hppp = battle(pokename, epokename, bases, ebases, stats, estats, lvl, elvl, hp, move1, pp[0], move2, pp[1], move3, pp[2], move4, pp[3], mname1, mname2, mname3, mname4, emoveno, emove1, emove2, emove3, emove4, emname1, emname2, emname3, emname4, type, etype);
	hp = hppp / 100000000;
	pp[0] = (hppp % 100000000) / 1000000;
	pp[1] = (hppp % 1000000) / 10000;
	pp[2] = (hppp % 10000) / 100;
	pp[3] = hppp % 100;
	int expgain;
	if (hp <= 0) {
		hp = stats[0];
		pp[0] = move1[3];
		pp[1] = move2[3];
		pp[2] = move3[3];
		pp[3] = move4[3];
		grindend1 = false;
		goto END1;
	}
	else if (esc == 1) {}
	else if (hp > 0) {
		switch (epoke) {
		case 16:
			expgain = (55 * elvl) / 7;
			evs[4] += 1;
			break;
		case 19:
			expgain = (57 * elvl) / 7;
			evs[4] += 1;
			break;
		}
		system("cls");
		cout << pokename << " gained " << expgain << " EXP.\n";
		exp += expgain;
		lvl = levelcheck(lvl, exp, lvlrate, pokename);
		stats[0] = hpstat(lvl, ivs[0], evs[0], bases[0]);
		stats[1] = stat(lvl, ivs[1], evs[1], bases[1]);
		stats[2] = stat(lvl, ivs[2], evs[2], bases[2]);
		stats[3] = stat(lvl, ivs[3], evs[3], bases[3]);
		stats[4] = stat(lvl, ivs[4], evs[4], bases[4]);
		system("pause");
		if (poke == 1 && lvl == 7 && move3[0] == 0) {
			mname3 = "Leech Seed (NYI)";
			move3[0] = 6;
			move3[1] = 1;
			move3[2] = 90;
			move3[3] = 10;
			move3[4] = 6;
			pp[2] = move3[3];
			cout << "Bulbasaur learned Leech Seed!\n";
		}
		if (poke == 7 && lvl == 8 && move3[0] == 0) {
			mname3 = "Bubble";
			move3[0] = 1;
			move3[1] = 20;
			move3[3] = 30;
			move3[4] = 4;
			pp[2] = move3[3];
			cout << "Squirtle learned Bubble!\n";
		}
		if (poke == 4 && lvl == 9 && move3[0] == 0) {
			mname3 = "Ember";
			move3[0] = 1;
			move3[1] = 40;
			move3[3] = 25;
			move3[4] = 2;
			pp[2] = move3[3];
			cout << "Charmander learned Ember!\n";
		}
		if (poke == 1 && lvl == 13 && move4[0] == 0) {
			mname4 = "Vine Whip";
			move4[0] = 1;
			move4[1] = 35;
			move4[3] = 10;
			move4[4] = 6;
			pp[3] = move4[3];
			cout << "Bulbasaur learned Vine Whip!\n";
		}
		if (poke == 7 && lvl == 15 && move4[0] == 0) {
			mname4 = "Water Gun";
			move4[0] = 1;
			move4[1] = 40;
			move4[3] = 25;
			move4[4] = 4;
			pp[3] = move4[3];
			cout << "Squirtle learned Water Gun!\n";
		}
	}
	cout << pokename << " has " << hp << "/" << stats[0] << " HP remaining.\n";
	grindend1 = ynmenu("Would you like to continue grinding?");
END1:
	switch (grindend1) {
	case true:
		goto GRIND1;
		break;
	case false:
		break;
	}
}

void routegrind2() {}

void routegrind22() {}