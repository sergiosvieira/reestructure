/********************************************************************************
 *   Copyright (C) 2022 by Prof. MSc. Sérgio Vieira <sergio.vieira@ifce.edu.br> *
 ********************************************************************************/

#ifndef CNES_H
#define CNES_H

#include <iostream>

struct CNES {
    std::string id = "";
    std::string site = "";
    std::string city = "";
    std::string state = "";
    friend std::ostream& operator<<(std::ostream& out, const CNES& c) {
        return out;
    }
};


#endif // CNES_H
