class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int n = t.size();
        
        vector<pair<char,int>> blocks;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            blocks.push_back({t[i], j - i});
            i = j;
        }
        
        int ones = 0;
        for (char c : s) if (c == '1') ones++;
        
        int bestGain = 0;
        for (int idx = 1; idx + 1 < (int)blocks.size(); idx++) {
            if (blocks[idx].first == '1') {
                int left = blocks[idx - 1].second;
                int right = blocks[idx + 1].second;
                bestGain = max(bestGain, left + right);
            }
        }
        
        return ones + bestGain;
    }
};