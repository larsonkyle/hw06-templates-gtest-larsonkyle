#ifndef H_listType
#define H_listType

#include <iostream>
#include <fstream>

template <class T>
class listType
{
public:
    bool isEmptyList() const;
    bool isFullList() const;
    void setLength(int len);
    int showLength() const;
    void search(T searchItem) const;
    void insert(T newElement);
    void deleteItem(T deleteElement);
    void sort();
    void print() const;
    void getList(std::ifstream& infile);
    void destroyList();
    void printList() const;
    listType(int listSize);
    listType();
    ~listType();

protected:
    void binarySearch(T searchItem, int& found, int& index) const;

    int maxSize;
    int length;
    T* elements;
};

template <class T>
listType<T>::listType(int listSize)
{
    maxSize = listSize;
    length = 0;
    elements = new T[maxSize];
}

template <class T>
listType<T>::listType()
{
    maxSize = 50;
    length = 0;
    elements = new T[50];
}

template <class T>
listType<T>::~listType()
{
    delete[] elements;
}

template <class T>
bool listType<T>::isEmptyList() const
{
    return (length == 0);
}

template <class T>
bool listType<T>::isFullList() const
{
    return (length == maxSize);
}

template <class T>
void listType<T>::sort()
{
    int i, j;
    int min;
    T temp;

    for (i = 0; i < length; i++)
    {
        min = i;
        for (j = i + 1; j < length; ++j)
            if (elements[j] < elements[min])
                min = j;

        temp = elements[i];
        elements[i] = elements[min];
        elements[min] = temp;
    }
}

template <class T>
void listType<T>::print() const
{
    int i;

    for (i = 0; i < length; i++)
        std::cout << elements[i] << std::endl;
    std::cout << std::endl;
}

template <class T>
void listType<T>::getList(std::ifstream& infile)
{
    int i;

    for (i = 0; i < length; i++)
        infile >> elements[i];
}

template <class T>
void listType<T>::search(T searchItem) const
{
    int found;
    int index;

    binarySearch(searchItem, found, index);

    if (found)
        std::cout << "Item is in the list" << std::endl;
    else
        std::cout << "Item is not in the list" << std::endl;
}

template <class T>
void listType<T>::binarySearch(T searchItem, int& found, int& index) const
{
    int first = 0;
    int last = length - 1;
    int mid;

    found = 0;

    while (!found && (first <= last))
    {
        mid = (first + last) / 2;

        if (elements[mid] == searchItem)
            found = 1;
        else if (elements[mid] > searchItem)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        index = mid;
    else
        index = -1; // Not found
}

template <class T>
void listType<T>::setLength(int len)
{
    length = len;
}

template <class T>
int listType<T>::showLength() const
{
    return length;
}

template <class T>
void listType<T>::insert(T newElement)
{
    if (!isFullList())
    {
        elements[length] = newElement;
        length++;
    }
}

template <class T>
void listType<T>::deleteItem(T deleteElement)
{
    if (!isEmptyList())
    {
        int index = -1;
        binarySearch(deleteElement, index, index);

        if (index != -1)
        {
            for (int i = index; i < length - 1; i++)
                elements[i] = elements[i + 1];

            length--;
        }
    }
    else
    {
        std::cout << "Cannot delete from the empty list" << std::endl;
    }
}

template <class T>
void listType<T>::destroyList()
{
    length = 0;
}

template <class T>
void listType<T>::printList() const
{
    print();
}

#endif

