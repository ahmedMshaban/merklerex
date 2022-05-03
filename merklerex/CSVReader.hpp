//
//  CSVReader.hpp
//  merklerex
//
//  Created by Ahmed Shaban on 20.04.2022.
//

#ifndef CSVReader_hpp
#define CSVReader_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "OrderBookEntry.hpp"

class CSVReader {
public:
    CSVReader();
    /** parse the sent CSV file into multiple
     * OrderBookEntry objects which should contain
     * lines like:
     * 2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187305,6.85567013
     */
    static std::vector<OrderBookEntry> readCSV(std::string csvFile);
private:
    static std::vector<std::string> tokenise(std::string csvLine, char separator);
    static OrderBookEntry stringsToOBE(std::vector<std::string> strings);
};
#endif /* CSVReader_hpp */
