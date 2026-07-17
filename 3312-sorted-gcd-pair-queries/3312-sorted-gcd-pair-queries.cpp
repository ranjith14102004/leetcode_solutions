#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = 50000;
        
        vector<long long> freq(maxVal + 1, 0);
        for (int x : nums) freq[x]++;
        
        // Count numbers divisible by g
        vector<long long> cnt(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            for (int m = g; m <= maxVal; m += g) {
                cnt[g] += freq[m];
            }
        }
        
        // Count pairs divisible by g
        vector<long long> pairs(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            if (cnt[g] >= 2) {
                pairs[g] = cnt[g] * (cnt[g] - 1) / 2;
            }
        }
        
        // Inclusion-exclusion for exact gcd
        for (int g = maxVal; g >= 1; g--) {
            for (int m = 2 * g; m <= maxVal; m += g) {
                pairs[g] -= pairs[m];
            }
        }
        
        // Prefix sum
        vector<long long> pref(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            pref[g] = pref[g - 1] + pairs[g];
        }
        
        // Answer queries
        vector<int> ans;
        for (long long q : queries) {
            int g = lower_bound(pref.begin(), pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }
        
        return ans;
    }
};