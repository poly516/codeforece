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
int n,a[110],sum,f;
string s;
int main(){
	cin>>n>>s;
	for (int i=0;i<n;i++) a[i]=s[i]-'0',sum+=a[i];
	if (sum==0){
		cout<<"YES"<<endl;
		return 0;
	}
	for (int i=2;i<=sum;i++)
		if (sum%i==0){
			int j=0;
			f=1;
			int x=0;
			while (j<n){
				int num=0;
				while (num<sum/i&&j<n) num+=a[j],x+=a[j++];
				if (x==sum&&num==0) break;
				if (num!=sum/i){
					f=0;
					break;
				}
			}
			if (f==1) break;
		}
	if (f==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
