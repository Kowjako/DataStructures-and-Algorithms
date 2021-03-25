#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <fstream>

using namespace std;

class DynamicArray
{
    public:
        DynamicArray(int sizeVar);
        DynamicArray();
        virtual ~DynamicArray();

        int sizeVar = 0; /* rozmiar tablicy */
        int* dynamicArrayptr = NULL; /* wskaznik na dynamiczna tablice */

        void readFromFile(string filename);
        void fillDynamicArray(int val);
        void showDynamicArray();
        void addToPosition(int position, int item);
        void addToEnd(int item);
        void addToStart(int item);
        void removeFromPosition(int position);
        void removeFromEnd();
        void removeFromStart();
        bool findElement(int element);

    protected:

    private:
};

#endif // DYNAMICARRAY_H
