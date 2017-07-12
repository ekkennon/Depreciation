#pragma once
class Asset
{
public:
	Asset(double, double, int);
	~Asset(void);
	
	double getOrigCost();
	double getOrigSalvage();
	double getDoubDecDep();
	double getBegBal(int);
	double getEndBal(int);
	double getDouDecBegBal(int);
	double getDouDecEndBal(int);
	double getAnnualDepreciation();
	double getAnnualDepreciation(int);

	int getOriginalLife();

private:
	double origCost;
	double origSalvage;
	double annualDepreciation;

	int origLife;

	double* bbal;
	double* ebal;
	double* douDecBegBal;
	double* douDecEndBal;
	double* doubDecDep;
};

