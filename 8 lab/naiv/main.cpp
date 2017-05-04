#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("search1.in");
    ofstream fout("search1.out");
    vector<int> answer;

    string where, find;
    fin >> find >> where;
    int n = find.length();

    vector<char> temp;
    vector<char> findvec;

    for (auto q: find)
        findvec.push_back(q);
    for (int i = 0; i < n; ++i) {
        temp.push_back(where[i]);
    }

    int i = 1;

    while (n <= where.length()) {
        if (temp == findvec)
            answer.push_back(i);
        ++i;
        temp.erase(temp.begin());
        temp.push_back(where[n]);
        ++n;
    }

    fout << answer.size() << endl;
    for (auto q: answer)
        fout << q << " ";

    return 0;
}