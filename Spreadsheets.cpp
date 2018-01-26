#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int s2i(string t){
	int a=0;
	for (int i=0;i<t.size();i++) a=a*26+t[i]-'A'+1;
	return a;
}
string i2s(int a){
	string t="";
	while (a>0)
		if(a%26!=0){
			t+=char('A'+a%26-1);
			a=a/26;
		}
		else if(a%26==0){
			t+='Z';
			if(a%26==0) a=a/26-1;
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
bool iff(string s){
	if (s.size()<4) return 0;
	int i=0;for (;i<s.size();i++) if (s[i]=='C') break;
	if (s[0]=='R'&&s[1]<='9'&&s[1]>='0'&&i+1<s.size()&&s[i+1]) return 1;
	return 0;
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
		if (iff(t[i])==1){
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
