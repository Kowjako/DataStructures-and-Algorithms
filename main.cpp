#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>

/*Kolejne struktury danych */
#include "dynamicarray.h"
#include "twodirectionlist.h"
#include "binaryheap.h"
#include "treebst.h"

using namespace std;

/** Deklaracja struktur **/
DynamicArray dArray;
TwoDirectionList twoDirList;
BinaryHeap bHeap;
TreeBST treeBST;

/** Losowanie liczb oraz sprawdzanie czasu **/
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(1, 100000);
long long int frequency, start, elapsed;


/** Zmienne **/
int structNumber = 0;
int operationNumber = 0;
int tmpNumber = 0;
int tmpPosition = 0;
string tmpLocation;

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

void workWithArray() {
    do {
        cout<<"Aktualna struktura: Tablica dynamiczna"<<endl;
        cout<<"1.Dodanie na poczatek"<<endl;
        cout<<"2.Dodanie na dowolnej pozycji"<<endl;
        cout<<"3.Dodanie na koniec"<<endl;
        cout<<"4.Usuwanie poczatku"<<endl;
        cout<<"5.Usuwanie z dowolnej pozycji"<<endl;
        cout<<"6.Usuwanie z konca"<<endl;
        cout<<"7.Wyszukiwanie elementu"<<endl;
        cout<<"8.Wczytac z pliku"<<endl;
        cout<<"9.Wyswietlic tablice"<<endl;
        cout<<"10.Koniec programu"<<endl;
        cin>>operationNumber;
        switch(operationNumber) {
            case 1:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                dArray.addToStart(tmpNumber);
                break;
            case 2:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                cout<<"Wprowadz pozycje"<<endl;
                cin>>tmpPosition;
                dArray.addToPosition(tmpPosition,tmpNumber);
                break;
            case 3:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                dArray.addToEnd(tmpNumber);
                break;
            case 4:
                dArray.removeFromStart();
                break;
            case 5:
                cout<<"Wprowadz pozycje"<<endl;
                cin>>tmpPosition;
                dArray.removeFromPosition(tmpPosition);
                break;
            case 6:
                dArray.removeFromEnd();
                break;
            case 7:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                if(dArray.findElement(tmpNumber)) cout<<"Element znaleziony"<<endl;
                else cout<<"Element nie znaleziony"<<endl;
                break;
            case 8:
                cout<<"Wprowadz lokalizacje pliku np. D://dane.txt"<<endl;
                cin>>tmpLocation;
                dArray.readFromFile(tmpLocation);
                break;
            case 9:
                dArray.showDynamicArray();
                break;
            default:
                break;
        }
    }
    while(operationNumber!=10);
}

void workWithList() {
    do {
        cout<<"Aktualna struktura: Lista dwukierunkowa"<<endl;
        cout<<"1.Dodanie na poczatek"<<endl;
        cout<<"2.Dodanie na dowolnej pozycji"<<endl;
        cout<<"3.Dodanie na koniec"<<endl;
        cout<<"4.Usuwanie poczatku"<<endl;
        cout<<"5.Usuwanie z dowolnej pozycji"<<endl;
        cout<<"6.Usuwanie z konca"<<endl;
        cout<<"7.Wyszukiwanie elementu"<<endl;
        cout<<"8.Wczytac z pliku"<<endl;
        cout<<"9.Wyswietlic liste"<<endl;
        cout<<"10.Koniec programu"<<endl;
        cin>>operationNumber;
        switch(operationNumber) {
            case 1:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                twoDirList.addToStartItem(tmpNumber);
                break;
            case 2:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                cout<<"Wprowadz pozycje"<<endl;
                cin>>tmpPosition;
                twoDirList.addToPosition(tmpPosition,tmpNumber);
                break;
            case 3:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                twoDirList.addToEndItem(tmpNumber);
                break;
            case 4:
                twoDirList.removeFromStart();
                break;
            case 5:
                cout<<"Wprowadz pozycje"<<endl;
                cin>>tmpPosition;
                twoDirList.removeFromPosition(tmpPosition);
                break;
            case 6:
                twoDirList.removeFromEnd();
                break;
            case 7:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                if(twoDirList.findElement(tmpNumber)) cout<<"Element znaleziony"<<endl;
                else cout<<"Element nie znaleziony"<<endl;
                break;
            case 8:
                cout<<"Wprowadz lokalizacje pliku np. D://dane.txt"<<endl;
                cin>>tmpLocation;
                twoDirList.readFromFile(tmpLocation);
                break;
            case 9:
                twoDirList.showTwoDirectionList();
                break;
            default:
                break;
        }
    }
    while(operationNumber!=10);
}

