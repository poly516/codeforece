# codeforece
T-prime
这一题告诉我们只有三个因数才行，所以必为一个质数的平方。
因此，这一题的关键也就在于如何快速判定是否为质数。
因为1<=n<=100000，所以一个个判定是不太合理的。所以可以先算质数。
可以这样求：
for (int i=2;i<1000000;i++){//i<=1000000000000
  int f=0;
  for (int j=2;j<i/2;j++) if (i%j==0) f=1;
  if (f==0)//压入
}
这样也是可以求出的，但是会严重超时，所以得用这一段。（prime是bool类型，这样可以节省内存）
prime[0]=prime[1]=1;
   for(int i=2;i*i<=1000000;i++)
       if(!prime[i])
           for(int j=i*i;j<=1000000;j+=i) prime[j]=1;
剩下的也就很好解决了。
Spreadsheets
这一题是两种格式的转换。
RxCy(xy是数字)->yx2(两个y相等，x2由x转换而来)
要注意的是，如何将两种情况分开。
一开时，我只注意了R，所以导致字符串的边界超出。
t[i][0]=='R'&&t[i][1]<='9'&&t[i][1]>='0'
这样会因后面没有C而RE，所以还需要一些条件。
bool iff(string s){
	if (s.size()<4) return 0;
	int i=0;for (;i<s.size();i++) if (s[i]=='C') break;
	if (s[0]=='R'&&s[1]<='9'&&s[1]>='0'&&i+1<s.size()&&s[i+1]) return 1;
	return 0;
}
这样就可以避免上述问题。
下面是如何改变的方法：
//1->2
while (a>0)
	if(a%26!=0){
		t+=char('A'+a%26-1);
		a=a/26;
	}
	else if(a%26==0){
		t+='Z';
		if(a%26==0) a=a/26-1;
	}//Z是一种特殊情况，分开讨论
for (int i=0;i<(t.size()+1)/2;i++) swap(t[i],t[t.size()-i-1]);//由于所得结果是反的，所以要反过来
//2->1
for (int i=0;i<t.size();i++) a=a*26+t[i]-'A'+1;
