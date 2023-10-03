#pragma once
#include <cstddef>
#include <iostream>
using namespace std;

struct ZooCage
{
    char* name;
    int cageNumber;

    /*
    In the ZooCage structure, the link member is a pointer to the next ZooCage instance in the chain.
    This creates a linked list data structure where each ZooCage instance is connected to the next ZooCage instance in the chain via the link pointer.
    For example, consider a chain of ZooCage instances containing three ZooCage instances with cageNumber values of 1, 2, and 3, respectively.
    The link pointer of the ZooCage instance with cageNumber 1 would point to the ZooCage instance with cageNumber 2,
    and the link pointer of the ZooCage instance with cageNumber 2 would point to the ZooCage instance with cageNumber 3.
    The link pointer of the ZooCage instance with cageNumber 3 would be NULL since it is the last ZooCage instance in the chain.
    This linked list structure allows for efficient traversaland manipulation of the chain of ZooCage instances.
    */
    ZooCage* link;      // using it to create a linked list
};

class ZooChain {
public:
    ZooCage* start;

    // Default constructor
    ZooChain() 
    {
        start = NULL;
    }

    // This member function will take the name and cageNumber of Animal as input parameter.
    // It creates the ZooCage instance. If the new Zoocage instance is the first in the chain
    // then the pointer “start“ will point to it. Otherwise a new instance is attached at the
    // end of the existing chain.
    void add_Cage(char* name, int cageNumber) {

        // sets the attributes of the cage
        ZooCage* newCage = new ZooCage;
        newCage->name = new char[strlen(name) + 1];
        strcpy(newCage->name, name);
        newCage->cageNumber = cageNumber;
        newCage->link = NULL;

        //cehcks if the cage is first or not
        if (start == NULL) {
            start = newCage;
        }
        else {
            // Not the first one. Takes the start number then check where to put the cage info. First Null location will be preffered
            ZooCage* temp = start;
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = newCage;
        }
    }

    // It prints all the animals with their cage number in the chain.
    void print_Chain() {
        if (start == NULL) {
            cout << "ZooChain is empty." << endl;
            return;
        }
        ZooCage* temp = start;
        while (temp != NULL) {
            cout << "Animal Name: " << temp->name << " | Cage Number: " << temp->cageNumber << endl;
            temp = temp->link;
        }
    }

    // This member function will take the cageNumber of Animal as input parameter.
    // It deletes the mentioned cageNumber from the chain of ZooCage instances.
    // And rejoins the remaining chain.
    void delete_Chain(int cageNumber) {
        if (start == NULL) {
            cout << "ZooChain is empty." << endl;
            return;
        }
        ZooCage* temp = start;
        ZooCage* prev = NULL;
        while (temp != NULL && temp->cageNumber != cageNumber) {
            prev = temp;
            temp = temp->link;
        }
        if (temp == NULL) {
            cout << "Animal with Cage Number " << cageNumber << " not found in ZooChain." << endl;
            return;
        }
        if (prev == NULL) {
            start = temp->link;
        }
        else {
            prev->link = temp->link;
        }
        delete temp;
        cout << "Animal with Cage Number " << cageNumber << " has been removed from ZooChain." << endl;
    }

    // It sorts all the elements in the chain based upon their cageNumber.
    void Sort_Chain() {
        
        //checks if its empty
        if (start == NULL) {
            cout << "ZooChain is empty." << endl;
            return;
        }


        bool swapped = true;
        ZooCage* ptr1;
        ZooCage* lptr = NULL;
        while (swapped) {
            swapped = false;
            ptr1 = start;
            while (ptr1->link != lptr) {
                if (ptr1->cageNumber > ptr1->link->cageNumber) {
                    swap(ptr1->cageNumber, ptr1->link->cageNumber);
                    swap(ptr1->name, ptr1->link->name);
                    swapped = true;
                }
                ptr1 = ptr1->link;
            }
            lptr = ptr1;
        }
        cout << "ZooChain has been sorted based on cage numbers." << endl;
    }

    // It updates the name of an animal at a particular cage number.
    void update_name_at_cageNumber(int cageNumber, char* name) {
        if (start == NULL) {
            cout << "ZooChain is empty." << endl;
            return;
        }
        ZooCage* temp = start;
        while (temp != NULL && temp->cageNumber != cageNumber) {
            temp = temp->link;
        }
        if (temp == NULL) {
            cout << "Animal with Cage Number " << cageNumber << " not found in ZooChain." << endl;
            return;
        }
        delete[] temp->name;
        temp->name = new char[strlen(name) + 1];
        strcpy(temp->name, name);
        cout << "Animal with Cage Number " << cageNumber << " has been updated with the new name '" << name << "'." << endl;
    }

    // It removes all the duplicates in the chain.
    void remove_Duplicate() {
        if (start == NULL) {
            cout << "ZooChain is empty." << endl;
            return;
        }
        ZooCage* ptr1;
        ZooCage* ptr2;
        ZooCage* dup;
        ptr1 = start;

        while (ptr1 != NULL && ptr1->link != NULL) {
            ptr2 = ptr1;
            while (ptr2->link != NULL) {
                if (ptr1->cageNumber == ptr2->link->cageNumber) {
                    dup = ptr2->link;
                    ptr2->link = ptr2->link->link;
                    delete dup;
                }
                else {
                    ptr2 = ptr2->link;
                }
            }
            ptr1 = ptr1->link;
        }
        cout << "All duplicates have been removed from ZooChain." << endl;
    }

    // Destructor to deallocate memory.
    ~ZooChain() {
        while (start != NULL) {
            ZooCage* temp = start;
            start = start->link;
            delete[] temp->name;
            delete temp;
        }
    }

  /*  ZooChain();

    void add_Cage(char* name, int cageNumber);

    void print_Chain();

    void delete_Chain(int cageNumber);

    void Sort_Chain();

    void update_name_at_cageNumber(int cageNumber, char* name);

    void remove_Duplicate();

    ~ZooChain();*/

};