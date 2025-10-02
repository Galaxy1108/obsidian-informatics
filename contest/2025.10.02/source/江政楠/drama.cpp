#include<bits/stdc++.h>
using namespace std;
long long a[100005];
void print(__int128 x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)print(x / 10);
    putchar(x%10+'0');
}
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	int n;
	cin>>n;
	__int128 ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		__int128 minn=1e9+5;
		__int128 maxn=0;
		for(int j=i;j<=n;j++){
			__int128 x=a[j];
			minn=min(x,minn);
			maxn=max(x,maxn);
			ans=max(ans,maxn*minn*(j-i+1));
		}
	}
	print(ans);
	return 0;
}
