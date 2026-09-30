class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        vector<int> res(num1.size() + num2.size(), 0);
        for(int i = num1.size() - 1; i >= 0; i--) {
            for(int j = num2.size() - 1; j >= 0; j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int product = a * b;
                int sum = product + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        string ans = "";
        for(int x : res) {
            if(ans.empty() && x == 0)
                continue;
            ans += char(x + '0');
        }
        return ans;
    }
};