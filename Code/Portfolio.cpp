//
// Created by Julien on 29/05/2024.
//

#include "Portfolio.h"

Portfolio::Portfolio() {
    interest = 0.0 ;
    repayment = 0.0;
}

void Portfolio::addInterest(double amount) {
    interest += amount;
}

void Portfolio::addRepayment(double amount){
      repayment += amount;
}

double Portfolio::getRepayment(){
    return repayment;
}
double Portfolio::getInterest(){   
    return interest; 
}
