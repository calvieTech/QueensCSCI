#include <iostream>
using namespace std;

int main() {
    
    int n = 0;
    
    cout << "Type in a number n: ";
    cin >> n;
    
    int x = 0;
    int sum = 0;
    cout << "Now type in " << n << " more numbers: ";
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        sum += x;
    }
    
    cout << "The average is: " << ((double) sum / n) << endl;
    
    
    
    
    
    return 0;
}
