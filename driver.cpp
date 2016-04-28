/*!
 * @file
 */

// Copyright 2016 David Connolly

#include "PowerTeam.h"
#include "OtherTeam.h"
#include "PowerCell.h"
#include <string>
#include <iostream>
//#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void powerUp(vector<PowerTeam> *vec, int numItems);
void drainCell(PowerCell *battery);
void rechargeCell(PowerCell *battery);
string nameBattery();

int main(int argc, char const *argv[]) {
    cout << "This is Assignment 5 for Cubesat\n";
    vector<PowerTeam> powerVec;
    powerUp(&powerVec, 4);
    PowerCell battery(powerVec);
    battery.printCell();
    drainCell(&battery);
    battery.printCell();
    cout << "Recharging " << nameBattery() << "... " << endl;
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

/*!
 * Helper function. A function used to quickly get a name and add it to a
 * battery.
 */
string nameBattery() {
    string name;
    cout << "Please enter a good name: " << endl; cin << name;
    return name;
}
