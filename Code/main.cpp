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
    Deal* d1 = b->requestDeal(a, 100, 0, 3);
    std::cout << d1->toString() << std::endl;
    for (int i=0; i<3; i++){
        std::cout << d1->getPool()[i]->getName() << std::endl;
    }

    std::cout << std::endl << "Facility 1" << std::endl;
    Lender* lendersD1F1[1] = {l1};
    float proportionsD1F1[1] = {0.5};
    a->setPoolForNextFacility(lendersD1F1, proportionsD1F1, 1);
    a->UnlockMoney(d1, 10, "USD - EUR", 1, 2, 0.2);
    std::cout << "D1 - Montant à débloquer:" << d1->getAmountToUnlock() << std::endl;
    std::cout << "Number of lenders:" <<  d1->getFacilities()[0]->getSize() << std::endl;
    for(int i = 0; i<d1->getFacilities()[0]->getSize(); i++){
        std::cout << d1->getFacilities()[0]->getLenders()[i]->getName() << std::endl;
        std::cout << d1->getFacilities()[0]->getProportions()[i]<< std::endl;
    }
    std::cout << "Status:" <<  d1->getStatus() << std::endl;

    std::cout << std::endl << "Facility 2" << std::endl;
    Lender* lendersD1F2[2] = {l2, l3};
    float proportionsD1F2[2] = {0.6, 0.3};
    a->setPoolForNextFacility(lendersD1F2, proportionsD1F2, 2);
    a->UnlockMoney(d1, 10, "USD - EUR", 1, 3, 0.1);
    std::cout << "D1 - Montant à débloquer:" << d1->getAmountToUnlock() << std::endl;
    std::cout << "Number of lenders:" <<  d1->getFacilities()[1]->getSize() << std::endl;
    for(int i = 0; i<d1->getFacilities()[1]->getSize(); i++){
        std::cout << d1->getFacilities()[1]->getLenders()[i]->getName() << std::endl;
        std::cout << d1->getFacilities()[1]->getProportions()[i]<< std::endl;
    }
    std::cout << "Status:" <<  d1->getStatus() << std::endl;

    std::cout << std::endl << "Facility 2" << std::endl;
    Lender* lendersD1F3[2] = {l2, l3};
    float proportionsD1F3[2] = {0.6, 0.3};
    a->setPoolForNextFacility(lendersD1F2, proportionsD1F3, 2);
    a->UnlockMoney(d1, 80, "USD - EUR", 1, 3, 0.1);
    std::cout << "D1 - Montant à débloquer:" << d1->getAmountToUnlock() << std::endl;
    std::cout << "Number of lenders:" <<  d1->getFacilities()[1]->getSize() << std::endl;
    for(int i = 0; i<d1->getFacilities()[2]->getSize(); i++){
        std::cout << d1->getFacilities()[2]->getLenders()[i]->getName() << std::endl;
        std::cout << d1->getFacilities()[2]->getProportions()[i]<< std::endl;
    }
    std::cout << "Status:" <<  d1->getStatus() << std::endl;


    std::cout << std::endl << "Test " << std::endl;
    b->repay(d1, a, 6,0);
    b->repay(d1, a, 6, 0);
    std::cout << l1->getPortfolio()->getAmount() << std::endl;

    return 0;
}
