#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{
	char s[100];
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		scanf("%s",&s);
		bool f=0;
		for (int i=1;s[i];i++) if (!isdigit(s[i])&&isdigit(s[i-1])) f=1;
		if (f==0){
			int c=0,j=0,r=0;
			for (;!isdigit(s[j]);++j) c=26*c+s[j]-'A'+1;
			for (;s[j];j++) r=10*r+s[j]-'0';
			printf("R%dC%d\n",r,c);
		}
		else{
			int c=0,j=1,r=0,z=0;
			for (;isdigit(s[j]);++j) r=10*r+s[j]-'0';
			for (++j;s[j];++j) c=10*c+s[j]-'0';
			while(c){
				s[z++]=c%26+'A'-1;
				if(s[z-1]<'A'){
					s[z-1]='Z';
					c-=26;
				}
				c/=26;
			}
			for (int k=z-1;k>=0;--k) putchar(s[k]);
			printf("%d\n",r);
		}
	}
	return 0;
}
