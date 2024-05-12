#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
#include <iostream>

using namespace std;

/**
 * Il MaxHeap è una struttura dati composta da un array che può essere considerato come un albero binario quasi completo, cioè tutti i livelli tranne l'ultimo sono completi
 * La sua proprietà per ogni nodo diverso dalla radice è che A[parent(i)]>=A[i]
 * 
*/

template <typename T>
class MaxHeap
{
    private:
        vector<T> tree;
        int heapSize;

        //formule per calcolare figlio sinistro e destro
        int left(int i){return 2*i+1;}
        int right(int i){return 2*i+2;}

        //metodo per costruire il max heap
        void buildMaxHeap();

    protected:

        //metodo per il calcolo del padre
        int parent(int i){return (i-1)/2;}

        
        T getRoot(){return this->tree.at(0);}
        T getTail(){return this->tree.at(0);}

        vector<T> getTree(){return this->tree;}
        void setTree(int i, T key){this->tree.at(i) = key;}
        
        void setHeapSize(int newSize) {this->heapSize= newSize;}
        int getHeapSize(){return this->heapSize;}

        //metodo per la stampa
        void inOrderAscii(int, int);

        //metodo per mantenere la proprietà dell'heap
        void maxHeapify(int);
        void swap(T&, T&);

    public:
    //costruttori e distruttore
        MaxHeap(vector<T>);
        MaxHeap();
        ~MaxHeap();

        void insert(T);
        void print();
        void printAsciiTree();
        void heapSort();
};

template <typename T>
MaxHeap<T>::MaxHeap(vector<T> tree)
{
    this->tree = tree;
    this->heapSize=tree.size();
    buildMaxHeap();
}

template <typename T>
MaxHeap<T>::MaxHeap()
{
    this->tree = new vector<T>;
    this->heapSize=0;
}

template <typename T>
MaxHeap<T> :: ~MaxHeap()
{
}

template <typename T>
void MaxHeap<T>::maxHeapify(int i)
{
    int leftTree = left(i);
    int rightTree = right(i);

    int max=i;

    if(leftTree < heapSize && this->tree.at(max) < this->tree.at(leftTree))
        max=leftTree;
    
    if(rightTree < heapSize && this->tree.at(max) < this->tree.at(rightTree))
        max=rightTree;

    if(max !=i)
    {
        swap(this->tree.at(i), this->tree.at(max));
        maxHeapify(max);
    }
}

template <typename T>
void MaxHeap<T> :: swap(T &a, T &b)
{
    T temp=a;a=b;b=temp;
}

template <typename T>
void MaxHeap<T> ::buildMaxHeap()
{
    for(int i = heapSize/2;i >=0; i--)
        maxHeapify(i);
}

template <typename T>
void MaxHeap<T> :: insert(T key)
{
    heapSize++;
    this->tree.push_back(key);
    int i = heapSize-1;
    while(i != 0 && this->tree.at(parent(i)) < this->tree.at(i))
    {
        swap(this->tree.at(i), this->tree.at(parent(i)));
        i=parent(i);
    }
}

template <typename T>
void MaxHeap<T> :: print()
{
    cout << endl << "****Max Heap****" << endl;
    for(int i = 0; i < heapSize; i++)
        cout << tree.at(i) << " ";
}

template <typename T>
void MaxHeap<T> :: printAsciiTree()
{
    cout << endl << "***Max Ascii Heap***" << endl;
    inOrderAscii(0,0);
}

template <typename T>
void MaxHeap<T> :: inOrderAscii(int i, int spazio)
{
    if(i >= heapSize)
        return;
    
    spazio+=5;

    inOrderAscii(right(i), spazio);

    cout << endl;
    for(int i = 5; i < spazio; i++)
        cout << " ";
    cout << this->tree.at(i) << endl;

    inOrderAscii(left(i), spazio);
}

template <class T>
void MaxHeap<T> :: heapSort()
{
    buildMaxHeap();
    for(int i = getHeapSize()-1; i>= 0; i--)
    {
        swap(tree.at(0), tree.at(i));
        setHeapSize(i);
        maxHeapify(0);
    }
}

#endif //MAXHEAP_H