#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct TEAM {
        bitset<26> bf, af;
        int atime[26], btime[26];
};

struct tteam {
        string name;
        int bs, as;
        int atime, btime;
        bool operator<(const tteam &t) const {
                if (bs != t.bs) {
                        return bs > t.bs;
                }
                return btime < t.btime;
        }
};

struct SUB {
        string tname;
        char pid;
        int time;
        string res;
        bool operator<(const SUB &t) const {
                return time < t.time;
        }
};

void solve() {
        int n;
        cin >> n;
        map<string, TEAM> team;
        vector<SUB> sub(n);
        for (auto &x : sub) {
                cin >> x.tname >> x.pid >> x.time >> x.res;
        }
        sort(sub.begin(), sub.end());
        for (int i = 0; i < n; ++i) {
                auto [tname, pid, time, res] = sub[i];
                int t = int(pid - 'A');
                if (team[tname].af.test(t)) {
                        continue;
                }
                if (res == "Accepted") {
                        team[tname].bf |= 1 << t;
                        team[tname].af |= 1 << t;
                        team[tname].atime[t] += time;
                        team[tname].btime[t] += time;
                } else if (res == "Unknown") {
                        team[tname].af |= 1 << t;
                        team[tname].atime[t] += time;
                } else {
                        team[tname].atime[t] += 20;
                        team[tname].btime[t] += 20;
                }
        }
        vector<tteam> tt;
        for (auto x : team) {
                int atime = 0, btime = 0;
                for (int i = 0; i < 26; ++i) {
                        if (x.second.af.test(i)) {
                                atime += x.second.atime[i];
                        }
                        if (x.second.bf.test(i)) {
                                btime += x.second.btime[i];
                        }
                }
                tt.push_back(
                    { x.first, (int)x.second.bf.count(), (int)x.second.af.count(), atime, btime });
        }
        sort(tt.begin(), tt.end());
        int sv = tt[0].bs, tm = tt[0].btime;
        vector<string> ans;
        for (auto x : tt) {
                if (x.as > sv || (x.as == sv && x.atime <= tm)) {
                        ans.push_back(x.name);
                }
        }
        sort(ans.begin(), ans.end());
        for (string x : ans) {
                cout << x << ' ';
        }
        cout << endl;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
                solve();
        }

        return 0;
}
