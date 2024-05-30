//
// Created by Julien on 28/05/2024.
//

#include "Facility.h"

Facility::Facility(Deal* deal, int start, int fin, double montant, float taux, std::string devises, Lender *lenders[6], float proportions[6], int size) {
    this->start = start;
    this->deal = deal;
    this->lentAmount = montant;
    this->devises = devises;
    this->end = fin;
    this->rate = taux;
    this->interestAmount = pow(rate, (end-start)) * lentAmount ;
    this->interestAmountToRepay = pow(rate, (end-start)) * lentAmount ;
    this->lentAmountToRepay = montant;
    for (int i=0; i<size; i++){
        this->proportions[i] = proportions[i];
    }
    for (int i=0; i<size; i++){
        this->lenders[i] = lenders[i];
    }
    this->size = size;
}

void Facility::InterstCalculation() {
    this->interestAmount = this->interestAmount * (this->lentAmountToRepay + this->interestAmount) * this->rate;
}

void Facility::applyRepay(double amount) {
    double toRepayInterest = amount * 0.2;
    double toRepayLoan = amount * 0.8;
    this->lentAmountToRepay = this->lentAmountToRepay - toRepayLoan;
    this->lentAmount = this->lentAmount - toRepayInterest;
}

float Facility::getRate() {
    return rate;
}

int Facility::getAnEnd() {
    return end;
}

void Facility::setAnEnd(int anEnd) {
    end = anEnd;
}

int Facility::getStart() {
    return start;
}

void Facility::setStart(int start) {
    Facility::start = start;
}

double Facility::getLentAmount() {
    return lentAmount;
}

void Facility::setLentAmount(double amount) {
    Facility::lentAmount = amount;
}

double Facility::getAmountToRepay() {
    return lentAmountToRepay;
}

void Facility::setAmountToRepay(double amountToRepay) {
    Facility::lentAmountToRepay = amountToRepay;
}

double Facility::getInterestAmount() {
    return interestAmount;
}

void Facility::setInterestAmount(double interest) {
    Facility::interestAmount = interest;
}

void Facility::setRate(float rate) {
    Facility::rate = rate;
}

std::string Facility::getDevises() {
    return devises;
}

void Facility::setDevises(std::string devises) {
    Facility::devises = devises;
}

Lender** Facility::getLenders()  {
    return lenders;
}

float* Facility::getProportions() {
    return proportions;
}

Deal *Facility::getDeal() {
    return deal;
}

void Facility::setDeal(Deal *deal) {
    Facility::deal = deal;
}

int Facility::getSize() {
    return size;
}

void Facility::setSize(int size) {
    Facility::size = size;
}

void Facility::repay(double d) {
    double interest = d * (1 - 1 / pow(1 + rate, end - start));
    for (int i=0; i<size; i++){
        lenders[i]->addInterest(interest * proportions[i]);
    }
}
