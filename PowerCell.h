/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#ifndef POWER_CELL_H_
#define POWER_CELL_H_ 

#include "PowerTeam.h"
#include <vector>
#include <string>

class PowerCell
{
 private:
    std::vector<PowerTeam> mPowerCell;
    double mTotalVoltage;
    double mMaxVoltage;

 public:
    PowerCell(std::vector<PowerTeam> powerCell);
    double getTotalVoltage();
	void drawPower(double power);    
	void printCell();    
};

#endif // POWER_CELL_H_