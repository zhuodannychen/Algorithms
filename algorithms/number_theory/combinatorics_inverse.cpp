// Modular inverse and combinatorics

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

const int MAXN = 1e4;
long long fact[MAXN]; // fact[i] = i !
long long inv[MAXN]; // inv[i] = i-1
long long finv[MAXN]; // finv[i] = (i !)-1

void buildFact(int n) {
    fact[0] = finv[0] = inv[1] = 1;
    for(int i = 2; i < n; i++) inv[i] = (MOD - (MOD / i) * inv[MOD%i] % MOD) % MOD;
    for(int i = 1; i < n; i++){
        fact[i] = fact[i-1] * i % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
long long C(int a,int b){if(a < b || b < 0)return 0; return fact[a] * finv[b] % MOD * finv[a-b] % MOD;}

// running code
int main() {
    buildFact(5);
    cout << C(4, 2) << "\n";
}

