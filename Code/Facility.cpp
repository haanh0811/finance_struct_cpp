//
// Created by Julien on 28/05/2024.
//

#include "Facility.h"

Facility::Facility(const std::string& name, double size, double interestRate, int priority){
    this->name = name;
    this->size = size;
    this->interestRate = interestRate;
    remainingAmount = size;
    this->priority = priority;
    totalInterest = 0;
    totalRepayment = 0;

}

void Facility::addLender(Lender* lenders[], double amounts[], int lenderCount) {
    for (int i = 0; i < lenderCount; ++i) {
        this->lenders.push_back(std::make_pair(lenders[i], amounts[i]));
        lenders[i]->addTotalLent(amounts[i]);
    }
}

void Facility::addInterest(double amount) {
    totalInterest += amount;
    for (const auto& lenderPair : lenders) {
        Lender* lender = lenderPair.first;
        double lenderContribution = lenderPair.second;
        double lenderInterest = (amount * lenderContribution) / size;
        lender->getPortfolio()->addInterest(lenderInterest);
    }
}

void Facility::addRepayment(double amount) {
    totalRepayment += amount;
    remainingAmount -= amount;
    for (const auto& lenderPair : lenders) {
        Lender* lender = lenderPair.first;
        double lenderContribution = lenderPair.second;
        double lenderRepayment = (amount * lenderContribution) / size;
        lender->getPortfolio()->addRepayment(lenderRepayment);
    }
}
double Facility::getRemainingAmount() const {
    return remainingAmount;
}

double Facility::getTotalInterest() const {
    return totalInterest;
}

double Facility::getTotalRepayment() const {
    return totalRepayment;
}

int Facility::getPriority() const {
    return priority;
}

double Facility::calculateInterest(int period) const {
    return (size * interestRate * period) / 100.0;
}



