//
//  OrderBook.cpp
//  merklerex
//
//  Created by Ahmed Shaban on 3.05.2022.
//

#include "OrderBook.hpp"
#include "CSVReader.hpp"

/** construct, reading a csv data file */
OrderBook::OrderBook(std::string filename) {
    orders = CSVReader::readCSV(filename);
}
/** return vector of all know products in the dataset*/
std::vector<std::string> OrderBook::getKnownProducts() {
    std::vector<std::string> products;
    return products;
}
/** return vector of Orders according to the sent filters*/
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                                 std::string product,
                                                 std::string timestamp) {
    std::vector<OrderBookEntry> order_sup;
    return order_sup;
}


