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
    this->size = size;
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

double Facility::getAmount() {
    return amount;
}

void Facility::setAmount(double amount) {
    Facility::amount = amount;
}

double Facility::getAmountToRepay() {
    return amountToRepay;
}

void Facility::setAmountToRepay(double amountToRepay) {
    Facility::amountToRepay = amountToRepay;
}

double Facility::getInterest() {
    return interest;
}

void Facility::setInterest(double interest) {
    Facility::interest = interest;
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

