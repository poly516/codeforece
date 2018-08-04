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
int n,m,num;
string s[110];
bool d[1100][1100];
vector<int> a,b,c;
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>s[i];
	if (s[0][m-1]=='*'||s[0][0]=='*'||s[n-1][0]=='*'||s[n-1][m-1]=='*'){
		cout<<"-1";
		return 0;
	}
	for (int j=0;j<n;j++)
		for (int k=0;k<m;k++)
			for (int i=min(n,m);i>=1;i--)
				if (j-i>=0&&k-i>=0&&j+i<n&&k+i<m&&s[j][k]=='*'){
					int f=0;
					for (int l=1;l<=i;l++) if (s[j+l][k]=='*') f++;
					for (int l=1;l<=i;l++) if (s[j-l][k]=='*') f++;
					for (int l=1;l<=i;l++) if (s[j][k+l]=='*') f++;
					for (int l=1;l<=i;l++) if (s[j][k-l]=='*') f++;
					if (f==i*4){
						a.push_back(j+1);
						b.push_back(k+1);
						c.push_back(i);
						for (int l=0;l<=i;l++) d[j+l][k]=1;
						for (int l=0;l<=i;l++) d[j-l][k]=1;
						for (int l=0;l<=i;l++) d[j][k+l]=1;
						for (int l=0;l<=i;l++) d[j][k-l]=1;
						num++;
						i=0;
					}
				}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if ((d[i][j]==1&&s[i][j]=='.')||(d[i][j]==0&&s[i][j]=='*')){
				cout<<"-1";
				return 0;
			}
	cout<<a.size()<<endl;
	for (int i=0;i<a.size();i++) cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<endl;
	return 0;
}
