#include <bits/stdc++.h>

using namespace std;

bool isNumber(string str) {
    for (auto q: str) {
        if (!isdigit(q)) return false;
    }
    return true;
}

int main() {
    ifstream fin("quack.in");
    freopen("quack.out", "w", stdout);

    string currstring, temp;
    queue<long long> num;
    map<char, long long> reg;
    map<string, long long> labels;
    vector<string> prog;
    long long command = 0;
    long long a, b, pig;

    while (fin >> currstring) {
        prog.push_back(currstring);
        if (currstring[0] == ':') {
            temp = currstring.substr(1, currstring.size() - 1);
            labels[temp] = command;
        }
        command++;
    }


    for (long long i = 0; i < prog.size(); i++) {
        currstring = prog[i];

        if (isNumber(currstring)) {
            num.push(atoi(currstring.c_str()));
        } else {
            if (currstring[0] == '+') {
                a = num.front();
                num.pop();
                b = num.front();
                num.pop();
                pig = ((a + b) % 65536 + 65536) % 65536;
                num.push(pig);
            } else if (currstring[0] == '-') {
                a = num.front();
                num.pop();
                b = num.front();
                num.pop();
                pig = ((a - b) % 65536 + 65536) % 65536;
                num.push(pig);
            } else if (currstring[0] == '*') {
                a = num.front();
                num.pop();
                b = num.front();
                num.pop();
                pig = ((a * b) % 65536 + 65536) % 65536;
                num.push(pig);
            } else if (currstring[0] == '/') {
                a = num.front();
                num.pop();
                b = num.front();
                num.pop();
                if (b == 0) {
                    num.push(0);
                } else {
                    pig = (a / b) % 65536;
                    num.push(pig);
                }
            } else if (currstring[0] == '%') {
                a = num.front();
                num.pop();
                b = num.front();
                num.pop();
                if (b == 0) {
                    num.push(0);
                } else {
                    pig = (a % b) % 65536;
                    num.push(pig);
                }
            } else if (currstring[0] == '>') {
                a = num.front();
                num.pop();
                reg[currstring[1]] = a;
            } else if (currstring[0] == '<') {
                a = reg[currstring[1]];
                num.push(a);
            } else if (currstring[0] == 'P' && currstring.size() == 1) {
                a = num.front();
                num.pop();
                cout << a << endl;
            } else if (currstring[0] == 'P') {
                a = reg[currstring[1]];
                cout << a << endl;
            } else if (currstring[0] == 'C' && currstring.size() == 1) {
                a = num.front();
                num.pop();
                printf("%c", (a % 256));
            } else if (currstring[0] == 'C') {
                a = reg[currstring[1]];
                printf("%c", (a % 256));
            } else if (currstring[0] == 'J') {
                temp = currstring.substr(1, currstring.size() - 1);
                i = labels[temp];
            } else if (currstring[0] == 'Z') {
                if (reg[currstring[1]] == 0) {
                    temp = currstring.substr(2, currstring.size() - 2);
                    i = labels[temp];
                }
            } else if (currstring[0] == 'E') {
                if (reg[currstring[1]] == reg[currstring[2]]) {
                    temp = currstring.substr(3, currstring.size() - 3);
                    i = labels[temp];
                }
            } else if (currstring[0] == 'G') {
                if (reg[currstring[1]] > reg[currstring[2]]) {
                    temp = currstring.substr(3, currstring.size() - 3);
                    i = labels[temp];
                }
            } else if (currstring[0] == 'Q') {
                return 0;
            }


        }

    }

    return 0;
}