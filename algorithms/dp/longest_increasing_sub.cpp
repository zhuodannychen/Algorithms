/**
 * Motivation: Solve the longest increasing subsequence problem
 * Complexity: O(NlogN)
 */

#include<bits/stdc++.h>
using namespace std;

int bin_search(vector<int>& arr, int low, int high, int value) {
    while (high - low > 1) {
        int mid = low + (high-low) / 2;
        if (arr[mid] >= value)
            high = mid;
        else
            low = mid;
    }
    return high;
}

int main() {
    int n; cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    
    int length = 1;
    vector<int> min_values(n);
    min_values[0] = input[0];
    for (int i = 1; i < n; i++) {
        if (input[i] < min_values[0])
            min_values[0] = input[i];
        else if (input[i] > min_values[length-1]) 
            min_values[length++] = input[i];
        else
            min_values[bin_search(min_values, -1, length-1, input[i])] = input[i];
    }
    cout << length << "\n";
}

/*
8
10 9 2 5 3 7 101 18
output: 4
*/
