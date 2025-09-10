#include<iostream>
using namespace std;
char a[50]="rename find.in find0.in";
char b[50]="rename find.out find0.out";
int main()
{
	for(int i=0;i<10;++i){
		system("da.exe");
		system("find.exe");
		system(a);
		system(b);
		for(int j=0;true;j++){
			if(a[j]-'0'==i){
				a[j]=i+1+'0';
				break;
			}
		}
		for(int j=0;true;j++){
			if(b[j]-'0'==i){
				b[j]=i+1+'0';
				break;
			}
		}
	}
	
}
