#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <sstream>

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
		for(auto& i : table[index])
			if(i.key == key)
			{
				i.value++;
				return;
			}
		insert(key, 1);
	}

	void printToFile(const string& fileName)
	{
		ofstream oFile(fileName);
		for(auto &bucket : table)
			for(auto& element : bucket)
				oFile << "key: [ " << element.key << " ] Value: [" << element.value << " ]" << endl;

	}

	int searchCharacter(char key)
	{
		int index = hash(key);
		for(auto& i : table[index])
			if(i.key == key)
				return i.value;
		return -1;
	}

	void removeCharacter(char key)
	{
		int index = hash(key);
		auto &bucket = table[index];
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
	ifstream iFile("input.txt");
	char ch;
	while(iFile.get(ch))
		hash.increment(ch);
	iFile.close();
	hash.printToFile("output.txt");
	return 0;


}