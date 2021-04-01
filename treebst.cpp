#include "treebst.h"

TreeBST::TreeBST()
{
    //ctor
}

TreeBST::~TreeBST()
{
    clearTree(root);
}

void TreeBST::clearTree(nodeBST* node) {
    if(node!=NULL) {
        nodeBST* rightItem = node->rightItem;
        nodeBST* leftItem = node->leftItem;
        clearTree(rightItem);
        clearTree(leftItem);
        free(node);
        node = NULL;
        balanced = false;
    }
}

void TreeBST::readFromFile(string filename) {
    int tmpSize = 0, temporaryInt = 0;
    ifstream in(filename);
    if(in.is_open()) {
        in>>tmpSize;
        if(in.fail()) cout<<"Blad podczas odczytywania rozmiaru"<<endl;
        else {
            for(int i=0;i<tmpSize;i++) {
                in>>temporaryInt;
                if(in.fail()) {
                    cout<<"Blad odczytywania wartosci"<<endl;
                }
                else addValue(temporaryInt);
            }
            in.close();
        }
    }
    else cout<<"Blad przy otwieraniu pliku"<<endl;
}


nodeBST* TreeBST::addNewNode(nodeBST* parent, int value) {
    nodeBST* tmpNode = (nodeBST*)malloc(sizeof(nodeBST));
    tmpNode->leftItem = NULL; /*nowy element nie ma na poczatku potomkow*/
    tmpNode->rightItem = NULL; /*nowy element nie ma na poczatku potomkow*/
    tmpNode->value = value;
    tmpNode->parentItem = parent;
    return tmpNode;
}

void TreeBST::addValue(int value) {
    bool notInserted = true;
    if(root == NULL) {
        root = addNewNode(NULL, value);
        return;
    }
    nodeBST* tmpRoot = root;
    while(notInserted) {
        if(value >= tmpRoot->value) {
            if(tmpRoot->rightItem!=NULL) {
                tmpRoot = tmpRoot->rightItem;
            }
            else
            {
                tmpRoot->rightItem = addNewNode(tmpRoot,value);
                notInserted = false;
            }
        }
        else
        {
            if(tmpRoot->leftItem!=NULL) {
                tmpRoot = tmpRoot->leftItem;
            }
            else
            {
                tmpRoot->leftItem = addNewNode(tmpRoot, value);
                notInserted = false;
            }
        }
    }
}

void TreeBST::deletePtr(nodeBST* deletedNode) {
    if(deletedNode->leftItem!=NULL && deletedNode->rightItem!=NULL) { /* kasowany wezel ma dwoch potomkow */
        nodeBST* maxLeftTreeNode = getMaxNode(deletedNode->leftItem); /* szukamy najwiekszy element w lewym potomnym drzewie */
        deletedNode->value = maxLeftTreeNode->value; /*zamieniamy wartosc usuwanego wezla na najwiekszy element w lewym potomnym */
        deletePtr(maxLeftTreeNode); /*kasujemy nawiekszy element w lewym potomnym drzewie rekursywnie */
        return; /* wychodzimy z funkcji zeby nie byl usuniety poczatkowy element za pomoca ostatniej linijki  free(deletedNode)*/
    }
    else
    {
        if(deletedNode->leftItem!=NULL) { /* ma tylko potomka po lewej */
            if(deletedNode==root) {
                nodeBST* newRoot = deletedNode->leftItem;
                free(root);
                root = newRoot;
                return;
            }
            else
            {
                if(deletedNode == deletedNode->parentItem->leftItem) { /* kasowany wezel jest dla rodzica lewym? */
                    deletedNode->parentItem->leftItem = deletedNode->leftItem;
                }
                else deletedNode->parentItem->rightItem = deletedNode->leftItem;
            }
        }
        else
        {
            if(deletedNode->rightItem!=NULL) { /* ma tylko potomka po prawej */
                if(deletedNode==root) {
                    nodeBST* newRoot = deletedNode->rightItem;
                    free(root);
                    root = newRoot;
                    return;
                }
                else
                {
                    if(deletedNode == deletedNode->parentItem->rightItem) { /* kasowany wezel jest dla rodzica prawym? */
                        deletedNode->parentItem->rightItem = deletedNode->rightItem;
                    }
                    else deletedNode->parentItem->leftItem = deletedNode->rightItem;
                }
            }
            else /*przypadek gdy nie ma potomkow czyli jest wiszacym */
            {
                if(deletedNode==root) {
                    free(root);
                    root = NULL;
                    return;
                }
                else {
                    if(deletedNode == deletedNode->parentItem->leftItem) { /*wiszacy wezel jest lewym odnosnie rodzica ? */
                        deletedNode->parentItem->leftItem = NULL;
                    }
                    else
                    {
                        deletedNode->parentItem->rightItem = NULL;
                    }
                }
            }
        }
    }
    free(deletedNode);
}

nodeBST* TreeBST::getMaxNode(nodeBST* parent) {
    while(parent->rightItem!=NULL) {
        parent = parent->rightItem;
    }
    return parent;
}

void TreeBST::deleteVertex(int value) {
    if(root == NULL) {
        cout<<"Drzewo BST nie ma wierzcholku"<<endl;
        return;
    }
    nodeBST* deletedNode = findElement(value);
    if(deletedNode!=NULL) {
        deletePtr(deletedNode);
    }
    else return;
}

void TreeBST::showTree(nodeBST* root, long n) {
    if(root!=NULL)
    {
      showTree(root->rightItem, n+5);
      for (long i=0;i<n;i++) printf(" ");
      printf("%d\n", root->value);
      showTree(root->leftItem, n+5);
    }
}

