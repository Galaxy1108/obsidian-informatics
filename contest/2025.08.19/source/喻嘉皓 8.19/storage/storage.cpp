#include<bits/stdc++.h>
#define Min(a,b) a=min(a,b)
#define ll long long
using namespace std;
const int N=10010;
int n;
struct Node{
	int x,p,c;
}cam[N];
ll f[N];//���ǵ�i������i���ֿ����С���� 
int main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cam[i].x>>cam[i].p>>cam[i].c;
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++){
		ll sum=0;//ͳ��i��j֮���������� 
		for(int j=i;j>=1;j--){
			sum+=(ll)cam[j].p*(cam[i].x-cam[j].x);
			Min(f[i],f[j-1]+sum+cam[i].c);
		}
	}
	cout<<f[n];
	return 0;
}

