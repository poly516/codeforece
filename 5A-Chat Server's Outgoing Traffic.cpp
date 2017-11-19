#include<iostream>
using namespace std;
int main()
{
	int ans=0,people=0;
	string s;
	while (getline(cin,s)){
		if (s[0]=='+')
			++people;
		else if (s[0]=='-')
			--people;
		else{
			int i=1;
			while (s[i]!=':') i++;
			string t=s.substr(i+1,s.size());
			ans+=t.size()*people;
		}
	}
	cout<<ans;
	return 0;
}
