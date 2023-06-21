/*
assign
declare
define
property or attribute   name age
method                  display
object                  ct
data type               int float
no-arg method
parameterized method
 */
#include <stdio.h>
class contract
{
private:
    int money;     // amount in the contract
    float itrRate; // interest rate in the contract

public:
    static int numCT; // num of contract

    contract()
    { // no-arg constructor
    }
    contract(int money, float itrRate)
    { // parameterized constructor
        this->money = money;
        this->itrRate = itrRate;
    }

    void setMoney(int money)
    {
        this->money = money;
    }
    int getMoney()
    {
        return money;
    }

    void setItrRate(float itrRate)
    {
        this->itrRate = itrRate;
    }
    float getItrRate()
    {
        return itrRate;
    }

    void getInf()
    {
        int m;      // money
        float itrR; // interest rate

        printf("\nAmount In This Contract: ");
        scanf("%d", &m);
        printf("Interest Rate In This Contract: ");
        scanf("%f", &itrR);

        setMoney(m);
        setItrRate(itrR);
    }

    void display()
    {
        printf("\t\t%d\t\t%.2f\n", getMoney(), getItrRate());
    }
};