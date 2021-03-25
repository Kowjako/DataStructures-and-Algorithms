#ifndef QUEUELIST_H
#define QUEUELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

struct queueNode {
    int item;
    queueNode* nextElement;
};

class QueueList
{
    public:
        QueueList();
        virtual ~QueueList();
        int sizeVar = 0;
        queueNode* head = NULL;

        void push(int element);
        int pop();
        void showQueue();
        int getFirst() { return head->item; }
        int getLast();
    protected:

    private:
};

#endif // QUEUELIST_H
