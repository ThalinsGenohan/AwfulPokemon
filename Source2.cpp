int attack(double att, double edef, double power, double bspeed, double lvl, int type, int poketype1, int poketype2, int etype1, int etype2)
{
	double critx = ((bspeed * 100.00) / 512.00);
	double crity = (rand() % 255);
	double critz;
	int crit;
	if (critx < crity) {
		critz = ((2.00 * lvl + 5.00) / (lvl + 5.00));
		crit = critz;
	}
	else {
		crit = 1;
	}
	double eff = 1.0;
	switch (type) {
	case 1:
		if ((etype1 = 11) || (etype2 = 11)) {
			eff *= 0.50;
		}
		if ((etype1 = 15) || (etype2 = 15)) {
			eff *= 0.00;
		}
		break;
	case 2:
		if ((etype1 = 13) || (etype2 = 13)) {
			eff *= 2.00;
		}
		if ((etype1 = 6) || (etype2 = 6)) {
			eff *= 2.00;
		}
		if ((etype1 = 12) || (etype2 = 12)) {
			eff *= 2.00;
		}
		if ((etype1 = 14) || (etype2 = 14)) {
			eff *= 0.50;
		}
		if ((etype1 = 4) || (etype2 = 4)) {
			eff *= 0.50;
		}
		if ((etype1 = 2) || (etype2 = 2)) {
			eff *= 0.50;
		}
		if ((etype1 = 11) || (etype2 = 11)) {
			eff *= 0.50;
		}
		break;
	case 3:
		if ((etype1 = 1) || (etype2 = 1)) {
			eff *= 2.00;
		}
		if ((etype1 = 11) || (etype2 = 11)) {
			eff *= 2.00;
		}
		if ((etype1 = 12) || (etype2 = 12)) {
			eff *= 2.00;
		}
		if ((etype1 = 7) || (etype2 = 7)) {
			eff *= 0.50;
		}
		if ((etype1 = 5) || (etype2 = 5)) {
			eff *= 0.50;
		}
		if ((etype1 = 13) || (etype2 = 13)) {
			eff *= 0.50;
		}
		if ((etype1 = 10) || (etype2 = 10)) {
			eff *= 0.50;
		}
		if ((etype1 = 15) || (etype2 = 15)) {
			eff *= 0.00;
		}
		break;
	case 4:
		if ((etype1 = 1) || (etype2 = 1)) {
			eff *= 2.00;
		}
		if ((etype1 = 9) || (etype2 = 9)) {
			eff *= 2.00;
		}
		if ((etype1 = 11) || (etype2 = 11)) {
			eff *= 2.00;
		}
		if ((etype1 = 14) || (etype2 = 14)) {
			eff *= 0.50;
		}
		if ((etype1 = 6) || (etype2 = 6)) {
			eff *= 0.50;
		}
		if ((etype1 = 4) || (etype2 = 4)) {
			eff *= 0.50;
		}
		break;
	case 5:
		if ((etype1 = 13) || (etype2 = 13)) {
			eff *= 2.00;
		}
		if ((etype1 = 3) || (etype2 = 3)) {
			eff *= 2.00;
		}
		if ((etype1 = 6) || (etype2 = 6)) {
			eff *= 2.00;
		}
		if ((etype1 = 8) || (etype2 = 8)) {
			eff *= 0.50;
		}
		if ((etype1 = 11) || (etype2 = 11)) {
			eff *= 0.50;
		}
		break;
	case 6:
		if ((etype1 = 9) || (etype2 = 9)) {
			eff *= 2.00;
		}
		if ((etype1 = 11) || (etype2 = 11)) {
			eff *= 2.00;
		}
		if ((etype1 = 4) || (etype2 = 4)) {
			eff *= 2.00;
		}
		if ((etype1 = 13) || (etype2 = 13)) {
			eff *= 0.50;
		}
		if ((etype1 = 14) || (etype2 = 14)) {
			eff *= 0.50;
		}
		if ((etype1 = 2) || (etype2 = 2)) {
			eff *= 0.50;
		}
		if ((etype1 = 5) || (etype2 = 5)) {
			eff *= 0.50;
		}
		if ((etype1 = 6) || (etype2 = 6)) {
			eff *= 0.50;
		}
		if ((etype1 = 7) || (etype2 = 7)) {
			eff *= 0.50;
		}
		break;
	case 7:
		if ((etype1 = 13) || (etype2 = 13)) {
			eff *= 2.00;
		}
		if ((etype1 = 6) || (etype2 = 6)) {
			eff *= 2.00;
		}
		if ((etype1 = 7) || (etype2 = 7)) {
			eff *= 0.50;
		}
		if ((etype1 = 9) || (etype2 = 9)) {
			eff *= 0.50;
		}
		if ((etype1 = 11) || (etype2 = 11)) {
			eff *= 0.50;
		}
		if ((etype1 = 15) || (etype2 = 15)) {
			eff *= 0.50;
		}
		break;
	case 8:
		if ((etype1 = 5) || (etype2 = 5)) {
			eff *= 2.00;
		}
		if ((etype1 = 4) || (etype2 = 4)) {
			eff *= 2.00;
		}
		if ((etype1 = 14) || (etype2 = 14)) {
			eff *= 0.50;
		}
		if ((etype1 = 8) || (etype2 = 8)) {
			eff *= 0.50;
		}
		if ((etype1 = 6) || (etype2 = 6)) {
			eff *= 0.50;
		}
		if ((etype1 = 9) || (etype2 = 9)) {
			eff *= 0.00;
		}
		break;
	case 9:
		if ((etype1 = 8) || (etype2 = 8)) {
			eff *= 2.00;
		}
		if ((etype1 = 2) || (etype2 = 2)) {
			eff *= 2.00;
		}
		if ((etype1 = 7) || (etype2 = 7)) {
			eff *= 2.00;
		}
		if ((etype1 = 11) || (etype2 = 11)) {
			eff *= 2.00;
		}
		if ((etype1 = 13) || (etype2 = 13)) {
			eff *= 0.50;
		}
		if ((etype1 = 6) || (etype2 = 6)) {
			eff *= 0.50;
		}
		if ((etype1 = 5) || (etype2 = 5)) {
			eff *= 0.00;
		}
		break;
	case 10:
		if ((etype1 = 3) || (etype2 = 3)) {
			eff *= 2.00;
		}
		if ((etype1 = 7) || (etype2 = 7)) {
			eff *= 2.00;
		}
		if ((etype1 = 10) || (etype2 = 10)) {
			eff *= 0.50;
		}
		break;
	case 11:
		if ((etype1 = 13) || (etype2 = 13)) {
			eff *= 2.00;
		}
		if ((etype1 = 2) || (etype2 = 2)) {
			eff *= 2.00;
		}
		if ((etype1 = 5) || (etype2 = 5)) {
			eff *= 2.00;
		}
		if ((etype1 = 12) || (etype2 = 12)) {
			eff *= 2.00;
		}
		if ((etype1 = 3) || (etype2 = 3)) {
			eff *= 0.50;
		}
		if ((etype1 = 9) || (etype2 = 9)) {
			eff *= 0.50;
		}
		break;
	case 12:
		if ((etype1 = 14) || (etype2 = 14)) {
			eff *= 2.00;
		}
		if ((etype1 = 5) || (etype2 = 5)) {
			eff *= 2.00;
		}
		if ((etype1 = 6) || (etype2 = 6)) {
			eff *= 2.00;
		}
		if ((etype1 = 9) || (etype2 = 9)) {
			eff *= 2.00;
		}
		if ((etype1 = 12) || (etype2 = 12)) {
			eff *= 0.50;
		}
		if ((etype1 = 4) || (etype2 = 4)) {
			eff *= 0.50;
		}
		break;
	case 13:
		if ((etype1 = 6) || (etype2 = 6)) {
			eff *= 2.00;
		}
		if ((etype1 = 7) || (etype2 = 7)) {
			eff *= 2.00;
		}
		if ((etype1 = 10) || (etype2 = 10)) {
			eff *= 2.00;
		}
		if ((etype1 = 3) || (etype2 = 3)) {
			eff *= 0.50;
		}
		if ((etype1 = 2) || (etype2 = 2)) {
			eff *= 0.50;
		}
		if ((etype1 = 5) || (etype2 = 5)) {
			eff *= 0.50;
		}
		if ((etype1 = 15) || (etype2 = 15)) {
			eff *= 0.50;
		}
		break;
	case 14:
		if ((etype1 = 14) || (etype2 = 14)) {
			eff *= 2.00;
		}
		break;
	case 15:
		if ((etype1 = 15) || (etype2 = 15)) {
			eff *= 2.00;
		}
		if ((etype1 = 1) || (etype2 = 1)) {
			eff *= 0.00;
		}
		if ((etype1 = 10) || (etype2 = 10)) {
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
	cout << "Damage = " << dam << endl;
	return dam;
}
