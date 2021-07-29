#include <iostream>
#include <stdlib.h>  //exit
#include "functions.h"

int main()
{
 
int numItems; //initial number of items
int tableSize;
  cout <<"*********************************"<<endl;
  cout <<"* Welcome to hashmaster v1.0    *"<<endl;
  cout <<"*                               *"<<endl;
  cout <<"* Here are your options:        *"<<endl;
  cout <<"* 1) Insert                     *"<<endl
       <<"* 2) Delete                     *"<<endl
       <<"* 3) Search                     *"<<endl
       <<"* 4) Print                      *"<<endl
       <<"* 5) Exit                       *"<<endl;
 cout << "*********************************"<<endl<<endl;

cout<< "Looks like our table is empty, let's start by fixing that."<<endl;
cout << "How many items would you like to add? ";
cin >> numItems;

//Checks for invalid input
while (numItems<0)
{
cout << "\nNumber of items cannot be negative."<<endl;
cout << "How many items would you like to add? ";
cin >> numItems;
} 

//checks if user wants to use program.
if (numItems == 0)
{
  cout <<"\nWell that was not much fun. Bye bye!\n";
  exit (EXIT_SUCCESS);
}

cout << "How many buckets? ";
cin >> tableSize;

//creates array 
int mydata[numItems];
HTable myhash(tableSize);
int temp;

//fills initial array

for (int i = 0; i < numItems; i++)
{
  cout << "What is value "<<(i+1)<<"? ";
  cin >> temp;
  mydata[i]=temp;
  myhash.insertval(mydata[i]);
}

cout<<"\nTable as of now\n";
myhash.printtbl();


int answer;
do{

cout <<"\nWhat option would you like? ";
cin >> answer;
if (answer==1){
  cout << "What is value? ";
  cin >> temp;
  myhash.insertval(temp);
}
else if (answer==2){
cout << "What value would you like to delete? ";
cin >> temp;
myhash.deleteval(temp);
cout << "If it existed now it doesn't.";
}
else if (answer==3)
{
cout << "What value would you like to search? ";
cin >> temp;
cout << "Ooops, this feature is to be added. Psssst don't tell anyone.";
}

else if (answer==4)
{
myhash.printtbl();
}

else if (answer==5)
{cout<<"Have a great day!";}
else 
{cout<<"Invalid choice, lets try this again.";}

}while(answer!=5);



return(0);

}
