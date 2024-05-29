//
// Created by Julien on 28/05/2024.
//

#include "Entreprise.h"

Entreprise::Entreprise(std::string &nom) : name(nom) {}
Entreprise::Entreprise(){}

std::string Entreprise::getName() {
    return name;
}

void Entreprise::setName(std::string name) {
    Entreprise::name = name;
}
