class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>seen;
        while (n!=1 && seen.find(n)==seen.end()){
            seen.insert(n);
        int num =0;
        while(n!=0){
            int dig = n%10;
            num += dig*dig;
            n=n/10;
        }
        n=num;
        } 
        return n==1;
    }
};
