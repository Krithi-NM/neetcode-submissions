class Solution { 
public: 
    int subarraySum(vector<int>& nums, int k) { 
        int count = 0; 
        int prefixsum = 0; 

        unordered_map<int,int>m; 
        m[0] = 1; 

        for (int i=0; i<nums.size(); i++){ 
            prefixsum += nums[i]; 

            int val = prefixsum-k; 
            if (m.find(val)!=m.end()){ 
                count += m[val]; 
            } 
            m[prefixsum]++; 
        } 
        return count; 
    } 
};