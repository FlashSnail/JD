// JDonlineTest2.cpp : �������̨Ӧ�ó������ڵ㡣
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

/*�յ��鱨����������Ļ�����Ҫ���䵽ǰ�ߡ�СC��ȥ�ƻ������˵����䡣
СC�������ڷ����ڹ�·��һ�ԣ������䳵������ʱ���䣨���輤����һ�������䴩��������
������Դ���ޣ�������ֻ�ܷ������Ρ�������Ϊ�����ڷ����������ԭ�㴦������y���������䡣
ÿ�����䳵���Կ�����һ�����Σ���ʼ��x������ΪXi ,���еĳ���λ�ڵ�һ���ޣ�����ΪLi,�ٶ�Ϊ1����x�Ḻ�����˶���
������tʱ��󣬸ó���ͷ��x����ΪXi-t����β����ΪXi-t+Li ��ֻҪ���г����κ�һ�����־�����С�
�������㣬����������ʱ�̷��䣬���ܴݻ��������䳵��

����
��һ��һ�������� n ( 2��N��200 )����ʾ�������������
������n�У�ÿ����������X��L(1��X��L��109)����ʾһ������x������ͳ��ȡ�
���
��������Դݻٵ����䳵������

��������
4
2 2
3 1
5 2
7 3
�������
4

Hint
��һ���ڵ�3�뷢�䣬����1�ź�2�����䳵����ʱ1�ź�2�ų����x���귶Χ�ֱ�Ϊ[-1,1]��[0,1]��
�ڶ����ڵ�7�뷢�䣬����3�ź�4�����䳵����ʱ3�ź�4�ų����x���귶Χ�ֱ�Ϊ[-2,0]��[0,3]��*/

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	map<int, vector<int>> vec;
	map<int, vector<int>> time;
	map<int, vector<int>>::iterator it_time;
	map<int, vector<int>>::iterator iteri;
	map<int, vector<int>>::iterator iterj;
	int x, L;
	int boom;
	while (cin>>n)
	{
		boom = 0;
		vector<int> ans;
		ans.clear();
		ans.resize(2);
		for (int i = 0; i < n; i++)
		{
			cin >> x >> L;
			vec[i].push_back(x);
			vec[i].push_back(L);
			time[i].push_back(x);
			time[i].push_back(x + L);
		}
		for (int i = 0; i < n && boom < 2; i++)
		{
			iteri = time.find(i);
			for (int j = i+1; j < n; j++)
			{
				iterj = time.find(j);
				if ((iteri->second[0] <= iterj->second[0] && iteri->second[1] >= iterj->second[1]) 
					|| (iteri->second[0] <= iterj->second[0] && iteri->second[1] >= iterj->second[0])
					|| (iteri->second[0] >= iterj->second[0] && iteri->second[0] <= iterj->second[1]))
				{
					ans[boom]++;
					i++;
				}
			}
			boom++;
		}
		int sum = 0;
		if (ans[0] != 0)
		{
			sum += ans[0] + 1;
		}
		if (ans[1] != 0)
		{
			sum += ans[1] + 1;
		}
		cout << sum << endl;
		time.clear();
		vec.clear();
	}
	system("pause");
	return 0;
}

/*�ս���C��
���䳵���λ�ò��䣬�������䳵�����������ڶ���ö�ٷż����ڵĵط�
ʾ�����룺
#include<cstdio>
#include<cstring>
int a[205],b[205],c[205];
bool q(int w,int e){
	return a[e]<=a[w]&&b[e]>=a[w];
}
int n;
int s(int w,int e){
	int re=0;
	for(int i=1;i<=n;i++)
		if(q(w,i)||q(e,i))re++;
	return re;
}
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int l;
		scanf("%d %d",&a[i],&l);
		b[i]=a[i]+l;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
				int k=s(i,j);
				if(k>ans)ans=k;
			}
	printf("%d\n",ans); 
} 
int main(){ 
	work(); 
	return 0;
	}*/