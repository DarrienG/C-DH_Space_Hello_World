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
    double getVoltage() const;
    void setVoltage(double voltage);

    PowerTeam operator+(const PowerTeam& toAdd);
};

#endif  // POWERTEAM_H_
