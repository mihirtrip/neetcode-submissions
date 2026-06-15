class Solution {
public:
    void dfs(int node , vector<vector<int>>& adj, vector<bool>&vis){
        vis[node] = true;

        for(int i:adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto&a : edges){
            int u = a[0];
            int v = a[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        vector<bool>vis(n,false);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};
