#include "stack.h"

Stack::Stack()
{
    //ctor
}

Stack::~Stack()
{
    //dtor
}

void Stack::push(int element) {
    int* tmpStack = (int*)calloc(sizeVar+1,sizeof(int));
    sizeVar++;
    for(int i=0;i<sizeVar-1;i++) {
        tmpStack[i] = stackArray[i];
    }
    tmpStack[sizeVar-1] = element;
    if(stackArray!=NULL) free(stackArray);
    stackArray = tmpStack;
}

void Stack::showStack() {
    for(int i=0;i<sizeVar;i++) {
        cout<<stackArray[i]<<"\t";
    }
    cout<<endl;
}

int Stack::pop() {
    int* tmpStack = (int*)calloc(sizeVar-1,sizeof(int));
    sizeVar--;
    for(int i=0;i<sizeVar;i++) {
        tmpStack[i] = stackArray[i];
    }
    int popValue = stackArray[sizeVar];
    if(stackArray!=NULL) free(stackArray);
    stackArray = tmpStack;
    return popValue;
}
