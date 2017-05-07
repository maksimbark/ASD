#include <bits/stdc++.h>

#define pred 1000000000
using namespace std;

int main() {

    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");

    long long n, how;
    pair<long long, long long> temp;
    fin >> n;
    vector<vector<pair<long long, long long>>> graph(n + 1);
    vector<long long> distance(n + 1, 0);
    vector<long long> way(n + 1);
    vector<bool> out (n+1);


    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            fin >> how;
            temp.first = j;
            temp.second = how;
            graph[i].push_back(temp);
            if (i == j && how < 0) {
                fout << "YES" << endl << 2 << endl;
                fout << i << " " << i << endl;
                return 0;
            }
        }
    }

    long long s = 1;
    for (long long j = 1; j < n; ++j) {

        for (long long i = 1; i <= n; ++i) {

            if (i == 1)
                for (auto q: graph[s]) {
                    if ((distance[q.first] > distance[s] + q.second) && distance[s] != pred &&
                        q.second != pred) {
                        distance[q.first] = distance[s] + q.second;
                        way[q.first] = s;
                    }
                }
            if (i != s)
                for (auto q: graph[i]) {
                    if ((distance[q.first] > distance[i] + q.second) && distance[i] != pred &&
                        q.second != pred) {
                        distance[q.first] = distance[i] + q.second;
                        way[q.first] = i;
                    }
                }
        }

    }

    //one more iteration to find a cycle
    long long found = 0;
    for (long long i = 1; i <= n; ++i) {

        if (i == 1)
            for (auto q: graph[s]) {
                if ((distance[q.first] > distance[s] + q.second) && distance[s] != pred &&
                    q.second != pred) {
                    found = q.first;
                    break;
                }
            }

        if (found)
            break;

        if (i != s)
            for (auto q: graph[i]) {
                if ((distance[q.first] > distance[i] + q.second) && distance[i] != pred &&
                    q.second != pred) {
                    found = q.first;
                    break;
                }
            }

        if (found)
            break;
    }


    if (!found) {
        fout << "NO" << endl;
        return 0;
    }

    vector<long long> answer;
    long long tmp = found;
    while (true) {
        answer.push_back(tmp);
        out[tmp] = true;
        tmp = way[tmp];
        if (out[tmp]) {
            answer.push_back(tmp);
            break;
        }
    }
    vector<long long> cleanAnswer;
    reverse(answer.begin(), answer.end());
    cleanAnswer.push_back(tmp);
for (int i = 1; i < answer.size(); ++i) {
    cleanAnswer.push_back(answer[i]);
    if (answer[i]==tmp)
        break;
}

    fout << "YES" << endl << cleanAnswer.size() << endl;
    for (auto q: cleanAnswer)
        fout << q << " ";
    return 0;
}