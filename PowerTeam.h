/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#ifndef POWERTEAM_H_
#define POWERTEAM_H_

class PowerTeam {
 private:
    double mVoltage = -1;

 public:
    PowerTeam();
    explicit PowerTeam(double voltage);
    double getVoltage();
    void setVoltage(double voltage);
};

#endif  // POWERTEAM_H_
