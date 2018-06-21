#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// arr contains all the prime numbers from 0 to n
void sieve(int n, vector<bool> &SIEVE, vector<int> &arr) {
    SIEVE[0] = SIEVE[1] = false;
    long int p;
    for(long int i = 2; i <= n; i++) {
        p = i;
        if(!SIEVE[p]) {
            SIEVE[p] = true;
            arr.push_back(p);
            for(int j = p; j <= n; j += p)
                SIEVE[j] = true;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<bool> SIEVE(10000000, false);
    vector<int> arr;
    sieve(10000000, SIEVE, arr);
    return 0;
}