void workWithHeap() {
    do {
        cout<<"Aktualna struktura: Kopiec binarny typu MAX"<<endl;
        cout<<"1.Dodanie elementu"<<endl;
        cout<<"2.Usuniecie szczytu"<<endl;
        cout<<"3.Wyszukiwanie elementu"<<endl;
        cout<<"4.Wczytac z pliku"<<endl;
        cout<<"5.Wyswietlic kopiec"<<endl;
        cout<<"6.Koniec programu"<<endl;
        cin>>operationNumber;
        switch(operationNumber) {
            case 1:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                bHeap.addItem(tmpNumber);
                break;
            case 2:
                bHeap.deleteVertex();
                break;
            case 3:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                bHeap.findElement(0,tmpNumber);
                break;
            case 4:
                cout<<"Wprowadz lokalizacje pliku np. D://dane.txt"<<endl;
                cin>>tmpLocation;
                bHeap.readFromFile(tmpLocation);
                break;
            case 5:
                bHeap.showBinaryHeap();
                break;
            default:
                break;
        }

    } while(operationNumber!=6);
}

void workWithTree() {
    do {
        cout<<"Aktualna struktura: Drzewo poszukiwan binarnych"<<endl;
        cout<<"1.Dodanie elementu"<<endl;
        cout<<"2.Usuniecie elementu"<<endl;
        cout<<"3.Wyszukiwanie elementu"<<endl;
        cout<<"4.Wczytac z pliku"<<endl;
        cout<<"5.Wyswietlic drzewo"<<endl;
        cout<<"6.Koniec programu"<<endl;
        cin>>operationNumber;
        switch(operationNumber) {
            case 1:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                treeBST.addValue(tmpNumber);
                break;
            case 2:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                treeBST.deleteVertex(tmpNumber);
                break;
            case 3:
                cout<<"Wprowadz liczbe"<<endl;
                cin>>tmpNumber;
                if(treeBST.findElement(tmpNumber)) cout<<"Element znaleziony"<<endl;
                cout<<"Element nie znaleziony"<<endl;
                break;
            case 4:
                cout<<"Wprowadz lokalizacje pliku np. D://dane.txt"<<endl;
                cin>>tmpLocation;
                treeBST.readFromFile(tmpLocation);
                break;
            case 5:
                treeBST.showTree(treeBST.root,0);
                break;
            default:
                break;
        }

    } while(operationNumber!=6);
}

int main()
{
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    int i;
    /*do {
        cout<<"Witam w Projekcie Nr.1"<<endl;
        cout<<"Prosze wybrac strukture do sprawdzania"<<endl;
        cout<<"1. Tablica dynamiczna"<<endl;
        cout<<"2. Lista dwukierunokwa"<<endl;
        cout<<"3. Kopiec binarny MAX"<<endl;
        cout<<"4. Drzewo BST"<<endl;
        cout<<"5. Koniec programu"<<endl;
        cin>>structNumber;
        switch(structNumber) {
            case 1: workWithArray();
                    break;
            case 2: workWithList();
                    break;
            case 3: workWithHeap();
                    break;
            case 4: workWithTree();
                    break;
            default:
                    break;
        }
    } while(structNumber!=5); */

    /*TreeBST tree;
    int sizeVar = 40000;
    for(int i=0;i<sizeVar;i++) {
        tree.addValue(dist(gen));
    }
    double sum = 0;

    for(int i=0;i<100;i++) {
        start = read_QPC();
        tree.deleteVertex(dist(gen));
        elapsed = read_QPC() - start;
        sum+=elapsed;
    }
    cout << "Time [ns] = " << (1000.0*1000.0*1000.0 * sum) /(frequency*100)<<endl; */
	return(0);
}
