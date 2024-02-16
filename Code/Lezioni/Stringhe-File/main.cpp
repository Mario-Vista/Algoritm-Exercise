#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fileread("prova.txt");
    char ch;
    while(fileread.get(ch))
        cout << ch;
    cout << endl;
    fileread.close();
    return 0;
}