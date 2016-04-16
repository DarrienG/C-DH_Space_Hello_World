/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#include "OtherTeam.h"

/*!
 * Public constructor. Takes a double, and sets data member to it.
 *
 * @param convertedVal Value to be set.
 */
OtherTeam::OtherTeam(double convertedVal) {
    mConvertedVal = convertedVal;
}

/*!
 * Public constructor. Takes a PowerTeam object, and sets the mConvertedVal to
 * PowerTeam's voltage.
 *
 * @param powerVal PowerTeam. Voltage to be extracted and set.
 */
OtherTeam::OtherTeam(PowerTeam powerVal) {
    mConvertedVal = powerVal.getVoltage();
}

/*!
 * @return double Stored converted value.
 * Basic getter. Returns stored converted value.
 *
 */
double OtherTeam::getConvertedVal() {
    return mConvertedVal;
}

/*!
 * Basic setter. Sets convertedVal data member to given argument.
 *
 * @param convertedVal Converted value to be stored.
 */
void OtherTeam::setConvertedVal(double convertedVal) {
    mConvertedVal = convertedVal;
}
