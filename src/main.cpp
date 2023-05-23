#include <iostream>
#include "stock.h"
#include "listType.h"
#include "stockList.h"

int main() {
  // Create a stock object and test its functionality
  Stock stock1("AAPL", 100.0);
  Stock stock2("GOOGL", 200.0);
  std::cout << "Stock 1: " << stock1 << std::endl;
  std::cout << "Stock 2: " << stock2 << std::endl;
  std::cout << "Stock 1 value: $" << stock1.getValue() << std::endl;

  // Create a listType object and test its functionality
  ListType<int> intList;
  intList.insert(10);
  intList.insert(20);
  intList.insert(30);
  std::cout << "Integer list: ";
  intList.print();
  std::cout << "List size: " << intList.getSize() << std::endl;

  // Create a stockList object and test its functionality
  StockList stockList;
  stockList.addStock(stock1);
  stockList.addStock(stock2);
  std::cout << "Stock List:" << std::endl;
  stockList.print();

  return 0;
}
