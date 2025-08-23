/*
洛谷 / 讨论列表 / 讨论详情 
请求将此题降绿
版块AT2370 [A...
楼主hrgd
发帖时间2022-10-05 08:31
题目AT2370 [AGC013D] Piling Up
 

 
@hrgd 2022-10-05 08:31 回复
RT，既然有人能把它搬到 NOIP 模拟赛 T1 的话。

 
@陈刀仔  2022-10-05 08:32 回复 举报
/tx

 
@_cyle_King  2022-10-05 08:39 回复 举报
啊这，AGC 的 D 题啊。

 
@IdnadRev 2022-10-05 08:39 回复 举报
确实。

 
@liqingyang  2022-10-05 08:42 回复 举报
事实上往届联考可能从来没有签到题

 
@今天也要开心a 2022-10-05 08:43 回复 举报
高效

 
@CoCo_Candy 2022-10-05 08:45 回复 举报
没保证题目按难度排序

 
@Itst 2022-10-05 08:45 回复 举报
原来想把什么题变成绿题只要放模拟赛 T1 就行

 
@Aonynation 2022-10-05 08:47 回复 举报
@hrgd 原题自动机

 
@10circle 2022-10-05 08:47 回复 举报
什么离谱，什么时候 AGC 的 D 都能做 NOIP T1 了。

 
@10circle 2022-10-05 08:48 回复 举报
@10circle kenkoooo 上评分 3000+。怎么回事呢。

@ta3b  2022-10-05 08:55 回复 举报
别骂了

 
@kirihara233 2022-10-05 09:04 回复 举报
我的第一反应告诉我是排列组合。

 
@Raymondzll  2022-10-05 09:14 回复 举报
我觉得是蓝

 
@_cyle_King  2022-10-05 09:22 回复 举报
还是等着有能力不看题解就能切掉这个题的 dalao 来评难度吧。

 
@hrgd 2022-10-05 09:30 回复 举报
@_cyle_King 你想我既然敢这么说，那我就是已经过了对不对

 
@zhouyuhang 2022-10-05 09:31 回复 举报
神了

 
@_cyle_King  2022-10-05 09:31 回复 举报
@hrgd 是赛时过的吗？

 
@Pasw 2022-10-05 09:44 回复 举报
@_cyle_King 这场比赛是2017年的

 
@_cyle_King  2022-10-05 09:45 回复 举报
@Pasw 赛时，指的是模拟赛。

 
@yangruibin  2022-10-05 09:50 回复 举报
乐，乐死了

《easyhard》

@有素质的2B铅笔 2022-10-05 09:51 回复 举报
《easyhard》 新概念T1

 
@yangruibin  2022-10-05 09:56 回复 举报
noip人均会AGC的D捏

 
@CoCo_Candy 2022-10-05 09:57 回复 举报
noip人均爆切AGC

 
@卞宇轩  2022-10-05 10:01 回复 举报
@chufuzhe 艹

 
@hrgd 2022-10-05 10:01 回复 举报
easyhard

 
@Ex_咖喱棒 2022-10-05 10:01 回复 举报
这都不会退役吧（

 
@hrgd 2022-10-05 10:02 回复 举报
@Ex_咖喱棒 ？

 
@卞宇轩  2022-10-05 10:02 回复 举报
但感觉真的不应该有黑

 
@卞宇轩  2022-10-05 10:03 回复 举报
蓝±

 
@Karl_Aurora  2022-10-05 10:08 回复 举报 删除
@卞宇轩 %%%

@Karl_Aurora  2022-10-05 10:09 回复 举报 删除
三道原题，这模拟赛还不爆破？

 
@Karl_Aurora  2022-10-05 10:09 回复 举报 删除
（

 
@hrgd 2022-10-05 10:10 回复 举报
@Karl_Aurora 能看看私信吗？/kel

 
@yangruibin  2022-10-05 10:11 回复 举报
建议把题解复制下来注释放在程序开头（

 
@luo_shen  2022-10-05 10:12 回复 举报
@Ex_咖喱棒 %%%

 
@yangruibin  2022-10-05 10:17 回复 举报
https://www.luogu.com.cn/paste/zjk7jp7o

 
@Ex_咖喱棒 2022-10-05 10:17 回复 举报
我们机房已经把题解复制下来提交到代码里了

 
@Karl_Aurora  2022-10-05 10:17 回复 举报 删除
机房里顿时洋溢着欢乐的氛围.jpg
*/
#include <bits/stdc++.h>
#define maxn 3010
#define ll long long
using namespace std;
char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
template < typename T >
inline void read(T &X) 
{
	X = 0; bool f = false; char ch = getchar();
	while (ch < '0' || ch > '9') {f |= ch == '-'; ch = getchar();}
	while (ch >= '0' && ch <= '9') {X = X * 10 + (ch ^ 48); ch = getchar();}
	X = f ? -X : X;
	return;
}
template < typename T >
inline void write(T X) 
{
	if (X == 0) {*O++ = '0'; return;}
	if (X < 0) {*O++ = '-'; X = -X;}
	static int cnt = 0, num[21];
	while (X) {num[++cnt] = X % 10; X /= 10;}
	while (cnt) *O++ = num[cnt--] ^ 48;
	return;
}
ll quickpow(ll a, ll k, ll p)
{
	ll x = 1;
	while (k)
	{
		if (k & 1) x = (x * a) % p;
		a = (a * a) % p; k >>= 1;
	}
	return x;
}
ll n, m, p;

//sol from ez_lcw
int dp[maxn][maxn];
int solve(int n)
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=n;i++) dp[0][i]=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%p;//先白后黑 
			if(n-j) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%p;//先黑后白 
			if(j) dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%p;//白白 
			if(n-j) dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%p;//黑黑
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=(ans+dp[m][i])%p;
	return ans;
}

int main()
{
	freopen("easyhard.in", "r", stdin);
	freopen("easyhard.out", "w", stdout);
	read(n); read(m); read(p);
	if (n >= m) {write(quickpow(2, m << 1, p)); fwrite(obuf, O - obuf, 1, stdout); return 0;}
	write((solve(n) - solve(n - 1) + p) % p);
	fwrite(obuf, O - obuf, 1, stdout);
	return 0;
}