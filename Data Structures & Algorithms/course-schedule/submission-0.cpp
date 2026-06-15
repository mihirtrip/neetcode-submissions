class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto& a:prerequisites){
            indegree[a[0]]++;
            adj[a[1]].push_back(a[0]);
        }

        queue<int>q;

        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int completed = 0;

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            completed++;

            for(int next: adj[temp]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return numCourses==completed;
    }
};
