class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<long long, 3>> v;
        
        for (int i = 0; i < n; i++) {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(v.begin(), v.end());
        
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;
        
        vector<int> ans;
        long long curr = 0;
        int i = 0;
        
        while (i < n || !pq.empty()) {
            
            if (pq.empty() && curr < v[i][0])
                curr = v[i][0];
            
            while (i < n && v[i][0] <= curr) {
                pq.push({v[i][1], v[i][2]});
                i++;
            }
            
            auto [time, index] = pq.top();
            pq.pop();
            
            ans.push_back(index);
            curr += time;
        }
        
        return ans;
    }
};