#ifndef H_STOCKLIST
#define H_STOCKLIST
#include "listType.h"
#include "stock.h"
#define AR_CAP 50

class stockListType : public listType<stockType> {
    public:
        void sortByGainLoss();
        void printListByGainLoss();

        stockListType(const stockListType &right); // copy constructor
        stockListType operator=(const stockListType &right); //assignment operator

	stockListType(){}
        stockListType(int listSize) : listType<stockType>(listSize){}
        //no destructor needed, array is statically allocated.
    private:
        void sortIndices(int* indices, const stockType* arr, int size);
        int sortedByGainLoss[AR_CAP];
};


#endif
