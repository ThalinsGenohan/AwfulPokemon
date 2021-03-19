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
#include "menus.h"
#include "stats.h"
#include "routes.h"
 
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

void moremenu(int town, int pokenum, string pokename, string opokename, int lvl, int exp, int lvlrate, int hp, int ivs[5], int evs[5], int stats[5], string mname1, string mname2, string mname3, string mname4, int move1[5], int move2[5], int move3[5], int move4[5], int pp[4]) {
	int c = 0;
	int act = 1;
	int x = 0;
	string q = "Welcome to Viridian City!";
	string o1 = "Pokemon";
	string o2 = "Bag (NYI)";
	string o3 = "Check IVs/EVs";
	string o4 = "Get Save Password (Experimental)";
	string o5 = "Back...";
	string o6 = "Quit Game";
	system("cls");
	cout << q << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n  " << o6;
	while (x == 0) {
		c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			system("cls");
			switch (act) {
			case 1:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n> " << o6 << " <";
				act = 6;
				break;
			case 2:
				cout << q << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 1;
				break;
			case 3:
				cout << q << "\n  " << o1 << "  \n> " << o2 << " <\n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 2;
				break;
			case 4:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n> " << o3 << " <\n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 3;
				break;
			case 5:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n> " << o4 << " <\n  " << o5 << "  \n  " << o6 << "  ";
				act = 4;
				break;
			case 6:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n> " << o5 << " <\n  " << o6 << "  ";
				act = 5;
				break;
			}
			break;
		case KEY_DOWN:
			system("cls");
			switch (act) {
			case 5:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n> " << o6 << " <";
				act = 6;
				break;
			case 6:
				cout << q << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 1;
				break;
			case 1:
				cout << q << "\n  " << o1 << "  \n> " << o2 << " <\n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 2;
				break;
			case 2:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n> " << o3 << " <\n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 3;
				break;
			case 3:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n> " << o4 << " <\n  " << o5 << "  \n  " << o6 << "  ";
				act = 4;
				break;
			case 4:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n> " << o5 << " <\n  " << o6 << "  ";
				act = 5;
				break;
			}
			break;
		case KEY_ENTER:
			x = 1;
			break;
		}
	}
	ostringstream passwordx;
	string password = "";
	switch (act) {
	case 1:
		system("cls");
		cout << "Sorry, parties are not yet implemented.\n";
		summary(pokename, opokename, lvl, exp, lvlrate, hp, stats, mname1, mname2, mname3, mname4, move1, move2, move3, move4);
		break;
	case 2:
		cout << "\nItems are not yet implemented.";
		system("pause");
		break;
	case 3:
		eviv(pokename, opokename, ivs, evs);
		break;
	case 4:
		cout << "";
		passwordx << pokenum << ivs << evs << lvl << move1 << move2 << move3 << move4 << town;
		password = passwordx.str();
		break;
	}
}

int viridian1(int lvl, int exp, int lvlrate, int hp, int ivs[5], int evs[5], int stats[5], string mname1, string mname2, string mname3, string mname4, int move1[5], int move2[5], int move3[5], int move4[5], int pp[4]) {
	int c = 0;
	int act = 1;
	int x = 0;
	string q = "Welcome to Viridian City!";
	string o1 = "Pokemon Center";
	string o2 = "Pokemart (NYI)";
	string o3 = "Gym (Closed)";
	string o4 = "Grind for Levels";
	string o5 = "More...";
	string o6 = "Exit to Route 2";
	system("cls");
	cout << q << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n  " << o6;
	while (x == 0) {
		c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			system("cls");
			switch (act) {
			case 1:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n> " << o6 << " <";
				act = 6;
				break;
			case 2:
				cout << q << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 1;
				break;
			case 3:
				cout << q << "\n  " << o1 << "  \n> " << o2 << " <\n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 2;
				break;
			case 4:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n> " << o3 << " <\n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 3;
				break;
			case 5:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n> " << o4 << " <\n  " << o5 << "  \n  " << o6 << "  ";
				act = 4;
				break;
			case 6:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n> " << o5 << " <\n  " << o6 << "  ";
				act = 5;
				break;
			}
			break;
		case KEY_DOWN:
			system("cls");
			switch (act) {
			case 5:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n> " << o6 << " <";
				act = 6;
				break;
			case 6:
				cout << q << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 1;
				break;
			case 1:
				cout << q << "\n  " << o1 << "  \n> " << o2 << " <\n  " << o3 << "  \n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 2;
				break;
			case 2:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n> " << o3 << " <\n  " << o4 << "  \n  " << o5 << "  \n  " << o6 << "  ";
				act = 3;
				break;
			case 3:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n> " << o4 << " <\n  " << o5 << "  \n  " << o6 << "  ";
				act = 4;
				break;
			case 4:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n  " << o3 << "  \n  " << o4 << "  \n> " << o5 << " <\n  " << o6 << "  ";
				act = 5;
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