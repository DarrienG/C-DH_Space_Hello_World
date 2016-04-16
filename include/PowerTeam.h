/*!
 * @file
 */

// Copyright 2016 UMass Lowell Command and Data Handling Team

#ifndef INCLUDE_POWERTEAM_H_
#define INCLUDE_POWERTEAM_H_

class PowerTeam {
 private:
    double mVoltage;

 public:
    PowerTeam();
    explicit PowerTeam(double voltage);
    double getVoltage() const;
    void setVoltage(double voltage);
    PowerTeam operator+(const PowerTeam& toAdd);
};

#endif  // INCLUDE_POWERTEAM_H_