void TreeBST::leftRotation(nodeBST* rotRoot) {
    if(root==NULL) return;
    nodeBST* parent = NULL;
    nodeBST* a = NULL; //wezel rotacji
    nodeBST* b = NULL; //prawy potomek
    nodeBST* c = NULL; //lewy potomek prawego potomka
    /** Ustawianie adresow **/
    a = rotRoot; //wezel odnosnie ktorego bedzie rotacja
    parent = a->parentItem; //rodzic wezla rotacji
    b = a->rightItem;   //prawy potomek wezla rotacji
    if(b == NULL) {
        return;     //lewa rotacja niemozliwa gdy nie ma prawego potomka
    }
    c = b->leftItem;    //lewy potomek prawego potomka wezla rotacji
    /** Rotacja **/
    b->leftItem = a;    //po rotacji A bedzie lewym potomkiem B
    if(c!=NULL) {
        c->parentItem = a;  //jezeli C nie jest NULL ustawiamy dla nowego rodzica dla tego wezla
        a->rightItem = c; //po rotacji c bedzie prawym potomkiem dla A
    }
    else a->rightItem = NULL; //jezeli nie bylo C to po rotacji dla A prawego potomka nie bedzie
    b->parentItem = parent;     //B teraz zamiast a wiec teraz b bedzie wskazywal na rodzica wezla rotacji
    if(parent!=NULL) {  //jezeli A nie bylo korzeniem drzewa
        if(parent->leftItem == a) { //sprawdzamy jakim potomkiem byl poczatkowy wezel rotacji
            parent->leftItem = b;
        }
        else parent->rightItem = b;
    }
    a->parentItem = b;      //aktualizujemy rodzica A bo teraz jego rodzicem jest B
    if(parent==NULL) {
        root = b;   //jezeli A byl korzeniem to teraz po rotacji korzeniem bedzie B
    }
}

void TreeBST::rightRotation(nodeBST* rotRoot) {
    if(root==NULL) return;
    nodeBST* parent;
    nodeBST* a; //wezel rotacji
    nodeBST* b; //lewy potomek
    nodeBST* c; //prawy potomek lewego potomka
    /** Ustawianie adresow **/
    a = rotRoot; //wezel odnosnie ktorego bedzie rotacja
    parent = a->parentItem; //rodzic wezla rotacji
    b = a->leftItem;   //lewypotomek wezla rotacji
    if(b == NULL) {
        return;     //prawa rotacja niemozliwa gdy nie ma lewego potomka
    }
    c = b->rightItem;    //prawy potomek prawego potomka wezla rotacji
    /** Rotacja **/
    b->rightItem = a;    //po rotacji A bedzie prawym potomkiem B
    if(c!=NULL) {
        c->parentItem = a;  //jezeli C nie jest NULL ustawiamy dla nowego rodzica dla tego wezla
        a->leftItem = c; //po rotacji c bedzie prawym potomkiem dla A
    }
    else a->leftItem = NULL; //jezeli nie bylo C to po rotacji dla A prawego potomka nie bedzie
    b->parentItem = parent;     //B teraz zamiast a wiec teraz b bedzie wskazywal na rodzica wezla rotacji
    if(parent!=NULL) {  //jezeli A nie bylo korzeniem drzewa
        if(parent->leftItem == a) { //sprawdzamy jakim potomkiem byl poczatkowy wezel rotacji
            parent->leftItem = b;
        }
        else parent->rightItem = b;
    }
    a->parentItem = b;      //aktualizujemy rodzica A bo teraz jego rodzicem jest B
    if(parent==NULL) {
        root = b;   //jezeli A byl korzeniem to teraz po rotacji korzeniem bedzie B
    }
}

void TreeBST::algorithmDSW() {
    if(balanced) {
        cout<<"Drzewo juz jest zrownowazone"<<endl;
        return;
    }
    /** Etap 1 - Prostowanie **/
    nodeBST* startNode = root;
    while(startNode!=NULL) {
        if(startNode->leftItem!=NULL) {
            rightRotation(startNode);
            startNode = root;
        }
        else {
            startNode = startNode->rightItem;
        }
    }
    /** Etap 2 - Rownowazenie **/
    numberOfNodes(root);
    startNode = root;
    nodeBST* nextNode = NULL;

    int fullLevel = pow(2, log2(counter+1)) - 1; //m
    int difference = counter - fullLevel; //n-m
    while(difference!=0) {
        nextNode = startNode->rightItem->rightItem;    //obliczamy wskaznik na co drugi element
        leftRotation(startNode);        //robimy rotacje w lewo
        startNode = nextNode;   //przechodzimy do nastepnego ktory jest co drugim
        difference--;
    }
    startNode = root;
    nextNode = NULL;
    while(fullLevel>1) {
        fullLevel = fullLevel/2;
        for(int i=0;i<fullLevel;i++) {  //wykonujemy floor(m/2) rotacji w lewo
            nextNode = startNode->rightItem->rightItem;    //obliczamy wskaznik na co drugi element
            leftRotation(startNode);
            startNode = nextNode;
        }
        startNode = root;  //po rotacjach aktualizujemy startNode na nowy korzen
    }
    balanced = true;
}

void TreeBST::numberOfNodes(nodeBST* root) {
    if(root==NULL) return;
    numberOfNodes(root->leftItem);
    counter++;
    numberOfNodes(root->rightItem);
}

nodeBST* TreeBST::findElement(int element) {
    if(root==NULL) {
        return NULL;
    }
    else
    {
        nodeBST* tmpNode = root;
        while(tmpNode!=NULL) {
            if(element > tmpNode->value) {
                tmpNode = tmpNode->rightItem;
            }
            else
            {
                if(element<tmpNode->value) tmpNode = tmpNode->leftItem;
                    else
                    {
                        return tmpNode;
                    }
            }
        }
        return NULL;
    }
}
