//
// Created by Anton Zaripov on 15.12.2021.
//
#pragma once

#include "fstream"

class Hotel {

public:

    int lowest = 0, middle = 0, high = 0;

    Hotel() = default;

    bool welcomes() const {
        return lowest < 10 || middle < 10 || high < 5;
    }

    void out(std::ofstream &basicOfstream) const {
        basicOfstream << "total:\n   200$ rooms: " << lowest << "\n   400$ rooms: " << middle << "\n   600$ rooms: "
                      << high << '\n';
    }
};
