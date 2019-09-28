#include<bits/stdc++.h>
using namespace std;

struct Node{
	int pid, size, query;
	public:
	Node(int p, int s, int q){
		pid = p;
		size = s;
		query = q;
	}
};

list<Node> pend;
list< pair<int,int> > space;
vector<int> result;

void merge(list<pair<int,int>>::iterator it){
	auto next = it;
	next++;
	auto prev = it;
	--prev;
	if (next!=space.end()){
	if (next->first == ( it->first + it->second ) ){
		it->second = it->second + next->second;
		space.erase(next);
	}}

	if (it!=space.begin()){
	if (it->first == ( prev->first + prev->second ) ){
		prev->second = prev->second + it->second;
		space.erase(it);
	}}
}

pair<int,int> allocate(int pid, int size, int query){
	pair<int,int> ans = make_pair(-1,-1);

	auto i = space.begin();
	for(i=space.begin();i!=space.end();i++)
	{
		if (i->second >=size)
			break;
	}

	if (i!=space.end())
	{
		ans = make_pair(i->first, size);
		if (query >= result.size())
			result.push_back(i->first);
		else
			result[query] = i->first;

		i->first = i->first + size;
		i->second = i->second-size;
	}
	else if (query>=result.size())
	{
		result.push_back(-1);
		pend.push_back( Node(pid, size, query) );
	}
	else
	{
		result[query] = -1;
	}

	if (i!=space.end() && i->second==0)
		space.erase(i);

	return ans;
}

int main(){
	int n,M;
	cin>>n>>M;
	int query=-1;
	char ch;
	space.push_back( make_pair(0, M) );
	vector< list< pair<int,int> > > occupied(n);

	while(true)
	{
		query++;
		cin>>ch;
		if (ch=='H')
		{
			break;
		}
		else if (ch=='T')
		{
			int pid;
			cin>>pid;
			for (auto i = occupied[pid].begin();i!=occupied[pid].end();i++)
			{
				auto ii = space.begin();
				for (ii = space.begin();ii!=space.end();ii++)
				{
					if (ii->first > i->first)
						break;
				}
				space.insert(ii, make_pair(i->first, i->second) );
				ii--;
				merge(ii);
			}
			if (!occupied[pid].empty())
				result.push_back(0);
			else
				result.push_back(1);

			occupied[pid].clear();
			// reallocation continues
			auto i = pend.begin();
			while(i!=pend.end())
			{
				if (i->pid == pid)
				{
					i = pend.erase(i);
				}
				else
				{
					auto ans = allocate(i->pid, i->size, i->query);
					if (ans.first != -1)
					{
						occupied[i->pid].push_back(ans);
						i = pend.erase(i);
					}
					else
						i++;
				}
			}
		}
		else
		{
			int pid, size;
			cin>>pid>>size;
			if (ch=='A')
			{
				pair<int,int> ans = allocate(pid,size,query);
				if (ans.first != -1)
					occupied[pid].push_back(ans);
			}
			else if (ch=='D')
			{
				auto i = occupied[pid].begin();
				for (i = occupied[pid].begin();i!= occupied[pid].end();i++)
				{
					if (i->first == size)
						break;
				}
				if (i!=occupied[pid].end())
				{
					result.push_back(0);
					auto ii = space.begin();
					for (ii = space.begin();ii!=space.end();ii++)
					{
						if (ii->first > i->first)
							break;
					}
					space.insert(ii, make_pair(i->first, i->second) );
					ii--;
					merge(ii);
					occupied[pid].erase(i);
					// reallocation continues
					auto iii = pend.begin();
					while (iii!=pend.end())
					{
						auto ans = allocate(iii->pid, iii->size, iii->query);
						if (ans.first != -1)
						{
							occupied[iii->pid].push_back(ans);
							iii = pend.erase(iii);
						}
						else
							iii++;
					}

				}
				else
				{
					result.push_back(1);
				}
			}
		}
	}
	for (int i=0;i<result.size();i++){
		cout<<result[i]<<"\n";
	}
}