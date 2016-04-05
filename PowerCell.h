/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#ifndef POWER_CELL_H_
#define POWER_CELL_H_ 

#include "PowerTeam.h"

class PowerCell
{
 private:
    std::vector<PowerTeam> mPowerCell;
    int mTotalVoltage;

 public:
    PowerCell(std::vector<PowerTeam> powerCell);
    int getTotalVoltage();
    void recharge(int power);
    
    
};

#endif // POWER_CELL_H_