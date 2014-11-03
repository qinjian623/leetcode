//
//  Operation.h
//  LeetCode
//
//  Created by QinJian on 14/11/1.
//  Copyright (c) 2014年 QinJian. All rights reserved.
//

#ifndef LeetCode_Operation_h
#define LeetCode_Operation_h
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif
