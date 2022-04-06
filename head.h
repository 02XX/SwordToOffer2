#ifndef HEAD_H_
#define HEAD_H_
//data struct
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

//lib
#include"Transfer.h"
#include<iostream>
#include<algorithm>
#include<cmath>
//STL
#include<string>
#include<vector>

#include<queue>
#include<deque>

#include<stack>

#include<map>
#include<unordered_map>

#include<set>

#include<list>
#include<forward_list>



using namespace std;
#endif