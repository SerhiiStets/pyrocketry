#ifndef EQUATIONS_H
#define EQUATIONS_H

double Tsiolkovsky_rocket_equation(double Isp, double Mo, double Mf, double g);
double suicide_burn_height(double Vz, double Fth, double Mship, double g);

#endif