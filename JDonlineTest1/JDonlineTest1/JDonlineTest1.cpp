// JDonlineTest1.cpp : �������̨Ӧ�ó������ڵ㡣
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

/*��������ǳ����Ķ��������㣬��������nλ��������a��b��a���b���������ο��Ƕ����Ƶ�ÿһλ������һλ��ͬ����ô��һλ�����������0����ͬ����1��
����a=1100, b=0100��ִ��a���b�����㣬a�����λ��1��b�����λ��0���������ֲ�ͬ�������λ�������1��a��b�θ�λ����1��
���Դθ�λ���Ϊ0�������λ���Ƕ���0�����������Ҳ����0����ôa���b�Ĵ𰸾���1000��
������������nλ������������������������ʮ���ƴ𰸡��������������Ķ����ƽ��Ϊ1000��ת����ʮ���ƾ���8��
����
���������У���һ��һ����n(1<=n<=20)������������������nλ��������������Ķ�������������ǰ���㡣
���
���һ�������������ʮ������ֵ����Ҫ���ǰ���㡣 

��������
4
1100
0100
�������
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

