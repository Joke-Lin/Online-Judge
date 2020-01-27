#include <iostream>
#include <sstream>
#include <string>
#include <set>

#define LOCAL

using namespace std;

struct Parameter{
	string name;
	string para;
	int type; // 0: 无参数 1:有参数
	bool operator < (const Parameter &other) const {
		return name < other.name;
	}
};

string format;
int n;

set<Parameter> solve(string cmd) {
	set<Parameter> res;
	stringstream ss(cmd);
	string str;
	ss >> str;
	while(ss >> str) {
		// 如果是无参数命令 
		if(str[0] == '-') {
			int pos = format.find(str.substr(1));
			if(pos == format.npos) {
				break;
			}
			else if(pos < format.length()-1 && format[pos+1] == ':') {
				string next; ss >> next;
				if(next.empty()) {
					break;
				}
				Parameter temp = {str.substr(1), next, 1};
				if(res.find(temp) != res.end()) {
					res.erase(temp);
				}
				res.insert(temp);
			}
			else {
				Parameter temp = {str.substr(1), "", 0};
				res.insert(temp);
			}
		}
		else {
			break;
		}
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("./in.txt", "r", stdin);
#endif
	cin >> format;
	cin >> n;
	string str;
	getline(cin, str);
	for(int i = 1;i <= n;i++) {
		getline(cin, str);
		set<Parameter> res = solve(str);
		cout << "Case " << i << ":";
		for(set<Parameter>::iterator it = res.begin();it!=res.end();it++) {
			if(it->type == 0) {
				cout << " -" << it->name;
			} else {
				cout << " -" << it->name << " " << it->para;
			}
		}
		cout << endl;
	}
	return 0;
}
