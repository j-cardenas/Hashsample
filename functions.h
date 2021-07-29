#include <iostream>
#include <list>
#include <cmath>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


using namespace std;

class HTable {

private:
  list<int> *htable;
  long long int count;

  //hashing function
  int gethash(int key)
  { 
   int x = key;
   
    return x % count;}

public:
  //constructor
  HTable(int x)
  {
   count = x;
   htable = new list<int>[count];
  }

//insert
  void insertval(int key)
  { htable[gethash(key)].push_back(key);}

//delete
void deleteval(int key)
{
   int pos = gethash(key);

   list<int>::iterator it;
  for (it = htable[pos].begin(); it != htable[pos].end(); it++)
  {
    if (*it == key)
     break;
  }

  if (it != htable[pos].end())
   htable[pos].erase(it);
}

/*void searchval(int key){
{
  
   int pos = gethash(key);

   list<int>::iterator it;
  for (it = htable[pos].begin(); it != htable[pos].end(); it++)
  {
    if (*it == key){
      cout << *it;
     break;
    }
  }

}*/

//Print function
void printtbl()
{

  for (int i=0; i < count; i++)  //traverse the indexes
  {
   cout << i << ": ";
    for  (int j : htable[i])
    {
      cout << j << " -> ";
    }
    cout << endl;
  }
}

}; //close class


#endif 