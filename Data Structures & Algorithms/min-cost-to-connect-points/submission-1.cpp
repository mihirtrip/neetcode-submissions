class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> vis(n, false);

        pq.push({0,0});
        int nodeUsed = 0;
        int cost = 0;

        while(nodeUsed<n){
            auto[currCost, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = true;
            cost += currCost;
            nodeUsed++;
            for(int i = 0;i<n;i++){
                if(!vis[i]){
                    int dist = abs(points[node][0]-points[i][0]) + abs(points[node][1]-points[i][1]);
                    pq.push({dist,i});
                }
            }
        }
        return cost;
    }
};
