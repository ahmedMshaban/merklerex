//
//  MerkelMain.hpp
//  merklerex
//
//  Created by Ahmed Shaban on 12.04.2022.
//

#ifndef MerkelMain_hpp
#define MerkelMain_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "OrderBookEntry.hpp"
#include "OrderBook.hpp"


class MerkelMain {
public:
    MerkelMain();
    /** Call this to start the sim*/
    void init();
private:
    void printMenu();
    int getUserOption();
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    void processUserOption(int userOption);
    
    OrderBook orderBook{"20200317.csv"};
    std::string currentTime;
};

#endif /* MerkelMain_hpp */
