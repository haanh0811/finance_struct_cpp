#include <iostream>
#include "Lender.h"
#include "Agent.h"
#include "Borrower.h"
#include "PrintMain.h"

const int MAX_REPAYMENTS = 10;



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
    printDealDetails(d1);

    std::cout << std::endl << "Status" << std::endl;
    std::cout << "----------------" << std::endl;
    Lender* lendersD1F1[1] = {l1};
    float proportionsD1F1[1] = {0.5};
    a->setPoolForNextFacility(lendersD1F1, proportionsD1F1, 1);
    a->UnlockMoney(d1, 10, "USD - EUR", 1, 2, 0.2);
    std::cout << "- Facility 1 :" <<  d1->getStatus() << std::endl;


    Lender* lendersD1F2[2] = {l2, l3};
    float proportionsD1F2[2] = {0.6, 0.3};
    a->setPoolForNextFacility(lendersD1F2, proportionsD1F2, 2);
    a->UnlockMoney(d1, 10, "USD - EUR", 1, 3, 0.1);
    std::cout << "- Facility 2 :" <<  d1->getStatus()  <<  std::endl;

 
    Lender* lendersD1F3[2] = {l2, l3};
    float proportionsD1F3[2] = {0.6, 0.3};
    a->setPoolForNextFacility(lendersD1F2, proportionsD1F3, 2);
    a->UnlockMoney(d1, 80, "USD - EUR", 1, 3, 0.1);
    std::cout << "- Facility 3 :" <<  d1->getStatus() <<std::endl;

    std::cout << std::endl << "Facilities Recap Table :" << std::endl;
    double sumNeededToBeRepaid = printFacilityTable(d1);
    std::cout << "Sum to be repaid :" <<  sumNeededToBeRepaid <<std::endl;
    

    float repayments[MAX_REPAYMENTS][2] = {0};
    int numRepayments = 0;
    getUserRepaymentInput(repayments, numRepayments, b, d1, a, sumNeededToBeRepaid);
    std::cout << std::endl << "Repayments Recap Table :" << std::endl;
    printRepaymentTable(repayments, numRepayments);
    
    std::cout << std::endl << "Lender Portfolios Recap Table : " << std::endl;
    printLenderPortfolios(lendersD1, 3);

    return 0;
}
