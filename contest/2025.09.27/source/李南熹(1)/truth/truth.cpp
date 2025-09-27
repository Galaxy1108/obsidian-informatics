#include<bits/stdc++.h>
using namespace std;
int a[50005],b[50],s=0,miku;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
signed main()
{
	freopen("truth","r",stdin);
    freopen("truth","w",stdout);
	int n,k,m;
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	while(m--){
		int op;
		op=read();
		if(op==1){
			int p,v;
			p=read(),v=read();
			a[p]=v;
		}
		if(op==2){
			int ans=100000,r=1,cnt=0,flag=0;
			if(s==2){
				cout<<miku<<endl;
				continue;
			}
			memset(b,0,sizeof(b));
			for(int i=1;i<=n;i++){
		        b[a[i]]++;
		        if(b[a[i]]==1) cnt++;
		        if(cnt==k){
			        while(1){
				        if(b[a[r]]==1) break;
				        b[a[r]]--;
				        r++;
			        }
			        ans=min(ans,i-r+1);
			        if(ans==k) break;
		        }
	        }
	        if(ans==100000) ans=-1;
	        miku=ans;
	        cout<<ans<<endl;
		}
		s=op;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
