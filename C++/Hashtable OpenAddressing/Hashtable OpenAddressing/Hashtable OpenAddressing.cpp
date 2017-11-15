// Hashtable OpenAddressing.cpp : Defines the entry point for the console application.
//
//All Rights Reseverd by Programmer SMAli KSS
//F_Name: Seyed Mohammad ali, L_Name: Kazemi Sheikh Shabani
//Student ID: 92222004
//Problem Hashtable open addressing name to number

#include "stdafx.h"
#include <iostream>

using namespace std;

class HashEntry {
private:
	  char name;
      int number;
public:
      HashEntry(int key, char value) {
		  this->number = key;
		  this->name = value;
      }
 
      int getKey() {
		  return number;
      }
 
      int getValue() {
		  return name;
      }
 
      void setValue(char value) {
		  this->name = value;
      }
};
 
class DeletedEntry: public HashEntry {
private:
      static DeletedEntry *entry;
      DeletedEntry() :
            HashEntry(-1, -1) {
      }
public:
      static DeletedEntry *getUniqueDeletedEntry() {
            if (entry == NULL)
                  entry = new DeletedEntry();
            return entry;
      }
};
 
DeletedEntry *DeletedEntry::entry = NULL;
 
const int TABLE_SIZE = 128;
 
class HashMap {
private:
      HashEntry **table;
public:
      HashMap() {
            table = new HashEntry*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL;
      }
 
      int get(int key) {
            int hash = (key % TABLE_SIZE);
            int initialHash = -1;
            while (hash != initialHash && (table[hash]
                        == DeletedEntry::getUniqueDeletedEntry() || table[hash] != NULL
                        && table[hash]->getKey() != key)) {
                  if (initialHash == -1)
                        initialHash = hash;
                  hash = (hash + 1) % TABLE_SIZE;
            }
            if (table[hash] == NULL || hash == initialHash)
                  return -1;
            else
                  return table[hash]->getValue();
      }
 
      void put(int key, int value) {
            int hash = (key % TABLE_SIZE);
            int initialHash = -1;
            int indexOfDeletedEntry = -1;
            while (hash != initialHash && (table[hash]
                        == DeletedEntry::getUniqueDeletedEntry() || table[hash] != NULL
                        && table[hash]->getKey() != key)) {
                  if (initialHash == -1)
                        initialHash = hash;
                  if (table[hash] == DeletedEntry::getUniqueDeletedEntry())
                        indexOfDeletedEntry = hash;
                  hash = (hash + 1) % TABLE_SIZE;
            }
            if ((table[hash] == NULL || hash == initialHash) && indexOfDeletedEntry
                        != -1)
                  table[indexOfDeletedEntry] = new HashEntry(key, value);
            else if (initialHash != hash)
                  if (table[hash] != DeletedEntry::getUniqueDeletedEntry()
                             && table[hash] != NULL && table[hash]->getKey() == key)
                        table[hash]->setValue(value);
                  else
                        table[hash] = new HashEntry(key, value);
      }
 
      void remove(int key) {
            int hash = (key % TABLE_SIZE);
            int initialHash = -1;
            while (hash != initialHash && (table[hash]
                        == DeletedEntry::getUniqueDeletedEntry() || table[hash] != NULL
                        && table[hash]->getKey() != key)) {
                  if (initialHash == -1)
                        initialHash = hash;
                  hash = (hash + 1) % TABLE_SIZE;
            }
            if (hash != initialHash && table[hash] != NULL) {
                  delete table[hash];
                  table[hash] = DeletedEntry::getUniqueDeletedEntry();
            }
      }
 
      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL && table[i]
                             != DeletedEntry::getUniqueDeletedEntry())
                        delete table[i];
            delete[] table;
      }
};

int _tmain(int argc, _TCHAR* argv[])
{	
	return 0;
}