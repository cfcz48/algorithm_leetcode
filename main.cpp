#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

#pragma region week_1  // 第一周

vector<int> twoSum(vector<int> &nums, int target);

void rotate(vector<int> &nums, int k);

#pragma endregion

#pragma region week_2  // 第二周

bool isAnagram(string s, string t);

vector<int> topKFrequent(vector<int> &nums, int k);

#pragma endregion

#pragma region week_3// 第三周
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
vector<vector<int>> combine(int n, int k);

#pragma endregion


int main() {
    combine(4,2);
    return 0;
}

#pragma region week_1 // 第一周

// 1. 两数之和 https://leetcode-cn.com/problems/two-sum/
vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        auto iter = map.find(complement);
        if (iter != map.end()) {
            return vector<int>{iter->second, i};
        }
        map[nums[i]] = i;
    }
}

//  186. 旋转数据 https://leetcode-cn.com/problems/rotate-array/
void rotate(vector<int> &nums, int k) {
    vector<int> rs(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        rs[(i + k) % nums.size()] = nums[i];
    }
    nums.assign(rs.begin(), rs.end());
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
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    }
};

vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> nums_count;
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

#pragma region week_3


// 105 从前序与中序遍历序列构造二叉树 https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[0]);
    stack<TreeNode *> stack;
    stack.push(root);
    int inorderIndex = 0;
    for (int i = 1; i < preorder.size(); ++i) {
        int preorderVal = preorder[i];
        TreeNode *node = stack.top();
        if (node->val != inorder[inorderIndex]) {
            node->left = new TreeNode(preorderVal);
            stack.push(node->left);
        } else {
            while (!stack.empty() && stack.top()->val == inorder[inorderIndex]) {
                node = stack.top();
                stack.pop();
                ++inorderIndex;
            }
            node->right = new TreeNode(preorderVal);
            stack.push(node->right);
        }
    }
    return root;
}
// 77. 组合 https://leetcode-cn.com/problems/combinations/
vector<vector<int>> combine(int n, int k) {
    vector<int> temp;
    vector<vector<int>> res;
    for (int i = 1; i <= k; i++) {
        temp.push_back(i);
    }
    temp.push_back(n + 1);

    int j = 0;
    while (j < k) {
        res.emplace_back(temp.begin(), temp.begin() + k);
        j = 0;
        while (j < k && temp[j] + 1 == temp[j + 1]) {
            temp[j] = j + 1;
            j++;
        }
        temp[j]++;
    }
    return res;
}


#pragma endregion