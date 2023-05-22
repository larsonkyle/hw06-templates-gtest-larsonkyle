#include "lib/gtest-1.7.0/include/gtest/gtest.h"
#include <iostream>
#include "listType.h"

class listTypeTest : public ::testing::Test{
    protected:

        void SetUp() override
        {
            lst1 = new listType<int>;
            lst2 = new listType<int>;
            lst3 = new listType<int>;

            lst2->insert(1);
            lst2->insert(2);
            lst3->insert(3);
        }

        void TearDown() override
        {
            delete lst1;
            lst1 = nullptr;
            delete lst2;
            lst2 = nullptr;
            delete lst3;
            lst3 = nullptr;
        }
        listType<int>* lst1 = nullptr;
        listType<int>* lst2 = nullptr;
        listType<int>* lst3 = nullptr;
};

TEST_F(listTypeTest, isEmptyTest){
    bool val = true;
    EXPECT_EQ(lst1->isEmptyList(), val); << "isEmptyList did not result into the correct solution";
}

TEST_F(listTypeTest, isFullListTest){
    bool val = true;
    EXPECT_EQ(lst2->isFullList(), val) << "isFullList did not result into the correct solution";
}

TEST_F(listTypeTest, setLengthTest){
    int val = 5;
    lst1->setLength(5);
    EXPECT_EQ(lst1->showLength, val) << "setLength() did not result in the correct solution";
}

TEST_F(listTypeTest, insertTest){
    bool v1 = true;
    int v2 = 3;
    lst2->insert(4);
    bool fnd;
    int index;

    lst2->search(4, fnd, index);

    EXPECT_EQ(fnd, v1) << "insert() 1 failed";
    EXPECT_EQ(fnd, v2) << "insert() 2 failed";
}

TEST_F(listTypeTest, searchTest){
    bool v1 = true;
    bool v2 = false;
    bool fnd1;
    bool fnd2;
    int index1;
    int index2;

    lst2->search(2, fnd1, index1);
    lst2->search(8, fnd2, index2);

    EXPECT_EQ(fnd1, v1) << "search() 1 failed";
    EXPECT_EQ(fnd2, v2) << "search() 2 failed";
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}