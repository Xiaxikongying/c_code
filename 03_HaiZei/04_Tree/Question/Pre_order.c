#include <stdio.h>
#include <stdlib.h>
#include <vector>

// leetcode 895

/*
给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。
 n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

输入：root = [1,null,3,2,4,null,5,6]
输出：[1,3,5,6,2,4]
*/


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        if (root == NULL)
            return vector<int>();

        vector<int> ans;
        ans.push_back(root->val);
        for(auto x :root->children)
        {
            vector<int> temp = preorder(x);\
            for(auto y:temp)
                ans.push_back(y);
        }
        return ans;
    }
};