#include "lib/gtest-1.7.0/include/gtest/gtest.h"
#include <iostream>
#include "stockListType.h"
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
            lest2 = nullptr;
        }
        stockListType* lst1 = nullptr;
        stockListType* lst2 = nullptr;
};

TEST_F(stockListTypeTest, constructorTest){
    int val = 5;
    lst1 = new stockListType(5);

    EXPECT_EQ(lst1->showLength(), val) << "constructor test failed.\n";
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}