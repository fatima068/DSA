#include <iostream>
#include <string>
using namespace std;
#define SIZE 10

/*
key[] → stores keys
occupied[] → slot has ever been filled
deleted[] → slot was deleted
*/

// Linear PRobing
class HashLinear {
    string key[SIZE];
    bool occupied[SIZE];
    bool deleted[SIZE];

public:
    HashLinear() {
        for (int i = 0; i < SIZE; i++) {
            occupied[i] = false;
            deleted[i] = false;
        }
    }

    int hash(string k) {
        return k.length() % SIZE;
    }

    void insert(string k) {
        int index = hash(k);
        int start = index;

        while (occupied[index] && !deleted[index]) {
            index = (index + 1) % SIZE;
            if (index == start) return; // table full
        }

        key[index] = k;
        occupied[index] = true;
        deleted[index] = false;
    }

    bool search(string k) {
        int index = hash(k);
        int start = index;

        while (occupied[index]) {
            if (!deleted[index] && key[index] == k)
                return true;
            index = (index + 1) % SIZE;
            if (index == start) break;
        }
        return false;
    }

    void remove(string k) {
        int index = hash(k);
        int start = index;

        while (occupied[index]) {
            if (!deleted[index] && key[index] == k) {
                deleted[index] = true;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }
    }
};

//Quadratic Probing
class HashQuadratic {
    string key[SIZE];
    bool occupied[SIZE];
    bool deleted[SIZE];

public:
    HashQuadratic() {
        for (int i = 0; i < SIZE; i++) {
            occupied[i] = false;
            deleted[i] = false;
        }
    }

    int hash(string k) {
        return k.length() % SIZE;
    }

    void insert(string k) {
        int h = hash(k);
        int i = 1;

        int index = h;
        while (occupied[index] && !deleted[index]) {
            index = (h + i * i) % SIZE;
            i++;
            if (i == SIZE) return; // table full
        }

        key[index] = k;
        occupied[index] = true;
        deleted[index] = false;
    }

    bool search(string k) {
        int h = hash(k);
        int i = 1;
        int index = h;

        while (occupied[index]) {
            if (!deleted[index] && key[index] == k)
                return true;

            index = (h + i * i) % SIZE;
            i++;
            if (i == SIZE) break;
        }
        return false;
    }


    void remove(string k) {
        int h = hash(k);
        int i = 1;
        int index = h;

        while (occupied[index]) {
            if (!deleted[index] && key[index] == k) {
                deleted[index] = true;
                return;
            }

            index = (h + i * i) % SIZE;
            i++;
            if (i == SIZE) break;
        }
    }

};

// Double HAshing
class HashDouble {
    string key[SIZE];
    bool occupied[SIZE];
    bool deleted[SIZE];

public:
    HashDouble() {
        for (int i = 0; i < SIZE; i++) {
            occupied[i] = false;
            deleted[i] = false;
        }
    }

    int hash1(string k) {
        return k.length() % SIZE;
    }

    int hash2(string k) {
        return 7 - (k.length() % 7);
    }

    void insert(string k) {
        int h1 = hash1(k);
        int h2 = hash2(k);
        int i = 0;

        int index = h1;
        while (occupied[index] && !deleted[index]) {
            i++;
            index = (h1 + i * h2) % SIZE;
            if (i == SIZE) return; // table full
        }

        key[index] = k;
        occupied[index] = true;
        deleted[index] = false;
    }


    bool search(string k) {
        int h1 = hash1(k);
        int h2 = hash2(k);
        int i = 0;

        int index = h1;
        while (occupied[index]) {
            if (!deleted[index] && key[index] == k)
                return true;

            i++;
            index = (h1 + i * h2) % SIZE;
            if (i == SIZE) break;
        }
        return false;
    }


   void remove(string k) {
        int h1 = hash1(k);
        int h2 = hash2(k);
        int i = 0;

        int index = h1;
        while (occupied[index]) {
            if (!deleted[index] && key[index] == k) {
                deleted[index] = true;
                return;
            }

            i++;
            index = (h1 + i * h2) % SIZE;
            if (i == SIZE) break;
        }
    }
};