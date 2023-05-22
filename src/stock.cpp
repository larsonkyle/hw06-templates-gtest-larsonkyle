#include "stock.h"

//constructors
stockType::stockType(){
    stockSymbol = "";
    openingPrice = 0.0;
    closingPrice = 0.0;
    todayHigh = 0.0; 
    todayLow = 0.0; 
    previousClose = 0.0; 
    volume = 0.0;
}

stockType::stockType(std::string symbol, double opPrice, double clPrice, double tHigh, double tLow, double prevClose, double vol){
        stockSymbol = symbol;
        openingPrice = opPrice;
        closingPrice = clPrice;
        todayHigh = tHigh; 
        todayLow = tLow; 
        previousClose = prevClose; 
        volume = vol;
}

//Setter Methods String
void stockType::setStockInfo(std::string symbol, double opPrice, double clPrice, double tHigh, double tLow, double prevClose, double vol){
        stockSymbol = symbol;
        openingPrice = opPrice;
        closingPrice = clPrice;
        todayHigh = tHigh; 
        todayLow = tLow; 
        previousClose = prevClose; 
        volume = vol;
}

void stockType::setStockSymbol(std::string symbol){
    stockSymbol = symbol;
}

void stockType::setOpeningPrice(double opPrice){
    openingPrice = opPrice;
}

void stockType::setClosingPrice(double clPrice){
    closingPrice = clPrice;
}

void stockType::setTodayHigh(double tHigh){
    todayHigh = tHigh;
}

void stockType::setTodayLow(double tLow){
    todayLow = tLow;
}

void stockType::setPreviousClose(double prevClose){
    previousClose = prevClose;
}

void stockType::setVolume(double vol){
    volume = vol;
}

//Getter Methods
std::string stockType::getStockSymbol() const{
    return stockSymbol;
}

double stockType::getOpeningPrice() const{
    return openingPrice;
}

double stockType::getClosingPrice() const{
    return closingPrice;
}

double stockType::getTodayHigh() const{
    return todayHigh;
}

double stockType::getTodayLow() const{
    return todayLow;
}

double stockType::getPreviousClose() const{
    return previousClose;
}

double stockType::getVolume() const{
    return volume;
}

//Print Methods
void stockType::printStockInfo() const{
    std::cout << setw(6) << this->getStockSymbol();
    std::cout << setw(8) << this->getOpeningPrice();
    std::cout << setw(8) << this->getClosingPrice();
    std::cout << setw(8) << this->getTodayHigh();
    std::cout << setw(8) << this->getTodayLow();
    std::cout << setw(8) << this->getPreviousClose();
    std::cout << setw(8) << this->getVolume();
    std::cout << "\n";
}

void stockType::printStockPrices() const{

}

void stockType::printNumberOfShares() const{

}

// Calculate percentGain/Loss
double stockType::calculatePercentGainLoss() const{
    return previousClose / closingPrice;
}

//Overloaded Relational Operators
bool stockType::operator< (const stockType &right) const {
    if (this->stockSymbol < right.stockSymbol) {
        return true;
    }
    else {
        return false;
    }
}

bool stockType::operator> (const stockType &right) const {
    if (this->stockSymbol > right.stockSymbol) {
        return true;
    }
    else {
        return false;
    }
}

bool stockType::operator== (const stockType &right) const{
    if(this->stockSymbol == right.stockSymbol){
        return true;
    }
    else
        return false;
}

//Overloaded Stream Extraction/Insertion Operators
ifstream & operator >> (ifstream &in, stockType &right){
    std::string symbol;
    double opPrice, clPrice, tHigh, tLow, prevClose, vol;

//if csv file, replace "in >> ..." with "getline(in,...,',')"

    in >> symbol;
    in >> opPrice;
    in >> clPrice;
    in >> tHigh;
    in >> tLow;
    in >> prevClose;
    in >> vol;

    right.setStockSymbol(symbol);
    right.setOpeningPrice(opPrice);
    right.setClosingPrice(clPrice);
    right.setTodayHigh(tHigh);
    right.setTodayLow(tLow);
    right.setPreviousClose(prevClose);
    right.setVolume(vol);

    return in;
}

ostream & operator << (ostream &out, const stockType &right){
    out << setw(6) << right.getStockSymbol();
    out << setw(8) << right.getOpeningPrice();
    out << setw(8) << right.getClosingPrice();
    out << setw(8) << right.getTodayHigh();
    out << setw(8) << right.getTodayLow();
    out << setw(8) << right.getPreviousClose();
    out << setw(8) << right.getVolume();
    // out << "\n";

    return out;
}