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
    currentTime = orderBook.getEarliestTime();
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
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-6" << std::endl;
    std::getline(std::cin, line);
    try {
        userOption = std::stoi(line);
    } catch(const std::exception& e)
    {
        
    }
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::printHelp() {
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void MerkelMain::printMarketStats() {
    for (const std::string& p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
}

void MerkelMain::enterAsk() {
    std::cout << "Make an ask - enter the amount: product,price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if(tokens.size() != 3) {
        std::cout << "MerkelMain::enterAsk Bad input! " << input << std::endl;
    } else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1],
                                                         tokens[2],
                                                         currentTime,
                                                         tokens[0],
                                                         OrderBookType::ask
                                                         );
            orderBook.insertOrder(obe);
        } catch (const std::exception& e) {
            std::cout << "MerkelMain::enterAsk Bad input! " << std::endl;
        }
    }
}

void MerkelMain::enterBid() {
    std::cout << "Make an bid - enter the amount: product,price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if(tokens.size() != 3) {
        std::cout << "MerkelMain::enterBid Bad input! " << input << std::endl;
    } else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1],
                                                         tokens[2],
                                                         currentTime,
                                                         tokens[0],
                                                         OrderBookType::bid
                                                         );
            orderBook.insertOrder(obe);
        } catch (const std::exception& e) {
            std::cout << "MerkelMain::enterBid Bad input! " << std::endl;
        }
    }
}

void MerkelMain::printWallet() {
    std::cout << "Your wallet is empty. " << std::endl;
}

void MerkelMain::gotoNextTimeframe() {
    std::cout << "Going to the next time frame. " << std::endl;
    currentTime = orderBook.getNextTime(currentTime);
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
