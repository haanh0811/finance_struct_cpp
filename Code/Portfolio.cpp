//
// Created by Julien on 29/05/2024.
//

#include "Portfolio.h"

Portfolio::Portfolio() {
    amount = 0;
}

double Portfolio::getAmount() {
    return amount;
}

void Portfolio::add(double d) {
    amount = amount + d;
}


