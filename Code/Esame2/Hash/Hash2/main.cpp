#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

class HashElement
{
    public:
    int value;
    char key;
    HashElement(char key, int value): value(value), key(key){};
};

class HashTable
{
    private:
    vector<list<HashElement>> table;
    int size;
    int hash(char key){return static_cast<int>(key)%size;}

    public:
    HashTable(int size):size(size){table.resize(size);}
    
    void insert(char key, int value)
    {
        int index = hash(key);
        table[index].push_front(HashElement(key, value));
    }

    void increment(char key)
    {
        int index = hash(key);
        for(auto &i : table[index])
            if(i.key == key)
            {
                i.value++;
                return;
            }
        insert(key, 1);
    }

    int searchElement(char key)
    {
        int index = hash(key);
        for(auto &i : table[index])
            if(i.key ==key)
                return i.value;
        return -1;
    }
    
    void deleteElement(char key)
    {
        int index = hash(key);
        auto bucket = table[index];
        for(auto it = bucket.begin(); it!= bucket.end(); it++)
            if(it->key ==key)
                bucket.erase(it);
    }

    void printToFile(const string& filename)
    {
        ofstream oFile(filename);
        for(auto &bucket: table)
            for(auto &element:bucket)
                oFile << "Carattere:[" << element.key << "] Occorrenze:[" << element.value << "]" << endl;
    }
};

int main()
{
    HashTable hash(256);
    ifstream iFile("input.txt");
    char ch;
    while(iFile.get(ch))
        hash.increment(ch);
    hash.printToFile("output.txt");
    
}