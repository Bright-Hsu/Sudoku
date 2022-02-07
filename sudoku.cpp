#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;

vector<vector<int>> vec(3,vector<int>(3));
const vector<vector<int>> goal = { {1,2,3},{8,0,4},{7,6,5} };
const vector<pair<int, int>> direct = { {0,-1},{-1,0},{0,1},{1,0} };
int xplot = 1;
int yplot = 1;

void input() {
	cout << "ÇëÊäÈë¾ØÕóÖµ:" << endl;
	for (int i = 0; i < 9; ++i) {
		cin >> vec[i/3][i%3];
		if (vec[i / 3][i % 3] == 0) {
			xplot = i / 3;
			yplot = i % 3;
		}
	}
}

void output(vector<vector<int>> nums) {
	cout << "¾ØÕó×´Ì¬Îª:" << endl;
	for (int i = 0; i < 9; ++i) {
		cout << nums[i / 3][i % 3] << " ";
		if ((i+1) % 3 == 0)
			cout << endl;
	}
	cout << endl;
}

void findPlot(vector<vector<int>> nums) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (nums[i][j] == 0) {
				xplot = i;
				yplot = j;
			}
		}
	}
}

void bfs() {
	queue<vector<vector<int>>> q;
	queue<int> p;
	int lock = -1;
	int count = 0;
	q.push(vec);
	p.push(-1);
	while (!q.empty()) {
		vector<vector<int>> cur = q.front();
		int last = p.front();
		q.pop();
		p.pop();
		++count;
		cout << "×´Ì¬" << count << ":" << endl;
		output(cur);
		if (cur == goal) {
			return;
		}
		findPlot(cur);
		for (int i = 0; i < 4; i++) {
			if (last == 0 && i == 2)  continue;
			if (last == 2 && i == 0)  continue;
			if (last == 1 && i == 3)  continue;
			if (last == 3 && i == 1)  continue;
			if (xplot + direct[i].first >= 0 && xplot + direct[i].first < 3 && yplot + direct[i].second >= 0 && yplot + direct[i].second < 3) {
				swap(cur[xplot][yplot], cur[xplot + direct[i].first][yplot + direct[i].second]);
				cout << xplot << " " << yplot << endl;
				q.push(cur);
				p.push(i);
				swap(cur[xplot][yplot], cur[xplot + direct[i].first][yplot + direct[i].second]);
			}
		}
	}
}

int main() {
	input();
	bfs();
	return 0;
}