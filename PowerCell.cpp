/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#include "PowerCell.h"

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

/*!
 * Public constructor. Takes a vector of PowerTeam, and gets the total voltage
 * from it.
 */
PowerCell::PowerCell(vector<PowerTeam> powerCell) {
    mPowerCell = powerCell;
    mTotalVoltage = 0;
    for (int i = 0; i < mPowerCell.size(); ++i) {
        mTotalVoltage += mPowerCell[i].getVoltage();
    }
}

/*!
 * Returns the total voltage across all power cells.
 *
 * @return The total voltage across all power cells.
 */
double PowerCell::getTotalVoltage() {
    return mTotalVoltage;
}

/*!
 * Takes power from the PowerCell. Prints an error message if current draw is
 * too high.
 */
void PowerCell::drawPower(double power) {
    if (power > mTotalVoltage) {
        cout << "Power draw too high, cannot draw: " << power << " with only " \
        << mTotalVoltage << " power left." << endl;
        return;
    }

    // While we still have power, and we haven't moved past our final cell,
    // keep drawing power from each cell.
    for (int i = 0; power != 0; ++i) {
        double powerDrawn;
        if (power > mPowerCell[i].getVoltage()) {
            powerDrawn = mPowerCell[i].getVoltage();
        } else {
            powerDrawn = power;
        }
        mPowerCell[i].setVoltage(mPowerCell[i].getVoltage() - powerDrawn);
        mTotalVoltage -= powerDrawn;
        power -= powerDrawn;
    }
}

/*!
 * Prints the total power in the cell, and the power in each specific cell.
 */
void PowerCell::printCell() {
    cout << "Total power left: " << mTotalVoltage << endl;
    cout << "Power in each cell: " << endl;
    for (int i = 0; i < mPowerCell.size(); ++i) {
        cout << "Battery " << i + 1 << ": " << mPowerCell[i].getVoltage() \
        << endl;
    }
}
