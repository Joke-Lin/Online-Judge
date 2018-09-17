#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int R,N;
	while(cin >> R >> N)
	{
		if(R == -1 && N==-1) break;
		set<int> X;
		for(int i = 0;i < N;i++)
		{
			int mid;cin >> mid;
			X.insert(mid);
		}
		int ans = 0;
		set<int>::iterator i = X.begin();
		while(i != X.end())
		{
			int start = *i;
			while(i != X.end() && *i <= start + R) i++;
			i--;
			start = *i;
			i++;
			while(i != X.end() && *i <= start + R) i++;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
