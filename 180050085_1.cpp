#include<bits/stdc++.h>

using namespace std;

int main()
{
	// cout<<abs(5-7);
	int n;
	cin>>n;
	char c[n];
	int i[n];
	int types[100001] = {0};
	bool present_types[100001]={false};
	int min_types[100001]={0};

	for(int j = 0; j < n ; j++ )
	{
		cin>>c[j]>>i[j];
		present_types[i[j]]=true;

		if (c[j]=='s')
			types[i[j]]++;
		else if (c[j]=='e')
			types[i[j]]--;

		min_types[i[j]] = min(min_types[i[j]], types[i[j]]);
	}
	
	int max_types = 0;	
	int current_deletions = 0;

	for(int j=0;j<100001;j++)
	{
		if ( present_types[j] && (types[j]==0 && min_types[j]==0) )
			max_types++;

		if (present_types[j])
		{
			current_deletions += 2*abs(min_types[j]) + types[j];
			cout<<"min_types "<<j<<" "<<current_deletions<<endl;
		}
	}
	int min_deletions = current_deletions;

	int current_nested_types = max_types;
	int index =1;

	for (int j=0;j<n;j++)
	{
		if (present_types[i[j]] && types[i[j]]==0)
		{
			if (c[j]=='s')
			{
				if (min_types[i[j]]==0)
					current_nested_types--;
				min_types[i[j]]--;
				
			}
			else //if (c[j]=='e')
			{
				min_types[i[j]]++;
				if (min_types[i[j]]==0)
					current_nested_types++;
			}
		}

		if (current_nested_types>max_types)
		{
			max_types=current_nested_types;
			index = j+2;
		}
		// deletions part
		if (j!=n-1)
		{
			if (c[j]=='s')
				current_deletions+=2;
			else // c[j] == 'e'
				current_deletions-=2;

			min_deletions= min(min_deletions, current_deletions);
		}

	}
	if (index>n)
		index-=n;

	cout<<index<<" "<<max_types<<" "<<min_deletions<<endl;

}