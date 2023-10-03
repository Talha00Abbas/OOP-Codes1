#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
#include "Record.h"

int main()
{
    char* fileName = new char[20];
    cout << "Enter File Name: ";
    cin >> fileName;
    Record record(fileName);

    while (true)
    {
        int choice;
        cout << endl << "Menu: " << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Display Records" << endl;
        cout << "3. Delete Record" << endl;
        cout << "4. Count Records" << endl;
        cout << "5. Search Record" << endl;
        cout << "6. Insert Record" << endl;
        cout << "7. Replace Record" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            record.record_Input();
            break;
        case 2:
            record.record_Display();
            break;
        case 3:
            record.delete_Record();
            break;
        case 4:
            cout << "Total Records: " << record.record_Count() << endl;
            break;
        case 5:
            record.record_Search();
            break;
        case 6:
            record.record_Insert();
            break;
        case 7:
            record.record_Replace();
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid Choice." << endl;
        }
    }

    return 0;
}
