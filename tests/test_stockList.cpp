#include "lib/gtest-1.7.0/include/gtest/gtest.h"
#include <iostream>
#include "../src/stockList.h"
using namespace std;

class stockListTypeTest : public ::testing::Test{
    protected:
        void SetUp() override
        {
            lst1 = new stockListType;

        }

        void TearDown() override
        {
            delete lst1;
            lst1 = nullptr;
            delete lst2;
            lst2 = nullptr;
        }
        stockListType* lst1 = nullptr;
        stockListType* lst2 = nullptr;
};

TEST_F(stockListTypeTest, constructorTest){
    int val = 0;
    lst1->setLength(0);
    EXPECT_EQ(lst1->showLength(), val) << "constructor test failed.\n";
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
