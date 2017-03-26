#include <bits/stdc++.h>

using namespace std;

int n;
double a;

double binsearch(double l, double r) {
    double h2;
    for (int i = 0; i < 100; i++) {
       double now = (l + r) / 2.0;
       double h0 = a;
       double h1 = now;
       int count = 0;
       if (h0 <= 0) count++;
       if (h1 <= 0) count++;
       for (int i = 0; i < n - 2; i++) {
           h2 = 2.0 * h1 + 2.0 - h0;
           if (h2 <= 0) {
               ++count;
           }
           h0 = h1;
           h1 = h2;
       }
       if (count >= 1) {
           l = now;
       } else r = now;
   }
    return h2;
}

int main() {

    ifstream fin("garland.in");
    ofstream fout("garland.out");

    fin >> n >> a;


   fout<<std::fixed<<std::setprecision(2)<<binsearch(0.0, a)<<std::endl;

    return 0;
}
