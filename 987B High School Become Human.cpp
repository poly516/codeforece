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
long long n,m,a=1,b=1;
int main(){
	cin>>n>>m;
	if (n==m||(n==2&&m==4)||(n==4&&m==2)){
		cout<<'=';
		return 0;
	}
	if (n==1||n==2&&m==3){
		cout<<'<';
		return 0;
	}
	if (m==1||n==3&&m==2){
		cout<<'>';
		return 0;
	}
	if (n-m>=2||n-m==1) cout<<"<";
	if (m-n>=2||m-n==1) cout<<">";
	return 0;
}
