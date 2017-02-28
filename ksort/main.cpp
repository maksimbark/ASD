#include <iostream>
#include <vector>
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

        //for (int i = 0; i < answ.size()-1; i++) {
        //          arr[a+i] = answ[i];

        //}



    }

}


int main()
{
ifstream cin("kth.in");
ofstream cout("kth.out");
    int n, k, a,b,c;
    cin >> n >> k >> a >> b >> c;
    //vector<int> arr(n);
    int f, s;
    cin >> f >> s;
    arr.push_back(f);
    arr.push_back(s);

    for (int i = 2; i < n; i++) {
        arr.push_back((a*arr[i-2]+b*arr[i-1]+c));
    }

    msort(0, arr.size());

    cout << arr[k-1];

    return 0;
}