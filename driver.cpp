/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#include "PowerTeam.h"
#include "OtherTeam.h"
#include "PowerCell.h"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void powerUp(vector<PowerTeam> *vec, int numItems);
void drainCell(PowerCell *battery);

int main(int argc, char const *argv[]) {
    vector<PowerTeam> powerVec;
    powerUp(&powerVec, 4);
    PowerCell battery(powerVec);
    battery.printCell();
    drainCell(&battery);
    battery.printCell();
    return 0;
}

/*!
 * Helper method. Fills vector with PowerTeam objects.
 */
void powerUp(vector<PowerTeam> *vec, int numItems) {
    for (size_t i = 0; i < numItems; i++) {
        PowerTeam tmpTeam(5);
        (*vec).push_back(tmpTeam);
    }
}

/*!
 * Helper method. Drains power from battery.
 */
void drainCell(PowerCell *battery) {
    for (size_t i = 0; i < 4; i++) {
        (*battery).drawPower(8);
    }
}
