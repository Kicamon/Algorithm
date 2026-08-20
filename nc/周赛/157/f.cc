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
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ai3 = array<int, 3>;

ai3 operator+(const ai3 &a, const ai3 &b) {
        return ai3{ a[0] + b[0], a[1] + b[1], a[2] + b[2] };
}

class segment_tree {
    private:
        struct Node {
                int l, r;
                int lazy;
                ai3 num = { 0, 0, 0 };
        };

        vector<int> a;
        vector<Node> node;

    public:
        segment_tree(int n, string s) {
                node.resize((n + 1) << 2);
                a.resize(n + 1);
                for (int i = 0; i < (int)s.size(); ++i) {
                        a[i + 1] = s[i] - 'A';
                }
                build(1, 1, n);
        }

        void reverse(Node &t) {
                swap(t.num[0], t.num[2]);
                swap(t.num[1], t.num[2]);
                t.l = (t.l + 1) % 3;
                t.r = (t.r + 1) % 3;
        }

        void push(int u) {
                Node l = node[u << 1], r = node[u << 1 | 1];
                while (l.lazy--) {
                        reverse(l);
                }
                while (r.lazy--) {
                        reverse(r);
                }
                node[u] = { l.l, r.r, 0, l.num + r.num };
                if (l.r == r.l) {
                        node[u].num[l.r]--;
                }
        }

        void down(int u) {
                int t = node[u].lazy;
                while (t--) {
                        reverse(node[u]);
                }
                (node[u << 1].lazy += node[u].lazy) %= 3;
                (node[u << 1 | 1].lazy += node[u].lazy) %= 3;
                node[u].lazy = 0;
        }

        void build(int u, int l, int r) {
                if (l == r) {
                        node[u] = { a[l], a[l], 0 };
                        node[u].num[a[l]]++;
                        return;
                }
                int mid = (l + r) >> 1;
                build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
                push(u);
        }

        void modify(int u, int l, int r, const int &L, const int &R) {
                if (L <= l && r <= R) {
                        (node[u].lazy += 1) %= 3;
                        return;
                }
                down(u);
                int mid = (l + r) >> 1;
                if (L <= mid) {
                        modify(u << 1, l, mid, L, R);
                }
                if (mid < R) {
                        modify(u << 1 | 1, mid + 1, r, L, R);
                }
                push(u);
        }

        int query() {
                down(1);
                return node[1].num[0];
        }
};

int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, q, op, l, r;
        cin >> n >> q;
        string s;
        cin >> s;
        segment_tree st(n, s);
        while (q--) {
                cin >> op;
                if (op == 1) {
                        cin >> l >> r;
                        st.modify(1, 1, n, l, r);
                } else {
                        cout << st.query() << '\n';
                }
        }

        return 0;
}
