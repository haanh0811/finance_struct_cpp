#include <iostream>
#include "Lender.h"
#include "Agent.h"
#include "Borrower.h"

int main() {
    Agent* a = new Agent("BNP");
    Borrower* b = new Borrower("Air France");

    Lender* l1 = new Lender("CA");
    Lender* l2 = new Lender("SG");
    Lender* l3 = new Lender("Crédit Mutuel");
    int sizeD1 = 3;
    Lender* lendersD1[3] = {l1,l2, l3};
    a->setFuturePool(lendersD1, sizeD1);
    Deal* d1 = b->requestDeal(a, 100, 3);

    Lender* lendersD1F1[1] = {l1};
    a->setPoolForNextFacility(lendersD1F1, 1);

    Facility* f1d1 = a->UnlockMoney(d1, 20, "USD - EUR", 2, 0.1);

    std::cout << d1->toString() << std::endl;
    for (int i=0; i<sizeof(lendersD1); i++){
        std::cout << d1->getPool()[i]->getName() << std::endl;
    }
    std::cout << f1d1->getRate() << std::endl;

    return 0;
}
