//
//  main.cpp
//  merklerex
//
//  Created by Ahmed Shaban on 6.04.2022.
//

#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.hpp"
#include "MerkelMain.hpp"
#include "CSVReader.hpp"

int main(int argc, const char * argv[]) {
    MerkelMain app{};
    app.init();
    return 0;
}
