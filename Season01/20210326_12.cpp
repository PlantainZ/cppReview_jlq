#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;


/*====================================================================================
 @ title   : 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
			 路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
			 如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
			 
			 例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用[]标出）。
				[["a",["b"],"c"  ,"e"],
				 ["s",["f"],["c"],"s"],
				 ["a","d"  ,["e"],"e"]]

			 但矩阵中不包含字符串“abfb”的路径，
			 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。


 @ example : 输入：board = [["A","B","C","E"],
						    ["S","F","C","S"],
							["A","D","E","E"]], word = "ABCCED"
			 输出：true
			 ---------------------------------------------------
			 输入：board = [["a","b"],
							["c","d"]], word = "abcd"
			 输出：false

 @ limited : 1 <= board.length <= 200
			 1 <= board[i].length <= 200
======================================================================================*/


// dfs + 剪枝

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
			board[i][j] != word[k]) return false;   // 剪枝操作！
		if (k == word.size() - 1) return true;		// 如果k已经是word的最后一位，
													// 且上面的最后一个条件没把它打回去

		board[i][j] = '\0';	 // 让当前位置的board置空，防止下方滚到倒回去的方向时重复检测。
		bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||	// 向下，向上
				   dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);		// 向右，向左
		board[i][j] = word[k];	// 剪枝完成，填回去。
		return res;
	}
};






