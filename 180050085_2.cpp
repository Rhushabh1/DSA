#include<bits/stdc++.h>
using namespace std;

long long factorial(int n)
{
	long long ans=1;
	for(int i=2;i<=n;i++)
		ans*=i;
	return ans;
}

long long anagram(int a[26])
{
	long long den=1;
	int total=0;
	for(int i=0;i<26;i++)
	{
		total+=a[i];
		den*=factorial(a[i]);
	}
	return factorial(total)/den;
}

int main()
{
	string s, x_s="";
	cin>>s;
	int len=s.length();
	long long x;
	cin>>x;
	long long rank=0,x_rank=0;

	int count[26]={0};
	for (int i=0;i<len; i++) // (n) 
	{
		count[ int(s[i])-'a' ]++;
	}
	// rank of string
	int copy_count[26];
	copy(count, count+26, copy_count);
	for(int i=0;i<len;i++) // (n)
	{
		for (int j=0;j<int(s[i])-'a';j++ ) // (logn)
		{
			if (count[j]!=0)
			{
				count[j]--;
				long long temp=anagram(count);
				rank+=temp;
				count[j]++;
			}
		}
		count[ int(s[i])-'a' ]--;
	}
	// anagram at x
	for (int i=0;i<len;i++)
	{
		char str;
		long long temp1=0;
		int pos=0;
		while(pos<26)
		{
			if (copy_count[pos]!=0)
			{
				str=char(pos+'a');
				copy_count[pos]--;
				temp1=anagram(copy_count);
				if (x_rank+temp1>x)
					break;
				else
				{
					x_rank+=temp1;
					copy_count[pos]++;
				}
			}
			pos++;
		}
		x_s.push_back(str);
	}
	cout<<rank<<" "<<x_s<<endl;
}