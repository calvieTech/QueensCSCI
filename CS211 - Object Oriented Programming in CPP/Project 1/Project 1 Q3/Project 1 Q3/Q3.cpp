#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

bool sum_top(int a[], int n, int m, int & sum);
void sort(int a[], int n);

int main() {
    int a[4] = {2, 12, 24, 9};
    int m = 2, n = 4, sum = 0;
    cout << sum_top(a, n, m, sum) << endl;
    
    
    return 0;
}

bool sum_top(int a[], int n, int m, int & sum) {
    if (n <= 0 || m <= 0 || m > n) {
        sum = 0;
        return false;
    }
    
    sort(a, n);
    
    for (int i = 0; i < m; i++) {
        sum += a[i];
    }
    cout << sum << endl;
    return true;
}

void sort(int a[], int n) {
    bool swapped = true;
    int temp = 0;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < n-1; i++) {
            if (a[i] < a[i+1]) {
                temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
                swapped = true;
            }
        }
    }
}
