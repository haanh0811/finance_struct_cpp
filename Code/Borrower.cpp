#include "Borrower.h"


Borrower::Borrower(std::string name) {
    this->setName(name);
}

Deal* Borrower::requestDeal(Agent* a, double d, int start, int fin) {
    std::string devise = "USD";
    return a->createDeal(this->getName(), d, devise, start, fin);
}

Part* Borrower::repay(Deal* d, Agent* a, double amount, int indexFacility) {
    return a->repayFacility(d, amount, indexFacility);
}
