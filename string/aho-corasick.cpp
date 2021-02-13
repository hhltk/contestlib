#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int seen[MAXN],t[MAXN];
char s[MAXN],buf[MAXN];
int n,k;
struct AC
{
	int nxt[MAXN][26],nc,link[MAXN],que[MAXN];
	int add(char*p,int i)
	{
		int n=0;
		while(*p)
		{
			if(!nxt[n][*p-'a'])nxt[n][*p-'a']=++nc;
			n=nxt[n][*p-'a'];
			p++;
		}
		return n;
	}
	void push_links()
	{
		que[0]=0;
		int l=0,r=1;
		while(l<r)
		{
			int n=que[l++];
			int k=link[n];
			for(int i=0;i<26;++i)
			{
				if(nxt[n][i])
				{
					link[nxt[n][i]] = !n ? 0 : nxt[k][i];
					que[r++]=nxt[n][i];
				}
				else
				{
					nxt[n][i]=nxt[k][i];
				}
			}
		}
	}
	void match(char*p)
	{
		int n=0;
		while(*p)
		{
			n=nxt[n][*p-'a'];
			seen[n]++;
			p++;
		}
		for(int i=nc+1;i;--i)
		{
			seen[link[que[i]]]+=seen[que[i]];
		}
	}
}ac;
int main()
{
	scanf("%s%d",s,&k);
	for(int i=1;i<=k;++i)
	{
		scanf("%s",buf);
		t[i]=ac.add(buf,i);
	}
	ac.push_links();
	ac.match(s);
	for(int i=1;i<=k;++i)
	{
		printf("%d\n",seen[t[i]]);
	}
}
