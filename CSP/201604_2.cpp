#include<iostream>
#include<cstdio>

#define LOCAL
 
using namespace std;

const int width = 10;
const int height = 15;

int matrix[height+4][width];
int block[4][4];

bool judgeKnock(int x_pos, int y_pos) {
	// 从下往上判断 
	int x, y;
	for(int i = 3;i >= 0;i--) {
		for(int j = 3;j >= 0;j--) {
			x = x_pos + j;
			y = y_pos + i;
			if(block[i][j] == 0) {
				continue;
			}
			if(block[i][j] == 1 && matrix[y+1][x] == 1) {
				return true;
			}
		}
	}
	return false;
}

int main() {
#ifdef LOCAL
	freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
	for(int i = 0;i < height;i++) {
		for(int j = 0;j < width;j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	
	// 在最下方增加4格全为格子，方便处理碰撞 
	for(int i = 0;i < 4;i++) {
		for(int j = 0;j < width;j++) {
			matrix[height + i][j] = 1;
		}
	}
	
	for(int i = 0;i < 4;i++) {
		for(int j = 0;j < 4;j++) {
			scanf("%d", &block[i][j]);
		}
	}
	
	int x_pos = 0, y_pos = 0;
	scanf("%d",&x_pos);
	x_pos--;
	
	while(true) {
		if(judgeKnock(x_pos, y_pos)) {
			// 将图案嵌入 
			for(int i = 0;i < 4;i++) {
				for(int j = 0;j < 4;j++) {
					matrix[y_pos+i][x_pos+j] |= block[i][j];
				}
			}
			break;
		} else {
			y_pos++;
		}
	}
	
	for(int i = 0; i < height;i++) {
		for(int j = 0;j < width;j++) {
			printf("%d", matrix[i][j]);
			if(j != width - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
