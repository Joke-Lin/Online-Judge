// 如果需要多次删除插入操作采取list更好
// 此题vector TE  (￣▽￣)" 

#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <list>
#include <list>
#include <algorithm>

using namespace std;

struct IP {
	string ip;
	int length;	// 前缀长度
	IP():
		ip(""),length(-1)
	{}
	bool operator < (IP &another) {
		if(ip != another.ip) return ip < another.ip;
		return length < another.length;
	}
	// 格式化输出 
	void formatShow() {
		for(int i = 0;i < 4;i++) {
			string substr = ip.substr(i*8,8);
			int res = 0;
			for(int j = 0;j < 8;j++) {
				res += (substr[j] - '0')*(1 << (7 - j));
			}
			cout << res;
			cout << ((i < 3) ? '.' : '/');
		}
		cout << length;
	}
};

// 格式化输入 
IP formatInput(string &input) {
	IP res;
	string sub = "";	// 每一个子字符串
	for(int i = 0;i <= input.size();i++) {
		if(i == input.size() || !isdigit(input[i])) {
			int subInt = atoi(sub.c_str());
			for(int j = 7;j >= 0;j--) {
				int bit = (subInt & (1 << j)) >> j;	// 获取第i位的二进制码 
				res.ip += bit + '0';
			}
			sub = "";
			if(i != input.size() && input[i] == '/') {
				res.length = atoi(input.substr(i+1).c_str());
				break;
			}
		} else {
			sub += input[i];
		}	
	}
	if(res.length == -1) {
		res.length = res.ip.size();
	}
	res.ip.insert(res.ip.end(),32-res.ip.size(),'0');
	return res;
}

// 判断b 是否是 a的子集 
bool isSubSet(IP a, IP b) {
	if(a.length > b.length) return false;
	for(int i = 0;i < a.length;i++) {
		if(a.ip[i] != b.ip[i]) return false;
	}
	return true;
}

// 是否可以合并 
bool isUnion(IP a, IP b) {
	if(a.length != b.length) return false;
	for(int i = 0;i < a.length-1;i++) {
		if(a.ip[i] != b.ip[i]) return false;
	}
	return true;
}

// 从小到大合并 
void merge1(list<IP> &ips) {
	list<IP>::iterator front = ips.begin(), next = ips.begin();
	for(next++;next != ips.end();) {
		if(isSubSet(*front,*next)) {
			next = ips.erase(next);
		} else {
			front++;
			next++;
		}
	}
}

void merge2(list<IP> &ips) {
	list<IP>::iterator front = ips.begin(), next = ips.begin();
	for(next++;next != ips.end();) {
		if(isUnion(*front,*next)) {
			next = ips.erase(next);
			(*front).length--;
			if(front != ips.begin()) {
				next--;
				front--;
			}
		} else {
			front++;
			next++;
		}
	}
}

int main()
{
	int n; scanf("%d",&n);
	list<IP> Ips;	
	for(int i = 0;i < n;i++) {
		string input;
		cin >> input;
		IP ip = formatInput(input);
		Ips.push_back(ip);
	}	
	Ips.sort();
	merge1(Ips);
	merge2(Ips);
	for(list<IP>::iterator it = Ips.begin();it != Ips.end();it++) {
		(*it).formatShow();
		cout << endl;
	}
	return 0;
}
