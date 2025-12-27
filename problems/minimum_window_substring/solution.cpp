class Solution {
public:
   string minWindow(string s, string t) {
    //Shopping list
    // map batata hai kaunsa character kitni baar chahiye
    vector<int> map(128, 0);
    for (auto c : t)
        map[c]++;
    //counter = abhi kitne characters milna baaki hain
    int counter = t.size();
    //  begin aur end = sadak par chalne wale do log
    int begin = 0, end = 0;
    //  d = ab tak ki sabse chhoti khidki ka size
    // head = us khidki ka starting point
    int d = INT_MAX, head = 0;
    //  end aage badhta rahega (window badhegi)
    while (end < s.size()) {
        // Agar end ne jo character dekha wo shopping list mein tha
        // toh counter kam kar do
        if (map[s[end++]]-- > 0)
            counter--;
        // Jab counter == 0 ho jaaye
        // matlab saari cheezein mil gayi hain
        while (counter == 0) {
            // Agar yeh window ab tak ki sabse chhoti hai
            // toh ise yaad kar lo
            if (end - begin < d)
                d = end - (head = begin);
            // Ab begin ko aage badhao (window chhoti karo)
            // Agar koi zaroori cheez nikal gayi
            // toh shopping incomplete ho jaayegi
            if (map[s[begin++]]++ == 0)
                counter++;
        }
    }
    // Kahani ka end:
    // Agar koi valid khidki mili toh return karo
    // warna empty string
    return d == INT_MAX ? "" : s.substr(head, d);
}

};