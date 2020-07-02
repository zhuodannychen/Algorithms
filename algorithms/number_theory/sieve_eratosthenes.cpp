/**
 * Motivation: Create Sieve for prime numbers.
 * Complexity: O(NlogN)
 * Comment: Consider using long long to prevent integer overflow (i*i)
 */

#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;
bool sieve[maxn];

int main() {
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;
    vector<int> primes;

    for (int i = 2; i <= maxn; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            for (int j = i*i; j <= maxn; j+=i)
                sieve[j] = false;
        }
    }
    for (int p : primes)
        cout << p << " ";
}
