// @active_botane every day

// Мальчик-айтишник, 300k в секунду
// Постоянно кодит, молодой Дуров
// Я уже устала о тебе думать
// Как же я хочу быть твоей клавиатурой
// Как же я хочу быть твоей

#include <bits/stdc++.h>
#define endl "\n"
#define all(x) x.begin(), x.end()
#define print(v) for (auto u: v) cout << u << " ";
#define getv(v) for (int i = 0; i < v.size(); i++) cin >> v[i];
#define printPair(pr) cout << pr.first << " " << pr.second;
#define getPair(pr) cin >> pr.first >> pr.second;
typedef long long ll;
typedef long double ld;
using namespace std;

const int INF = 2e9;

struct stree{
	int n;
	vector <int> max_time_of_sex, min_time_of_sex, add_time_for_sex;

	void build(int v, int vl, int vr, const vector<int>& a){
		if (vl == vr){
			max_time_of_sex[v] = a[vl];
			min_time_of_sex[v] = a[vl];
			return;
		}
		int vm = (vl + vr) / 2;
		build(2 * v + 1, vl, vm, a);
		build(2 * v + 2, vm+1, vr, a);
		max_time_of_sex[v] = max(max_time_of_sex[2 * v + 1], max_time_of_sex[2 * v + 2]);
		min_time_of_sex[v] = min(min_time_of_sex[2 * v + 1], min_time_of_sex[2 * v + 2]);
	}

	stree(const vector<int>& a){
		n = a.size();
		max_time_of_sex.resize(4 * n, 0);
		min_time_of_sex.resize(4 * n, INF);
		add_time_for_sex.resize(4 * n, 0);
		build(0, 0, n-1, a);
	}

	void push(int v, int vl, int vr){
		if (!add_time_for_sex[v]) return;
		max_time_of_sex[v] = max(max_time_of_sex[v], add_time_for_sex[v]);
		min_time_of_sex[v] = max(min_time_of_sex[v], add_time_for_sex[v]);
		if (vl != vr){
			add_time_for_sex[2 * v + 1] = max(add_time_for_sex[2 * v + 1], add_time_for_sex[v]);
			add_time_for_sex[2 * v + 2] = max(add_time_for_sex[2 * v + 2], add_time_for_sex[v]);
		}
		add_time_for_sex[v] = 0;
	}

	ll get_max(int v, int vl, int vr, int left, int right){
		push(v, vl, vr);

		if (right < vl || vr < left)
			return 0;
		if (left <= vl && vr <= right)
			return max_time_of_sex[v];
		int vm = (vl + vr) / 2;
		ll ql = get_max(2 * v + 1, vl, vm, left, right);
		ll qr = get_max(2 * v + 2, vm+1, vr, left, right);
		return max(ql, qr);
	}

	ll get_min(int v, int vl, int vr, int left, int right){
		push(v, vl, vr);

		if (right < vl || vr < left)
			return INF;
		if (left <= vl && vr <= right)
			return min_time_of_sex[v];
		int vm = (vl + vr) / 2;
		ll ql = get_min(2 * v + 1, vl, vm, left, right);
		ll qr = get_min(2 * v + 2, vm+1, vr, left, right);
		return min(ql, qr);
	}

	void update(int v, int vl, int vr, int left, int right, int val){
		push(v, vl, vr);
		if (right < vl || vr < left)
			return;
		if (left <= vl && vr <= right){
			add_time_for_sex[v] = val;
			push(v, vl, vr);
			return;
		}
		int vm = (vl + vr) / 2;
		update(2 * v + 1, vl, vm, left, right, val);
		update(2 * v + 2, vm+1, vr, left, right, val);
		max_time_of_sex[v] = max(max_time_of_sex[2 * v + 1], max_time_of_sex[2 * v + 2]);
		min_time_of_sex[v] = min(min_time_of_sex[2 * v + 1], min_time_of_sex[2 * v + 2]);
	}

	ll get_max(int left, int right){
		return get_max(0, 0, n-1, left, right);
	}

	ll get_min(int left, int right){
		return get_min(0, 0, n-1, left, right);
	}

	void update(int left, int right, int val){
		update(0, 0, n-1, left, right, val);
	}

	ll bs(int v, int vl, int vr, int val){
		if (v)
	}
};	

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, t;
	cin >> n >> t;
	vector <int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	stree segment_tree(v);

	while (t--){
		int q;
		cin >> q;
		if (q == 1){
			int x, y;
			cin >> x >> y;
			segment_tree.update(0, x-1, y);
		}else if (q == 2){
			int x, y;
			cin >> x >> y;

			
		}
	}
	
    cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
