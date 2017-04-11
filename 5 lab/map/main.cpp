#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
unsigned long long maxdva = int(pow(2,64));
struct oneWay {
    string key;
    string value;
    oneWay *parent;
    oneWay *child;
};

vector<oneWay *> table(10000000);

int getNum(string str) {
/*
    int answer = 0;
    answer += int(str[0]);
    answer += 1000 * int(str[str.length() - 1]);
    answer += 10000 * int(str[(str.length() - 1) / 2]);
    return (answer % 10000000);
    */


    unsigned long long answer = 0;
    for (int i = 0; i < str.length(); i++) {
        answer = (answer + int(str[i]) * int(pow(31, i))) % maxdva;
    }

    return (answer % 10000000);
}

void addInList(oneWay *current, string key, string value) {
    if (current->key == key) {
        current->value = value;
    } else if (current->child == NULL) {
        oneWay *node = new(oneWay);
        node->key = key;
        node->value = value;
        node->parent = current;
        node->child = NULL;
        current->child = node;
    } else {
        addInList(current->child, key, value);
    }
}

void add(string key, string value) {
    int where = getNum(key);
    if (table[where] == NULL) {
        oneWay *node = new(oneWay);
        node->key = key;
        node->value = value;
        node->parent = NULL;
        node->child = NULL;
        table[where] = node;
    } else {
        addInList(table[where], key, value);
    }
}

string getValue(oneWay *where, string key) {
    if (where == NULL) {
        return "none";
    } else if (where->key == key) {
        return (where->value);
    } else return (getValue(where->child, key));
}

void kill(oneWay *where, string key) {
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
    ifstream fin("map.in");
    ofstream fout("map.out");
    string curr, now, key;
    int temp;
    while (fin >> curr) {
        fin >> now;
        if (curr == "put") {
            fin >> key;
            add(now, key);
        } else if (curr == "get") {
            temp = getNum(now);
            fout << getValue(table[temp], now) << endl;
        } else {
            kill(table[getNum(now)], now);
        }
    }
    return 0;
}