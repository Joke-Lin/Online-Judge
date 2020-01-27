#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int srcYear = 1850;
const int srcWeek = 1; // 0 1 2 3 4 5 6
int a, b, c, y1, y2;

bool isRun(int x) {
	if(x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)) {
		return true;
	}
	return false;
}

int getFirstWeek(int tarYear) {
	int daySum = 0;
	for(int i = srcYear;i < tarYear;i++) {
		daySum += isRun(i) ? 366 : 365;
	}
	return (daySum+srcWeek) % 7;
}

void getAnswer() {
	for(int i = y1;i <= y2;i++) {
		int firstWeek = getFirstWeek(i);
		int days = 0, j;
		daysOfMonth[2] = isRun(i) ? 29 : 28;
		for(j = 1;j < a;j++) {
			days += daysOfMonth[j];
		}
		for(j = 1;j <= daysOfMonth[a]+1;j++) {
			if((days + j + firstWeek - 1)%7 == c - 1) {
				break;
			}
		}
		j = j + 7*(b-1);
		if(j > daysOfMonth[a]) {
			printf("none\n");
			continue;
		}
		printf("%d/%02d/%02d\n", i, a, j);
	}
}

int main() {
	cin >> a >> b >> c >> y1 >> y2;
	getAnswer();
	return 0;
}
