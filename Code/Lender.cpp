//
// Created by Julien on 28/05/2024.
//

#include "Lender.h"

Lender::Lender(std::string name) {
    setName(name);
    totalLent = 0.0;
    portfolio = new Portfolio() ;
}
Lender::~Lender() {
    delete portfolio;
}
Portfolio* Lender::getPortfolio() {
    return portfolio;
}


void Lender::addTotalLent(double amount) {
    totalLent += amount;
}

double Lender::getTotalLent() const {
    return totalLent;
}

