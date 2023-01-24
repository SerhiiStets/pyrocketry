#include <math.h>

double Tsiolkovsky_rocket_equation(double Isp, double Mo, double Mf, double g)
{
    return Isp * g * log(Mo / Mf);
}

double suicide_burn_height(double Vz, double Fth, double Mship, double g)
{
    return Vz * Vz / (2 * (Fth / Mship - g));
}
