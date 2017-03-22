#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
vector<int> arr;

void msort(int a, int b) {

    if ((b-a) > 1) {


        msort(a, ((a + b) / 2));
        msort(((a + b) / 2), b);

        vector<int> left;
        vector<int> right;
        vector<int> answ;
/*
        for (int i = 0; i < (a+b)/2; i++) {
            left.push_back(arr[i]);
        }
        for (int i = (a+b)/2; i < b; i++) {
            right.push_back(arr[i]);
        }
*/
        int coLeft = 0;
        int coRight = 0;
        //int k = a;
        int mid = ((a + b) / 2);


        while ((a + coLeft < mid) && (mid + coRight < b)) {

            if (arr[a + coLeft] < arr[mid + coRight]) {
                answ.push_back(arr[a + coLeft]);
                coLeft++;
            } else {
                answ.push_back(arr[mid + coRight]);
                coRight++;
            }
        }

        while (a + coLeft < mid) {
            answ.push_back(arr[a + coLeft]);
            coLeft++;
        }
        while (mid + coRight < b) {
        answ.push_back(arr[mid + coRight]);
        coRight++;
    }
        for (int i = 0; i < (coLeft + coRight); i++) {
            arr[a + i] = answ[i];
        }
        cout << a+1 << " " << b << " " << arr[a] << " " << arr[b-1] << endl;

    //for (int i = 0; i < answ.size()-1; i++) {
      //          arr[a+i] = answ[i];

        //}



    }

}

int main() {
    ifstream cin("input.txt");
    freopen("output.txt", "w", stdout);
    int n, curr;
    cin >> n;
for (int i = 0; i < n; i++) {
    cin >> curr;
    arr.push_back(curr);
}

  msort(0, arr.size());

    for (int i = 0; i < arr.size(); i++) {
        cout << (arr[i]) << " ";
    }

    return 0;
}

