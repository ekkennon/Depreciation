#include "stdafx.h"
#include "Asset.h"


Asset::Asset(double cost, double salvage, int life)
{
	origCost = cost;
	origSalvage = salvage;
	origLife = life;
	annualDepreciation = ((cost - salvage) / life);
	bbal = new double[origLife];
	ebal = new double[origLife];
	doubDecDep = new double[origLife];
	douDecBegBal = new double[origLife];
	douDecEndBal = new double[origLife];

	bbal[0] = origCost;
	douDecBegBal[0] = origCost;
	for (int i = 0; i < origLife; i++) {
		if (i > 0) {
			bbal[i] = ebal[i - 1];
			douDecBegBal[i] = douDecEndBal[i - 1];
		}
		ebal[i] = bbal[i] - annualDepreciation;
		doubDecDep[i] = douDecBegBal[i] * 2 / life;
		if (doubDecDep[i] < annualDepreciation) {
			if (douDecBegBal[i] - doubDecDep[i] <= salvage) {
				doubDecDep[i] = douDecBegBal[i] - salvage;
			}
			else {
				doubDecDep[i] = annualDepreciation;
			}
		}
		douDecEndBal[i] = douDecBegBal[i] - doubDecDep[i];
	}
}

double Asset::getOrigCost()
{
	return origCost;
}

double Asset::getOrigSalvage()
{
	return origSalvage;
}

double Asset::getAnnualDepreciation()
{
	return annualDepreciation;
}

double Asset::getAnnualDepreciation(int year)
{
	return doubDecDep[year-1];
}

double Asset::getBegBal(int year)
{
	return bbal[year-1];
}

double Asset::getEndBal(int year)
{
	return ebal[year-1];
}

double Asset::getDouDecBegBal(int year)
{
	return douDecBegBal[year - 1];
}

double Asset::getDouDecEndBal(int year)
{
	return douDecEndBal[year - 1];
}

int Asset::getOriginalLife()
{
	return origLife;
}

Asset::~Asset()
{
}


