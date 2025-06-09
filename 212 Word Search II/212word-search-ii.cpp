#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> bd;
vector<vector<bool>> vis;
set<string> found; 
vector<string> ans;
int idx[4] = {0, 0, -1, 1};
int idy[4] = {-1, 1, 0, 0};

class Node {
public:
    vector<Node*> next;
    int flag;

    Node() {
        next = vector<Node*>(26, nullptr);
        flag = 0;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->next[c - 'a']) {
                curr->next[c - 'a'] = new Node();
            }
            curr = curr->next[c - 'a'];
        }
        curr->flag = 1;
    }

    Node* getroot() {
        return root;
    }
};

class Solution {
private:
    void find(Node* head, int x, int y, string &s, int n, int m) {
        char c = bd[x][y];
        head = head->next[c - 'a'];
        if (!head) return;

        s.push_back(c);
        if (head->flag && found.find(s) == found.end()) {
            ans.push_back(s);
            found.insert(s);
        }

        vis[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + idx[i];
            int ny = y + idy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                find(head, nx, ny, s, n, m);
            }
        }

        vis[x][y] = false;
        s.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        Trie trie;
        for (auto &word : words) {
            trie.insert(word);
        }

        int n = board.size();
        int m = board[0].size();
        bd = board;
        vis.assign(n, vector<bool>(m, false));
        ans.clear();
        found.clear();

        string s;
        Node* root = trie.getroot();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (root->next[board[i][j] - 'a']) {
                    find(root, i, j, s, n, m);
                }
            }
        }

        return ans;
    }
};
