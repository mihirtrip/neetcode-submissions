class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(auto& a: pre){
            int course = a[0];
            int pree = a[1];
            indegree[course]++;
            adj[pree].push_back(course);
        }
        queue<int>q;

        for(int i =0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(int next:adj[temp]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }   
        if(ans.size()==n){
            return ans;
        }
        else{
            return {};
        }
    }
};
