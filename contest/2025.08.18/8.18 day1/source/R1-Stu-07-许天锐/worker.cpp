#include<bits/stdc++.h>
using namespace std;
int n;
int a[151],f[101][11][11][11],cnt[151][3];
int main(){
//	freopen("worker.in","r",stdin);
//	freopen("worker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		a[i]=ch-'A';
		for(int j=0;j<=2;j++)cnt[i][j]=cnt[i-1][j];
		cnt[i][a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=max(1,i-30);j<i;j++)
		{
			for(int c0=0;c0<=cnt[i][0]-cnt[j-1][0];c0++){
				for(int c1=0;c1<=cnt[i][1]-cnt[j-1][1];c1++){
					for(int c2=0;c2<=cnt[i][2]-cnt[j-1][2];c2++){
						if(i-j+1<=10)
						{
							
						}
					}
				}
			}
		}
	 } 
	cout<<(n%17==0?n/17:n/17+1)*3<<endl;
	return 0;
}
/*
ABCABBACBACBCBABACBACBCBABABCBABAB
*/
