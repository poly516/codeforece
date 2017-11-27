#include<iostream>
#include<math.h>
using namespace std;
long long n,x[200000],a[1000000],mx=-1000000000;
bool prime[1000000];
int main()
{
	cin>>n;
	for (long long i=0;i<n;i++){
		cin>>x[i];
		a[i]=x[i];
	}
	prime[0]=prime[1]=1;
    for(int i=2;i*i<=1000000;i++)
        if(!prime[i])
            for(int j=i*i;j<=1000000;j+=i) prime[j]=1;
	for (long long i=0;i<n;i++){
		long long j=sqrt(x[i]);
		if ((j*j==x[i]&&!prime[j])||x[i]==4)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
