#include <bits/stdc++.h>
using namespace std;

struct l{
    int x,y,z;
};

l sn[150005];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sn[i].x>>sn[i].y>>sn[i].z;
    }
    long long anss=-1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                long long maxx=max({sn[i].x,sn[j].x,sn[k].x});
                long long maxy=max({sn[i].y,sn[j].y,sn[k].y});
                long long maxz=max({sn[i].z,sn[j].z,sn[k].z});
                if((sn[i].x==maxx && sn[j].x< maxx && sn[k].x< maxx && 
                    sn[i].y< maxy && sn[j].y==maxy && sn[k].y< maxy &&
                    sn[i].z< maxz && sn[j].z< maxz && sn[k].z==maxz)||
                   (sn[i].x==maxx && sn[j].x< maxx && sn[k].x< maxx && 
                    sn[i].y< maxy && sn[j].y< maxy && sn[k].y==maxy &&
                    sn[i].z< maxz && sn[j].z==maxz && sn[k].z< maxz)||
                   (sn[i].x< maxx && sn[j].x==maxx && sn[k].x< maxx && 
                    sn[i].y==maxy && sn[j].y< maxy && sn[k].y< maxy &&
                    sn[i].z< maxz && sn[j].z< maxz && sn[k].z==maxz)||
                   (sn[i].x< maxx && sn[j].x==maxx && sn[k].x< maxx && 
                    sn[i].y< maxy && sn[j].y< maxy && sn[k].y==maxy &&
                    sn[i].z==maxz && sn[j].z< maxz && sn[k].z< maxz)||
                   (sn[i].x< maxx && sn[j].x< maxx && sn[k].x==maxx && 
                    sn[i].y==maxy && sn[j].y< maxy && sn[k].y< maxy &&
                    sn[i].z< maxz && sn[j].z==maxz && sn[k].z< maxz)||
                   (sn[i].x< maxx && sn[j].x< maxx && sn[k].x==maxx && 
                    sn[i].y< maxy && sn[j].y==maxy && sn[k].y< maxy &&
                    sn[i].z==maxz && sn[j].z< maxz && sn[k].z< maxz)){
                        anss=max(anss,maxx+maxy+maxz);
                    }
            }
        }
    }
    cout<<anss;
}