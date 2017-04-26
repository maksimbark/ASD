#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
} S, T;

int n, m;
bool found = false;
vector<char> finalOut;

vector<vector<char>> symbols(100, vector<char>(100));
vector<vector<int>> result(100, vector<int>(100, 100000000));
queue<pair<int, int>> bfs;

void search(pair<int, int> curr) {
    if (symbols[bfs.front().first][bfs.front().second] == 'T') {
        found = true;
        bfs.pop();
        return;
    } else {
        if (bfs.front().first - 1 >= 0 && symbols[bfs.front().first - 1][bfs.front().second] != '#' &&
            result[bfs.front().first - 1][bfs.front().second] > result[curr.first][curr.second] + 1) {
            pair<int, int> temp;
            temp.first = bfs.front().first - 1;
            temp.second = bfs.front().second;
            bfs.push(temp);
            result[curr.first - 1][curr.second] = result[curr.first][curr.second] + 1;
        }
        if (bfs.front().first + 1 < n && symbols[bfs.front().first + 1][bfs.front().second] != '#' &&
            result[bfs.front().first + 1][bfs.front().second] > result[curr.first][curr.second] + 1) {
            pair<int, int> temp;
            temp.first = bfs.front().first + 1;
            temp.second = bfs.front().second;
            bfs.push(temp);
            result[curr.first + 1][curr.second] = result[curr.first][curr.second] + 1;
        }
        if (bfs.front().second - 1 >= 0 && symbols[bfs.front().first][bfs.front().second - 1] != '#' &&
            result[bfs.front().first][bfs.front().second - 1] > result[curr.first][curr.second] + 1) {
            pair<int, int> temp;
            temp.first = bfs.front().first;
            temp.second = bfs.front().second - 1;
            bfs.push(temp);
            result[curr.first][curr.second - 1] = result[curr.first][curr.second] + 1;
        }
        if (bfs.front().second + 1 < m && symbols[bfs.front().first][bfs.front().second + 1] != '#' &&
            result[bfs.front().first][bfs.front().second + 1] > result[curr.first][curr.second] + 1) {
            pair<int, int> temp;
            temp.first = bfs.front().first;
            temp.second = bfs.front().second + 1;
            bfs.push(temp);
            result[curr.first][curr.second + 1] = result[curr.first][curr.second] + 1;
        }
    }
    bfs.pop();
}

void wayOut(int x, int y) {
    int curr = result[x][y];
    if (x - 1 >= 0 && result[x - 1][y] == curr - 1) {
        finalOut.push_back('D');
        wayOut(x - 1, y);
    } else if (x + 1 < n && result[x + 1][y] == curr - 1) {
        finalOut.push_back('U');
        wayOut(x + 1, y);
    } else if (y - 1 >= 0 && result[x][y - 1] == curr - 1) {
        finalOut.push_back('R');
        wayOut(x, y - 1);
    } else if (y + 1 < m && result[x][y + 1] == curr - 1) {
        finalOut.push_back('L');
        wayOut(x, y + 1);
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
            if (curr == 'T') {
                T.x = i;
                T.y = j;
            }
        }
    }

    pair<int, int> temp;

    temp.first = S.x;
    temp.second = S.y;

    bfs.push(temp);
    result[S.x][S.y] = 1;
    while (bfs.size() > 0) {
        search(bfs.front());
    }

    if (found) {
        wayOut(T.x, T.y);

        if ((result[T.x][T.y] - 1) < (finalOut.size())) finalOut.pop_back();
        reverse(finalOut.begin(), finalOut.end());
        fout << result[T.x][T.y] - 1 << endl;
        for (auto q: finalOut) {
            fout << q;
        }
    } else {
        fout << "-1";
    }


    return 0;
}