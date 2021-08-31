#include "person.h"

person::person()
{
    ID = NULL;
    firstName = NULL;
    lastName = NULL;
    familyID = NULL;
}

person::person(char* initID, char* initFirstName, char* initLastName, char* initFamilyID)
{
    ID = new char[strlen(initID) + 1];
    firstName = new char[strlen(initFirstName) + 1];
    lastName = new char[strlen(initLastName) + 1];
    familyID = new char[strlen(initFamilyID) + 1];

    strcpy(ID, initID);
    strcpy(firstName, initFirstName);
    strcpy(lastName, initLastName);
    strcpy(familyID, initFamilyID);
}

person::person(const person& other)
{
    ID = new char[strlen(other.getID()) + 1];
    strcpy(ID, other.getID());
    firstName = new char[strlen(other.getFirstName()) + 1];
    strcpy(firstName, other.getFirstName());
    lastName = new char[strlen(other.getLastName()) + 1];
    strcpy(lastName, other.getLastName());
    familyID = new char[strlen(other.getFamilyID()) + 1];
    strcpy(familyID, other.getFamilyID());
}

void person::operator=(const person& other)
{
    if (ID)
        delete[] ID;
    if (firstName)
        delete[] firstName;
    if (lastName)
        delete[] lastName;
    if (familyID)
        delete[] familyID;

    ID = new char[strlen(other.getID()) + 1];
    strcpy(ID, other.getID());
    firstName = new char[strlen(other.getFirstName()) + 1];
    strcpy(firstName, other.getFirstName());
    lastName = new char[strlen(other.getLastName()) + 1];
    strcpy(lastName, other.getLastName());
    familyID = new char[strlen(other.getFamilyID()) + 1];
    strcpy(familyID, other.getFamilyID());
}

person::~person()
{
    delete[] ID;
    delete[] firstName;
    delete[] lastName;
    delete[] familyID;
}

char* person::getID() const
{
    return ID;
}
char* person::getFirstName() const
{
    return firstName;
}
char* person::getLastName() const
{
    return lastName;
}
char* person::getFamilyID() const
{
    return familyID;
}

void person::setID(char* newID)
{
    strcpy(ID, newID);
}
void person::setFirstName(char* newFirstName)
{
    strcpy(firstName, newFirstName);
}
void person::setLastName(char* newLastName)
{
    strcpy(lastName, newLastName);
}
void person::setFamilyID(char* newFamilyID)
{
    strcpy(familyID, newFamilyID);
}

void person::print() const
{
    cout << "ID: " << ID << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << endl;
}