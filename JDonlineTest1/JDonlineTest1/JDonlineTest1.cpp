// JDonlineTest1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

/*异或运算是常见的二进制运算，给出两个n位二进制数a，b。a异或b的运算依次考虑二进制的每一位，若这一位相同，那么这一位的异或结果就是0，不同就是1。
例如a=1100, b=0100。执行a异或b的运算，a的最高位是1，b的最高位是0，两个数字不同所以最高位异或结果是1；a和b次高位都是1，
所以次高位异或为0；最后两位它们都是0，所以异或结果也都是0。那么a异或b的答案就是1000。
现在输入两个n位二进制数，输出它们异或结果的十进制答案。上述样例中异或的二进制结果为1000，转化成十进制就是8。
输入
输入有三行，第一行一个数n(1<=n<=20)，接下来两行有两个n位二进制数。输入的二进制数可能有前导零。
输出
输出一个数，异或结果的十进制数值，不要输出前导零。 

样例输入
4
1100
0100
样例输出
8*/

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	string num1;
	string num2;
	int num;
	int ans = 0;
	while (cin>>n)
	{
		cin >> num1;
		cin >> num2;
		for (int i = 0; i < n; i++)
		{
			num = int(num1[i]) ^ int(num2[i]);
			ans += num*pow(2, n - i - 1);
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}

