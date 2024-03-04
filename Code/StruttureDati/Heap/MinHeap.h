#ifndef MINHEAP_H
#define MINHEAP_H
#include <vector>
#define space 5

using namespace std;

template <class T>
class MinHeap
{
    private:
        vector<T> *tree;
        int heapSize;

        int left(int i){return 2*i+1;}
        int right(int i){return 2*i+2;}

        void buildMinHeap();
    protected:
        int parent(int i){return (i-1)/2;}

        T getRoot(){return this->tree->at(0);}
        T getTail(){return this->tree->at(heapSize-1);}

        vector<T>* getTree(){return this->tree;}
        void setTree(int i, T key){this->tree->at(i) = key;}

        void setHeapSize(int heapSize){this->heapSize = heapSize;}
        int getHeapSize(){return this->heapSize;}

        void inOrderAscii(int, int);
        void minHeapify(int);
        void swap(T&, T&);

    public:
        MinHeap(vector<T>*);
        MinHeap();
        //~MinHeap();

        void insert(T);
        void print();
        void printAsciiTree();

};

template<class T>
MinHeap<T> :: MinHeap(vector<T>* tree)
{
    this->tree = tree;
    this->heapSize = tree->size();
    buildMinHeap();
}

template <class T>
MinHeap<T> :: MinHeap()
{
    this->tree = new vector<T>;
    this->heapSize = 0;
}


/**
 * metodo per verificare e mantenere la proprietà di un minHeap
*/
template <class T>
void MinHeap<T>::minHeapify(int i)
{
    int leftTree = left(i);
    int rightTree = right(i);

    int min = i;

    if(leftTree < heapSize && tree->at(min) > this->tree->at(leftTree))
        min = leftTree;
    else if(rightTree < heapSize && tree->at(min) > this->tree->at(rightTree))
        min = rightTree;

    if(min != i)
    {
        swap(this->tree->at(i), this->tree->at(min));
        minHeapify(min);
    }
}

template <class T>
void MinHeap<T> :: swap(T& a, T& b)
{
    T temp = a; a = b; b = temp;
}

/**
 * Metodo fatto per la creazione di un minHeap
*/
template <class T>
void MinHeap<T> :: buildMinHeap()
{
    for(int i = heapSize/2; i >= 0; i--)
    {
        minHeapify(i);
    }

}

template <class T>
void MinHeap<T> :: inOrderAscii(int i, int spazio)
{
    if (i >= heapSize)
        return;

    spazio+=space;

    inOrderAscii(right(i), spazio);

    cout << endl;
    for(int i = space; i < spazio; i++)
        cout << " ";
    cout << this->tree->at(i) << endl;

    inOrderAscii(left(i), spazio);

}

template <class T>
void MinHeap<T> :: insert(T key)
{
    heapSize++;
    this->tree->push_back(key);
    int i = heapSize-1;
    //inserisco il nuovo valore nel posto giusto in modo da rispettare la proprietà del minHeap
    while(i != 0 && this->tree->at(parent(i)) > this->tree->at(i)){
        swap(this->tree->at(i), this->tree->at(parent(i)));
        i = parent(i);
    }

}

template <class T>
void MinHeap<T> :: print()
{
    cout << endl << "**MIN HEAP**"<< endl;
    for(int i = 0; i < heapSize; i++)
        cout << tree->at(i) << " ";
}

template <class T>
void MinHeap<T> :: printAsciiTree()
{
    cout << endl << "**MIN HEAP ASCII**" << endl;
    inOrderAscii(0,0);
}










#endif //MINHEAP_H