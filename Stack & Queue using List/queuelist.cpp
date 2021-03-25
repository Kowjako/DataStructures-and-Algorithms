#include "queuelist.h"

QueueList::QueueList()
{
    //ctor
}

QueueList::~QueueList()
{
    //dtor
}
void QueueList::push(int element) {
    if(head == NULL) {
        queueNode* newElement = (queueNode*)malloc(sizeof(queueNode));
        newElement->item = element;
        newElement->nextElement = NULL;
        head = newElement;
        sizeVar++;
    }
    else
    {
        queueNode* tmpNode = head;
        queueNode* newElement = (queueNode*)malloc(sizeof(queueNode));
        newElement->item = element;
        newElement->nextElement = NULL;
        for(int i=0;i<sizeVar-1;i++) {
            tmpNode = tmpNode->nextElement;
        }
        tmpNode->nextElement = newElement;
        sizeVar++;
    }

}

int QueueList::pop() {
    if(sizeVar==0) {
        cout<<"Nie ma zadnych elementow"<<endl;
        return 0;
    }
    int headValue = head->item;
    queueNode* newHead = head->nextElement;
    free(head);
    head = newHead;
    sizeVar--;
    return headValue;
}

void QueueList::showQueue() {
    queueNode* tmpNode = head;
    for(int i=0;i<sizeVar;i++) {
        cout<<tmpNode->item<<"\t";
        tmpNode = tmpNode->nextElement;
    }
    cout<<endl;
}

int QueueList::getLast() {
    queueNode* lastElement = head;
    for(int i=0;i<sizeVar - 1;i++) {
        lastElement = lastElement->nextElement;
    }
    return lastElement->item;
}
