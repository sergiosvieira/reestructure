/********************************************************************************
 *   Copyright (C) 2022 by Prof. MSc. Sérgio Vieira <sergio.vieira@ifce.edu.br> *
 ********************************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include "utils.h"
#include "vaccine.h"

using VectorVaccine = std::vector<Vaccine>;

struct Person {
    std::string name = "";
    std::string birth = "";
    std::string cpf = "";
    std::string mother = "";
    std::string key = "";
    VectorVaccine vaccines;
    friend std::ostream& operator<<(std::ostream& out, const Person& r) {
        out << "{";
        out << keyname("name") << dquote(r.name) << ", ";
        out << keyname("birth") << dquote(r.birth) << ", ";
        out << keyname("cpf") << dquote(r.cpf) << ", ";
        out << keyname("mother") << dquote(r.mother) << ", ";
        out << keyname("key") << dquote(r.key) << ", ";
        out << keyname("vaccines") << "[";
        for (size_t i = 0; i < r.vaccines.size(); ++i) {
            out << r.vaccines[i];
            if (i != r.vaccines.size() - 1) out << ", ";
        }
        out << "]";
        out << "}";
        return out;
    }
};

using Rows = std::vector<Person>;

#endif // PERSON_H
