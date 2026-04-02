class Solution {
public:
vector<int> state;
vector<vector<int>> adj;
 bool dfs(int node) {
        state[node]=1;                          
        for(int nbr : adj[node]) {
            if(state[nbr]==1) return false;    
            if (state[nbr]==0)                 
                if(!dfs(nbr))return false;      
        }
        state[node]=2;                           
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        state.assign(numCourses,0);
        for(auto&p:prerequisites)
            adj[p[1]].push_back(p[0]);           
        for(int i=0;i<numCourses;i++)
            if(state[i]==0)
                if(!dfs(i)) return false;        
        return true;
    }
};