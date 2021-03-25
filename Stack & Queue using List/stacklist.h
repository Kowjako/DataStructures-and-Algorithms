#ifndef STACKLIST_H
#define STACKLIST_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

struct stackNode {
    int item;
    stackNode* nextElement;
};

class StackList
{
    public:
        StackList();
        virtual ~StackList();
        int sizeVar = 0;
        stackNode* head = NULL;

        int pop();
        void push(int element);
        void showStack();
    protected:

    private:
};

#endif // STACKLIST_H
