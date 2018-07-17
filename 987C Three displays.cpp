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
long long n,ans=1e11,a[10000],b[10000],c[10000];
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	for (int i=0;i<n;i++) c[i]=1e11;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (a[i]<a[j]) c[i]=min(c[i],b[j]);
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (a[i]<a[j]) ans=min(ans,b[i]+b[j]+c[j]);
	if (ans!=1e11)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
