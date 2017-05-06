#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");
    long long n, m, from, where, how;
    pair<long long, long long> temp;
    priority_queue<pair<long long, long long>> dej;
    fin >> n >> m;
    vector<vector<pair<long long, long long>>> graph(n + 1);
    vector<bool> visited(n + 1);
    vector<long long> path(n + 1, LLONG_MAX);
    path[1] = 0;
    for (long long i = 0; i < m; ++i) {
        fin >> from >> where >> how;
        temp.first = where;
        temp.second = how;
        graph[from].push_back(temp);
        temp.first = from;
        graph[where].push_back(temp);
    }
    temp.first = 0;
    temp.second = 1;
    dej.push(temp);
    while (dej.size() != 0) {
        from = dej.top().second;
        visited[from] = true;
        dej.pop();
        for (auto q: graph[from]) {
            if (!visited[q.first] && (path[q.first] > path[from] + q.second) && path[from] != LLONG_MAX &&
                q.second != LLONG_MAX) {
                path[q.first] = path[from] + q.second;
                temp.first = -1 * path[q.first];
                temp.second = q.first;
                dej.push(temp);
            }
        }
    }

    for (long long i = 1; i <= n; ++i) {
        fout << path[i] << " ";
    }
    return 0;
}
