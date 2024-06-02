#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include "Agent.h"
#include "Borrower.h"
#include "Lender.h"
#include "Deal.h"
#include "Portfolio.h"

double printFacilityTable(Deal* deal);
void printDealDetails(Deal* deal);
void printLenderPortfolios(Agent *a,Lender* lenders[], int size);
void printRepaymentTable(float repayments[][2], int numRepayments);
bool isValidNumber(const std::string& str, double& number);
void getUserRepaymentInput(float repayments[][2], int &numRepayments, Borrower* borrower, Deal* deal, Agent* agent, double SumNeededToBeRepaid);
#endif // PRINT_UTILS_H
