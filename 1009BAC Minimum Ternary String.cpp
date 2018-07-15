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
string s,t,l;
int main(){
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]=='1') l+='1';
		if (s[i]!='1') t+=s[i];
	}
	for (int i=0;i<t.size();i++){
		if (t[i]=='2'){
			cout<<l;l="";
		}
		cout<<t[i];
	}
	cout<<l<<endl;
	return 0;
}
