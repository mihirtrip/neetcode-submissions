class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>&adj){
        vis[node] = true;
        for(int a:adj[node]){
            if(!vis[a]){
                dfs(a,vis,adj);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        if(edges.size() != n - 1){
            return false;
        }
        for(auto& a: edges){
            int u = a[0];
            int v = a[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        dfs(0,vis,adj);

        for(bool v: vis){
            if(!v){
                return false;
            }
        }
        return true;
    }
};
