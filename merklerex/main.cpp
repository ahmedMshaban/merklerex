//
//  main.cpp
//  merklerex
//
//  Created by Ahmed Shaban on 6.04.2022.
//

#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.hpp"
#include "MerkelMain.hpp"
#include "CSVReader.hpp"
#include "Wallet.hpp"

int main(int argc, const char * argv[]) {
//    MerkelMain app{};
//    app.init();
    Wallet wallet;
    wallet.insertCurrency("BTC", 1.5);
    std::cout << "Wallet should contain 1.5 BTC now" << std::endl;
    return 0;
}
