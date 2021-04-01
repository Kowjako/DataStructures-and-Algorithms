#include "dynamicarray.h"

DynamicArray::DynamicArray(int rozmiar = 0)
{
    this->sizeVar = rozmiar;
    dynamicArrayptr = (int*)calloc(sizeVar, sizeof(int));
}
DynamicArray::DynamicArray()
{
    //default constructor
}
DynamicArray::~DynamicArray()
{
    if(dynamicArrayptr==NULL) return;
    free(dynamicArrayptr);
    sizeVar = 0;
    dynamicArrayptr = NULL;
}

void DynamicArray::readFromFile(string filename) {  /* funkcja do odczytywania danych z pliku */
    ifstream in(filename);
    int temporaryInt = 0;
    if(in.is_open()) {
        in>>sizeVar;
        if(in.fail()) cout<<"Blad podczas odczytywania rozmiaru"<<endl;
        else {
            dynamicArrayptr = (int*)calloc(sizeVar, sizeof(int));
            for(int i=0;i<sizeVar;i++) {
                in>>temporaryInt;
                if(in.fail()) {
                    cout<<"Blad odczytywania wartosci"<<endl;
                }
                else dynamicArrayptr[i] = temporaryInt;
            }
            in.close();
        }
    }
    else cout<<"Blad przy otwieraniu pliku"<<endl;
}

void DynamicArray::fillDynamicArray(int val) { /* funkcja do napelnienia tablicy */
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(10, 100);
    sizeVar = val;
    dynamicArrayptr = (int*)calloc(sizeVar, sizeof(int));
    for(int i =0 ;i<sizeVar; i++) *(dynamicArrayptr+i) = dist(gen);
}

void DynamicArray::showDynamicArray() {  /* funkcja wypisujaca zawartosc tablicy */
    for(int i=0;i<sizeVar;i++) {
        cout<<*(dynamicArrayptr+i)<<"\t";
    }
    cout<<endl;
}

void DynamicArray::addToPosition(int position, int item) { /* dodaje element do konkretnej poyzcji */
    if(position>=sizeVar) cout<<"Nie ma takiej pozycji"<<endl;
    else
    {
        int replacer = 0;
        int *buffer = (int*)calloc(sizeVar+1, sizeof(int));
        sizeVar++;
        for(int i = 0;i<sizeVar;i++) {
            if(i==position) {
                buffer[i] = item;
                replacer = 1;
            }
            else
            {
                buffer[i] = dynamicArrayptr[i-replacer];
            }
        }
        free(dynamicArrayptr); /*usuniecie tablicy */
        dynamicArrayptr = buffer; /*przypisanie wskaznika na nowy adres tablicy */
    }
}

void DynamicArray::addToEnd(int item) { /* dodaje element w koniec tablicy */
    int* buffer = (int*)calloc(sizeVar+1, sizeof(int));
    for(int i=0;i<sizeVar;i++) {
        buffer[i] = dynamicArrayptr[i];
    }
    buffer[sizeVar] = item;
    free(dynamicArrayptr);
    dynamicArrayptr = buffer;
    sizeVar++;
}

void DynamicArray::addToStart(int item) { /* dodaje element na poczatku tablicy */
    int* buffer = (int*)calloc(sizeVar+1, sizeof(int)); /* nowa tablica do przechowywania */
    buffer[0] = item;
    sizeVar++;
    for(int i=1;i<sizeVar;i++) {
        *(buffer+i) = *(dynamicArrayptr+i-1);
    }
    free(dynamicArrayptr); /*usuniecie tablicy */
    dynamicArrayptr = NULL;
    dynamicArrayptr = buffer; /*przypisanie wskaznika na nowy adres tablicy */
}

void DynamicArray::removeFromPosition(int position) { /*usuwa element z okreslonej pozycji */
    if(position>=sizeVar) cout<<"Nie ma takiej pozycji"<<endl;
    else
    {
        int replacer = 0;
        int* buffer = (int*)calloc(sizeVar-1, sizeof(int)); /* realokacja pamieci */
        for(int i=0;i<sizeVar;i++) {
            if(i==position) {
                    replacer = 1;
                    continue;
            }
            else
            buffer[i-replacer] = dynamicArrayptr[i];
        }
        free(dynamicArrayptr);
        dynamicArrayptr = buffer;
        sizeVar--;
    }
}

void DynamicArray::removeFromEnd() { /*usuwa element koncowy */
    if(sizeVar==0)
        cout<<"Tablica jest pusta"<<endl;
    else {
        int* newArray = (int*)calloc(sizeVar-1, sizeof(int)); /* realokacja pamieci */
        for(int i=0;i<sizeVar-1;i++){
            newArray[i] = dynamicArrayptr[i];
        }
        free(dynamicArrayptr);
        dynamicArrayptr = newArray;
        sizeVar--;
    }
}

void DynamicArray::removeFromStart() { /* usuwa element poczatkowy */
    if(sizeVar==0)
        cout<<"Tablica jest pusta"<<endl;
    else {
        int* buffer = (int*)calloc(sizeVar-1,sizeof(int)); /* realokacja pamieci */
        sizeVar--;
        for(int i=0;i<sizeVar;i++) {
            buffer[i] = dynamicArrayptr[i+1];
        }
        free(dynamicArrayptr);
        dynamicArrayptr = buffer;
    }
}

bool DynamicArray::findElement(int element) { /* szuka okreslony element w tablicy */
    for(int i=0;i<sizeVar;i++) {
        if(*(dynamicArrayptr+i)==element) {
            return true;
        }
    }
    return false;
}

