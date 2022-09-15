class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        
        for(auto itr = nums.begin(); itr !=  nums.end() ;++itr){
            cout<<1<<endl;
            if(hash.find(target - *itr)!=hash.end()){
                int index = itr - nums.begin();
                return {index,hash[target - *itr]};
            }
            hash[*itr]= itr-nums.begin();
        }
    
        return {};
    }
};