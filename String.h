#include <iostream>
#include <cstring>

using namespace std;

class String {
    char* data;
    int len; // to store the length of string
public:
    // default constructor
    String() {
        data = new char[1];
        data[0] = '\0';
        len = 0;
    }

    // constructor to initialize the string with constant cstring
    String(const char* str) {
        len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);
    }

    // copy constructor to initialize the string from existing string
    String(const String& str) {
        len = str.len;
        data = new char[len + 1];
        strcpy(data, str.data);
    }

    // initializes a string of pre-defined size
    String(int x) {
        data = new char[x + 1];
        for (int i = 0; i < x; i++)
            data[i] = '\0';
        len = strlen(data);
    }

    // returns a pointer to the string data
    char* getdata() {
        return data;
    }

    // returns the character at index [x] in a string
    char getChar(int i) {
        if (i < 0 || i >= len) {
            std::cerr << "Index out of bounds" << std::endl;
            return '\0';
        }
        return data[i];
    }

    // returns true if string is empty
    bool isEmpty() {
        if (len <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // appends a String at the end of the String
    String append_string(const String& str) {
        
        int newLen = len + str.len;
        char* newData = new char[newLen + 1];
        strcpy(newData, data);
        strcat(newData, str.data);
        this->data = newData;
        //delete[] newData;
        return this->data;
    }

    // appends a char at the end of the String
    String append_string(const char& ch) {
        int newLen = len + 3;
        cout << "\n newLen is : " << newLen << endl;

        char* newData = new char[newLen + 1];
        strcpy(newData, data);
        newData[len] = ch;
        newData[newLen] = '\0';
        this->data = newData;
        //delete[] newData;
        return this->data;
    }

    // appends a c-string at the end of the String
    String append_string(char*& str) {
        String temp(str);
        String res;
        //res = append_string(temp);
        return res;
    }

    // appends a string at the end of the String
    String append_string(string& str) {
        String temp(str.c_str());
        String res;
        //res = append_string(temp);
        return res;
    }

    String remove_string(const String& substr) {
        char* result = strstr(data, substr.data);
        if (result == nullptr) {
            return *this;
        }
        int pos = result - data;
        String newString(data);
        newString.len -= substr.len;
        for (int i = pos; i < newString.len; i++) {
            newString.data[i] = newString.data[i + substr.len];
        }
        newString.data[newString.len] = '\0';

        for (int i = 0; i < (newString.len); i++)
        {
            data[i] = newString.data[i];
        }
        data[len - 1] = '\0';
        len -= 1;

        cout << "\n\n This string is : " << this->data << endl << endl;
        return this->data;
    }

    String remove_string(const string& substr) {
        String temp(substr.c_str());
        return remove_string(temp);
    }

    String remove_string(const char*& substr) {
        String temp(substr);
        return remove_string(temp);
    }

    String remove_string(const char& ch) {
        int pos = -1;
        for (int i = 0; i < len; i++) {
            if (data[i] == ch || data[i] == ' ') {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            return *this;
        }
        String newString(data);
        newString.len--;
        for (int i = pos; i < newString.len; i++) {
            newString.data[i] = newString.data[i + 1];
        }
        newString.data[newString.len] = '\0';

        for (int i = 0; i < (newString.len); i++)
        {
            data[i] = newString.data[i];
        }
        data[len-1] = '\0';
        len -= 1;
        return this->data;
    }

    String& assign_string(const String& str) {
        if (this == &str) {
            return *this;
        }
        delete[] data;
        len = str.len;
        data = new char[len + 1];
        strcpy(data, str.data);
        return *this;
    }

    String& assign_string(char* str) {
        String temp(str);
        return assign_string(temp);
    }

    String& assign_string(const std::string& str) {
        String temp(str.c_str());
        return assign_string(temp);
    }

    bool isEqual(const String& str) const {
        return strcmp(data, str.data) == 0;
    }

    bool isEqual(const string& str) const {
        String temp(str.c_str());
        return isEqual(temp);
    }

    bool isEqual(char* str) const {
        String temp(str);
        return isEqual(temp);
    }

    int index_at(char ch) const {
        for (int i = 0; i < len; i++) {
            if (data[i] == ch) {
                return i;
            }
        }
        return -1;
    }

    int index_at(const String& str) const {
        char* result = strstr(data, str.data);
        if (result == nullptr) {
            return -1;
        }
        return result - data;
    }

    int index_at(const std::string& str) const {
        String temp(str.c_str());
        return index_at(temp);
    }

    int index_at(char* str) const {
        String temp(str);
        return index_at(temp);
    }

    int length() {
        return len;
    }

    ~String() {
        delete[] data;
    }
};