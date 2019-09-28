#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> f(n);
	// int pos[n];

	for(int i =0;i<n;i++)
	{
		cin>>f[i];
		// pos[f[i]] = i;
	}

	vector<int> weight(n);
	vector<long long int> distance(n);

	for (int i=0;i<n;i++)
	{
		cin>>weight[i];
	}
	distance[0] = 0;
	for(int i=1;i<n;i++)
	{
		cin>>distance[i];
		distance[i] += distance[i-1];
	}

	vector<int> stack;
	int x;
	long long int swaps = 0;
	long long int cost =0;
	// to print cost

	for (int i=0;i<n;i++)
	{
		cost+=abs(distance[f[i]]-distance[i])*weight[i];
	}
	cout<<cost<<"\n";

	// the stack implementation
	vector<int> first, second;

	int c = n-1;
	while(c!=-1)
	{
		if(f[c]<=c)
		{
			c--;
		}
		else
		{
			x = f[c];
			int c_original = c;
			int forward = f[c];
			stack.push_back(forward);
			while(f[forward]>c)
			{
				stack.push_back(f[forward]);
				forward = f[forward];
			}

			swaps+=stack.size();
			int last = stack.back();

			while(!stack.empty())
			{
				first.push_back(c);
				second.push_back(stack.back());
				c = stack.back();
				stack.pop_back();
			}

			f[c_original] = f[last];
			c = c_original;

		}


	}

	// output the answer

	cout<<swaps<<"\n";
	for(int i=0;i<first.size();i++)
	{
		cout<<first[i]<<" "<<second[i]<<"\n";
	}




}