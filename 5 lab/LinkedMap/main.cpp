#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;
unsigned long long maxdva = int(pow(2, 64));
vector<string> operations;
vector<bool> aliveStatus;
int crutch;
struct oneWay {
    string key;
    string value;
    oneWay *parent;
    oneWay *child;
    int addedTime;
};

vector<oneWay *> table(10000000);

int getNum(string str) {
    unsigned long long answer = 0;
    for (int i = 0; i < str.length(); i++) {
        answer = (answer + int(str[i]) * int(pow(31, i))) % maxdva;
    }
    return (answer % 10000000);
}

void addInList(oneWay *current, string key, string value, int time) {
    if (current->key == key) {
        current->value = value;
    } else if (current->child == NULL) {
        oneWay *node = new(oneWay);
        node->key = key;
        node->value = value;
        node->parent = current;
        node->child = NULL;
        node->addedTime = time;
        current->child = node;
    } else {
        addInList(current->child, key, value, time);
    }
}

void add(string key, string value, int time) {
    int where = getNum(key);
    if (table[where] == NULL) {
        oneWay *node = new(oneWay);
        node->key = key;
        node->value = value;
        node->parent = NULL;
        node->child = NULL;
        node->addedTime = time;
        table[where] = node;
    } else {
        addInList(table[where], key, value, time);
    }
}

string getValue(oneWay *where, string key) {
    if (where == NULL) {
        return "none";
    } else if (where->key == key) {
        crutch = where->addedTime;
        return (where->value);
    } else return (getValue(where->child, key));
}

void kill(oneWay *where, string key) {
    if (where != NULL) {

        if (where->key == key) {
            if ((where->parent == NULL) && (where->child == NULL)) {
                aliveStatus[where->addedTime] = false;
                free(where);
                table[getNum(key)] = NULL;
            } else if (where->parent == NULL) {
                where->child->parent = NULL;
                table[getNum(key)] = where->child;
                aliveStatus[where->addedTime] = false;
                free(where);
            } else if (where->child == NULL) {
                where->parent->child = NULL;
                aliveStatus[where->addedTime] = false;
                free(where);
            } else {
                where->parent->child = where->child;
                where->child->parent = where->parent;
                aliveStatus[where->addedTime] = false;
                free(where);
            }
        } else kill(where->child, key);

    }
}

int main() {
    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");

    string curr, now, key;
    int time = 0, temp;

    while (fin >> curr) {

        fin >> now;
        if (curr == "put") {
            fin >> key;
            if (getValue(table[getNum(now)], now) == "none") {
                operations.push_back(now);
                aliveStatus.push_back(true);
            } else {
                operations.push_back("0");
                aliveStatus.push_back(false);
            }

            add(now, key, time);
            time++;

        } else if (curr == "get") {
            temp = getNum(now);
            fout << getValue(table[temp], now) << endl;
        } else if (curr == "delete") {
            kill(table[getNum(now)], now);
        } else if (curr == "prev") {
            bool flag = true;
            temp = getNum(now);
            if (getValue(table[temp], now) == "none") {
                fout << "none" << endl;
            } else {
                for (int i = crutch-1; i >= 0; i--) {
                    if (aliveStatus[i] == true) {
                        fout << getValue(table[getNum(operations[i])], operations[i]) << endl;
                        flag = false;
                        break;
                    }
                }
                if (flag) fout << "none" << endl;
            }
        } else { //next
            bool flag = true;
            temp = getNum(now);
            if (getValue(table[temp], now) == "none") {
                fout << "none" << endl;
            } else {
                for (int i = crutch+1; i < aliveStatus.size(); i++) {
                    if (aliveStatus[i] == true) {
                        fout << getValue(table[getNum(operations[i])], operations[i]) << endl;
                        flag = false;
                        break;
                    }
                }
                if (flag) fout << "none" << endl;
            }
        }
    }

    return 0;
}