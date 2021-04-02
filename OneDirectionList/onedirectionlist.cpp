#include <iostream>

using namespace std;

int sizeVar = 1;

struct elementList {
    int value;
    elementList* nextElement;
};

elementList* head;
elementList* ogon;

elementList* addItem(elementList* prevNode, int item) { /* funkcja do inicjalizacji */
    elementList* newNode = (elementList*)malloc(sizeof(elementList));
    newNode->value = item;
    newNode->nextElement = NULL;
    prevNode->nextElement = newNode;
    sizeVar++;
    return newNode;
}
void deleteItem() { /* usuwa na koncu element */
    elementList* tmpElement = head->nextElement; /* bedzie wskazywal na ostatni element */
    for(int i=0;i<sizeVar-3;i++) { /* -3 bo jeden element powinien zostac na koniec jeden byl wziety jako poczatkowy wyzej */
        tmpElement = tmpElement->nextElement;
    }
    free(tmpElement->nextElement);
    tmpElement->nextElement = NULL;
    ogon = tmpElement;
    sizeVar--;
}
elementList* createStartNode(int item) {
    elementList* newNode = (elementList*)malloc(sizeof(elementList));
    newNode->value = item;
    newNode->nextElement = NULL;
    return newNode;
}

void showList() {
    elementList* tmpNode = head;
    for(int i=0;i<sizeVar;i++) {
        cout<<tmpNode->value<<"\t";
        tmpNode = tmpNode->nextElement;
    }
    cout<<endl;
}

void init() {
    elementList* startNode = createStartNode(rand()%50);
    head = startNode; /*inicjalizacja wezla poczatkowego */
    for(int i=0;i<9;i++) {
        startNode = addItem(startNode, rand()%50);
    }
    ogon = startNode; /*inicjalizacja wezla koncowego */
}

void addToStart(int item) {
    elementList* newNode = (elementList*)malloc(sizeof(elementList));
    newNode->value = item;
    newNode->nextElement = head;
    head = newNode;
    sizeVar++;
}

void addToPosition(int position, int item) {
    elementList* newNode = (elementList*)malloc(sizeof(elementList));
    newNode->value = item;
    elementList* tmpNode = head;
    for(int i=0;i<position - 1;i++) /*element poprzedzajacy usuwany */
    {
        tmpNode = tmpNode->nextElement;
    }
    elementList* nextByPreviosElement = tmpNode->nextElement;
    tmpNode->nextElement = newNode;
    newNode->nextElement = nextByPreviosElement;
    sizeVar++;
}

void addToEnd(int item) {
    elementList* newNode = (elementList*)malloc(sizeof(elementList));
    newNode->value = item;
    newNode->nextElement = NULL;
    ogon->nextElement = newNode;
    ogon = newNode;
    sizeVar++;
}

void removeFromStart() {
    elementList* newHead = head->nextElement;
    free(head);
    head = newHead;
    sizeVar--;
}

void removeFromPosition(int position) {
    elementList* element = head;
    for(int i=0;i<position-1;i++) {
        element = element->nextElement; /* tutaj bedzie element poprzedzajacy usuwany */
    }
    elementList* deletedNode = element->nextElement;
    element->nextElement = deletedNode->nextElement;
    free(deletedNode);
    sizeVar--;
}

void removeFromEnd() {
    elementList* element = head;
    for(int i=0;i<sizeVar-1;i++) { /* -1 bo potrzebujemy przed ostatni */
        element = element->nextElement;
    }
    elementList* deletedNode = element->nextElement;
    free(deletedNode);
    element->nextElement = NULL;
    sizeVar--;
}
int main()
{
    init();
    showList();
    addToStart(177);
    showList();
    addToPosition(4,55);
    showList();
    return 0;
}
