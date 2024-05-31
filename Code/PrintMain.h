#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include "Agent.h"
#include "Borrower.h"
#include "Lender.h"
#include "Deal.h"
#include "Portfolio.h"

void printFacilityTable(Deal* deal);
void printDealDetails(Deal* deal);
void printLenderPortfolio(Lender* lender);
void printLenderPortfolios(Lender* lenders[], int size);
void printRepaymentTable(float repayments[][2], int numRepayments);
void getUserRepaymentInput(float repayments[][2], int &numRepayments, Borrower* borrower, Deal* deal, Agent* agent);
#endif // PRINT_UTILS_H
