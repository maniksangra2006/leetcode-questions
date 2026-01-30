class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map(26,0);
        for(char &ch:tasks){
            map[ch-'A']++;
        }
        int time = 0;
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(map[i]>0){
                pq.push(map[i]);
            }
        }
          
        while(!pq.empty()){
            vector<int>  tmp;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    tmp.push_back(freq);
                }
            }
            for(int &f : tmp){
                if(f>0) pq.push(f);
            }
        
        if(pq.empty()){
            time+=tmp.size();
        }
        else{
            time+=n+1;
        }
        }
        return time;
    }
};