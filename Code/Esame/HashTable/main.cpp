#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class HashElement
{
public:
	char key;
	int value;
	HashElement(char key, int value): key(key), value(value){}
};

class HashTable
{
private:
	vector<list<HashElement>> table;
	int size;
	int hash(char key){return static_cast<int>(key) % size;}

public:
	HashTable(int s): size(s){table.resize(size);}

	void insert(char key, int value)
	{
		int index = hash(key);
		table[index].push_front(HashElement(key, value));
	}

	void increment(char key)
	{
		int index = hash(key);
		for(auto& element : table[index])
			if(element.key == key)
			{
				element.value++;
				return;
			}
		insert(key, 1);
	}

	void printToFile(const string& fileName)
	{
		ofstream outputFile(fileName);
		for(const auto& bucket : table)
			for(const auto& element : bucket)
				outputFile << "Carattere -> [ " << element.key << " ] Occorrenza -> [" << element.value << " ]" << endl;
	}

	int searchCharacter(char key)
	{
		int index = hash(key);
		for(const auto& element : table[index])
			if(element.key == key)
				return element.value;
	}


	void removeCharacter(char key)
	{
		int index = hash(key);
		auto& bucket = table[index];
		for(auto it = bucket.begin(); it != bucket.end(); it++)
			if(it->key == key)
				bucket.erase(it);
		return;
	}

	vector<list<HashElement>> getTable(){return this->table;}
};



int main()
{
	HashTable hash(256);
	ifstream inputFile("input.txt");
	char ch;
	while(inputFile.get(ch))
		hash.increment(ch);
	inputFile.close();
	hash.printToFile("output.txt");
	return 0;
}