#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region week_1  // 第一周

vector<int> twoSum(vector<int>& nums, int target);
void rotate(vector<int>& nums, int k);

#pragma endregion

int main() {
//    int nums1[] = [2,7,11,15];
    vector<int> nums{-1,-100,3,99};
     rotate(nums,2);
    return 0;
}
#pragma region week_1 // 第一周
// 1. 两数之和 https://leetcode-cn.com/problems/two-sum/
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        auto iter = map.find(complement);
        if (iter != map.end()) {
            return vector<int>{iter->second,i};
        }
        map[nums[i]]=i;
    }
}

//  186. 旋转数据 https://leetcode-cn.com/problems/rotate-array/
void rotate(vector<int>& nums, int k) {
    vector<int> rs(nums.size());
    for (int i = 0; i < nums.size(); ++i)
    {
        rs[(i+k)%nums.size()] = nums[i];
    }
    nums.assign(rs.begin(),rs.end());
}
#pragma endregion