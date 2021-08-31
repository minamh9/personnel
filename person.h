#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class person
{
public:
    person();
    person(char* initID, char* initFirstName, char* initLastName, char* initFamilyID);

    ~person();

    person(const person& other);
    void operator=(const person& other);

    char* getID() const;
    char* getFirstName() const;
    char* getLastName() const;
    char* getFamilyID() const;
    void setID(char* newID);
    void setFirstName(char* newFirstName);
    void setLastName(char* newLastName);
    void setFamilyID(char* newFamilyID);

    void print() const;

private:
    char* ID;
    char* firstName;
    char* lastName;
    char* familyID;


};

#endif
