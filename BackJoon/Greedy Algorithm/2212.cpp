#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> sensor;
vector<int> width;

void makeWidth() {
	

	sort(sensor.begin(), sensor.end());

	for (int i = 0; i < N - 1; ++i) {
		width.push_back(sensor[i + 1] - sensor[i]);
	}
}

int makeSensor() {
	makeWidth();
	int tmp = K - 1;
	int sum = 0;
	sort(width.begin(), width.end(), greater<int>());
	for (int i = tmp; i < N - 1; ++i) {
		sum += width[i];
	}
	return sum;

}

int main() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		sensor.push_back(tmp);
	}

	cout << makeSensor();

}

