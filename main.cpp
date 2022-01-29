/********************************************************************************
 *   Copyright (C) 2022 by Prof. MSc. Sérgio Vieira <sergio.vieira@ifce.edu.br> *
 ********************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>
#include <functional>
#include "state.h"
#include "person.h"
#include "vaccine.h"
#include "processing.h"

using std::cin, std::cout;
using Checking = std::function<bool(const std::string&)>;
using Processing = std::function<State(Rows&, const std::string&)>;
using Pair = std::pair<Checking, Processing>;
using Actions = std::vector<Pair>;
using Map = std::map<State, Actions>;

static Map states = {
    {State::init, {{is_word, processInitWord}}},
    {State::name, {{is_word, processNameWord}, {is_date, processNameDate}}},
    {State::birth, {{is_cpf, processBirthCPF}, {is_word, processBirthWord}}},
    {State::mother, {{is_cpf, processMotherCPF}, {is_vacc, processMotherVacc}, {is_word, processMotherWord}}},
    {State::cpf, {{is_date, processCPFDate}}},
    {State::vacdate, {{is_word, processVacDateWord}, {is_dose, processVacDateDose}}},
    {State::vacdesc, {{is_date, processVacDescDate}, {is_word, processVacDescWord}, {is_dose, processVacDescDose}}},
    {State::vacdose, {{_true, processVacDoseWord}}},
    {State::vacbatc, {{_true, processVacBatchWord}}},
    {State::vaccnes, {{is_date, processVacCnessDate}, {is_key, processVacCnessKey}}},
};


int main() {
    Rows rows;
    std::string input;
    State current = State::init;
    while (cin >> input) {
        for (Pair& p: states[current]) {
            auto [checking, processing] = p;
            if (checking(input)) {
                if (debug_flag) cout << "[+] " << state_str(current) << " -> " ;
                current = processing(rows, input);
                if (debug_flag) cout << "(" << input << ") -> ";
                if (debug_flag) cout << state_str(current) << "\n";
                break;
            }
        }
    }
    std::cout << "{ " << keyname("rows") << "[";
    size_t i = 0;
    for (auto const& r: rows) {
        std::cout << r;
        if (i != rows.size() - 1) std::cout << ", ";
        ++i;
    }
    std::cout << "]}";
    return 0;
}
