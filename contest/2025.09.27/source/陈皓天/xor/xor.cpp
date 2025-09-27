#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c;c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
	return x*f;
}
int n,a[100005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	for(int i=0;i<n;i++) a[i]=read();
	for(int i=0,s,b;i<n;i++){
		for(int j=i+1;j<n;j++){
			s=b=a[i];
			for(int k=i+1;k<=j;k++){
				s=s^a[k],b=max(b,a[k]);
			}
			if(s<=b) ans++;
		}
	}
	cout<<ans+n;
}
