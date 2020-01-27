#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define LOCAL

using namespace std;

// �������׷���֮����ı� ��[text] 
string findBracket(string &str, char tar, int &index) {
	int nextIndex = str.find(tar, index+1);
	string res = str.substr(index+1, nextIndex-index-1);
	index = nextIndex;
	return res;
}

// ����һ�м��ı� 
string dealText(string str) {
	string res;
	int index = 0, len = str.length();
	while(index < len) {
		if(str[index] == '_') {
			res += "<em>";
			res += dealText(findBracket(str, '_', index));
			res += "</em>";
		}
		else if(str[index] == '[') {
			string text = dealText(findBracket(str, ']', index));
			index++;
			string link = findBracket(str, ')', index);
			res += "<a href=\"" + link + "\">" + text + "</a>";
		}
		else {
			res += str[index];
		}
		index++;
	}
	return res;
}

// ������� 
string dealTitle(string str) {
	int layers = 0;
	int index = 0, len = str.length();
	while(index < len) {
		if(str[index] != '#' && str[index] != ' ') {
			break;
		}
		if(str[index] == '#') {
			layers++;
		}
		index++;
	}
	string h = "h";
	h += char('0'+layers);
	string res = "<" + h + ">";
	res += dealText(str.substr(index));
	res += "</" + h + ">";
	return res;
}

// �����б� 
string dealList(string str) {
	int index = 0, len = str.length();
	while(index < len) {
		if(str[index] != '*' && str[index] != ' ') {
			break;
		}
		index++;
	}
	string res = "<li>";
	res += dealText(str.substr(index));
	res += "</li>";
	return res;
}

 

int main() {
#ifdef LOCAL
	freopen("./in.txt", "r", stdin);
#endif
	string str;
	int type = -1;	// 0�� ���� 1���б� -1:else
	bool isInBlock = false;	// �ж��Ƿ���һ������ 
	string p;	// ��������ַ��� 
	while(getline(cin, str)) {
		if(str.empty()) {
			if(isInBlock) {
				if(type == 1) {	// �Ƿ����б���� 
					cout << "</ul>" << endl;
				}
				else if(type == 0) {	// ������� 
					p.erase(p.end()-1);
					p += "</p>";
					cout << p << endl;
					p = "";
				}
				isInBlock = false;
				type = -1;
			}
			continue;
		}
		if(str[0] == '#') {	// ����ֻ��һ��ֱ����� 
			type = -1;
			cout << dealTitle(str) << endl;
		}
		else if(str[0] == '*') {	// �б���Ҫǰ���<ul> 
			type = 1;
			if(!isInBlock) {
				cout << "<ul>" << endl;
				isInBlock = true;
			}
			cout << dealList(str) << endl;
		}
		else {
			type = 0;
			if(!isInBlock) {
				p += "<p>";
				isInBlock = true;
			}
			p += dealText(str) + "\n";
		}
	}
	// ��������p 
	if(type == 1) {
		cout << "</ul>" << endl;
	}
	else if(type == 0) {
		p.erase(p.end()-1);
		p += "</p>";
		cout << p << endl;
		p = "";
	}
	return 0;
}
