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
int n,mx=1;
int main(){
	cin>>n;
	for (int i=2;i<=n;i++) if ((n+i-1)/i+i<(n+mx-1)/mx+mx) mx=i;
	for (int i=n-(n+mx-1)/mx+1;i<=n;i++) cout<<i<<' ';
	n-=(n+mx-1)/mx;mx-=1;
	while (n>0){
		for (int i=n-n/mx+1;i<=n;i++) cout<<i<<' ';
		n=n-n/mx;mx-=1;
	}
	return 0;
}
