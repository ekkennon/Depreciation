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

	bbal[0] = origCost;
	for (int i = 0; i < origLife; i++) {
		if (i > 0) {
			bbal[i] = ebal[i - 1];
		}
		ebal[i] = bbal[i] - annualDepreciation;
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

double Asset::getBegBal(int year)
{
	return bbal[year-1];
}

double Asset::getEndVal(int year)
{
	return ebal[year-1];
}

int Asset::getOriginalLife()
{
	return origLife;
}

Asset::~Asset()
{
}


