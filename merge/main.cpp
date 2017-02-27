#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
vector<int> arr;


vector<int> msort(vector<int> mas) {
    vector<int> answ;
    if (mas.size() > 1) {
        vector<int> left;
        vector<int> right;

        for (int i = 0; i < mas.size()/2; i++) {
            left.push_back(mas[i]);
        }
        for (int i = mas.size()/2; i < mas.size(); i++) {
            right.push_back(mas[i]);
        }
        left = msort(left);
        right = msort(right);
        int coLeft = 0;
        int coRight = 0;

        //left[0]>right[0]?answ.push_back(right[0]):answ.push_back(left[0]);
        //left[0]>right[0]?answ.push_back(left[0]):answ.push_back(right[0]);

        while (coLeft<left.size() && coRight < right.size()) {
            if (left[coLeft]>right[coRight]) {
                answ.push_back(right[coRight]);
                coRight++;
            } else {
                answ.push_back(left[coLeft]);
                coLeft++;
            }
        }
        while ((coLeft) < left.size() || (coRight) < right.size()) {
            if ((coLeft) < left.size()) {
                answ.push_back(left[coLeft]);
                coLeft++;
            }
            if ((coRight) < right.size()) {
                answ.push_back(right[coRight]);
                coRight++;
            }
        }


//cout << endl << coLeft << ' ' << coRight;
        return answ;
    }


return mas;
}

int main() {
    ifstream cin("sort.in");
    ofstream cout ("sort.out");
    int n;
    int curr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        arr.push_back(curr);
    }
    cout << endl;
    //msort(0,arr.size());
    arr = msort(arr);
   for (int i = 0; i < n; i++) {
       cout << arr[i] << " ";
    }

    return 0;
}