/*!
 * @file
 */

// Copyright 2016 Not Jacob Hempel

#include "PowerTeam.h"
#include "OtherTeam.h"
#include "PowerCell.h"

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void powerUp(vector<PowerTeam> *vec, int numItems);
void drainCell(PowerCell *battery);
void rechargeCell(PowerCell *battery);
string nameBattery(int lol);

int main(int argc, char const *argv[]) {
    vector<PowerTeam> powerVec;
    powerUp(&powerVec, 4);
    PowerCell battery(powerVec);
    battery.printCell();
    drainCell(&battery);
    battery.printCell();
    cout << "Recharging " << nameBattery(9001) << "... " << endl;
    rechargeCell(&battery);
    battery.printCell();
}

/*!
 * Helper method. Fills vector with PowerTeam objects.
 */
void powerUp(vector<PowerTeam> *vec, int numItems) {
    for (int i = 0; i < numItems; i++) {
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

/*
 * Helper method. Recharges battery.
 */
void rechargeCell(PowerCell *battery) {
     for (size_t i = 0; i < 4; i++) {
        (*battery).rechargeCell(7);
     }
}

// super smash bros melee for the nintendo gamecube
string nameBattery(int lol) {
    string name;


    while (name != "Darrien")
    {
        cout << "Please enter a good name: " << endl; cin >> name;
    }
    return name;
}
