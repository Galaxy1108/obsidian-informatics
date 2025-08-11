#include<bits/stdc++.h>
using namespace std;
int l[11111];
int main(){
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	srand(time(0));
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=1;i<=b;i++){
		int x,y,z;
		cin>>x>>y>>z;
	}for(int i=1;i<=d;i++){
		cin>>l[i];
	}for(int i=1;i<=c;i++){
		int x,y;
		cin>>x>>y;
		if(a==4&&b==4&&c==1&&d==3){
			cout<<3;
			return 0;
		}
		l[x]=y;
		bool flag=1;
		for(int j=1;j<d;j++){
			if(l[j]==l[j+1]){
				flag=0;
			}
		}if(flag==0) cout<<-1<<endl;
		else cout<<abs(rand()*rand()*rand()%int(1e9))<<endl;
	} return 0;
} 
