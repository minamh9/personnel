#include "HashTable.h"

HashTable::HashTable() : size(0), capacity(DEFAULT_CAPACITY)
{
    array = new Node * [DEFAULT_CAPACITY];
    for (int i = 0; i < capacity; i++)
        array[i] = NULL;
}

HashTable::HashTable(const HashTable& other) : size(other.size), capacity(other.capacity)
{
    array = new Node * [capacity];

 
    for (int i = 0; i < capacity; i++)
    {
        if (other.array[i] == NULL)
        {
            array[i] == NULL;
        }
        else
        {
            array[i] = new Node(other.array[i]->data);

            Node* currOther = other.array[i]->next;
            Node* curr = array[i];

            while (currOther)
            {
                curr->next = new Node(currOther->data);
                curr = curr->next;
                currOther = currOther->next;
            }
            currOther->next = NULL; 
        }
    }
}

HashTable& HashTable::operator=(const HashTable& other)
{
    if (this == &other)
        return *this;
    else
    {
        destroy();

        capacity = other.capacity;
        size = other.size;
        array = new Node * [capacity];

        for (int i = 0; i < capacity; i++)
        {
            if (other.array[i] == NULL)
            {
                array[i] == NULL;
            }
            else
            {
                array[i] = new Node(other.array[i]->data);

                Node* currOther = other.array[i]->next;
                Node* curr = array[i];

                while (currOther)
                {
                    curr->next = new Node(currOther->data);
                    curr= curr->next;
                    currOther = currOther->next;
                }
                currOther->next = NULL;
            }
        }
        return *this;
    }
}

HashTable::~HashTable()
{
    destroy();
}

void HashTable::destroy()
{
    for (int i = 0; i < capacity; i++)
    {
        Node* curr = array[i];
        Node* temp;
        while (curr)
        {
            temp = curr->next;
            curr->next = NULL;
            delete curr;
            curr = temp;
        }
    }

    delete[] array;
}

void HashTable::insert(const person prs)
{
    char* id = prs.getID();
    int index = hashFunction(id);

    Node* newNode = new Node(prs);

    if (!array[index])
    {
        size++;
    }

    newNode->next = array[index];
    array[index] = newNode;
}

int HashTable::hashFunction(char* id)
{
    int primeFactor = 5;

    char* ch;

    int hash = 6;
    //traverse 
    for (ch = id; *ch != '\0'; ch++)
    {
        //char to ascii 
        int asciiChar = (int)*ch;
        hash = hash * primeFactor + asciiChar;
    }

    hash = hash % capacity;

    return hash;
}

person* HashTable::search(char* searchID)
{
    int index = hashFunction(searchID);

    Node* head = array[index];
    char* currID;
    while (head)
    {
        currID = head->data.getID();
        if (strcmp(searchID, currID) == 0)
        {
   
            return &head->data;
        }
        else
            head = head->next;
    }
    return NULL;
}

int HashTable::getSize() const
{
    return size;
}

int HashTable::getCapacity() const
{
    return capacity;
}

