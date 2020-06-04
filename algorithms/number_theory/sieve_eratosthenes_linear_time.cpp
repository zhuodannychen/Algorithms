/**
 * Motivation: Sieve of Eratosthenes in O(n) time.
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int spf[N+1];
vector<int> primes;

int main() {
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) {
            primes.push_back(i);
            spf[i] = i;
        }
        for (int j = 0; j < primes.size() && primes[j] <= spf[i] && i*primes[j] <= N; j++)
            spf[i * primes[j]] = primes[j];
    }
    for (int i = 0; i < primes.size(); i++) cout << primes[i] << " ";
    cout << "\n";
}
