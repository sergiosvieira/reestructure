/********************************************************************************
 *   Copyright (C) 2022 by Prof. MSc. Sérgio Vieira <sergio.vieira@ifce.edu.br> *
 ********************************************************************************/

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <algorithm>
#include <regex>
#include <set>

const bool debug_flag = false;

using std::regex, std::smatch;

void debug(const std::string& value) {
    if (debug_flag) std::cout << value << " - ";
}

const std::string dquote(const std::string& value) {
    return "\"" + value + "\"";
}

const std::string keyname(const std::string& value) {
    return dquote(value) + ":";
}

std::string extract_last_word(std::string& value) {
    std::size_t pos = value.find_last_of(' ');
    std::string result = value.substr(pos + 1, value.size() - 1);
    value = value.substr(0, pos);
    return result;
}

bool _true(const std::string& value) {
    return true;
}

bool is_word(const std::string& value) {
    auto lambda = [](char ch) {
        int result = std::isalpha(ch);
        return result;
    };
    if (std::all_of(value.begin(), value.end(), lambda)) {
        debug("is_word");
        return true;
    } else {
        if (value.find("-") != std::string::npos) {
            return true;
        }
        return false;
    }
}

bool is_date(const std::string& value) {
    static regex p("^([0-3]?[0-9])/([0-3]?[0-9])/((?:[0-9]{2})?[0-9]{2}$)");
    smatch m;
    if (regex_search(value, m, p)) {
        debug("is_date");
        return true;
    }
    return false;
}


bool is_cpf(const std::string& value) {
    static regex p("^[0-9]{3}\.[0-9]{3}\.[0-9]{3}\-[0-9]{2}$");
    smatch m;
    if (regex_search(value, m, p)) {
        debug("is_cpf");
        return true;
    }
    return false;
}

bool is_dose(const std::string& value) {
    size_t pos = value.find("Refor");
    if (pos == 0
            && pos != std::string::npos) {
        debug("is_dose");
        return true;
    }
    static regex p("^[0-9]{1,2}/[0-9]{1,2}$");
    smatch m;
    if (regex_search(value, m, p)) {
        debug("is_dose");
        return true;
    }
    return false;
}

bool is_vacc(const std::string& value) {
    static std::set<std::string> vaccs = {
        "COVID-19",
        "PFIZER",
        "CORONAVAC",
        "ASTRAZENECA"
    };
    std::string str = value;
    std::for_each(str.begin(), str.end(), [](char& c){c = std::toupper(c);});
    bool result = vaccs.find(str) != vaccs.end();
    if (result) debug("\tis_vacc\n");
    return result;
}

bool is_key(const std::string& value) {
    static regex p("^\\w{4}\.\\w{4}\.\\w{4}\.\\w{4}$");
    smatch m;
    if (regex_search(value, m, p)) {
        debug("\tis_key\n");
        return true;
    }
    return false;
}

#endif // UTILS_H
