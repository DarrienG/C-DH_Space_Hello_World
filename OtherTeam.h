/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#ifndef OTHERTEAM_H_
#define OTHERTEAM_H_

#include "PowerTeam.h"
#include <stdexcept>

class OtherTeam {
 private:
    double mConvertedVal;

 public:
    explicit OtherTeam(double convertedVal);
    explicit OtherTeam(PowerTeam powerVal);
    double getConvertedVal();
    void setConvertedVal(double convertedVal);
};

#endif  // OTHERTEAM_H_
