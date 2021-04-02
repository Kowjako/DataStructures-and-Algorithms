#include "binayheap.h"

BinaryHeap::BinaryHeap()
{
    //ctor
}
BinaryHeap::~BinaryHeap()
{
    //dtor
}

void BinaryHeap::showBinaryHeap() {
    for(int i=0;i<sizeVar;i++) {
        cout<<heap[i]<<"\t";
    }
    cout<<endl;
}

void BinaryHeap::addItem(int item) {
    int* tmp = (int*)calloc((sizeVar+1),sizeof(int));
    for(int i=0;i<sizeVar;i++) {
        tmp[i]= heap[i];
    }
    free(heap);
    heap = NULL;
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
        if(heap[index]<heap[leftItem]) { /*rekursywny algorytm uporzadkowania po lewej stronie potomka */
            temp = heap[index];
            heap[index] = heap[leftItem];
            heap[leftItem] = temp;
            normalize(leftItem);
        }
    }
    if(rightItem<sizeVar) {
        if(heap[index]<heap[rightItem]) { /*rekursywny algorytm uporzadkowania po prawej stronie potomka */
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

void BinaryHeap::startValues(int newArr[]) {
    sizeVar = 9;
    heap = (int*)calloc(sizeVar,sizeof(int));
    for(int i=0;i<sizeVar;i++) {
        heap[i] = newArr[i];
    }
}

void BinaryHeap::initializateWithArray(int arr[], int sizeValue) {
    heap = (int*)calloc(sizeValue,sizeof(int));
    for(int i=0;i<sizeValue;i++) {
        addToNormalizedPosition(arr[i]);
    }
}

void BinaryHeap::findElement(int item) {
    for(int i=0;i<sizeVar;i++) {
        if(*(heap+i)==item) {
            cout<<"Element znaleziony: pozycja = "<<i<<endl;
            return;
        }
    }
    cout<<"element nie zostal znaleziony"<<endl;
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

void BinaryHeap::floydMethod() {
    for(int i = (sizeVar-2)/2;i>=0;i--) /*sizevar-2/2 to pozcyja rodzica dla ostaniego elementa w tablicy */
    {
        changePosition(heap,i,sizeVar-1); /* dla kazdego korzenia sortujemy drzewa */
    }
}

void BinaryHeap::changePosition(int* heap, int start, int finish) {
    int maxElement = 2*start+1; /* pozycja lewego elementu */
    while(maxElement<=finish) {
        if(maxElement<finish && (heap[maxElement]<heap[maxElement+1])) maxElement++; /*jezeli prawy potomek > lewy ustawiamy pozycje maksymalnego */
        if(heap[start]<heap[maxElement]) { /* sprawdzamy wierzcholek oraz maksymalny element */
            int tmp = heap[start];
            heap[start] = heap[maxElement];
            heap[maxElement] = tmp;
            start = maxElement; /*ustawiamy nowy korzen */
            maxElement = 2*start+1; /*obliczamy dla niego lewego potomka */
        }
        else
        {
            maxElement = finish+1; /* tu trafi jezeli korzen jest wiekszy swoich potomkow i to powoduje wyjscie z uporzadkowania */
        }
    }
}

void BinaryHeap::readFromFile(string filename) {}
