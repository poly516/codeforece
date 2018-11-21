#include<bits/stdc++.h>
using namespace std;
long long n,m,c[100010],x,y,ans,num;
bool f[100010];
vector<long long> v[100010];
void dfs(long long last){
	for (long long i=0;i<v[last].size();i++)
		if (f[v[last][i]]==0){
			f[v[last][i]]=1;
			dfs(v[last][i]);
			num=min(num,c[v[last][i]]);
		}
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>c[i];
	for (int i=0;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (long long i=1;i<=n;i++)
		if (f[i]==0){
			f[i]=1;
			num=c[i];
			dfs(i);
			ans+=num;
		}
	cout<<ans<<endl;
	return 0;
}
