#include<bits/stdc++.h>
using namespace std;

void multiply(vector<int>::iterator P, vector<int>::iterator Q, vector<int>::iterator R, int n)
{
	if (n<=16)
	{
		// cout<<*P<<"-P "<<*Q<<"-Q ";
		// *R = (*P) * (*Q);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				*(R+i+j) += (*(P+i)) * (*(Q+j));
			}
		}
	}
	else
{

	vector<int>::iterator P_0=P , P_1=P+n/2, Q_0=Q, Q_1=Q+n/2;
	vector<int> p0q0(n-1,0), p1q1(n-1,0), p0p1, q0q1, pq(n-1,0);

	multiply(P_0, Q_0, p0q0.begin(), n/2);
	// cout<<"p0q0 "<<p0q0[0]<<p0q0[1]<<endl;
	multiply(P_1, Q_1, p1q1.begin(), n/2);
	// cout<<"p1q1 "<<p1q1[0]<<p1q1[1]<<endl;

	// for making (p0+p1) and (q0+q1)
	for(int i=0;i<n/2;i++)
		p0p1.push_back(*(P_0+i) + *(P_1+i));
	// cout<<"p0p1 "<<p0p1[0]<<p0p1[1]<<endl;

	for(int i=0;i<n/2;i++)
		q0q1.push_back(*(Q_0+i) + *(Q_1+i));
	// cout<<"q0q1 "<<q0q1[0]<<q0q1[1]<<endl;

	multiply(p0p1.begin(), q0q1.begin(), pq.begin(), n/2);
	// cout<<"pq "<<pq[0]<<pq[1]<<endl;

	for(int i=0;i<n-1;i++) //n/2
	{
		pq[i]=pq[i]-p0q0[i]-p1q1[i];
		// cout<<pq[i]<<" ";
	}
	// cout<<"new pq "<<pq[0]<<pq[0]<<endl;

	// copying R
	int i;
	for(i=0;i<n-1;i++)
	{
		*(R+i) = *(R+i) + p0q0[i];
		// cout<<*(R+i)<<p0q0[i]<<endl;
	}
	
	for(i=n;i<2*n-1;i++)
	{
		*(R+i) = *(R+i) + p1q1[i-n];		
		// cout<<*(R+i)<<p1q1[i-n];
	}
	
	for(i=n/2;i<3*(n/2)-1;i++)
	{
		*(R+i) = *(R+i) + pq[i-n/2];				
		// cout<<" "<<*(R+i)<<pq[i-n/2];
	}

	// cout<<"R-in- ";
	// for(i=0;i<2*n-1;i++)
	// 	cout<<*(R+i)<<" ";
}

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,temp1;
	cin>>n;
	vector<int> P,Q,R(2*n-1, 0);

	for(int i =0;i<n;i++)
	{
		cin>>temp1;
		P.push_back(temp1);
	}

	for(int i =0;i<n;i++)
	{
		cin>>temp1;
		Q.push_back(temp1);
	}

	multiply(P.begin(), Q.begin(), R.begin(), n);
	
	// cout<<"R- ";
	for(auto it=R.begin();it!=R.end();it++)
		cout<<*it<<" ";

	cout<<endl;

}