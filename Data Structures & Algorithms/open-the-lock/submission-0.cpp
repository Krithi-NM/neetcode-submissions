class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000"))
            return -1;
        queue<string> q;
        q.push("0000");
        int turns = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front();
                q.pop();

                if (curr == target)
                    return turns;
                for (int i = 0; i < 4; i++) {
                    string next = curr;

                    next[i] = (curr[i] - '0' + 1) % 10 + '0';

                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                    next[i] = (curr[i] - '0' + 9) % 10 + '0';

                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            turns++;
        }

        return -1;
    }
};