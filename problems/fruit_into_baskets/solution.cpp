class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int n =fruits.size();
       int maxLen=0;
        unordered_map<int, int> basket;
        for(int r=0;r<n;r++){
            basket[fruits[r]]++;
            while(basket.size()>2){
                basket[fruits[l]]--;
                if(basket[fruits[l]]==0){
                 basket.erase(fruits[l]);
                }
                l++;
            }
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};