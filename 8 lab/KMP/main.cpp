#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("search2.in");
    ofstream fout("search2.out");
    string what;
    string where;
    vector<int> meow;
    int size;
    int i = 1, j = 0;
    fin >> what;
    size = what.length();
    fin >> where;
    what += "@";
    what += where;

    vector<int> p(what.length()+1);

    while (i < what.length()) {
        if (what[i] == what[j]) {
            p[i + 1] = j + 1;
            ++j;
            ++i;
        } else {
            if (j > 0)
                j = p[j];
            else {
                ++i;
            }

        }
    }

    for (int i = 1 + size; i <= what.length(); ++i) {
        if (size == p[i]) {
                meow.push_back(i - 2 * size);
        }
    }
    fout << meow.size() << endl;
    for (auto q: meow) {
        fout << q << " ";
    }

    return 0;
}