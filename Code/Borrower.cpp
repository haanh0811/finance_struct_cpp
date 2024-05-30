#include "Borrower.h"


Borrower::Borrower(std::string name) {
    this->setName(name);
}

Deal* Borrower::requestDeal(Agent* a, double d, int start, int fin) {
    std::string devise = "USD";
    return a->createDeal(this->getName(), d, devise, start, fin);
}

void Borrower::repay(Facility* f, Agent* a, double amount) {
    return a->repayFacility(f, amount);
}
