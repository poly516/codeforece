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
int a[2][100010],n,f;
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[0][i]>>a[1][i];
	for (int i=0;i<n;i++){
		int x=a[0][i],y=a[1][i];
		a[0][i]=max(x,y);
		a[1][i]=min(x,y);
	}
	bool last=1;
	for (int i=n-1;i>0;i--){
		if (a[last][i]<=a[1][i-1]){
			last=1;
			continue;
		}
		if (a[last][i]<=a[0][i-1]){
			last=0;
			continue;
		}
		f=1;
	}
	if (f==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
