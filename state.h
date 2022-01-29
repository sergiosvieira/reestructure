/********************************************************************************
 *   Copyright (C) 2022 by Prof. MSc. Sérgio Vieira <sergio.vieira@ifce.edu.br> *
 ********************************************************************************/

#ifndef STATE_H
#define STATE_H

/*
digraph G {

    init -> name [label=" is_word"]
    name -> name [label=" is_word"]
    name -> birth [label=" is_date"]
    birth -> mother [label=" is_word"]
    birth -> cpf [label=" is_cpf"]
    mother -> mother [label=" is_word"]
    mother -> cpf [label=" is_cpf"]
    mother -> vacdesc [label=" is_vacc"]
    cpf -> vacdate [label=" is_date"]
    cpf -> mother [label=" is_word"]
    vacdate -> vacdesc [label=" is_word"]
    vacdate -> vacdose [label=" is_dose"]
    vacdesc -> vacdesc [label=" is_word"]
    vacdesc -> vacdose [label=" is_dose"]
    vacdesc -> vacdate [label=" is_date"]
    vacdose -> vacbatc [label=" is_word"]
    vacbatc -> vaccnes [label=" is_word"]
    vaccnes -> vacdate [label=" is_date"]
    vaccnes -> sink [label=" is_word"]
    sink -> sink [label=" is_word"]
    sink-> vacdesc [label=" is_vacc"]
    vaccnes -> key [label=" is_key"]
    key -> init
}
*/

#include <map>

enum class State {init, name, birth, mother, cpf, vacdesc, vacdate, vacdose, vacbatc, vaccnes, sink, key};

std::string state_str(const State& s) {
    static std::map<State, std::string> m = {
        {State::init, "init"},
        {State::name, "name"},
        {State::birth, "birth"},
        {State::mother, "mother"},
        {State::cpf, "cpf"},
        {State::vacdesc, "vacdesc"},
        {State::vacdate, "vacdate"},
        {State::vacdose, "vacdose"},
        {State::vacbatc, "vacbatc"},
        {State::vaccnes, "vaccnes"},
        {State::sink, "sink"},
        {State::key, "key"},
    };
    return m[s];
}

#endif // STATE_H
