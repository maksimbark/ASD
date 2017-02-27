#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int n;
vector<string> msort(vector<string> mas, int k) {
    vector<string> answ;
    if (mas.size() > 1) {
        vector<string> left;
        vector<string> right;

        for (int i = 0; i < mas.size()/2; i++) {
            left.push_back(mas[i]);
        }
        for (long int i = mas.size()/2; i < mas.size(); i++) {
            right.push_back(mas[i]);
        }
        left = msort(left, k);
        right = msort(right, k);
        int coLeft = 0;
        int coRight = 0;

        while (coLeft < left.size() && coRight < right.size()) {
            if (left[coLeft][k] > right[coRight][k]) {
                /*if (right[coRight] != "") {*/answ.push_back(right[coRight]);/*}*/

                coRight++;

            } else {
                /*if (left[coLeft] != "") {*/answ.push_back(left[coLeft]);/*}*/
                coLeft++;

            }
        }
        while ((coLeft) < left.size() || (coRight) < right.size()) {
            if ((coLeft) < left.size()) {
                /*if (left[coLeft] != ""){*/answ.push_back(left[coLeft]);/*}*/
                coLeft++;
            }
            if ((coRight) < right.size()) {
                /*if (right[coRight] != "") {*/answ.push_back(right[coRight]);/*}*/
                coRight++;
            }
        }
        //for (int i = 0; i < n; i++) {
        //   cout << answ[i] << endl;
        // }
        return answ;
    }


    return mas;
}

int main() {
    ifstream cin("radixsort.in");
    ofstream cout("radixsort.out");
int m, k;
    string curr;
cin >> n >> m >> k;
    vector<string> arr;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        arr.push_back(curr);
    }
for (int i = m-1; i>=m-k; i--) {
    arr = msort(arr, i);
    //cout << i << " ";

}
   for (int i = 0; i < arr.size(); i++) {
      //if (arr[i] != "") {
          cout << arr[i] << endl;
      //}
    }

return 0;
}
