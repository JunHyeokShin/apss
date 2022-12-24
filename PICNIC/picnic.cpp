#include <iostream>
#include <string>
using namespace std;

int n;
bool areFriends[10][10];
int countPairings(bool[]);

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int pairs;
		int answer;
		bool taken[10];

		cin >> n;
		cin >> pairs;

		for (int i = 0; i < n; i++) {
			taken[i] = false;
			for (int j = 0; j < n; j++) {
				areFriends[i][j] = false;
			}
		}

		for (int i = 0; i < pairs; i++) {
			int first, second;
			cin >> first;
			cin >> second;
			areFriends[first][second] = true;
			areFriends[second][first] = true;
		}

		answer = countPairings(taken);

		cout << answer << endl;
	}
}

// taken[i] = i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings(bool taken[10]) {
	// 남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	// 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	if (firstFree == -1) return 1;
	int ret = 0;
	// 이 학생과 짝지을 학생을 결정한다.
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}
