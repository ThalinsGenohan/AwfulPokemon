#define _WIN32_WINNT 0x0500
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include "stats.h"
#include "battle.h"
#include "pokedeps.h"
#include "menus.h"
#include "towns.h"
#include "routes.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

int main(int argc, char* argv[])
{
	//PlaySound(TEXT("hgss.wav"), GetModuleHandle(NULL), SND_FILENAME);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);
	srand((time(0) * rand()));
	int type[2] = { 0,0 };
	int poke = 0;
	int pokechoice = 0;
	int exp = 135;
	int lvlrate = 3;
	int lvl = 5;
	int evs[5] = { 0,0,0,0,0 };
	int ivs[5] = { rand() % 32,rand() % 32,rand() % 32,rand() % 32,rand() % 32 };
	int bases[5];
	string mname1 = "-----";
	string mname2 = "-----";
	string mname3 = "-----";
	string mname4 = "-----";
	int move1[5] = { 0,0,100,0,1 };
	int move2[5] = { 0,0,100,0,1 };
	int move3[5] = { 0,0,100,0,1 };
	int move4[5] = { 0,0,100,0,1 };
	int stats[5];
	string opokename;
	pokechoice = menu3("Please choose your starter.", "Bulbasaur", "Squirtle", "Charmander");
	switch (pokechoice) {
	case 1:
		poke = 1;
		opokename = "Bulbasaur";
		type[0] = 6;
		type[1] = 7;
		bases[0] = 45;
		bases[1] = 49;
		bases[2] = 49;
		bases[3] = 65;
		bases[4] = 45;
		break;
	case 2:
		poke = 7;
		opokename = "Squirtle";
		type[0] = 4;
		bases[0] = 44;
		bases[1] = 48;
		bases[2] = 65;
		bases[3] = 50;
		bases[4] = 43;
		break;
	case 3:
		poke = 4;
		opokename = "Charmander";
		type[0] = 2;
		bases[0] = 39;
		bases[1] = 52;
		bases[2] = 43;
		bases[3] = 50;
		bases[4] = 65;
		mname1 = "Scratch";
		move1[0] = 1;
		move1[1] = 40;
		move1[3] = 35;
		mname2 = "Growl";
		move2[0] = 2;
		move2[1] = 1;
		move2[3] = 40;
		mname3 = "-----";
		mname4 = "-----";
		break;
	}
	stats[0] = hpstat(lvl, ivs[0], 0, bases[0]);
	stats[1] = stat(lvl, ivs[1], 0, bases[1]);
	stats[2] = stat(lvl, ivs[2], 0, bases[2]);
	stats[3] = stat(lvl, ivs[3], 0, bases[3]);
	stats[4] = stat(lvl, ivs[4], 0, bases[4]);
	int hp = stats[0];
	int pp[4] = { move1[3], move2[3], move3[3],move4[3] };
	ostringstream pnn;
	system("cls");
	pnn << "Would you like to give " << opokename << " a nickname?";
	string pokenick = pnn.str();
	bool pnnx = ynmenu(pokenick);
	string pokename = opokename;
	switch (pnnx) {
	case true:
		cout << "\n__________\r";
		cin >> pokename;
		break;
	}
	system("cls");
	summary(pokename, opokename, lvl, exp, lvlrate, hp, stats, mname1, mname2, mname3, mname4, move1, move2, move3, move4);
ROUTE1:
	int esc = 0;
	__int64 hppp = 0;
	hp = stats[0];
	pp[0] = move1[3];
	pp[1] = move2[3];
	pp[2] = move3[3];
	pp[3] = move4[3];
	system("cls");
	cout << "Entering Route 1...\n";
	Sleep(3000);
	int epoke;
	string epokename;
	int etype[2] = { 0,0 };
	int elvl = 0;
	int ebases[5] = { 0,0,0,0,0 };
	int emoveno = 0;
	int emove1[5] = { 0,0,100,0,1 };
	int emove2[5] = { 0,0,100,0,1 };
	int emove3[5] = { 0,0,100,0,1 };
	int emove4[5] = { 0,0,100,0,1 };
	string emname1;
	string emname2;
	string emname3;
	string emname4;
	int eivs[5] = { 0,0,0,0,0 };
	int enc = 0;
	int estats[5] = { 0,0,0,0,0 };
	int encrate1 = 8.5 / 187.5;
	int enc1;
	int grass1 = 15 + (rand() % 89);
	int expgain = 0;
	for (int r1 = grass1; r1 > 0; r1--) {
		enc1 = rand() % 374;
		if (enc1 <= 16) {
			esc = 0;
			hppp = 0;
			eivs[0] = rand() % 32;
			eivs[1] = rand() % 32;
			eivs[2] = rand() % 32;
			eivs[3] = rand() % 32;
			eivs[4] = rand() % 32;
			enc = rand() % 100;
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
			estats[0] = hpstat(elvl, eivs[0], 0, ebases[0]);
			estats[1] = stat(elvl, eivs[1], 0, ebases[1]);
			estats[2] = stat(elvl, eivs[2], 0, ebases[2]);
			estats[3] = stat(elvl, eivs[3], 0, ebases[3]);
			estats[4] = stat(elvl, eivs[4], 0, ebases[4]);
			hppp = battle(pokename, epokename, bases, ebases, stats, estats, lvl, elvl, hp, move1, pp[0], move2, pp[1], move3, pp[2], move4, pp[3], mname1, mname2, mname3, mname4, emoveno, emove1, emove2, emove3, emove4, emname1, emname2, emname3, emname4, type, etype);
			esc = hppp / 100000000000;
			hp = (hppp % 100000000000) / 100000000;
			pp[0] = (hppp % 100000000) / 1000000;
			pp[1] = (hppp % 1000000) / 10000;
			pp[2] = (hppp % 10000) / 100;
			pp[3] = hppp % 100;
			hppp = 0;
			if (hp <= 0) {
				hp = stats[0];
				pp[0] = move1[3];
				pp[1] = move2[3];
				pp[2] = move3[3];
				pp[3] = move4[3];
				goto ROUTE1;
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
		}
	}
VIRIDIAN1:
	system("cls");
	int viridianact = viridian1(lvl, exp, lvlrate, hp, ivs, evs, stats, mname1, mname2, mname3, mname4, move1, move2, move3, move4, pp);
	switch (viridianact) {
	case 1:
		hp = stats[0];
		pp[0] = move1[3];
		pp[1] = move2[3];
		pp[2] = move3[3];
		pp[3] = move4[3];
		cout << "\nYour Pokemon have been healed to full health!\n";
		system("pause");
		break;
	case 2:
		cout << "\nItems are not yet implemented.\n";
		system("pause");
		break;
	case 3:
		cout << "\nThe gym is currently closed.\n";
		system("pause");
		break;
	case 4:
		switch (menu3("Which route would you like to grind on?", "Route 1", "Route 2", "Route 22")) {
		case 1:
			routegrind1(poke, exp, lvlrate, pokename, bases, ivs, evs, stats, lvl, hp, pp, move1, move2, move3, move4, mname1, mname2, mname3, mname4, type);
			break;
		case 2:
			routegrind2();
			break;
		case 3:
			routegrind22();
			break;
		}
		break;
	case 5:
		moremenu(1, poke, pokename, opokename, lvl, exp, lvlrate, hp, ivs, evs, stats, mname1, mname2, mname3, mname4, move1, move2, move3, move4, pp);
		break;
	}
	goto VIRIDIAN1;
	/*int townact = 0;
	int grindroute = 0;
	bool grindend1 = false;
	bool grindend2 = false;
	cout << "Welcome to Viridian City!\n\n1. Pokemon Center\n2. PokeMart (NYI)\n3. Gym (Closed)\n4. Grind for levels\n5. Pokemon Summary\n6. Exit\n";
	cin >> townact;
	switch (townact) {
	case 1:
		hp = stats[0];
		pp[0] = move1[3];
		pp[1] = move2[3];
		pp[2] = move3[3];
		pp[3] = move4[3];
		cout << "Your Pokemon have been healed to full health!\n";
		system("pause");
		goto VIRIDIAN1;
		break;
	case 2:
		cout << "Items are NOT YET IMPLEMENTED.\n";
		system("pause");
		goto VIRIDIAN1;
		break;
	case 3:
		cout << "The Gym is currently closed.\n";
		system("pause");
		goto VIRIDIAN1;
		break;
	case 4:
		cout << "What Route would you like to grind on?\n-Route 1\n-Route 2\n-Route 22 (NYI)\n";
		cin >> grindroute;
		switch (grindroute) {
		case 1:
ROUTE1GRIND:
			
		case 2:
ROUTE2GRIND:
			grindend2 = true;
			esc = 0;
			hppp = 0;
			eivs[0] = rand() % 32;
			eivs[1] = rand() % 32;
			eivs[2] = rand() % 32;
			eivs[3] = rand() % 32;
			eivs[4] = rand() % 32;
			enc = rand() % 100;
			if (enc < 15) {
				epoke = 13;
				epokename = "Weedle";
				etype[0] = 13;
				etype[1] = 7;
				elvl = rand() % 3 + 3;
				ebases[0] = 40;
				ebases[1] = 35;
				ebases[2] = 30;
				ebases[3] = 20;
				ebases[4] = 50;
				emoveno = 2;
				emname1 = "Poison Sting";
				emove1[0] = 1;
				emove1[1] = 15;
				emove1[3] = 35;
				emove1[4] = 7;
				emname2 = "String Shot";
				emove2[0] = 2;
				emove2[1] = 31;
				emove2[3] = 40;
				emove2[4] = 13;
			}
			else if (enc >= 15 && enc < 55) {
				epoke = 16;
				epokename = "Pidgey";
				etype[0] = 1;
				etype[1] = 5;
				elvl = rand() % 3 + 3;
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
			else if (enc >= 55) {
				epoke = 19;
				epokename = "Rattata";
				etype[0] = 1;
				elvl = rand() % 4 + 2;
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
			estats[0] = hpstat(elvl, eivs[0], 0, ebases[0]);
			estats[1] = stat(elvl, eivs[1], 0, ebases[1]);
			estats[2] = stat(elvl, eivs[2], 0, ebases[2]);
			estats[3] = stat(elvl, eivs[3], 0, ebases[3]);
			estats[4] = stat(elvl, eivs[4], 0, ebases[4]);
			hppp = battle(pokename, epokename, bases, ebases, stats, estats, lvl, elvl, hp, move1, pp[0], move2, pp[1], move3, pp[2], move4, pp[3], mname1, mname2, mname3, mname4, emoveno, emove1, emove2, emove3, emove4, emname1, emname2, emname3, emname4, type, etype);
			esc = hppp / 100000000000;
			hp = (hppp % 100000000000) / 100000000;
			pp[0] = (hppp % 100000000) / 1000000;
			pp[1] = (hppp % 1000000) / 10000;
			pp[2] = (hppp % 10000) / 100;
			pp[3] = hppp % 100;
			if (hp <= 0) {
				hp = stats[0];
				pp[0] = move1[3];
				pp[1] = move2[3];
				pp[2] = move3[3];
				pp[3] = move4[3];
				goto VIRIDIAN1;
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
				case 13:
					expgain = (52 * elvl) / 7;
					evs[4] += 1;
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
			grindend2 = ynmenu("Would you like to continue grinding?");
			switch (grindend2) {
			case true:
				goto ROUTE2GRIND;
				break;
			case false:
				goto VIRIDIAN1;
				break;
			}
			break;
		}
		break;
	case 5:
		summary(lvl, exp, lvlrate, hp, stats, mname1, mname2, mname3, mname4, move1, move2, move3, move4);
		goto VIRIDIAN1;
		break;
	case 6:
		goto ROUTE2p1;
		break;
	default:
		goto VIRIDIAN1;
	}*/
ROUTE2p1:
	esc = 0;
	hppp = 0;
	eivs[0] = rand() % 32;
	eivs[1] = rand() % 32;
	eivs[2] = rand() % 32;
	eivs[3] = rand() % 32;
	eivs[4] = rand() % 32;
	enc = rand() % 100;
	if (enc < 15) {
		epoke = 13;
		epokename = "Weedle";
		etype[0] = 13;
		etype[1] = 7;
		elvl = rand() % 3 + 3;
		ebases[0] = 40;
		ebases[1] = 35;
		ebases[2] = 30;
		ebases[3] = 20;
		ebases[4] = 50;
		emoveno = 2;
		emname1 = "Poison Sting";
		emove1[0] = 1;
		emove1[1] = 15;
		emove1[3] = 35;
		emove1[4] = 7;
		emname2 = "String Shot";
		emove2[0] = 2;
		emove2[1] = 31;
		emove2[3] = 40;
		emove2[4] = 13;
	}
	else if (enc >= 15 && enc < 55) {
		epoke = 16;
		epokename = "Pidgey";
		etype[0] = 1;
		etype[1] = 5;
		elvl = rand() % 3 + 3;
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
	else if (enc >= 55) {
		epoke = 19;
		epokename = "Rattata";
		etype[0] = 1;
		elvl = rand() % 4 + 2;
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
	estats[0] = hpstat(elvl, eivs[0], 0, ebases[0]);
	estats[1] = stat(elvl, eivs[1], 0, ebases[1]);
	estats[2] = stat(elvl, eivs[2], 0, ebases[2]);
	estats[3] = stat(elvl, eivs[3], 0, ebases[3]);
	estats[4] = stat(elvl, eivs[4], 0, ebases[4]);
	hppp = battle(pokename, epokename, bases, ebases, stats, estats, lvl, elvl, hp, move1, pp[0], move2, pp[1], move3, pp[2], move4, pp[3], mname1, mname2, mname3, mname4, emoveno, emove1, emove2, emove3, emove4, emname1, emname2, emname3, emname4, type, etype);
	esc = hppp / 100000000000;
	hp = (hppp % 100000000000) / 100000000;
	pp[0] = (hppp % 100000000) / 1000000;
	pp[1] = (hppp % 1000000) / 10000;
	pp[2] = (hppp % 10000) / 100;
	pp[3] = hppp % 100;
	if (hp <= 0) {
		hp = stats[0];
		pp[0] = move1[3];
		pp[1] = move2[3];
		pp[2] = move3[3];
		pp[3] = move4[3];
		goto VIRIDIAN1;
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
		case 13:
			expgain = (52 * elvl) / 7;
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
	system("pause");
	return 0;
}