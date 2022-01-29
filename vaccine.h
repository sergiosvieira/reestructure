/********************************************************************************
 *   Copyright (C) 2022 by Prof. MSc. Sérgio Vieira <sergio.vieira@ifce.edu.br> *
 ********************************************************************************/

#ifndef VACCINE_H
#define VACCINE_H

#include <iostream>
#include "utils.h"

struct Vaccine {
    std::string date = "";
    std::string name = "";
    std::string manufacturer = "";
    std::string dose = "";
    std::string batch = "";
    std::string cnes = "";
    friend std::ostream& operator<<(std::ostream& out, const Vaccine& v) {
        out << "{";
        out << keyname("date") << dquote(v.date) << ", ";
        out << keyname("name") << dquote(v.name) << ", ";
        out << keyname("manufacturer") << dquote(v.manufacturer) << ", ";
        out << keyname("dose") << dquote(v.dose) << ", ";
        out << keyname("batch") << dquote(v.batch) << ", ";
        out << keyname("cnes") << dquote(v.cnes);
        out << "}";
        return out;
    }
};



#endif // VACCINE_H
