/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#include "PowerTeam.h"

/*!
 * Default constructor. Having a useless default constructor is bad practice,
 * but it's part of the assignment I made, so it's here.
 */
PowerTeam::PowerTeam() {
    // Intentionally do nothing
}

/*!
 * Public constructor. Takes a voltage, and sets the data member mVoltage with
 * it.
 *
 * @param voltage The voltage that
 */
PowerTeam::PowerTeam(double voltage) {
    mVoltage = voltage;
}

/*!
 * Basic getter. Returns stored voltage.
 *
 * @return double Stored voltage.
 */
double PowerTeam::getVoltage() {
    return mVoltage;
}

/*!
 * Basic setter. Sets voltage data member to given argument.
 *
 * @param voltage Voltage to be stored.
 */
void PowerTeam::setVoltage(double voltage) {
    mVoltage = voltage;
}
