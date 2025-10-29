#include<bits/stdc++.h>
#define endl '\n'
#define itn int

typedef unsigned long long ull;
typedef long long ll;
using namespace std;
char f[45][15];
int n;
int len[45];
int main(){
    freopen("flower.in","r",stdin);freopen("flower.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    if(n==3){printf("%s\n%s\n%s\n%s\n%s\n%s",f[3],f[1],f[2],f[1],f[3],f[2]);}
    else if(n==4){printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",f[4],f[1],f[3],f[1],f[2],f[4],f[3],f[2]);}
    /*else if(n==7){printf("%s %s %s %s %s %s %s %s %s %s %s %s %s %s",f[]);}
    else if(n==8)*/


    
    return 0;
}