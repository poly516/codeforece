#include<bits/stdc++.h>
using namespace std;
long long n,ans,last=-2e9;
pair<long long,long long> p[100010];
int main(){
	cin>>n;
	for (long long i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	p[0].first=-3e9;p[n+1].first=3e9;
	for (long long i=1;i<=n;i++){
		if (p[i].first-p[i].second>max(last,p[i-1].first)){
			ans++;
			last=p[i].first;
		}
		else if (p[i].first+p[i].second<p[i+1].first){
			ans++;
			last=p[i].first+p[i].second;
		}
	}
	cout<<ans<<endl;
}
