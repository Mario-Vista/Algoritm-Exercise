#include "Bst.h"
#include <iostream>

using namespace std;

int main(){

    Bst<int> bst;

    bst.insert(10);
    bst.insert(100);
    bst.insert(20);
    bst.insert(18);
    bst.insert(120);
    bst.insert(4);

    cout << "MIN: " << bst.minimum() << endl;
    cout << "MAX: " << bst.maximum() << endl;
    cout << "SUC: " << bst.successor(bst.getRoot()) << endl;
    cout << "PRE: " << bst.predecessor(bst.getRoot()) << endl;

    cout << endl << "***PRE ORDER***" << endl;
    bst.preOrder();

    cout << endl << "***IN ORDER***" << endl;
    bst.inOrder();
    
    cout << endl << "***POST ORDER***" << endl;
    bst.postOrder();
    cout << endl;

    return 0;
}