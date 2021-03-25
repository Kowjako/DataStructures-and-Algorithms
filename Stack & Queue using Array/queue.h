#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

class Queue
{
    public:
        Queue();
        virtual ~Queue();

        int* queueArray = NULL;
        int* frontValue;
        int* backValue;
        int sizeVar = 0;

        int pop();
        void push(int element);
        int frontElement();
        int backElement();
        void initialize();
        void showQueue();

    protected:

    private:
};

#endif // QUEUE_H
