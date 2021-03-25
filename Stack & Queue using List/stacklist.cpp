#include "stacklist.h"

StackList::StackList()
{
    //ctor
}

StackList::~StackList()
{
    //dtor
}

void StackList::push(int element) {
    if(head == NULL) {
        stackNode* newNode = (stackNode*)malloc(sizeof(stackNode*));
        newNode->item = element;
        newNode->nextElement = NULL;
        head = newNode;
        sizeVar++;
    }
    else
    {
        stackNode* newNode = (stackNode*)malloc(sizeof(stackNode*));
        newNode->item = element;
        newNode->nextElement = head;
        head = newNode;
        sizeVar++;
    }
}

int StackList::pop() {
    if(sizeVar == 0) {
        cout<<"Nie ma zadnych elementow "<<endl;
        return 0;
    }
    else
    {
        int headValue = head->item;
        stackNode* newHead = head->nextElement;
        free(head);
        head = newHead;
        sizeVar--;
        return headValue;
    }
}

void StackList::showStack() {
    stackNode* tmpNode = head;
    for(int i=0;i<sizeVar;i++) {
        cout<<tmpNode->item<<"\t";
        tmpNode = tmpNode->nextElement;
    }
    cout<<endl;
}
