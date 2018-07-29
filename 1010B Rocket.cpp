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
int n,m,lowerbound,upperbound,a,num=0;
vector<int> p;
int main(){
	cin>>m>>n;
	lowerbound=1;upperbound=m;
	for (int i=1;i<=n;i++){
		cout<<i<<endl;
		fflush(stdout);
		cin>>a;
		if (a==0) exit(0);
		if (a==1) p.push_back(1);
		if (a==-1) p.push_back(0);
	}
	while (lowerbound<upperbound){
		int mid=(upperbound+lowerbound)/2;
		if (mid<=n){
			lowerbound=mid+1;
			continue;
		}
		cout<<mid<<endl;
		fflush(stdout);
		cin>>a;
		if (a==0)
			exit(0);
		else if (p[num]==1){
			if (a==1) lowerbound=mid+1;
			if (a==-1) upperbound=mid;
		}
		else{
			if (a==-1) lowerbound=mid+1;
			if (a==1) upperbound=mid;
		}
		if (num==n-1) num=-1;
		num++;
	}
	if (a!=0){
		cout<<lowerbound<<endl;
		fflush(stdout);
		cin>>a;
		exit(0);
	}
	return 0;
}
