class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        int n = s.size();

        // powers of 10
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // prefix sum of digits
        vector<int> sumD(n + 1, 0);

        // prefix count of non-zero digits
        vector<int> cnt(n + 1, 0);

        // prefix concatenated value of non-zero digits
        vector<long long> pref(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';

            sumD[i] = sumD[i - 1] + d;
            cnt[i] = cnt[i - 1] + (d != 0);

            if (d == 0)
                pref[i] = pref[i - 1];
            else
                pref[i] = (pref[i - 1] * 10 + d) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int nonZero = cnt[r + 1] - cnt[l];
            int digitSum = sumD[r + 1] - sumD[l];

            long long x =
                (pref[r + 1] - pref[l] * pow10[nonZero] % MOD + MOD) % MOD;

            ans.push_back((x * digitSum) % MOD);
        }

        return ans;
    }
};