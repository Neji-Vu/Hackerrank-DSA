/***********************************************
 * File:        LargestRectangle.cpp
 * Date:        2025 Mar 08 18:31:38
 * Description: Basic C++ program template
 ***********************************************/
#include <iostream>

using namespace std;
#define ll long long

int main(int argc, char **argv) {
	int n;
	cin >> n;
	int h[n];
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	int cnt = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (h[j] >= h[i])
				cnt++;
			else {
				if (j <= i)
					cnt = 0;
				else
					break;
			}
		}
		ans = max(ans, h[i] * cnt);
	}
	cout << ans;

	return 0;
}
