#include<bits/stdc++.h>
using namespace std;
int h[2000006],maxx[2000006][35],minn[2000006][35];
unsigned long long ans;
int find1(int le,int ri){
	int lg=log2(ri-le+1);
	return max(maxx[le][lg],maxx[ri-(1<<lg)+1][lg]);
}
int find2(int le,int ri){
	int lg=log2(ri-le+1);
	return min(minn[le][lg],minn[ri-(1<<lg)+1][lg]);
}
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		maxx[i][0]=h[i];
		minn[i][0]=h[i];
	}
	for(int j=1;j<=25;j++){
		for(int i=1;(i+(1<<j)-1)<=n;i++){
			maxx[i][j]=max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]);
			minn[i][j]=min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
		}
	}
	ans=1;
	int k=1;
	unsigned long long sum=1;
	for(int i=2;i<=n;i++){
		for(int j=k;j<i;j++){
			int a=find1(j,i),b=find2(j,i);
			int ll=i-j+1;
			sum=a*b*ll;
			if(sum<ans&&j==k) break;
			else if(j!=k&&sum>=ans) k=j;
			else if(sum<ans) continue; 
			ans=sum;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
	/*9
	5 11 15 17 19 3 19 9 4
	*/
 } 
