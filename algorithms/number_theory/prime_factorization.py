# Sieve
primes = []
boo = [True] * (int(1e6) + 1)
boo[0] = False; boo[1] = False
for i in range(2, len(boo)):
    if boo[i]:
        for j in range(i*i, len(boo), i):
            boo[j] = False
        primes.append(i)
        
# Finds the prime factors of a number
def findPF(num):
    ans = []
    PF_idx = 0
    PF = primes[PF_idx]
    while PF * PF <= num:
        while num % PF == 0:
            num //= PF
            ans.append(PF)
        PF_idx += 1
        PF = primes[PF_idx]
    if num != 1:
        ans.append(num)
    return ans

# Main/running code
cases = int(input())
for i in range(cases):
    ns = int(input())
    ans = findPF(ns)






