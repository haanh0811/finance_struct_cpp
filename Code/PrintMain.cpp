#include <iostream>
#include <iomanip>
#include <cmath>
#include "PrintMain.h"
#include <string>
#include <sstream>
#include <limits>

double printFacilityTable(Deal* deal) {
    std::cout << std::left << std::setw(10) << "Facility" 
              << std::setw(20) << "Amount to Unlock" 
              << std::setw(30) << "Amount Needed to Repay" 
              << std::setw(50) << "Lenders (Proportions)" << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    double sumNeededToBeRepaid = 0 ;
    for (int i = 0; i < deal->getNumberOfFacilities(); ++i) {
        Facility* facility = deal->getFacilities()[i];
        std::cout << std::left << std::setw(10) << i + 1
                  << std::setw(20) << facility->getLentAmount();
        std::cout << std::left << std::setw(10) 
                  << std::setw(20) << facility->getStillToRepay();
        sumNeededToBeRepaid += facility->getStillToRepay();
        for (int j = 0; j < facility->getSize(); ++j) {
            std::cout << facility->getLenders()[j]->getName() << " (" << facility->getProportions()[j] << ")";
            if (j < facility->getSize() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        
    }
    return sumNeededToBeRepaid;
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

void printLenderPortfolios(Agent *a,Lender* lenders[], int size) {
    std::cout << std::left << std::setw(20) << "Lender"
              << std::setw(20) << "Portfolio Amount" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::left << std::setw(20) << a->getName()
            << std::setw(20) << a->getPortfolio()->getAmount() << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << std::left << std::setw(20) << lenders[i]->getName()
                  << std::setw(30) << lenders[i]->getPortfolio()->getAmount() << std::endl;
    }
}

bool isValidNumber(const std::string& str, double& number) {
    std::istringstream iss(str);
    iss >> number;
    return !(iss.fail() || !iss.eof());
}

void getUserRepaymentInput(float repayments[][2], int &numRepayments, Borrower* borrower, Deal* deal, Agent* agent, double sumNeededToBeRepaid) {
    double paidAmount = 0;
    double tolerance = 0.0001;
    
    while (std::fabs(paidAmount - sumNeededToBeRepaid) > tolerance ) {
        double amount;
        double indexFacility;
        std::string input;
        std::cout << "Amount needed to be repaid : " << sumNeededToBeRepaid - paidAmount << std::endl;
        std::cout << "Enter repayment amount: ";

        while (true) {
            std::cin >> input;
            if (isValidNumber(input, amount) && amount > 0) {
                break;
            } else {
                std::cout << "Invalid input. Please enter a valid repayment amount: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

   
        while (amount > (sumNeededToBeRepaid - paidAmount)) {
            std::cout << "The entered amount exceeds the remaining amount to be repaid. Please enter a valid repayment amount: ";
            while (true) {
                std::cin >> input;
                if (isValidNumber(input, amount) && amount > 0) {
                    break;
                } else {
                    std::cout << "Invalid input. Please enter a valid repayment amount: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }

        std::cout << "Enter facility index: ";
        while (true) {
            std::cin >> input;
            if (isValidNumber(input, indexFacility) && indexFacility >= 0) {
                break;
            } else {
                std::cout << "Invalid input. Please enter a valid facility index: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        paidAmount += amount;
        

        Part* part = borrower->repay(deal, agent, amount, indexFacility);
        int facilityIndex = part ? part->getIdxFacility() : 0; 

        repayments[numRepayments][0] = amount;
        repayments[numRepayments][1] = facilityIndex;
        
        numRepayments++;
    }
}
