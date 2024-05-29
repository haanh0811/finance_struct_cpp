#include "Borrower.h"


Borrower::Borrower(std::string name) {
    this->setName(name);
}

Deal Borrower::requestDeal(Agent* a, double d, int fin) {
    std::string devise = "USD";
    a->createDeal(this->getName(), d, devise, fin);
}
