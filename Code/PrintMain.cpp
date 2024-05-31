#include <iostream>
#include <iomanip>
#include "PrintMain.h"

void printFacilityTable(Deal* deal) {
    std::cout << std::left << std::setw(10) << "Facility" 
              << std::setw(20) << "Amount to Unlock" 
              << std::setw(30) << "Amount Needed to Repay" 
              << std::setw(50) << "Lenders (Proportions)" << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < deal->getNumberOfFacilities(); ++i) {
        Facility* facility = deal->getFacilities()[i];
        std::cout << std::left << std::setw(10) << i + 1
                  << std::setw(20) << facility->getLentAmount();
        std::cout << std::left << std::setw(10) 
                  << std::setw(20) << facility->getStillToRepay();
        for (int j = 0; j < facility->getSize(); ++j) {
            std::cout << facility->getLenders()[j]->getName() << " (" << facility->getProportions()[j] << ")";
            if (j < facility->getSize() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}


void printRepaymentTable(float repayments[][2], int numRepayments) {
    std::cout << std::left << std::setw(20) << "Repayment Amount"
              << "Paid Facility" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    for (int i = 0; i < numRepayments; ++i) {
        std::cout << std::left << std::setw(20) << repayments[i][0]
                  << repayments[i][1] << std::endl;
    }
}

void printDealDetails(Deal* deal) {
    std::cout << "Deal Details" << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << std::left << std::setw(20) << "Agent:" << deal->getAgent() << std::endl;
    std::cout << std::left << std::setw(20) << "Borrower:" << deal->getBorrower() << std::endl;
    std::cout << std::left << std::setw(20) << "Amount:" << deal->getAmount() << std::endl;
    std::cout << std::left << std::setw(20) << "Currency:" << deal->getDevise() << std::endl;
    std::cout << std::left << std::setw(20) << "Contract Number:" << deal->getContractNumber() << std::endl;
    std::cout << std::left << std::setw(20) << "Status:" << deal->getStatus() << std::endl;

    std::cout << std::endl << "Pool of Lenders" << std::endl;
    std::cout << "----------------" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << std::left << std::setw(20) << deal->getPool()[i]->getName() << std::endl;
    }

}

void printLenderPortfolios(Lender* lenders[], int size) {
    std::cout << std::left << std::setw(20) << "Lender"
              << std::setw(20) << "Portfolio Amount" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << std::left << std::setw(20) << lenders[i]->getName()
                  << std::setw(20) << lenders[i]->getPortfolio()->getAmount() << std::endl;
    }
}

void getUserRepaymentInput(float repayments[][2], int &numRepayments, Borrower* borrower, Deal* deal, Agent* agent) {
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        double amount;
        int indexFacility;
        std::cout << "Enter repayment amount: ";
        std::cin >> amount;
        std::cout << "Enter facility index: ";
        std::cin >> indexFacility;

        Part* part = borrower->repay(deal, agent, amount, indexFacility);
        int facilityIndex = part ? part->getIdxFacility() : 0; 

        repayments[numRepayments][0] = amount;
        repayments[numRepayments][1] = facilityIndex;
        numRepayments++;

        std::cout << "Do you want to enter another repayment? (y/n): ";
        std::cin >> choice;
    }
}
