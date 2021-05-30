#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class KMP
{
public:
	vector<int> arr,next;
	string x;

private:

	void preKmp(string x, int m, vector<int>& next) { // 生成next模式串回滚位置指示数组
		int i, j;
		// 初试化。i为试探位
		i = 0;
		j = next[0] = -1;

		while (i < m) { // 重点关注的是，j指示位置的前缀。注意失配指的是主串失配，不是这个模式串失配。
			// 如果j位置 一直！= i位置的char，那就不停倒回去上一个指示位置（这些指示位置都是因为前缀相同）
			// 直到x[i]=x[j] 或者 j<1 那就出while了。
			// 使得在目前位置，i和j走过的char都是完全相同的
			while (j >= 1 && x[i] != x[j]) j = next[j];

			i++; // 然后进行下一组char匹配
			j++;

			if (x[i] == x[j]) next[i] = next[j]; // 如果它们两个的char相同，那么主串在i位置失配，那么在j位置也是失配的
			else next[i] = j; // 上一行的反例。当前x[j]不一定和x[i]相配，但是两者的前缀一样。
			// 谁知道主串是什么字母呢，所以不会继续往前钻。
		}
	}


	void kmp(string p, string t) {
		int m = p.length();
		int n = t.length();

		const char* x = p.c_str(); // 这样用也可以！x是模式串
		const char* y = t.c_str(); // y是主串
		/*--------------------------------------------------------------------------
		string-->char*
		char* x = p.c_str();
		c_str()：返回一个临时的const char*指针，一个指向正规C字符串的指针，不能对其进行操作
				 这是为了与c语言兼容，在c语言中没有string类型，
				 故必须通过string类对象的成员函数c_str()把string 对象转换成c中的字符串样式。
 
		string变成什么，这个指针就会变成什么。如果string被析构，那么这个指针就会懵逼。
		----------------------------------------------------------------------------*/
		int i = 0, j = 0;
		vector<int> next;
		preKmp(x, m, next); // 生成next数组，供模式串倒车用。

		while (j < n) { // 此时j指的是主串，主串要遍历完才算结束
			while (i > -1 && x[i] != y[i]) i = next[i]; // 主串和模式串失配，就让模式串倒车，确保和模式串的char相同。
			i++;
			j++;

			if (i >= m) { // 此时已经遍历完一次模式串
				cout << "Matching index found at:" << j - i << endl; // j-i 是在主串中，找到模式串第一个char开始的位置
				i = next[i]; // 已匹配完成，返回可匹配的上个前缀处
						     //（主串还没检查匹配完！模式串内容在主串中可能会发生重叠。）
			}
		}
	}

};