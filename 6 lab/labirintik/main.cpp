#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
} S;

int n, m;
vector<vector<char>> symbols(100, vector<char>(100));
vector<vector<bool>> checked(100, vector<bool>(100));

queue<pair<int, int>> bfs;
queue<int> paths;
queue<string> ways;
void search(pair<int, int> curr) {
    checked[bfs.front().first][bfs.front().second] = true;
    if (symbols[bfs.front().first][bfs.front().second] == 'T') {
        cout << "T was found" << endl << bfs.front().first << " " << bfs.front().second << endl << "Path took " << paths.front()
             << " meters " << endl;
        cout << "Best way is " << ways.front();
    } else {
        if (bfs.front().first - 1 >= 0 && symbols[bfs.front().first - 1][bfs.front().second] != '#' &&
            !checked[bfs.front().first - 1][bfs.front().second]) {
            pair<int, int> temp;
            temp.first = bfs.front().first - 1;
            temp.second = bfs.front().second;
            bfs.push(temp);
            paths.push(paths.front()+1);
            ways.push(ways.front() + 'U');
        }
        if (bfs.front().first + 1 < n && symbols[bfs.front().first + 1][bfs.front().second] != '#' &&
            !checked[bfs.front().first + 1][bfs.front().second]) {
            pair<int, int> temp;
            temp.first = bfs.front().first + 1;
            temp.second = bfs.front().second;
            bfs.push(temp);
            paths.push(paths.front()+1);
            ways.push(ways.front() + 'D');
        }
        if (bfs.front().second - 1 >= 0 && symbols[bfs.front().first][bfs.front().second - 1] != '#' &&
            !checked[bfs.front().first][bfs.front().second - 1]) {
            pair<int, int> temp;
            temp.first = bfs.front().first;
            temp.second = bfs.front().second - 1;
            bfs.push(temp);
            paths.push(paths.front()+1);
            ways.push(ways.front() + 'L');
        }
        if (bfs.front().second + 1 < m && symbols[bfs.front().first][bfs.front().second + 1] != '#' &&
            !checked[bfs.front().first][bfs.front().second + 1]) {
            pair<int, int> temp;
            temp.first = bfs.front().first;
            temp.second = bfs.front().second + 1;
            bfs.push(temp);
            paths.push(paths.front()+1);
            ways.push(ways.front() + 'R');
        }
    }
    bfs.pop();
    paths.pop();
    ways.pop();
    if (bfs.size() > 0) {
        search(bfs.front());
    }
}

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char curr;
    fin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> curr;
            symbols[i][j] = curr;
            if (curr == 'S') {
                S.x = i;
                S.y = j;
            }
        }
    }

    pair<int, int> temp;
    temp.first = S.x;
    temp.second = S.y;
    paths.push(0);
    ways.push("");
    bfs.push(temp);
    search(temp);

    return 0;
}