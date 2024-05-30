//
// Created by Julien on 29/05/2024.
//

#ifndef PROJET_PORTFOLIO_H
#define PROJET_PORTFOLIO_H


class Portfolio {
private:
    double repayment;
    double interest;
public:
    Portfolio();
    void addInterest(double amount);
    void addRepayment(double amount);
    double getRepayment();
    double getInterest();
};


#endif //PROJET_PORTFOLIO_H
