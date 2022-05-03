//
//  MerkelMain.cpp
//  merklerex
//
//  Created by Ahmed Shaban on 12.04.2022.
//

#include "MerkelMain.hpp"
#include "CSVReader.hpp"

MerkelMain::MerkelMain() {
    
}

void MerkelMain::init() {
    int input;
    while(true) {
        printMenu();
        input  = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu() {
    std::cout << "1: Print help " << std::endl;
    std::cout << "2: Print exchange stats " << std::endl;
    //An offer is someone offering to sell.
    std::cout << "3: Make an offer " << std::endl;
    // A bid is someone offering to buy.
    std::cout << "4: Make a bid " << std::endl;
    std::cout << "5: Print wallet " << std::endl;
    std::cout << "6: Continue " << std::endl;
    
    std::cout << "=============" << std::endl;
}

int MerkelMain::getUserOption() {
    int userOption;
    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    
    return userOption;
}

void MerkelMain::printHelp() {
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void MerkelMain::printMarketStats() {
    for (std::string const& p : orderBook.getKnownProducts()) {
        std::cout << "Product: " << p << std::endl;
    }

//    std::cout << "OrderBook contains " << orders.size() << " entries" << std::endl;
//    unsigned int bids = 0;
//    unsigned int asks = 0;
//
//    for(OrderBookEntry& e : orders) {
//        if(e.orderType == OrderBookType::ask) {
//            asks++;
//        } else if(e.orderType == OrderBookType::bid) {
//            bids++;
//        }
//    }
//
//    std::cout << "Orderbook asks: " << asks << " bids: " << bids << std::endl;
}

void MerkelMain::enterAsk() {
    std::cout << "Make an offer - enter the amount. " << std::endl;
}

void MerkelMain::enterBid() {
    std::cout << "Make a bid - enter the amount. " << std::endl;
}

void MerkelMain::printWallet() {
    std::cout << "Your wallet is empty. " << std::endl;
}

void MerkelMain::gotoNextTimeframe() {
    std::cout << "Going to the next time frame. " << std::endl;
}

void MerkelMain::processUserOption(int userOption) {
    if(userOption == 0) { //bad input
        std::cout << "Invalid choice. Choose 1-6" <<std::endl;
    }
    
    else if(userOption == 1) {
        printHelp();
    }
    
    else if(userOption == 2) {
        printMarketStats();
    }
    
    else if(userOption == 3) {
        enterAsk();
    }
    
    else if(userOption == 4) {
        enterBid();
    }
    
    else if(userOption == 5) {
        printWallet();
    }
    
    else if(userOption == 6) {
        gotoNextTimeframe();
    }
}
