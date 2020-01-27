#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#define LOCAL

using namespace std;

typedef vector<string> Route;

void creatRoute(Route &route, string relative) {
	stringstream ss(relative);
	string filename;
	bool flag = true;	// 第一个 / 需要考虑 后面不需要考虑 
	while(getline(ss, filename, '/')) {
		if(filename.empty()) {
			if(flag) route = Route();
		}
		else if(filename == "..") {
			if(!route.empty()) route.pop_back();
		}
		else if(filename == ".") {
			// donothing 
		}
		else {
			route.push_back(filename);
		}
		flag = false;
	}
}

void print(Route& route) {
	for(int i = 0;i < route.size();i++) {
		cout << "/" << route[i];
	}
	if(route.empty()) {
		cout << "/";
	}
	cout << endl;
}

int main() {
#ifdef LOCAL
	freopen("./in.txt", "r", stdin);
#endif
	int n; scanf("%d", &n);
	string curContentStr, relative; 
	cin >> curContentStr;
	Route curRoute, newRoute;
	creatRoute(curRoute, curContentStr);
	getline(cin, relative);
	for(int i = 0;i < n;i++) {
		getline(cin, relative);
		newRoute = curRoute;
		creatRoute(newRoute, relative);
		print(newRoute);
	}
	
	return 0;
}
