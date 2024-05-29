//
// Created by Julien on 28/05/2024.
//

#include "Facility.h"

Facility::Facility(Deal* deal, int fin, double montant, float taux, std::string devises, Lender *lenders[6], int size) {
    this->deal = deal;
    this->amount = montant;
    this->devises = devises;
    this->end = fin;
    this->rate = taux;
    this->interest = 0;
    this->start = Date().getTime();
    this->amountToRepay = montant;
    for (int i=0; i<size; i++){
        this->lenders[i] = lenders[i];
    }
}

void Facility::InterstCalculation() {
    this->interest = this->interest * (this->amountToRepay + this->interest) * this->rate;
}

void Facility::applyRepay(double amount) {
    double toRepayInterest = amount * 0.2;
    double toRepayLoan = amount * 0.8;
    this->amountToRepay = this->amountToRepay - toRepayLoan;
    this->amount = this->amount - toRepayInterest;
}

float Facility::getRate() {
    return rate;
}

