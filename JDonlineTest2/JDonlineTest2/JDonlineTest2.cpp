// JDonlineTest2.cpp : 定义控制台应用程序的入口点。
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

/*收到情报，有批新造的机器人要运输到前线。小C将去破坏机器人的运输。
小C将激光炮放置在公路的一旁，等运输车经过的时候发射（假设激光炮一定可以射穿车辆）。
由于能源有限，激光炮只能发射两次。可以认为激光炮放在坐标轴的原点处，并向y轴正方向发射。
每辆运输车可以看作是一个矩形，起始的x轴坐标为Xi ,所有的车均位于第一象限，长度为Li,速度为1，朝x轴负方向运动。
即经过t时间后，该车车头的x坐标为Xi-t，车尾坐标为Xi-t+Li 。只要打中车的任何一个部分就算击中。
请你算算，他在哪两个时刻发射，才能摧毁最多的运输车。

输入
第一行一个正整数 n ( 2≤N≤200 )，表示运输个的数量。
接下来n行，每行两个整数X和L(1≤X、L≤109)，表示一辆车的x轴坐标和长度。
输出
输出最多可以摧毁的运输车数量。

样例输入
4
2 2
3 1
5 2
7 3
样例输出
4

Hint
第一炮在第3秒发射，击中1号和2号运输车，此时1号和2号车身的x坐标范围分别为[-1,1]和[0,1]；
第二炮在第7秒发射，击中3号和4号运输车，此时3号和4号车身的x坐标范围分别为[-2,0]和[0,3]；*/

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

/*终结者C：
运输车相对位置不变，看成运输车不动，激光炮动，枚举放激光炮的地方
示例代码：
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