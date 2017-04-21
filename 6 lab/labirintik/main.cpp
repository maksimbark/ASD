#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
} S;

int n, m;
vector<vector<char>> symbols(100, vector<char>(100));
vector<vector<bool>> checked(100, vector<bool>(100));


void search(pair<int, int> curr, int now) {
    queue<pair<int, int>> bfs;
    bfs.push(curr);
    checked[bfs.front().first][bfs.front().second] = true;
    if (symbols[bfs.front().first][bfs.front().second] == 'T') {
        cout << "T was found" << endl << bfs.front().first << " " << bfs.front().second << endl << "Path took " << now << " meters " << endl;
        checked[bfs.front().first][bfs.front().second] = false;
    } else {
        if (bfs.front().first - 1 >= 0 && symbols[bfs.front().first - 1][bfs.front().second] != '#' &&
            !checked[bfs.front().first - 1][bfs.front().second]) {
            pair<int, int> temp;
            temp.first = bfs.front().first - 1;
            temp.second = bfs.front().second;
            bfs.push(temp);
        }
        if (bfs.front().first + 1 < n && symbols[bfs.front().first + 1][bfs.front().second] != '#' &&
            !checked[bfs.front().first + 1][bfs.front().second]) {
            pair<int, int> temp;
            temp.first = bfs.front().first + 1;
            temp.second = bfs.front().second;
            bfs.push(temp);
        }
        if (bfs.front().second - 1 >= 0 && symbols[bfs.front().first][bfs.front().second - 1] != '#' &&
            !checked[bfs.front().first][bfs.front().second - 1]) {
            pair<int, int> temp;
            temp.first = bfs.front().first;
            temp.second = bfs.front().second - 1;
            bfs.push(temp);
        }
        if (bfs.front().second + 1 < m && symbols[bfs.front().first][bfs.front().second + 1] != '#' &&
            !checked[bfs.front().first][bfs.front().second + 1]) {
            pair<int, int> temp;
            temp.first = bfs.front().first;
            temp.second = bfs.front().second + 1;
            bfs.push(temp);
        }
    }
    bfs.pop();
    while (bfs.size() > 0) {
        search(bfs.front(), now+1);
        bfs.pop();
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
   // bfs.push(temp);
    search(temp, 0);

    return 0;
}