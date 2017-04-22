#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
unsigned long long maxdva = int(pow(2,64));
struct oneWay {
    int key;
    oneWay *parent;
    oneWay *child;
};

vector<oneWay *> table(10000000);

int getNum(int str) {
    return abs(str % 10000000);
}

void addInList(oneWay *current, int key) {
    if (current->key == key) {
        return;
    } else if (current->child == NULL) {
        oneWay *node = new(oneWay);
        node->key = key;
        node->parent = current;
        node->child = NULL;
        current->child = node;
    } else {
        addInList(current->child, key);
    }
}

void add(int key) {
    int where = getNum(key);
    if (table[where] == NULL) {
        oneWay *node = new(oneWay);
        node->key = key;
        node->parent = NULL;
        node->child = NULL;
        table[where] = node;
    } else {
        addInList(table[where], key);
    }
}

string getValue(oneWay *where, int key) {
    if (where == NULL) {
        return "false";
    } else if (where->key == key) {
        return "true";
    } else return (getValue(where->child, key));
}

void kill(oneWay *where, int key) {
    if (where != NULL) {

        if (where->key == key) {
            if ((where->parent == NULL) && (where->child == NULL)) {
                free(where);
                table[getNum(key)] = NULL;
            } else if (where->parent == NULL) {
                where->child->parent = NULL;
                table[getNum(key)] = where->child;
                free(where);
            } else if (where->child == NULL) {
                where->parent->child = NULL;
                free(where);
            } else {
                where->parent->child = where->child;
                where->child->parent = where->parent;
                free(where);
            }
        } else kill(where->child, key);

    }
}

int main() {
    ifstream fin("set.in");
    ofstream fout("set.out");
    string curr;
    int now;
    int temp;
    while (fin >> curr) {
        fin >> now;
        if (curr == "insert") {
            add(now);
        } else if (curr == "exists") {
            temp = getNum(now);
            if (getValue(table[temp], now) == "false") {
                fout << "false" << endl;
            } else {
                fout << "true" << endl;
            }
        } else {
            kill(table[getNum(now)], now);
        }
    }
    return 0;
}