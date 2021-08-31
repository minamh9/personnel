#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "person.h"

class HashTable
{
public:
    HashTable();

    HashTable(const HashTable& other);
    HashTable& operator=(const HashTable& other);

    ~HashTable();
    void destroy();

    //functions for the hashtable
    int hashFunction(char* id);
    void insert(const person p);
    person* search(char* searchID);
    int getSize() const;
    int getCapacity() const;
    

private:
    struct Node
    {
        person data;
        Node* next;
        Node(const person& prs) : data(prs), next(NULL)
        {
        }
    };
    Node** array;
    const static int DEFAULT_CAPACITY = 9973;
    int capacity;
    int size;
};

#endif
