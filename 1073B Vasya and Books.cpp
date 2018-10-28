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
#include<stack>
#include<string>
#include<vector>
using namespace std;
int n,x,mx=0,mp[200010];
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		scanf("%d",&x);
		mp[x]=i+1;
	}
	for (int i=0;i<n;i++){
		scanf("%d",&x);
		cout<<max(0,mp[x]-mx)<<' ';
		mx=max(mx,mp[x]);
	}
	return 0;
}
