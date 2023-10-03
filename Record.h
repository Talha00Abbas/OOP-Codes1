#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

class Record
{
private:
    char* fileName;
public:
    Record(char* str)
    {
        fileName = str;
        ofstream outfile(fileName, ios::app);
        outfile.close();
    }

    int record_Input()
    {
        string name, address;
        int age;
        double cgpa;
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Address: ";
        //getline(cin, address);
        cin >> address;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter CGPA: ";
        cin >> cgpa;

        ofstream outfile(fileName, ios::app);
        outfile << name << "," << address << "," << age << "," << cgpa << endl;
        outfile.close();
        return 0;
    }

    void record_Display()
    {
        ifstream infile(fileName);
        string line;
        while (getline(infile, line))
        {
            cout << line << endl;
        }
        infile.close();
    }

    int delete_Record()
    {
        string name;
        cout << "Enter Name to Delete: ";
        cin.ignore();
        getline(cin, name);

        ifstream infile(fileName);
        ofstream outfile("temp.txt", ios::out);

        string line;
        int found = 0;
        while (getline(infile, line))
        {
            if (line.find(name) == string::npos)
            {
                outfile << line << endl;
            }
            else
            {
                found = 1;
            }
        }
        infile.close();
        outfile.close();
        if (found)
        {
            remove(fileName);
            rename("temp.txt", fileName);
            return 0;
        }
        else
        {
            cout << "Record not found." << endl;
            return -1;
        }
    }

    int record_Count()
    {
        ifstream infile(fileName);
        int count = 0;
        string line;
        while (getline(infile, line))
        {
            count++;
        }
        infile.close();
        return count;
    }

    int record_Search()
    {
        string name;
        cout << "Enter Name to Search: ";
        cin.ignore();
        getline(cin, name);

        ifstream infile(fileName);
        string line;
        int found = 0;
        while (getline(infile, line))
        {
            if (line.find(name) != string::npos)
            {
                cout << line << endl;
                found = 1;
            }
        }
        infile.close();
        if (!found)
        {
            cout << "Record not found." << endl;
            return -1;
        }
        return 0;
    }

    int record_Insert()
    {
        string name, address;
        int age;
        double cgpa;
        string newRecord;

        cout << "Enter Name after which you want to insert new record: ";
        cin.ignore();
        getline(cin, name);

        ifstream infile(fileName);
        ofstream outfile("temp.txt", ios::out);
        string line;
        int found = 0;
        while (getline(infile, line))
        {
            if (line.find(name) != string::npos)
            {
                found = 1;
                outfile << line << endl;
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Address: ";
                getline(cin, address);
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter CGPA: ";
                cin >> cgpa;
                newRecord = name + "," + address + "," + to_string(age) + "," + to_string(cgpa);
                outfile << newRecord << endl;
            }
            else
            {
                outfile << line << endl;
            }
        }
        infile.close();
        outfile.close();
        if (found)
        {
            remove(fileName);
            rename("temp.txt", fileName);
            return 0;
        }
        else
        {
            cout << "Record not found." << endl;
            return -1;
        }
    }

    void record_Replace()
    {
        string name;
        cout << "Enter Name to Replace: ";
        cin.ignore();
        getline(cin, name);

        ifstream infile(fileName);
        ofstream outfile("temp.txt", ios::out);
        string line;
        int found = 0;
        while (getline(infile, line))
        {
            if (line.find(name) != string::npos)
            {
                found = 1;
                string newRecord;
                string address;
                int age;
                double cgpa;
                cout << "Enter new Name: ";
                getline(cin, name);
                cout << "Enter new Address: ";
                getline(cin, address);
                cout << "Enter new Age: ";
                cin >> age;
                cout << "Enter new CGPA: ";
                cin >> cgpa;
                newRecord = name + "," + address + "," + to_string(age) + "," + to_string(cgpa);
                outfile << newRecord << endl;
            }
            else
            {
                outfile << line << endl;
            }
        }
        infile.close();
        outfile.close();
        if (found)
        {
            remove(fileName);
            rename("temp.txt", fileName);
        }
        else
        {
            cout << "Record not found." << endl;
        }
    }

    ~Record()
    {
        delete[] fileName;
    }
};