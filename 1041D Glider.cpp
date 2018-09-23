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
int n,m,a[200010],b[200010],h,l,ans;
vector<int> v,c;
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i]>>b[i];
	v.push_back(0);c.push_back(0);
	for (int i=0;i<n;i++){
		v.push_back(b[i]-a[i]);
		if (i!=n-1) c.push_back(a[i+1]-b[i]);
	}
	for (int i=0;i<c.size()-1;i++) c[i+1]+=c[i];
	for (int i=0;i<v.size()-1;i++) v[i+1]+=v[i];
	h=m;
	for (int i=1;i<v.size();i++){
		int lbound=i,rbound=c.size()+1;
		while (lbound<rbound){
			int mid=(lbound+rbound)/2;
			if (mid<c.size()&&c[mid]-c[i-1]<h)
				lbound=mid+1;
			else
				rbound=mid;
		}
		h-=(c[lbound]-c[i-1]);
		l+=(v[lbound]-v[i-1])+(c[lbound]-c[i-1]);
		if (h<0){
			l+=h;
			h=0;
		}
		ans=max(ans,l+h);
		if (h!=0) break;
		l=0;h=m;
	}
	cout<<max(ans,l+h)<<endl;
	return 0;
}
