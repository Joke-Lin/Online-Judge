#include <iostream>
#include <map>
#include <vector>
#include <string>

#define LOCAL

using namespace std;

int n, m;
vector<string> html;
map<string,string> format;

string replace(string src) {
	int leftIndex = 0, rightIndex;
	string key, value;
	while(true) {
		leftIndex = src.find("{{", leftIndex);
		rightIndex = src.find("}}", leftIndex);
		if(leftIndex == src.npos || rightIndex == src.npos) {
			break;
		}
		key = src.substr(leftIndex+3, rightIndex-leftIndex-4);
		value = format.count(key) == 0 ? "" : format[key];
		src.replace(leftIndex, rightIndex-leftIndex+2, value);
		// Error 原来是 leftIndex = rightIndex 注意src会改变 原来下标无效 
		leftIndex += key.length();
	}
	return src;
}

int main() {
#ifdef LOCAL
	freopen("./in.txt", "r", stdin);
#endif
	cin >> n >> m;
	string str;
	getline(cin, str);
	for(int i = 0;i < n;i++) {
		getline(cin, str);
		html.push_back(str);
	}
	string key, value;
	for(int i = 0;i < m;i++) {
		cin >> key;
		getline(cin, value);
		format.insert(make_pair(key, value.substr(2,value.length()-3)));
	}
	for(int i = 0;i < n;i++) {
		cout << replace(html[i]) << endl;
	}
	return 0;
}
