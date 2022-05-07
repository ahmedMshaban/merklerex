//
//  OrderBook.hpp
//  merklerex
//
//  Created by Ahmed Shaban on 3.05.2022.
//

#ifndef OrderBook_hpp
#define OrderBook_hpp

#include <stdio.h>
#include "OrderBookEntry.hpp"
#include "CSVReader.hpp"

class OrderBook
{
public:
    /** construct, reading a csv data file */
    OrderBook(std::string filename);
    /** return vector of all know products in the dataset*/
    std::vector<std::string> getKnownProducts();
    /** return vector of Orders according to the sent filters*/
    std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                          std::string product,
                                          std::string timestamp);
    /** return the price of the highest bid in the sent set */
    static double getHighPrice(std::vector<OrderBookEntry>& orders);
    /** return the price of the lowest bid in the sent set */
    static double getLowPrice(std::vector<OrderBookEntry>& orders);
    /** returns the earliest time in the orderbook,*/
    std::string getEarliestTime();
    /** return the next time after the
     * sent time in the orderbook
     */
    std::string getNextTime(const std::string& timestamp);
private:
    std::vector<OrderBookEntry> orders;
};
#endif /* OrderBook_hpp */
