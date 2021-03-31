#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;


/*====================================================================================
 @ title   : �����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
			 ·�����ԴӾ����е�����һ��ʼ��ÿһ�������ھ����������ҡ��ϡ����ƶ�һ��
			 ���һ��·�������˾����ĳһ����ô��·�������ٴν���ø��ӡ�
			 
			 ���磬�������3��4�ľ����а���һ���ַ�����bfce����·����·���е���ĸ��[]�������
				[["a",["b"],"c"  ,"e"],
				 ["s",["f"],["c"],"s"],
				 ["a","d"  ,["e"],"e"]]

			 �������в������ַ�����abfb����·����
			 ��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�


 @ example : ���룺board = [["A","B","C","E"],
						    ["S","F","C","S"],
							["A","D","E","E"]], word = "ABCCED"
			 �����true
			 ---------------------------------------------------
			 ���룺board = [["a","b"],
							["c","d"]], word = "abcd"
			 �����false

 @ limited : 1 <= board.length <= 200
			 1 <= board[i].length <= 200
======================================================================================*/


// dfs + ��֦

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		rows = board.size();
		cols = board[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (dfs(board, word, i, j, 0)) return true;
			}
		}
		return false;
	}

private:
	int rows, cols;
	bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
		if (i >= rows || i < 0 ||
			j >= cols || j < 0 || 
			board[i][j] != word[k]) return false;   // ��֦������
		if (k == word.size() - 1) return true;		// ���k�Ѿ���word�����һλ��
													// ����������һ������û�������ȥ

		board[i][j] = '\0';	 // �õ�ǰλ�õ�board�ÿգ���ֹ�·���������ȥ�ķ���ʱ�ظ���⡣
		bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||	// ���£�����
				   dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);		// ���ң�����
		board[i][j] = word[k];	// ��֦��ɣ����ȥ��
		return res;
	}
};






