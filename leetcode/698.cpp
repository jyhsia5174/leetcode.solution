// 698. Partition to K Equal Sum Subsets
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(auto &v: nums)
            sum += v;
        int target = sum / k;
        if( sum % k || nums[n-1] > target ) return false;
        
        vector<bool> dp(1<<n, false);
        dp[0] = true;
        vector<int> total(1<<n, 0);
        
        for(int state = 0; state < (1<<n); state++){
            if(!dp[state]) continue;
            for(int i = 0; i < n; i++){
                int future = state | (1<<i);
                if( state != future && !dp[future] ){
                    if(nums[i] <= target - (total[state] % target)){
                        dp[future] = true;
                        total[future] = total[state] + nums[i];
                    }
                    else{
                        break;
                    }
                }
            }
        }
        
        return dp[(1<<n)-1];
    }
};

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for(auto &v: nums)
            total += v;
        if( total % k != 0 ) return false;
        
        vector<int> cache(1<<nums.size(), 0);
        cache[(1<<nums.size())-1] = 1;
        return search(0, total, cache, nums, total / k);
    }
    
    bool search(int used, int todo, vector<int> &cache, 
                const vector<int>& nums, int subsum){
        if( cache[used] == 0 ){
            cache[used] = -1;
            int targ = (todo-1) % subsum + 1;
            for(int i = 0; i < nums.size(); i++){
                if( (((used>>i) & 1)==0) && nums[i] <= targ ){
                    if( search(used | (1<<i), todo - nums[i], cache, nums, subsum) ){
                        cache[used] = 1;
                        break;
                    }
                }
            }
        }
        
        assert( cache[used] != 0 );
        if( cache[used] == 1 )
            return true;
        return false;
    }
};
