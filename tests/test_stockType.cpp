#include "lib/gtest-1.7.0/include/gtest/gtest.h"
#include <iostream>
#include "stock.h"
using namespace std;

class stockTypeTest : public ::testing::Test{
    protected:
        void SetUp() override
        {
            stck1 = new stockType;
            stck2 = new stockType("CBA", 67.50, 75.50, 78.75, 67.50, 65.75, 378233);
            stck3 = new stockType("MSMT", 112.50, 115.75, 116.50, 11.75, 113.50, 6723823);
        }

        void TearDown() override
        {
            delete stck1;
            stck1 = nullptr;
            delete stck2;
            stck2 = nullptr;
            delete stck3;
            stck3 = nullptr;
        }
        stockType *stck1 = nullptr;
        stockType *stck2 = nullptr;
        stockType *stck3 = nullptr;
};

TEST_F(stockTypeTest, constructorTest){
    string valSym = "CBA";
    double valOP = 67.50;
    double valCL = 75.50;
    double valtH = 78.75;
    double valtL = 67.50;
    double valPC = 65.75;
    double valVol = 378233;

    EXPECT_EQ(stck2->getStockSymbol(), valSym) << "getStockSymbol failed.\n";
    EXPECT_EQ(stck2->getOpeningPrice(), valOP) << "getOpeningPrice failed.\n";
    EXPECT_EQ(stck2->getClosingPrice(), valCL) << "getClosingPrice failed.\n";
    EXPECT_EQ(stck2->getTodayHigh(), valtH) << "getTodayHigh failed.\n";
    EXPECT_EQ(stck2->getTodayLow(), valtL) << "getTodayLow failed.\n";
    EXPECT_EQ(stck2->getPreviousClose(), valPC) << "getPreviousClose failed.\n";
    EXPECT_EQ(stck2->getVolume(), valVol) << "getVolume failed.\n";
}

TEST_F(stockTypeTest, setVariableTest){//"CSCO" 100.00 102.00 105.00 98.00 101.00 0.99 25000
    string valSym = "CSCO";
    double valOP = 100.00;
    double valCL = 102.00;
    double valtH = 105.00;
    double valtL = 98.00;
    double valPC = 101.00;
    double valVol = 25000;

    stck1->setStockSymbol("CSCO");
    stck1->setOpeningPrice(100.00);
    stck1->setClosingPrice(102.00);
    stck1->setTodayHigh(105.00);
    stck1->setTodayLow(98.00);
    stck1->setPreviousClose(101.00);
    stck1->setVolume(25000);

    EXPECT_EQ(stck1->getStockSymbol(), valSym) << "setStockSymbol failed.\n";
    EXPECT_EQ(stck1->getOpeningPrice(), valOP) << "setOpeningPrice failed.\n";
    EXPECT_EQ(stck1->getClosingPrice(), valCL) << "setClosingPrice failed.\n";
    EXPECT_EQ(stck1->getTodayHigh(), valtH) << "setTodayHigh failed.\n";
    EXPECT_EQ(stck1->getTodayLow(), valtL) << "setTodayLow failed.\n";
    EXPECT_EQ(stck1->getPreviousClose(), valPC) << "setPreviousClose failed.\n";
    EXPECT_EQ(stck1->getVolume(), valVol) << "setVolume failed.\n";
}

TEST_F(stockTypeTest, calculatePercentGainLossTest){// previousClose / closingPrice | 6 / 3
    double val = 115.75 / 113.50;
    EXPECT_EQ(stck3->calculatePercentGainLoss(), val) << "calculatePercentGainLossTest failed\n";
}

TEST_F(stockTypeTest, operator>Test){
    bool val = false;
    EXPECT_EQ((*stck2) > (*stck3), val) << "operator > test failed.\n";
}

TEST_F(stockTypeTest, operator<Test){
    bool val = true;
    EXPECT_EQ((*stck2) < (*stck3), val) << "operator > test failed.\n";
}

TEST_F(stockTypeTest, operator==Test){
    bool val = true;
    EXPECT_EQ((*stck2) == (*stck2), val) << "operator > test failed.\n";
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}