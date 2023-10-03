#include <iostream>
#include <cstring>

class BinaryStore {
private:
    int len; // length of the binary store
    char** addresses; // array of char pointers to hold the addresses
    char** bytes; // array of char pointers to hold the bytes at corresponding addresses

public:
    BinaryStore() {
        len = 0;
        addresses = nullptr;
        bytes = nullptr;
    }

    BinaryStore(int len) {
        this->len = len;
        addresses = new char* [len];
        bytes = new char* [len];
        for (int i = 0; i < len; i++) {
            addresses[i] = nullptr;
            bytes[i] = nullptr;
        }
    }

    ~BinaryStore() {
        for (int i = 0; i < len; i++) {
            delete[] addresses[i];
            delete[] bytes[i];
        }
        delete[] addresses;
        delete[] bytes;
    }

    void add_Address(char* s) {
        for (int i = 0; i < len; i++) {
            if (addresses[i] == nullptr) {
                addresses[i] = new char[strlen(s) + 1];
                strcpy(addresses[i], s);
                return;
            }
        }
    }

    void set_Byte(char* address, char* value) {
        for (int i = 0; i < len; i++) {
            if (addresses[i] != nullptr && strcmp(addresses[i], address) == 0) {
                if (bytes[i] != nullptr) {
                    delete[] bytes[i];
                }
                bytes[i] = new char[strlen(value) + 1];
                strcpy(bytes[i], value);
                return;
            }
        }
        // if address not found, add address and byte
        add_Address(address);
        set_Byte(address, value);
    }

    char* Get(char* address) {
        for (int i = 0; i < len; i++) {
            if (addresses[i] != nullptr && strcmp(addresses[i], address) == 0) {
                return bytes[i];
            }
        }
        return nullptr;
    }

    char* ToString() {
        int size = 0;
        for (int i = 0; i < len; i++) {
            if (addresses[i] != nullptr) {
                size += strlen(addresses[i]) + strlen(bytes[i]) + 2;
            }
        }
        char* str = new char[size];
        str[0] = '\0';
        for (int i = 0; i < len; i++) {
            if (addresses[i] != nullptr) {
                strcat(str, addresses[i]);
                strcat(str, ":");
                strcat(str, bytes[i]);
                strcat(str, ",");
            }
        }
        return str;
    }

    char* Add(char* a, char* b) {
        // convert a and b to integers
        int x = 0;
        int y = 0;
        for (int i = 0; i < strlen(a); i++) {
            x = x * 2 + (a[i] - '0');
        }
        for (int i = 0; i < strlen(b); i++) {
            y = y * 2 + (b[i] - '0');
        }
        int sum = x + y;

        // convert sum back to binary string
        char* result = new char[33]; // 32 bits + null terminator
        int i = 31;
        while (sum > 0) {
            result[i--] = (sum % 2) + '0';
            sum /= 2;
        }
        while (i >= 0) {
            result[i--] = '0';
        }
        return result;
    }

    bool comp_EQUAL(char* a, char* b) {
        if (strlen(a) != strlen(b)) {
            return false;
        }
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    char* comp_AND(char* a, char* b) {
        char* result = new char[strlen(a) + 1];
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] == '1' && b[i] == '1') {
                result[i] = '1';
            }
            else {
                result[i] = '0';
            }
        }
        result[strlen(a)] = '\0';
        return result;
    }

    char* comp_OR(char* a, char* b) {
        char* result = new char[strlen(a) + 1];
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] == '1' || b[i] == '1') {
                result[i] = '1';
            }
            else {
                result[i] = '0';
            }
        }
        result[strlen(a)] = '\0';
        return result;
    }

    char* comp_NOT(char* a) {
        char* result = new char[strlen(a) + 1];
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] == '1') {
                result[i] = '0';
            }
            else {
                result[i] = '1';
            }
        }
        result[strlen(a)] = '\0';
        return result;
    }
};