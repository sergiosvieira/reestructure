/********************************************************************************
 *   Copyright (C) 2022 by Prof. MSc. Sérgio Vieira <sergio.vieira@ifce.edu.br> *
 ********************************************************************************/

#ifndef PROCESSING_H
#define PROCESSING_H
#include "state.h"
#include "person.h"

Person& getLastPerson(Rows& rows) {
    return rows[rows.size() - 1];
}

Vaccine& getLastVaccine(Rows& rows) {
    Person& p = getLastPerson(rows);
    VectorVaccine& v = p.vaccines;
    return v[v.size() - 1];
}

State processInitWord(Rows& rows,
                      const std::string& input) {
    rows.push_back({});
    getLastPerson(rows).name += input + " ";
    return State::name;
}

State processNameWord(Rows& rows,
                      const std::string& input) {
    getLastPerson(rows).name += input + " ";
    return State::name;
}

State processNameDate(Rows& rows,
                      const std::string& input) {
    getLastPerson(rows).name.pop_back();
    getLastPerson(rows).birth = input;
    return State::birth;
}

State processBirthWord(Rows& rows,
                       const std::string& input) {
    getLastPerson(rows).mother += input + " ";
    return State::mother;
}

State processBirthCPF(Rows& rows,
                       const std::string& input) {
    getLastPerson(rows).cpf = input;
    return State::cpf;
}

State processMotherWord(Rows& rows,
                        const std::string& input) {
    getLastPerson(rows).mother += input + " ";
    return State::mother;
}

State processMotherVacc(Rows& rows,
                         const std::string& input) {
    return State::vacdesc;
}

State processMotherCPF(Rows& rows,
                         const std::string& input) {
    getLastPerson(rows).mother.pop_back();
    getLastPerson(rows).cpf = input;
    return State::cpf;
}

State processCPFDate(Rows& rows,
                     const std::string& input) {
    getLastPerson(rows).vaccines.push_back({});
    getLastVaccine(rows).date = input;
    return State::vacdate;
}

State processVacDateWord(Rows& rows,
                         const std::string& input) {
    getLastVaccine(rows).name += input + " ";
    return State::vacdesc;
}

State processVacDateDose(Rows& rows,
                         const std::string& input) {
    getLastVaccine(rows).dose = input;
    return State::vacdose;
}

State processVacDescDate(Rows& rows,
                         const std::string& input) {
    return State::vacdate;
}

State processVacDescWord(Rows& rows,
                         const std::string& input) {
    getLastVaccine(rows).name += input + " ";
    return State::vacdesc;
}

State processVacDescDose(Rows& rows,
                         const std::string& input) {
    getLastVaccine(rows).name.pop_back();
    std::string manufacturer = extract_last_word(getLastVaccine(rows).name);
    getLastVaccine(rows).manufacturer = manufacturer;
    getLastVaccine(rows).dose = input;
    return State::vacdose;
}


State processVacDoseWord(Rows& rows,
                         const std::string& input) {
    getLastVaccine(rows).batch = input;
    return State::vacbatc;
}

State processVacBatchWord(Rows& rows,
                         const std::string& input) {
    getLastVaccine(rows).cnes = input;
    return State::vaccnes;
}

State processVacCnessKey(Rows& rows,
                         const std::string& input) {
    getLastPerson(rows).key = input;
    return State::init;
}

State processVacCnessDate(Rows& rows,
                          const std::string& input) {
    return processCPFDate(rows, input);
}

#endif // PROCESSING_H
