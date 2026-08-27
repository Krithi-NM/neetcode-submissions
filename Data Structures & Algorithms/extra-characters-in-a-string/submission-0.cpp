class Solution {
public:
    int solve(int i, string &s, unordered_set<string> &st,
              vector<int> &dp) {
        if (i == s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        // Option 1: Current character ko extra maan lo
        int ans = 1 + solve(i + 1, s, st, dp);
        // Option 2: Dictionary ke words try karo
        for (int j = i; j < s.size(); j++) {
            string word = s.substr(i, j - i + 1);

            if (st.count(word)) {
                ans = min(ans,solve(j + 1, s, st, dp));
            }
        }

        return dp[i] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size(), -1);
        return solve(0, s, st, dp);
    }
};