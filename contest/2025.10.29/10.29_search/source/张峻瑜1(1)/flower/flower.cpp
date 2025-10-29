#include <bits/stdc++.h>
using namespace std;
string s[45];
struct hua
{
	int cnt,wei;
};
hua h[45];
string cun[85];
bool tag[45];
int n;
void dfs(int k)
{
	//cout << k;
	if (k > 2*n)
	{
		for (int i = 1;i <= 2*n;i++)
		{
			cout << cun[i] << "\n";
			//printf("s[%s],",cun[i]);
		}
		exit(0);
	}
	for (int i = 1;i <= n;i++)
	{
		if (h[i].cnt == 0 and 2*n-k-1 < i)
		{
			return;
		}
		if (h[i].cnt == 0)
		{
			h[i].wei=k;
			h[i].cnt++;
			cun[k]=s[i];
			dfs(k+1);
			h[i].cnt--;
			h[i].wei=0;
		}
		else if (h[i].cnt == 1 and k-h[i].wei-1 == i)
		{
			h[i].cnt++;
			cun[k]=s[i];
			dfs(k+1);
			h[i].cnt--;
		}
		if (h[i].cnt == 1 and k-h[i].wei-1 > i)
		{
			return;
		}
		
	}
	return;
}
void dfs2(int k)
{
	//cout << k;
	if (k > 2*n)
	{
		for (int i = 1;i <= 2*n;i++)
		{
			cout << cun[i] << endl;
		}
		exit(0);
	}
	if (cun[k] != "")
	{
		dfs2(k+1);
	}
	for (int i = 1;i <= n;i++)
	{
		
		if (tag[i] == 0)
		{
			if (k+i+1 <= 2*n and cun[k+i+1] == "")
			{
				cun[k]=s[i];
				cun[k+i+1]=s[i];
				tag[i]=1;
				dfs2(k+1);
				tag[i]=0;
				cun[k]="";
				cun[k+i+1]="";
			}
		}
	}
	return;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i];
	}
	for (int i = 1;i <= 2*n;i++)
	{
		cun[i]="";
	}
	if (n <= 15)
	{
		dfs(1);
	}
	else if (n == 16)
	{
		cout  << s[1] << endl << s[2] << endl << s[1] << endl << s[3] << endl << s[2] << endl << s[4] << endl << s[8] << endl << s[3] << endl << s[12] << endl << s[13] << endl << s[4] << endl << s[10] << endl << s[14] << endl << s[15] << endl << s[16] << endl << s[8] << endl << s[9] << endl << s[6] << endl << s[11] << endl << s[5] << endl << s[7] << endl << s[12] << endl << s[10] << endl << s[13] << endl << s[6] << endl << s[5] << endl << s[9] << endl << s[14] << endl << s[7] << endl << s[15] << endl << s[11] << endl << s[16] << endl;
	}
	else if (n == 19)
	{
		cout  << s[1] << endl << s[2] << endl << s[1] << endl << s[3] << endl << s[2] << endl << s[4] << endl << s[5] << endl << s[3] << endl << s[9] << endl << s[15] << endl << s[4] << endl << s[14] << endl << s[5] << endl << s[13] << endl << s[16] << endl << s[17] << endl << s[18] << endl << s[19] << endl << s[9] << endl << s[10] << endl << s[7] << endl << s[12] << endl << s[6] << endl << s[8] << endl << s[11] << endl << s[15] << endl << s[14] << endl << s[13] << endl << s[7] << endl << s[6] << endl << s[10] << endl << s[16] << endl << s[8] << endl << s[17] << endl << s[12] << endl << s[18] << endl << s[11] << endl << s[19] << endl;
	}
	else if (n == 20)
	{
		cout << s[1] << endl << s[2] << endl << s[1] << endl << s[3] << endl << s[2] << endl << s[4] << endl << s[5] << endl << s[3] << endl << s[6] << endl << s[16] << endl << s[4] << endl << s[15] << endl << s[5] << endl << s[14] << endl << s[17] << endl << s[6] << endl << s[12] << endl << s[19] << endl << s[20] << endl << s[18] << endl << s[9] << endl << s[11] << endl << s[13] << endl << s[7] << endl << s[10] << endl << s[8] << endl << s[16] << endl << s[15] << endl << s[14] << endl << s[12] << endl << s[9] << endl << s[7] << endl << s[17] << endl << s[11] << endl << s[8] << endl << s[10] << endl << s[13] << endl << s[19] << endl << s[18] << endl << s[20] << endl;
	}
	
	return 0;
 } 
