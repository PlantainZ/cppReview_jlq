#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

/*====================================================================================
 @ title   : ����ĳ��������ǰ���������������Ľ�������ؽ��ö�������
			 ���������ǰ���������������Ľ���ж������ظ������֡�

 @ example : ǰ����� preorder = [3,9,20,15,7]
			 ������� inorder = [9,3,15,20,7]
			 ���أ�
					 3
					/ \
					9  20
			  		  /  \
					 15   7

 @ limited : 0 <= �ڵ���� <= 5000
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
		auto root = find(inBegin, inEnd, *preBegin); // ��inBegin ~ inEnd֮��,�ҵ�*preBegin��λ�ò���������
		cur->left = recursionBuild(preBegin + 1, preBegin + 1 + (root - inBegin), inBegin, root);  // �����ұߵľ�ȡ������ֻ�����߽�ֵ��
		cur->right = recursionBuild(preBegin + 1 + (root - inBegin), preEnd, root + 1, inEnd);		// ������ߵ�Ϊ������right��Ԫ�أ�Ӧ��������
		return cur;
	}
};