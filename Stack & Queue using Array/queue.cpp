#include "queue.h"

Queue::Queue()
{
    //ctor
}

Queue::~Queue()
{
    //dtor
}
void Queue::push(int element) {
    int* tmpArray = (int*)calloc(sizeVar+1,sizeof(int));
    sizeVar++;
    for(int i=sizeVar-1;i>0;i--) {
        tmpArray[i] = queueArray[i-1];
    }
    tmpArray[0] = element;
    if(queueArray!=NULL) free(queueArray);
    queueArray = tmpArray;
    frontValue = &queueArray[sizeVar-1];
    backValue = &queueArray[0];
}

int Queue::pop() {
    if(sizeVar==0) {
        cout<<"Rozmiar pusty"<<endl;
        return 0;
    }
    int* tmpArray = (int*)calloc(sizeVar-1,sizeof(int));
    sizeVar--;
    for(int i=sizeVar-1;i>=0;i--) {
        tmpArray[i] = queueArray[i];
    }
    int tmpFront = *frontValue;
    if(queueArray!=NULL) free(queueArray);
    queueArray = tmpArray;
    frontValue = &queueArray[sizeVar-1];
    backValue = &queueArray[0];
    return tmpFront;
}

void Queue::showQueue() {
    for(int i=0;i<sizeVar;i++) {
        cout<<queueArray[i]<<"\t";
    }
    cout<<endl;
}
int Queue::frontElement() {
    return *frontValue;
}

int Queue::backElement() {
    return *backValue;
}
