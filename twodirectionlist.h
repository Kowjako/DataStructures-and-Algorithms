#ifndef TWODIRECTIONLIST_H
#define TWODIRECTIONLIST_H
#include <random>
#include <iostream>
#include <fstream>

using namespace std;

struct node {
    int nodeValue;
    node* prevNode;
    node* nextNode;
};

class TwoDirectionList
{
    public:
        TwoDirectionList();
        virtual ~TwoDirectionList();
        int sizeVar = 0;

        node* startNode = NULL; /* wskaznik na wezel poczatkowy */
        node* endNode = NULL; /* wskaznik na wezel koncowy */

        void readFromFile(string filename);
        void fillTwoDirectionList();
        void showTwoDirectionList();
        void addToStartItem(int number);
        void addToEndItem(int number);
        void addToPosition(int position, int item);
        void removeFromStart();
        void removeFromEnd();
        void removeFromPosition(int position);
        bool findElement(int item);

    protected:
    private:
        node* addItem(node* previousNode, int number);
};

#endif // TWODIRECTIONLIST_H
