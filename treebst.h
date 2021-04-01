#ifndef TREEBST_H
#define TREEBST_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>
#include <math.h>

struct nodeBST {
    int value;
    nodeBST* parentItem;
    nodeBST* leftItem;
    nodeBST* rightItem;
};

using namespace std;

class TreeBST
{
    public:
        TreeBST();
        virtual ~TreeBST();

        int counter = 0;    //zmienna dla algorytmu DSW
        nodeBST* root = NULL;
        bool balanced = false;

        void addValue(int value);
        nodeBST* addNewNode(nodeBST* parent, int value);
        void deletePtr(nodeBST* deletedNode);
        void deleteVertex(int value);
        nodeBST* getMaxNode(nodeBST* parent);
        nodeBST* findElement(int value);

        void leftRotation(nodeBST* root);   //funkcja rotacji w lewo
        void rightRotation(nodeBST* root);  //funkcja rotacji w prawo
        void algorithmDSW();
        void numberOfNodes(nodeBST* root); //funkcja pomocnicza dla algorytmu DSW

        void showTree(nodeBST* startNode, long n);
        void readFromFile(string filename);

    protected:

    private:
        void clearTree(nodeBST* node);
};

#endif // TREEBST_H
