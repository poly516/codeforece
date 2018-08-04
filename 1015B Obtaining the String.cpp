#include<algorithm>
#include<clocale>
#include<cmath>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<istream>
#include<map>
#include<math.h>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
int n,num;
char s[100],t[100];
string a,b,c;
int main(){
	cin>>n>>s>>t;
	c=a=s;b=t;
	sort(s,s+n);sort(t,t+n);
	for (int i=0;i<n;i++)
		if (s[i]!=t[i]){
			cout<<-1<<endl;
			return 0;
		}
	while (a!=b){
		for (int i=0;i<n;i++)
			if (b[i]!=a[i]){
				if (a[i+1]==b[i]){
					swap(a[i+1],a[i]);
					num++;
				}
				else{
					int j=i+1;
					for (;j<n;j++) if (a[j]==b[i]) break;
					for (;j>i;j--){
						swap(a[j],a[j-1]);
						num++;
					}
				}
			}
	}
	cout<<num<<endl;
	while (c!=b){
		for (int i=0;i<n;i++)
			if (b[i]!=c[i]){
				if (c[i+1]==b[i]){
					swap(c[i+1],c[i]);
					printf("%d ",i+1);
				}
				else{
					int j=i+1;
					for (;j<n;j++) if (c[j]==b[i]) break;
					for (;j>i;j--){
						swap(c[j],c[j-1]);
						printf("%d ",j);
					}
				}
			}
	}
	return 0;
}
