#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#define LOCAL

using namespace std;

struct Key_Value;
typedef vector<Key_Value> Object;

struct Key_Value{
	int type; // 判断value是str还是Obj 
	string key;
	string str;
	Object obj;
};

// global variable
int n, m;
string json;
char ch;
int lenJson;
int cur = 0;

// 解析JSON 
Object jsonParser(int &cur) {
	Object obj;
	Key_Value k_v;
	k_v.type = 0;
	string str;
	bool type = true;	// true: key false: value
	while(cur < lenJson) {
		if(json[cur] == ':') {
			k_v.key = str;
			str = "";
		}
		else if(json[cur] == '{') {
			k_v.type = 1;
			cur++;
			// 一个新的 Obj 
			k_v.obj = jsonParser(cur);
		}
		// 重新写入值 
		else if(json[cur] == ',' || json[cur] == '}') {
			k_v.str = str;
			obj.push_back(k_v);
			k_v.type = 0;
			str = "";
			if(json[cur] == '}') {
				return obj;
			}
		}
		else {
			str += json[cur];
		}
		cur++;
	}
	return obj;
}

int search(Object &root, string &key) {
	int res = -1;
	for(int i = 0;i < root.size();i++) {
		if(root[i].key == key) {
			res = i;
			break;
		}
	}
	return res;
}

void getAnswer(vector<string> format, Object root) {
	while(true) {
		int res = search(root, format.front());
		format.erase(format.begin());
		if(res == -1) {
			printf("NOTEXIST\n");
			return; 
		}
		if(root[res].type == 0 && !format.empty()) {
			printf("NOTEXIST\n");
			return;
		}
		if(format.empty()) {
			if(root[res].type == 1) {
				printf("OBJECT\n");
			}
			else {
				cout << "STRING " << root[res].str << endl;
			}
			return;
		}
		root = root[res].obj;
	}
}

int main() {
#ifdef LOCAL
	freopen("./in.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	cin.get();
	cin.get();
	// 将JSON变为连续的字符串丢弃空格 
	for(int i = 0;i < n;i++) {
		while((ch = cin.get())!='\n') {
			if(ch == '"' || ch == ' ') {
				continue;
			}
			else if(ch == '\\') {
				json += cin.get();
			}
			else {
				json += ch;
			}
		}
	}
	json[json.length()-1] = ',';
	lenJson = json.length();
	Object root = jsonParser(cur);
	string str;
	for(int i = 0;i < m;i++) {
		vector<string> searchList;
		cin >> str;
		stringstream ss(str);
		while(getline(ss, str, '.')) {
			searchList.push_back(str);
		}
		getAnswer(searchList, root);
	}
	return 0;
}
