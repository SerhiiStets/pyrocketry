#ifndef DOC_H
#define DOC_H
#include <Python.h>

PyDoc_STRVAR(pyrocketry_doc, "Python module for rocket equations.");

PyDoc_STRVAR(pyrocketry_Tre_doc,
             "Tsiolkovsky rocket equation.\n\n"
             "Args:\n"
             "\tIsp (float): The specific impulse in dimension of time.\n"
             "\tMo (float): The initial total mass, including propellant, a.k.a. wet mass.\n"
             "\tMf (float): The final total mass without propellant, a.k.a. dry mass.\n"
             "\tg (:obj:`float`, optional): Standard gravity. Defaults to 9.80665.\n\n"
             "Returns:\n"
             "\tV (float): The maximum change of velocity of the vehicle.\n");

PyDoc_STRVAR(pyrocketry_suicide_burn_heigh_doc,
             "Suicide burn height calculation.\n\n"
             "Args:\n"
             "\tVz (float): Vertical velocity.\n"
             "\tFth (float): Force from thrust.\n"
             "\tMship (float) Total mass of a vehicle.\n"
             "\tg (:obj:`float`, optional): Standard gravity. Defaults to 9.80665.\n\n"
             "Returns:\n"
             "\tH (float): Height for suicide burn start.\n");

#endif
