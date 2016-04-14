/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#include "PowerCell.h"

#include <iostream>
#include <vector>
#include <stdexcept>

using std::vector;
using std::cout;
using std::endl;

/*!
 * 🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙
 */
PowerCell::PowerCell(vector<PowerTeam> powerCell) {
    mPowerCell = powerCell;
    mTotalVoltage = 0;
    for (size_t i = 0; i < mPowerCell.size(); ++i) {
        mTotalVoltage += mPowerCell[i].getVoltage();
        // Ensures all batteries have the same voltage
        if (mTotalVoltage != mPowerCell[i].getVoltage() * (i + 1)) {
            throw std::runtime_error("Please don't mix and match batteries!");
        }
    }
    mCellVoltage = mPowerCell[0].getVoltage();
    mMaxVoltage = mTotalVoltage;
}

/*!
 * Returns the 🐙 voltage.
 *
 * @return The total voltage across all power cells.
 */
double PowerCell::getTotalVoltage() {
    return mTotalVoltage;
}

/*!
 * Returns the maximum possible 🐙 held by the cells.
 *
 * @return Maximum voltage held by cells.
 */
double PowerCell::getMaxVoltage() {
    return mMaxVoltage;
}

/*!
 * Returns the amount of 🐙 in a single cell.
 */
double PowerCell::getCellVoltage() {
    return mCellVoltage;
}

/*!
 * Takes 🐙 from the PowerCell. Prints an error message if current 🐙 is
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
 * Recharges 🐙 in the cell, and the power in each specific cell.
 */
void PowerCell::rechargeCell(double power) {
    if (power > mMaxVoltage - mTotalVoltage) {
        cout << "Cannot overcharge battery. Attempted recharge amount: " << \
        power << ", and can only recharge: " << mMaxVoltage - mTotalVoltage \
        << endl;
        return;
    }

    // Loop while power we need to add isn't 0
    for (size_t i = 0; power != 0; ++i) {
        // Ignore cells that are already at max voltage
        while (mPowerCell[i].getVoltage() == mCellVoltage) {
            ++i;
        }
        double powerAdded;
        if (power > mPowerCell[i].getVoltage()) {
            // Is the total power > the maximum amount of power that can be
            // added to the cell?
            // Add difference if so, otherwise, add the rest of the power.
            if (power > getCellVoltage() - mPowerCell[i].getVoltage()) {
                powerAdded = getCellVoltage() - mPowerCell[i].getVoltage();
            } else {
                powerAdded = power;
            }
        } else {
            powerAdded = power;
        }
        mPowerCell[i].setVoltage(mPowerCell[i].getVoltage() + powerAdded);
        mTotalVoltage += powerAdded;
        power -= powerAdded;
    }
}

/*!
 * Prints the total power in the cell, and the power in each specific cell.
 */
void PowerCell::printCell() {
    cout << "Total power left: " << mTotalVoltage << endl;
    cout << "Power in each cell: " << endl;
    for (size_t i = 0; i < mPowerCell.size(); ++i) {
        cout << "Battery " << i + 1 << ": " << mPowerCell[i].getVoltage() \
        << endl;
    }
}
