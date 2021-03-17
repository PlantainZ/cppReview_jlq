#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

/*====================================================================================
 @ title   : 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
			 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 @ example : 前序遍历 preorder = [3,9,20,15,7]
			 中序遍历 inorder = [9,3,15,20,7]
			 返回：
					 3
					/ \
					9  20
			  		  /  \
					 15   7

 @ limited : 0 <= 节点个数 <= 5000
======================================================================================*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution
{
public:
	TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder){
		return recursionBuild(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
	

	TreeNode* recursionBuild(vector<int>::iterator preBegin,
							 vector<int>::iterator preEnd,
							 vector<int>::iterator inBegin,
							 vector<int>::iterator inEnd) {
		if (inEnd == inBegin) return NULL;
		TreeNode* cur = new TreeNode(*preBegin);
		auto root = find(inBegin, inEnd, *preBegin); // 从inBegin ~ inEnd之间,找到*preBegin的位置并返回索引
		cur->left = recursionBuild(preBegin + 1, preBegin + 1 + (root - inBegin), inBegin, root);  // 两行右边的均取不到，只是作边界值。
		cur->right = recursionBuild(preBegin + 1 + (root - inBegin), preEnd, root + 1, inEnd);		// 两行左边的为包含在right的元素，应当包含。
		return cur;
	}
};