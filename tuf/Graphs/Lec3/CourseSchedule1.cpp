// Link: https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n,0);
        vector<int> adj[n];
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0; i < n; i++){
            for(int it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
         for(int i = 0; i < n; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }

        int cnt = 0;
        while(!q.empty()){
            cnt++;
            int node = q.front();
            q.pop();

            for(int itr: adj[node]){
                indegree[itr]--;
                if(indegree[itr] == 0){
                    q.push(itr);
                }
            }
        }

        return cnt == n;
    }
};