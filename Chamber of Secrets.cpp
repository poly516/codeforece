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
#define INF (1<<29)
int X,Y;
char maze[1010][1010];
int dist[1010][1010][4];
bool used[1010][1010][4];
deque<int> q;
void ft(int x,int y,int dir,int d){
	if (d<dist[x][y][dir]){
		dist[x][y][dir]=d;
		q.push_front(dir);
		q.push_front(y);
		q.push_front(x);
	}
}
void bk(int x,int y,int dir,int d){
	if (d<dist[x][y][dir]){
		dist[x][y][dir]=d;
		q.push_back(x);
		q.push_back(y);
		q.push_back(dir);
	}
}
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int main()
{
	cin>>X>>Y;
	for(int i=0;i<X;i++)
		for (int j=0;j<Y;j++)
			cin>>maze[i][j];
	for(int i=0;i<X;i++)
		for(int j=0;j<Y;j++)
			for(int k=0;k<4;k++)
				dist[i][j][k]=INF;
	ft(X-1,Y-1,3,0);
	while(!q.empty()){
		int x=q[0],y=q[1],dir=q[2];
		q.pop_front();q.pop_front();q.pop_front();
		if (used[x][y][dir]) continue;
		used[x][y][dir]=true;
		int x2=x+dx[dir],y2=y+dy[dir],d=dist[x][y][dir];
		if(x2>=0&&x2<X&&y2>=0&&y2<Y) ft(x2,y2,dir,d);
		if(maze[x][y]=='#') for(int i=0;i<4;i++) if(i!=dir) bk(x,y,i,d+1);
	}
	int ans=dist[0][0][3];
	if(ans==INF) ans=-1;
	cout<<ans;
	return 0;
}
