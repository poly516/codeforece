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
long long n,x,num,sum;
vector<pair<long long,long long> > p;
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>x;
		p.push_back(pair<int,int>(x,0));
	}
	for (int i=0;i<n;i++){
		cin>>x;
		p.push_back(pair<int,int>(x,1));
	}
	sort(p.begin(),p.end());reverse(p.begin(),p.end());
	for (int i=0;i<p.size();i++)
		if (i%2==p[i].second){
			if (i%2==0) num+=p[i].first;
			if (i%2==1) sum+=p[i].first;
		}
	cout<<num-sum<<endl;
	return 0;
}
