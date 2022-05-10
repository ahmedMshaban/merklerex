//
//  OrderBook.cpp
//  merklerex
//
//  Created by Ahmed Shaban on 3.05.2022.
//

#include "OrderBook.hpp"
#include <map>
#include <algorithm>

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
    
    for(OrderBookEntry& e: orders) {
        if(e.orderType == type
           && e.product == product
           && e.timestamp == timestamp) {
            order_sup.push_back(e);
        }
    }
    return order_sup;
}


double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders) {
    double max = orders[0].price;
    for(OrderBookEntry& e: orders) {
        if(e.price > max) max = e.price;
    }
    
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders) {
    double min = orders[0].price;
    for(OrderBookEntry& e: orders) {
        if(e.price < min) min = e.price;
    }
    
    return min;
}

std::string OrderBook::getEarliestTime() {
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(const std::string& timestamp) {
    std::string next_timestamp = "";
    for (OrderBookEntry& e : orders)
    {
        if (e.timestamp > timestamp)
        {
            next_timestamp = e.timestamp;
            break;
        }
    }
    if (next_timestamp == "")
    {
        next_timestamp = orders[0].timestamp;
    }
    return next_timestamp;
}

void OrderBook::insertOrder(OrderBookEntry& order)
{
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}
