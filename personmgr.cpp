#include "personmgr.h"


const person* personmgr::findPerson(char* searchID)
{
    const person* pRet = hTable.search(searchID);
    return pRet;
}

void personmgr::addPerson(const person& prs)
{
    hTable.insert(prs);
}

void personmgr::printHtStats() const
{
    cout << "Table uses " << hTable.getSize() << " out of " << hTable.getCapacity() << " entries." << endl << endl;
}

