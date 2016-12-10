#include <iostream>

using namespace std;

int multiply(int a, int b) {
    int result = 0;
    if (b<0 && a<0 || a>0 && b>0) {
        for (int i = 0; i < abs(b); i++) {
            result += abs(a);
        }
    } else {
        for (int i = 0; i < b; i++) {
            result -= a;
        }
    }
    return result;
}

//O(n)
int square1(int n) {
    multiply(n,n);
}

//O(n)
int square2(int n) {
    if (n<0) {
        n = -n;
    }
    int result = 0;
    for (int i=0; i<n; i++) {
        result += n;
    }
    return result;
}

int square3(int n) {
    if (n==1) {
        return 1;
    }
    if (n==0) {
        return 0;
    }
    if (n<0) {
        n = -n;
    }
    if (n&1) {//odd number
        return ((square3(n>>1)<<2)+((n>>1)<<2)+1);//(2n+1)^2
    } else {
        return (square3(n>>1)<<2);//(2n)^2
    }
}

//Find the square of a number w/out using *,/,pow()
int main() {
    int n = -25;
    int result = square3(n);
    cout << result;
    return 0;
}