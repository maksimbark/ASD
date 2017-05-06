#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    string my;
    int i = 1, j = 0;
    fin >> my;
    vector<int> p(my.length());

    while (i < my.length()) {
        if (my[i] == my[j]) {
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

    for (int i = 1; i <= my.length(); ++i) {
        fout << p[i] << " ";
    }

    return 0;
}