class Solution {
public:
  int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    if (m == 0) { // Edge case
        return 0;
    }
    if (n < m) { // If haystack is smaller than needle, needle cannot be found
        return -1;
    }
    
    for (int i = 0; i <= n - m; i++) { // Loop only until `n-m`
        if (haystack.substr(i, m) == needle) { // Direct substring comparison
            return i;
        }
    }
    
    return -1;
}
};