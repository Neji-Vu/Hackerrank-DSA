/***********************************************
 * File:        PoisonousPlants.cpp
 * Date:        2025 Mar 13 16:03:28
 * Description: Basic C++ program template
 ***********************************************/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
#define ll long long
const int mxN = 1e5;

int mySolution(vector<int> p) {
	stack<int> st;
	int cnt = 0, ans = 0, size = p.size();
	do {
		cnt = 0;
		size = p.size();
		for (int i = 1; i < p.size(); ++i) {
			if (p[i] > p[i - 1])
				st.push(i);
			else
				cnt++;
		}
		if (!st.empty())
			ans++;
		while (!st.empty()) {
			p.erase(p.begin() + st.top());
			st.pop();
		}
	} while (cnt + 1 != size);

	return ans;
}

int OptimalSolution(vector<int> v) {
	stack<pair<int, int>> st;
	int ans = 0;
	// vector<int> span(v.size(), -1);

	for (int i = 0; i < v.size(); i++) {
		int cnt = 1;
		while (!st.empty() && v[st.top().first] >= v[i]) {
			cnt = max(cnt, st.top().second + 1);
			st.pop();
		}
		if (st.empty())
			cnt = 0;
		ans = max(ans, cnt);
		st.push({i, cnt});
	}

	return ans;
}

int main(int argc, char **argv) {
	int n;

	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	cout << OptimalSolution(p);

	return 0;
}
