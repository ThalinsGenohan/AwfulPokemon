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

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

bool ynmenu(string q) {
	int c = 0;
	int act = 1;
	int x = 0;
	string o1 = "Yes";
	string o2 = "No";
	cout << q << "\n> " << o1 << " <\n  " << o2;
	while (x == 0) {
		c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			system("cls");
			switch (act) {
			case 1:
				cout << q << "\n  " << o1 << "  \n> " << o2 << " <";
				act = 2;
				break;
			case 2:
				cout << q << "\n> " << o1 << " <\n  " << o2;
				act = 1;
				break;
			}
			break;
		case KEY_DOWN:
			system("cls");
			switch (act) {
			case 1:
				cout << q << "\n  " << o1 << "  \n> " << o2 << " <";
				act = 2;
				break;
			case 2:
				cout << q << "\n> " << o1 << " <\n  " << o2;
				act = 1;
				break;
			}
			break;
		case KEY_ENTER:
			x = 1;
			break;
		}
	}
	bool yn;
	switch (act) {
	case 1:
		yn = true;
		break;
	case 2:
		yn = false;
		break;
	}
	return yn;
}

int menu3(string q, string o1, string o2, string o3) {
	int c = 0;
	int act = 1;
	int x = 0;
	system("cls");
	cout << q << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3;
	while (x == 0) {
		c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			system("cls");
			switch (act) {
			case 1:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n> " << o3 << " <";
				act = 3;
				break;
			case 2:
				cout << q << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3;
				act = 1;
				break;
			case 3:
				cout << q << "\n  " << o1 << "  \n> " << o2 << " <\n  " << o3;
				act = 2;
				break;
			}
			break;
		case KEY_DOWN:
			system("cls");
			switch (act) {
			case 1:
				cout << q << "\n  " << o1 << "  \n> " << o2 << " <\n  " << o3;
				act = 2;
				break;
			case 2:
				cout << q << "\n  " << o1 << "  \n  " << o2 << "  \n> " << o3 << " <";
				act = 3;
				break;
			case 3:
				cout << q << "\n> " << o1 << " <\n  " << o2 << "  \n  " << o3;
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