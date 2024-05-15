#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class HashElement
{
public:
	char key;
	int value;
	HashElement(char key, int value): key(key), value(value){};
};

class HashTable
{
private:

	vector<list<HashElement>> table;
	int size;
	int hash(char key){return static_cast<int>(key)%size;}

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
		ofstream oFile(fileName);
		for(auto& bucket:table)
			for(auto& element:bucket)
				oFile << "Carattere: [ " << element.key << " ] Occorrenza: [" << element.value << " ]" << endl;
	}
	
	int searchCharacter(char key)
	{
		int index = hash(key);
		for(auto& element : table[index])
			if(element.key == key)
				return element.value;
		return -1;
	}

	void deleteCharacter(char key)
	{
		int index = hash(key);
		
		auto&bucket = table[index];
		for(auto it = bucket.begin(); it != bucket.end(); it++)
			if(it->key == key)
				bucket.erase(it);
		return;
	}

};

int main()
{
	HashTable hash(256);
	ifstream iFile("input.txt");

	char ch;

	while(iFile.get(ch))
		hash.increment(ch);

	iFile.close();

	hash.printToFile("output.txt");

	return 0;
}