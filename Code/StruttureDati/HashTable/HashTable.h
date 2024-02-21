#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class HashTable
{
    private:
        vector<vector<pair<int, T>>> table;
        int hash(int key) {return key%table.size();}
    public:
        HashTable(int size){table.resize(size);}
        void insert(int key, T value)
        {
            int index = hash(key);
            table[index].push_back(make_pair(key, value));
        }

        T get(int key)
        {
            int index = hash(key);
            for(auto &item:table[index])
            {
                if(item.first == key){
                    return item.second;
                }
            }
            return -1;
        }
};


#endif //HASHTABLE_H