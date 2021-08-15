#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region week_1  // 第一周
vector<int> twoSum(vector<int>& nums, int target);
void rotate(vector<int>& nums, int k);
#pragma endregion

#pragma region week_1  // 第二周
bool isAnagram(string s, string t);
vector<int> topKFrequent(vector<int>& nums, int k);
#pragma endregion


int main() {
//    int nums1[] = [2,7,11,15];
    vector<int> nums{1,1,1,2,2,3};
    topKFrequent(nums,2);
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

#pragma region week_2 // 第二周

// 242 有效的字母异位词 https://leetcode-cn.com/problems/valid-anagram/description/
// 若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
// 等价于s和t排序后相等
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// 347. 前 K 个高频元素
struct CmpByValue {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> nums_count;
    for (int i = 0; i < nums.size(); ++i) {
        int key = nums[i];
        int vaule = nums_count[key];
        ++vaule;
        nums_count[key] = vaule;
    }
    vector<pair<int, int>> nums_count_vec(nums_count.begin(), nums_count.end());
    sort(nums_count_vec.begin(), nums_count_vec.end(), CmpByValue());
    vector<int> res(k);
    for (int i = 0; i < k; ++i) {
        res[i] = nums_count_vec[i].first;
    }
    return res;
}


#pragma endregion