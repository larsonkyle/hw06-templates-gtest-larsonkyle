#ifndef STOCK_H_
#define STOCK_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

class stockType {
public:
    void setStockInfo(std::string symbol, double opPrice, double clPrice, double tHigh, double tLow, double prevClose, double vol);
    void setStockSymbol(std::string symbol);
    void setOpeningPrice(double opPrice);
    void setClosingPrice(double clPrice);
    void setTodayHigh(double tHigh);
    void setTodayLow(double tLow);
    void setPreviousClose(double prevClose);
    void setVolume(double vol);

    std::string getStockSymbol() const;
    double getOpeningPrice() const;
    double getClosingPrice() const;
    double getTodayHigh() const;
    double getTodayLow() const;
    double getPreviousClose() const;
    double getVolume() const;

    void printStockInfo() const;
    void printStockPrices() const;
    void printNumberOfShares() const;

    double calculatePercentGainLoss() const; // previousClose / closingPrice

    stockType();
    stockType(std::string symbol, double opPrice, double clPrice, double tHigh, double tLow, double prevClose, double vol);

    // relational operators (for alphabetizing)
    bool operator< (const stockType &right) const;
    bool operator> (const stockType &right) const;
    bool operator== (const stockType &right) const;

    // stream operators (one for file input, one for 'cout' output)
    friend std::ifstream & operator >> (std::ifstream &in, stockType &right);
    friend std::ostream & operator << (std::ostream &out, const stockType &right);

private:
    std::string stockSymbol;
    double openingPrice;
    double closingPrice;
    double todayHigh;
    double todayLow;
    double previousClose;
    double volume;
};

std::ifstream & operator >> (std::ifstream &in, stockType &right);
std::ostream & operator << (std::ostream &out, const stockType &right);

#endif