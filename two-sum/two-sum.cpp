class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans ;
        unordered_map<int, int> mp ;
        
        for (int i = 0; i < nums.size() ; i++){
            int other = target - nums[i];
            
            if ( mp.find(other) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp.at(other));
                return ans;
            }
            
            mp[nums[i]] =  i;
        }
        
        return ans;
    }
};