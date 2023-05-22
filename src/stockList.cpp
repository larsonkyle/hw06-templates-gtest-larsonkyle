#include "stockList.h"

stockListType::stockListType(const stockListType &right){
    this->maxSize = right.maxSize;
    this->length = right.length;

    for(int i = 0; i < right.length; i++){
        this->elements[i] = right.elements[i];
    }

    sortIndices(sortedByGainLoss, elements, length);
}

void stockListType::sortIndices(int* indices, const stockType* arr, int size) {
    // Initialize the indices array with the original indices
    for (int i = 0; i < size; ++i) {
        indices[i] = i;
    }

    // Perform selection sort to sort the indices array based on the values in the arr
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[indices[j]].calculatePercentGainLoss() < arr[indices[minIndex]].calculatePercentGainLoss()) {
                minIndex = j;
            }
        }
        // Swap the indices
        int temp = indices[i];
        indices[i] = indices[minIndex];
        indices[minIndex] = temp;
    }
}

void stockListType::printListByGainLoss() const{
    sortIndices(sortedByGainLoss, elements, length);
    for (int i = 0; i < length; i++) {
        int index = hashTableGainLossArray[i];
        elements[index].printStockInfo(); // Print the stock information based on the sorted indices
    }
}

void stockListType::sortByGainLoss(){
    sortIndices(sortedByGainLoss, elements, length);
}

stockListType stockListType::operator=(const stockListType &right){
    this->maxSize = right.maxSize;
    this->length = right.length;

    for(int i = 0; i < right.length; i++){
        this->elements[i] = right.elements[i];
    }

    sortIndices(sortedByGainLoss, elements, length);

    return *this;
}