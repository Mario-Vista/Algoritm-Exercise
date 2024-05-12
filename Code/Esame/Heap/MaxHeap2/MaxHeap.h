#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include<vector>


using namespace std;

template <class T>
class MaxHeap
{
    private:
        vector<T> tree; //
        int heapSize;   //

        int left(int i){return (2*i)+1;}//
        int right(int i){return (2*i)+2;}//
        int parent(int i){return (i-1)/2;}//
        void swap(T&, T&);//
        void inOrderAscii(int, int);//
        void buildMaxHeap();//
        void maxHeapify(int);//
        vector<T> getTree(){return this->tree;}//
        void setTree(int i, T key){this->tree.at(i) = key;}//
        int getHeapSize(){return this->heapSize;}//
        void setHeapSize(int heapSiz){this->heapSize = heapSiz;}//
        T getRoot(){return this->tree.at(0);}//
        T getTail(){return this->tree.at(0);}//
    public:
        MaxHeap(vector<T>);//
        MaxHeap();//
        void printAsciiTree();  //
        void insert(T key);//
        void heapSort();//
        void printTree();
};

template <class T>
MaxHeap<T> :: MaxHeap(vector<T> vet)
{
    this->tree = vet;
    this->heapSize = vet.size();
    buildMaxHeap();
}

template <class T>
MaxHeap<T> :: MaxHeap()
{
    this->tree = new vector<T>;
    this->heapSize = 0;
}

template <typename T>
void MaxHeap<T> :: swap(T &a, T &b)
{
    T temp=a;a=b;b=temp;
}
template <class T>
void MaxHeap<T> :: buildMaxHeap()
{
    for(int i = heapSize/2; i >=0; i--)
        this->maxHeapify(i);
}

template <class T>
void MaxHeap<T> :: maxHeapify(int i)
{
    int max = i;
    int l = left(i);
    int r = right(i);

    if(l < heapSize && this->tree.at(max) < this->tree.at(l))
        max = l;
    if(r < heapSize && this->tree.at(max) < this->tree.at(r))
        max = r;
    if(max != i)
    {
        swap(this->tree.at(i), this->tree.at(max));
        maxHeapify(max);
    }
}

template <class T>
void MaxHeap<T> :: insert(T key)
{
    heapSize++;
    tree.push_back(key);
    int i = heapSize-1;
    while(i!=0 && this->tree.at(parent(i)) < this->tree.at(i))
    {
        swap(this->tree.at(i), this->tree.at(parent(i)));
        i = parent(i);
    }
}     

template <class T>
void MaxHeap<T> :: inOrderAscii(int i, int spazio)
{
    if(i >= heapSize)
        return;
    spazio+=5;

    inOrderAscii(right(i), spazio);

    cout << endl;

    for(int h = 5; h < spazio; h++)
    {
        cout << " prova ";

    }
    cout << this->tree.at(i) << endl;

    inOrderAscii(left(i), spazio);
}

template <class T>
void MaxHeap<T> :: printAsciiTree()
{
    cout <<"**ASCI TREE***" << endl;
    inOrderAscii(0,0);
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

template <class T>
void MaxHeap<T>::printTree() {
    cout << "\nPrint Tree: " << endl;
    for(auto i : tree)
        cout << i << endl;
}



#endif //MAXHEAP_H