#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <iostream>
#include <vector>

template <typename T>
class HashTable {
    private:
        std::vector<T> table;
        int capacity;

        int hash(T key, int i) {return (h1(key) + i * h2(key)) % capacity;}
        int h1(T key) {return key % capacity;}
        int h2(T key) {return 1 + (key % capacity);}
    public:
        HashTable(int size) : capacity(size), table(size, -1) {}
        int hash_insert(T key);
        int hash_search(T key);

        friend std::ostream& operator <<(std::ostream& out, const HashTable<T>& obj) {
            for (int i = 0; i < obj.capacity; ++i) {
                if (obj.table.at(i) != -1) {
                    out << "Posizione " << i << ": " << obj.table.at(i) << std::endl;
                } else {
                    out << "Posizione " << i << ": vuota" << std::endl;
                }
            }
            return out;
        }
};

template <typename T>
int HashTable<T>::hash_insert(T key) {
    int i = 0;
    while (i < capacity) {
        int j = hash(key, i);
        if (table.at(j) == -1) {
            table.at(j) = key;
            std::cout << "La chiave " << key << " Ã¨ stata inserita alla posizione " << j << std::endl;
            return j;
        }
        ++i;
    }
    std::cout << "Impossibile inserire la chiave: tabella piena" << std::endl;
    return -1;
}

template <typename T>
int HashTable<T>::hash_search(T key) {
    int i = 0;
    bool over = false;
    while (i < capacity && !over) {
        int j = hash(key, i);
        if (table.at(j) == key) {
            std::cout << "La chiave " << key << " è stata trovata alla posizione " << j << std::endl;
            return j;
        } else if (table.at(j) == -1) {
            over = true;
        }
        ++i;
    }
    std::cout << "La chiave " << key << " non è presente nella tabella" << std::endl;
    return -1;
}

#endif // HASH_TABLE_HPP