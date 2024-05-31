//
// Created by Julien on 28/05/2024.
//

#include "Facility.h"
#include <cmath>

Facility::Facility(int start, int fin, double montant, float taux, std::string devises, Lender *lenders[6], float proportions[6], int size) {
    this->start = start;
    this->partsNb = 0;
    this->lentAmount = montant;
    this->devises = devises;
    this->end = fin;
    this->rate = taux;
    this->stillToRepay = pow(1+rate, (end-start)) * lentAmount;
    for (int i=0; i<size; i++){
        this->proportions[i] = proportions[i];
    }
    for (int i=0; i<size; i++){
        this->lenders[i] = lenders[i];
    }
    this->size = size;
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

int Facility::getSize() {
    return size;
}

void Facility::setSize(int size) {
    Facility::size = size;
}

Part* Facility::repay(double d,int idxFacility) {
    if (d > stillToRepay){
        throw 1;
    }
    double interest = d * (1 - 1 / pow(1 + rate, end - start));
    for (int i=0; i<size; i++){
        lenders[i]->addInterest(interest * proportions[i]);
    }
    stillToRepay -= d;
    int index = partsNb;
    parts[index]  = new Part(d,idxFacility);
    partsNb++;
    return parts[index];
}

double Facility::getStillToRepay() {
    return stillToRepay;
}
