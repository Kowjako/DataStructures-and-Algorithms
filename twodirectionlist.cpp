#include "twodirectionlist.h"
TwoDirectionList::TwoDirectionList()
{
    //default constructor
}
TwoDirectionList::~TwoDirectionList()
{
    if(endNode!=NULL) {
    node* nextElement = endNode->prevNode;
    node* deletedNode = endNode;
        while(sizeVar>0) {
            sizeVar--;
            free(deletedNode);
            deletedNode = nextElement;
            if(sizeVar>0) nextElement = nextElement->prevNode;
        }
    }
}

void TwoDirectionList::readFromFile(string filename) {
    ifstream in(filename);
    int temporaryInt = 0;
    if(in.is_open()) {
        in>>sizeVar;
        if(in.fail()) cout<<"Blad podczas odczytywania rozmiaru"<<endl;
        else {
            startNode = (node*)malloc(sizeof(node));
            startNode->prevNode = NULL;
            startNode->nextNode = NULL;
            in>>startNode->nodeValue;
            node* tmpNode = startNode;
            for(int i=0;i<sizeVar-1;i++) {
                in>>temporaryInt;
                tmpNode = addItem(tmpNode,temporaryInt);
            }
        }
    }
}

void TwoDirectionList::fillTwoDirectionList() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(10, 100);
    /* tworzenia wezla poczatkowego */
    startNode = (node*)malloc(sizeof(node));
    startNode->nodeValue = dist(gen);
    startNode->prevNode = NULL;
    startNode->nextNode = NULL;
    /* koniec tworzenia wezla poczatkowego */
    node* tmpNode = startNode;
    for(int i=0;i<sizeVar-1;i++) /* sizeVar - 1 bo wezel poczatkowy juz istnieje */
    {
        tmpNode = addItem(tmpNode, dist(gen)); /* tmpNode przechowuje adres aktualnie dodanego wezla */
    }
    endNode = tmpNode; /* zapisanie adresu ostatniego(koncowego) wezla */
}

void TwoDirectionList::showTwoDirectionList() {
    node* tmpNode = startNode; /* poczatkowy wypisujemy osobno bo nie ma na niego wskaznika */
    for(int i=0;i<sizeVar;i++) {
        cout<<tmpNode->nodeValue<<"\t";
        tmpNode = tmpNode->nextNode;
    }
    cout<<endl;
}

void TwoDirectionList::addToStartItem(int number) {
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    if(startNode!=NULL) {
        startNode->prevNode = newNode;
    }
    else {
        endNode = newNode;
    }
    newNode->nextNode = startNode;
    newNode->nodeValue = number;
    newNode->prevNode = NULL;
    startNode = newNode; /* aktualizacja wskaznika na poczatkowy wezel na nowy dodany */
    sizeVar++;
}

void TwoDirectionList::addToEndItem(int number) {
    node* newNode;
    newNode = (node*)malloc(sizeof(node)); /* wydzielenie pamieci dla nowego wezla */
    if(endNode!=NULL) {
        endNode->nextNode = newNode; /* wskaznik ze kolejny wezel to jest nasz teraz tworzony wezel */
    }
    else {
        startNode = newNode;
    }
    newNode->nodeValue = number;
    newNode->nextNode = NULL;
    newNode->prevNode = endNode; /*wskaznik na poprzedni element teraz tworzonego wezla jest wskaznikem na wezel od ktorego tworzymy */
    endNode = newNode; /* aktualizacja wskaznika na koncowy wezel na nowy dodany na koniec*/
    sizeVar++;
}

void TwoDirectionList::addToPosition(int position, int item) {
    if(position>=sizeVar) cout<<"Nie ma takiej pozycji"<<endl;
    else
    {
        node* tmpNode = startNode;
        for(int i=0;i<position;i++) {
            tmpNode = tmpNode->nextNode; /* petla znajduje adres wezla na danej pozycji */
        }
        node* newNode;
        newNode = (node*)malloc(sizeof(node)); /* tworzenie nowego wezla */
        newNode->nextNode = tmpNode; /*przypisanie nastepnego wezla jako wezla na danej pozycji*/
        newNode->nodeValue = item;
        newNode->prevNode = tmpNode->prevNode; /* przypisanie poprzedniego wezla za pomoca adresu poprzedniego wezla aktualnego wezla */
        tmpNode->prevNode->nextNode = newNode; /* poprzedni wezel do aktulanego musi wskazywac na nastepny jako nowy dodany */
        tmpNode->prevNode = newNode; /* element byl dodany na tej pozycji wiec aktualny wezel musi wskazywac na ten nowy wstawiony element */
        sizeVar++;
    }
}

void TwoDirectionList::removeFromStart() {
    if(sizeVar==0) cout<<"Lista jest pusta"<<endl;
    else {
        node* newStartNode = startNode->nextNode; /*aktualny element poczatkowy */
        startNode->nextNode->prevNode = NULL;/* usuniecie poczatkowego elementu powoduje ze nastpeny nie ma wskaznika na poprzedni */
        free(startNode);
        startNode = NULL;
        startNode = newStartNode;
        sizeVar--;
    }
}

void TwoDirectionList::removeFromEnd() {
    if(sizeVar==0) cout<<"Lista jest pusta"<<endl;
    else {
        node* newEndNode = endNode->prevNode;
        endNode->prevNode->nextNode = NULL; /*usuniecie koncowego wezla powoduje ze wskaznik na nastpeny wezel wezla przedostatniego bedzie NULL */
        free(endNode);
        endNode = NULL;
        endNode = newEndNode;
        sizeVar--;
    }
}

void TwoDirectionList::removeFromPosition(int position) {
    if(position>=sizeVar) cout<<"Nie ma takiej pozycji"<<endl;
    else {
        node* tmpNode = startNode;
        for(int i=0;i<position;i++) {
            tmpNode = tmpNode->nextNode; /* petla znajduje adres wezla na danej pozycji */
        }
        tmpNode->prevNode->nextNode = tmpNode->nextNode; /* element poprzedni teraz wskazuje na element nastepny usuwanego wezla */
        tmpNode->nextNode->prevNode = tmpNode->prevNode; /* element nastepny teraz wskazuje na adres elementu poprzedzajacego usuwany */
        free(tmpNode);
        tmpNode = NULL;
        sizeVar--;
    }
}

bool TwoDirectionList::findElement(int item) {
    node* tmpNode = startNode; /* poczatkowy osobno bo nie ma na niego wskaznika */
    for(int i=0;i<sizeVar;i++) {
        if(tmpNode->nodeValue == item) {
            return true;
        }
        tmpNode = tmpNode->nextNode; /* przesuniecie wskaznika na nastepny wezel */
    }
    return false;
}

node* TwoDirectionList::addItem(node* previousNode, int number) {
    node* newNode;
    newNode = (node*)malloc(sizeof(node)); /* wydzielenie pamieci dla nowego wezla */
    previousNode->nextNode = newNode; /* wskaznik ze kolejny wezel to jest nasz teraz tworzony wezel */
    newNode->nodeValue = number;
    newNode->nextNode = NULL;
    newNode->prevNode = previousNode; /*wskaznik na poprzedni element teraz tworzonego wezla jest wskaznikem na wezel od ktorego tworzymy */
    return newNode;
}
