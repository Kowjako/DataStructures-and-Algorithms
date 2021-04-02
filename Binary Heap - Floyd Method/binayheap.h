#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

class BinaryHeap
{
    public:
        BinaryHeap();
        virtual ~BinaryHeap();

        int sizeVar = 0;
        int* heap;

        void readFromFile(string filename);
        void showBinaryHeap();
        void addItem(int item);
        void deleteVertex();
        void normalize(int index);
        void initializate(int sizeValue);
        void findElement(int item);
        void floydMethod();
        void changePosition(int* data, int a, int b);
        void startValues(int data[]);
        void initializateWithArray(int arr[], int sizeval);
    protected:

    private:
        void addToNormalizedPosition(int element);
};

#endif // BINARYHEAP_H
