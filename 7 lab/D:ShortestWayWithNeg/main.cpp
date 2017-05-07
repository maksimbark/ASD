#include <bits/stdc++.h>

using namespace std;

int main() {
    long long inf = 6000000000000000000;

    ifstream fin("path.in");
    ofstream fout("path.out");

    long long n, m, from, where, how, s;
    pair<long long, long long> temp;
    fin >> n >> m >> s;
    vector<vector<pair<long long, long long>>> graph(n + 1);
    vector<long long> distance(n + 1, inf);
    vector<long long> way(n + 1);
    vector<bool> isNeg(n + 1);
    for (long long i = 0; i < m; ++i) {
        fin >> from >> where >> how;
        temp.first = where;
        temp.second = how;
        graph[from].push_back(temp);
    }

    distance[s] = 0;

    for (long long j = 1; j < n; ++j) {

        for (long long i = 1; i <= n; ++i) {

            if (i == 1)
                for (auto q: graph[s]) {
                    if ((distance[q.first] > distance[s] + q.second) && distance[s] != inf &&
                        q.second != inf) {
                        distance[q.first] = max(-inf, distance[s] + q.second);
                        way[q.first] = s;
                    }
                }
            if (i != s)
                for (auto q: graph[i]) {
                    if ((distance[q.first] > distance[i] + q.second) && distance[i] != inf &&
                        q.second != inf) {
                        distance[q.first] = max(-inf, distance[i] + q.second);
                        way[q.first] = i;
                    }
                }
        }

    }

    //one more iteration to find a cycle
    vector<long long> negDetected;
    for (long long i = 1; i <= n; ++i) {

        if (i == 1)
            for (auto q: graph[s]) {
                if ((distance[q.first] > distance[s] + q.second) && distance[s] != inf &&
                    q.second != inf) {
                    negDetected.push_back(q.first);
                }
            }

        if (i != s)
            for (auto q: graph[i]) {
                if ((distance[q.first] > distance[i] + q.second) && distance[i] != inf &&
                    q.second != inf) {
                    negDetected.push_back(q.first);
                }
            }
    }

    for (auto found: negDetected) {
        queue<long long> bfs;
        vector<char> visited(n+1, 'w');
        bfs.push(found);
        while (bfs.size() > 0) {
            long long now = bfs.front();
            isNeg[now] = true;
            visited[now] = 'g';
            for (auto q: graph[now]) {
                long long point = q.first;
                if (visited[point] == 'w')
                    bfs.push(point);
            }
            visited[now] = 'b';
            bfs.pop();
        }
    }

    //output
    for (long long i = 1; i <= n; ++i) {
        if (isNeg[i]) {
            fout << "-" << endl;
        } else if (distance[i] == inf) {
            fout << "*" << endl;
        } else {
            fout << distance[i] << endl;
        }
    }

    return 0;
}