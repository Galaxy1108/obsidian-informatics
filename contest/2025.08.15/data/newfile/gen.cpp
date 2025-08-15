#include <bits/stdc++.h>
using namespace std;
mt19937 zsh(time(0));
int get_rnd(int l,int r){return zsh()%(r-l+1)+l;}
int n,m,q,jz;
char fil[110];
int main()
{
    for(int t=1;t<=20;t++)
    {
        sprintf(fil,"newfile%d.in",t);
        freopen(fil,"w",stdout);
        
        if(t<=4) jz=10;
        else if(t<=10) jz=5000;
        else jz=100000;
        if(t!=2&&t!=4&&t!=8&&t!=10&&t!=13&&t!=14&&t!=19&&t!=20)
            n=get_rnd(jz/2,jz),m=get_rnd(jz/2,jz),q=get_rnd(jz/2,jz);
        else n=m=q=jz;

        printf("%d %d %d\n",n,m,q);
        for(int i=1,l,r,x;i<=m;i++)
        {
            if(t&1) l=get_rnd(1,n),r=get_rnd(1,n);
            else l=get_rnd(1,n/3),r=get_rnd(n/3*2,n);
            if(l>r) swap(l,r);
            if(t==1||t==2||(t>=5&&t<=8)||(t>=11&&t<=14)) x=1;
            else x=get_rnd(1,(t<=4)?100:1000000000);
            printf("%d %d %d\n",l,r,x);
        }
        for(int i=1,u,d,l,r;i<=q;i++)
        {
            u=get_rnd(0,m),d=get_rnd(0,m);
            if(u>=d) swap(u,d);
            if(t&1) l=get_rnd(1,n),r=get_rnd(1,n);
            else l=get_rnd(1,n/2),r=get_rnd(n/2+1,n);
            if(l>r) swap(l,r);
            printf("%d %d %d %d\n",u,d,l,r);
        }
        fclose(stdout);

        sprintf(fil,"ren newfile%d.in newfile.in",t);
        system(fil);
        sprintf(fil,"del newfile%d.out",t);
        system(fil);
        
        cerr<<"Run STD"<<endl;
        
        system("newfile");

        cerr<<"STD Finished!"<<endl;
        
        sprintf(fil,"ren newfile.in newfile%d.in",t);
        system(fil);
        sprintf(fil,"ren newfile.out newfile%d.out",t);
        system(fil);
    }
    return 0;
}