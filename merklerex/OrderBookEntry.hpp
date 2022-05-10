//
//  OrderBookEntry.hpp
//  merklerex
//
//  Created by Mariam Ali on 12.04.2022.
//

#ifndef OrderBookEntry_hpp
#define OrderBookEntry_hpp

#include <stdio.h>
#include <string>

enum class OrderBookType{ask, bid, unknown, sale};

class OrderBookEntry {
public:
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType);
    
    static OrderBookType stringToOrderBookType(std::string s);
    
    static bool compareByTimestamp(const OrderBookEntry& e1, const OrderBookEntry& e2) {
        return e1.timestamp < e2.timestamp;
    }
    
    static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2) {
        return e1.price < e2.price;
    }
    
    static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2) {
        return e1.price > e2.price;
    }
    
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};

#endif /* OrderBookEntry_hpp */
