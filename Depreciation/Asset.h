#pragma once
class Asset
{
public:
	Asset(double, double, int);
	~Asset(void);
	
	double getOrigCost();
	double getOrigSalvage();
	double getAnnualDepreciation();
	double getBegBal(int);
	double getEndVal(int);
	int getOriginalLife();

private:
	double origCost;
	double origSalvage;
	double annualDepreciation;
	int origLife;

	double* bbal;
	double* ebal;
};

