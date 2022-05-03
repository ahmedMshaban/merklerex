//
//  CSVReader.cpp
//  merklerex
//
//  Created by Ahmed Shaban on 20.04.2022.
//

#include "CSVReader.hpp"
#include <iostream>
#include <fstream>

CSVReader::CSVReader() {
    
}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename) {
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile{csvFilename};
    std::string line;
    
    if(csvFile.is_open()) {
        std::cout << "Opened file " << csvFilename << std::endl;
        
        while(std::getline(csvFile, line)) {
            try {
                OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
                entries.push_back(obe);
            } catch(const std::exception& e) {
                std::cout << "CSVReader::readCSV bad data " << std::endl;
            }
        }
    } else {
        std::cout << "Problem opening file " << csvFilename << std::endl;
    }
    
    csvFile.close();
    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator) {
    std::vector<std::string> tokens;
    signed int start, end;
    start = csvLine.find_first_not_of(separator, 0);
    std::string token;
    
    do {
        end = csvLine.find_first_of(separator, start);
        
        if(start == csvLine.length() || start == end) break;
        
        else if(end >= 0){
            token = csvLine.substr(start, end - start);
        }
        
        else {
            token = csvLine.substr(start, csvLine.length() - start);
        }
        
        tokens.push_back(token);
        start = end + 1;
        
    } while(end > 0);
    
    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens) {
    double price,amount;
    
    if(tokens.size() != 5) {
        std::cout << "Bad line " << std::endl;
        throw std::exception{};
    }
    
    try {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    } catch(const std::exception& e) {
        std::cout << "Bad float! " << tokens[3] << std::endl;
        std::cout << "Bad float! " << tokens[4] << std::endl;
        throw;
    }
    
    OrderBookEntry obe{price, amount, tokens[0], tokens[1], OrderBookEntry::stringToOrderBookType(tokens[2])};
    return obe;
}
