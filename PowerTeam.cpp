/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#include "PowerTeam.h"

/*!
 * 🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙
 */
PowerTeam::PowerTeam() {
    // Intentionally do nothing
}

/*!
 * 🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙
 *
 * @param voltage The voltage that
 */
PowerTeam::PowerTeam(double voltage) {
    mVoltage = voltage;
}

/*!
 * 🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙
 *
 * @return double Stored voltage.
 */
double PowerTeam::getVoltage() const {
    return mVoltage;
}

/*!
 * 🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙
 *
 * @param voltage Voltage to be stored.
 */
void PowerTeam::setVoltage(double voltage) {
    mVoltage = voltage;
}

/**
 * Simply add the values within two PowerTeam variables,
 * then store it in a new PowerTeam var, and return it.
 *
 * @param toAdd The other PowerTeam to add to the current one
 * @return PowerTeam new variable made with addition of two other PowerTeams
 */
PowerTeam PowerTeam::operator+(const PowerTeam& toAdd) {
    PowerTeam toReturn;
    double value = mVoltage + toAdd.getVoltage();
    toReturn.setVoltage(value);
    return toReturn;
}
