#include <bits/stdc++.h>

using namespace std;

struct listik {
    int kuda;
    listik *next;
};

struct node {
    listik *cat;
    char color;
    int time;
};

vector<node *> graph(30001);
queue<int> bfs;

void search(int curr) {
    listik *temp = graph[curr]->cat;
    while (temp) {
        if (graph[temp->kuda]->color == 'w') {
            graph[temp->kuda]->time = graph[curr]->time + 1;
            graph[temp->kuda]->color = 'g';
            bfs.push(temp->kuda);
        }
        temp = temp->next;
    }
    bfs.pop();
}

int main() {
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    int size, count;
    int from, where;
    fin >> size >> count;
    for (int i = 1; i <= size; i++) {
        node *temp = new(node);
        temp->color = 'w';
        temp->cat = NULL;
        graph[i] = temp;
    }

    for (int i = 0; i < count; i++) {
        fin >> from >> where;

        if (!graph[from]->cat) {
            listik *add = new(listik);
            add->kuda = where;
            add->next = NULL;
            graph[from]->cat = add;
        } else {
            listik *temp = graph[from]->cat;
            while (temp->next) {
                temp = temp->next;
            }
            listik *add = new(listik);
            add->kuda = where;
            add->next = NULL;
            temp->next = add;
        }

        if (!graph[where]->cat) {
            listik *add = new(listik);
            add->kuda = from;
            add->next = NULL;
            graph[where]->cat = add;
        } else {
            listik *temp = graph[where]->cat;
            while (temp->next) {
                temp = temp->next;
            }
            listik *add = new(listik);
            add->kuda = from;
            add->next = NULL;
            temp->next = add;
        }
    }

    fout << 0 << " ";
    bfs.push(1);
    graph[1]->time = 0;
    graph[1]->color = 'g';
    while (bfs.size() > 0) {
        search(bfs.front());
    }
    for (int i = 2; i <= size; i++) {
        fout << graph[i]->time << " ";
    }
    return 0;
}