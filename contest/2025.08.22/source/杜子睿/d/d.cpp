#include<bits/stdc++.h>
using namespace std;
int t,n,x[100005],q;
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int flag=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=3&&x[i]-x[i-1]!=x[i-1]-x[i-2])
				flag=0;
		}
		cin>>q;
		for(int i=0;i<q;i++){
			int l,r;
			cin>>l>>r;
			if(l==r){
				cout<<"0 "<<x[l]<<" 1\n";
				continue;
			}
			if(flag==1){
				cout<<x[r]-x[r-1]<<" "<<x[l]<<" 1\n";
				continue;
			}
			int a,b,c;
			int f=1;
			for(c=1;c<=10&f;c++)
				for(a=0;a<=10&f;a++)
					for(b=0;b<=10&f;b++){
						int ff=1;
						for(int j=l;j<=r;j++)
							if(int((a*(j-l)+b)/c)!=x[j])
								ff=0;
						if(ff==1){
							cout<<a<<" "<<b<<" "<<c<<endl;
							f=0;
						}
					}
		}	
	}
	return 0;
}

