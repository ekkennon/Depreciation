// Depreciation.cpp : main project file.  Erin K Kennon

#include "stdafx.h"
#include "Asset.h"
#include <iostream>
#include <string>

using namespace std;
using namespace System;

bool choose(string);
double getValue(string);

int main()
{
	cout << "Welcome to the depreciation calcultor" << endl;

	do {
		double cost = getValue("Please enter the asset cost: ");
		double salvage = getValue("Please enter the salvage value: ");
		int life = (int)getValue("Please enter the asset life (in years): ");

		Asset a = Asset(cost, salvage, life);
		
		cout << "\nThe annual depreciation allowance on a $" << a.getOrigCost() << " asset\nwith a salvage value of $" << a.getOrigSalvage() << "\nand a life of " << a.getOriginalLife() << " years = $" << a.getAnnualDepreciation() << "\nper year under straight-line." << endl << endl;
		if (choose("Would you like to see a complete schedule? ")) {
			cout << "Year | Start Value | Depreciation | End Value" << endl;
			for (int i = 1; i < a.getOriginalLife() + 1; i++) {
				cout << i << "\t" << a.getBegBal(i) << "\t\t" << a.getAnnualDepreciation() << "\t\t" << a.getEndVal(i) << endl;
			}
		}
	} while (choose("Would you like to calculate another depreciation? "));

	cout << "Thanks for using the depreciation calculator" << endl << endl;
	system("Pause");
    return 0;
}

bool choose(string message) {
	char choice;
	cin.ignore(1000, '\n');
	cout << message;
	cin >> choice;

	if (!cin.good()) {
		cin.clear();
		cin.ignore(1000, '\n');
		return false;
	}
	else if (choice == 'y' || choice == 'Y') {
		return true;
	}

	return false;
}

double getValue(string message) {
	double value;

	do {
		cout << message;
		cin >> value;

		if (!cin.good()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your data was bad so I could not decipher your input as a decimal value." << endl;
			value = -1;
		}
		else if (value < 1) {
			cout << "Please enter a positive value." << endl;
		}

	} while (value < 1);

	return value;
}
