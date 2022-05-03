//
//  OrderBook.cpp
//  merklerex
//
//  Created by Ahmed Shaban on 3.05.2022.
//

#include "OrderBook.hpp"
#include <map>

/** construct, reading a csv data file */
OrderBook::OrderBook(std::string filename) {
    orders = CSVReader::readCSV(filename);
}
/** return vector of all know products in the dataset*/
std::vector<std::string> OrderBook::getKnownProducts() {
    std::vector<std::string> products;
    std::map<std::string,bool> prodMap;
    
    for (const OrderBookEntry& e : orders)
    {
        prodMap[e.product] = true;
    }
    
    for (const auto& e : prodMap)
    {
        products.push_back(e.first);
    }
    
    return products;
}
/** return vector of Orders according to the sent filters*/
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                                 std::string product,
                                                 std::string timestamp) {
    std::vector<OrderBookEntry> order_sup;
    return order_sup;
}


