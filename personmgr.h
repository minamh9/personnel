#ifndef PERSONMGR_H
#define PERSONMGR_H

#include "HashTable.h"

class personmgr
{
public:
    void addPerson(const person& prs);
    const person* findPerson(char* searchID);
    void printHtStats()const;
  

private:
    HashTable hTable;

};

#endif
