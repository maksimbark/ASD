#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
} S;

int n, m;
vector<vector<char>> symbols(100, vector<char>(100));
vector<vector<bool>> checked(100, vector<bool>(100));
queue<pair<int, int>> bfs;
int minStep = 1000000000;
bool found = false;
vector<char> answer;

void search(int x, int y, int currStep, int from, vector<char> currAnsw) {

    if (symbols[x][y] == 'T' && minStep > currStep) {
        minStep = currStep;
        answer = currAnsw;
        found = true;
    } else {
        if (x - 1 >= 0 && from != 3 && symbols[x - 1][y] != '#') {
            currAnsw.push_back('U');
            search(x - 1, y, currStep + 1, 2, currAnsw);
        }
        if (x + 1 < n && from != 2 && symbols[x + 1][y] != '#') {
            currAnsw.push_back('D');
            search(x + 1, y, currStep + 1, 3, currAnsw);
        }
        if (y - 1 >= 0 && from != 0 && symbols[x][y - 1] != '#') {
            currAnsw.push_back('L');
            search(x, y - 1, currStep + 1, 1, currAnsw);
        }
        if (y + 1 < m && from != 1 && symbols[x][y + 1] != '#') {
            currAnsw.push_back('R');
            search(x, y + 1, currStep + 1, 0, currAnsw);
        }
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

    search(S.x, S.y, 0, -1, answer);
    if (found) {
        fout << minStep << endl;
        for (auto q: answer) {
            fout << q;
        }
    } else {
        fout << -1;
    }
    return 0;
}