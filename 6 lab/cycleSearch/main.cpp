#include <bits/stdc++.h>
//be careful, it's WA version!
using namespace std;

vector<vector<int>> myGraph(100001);
vector<char> status(100001, 'w');
vector<int> dfs;

void search(int place) {
    status[place] = 'q';
    dfs.push_back(place);
    for (auto q: myGraph[place]) {
        if (status[q] == 'w') {
            search(q);
        } else if (status[q] == 'q') {
            cout << "YES" << endl;
            bool find = false;
            for (auto w: dfs) {
                if (w == q)
                    find = true;
                if (find)
                    cout << w << " ";
            }

            exit(0);
        }

    }
    status[place] = 'b';
    dfs.pop_back();
}

int main() {
    ifstream fin("cycle.in");
    freopen("cycle.out", "w", stdout);
    int n, m, from, where;
    fin >> n >> m;

    for (int i = 0; i < m; i++) {
        fin >> from >> where;
        myGraph[from].push_back(where);
    }

    for (int i = 0; i < n; i++) {
        if (status[i] == 'w')
            search(i);
    }
    cout << "NO";
    return 0;
}
