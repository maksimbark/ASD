#include <stdio.h>
#include <vector>
#include <cstdlib>

using namespace std;

int hsort(vector<int>& array, int a, int b) {
    if (a == b) {
        return a;
    }


    int cumid = array[b];

    int i = a-1;
    int j = b;

    while (1) {
        while (array[++i]<cumid) {
        }
        while (array[--j]>cumid) {
        }
        if (i < j) {
            //swap(array[i], array[j]);
int temp = array[i];
            array[i] = array[j];
            array[j]=temp;
        } else break;
    }
    int temp = array[i];
    array[i] = array[b];
    array[b]=temp;
    return i;

}

int testing(vector<int>& array, int a, int b, int k) {
    while (1) {
        int mid = hsort(array, a, b);
        if (mid == k) {
            return array[mid];
        } else if (mid < k) {
            a = mid + 1;
        } else {
            b = mid - 1;
        }
    }

}

int main() {
    FILE* f;
    f=fopen("kth.in","r");
    vector<int> array;
    int n, k, A, B, C;
    int curr;
    fscanf (f, "%d %d", &n, &k);
    fscanf (f, "%d %d %d", &A, &B, &C);
    fscanf (f, "%d", &curr);
    array.push_back(curr);
    fscanf (f, "%d", &curr);
    array.push_back(curr);
    fclose(f);
    for (int i = 2; i < n; i++) {
        array.push_back(A*array[i-2]+B*array[i-1]+C);
    }

    vector<int>& link = array;

    f=fopen("kth.out","w");
    fprintf(f, "%d",  testing(link, 0, array.size()-1, k-1));

    /* for (int i = 0; i < n; i++) {
     fprintf(f, "%d ", array[i]);
    }*/

    fclose(f);

    return 0;
}