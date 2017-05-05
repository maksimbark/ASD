#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");
    long long n, from, where;

    fin >> n >> from >> where;
    --from;
    --where;
    vector<vector<long long>> matrix(n, vector<long long>(n));
    vector<long long> res(n, LLONG_MAX);
    vector<bool> visited(n, false);

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            fin >> matrix[i][j];
        }
    }

    res[from] = 0;
    bool flag = true;
    long long i;
    long long mini;
    while (flag) {
        visited[from] = true;
        i = 0;
        for (auto q: matrix[from]) {
            if (!visited[i] && q >= 0) {

                if (res[i] > q + res[from])
                    res[i] = q + res[from];

            }
            ++i;
        }
        flag = false;
        mini = LLONG_MAX;
        for (long long j = 0; j < n; ++j) {
            if (!visited[j] && res[j] < LLONG_MAX) {
                flag = true;
                if (res[j] < mini) {
                    mini = res[j];
                    from = j;
                }
            }
        }

    }

    if (res[where] != LLONG_MAX) {
        fout << res[where] <<
             endl;
    } else {
        fout << -1 <<
             endl;
    }

    return 0;
}