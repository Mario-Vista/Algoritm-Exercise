#include <iostream>
#include <fstream>
#include "Abr.h"


using namespace std;

int main()
{
  Abr<int> abr;
  ifstream iFile("input.txt");
  int num;
  
  while(iFile >> num)
    abr.insert(num);
  
  abr.inOrderVisit();
  cout << endl;
  abr.preOrderVisit();
  cout << endl;
  abr.postOrderVisit();
  cout << endl;
  

  return 0;
}
