//
//  Wallet.cpp
//  merklerex
//
//  Created by Ahmed Shaban on 25.05.2022.
//

#include "Wallet.hpp"


Wallet::Wallet() {
    
}

void Wallet::insertCurrency(std::string type, double amount) {
    double balance;
    if(amount < 0) {
        balance = 0;
        throw std::<#expression#>{};
    }
    
    else if (currencies.count(type) == 0) // not there yet
        balance = 0;
    
    else // is there
        balance = currencies[type];
    
    balance += amount;
    
}

bool Wallet::removeCurrency(std::string type, double amount) {
    if(amount < 0 || currencies.count(type) == 0) {
        return false;
    }
    
    else {// is there - do we have enough
        if(containsCurrency(<#std::string type#>, <#double amount#>)) {
            currencies[type] -= amount;
            return true;
        }
        // they have it but not enough
        return false;
    }
}

bool Wallet::containsCurrency(std::string type, double amount) {
    if (currencies.count(type) == 0)
        return 0;
    else
        return currencies[type] >= amount;
}

std::string Wallet::toString() {
    std::string s;
    for (std::pair<std::string,double> pair : currencies)
    {
        std::string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + std::to_string(amount) + "\n";
    }
    return s;
}
