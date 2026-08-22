class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for(char c : s)
            freq[c]++;

        priority_queue<pair<int, char>> pq;
        int maxFreq = 0;
        for(auto it : freq) {
            pq.push({it.second, it.first});
            maxFreq = max(maxFreq, it.second);
        }
        if(maxFreq > (s.size() + 1) / 2)
            return "";

        string ans = "";
        pair<int, char> prev = {0, '#'};

        while(!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();

            ans += ch;
            count--;

            if(prev.first > 0)
                pq.push(prev);

            prev = {count, ch};
        }

        return ans;
    }
};