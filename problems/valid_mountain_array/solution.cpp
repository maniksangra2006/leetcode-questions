 class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false; 
        int peak = max_element(arr.begin(), arr.end()) - arr.begin(); 
        if (peak == 0 || peak == n - 1) return false; 
        for (int i = 0; i < peak; ++i) {
            if (arr[i] >= arr[i + 1]) return false;
        } 
        for (int i = peak; i < n - 1; ++i) {
            if (arr[i] <= arr[i + 1]) return false;
        } 
        return true;
    }
};
