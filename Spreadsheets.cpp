#include<algorithm>
#include<bits/allocator.h>
#include<bits/basic_ios.h>
#include<bits/basic_string.h>
#include<bits/basic_string.tcc>
#include<bits/c++config.h>
#include<bits/char_traits.h>
#include<bits/cpp_type_traits.h>
#include<bits/cxxabi_forced.h>
#include<bits/ios_base.h>
#include<bits/locale_classes.h>
#include<bits/localefwd.h>
#include<bits/ostream_insert.h>
#include<bits/postypes.h>
#include<bits/range_access.h>
#include<bits/stl_algobase.h>
#include<bits/stl_function.h>
#include<bits/stl_iterator.h>
#include<bits/stl_iterator_base_funcs.h>
#include<bits/stl_iterator_base_types.h>
#include<bits/stringfwd.h>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
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
#include<cwchar>
#include<cwchar>
#include<cwctype>
#include<debug/debug.h>
#include<deque>
#include<exception>
#include<ext/atomicity.h>
#include<ext/numeric_traits.h>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<math.h>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<utility>
#include<valarray>
#include<vector>
using namespace std;
int s2i(string t){
	int a=0;
	for (int i=0;i<t.size();i++) a=a*26+t[i]-'A'+1;
	return a;
}
string i2s(int a){
	string t="";
	while (a!=0){
		if(a%26!=0) t+=char('A'+a%26-1);
		if(a%26==0) t+='Z';
		a=(a-a%26)/26;
	}
	for (int i=0;i<(t.size()+1)/2;i++) swap(t[i],t[t.size()-i-1]);
	return t;
}
int si(string t){
	int a=0;
	for (int i=0;i<t.size();i++) a=a*10+t[i]-'0';
	return a;
}
string iis (int a){
	string t="";
	while (a!=0){
		t+=char(a%10+'0');
		a/=10;
	}
	for (int i=0;i<(t.size()+1)/2;i++) swap(t[i],t[t.size()-i-1]);
	return t;
}
vector<string> t;
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		string s;
		cin>>s;t.push_back(s);
	}
	for (int i=0;i<n;i++){
		string s="";
		if (t[i][0]=='R'&&t[i][1]<='9'&&t[i][1]>='0'){
			int j=0;
			for (;t[i][j]!='C';j++);
			s+=i2s(si(t[i].substr(j+1)))+t[i].substr(1,j-1);
		}
		else{
			int j=0;
			for (;t[i][j]>'9';j++);
			s+='R';
			s+=t[i].substr(j);
			s+='C';
			s+=iis(s2i(t[i].substr(0,j)));
		}
		cout<<s<<endl;
	}
	return 0;
}

