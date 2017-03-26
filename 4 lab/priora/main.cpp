#include <bits/stdc++.h>

using namespace std;

int a[100000001];
//int b[100000001];
//int c[100000001];

//map<int, int> a;
map<int, int> b;
map<int, int> c;

int n, now, command, when;


void fix(int k) {

    int left, right, min, temp;
    left = 2 * k;
    right = 2 * k + 1;
    min = k;
    if ((left <= n) && (a[left] <= a[min])) min = left;
    if ((right <= n) && (a[right] <= a[min])) min = right;
    if (min != k) {

        swap(b[c[k]], b[c[min]]);
        swap(c[k], c[min]);

        swap(a[k], a[min]);

        fix(min);
    }
}

void decrease(int when, int k) {

    a[b[when]] = k;
    int po = b[when];
    int parent;

    if (po != 1) {
       // if (po % 2 == 0) { parent = po / 2; } else { parent = (po - 1) / 2; }
parent = po/2;
        while ((po > 1) && (parent >= 1) && (a[po] <= a[parent])) {

            swap(b[c[po]], b[c[parent]]);
            swap(c[po], c[parent]);

            swap(a[po], a[parent]);

            po = parent;

           // if (po % 2 == 0) { parent = po / 2; } else { parent = (po - 1) / 2; }
        parent = po/2;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    string curr;
    ifstream fin("priorityqueue.in");
    ofstream fout("priorityqueue.out");
   // int k;
  //  fin >> k;
    command = 0;
    n = 0;
    while (fin >> curr) {
    //for (int i = 0; i < k; i++) {
        command = command + 1;
//fin >> curr;

        if (curr[0] == 'p') {
            n = n + 1;
            fin >> now;
            a[n] = 1000000001;
            b[command] = n;
            c[n] = command;
            decrease(command, now);

        } else if (curr[0] == 'e') {

            if (n == 0) fout << '*' << endl;
            else {

                fout << a[1] << endl;
                a[1] = a[n];
                b[c[n]] = 1;
                c[1] = c[n];
                n = n - 1;
                fix(1);

            }
        } else if (curr[0] == 'd') {
            fin >> when >> now;
            decrease(when, now);
        }

    }
}