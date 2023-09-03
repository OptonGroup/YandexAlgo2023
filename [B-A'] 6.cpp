// @active_botane every day
 
// Мальчик-айтишник, 300k в секунду
// Постоянно кодит, молодой Дуров
// Я уже устала о тебе думать
// Как же я хочу быть твоей клавиатурой
// Как же я хочу быть твоей
 
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) x.begin(), x.end()
#define print(x) for (auto u: x) cout << u << " ";
#define getv(v) for (int i = 0; i < v.size(); i++) cin >> v[i];
typedef long long ll;
typedef long double ld;
using namespace std;
 
int n;
int mx, my, mz;

vector<map<int, map<int, ll>>> dp;
vector<map<int, map<int, bool>>> used;

vector <array<int, 3>> v;

ll fn(int ind, int x, int y){
	if (ind > n) return 0;
	if (used[ind][x][y]) return dp[ind][x][y];
	used[ind][x][y] = 1;
	dp[ind][x][y] = 0;

	int z = mz - (ind - (mx-x + my-y));

	if (x > 0){
		dp[ind][x][y] = max(dp[ind][x][y], fn(ind+1, x-1, y) + v[ind][0]);
	}
	if (y > 0){
		dp[ind][x][y] = max(dp[ind][x][y], fn(ind+1, x, y-1) + v[ind][1]);
	}
	if (z > 0){
		dp[ind][x][y] = max(dp[ind][x][y], fn(ind+1, x, y)   + v[ind][2]);
	}
	return dp[ind][x][y];
}

int main() {
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	
	int x, y, z;
	cin >> x >> y >> z;
	mx = x, my = y, mz = z;
	n = x + y + z;
	dp.resize(n+1);
	used.resize(n+1);

	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i][0] >> v[i][1] >> v[i][2];

	cout << fn(0, x, y);

 
	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
