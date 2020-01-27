#include <cstdio>
#include <string>
#include <vector>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <queue>

#define LOCAL

using namespace std;
/*
	存储父节点，从下往上寻找 
*/ 

struct Node {
	int father;
	int layers;
	string name;
	string id;
};

vector<Node> html;
int n, m;

string toLower(string str) {
	for(int i = 0;i < str.length();i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}

void getTree() {
	for(int i = 0;i < html.size();i++) {
		int tarLayers = html[i].layers - 1;
		int father = i;
		for(int j = i - 1; j >= 0;j--) {
			if(html[j].layers == tarLayers) {
				father = j;
				break;
			}
		}
		html[i].father = i == father ? -1 : father;
	}
}

bool isMatch(int nodeIndex, vector<string> format) {
	int father = nodeIndex;
	// 可以是父亲的父亲这样的 
	while(father != -1 && !format.empty()) {
		if(html[father].name == format.back() || html[father].id == format.back()) {
			format.pop_back();
		}
		father = html[father].father;
	}
	return format.empty();
}

vector<int> getRes(vector<string> format) {
	vector<int> res;
	for(int i = 0;i < n;i++) {
		if(html[i].name == format.back() ||	html[i].id == format.back()) {
			if(isMatch(i, format)) {
				res.push_back(i);
			}
		}
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("./in.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	string str;
	getline(cin, str);
	for(int i = 0;i < n;i++) {
		getline(cin, str);
		Node node;
		int dots = 0;
		for(int j = 0;j < str.length() && str[j] == '.';j++) {
			dots++;
			str[j] = ' ';
		}
		stringstream ss(str);
		int type = 0;
		while(ss >> str) {
			if(type == 0) {
				node.name = toLower(str);
			}
			else {
				node.id = str;
			}
			type++;
		}
		node.layers = dots/2;
		html.push_back(node);
	}
	getTree();
	for(int i = 0;i < m;i++) {
		getline(cin, str);
		stringstream ss(str);
		vector<string> format;
		while(ss >> str) {
			format.push_back(str[0] == '#' ? str : toLower(str));
		}
		vector<int> res = getRes(format);
		int size = res.size();
		printf("%d ", size);
		for(int j = 0;j < size;j++) {
			printf("%d ", res[j] + 1);
		}
		printf("\n");
	}
	return 0;
}
