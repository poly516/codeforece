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
long long n,k,s,num;
int main(){
	cin>>n>>k>>s;
	if (2*1e14<s||(n-1)*k<s||k>s){
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	if (s==2){
		cout<<2<<' '<<1;
		return 0;
	}
	if (n==2){
		for (int i=0;i<k;i++) cout<<2-i%2<<' ';
		return 0;
	}
	if (k==2){
		if (s%2==1) cout<<(s+3)/2<<' '<<2;
		if (s%2==0) cout<<s/2+1<<' '<<1;
		return 0;
	}
	int i=1;
	while (i<=k+1){
		i+=1;s-=n-1;
		if (s<k-i+1) break;
		if (i%2==0) printf("%d ",n);
		if (i%2==1) printf("%d ",1);
	}
	if (i!=k+2) i-=1;s+=n-1;
	if (i%2==1&&i<=k+1){
		while (i<k){
			if (i%2==1) printf("%d ",2);
			if (i%2==0) printf("%d ",1);
			i++;s--;
		}
		if (s!=0) cout<<1+s+1-i%2;
	}
	else if (i%2==0&&i<=k+1){
		while (i<k){
			if (i%2==1) printf("%d ",n);
			if (i%2==0) printf("%d ",n-1);
			i++;s--;
		}
		if (s!=0) cout<<n-s-i%2;
	}
	return 0;
}
