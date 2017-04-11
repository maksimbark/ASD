#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;
unsigned long long maxdva = int(pow(2, 64));
vector<string> kitten;
struct oneWay {
    string key;
    vector<string> value;
    oneWay *parent;
    oneWay *child;
};

vector<oneWay *> table(10000000);

int getNum(string str) {
    unsigned long long answer = 0;
    for (int i = 0; i < str.length(); i++) {
        answer = (answer + int(str[i]) * int(pow(31, i))) % maxdva;
    }
    return (answer % 10000000);
}

//
void addInList(oneWay *current, string key, string value) {
    if (current->key == key) {
        bool flag = true;
        for (auto q: current->value) {
            if (q == value) flag = false;
        }
        if (flag) current->value.push_back(value);
    } else if (current->child == NULL) {
        oneWay *node = new(oneWay);
        node->key = key;
        node->value.push_back(value);
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
        node->value.push_back(value);
        node->parent = NULL;
        node->child = NULL;
        table[where] = node;
    } else {
        addInList(table[where], key, value);
    }
}

vector<string> &getValue(oneWay *where, string key) {
    if (where == NULL) {
        return kitten;
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

void miniKill(oneWay *where, string key, string value) {
    if (where != NULL) {

        if (where->key == key) {
            for (int i = 0; i < where->value.size(); i++) {
                if (where->value[i] == value) {
                    where->value.erase(where->value.begin()+i);
                }
        }
    } else miniKill(where->child, key, value);

}

}

int main() {
    ifstream fin("multimap.in");
    ofstream fout("multimap.out");
    string curr, now, key;
    int temp;
    while (fin >> curr) {
        fin >> now;
        if (curr == "put") {
            fin >> key;
            add(now, key);
        } else if (curr == "get") {
            temp = getNum(now);
            vector<string> &out = getValue(table[temp], now);
            fout << out.size() << " ";
            for (auto q: out) {
                fout << q << " ";
            }
            fout << endl;
        } else if (curr == "deleteall") {
            kill(table[getNum(now)], now);
        } else {
            fin >> key;
            miniKill(table[getNum(now)], now, key);
        }
    }
    return 0;
}