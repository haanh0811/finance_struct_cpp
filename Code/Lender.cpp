//
// Created by Julien on 28/05/2024.
//

#include "Lender.h"

Lender::Lender(std::string name) {
    setName(name);
    portfolio = new Portfolio();
}

