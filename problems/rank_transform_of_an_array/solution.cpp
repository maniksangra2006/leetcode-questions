class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> minheap;

        for(int x: arr){
            minheap.push(x);
        }
        unordered_map<int,int> rank;
        int prev=INT_MIN;
        int r=0;
        while(!minheap.empty()){
            int curr=minheap.top();
            minheap.pop();
            if(curr!=prev){
                r++;
                rank[curr]=r;
                prev=curr;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=rank[arr[i]];
        }
        return arr;
    }
};