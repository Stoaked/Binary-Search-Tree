//Author:Ryan Byrnes
//Course: Seng1120 Data Structores
//File: HTable.hpp

//#include "HTable.h"
#include <cstddef>
#include <ostream>
#include <iostream>


template<typename T>
HTable<T>::HTable()
{
      for(int i = 0;i<HASH_SIZE; i++) //will loop through the array and add an array to the hash tanle for the size of the hash table set at 5000
      {
      	hashh[i] = NULL;
      }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
HTable<T>::~HTable()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//This is the hash function provided for the assignment
template <typename T> 
int HTable<T>::hashFunc( const T& data ) { 
 int position = 0; 
 string temp = data.get_code (); 
 
 for ( int i=0; i<(int)temp.length( ); i++ ) { 
  position += ( i+1 ) * ( i+1 ) * temp.at( i ); 
 } 
 return position % HASH_SIZE; 
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void HTable<T>::add(const T& data)
{
     int hashLocation = hashFunc(data);
     if (hashh[hashLocation] == NULL)
     {
     	hashh[hashLocation] = new T(data);
     }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
T& HTable<T>::get(T& data)
{
	int location = hashFunc(data);
	return data[location];
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void HTable<T>::remove(T& data)
{
    int	hashLocation = hashFunc(data);
    if(hashh[hashLocation] == NULL)
    {
    	return;
    }
    else
    {
    	delete hashh[hashLocation];
    	hashh[hashLocation] = NULL;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T> 
int calculateInventory()
{
	int loop=0;
	for(int i=0;i<HASH_SIZE; i++)
	{
     	loop+= hashh[i]->get_quantity();
	}
	return loop;
	//I COULD CREATE A NEW CALCINVENTORY FUNCTION THAT PASSES IN THE HASH TABLE AND THEN RETURN IT THROUGH ANOTHER FUNCTION WITH PROPER NAME
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T> 
int calculateParts()
{
   int loop=0;
   for(int i=0;i<HASH_SIZE;i++)
   {
   	if(hashh[i] == NULL)
   	{
   		return NULL;
   	}
   	else
   	{
   		loop++;
   	}
   }
   return loop;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
ostream& operator << (ostream& out, HTable<T>& table)
{
	table.printTable(out);
	return out;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
 ostream& printTable(ostream& out)
 {
 	for(int i=0;i<HASH_SIZE;i++)
 	{
 			out << "(" << hashh[i]->get_code() << ","
 			<< hashh[i]->get_quantity() << ")";

 		
 	}
 	return out;
 }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////