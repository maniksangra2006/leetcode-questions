class Solution {
public:

bool checkbip(int node,vector<vector<int>>& graph,vector<int>&  color){

for(int i=0;i<graph[node].size();i++){
    if(color[graph[node][i]]==-1){
        color[graph[node][i]]=(color[node]+1)%2;
        if(!checkbip(graph[node][i],graph,color)) return 0;
    }
    else {
        if(color[node]==color[graph[node][i]])
         return 0;
             }
       }
     return 1;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int V =graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!checkbip(i,graph,color))
                return 0;
            }
        }
        return 1;
    }
};