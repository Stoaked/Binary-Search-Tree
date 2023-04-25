//Author:Ryan Byrnes Assignment 3 c3326903
//Course: Seng1120 Data Structores
//File: HTable.h

#ifndef RYAN_HTABLE
#define RYAN_HTABLE

#include <iostream>

#include <cstdlib>

#include <string>

using namespace std;
#define HASH_SIZE 5000 //defines the hash table size as 5000

template < typename T >
  class HTable {
    public:
      //constructor
      // Precondition: NIL
      // Postcondition: a new array is declared of the size of the hash. 
      HTable() {
        for (int i = 0; i < HASH_SIZE; i++) //will loop through the array and add an array to the hash tanle for the size of the hash table set at 5000
        {
          hashh[i] = 0;
        }
      }

      //destructor
      // Precondition: NIL
      // Postcondition: will set all the hash table data to NULL
      ~HTable() {
        for (int i = 0; i < HASH_SIZE; i++) {
          delete hashh[i];
          hashh[i] = NULL;
        }
      }


    //Getters, used to get and calculate inventory parts
    // Precondition: the hash tabnle is filled with values
    // Postcondition: Will calculate all the parts of the data
    int calculateParts() {
      int loop = 0;
      for (int i = 0; i < HASH_SIZE; i++) { //for loop for the size of the hash table
        if (hashh[i] != NULL) {  //if the hash table is not null
          loop++; //increment the loop
        }
      }
      return loop;
    }
    // Precondition: the hash tabnle is filled with values
    // Postcondition: Will calculate all the inventory of the data
    int calculateInventory() {
      int loop = 0;
      for (int i = 0; i < HASH_SIZE; i++) { //for loop for the size of the hash table

        if (hashh[i] != NULL) { //if the hash table is not set the null
          loop += hashh[i] -> get_quantity(); //will get the quantity of the hash location and add it to the loop counter
        }
      }
    }

    // Precondition: There is a hash table.
    // Postcondition: Will return the location of the data in the hash table.
    T & get(T & data) {
      int location = hashFunc(data); //will set the location to the hash table data
      return data[location]; //return the data and the location
    }

    // Precondition: There is a hash table.
    // Postcondition: Changed the data from null to the passed data at the generated location
    void add(const T & data) {
      int hashLocation = hashFunc(data);
      if (hashh[hashLocation] == NULL) {
        hashh[hashLocation] = new T(data);
      }
    }

    // Precondition: There is a hash table.
    // Postcondition: Will remove the data from the hash table
    void remove(T& data) {
      int hashLocation = hashFunc(data); //will set the hash location to the hash function
      if (hashh[hashLocation] == NULL) { //if the hash is NULL
        return; //return nothing
      } else {
        delete hashh[hashLocation]; //will delete the data out of the hash table
        hashh[hashLocation] = NULL;//set it to NULL
      }
    }

    //hash function provided for the assignment.
    int hashFunc(const T & data) {
      int position = 0;
      string temp = data.get_code();

      for (int i = 0; i < (int) temp.length(); i++) {
        position += (i + 1) * (i + 1) * temp.at(i);
      }
      return position % HASH_SIZE;
    }
    // Precondition: There is a hash table.
    // Postcondition: Will print the table out in a for loop, for each peice of data in the hash table
    ostream & printTable(ostream & out) {
      for (int i = 0; i < HASH_SIZE; i++) {
        if (hashh[i] != NULL) {
          out << " (" << hashh[i] -> get_code() << "," <<
            hashh[i] -> get_quantity() << ") ";
        }

      }
      return out;
    }
    //private member variables
    private:
      T* hashh[HASH_SIZE];
      T data;
  };
//Overload the << operator
template < typename T >
  ostream & operator << (ostream & out, HTable <T> & table) {
    table.printTable(out);
    return out;
  }

#endif


  void addHashTogether(const T& data, HTable<T>& table)
  {
    for(int i=0;i<hash_size;i++)
    {
        int hashLocation = hashFunc(data);
        if (hashh[hashLocation] == NULL) 
        {
        hashh[hashLocation] = new T(data);
        }
    }
  }