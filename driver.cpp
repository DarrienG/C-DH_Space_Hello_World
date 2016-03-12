/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#include "PowerTeam.h"
#include "OtherTeam.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    PowerTeam power(5.55);
    PowerTeam backupPower;
    backupPower.setVoltage(3.141592653589793238);
    OtherTeam other(power);
    OtherTeam backupOther(backupPower.getVoltage());

    cout << "power's power: " << power.getVoltage() << endl;
    cout << "other's conveted power: " << other.getConvertedVal() << endl;
    cout << "backupPower's power: " << backupPower.getVoltage() << endl;
    cout << "backupOther's power: " << backupOther.getConvertedVal() << endl;

    return 0;
}
