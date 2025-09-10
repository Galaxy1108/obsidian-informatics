#include<iostream>
using namespace std;
char a[50]="rename elevator.in elevator0.in";
char b[50]="rename elevator.out elevator0.out";
int main()
{
	for(int i=1;i<=10;++i){
		system("da.exe");
		system("elevator.exe");
		for(int j=0;true;j++){
			if(a[j]-'0'==i-1){
				a[j]=i+'0';
				break;
			}
		}
		for(int j=0;true;j++){
			if(b[j]-'0'==i-1){
				b[j]=i+'0';
				break;
			}
		}
		system(a);
		system(b);
	}
	
}
