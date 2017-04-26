#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> myGraph(30001);
vector<int> route(30001, INT_MAX);
queue<int> bfs;
void search(int place) {
for (auto q: myGraph[place]) {
    if (route[q] == INT_MAX) {
        bfs.push(q);
        route[q] = route[place] + 1;
    }
}
    bfs.pop();
}
int main() {
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");
    int n, m, from, where;
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        fin >> from >> where;
        myGraph[from].push_back(where);
        myGraph[where].push_back(from);
    }
    bfs.push(1);
    route[1] = 0;
    while (bfs.size() > 0) {
        search(bfs.front());
    }

    for (int i = 1; i <= n; i++) {
    fout << route[i] << " ";
    }
    return 0;
}