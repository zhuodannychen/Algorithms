/**
 * Motivation: Find prime factors of a number (with repetition)
 * Complexity: O(logN)
 * Source: Competitive Programming 3
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi primes;

void sieve(int N) {
    bool sieve[N];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            for (int j = i*i; j <= N; j+=i)
                sieve[j] = false;
        }
    }
}

vi primeFactors(ll N) {
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (N != 1 && (PF * PF <= N)) {
        while (N % PF == 0) { N /= PF; factors.push_back(PF); }
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.push_back(N);
    return factors;
}

int main() {
    sieve(200);
    vi res = primeFactors(60);
    for (auto x : res) cout << x << " ";
}

