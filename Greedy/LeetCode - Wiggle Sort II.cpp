// https://leetcode.com/problems/wiggle-sort-ii/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());

        int odd = 1;
        int even = 0;
        int half = (nums.size() % 2 == 0 ? nums.size()/2 : nums.size()/2 + 1);

        for(int i=half-1; i>=0; i--){
            nums[even] = temp[i];
            even += 2;
        }

        for(int i=nums.size()-1; i>=half; i--){
            nums[odd] = temp[i];
            odd += 2;
        }
    }
};