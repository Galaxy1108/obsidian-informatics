#include <bits/stdc++.h>
using namespace std;
const int N=8e3+10;
int n;
struct T{
    int wi,ui,ti;
}p[N];
int w[50]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int f[25][25000],dp[25][25000][2];
int dfs(int pos,int time,int flag){
    if(time>p[n].ti)return 0;
    for(int i=1;i<=20;i++){
        for(int j=1;j<=p[n].ti;j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    if(flag==1){
        for(int i=1;i<=n;i++){
            if(p[i].ti-time==0&&p[i].wi==15){
                f[pos][time]=0;
                cout << 145145 << endl; 
                return 0;
            }
        }
        cout << 1919810 << endl;
        f[pos][time]=dfs(pos,time+1,0);
    }
    else{
        for(int i=1;i<=n;i++){
            if(p[i].ti-time==0&&p[i].wi==15){
            	cout << 432132 <<endl;
                f[pos][time]=dfs(p[i].ui,time+1,1)+50;
                return f[pos][time];
            }
        }
        for(int i=1;i<=n;i++){
            if(abs(p[i].ui-pos)<=2&&p[i].ui!=pos&&p[i].ti-time==0){
                f[pos][time]=max(dfs(p[i].ui,time+1,1)+w[p[i].wi],f[pos][time]);
            }
        }
    }
    return f[pos][time];
}
int main(){
    freopen("sniper.in","r",stdin);
    freopen("sniper.out","w",stdout);
    memset(f,0,sizeof(f));
    cin >> n;
    int maxl=-1;
    for(int i=1;i<=n;i++){
        cin >> p[i].wi >> p[i].ui >> p[i].ti;
        dp[p[i].ui][p[i].ti][1]=w[p[i].wi],dp[p[i].ui][p[i].ti][0]=0;
//        cout << w[p[i].wi] << endl;
        maxl=max(p[i].ui,maxl);
    }
//    for(int i=1;i<=n;i++){
//        dfs(p[i].ui,p[i].ti,0);
//        puts("\n---\n\n");
//    }	

	for(int i=1;i<=maxl;i++){
		for(int j=1;j<=p[n].ti;j++){
			for(int k=1;k<=n;k++){
				if(p[k].ti-j!=0)continue;
				if(p[k].wi==15){
					if(abs(i-p[k].ui)>2)continue;
					else{
						if(dp[i][j-1][0]!=-1)dp[p[k].ui][j][1]=max(dp[i][j-1][0]+50,dp[p[k].ui][j][1]);
					}
					dp[p[k].ui][j][0]=-1;
				}
				else {
					if(abs(i-p[k].ui)>2)continue;
					if(dp[i][j-1][0]!=-1){
						dp[p[k].ui][j][1]=max(dp[i][j-1][0]+w[p[k].wi],dp[p[k].ui][j][1]);
						dp[p[k].ui][j][0]=max(dp[p[k].ui][j][0],max(dp[i][j-1][0],dp[i][j-1][1]));
					}
					
				}
			}
		}
	}
    int ans=0;
    for(int i=0;i<=maxl;i++){
        for(int j=0;j<=p[n].ti;j++){
//            cout << dp[i][j][0] << " ";
            ans=max(dp[i][j][0],ans);
        }
//        cout << endl;
    }
    // cout << ans << endl;
    for(int i=0;i<=maxl;i++){
        for(int j=0;j<=p[n].ti;j++){
//            cout << dp[i][j][1] << " ";
            ans=max(dp[i][j][1],ans);
        }
//        cout << endl;
    }
	cout << ans; 
    return 0;


}
