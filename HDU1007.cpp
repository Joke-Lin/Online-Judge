#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const double INF = 0x6FFFFFFF;

typedef pair<double,double> Point;

bool cmp(Point a,Point b)
{
	return a.second < b.second;
}

double close_des(vector<Point>::iterator,int);  //在此数组节点到其后N个数的最小距离，1的时候返回极大值，因为2的时候以比较

int main()
{
	int N;
	while(cin >> N)
	{
		if(N==0) break;
		vector<Point> Points;
		for(int i = 0;i < N;i++)
		{
			double a,b;
			cin >> a >> b;
			Point pot = {a,b};
			Points.push_back(pot);
		}
		sort(Points.begin(),Points.end());
		printf("%.2f\n",close_des(Points.begin(),N)/2.0);
	}
}

double close_des(vector<Point>::iterator p,int n)
{
	if(n <= 1) return INF;
	int mid = n/2;//中间节点
	double line = p[mid].first;
	double des = min(close_des(p,mid),close_des(p+mid,n-mid));
	inplace_merge(p,p+mid,p+n,cmp);
	vector<Point> b;
	for(int i = 0;i < n;i++)
	{
		if(fabs(p[i].first-line)>=des) continue;
		for(int j = 0;j < b.size();j++)
		{
			double dx = p[i].first-b[b.size()-j-1].first;
			double dy = p[i].second-b[b.size()-j-1].second;
			if(dy>=des) break;
			des = min(des,sqrt(dx*dx+dy*dy));
		}
		b.push_back(p[i]);
	}
	return des;
}
