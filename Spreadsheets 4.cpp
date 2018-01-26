#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int getint(string s){
	int ans=0,d=1,b=0;
	for (int i=0;i<s.size()-1;i++){
		d*=26;
		ans+=d;
	}
	for (int i=0;i<s.size();i++) b=b*26+s[i]-'A';
	return ans+b+1;
}
string getstring(int n){
	int d=26,p=1;
	n--;
	while (n>=d){
		n-=d;
		d*=26;
		p++;
	}
	string ans="";
	for (int i=0;i<p;i++){
		ans+='A'+n%26;
		n/=26;
	}
	for (int i=0;i<(ans.size()+1)/2;i++) swap(ans[i],ans[ans.size()-i-1]);
	return ans;
}
int main()
{
	cin>>n;
	for (int i=0;i<n;i++){
		int a=0,p=0,b=0;
		string s,t;
		cin>>s;
		while (!isdigit(s[p])) t+=s[p++];
		while (p<s.size()&&isdigit(s[p])) a=a*10+s[p++]-48;
		if (p==s.size())
			cout<<"R"<<a<<"C"<<getint(t)<<endl;
		else{
			p++;
			while (p<s.size()&&isdigit(s[p])) b=b*10+s[p++]-48;
			cout<<getstring(b)<<a<<endl;
		}
	}
	return 0;
}
