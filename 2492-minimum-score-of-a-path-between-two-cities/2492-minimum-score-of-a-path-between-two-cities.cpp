class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int mini = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &it : adj[node]) {
                mini = min(mini, it.second);

                if (!vis[it.first]) {
                    vis[it.first] = 1;
                    q.push(it.first);
                }
            }
        }

        return mini;
    }
};