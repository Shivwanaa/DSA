class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({passingFees[0], 0, 0});
        vector<int> bestTime(n, 1e9);
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int cost = cur[0];
            int time = cur[1];
            int node = cur[2];
            if (node == n - 1)
                return cost;
            if (time >= bestTime[node])
                continue;
            bestTime[node] = time;
            for (auto &[nei, t] : adj[node]) {
                int newTime = time + t;
                if (newTime > maxTime)
                    continue;
                pq.push({cost + passingFees[nei],newTime,nei});
            }
        }

        return -1;
    }
};