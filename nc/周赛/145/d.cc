/*
[[ ⣇⣿⠘⣿⣿⣿⡿⡿⣟⣟⢟⢟⢝⠵⡝⣿⡿⢂⣼⣿⣷⣌⠩⡫⡻⣝⠹⢿⣿⣷ ]],
[[ ⡆⣿⣆⠱⣝⡵⣝⢅⠙⣿⢕⢕⢕⢕⢝⣥⢒⠅⣿⣿⣿⡿⣳⣌⠪⡪⣡⢑⢝⣇ ]],
[[ ⡆⣿⣿⣦⠹⣳⣳⣕⢅⠈⢗⢕⢕⢕⢕⢕⢈⢆⠟⠋⠉⠁⠉⠉⠁⠈⠼⢐⢕⢽ ]],
[[ ⡗⢰⣶⣶⣦⣝⢝⢕⢕⠅⡆⢕⢕⢕⢕⢕⣴⠏⣠⡶⠛⡉⡉⡛⢶⣦⡀⠐⣕⢕ ]],
[[ ⡝⡄⢻⢟⣿⣿⣷⣕⣕⣅⣿⣔⣕⣵⣵⣿⣿⢠⣿⢠⣮⡈⣌⠨⠅⠹⣷⡀⢱⢕ ]],
[[ ⡝⡵⠟⠈⢀⣀⣀⡀⠉⢿⣿⣿⣿⣿⣿⣿⣿⣼⣿⢈⡋⠴⢿⡟⣡⡇⣿⡇⡀⢕ ]],
[[ ⡝⠁⣠⣾⠟⡉⡉⡉⠻⣦⣻⣿⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣦⣥⣿⡇⡿⣰⢗⢄ ]],
[[ ⠁⢰⣿⡏⣴⣌⠈⣌⠡⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣬⣉⣉⣁⣄⢖⢕⢕⢕ ]],
[[ ⡀⢻⣿⡇⢙⠁⠴⢿⡟⣡⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣵⣵⣿ ]],
[[ ⡻⣄⣻⣿⣌⠘⢿⣷⣥⣿⠇⣿⣿⣿⣿⣿⣿⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ ]],
[[ ⣷⢄⠻⣿⣟⠿⠦⠍⠉⣡⣾⣿⣿⣿⣿⣿⣿⢸⣿⣦⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟ ]],
[[ ⡕⡑⣑⣈⣻⢗⢟⢞⢝⣻⣿⣿⣿⣿⣿⣿⣿⠸⣿⠿⠃⣿⣿⣿⣿⣿⣿⡿⠁⣠ ]],
[[ ⡝⡵⡈⢟⢕⢕⢕⢕⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠿⠋⣀⣈⠙ ]],
[[ ⡝⡵⡕⡀⠑⠳⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢉⡠⡲⡫⡪⡪⡣ ]],
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node {
        int u;
        vector<int> v;

        bool operator<(const node &t) const {
                return v.size() > t.v.size();
        }
};

int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        vector<node> vis(n + 1);
        vector<bool> visb(n + 1), visc(n + 1);
        for (int i = 1; i <= n; ++i) {
                vis[i].u = i;
        }
        int t = 0;
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
                vis[a[i]].v.push_back(i);
                t = max(t, (int)vis[a[i]].v.size());
        }
        if (t > 2) {
                cout << -1;
                return 0;
        }
        sort(vis.begin(), vis.end());
        t = 0;
        for (auto x : vis) {
                if (x.v.empty()) {
                        break;
                }
                if (!x.v.empty() && t < n / 2) {
                        b[x.v.back()] = x.u;
                        visb[x.u] = true;
                        x.v.pop_back();
                        t++;
                }
                if (!x.v.empty()) {
                        c[x.v.back()] = x.u;
                        visc[x.u] = true;
                        x.v.pop_back();
                }
        }

        t = 1;
        for (int i = 0; i < n; ++i) {
                if (!b[i]) {
                        while (visb[t]) {
                                t++;
                        }
                        b[i] = t++;
                }
                cout << b[i] << " \n"[i == n - 1];
        }
        t = 1;
        for (int i = 0; i < n; ++i) {
                if (!c[i]) {
                        while (visc[t]) {
                                t++;
                        }
                        c[i] = t++;
                }
                cout << c[i] << " \n"[i == n - 1];
        }

        return 0;
}
