#include "binaryheap.h"

BinaryHeap::BinaryHeap()
{
    //ctor
}
BinaryHeap::~BinaryHeap()
{
    sizeVar = 0;
    free(heap);
    heap = NULL;
}

void BinaryHeap::showBinaryHeap() {
    for(int i=0;i<sizeVar;i++) {
        cout<<heap[i]<<"\t";
    }
    cout<<endl;
}

void BinaryHeap::readFromFile(string filename) {
    int temporaryInt = 0, temporarySize = 0;
    ifstream in(filename);
    if(in.is_open()) {
        in>>temporarySize;
        if(in.fail()) cout<<"Blad podczas odczytywania rozmiaru"<<endl;
        else {
            for(int i=0;i<temporarySize-1;i++) {
                in>>temporaryInt;
                if(in.fail()) cout<<"Blad odczytywania wartosci"<<endl;
                else
                addItem(temporaryInt);
            }
            in.close();
        }
    }
    else cout<<"Blad przy otwieraniu pliku"<<endl;
}

void BinaryHeap::addItem(int item) {
    int* tmp = (int*)calloc((sizeVar+1),sizeof(int));
    for(int i=0;i<sizeVar;i++) {
        tmp[i]= heap[i];
    }
    free(heap);
    heap = tmp;
    addToNormalizedPosition(item);
}

void BinaryHeap::deleteVertex() {
    int *tmp = (int*)realloc(heap, sizeof(int)*(sizeVar-1));
    tmp[0] = heap[sizeVar-1]; /*usuniecie szczytu jako zamiana na ostatni element */
    sizeVar--;
    normalize(0); /* usuniecie szczytu wymaga normalizacji od korzenia */
}

void BinaryHeap::normalize(int index) {
    int temp;
    int leftItem = 2*index+1;
    int rightItem = 2*index+2;
    if(leftItem<sizeVar) {
        if(heap[index]<heap[leftItem]) { /*rekurencyjny algorytm uporzadkowania po lewej stronie potomka */
            temp = heap[index];
            heap[index] = heap[leftItem];
            heap[leftItem] = temp;
            normalize(leftItem);
        }
    }
    if(rightItem<sizeVar) {
        if(heap[index]<heap[rightItem]) { /*rekurrencyjny algorytm uporzadkowania po prawej stronie potomka */
            temp = heap[index];
            heap[index] = heap[rightItem];
            heap[rightItem] = temp;
            normalize(rightItem);
        }
    }
}

void BinaryHeap::initializate(int sizeValue) {
    heap = (int*)calloc(sizeValue,sizeof(int));
    for(int i=0;i<sizeValue;i++) {
        addToNormalizedPosition(rand()%50);
    }
}

bool BinaryHeap::findElement(int i,int item) { /* wywolanie funkcji gdzie i wstawiamy 0 - poczatek */
    if(item>heap[i]) return false;
    if(item==heap[i]) {
        return true;
    }

    int left = 2*i+1;
    if(left>=sizeVar)
        return false; /* jezeli nie ma lewego to prawego nie moze byc */

    bool findLeft = findElement(left, item);
    if(findLeft!=false) {
        return true;
    }

    int right = 2*i+2;
    if(right>=sizeVar)
        return false;
    else
        return findElement(right,item);

}

void BinaryHeap::addToNormalizedPosition(int element) {
    int parentNode;
    int i = sizeVar;
    heap[sizeVar] = element; /* dodanie nowego elementu na koniec tablicy */
    parentNode = (i-1)/2; /* indeks rodzica  */
    while(i>0) {
        if(heap[i]>heap[parentNode]) { /* jezeli jest wiekszy niz rodzic robimy swap */
            int tmp = heap[i];
            heap[i] = heap[parentNode];
            heap[parentNode] = tmp;
        }
        i = parentNode;   /* ustawiamy pozycje elementu jako pozycje rodzica */
        parentNode = (i-1)/2; /* obliczamy pozycje "nowego" rodzica */
    }
    sizeVar++;
}

