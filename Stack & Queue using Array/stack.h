#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;
class Stack
{
    public:
        Stack();
        virtual ~Stack();
        int* stackArray = NULL;
        int sizeVar = 0;

        void push(int element);
        int pop();
        void showStack();
    protected:

    private:
};

#endif // STACK_H
