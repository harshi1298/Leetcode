#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    vector<Node *> next;
    int flag;

    Node()
    {
        next = vector<Node *>(26, nullptr);
        flag = 0;
    }
};

class WordDictionary
{
private:
    Node *root;

    bool dfs(Node *curr, const string &word, int idx)
    {
        if (!curr) return false;
        if (idx == word.size()) return curr->flag;

        char ch = word[idx];
        if (ch == '.')
        {
            for (int i = 0; i < 26; ++i)
            {
                if (curr->next[i] && dfs(curr->next[i], word, idx + 1))
                    return true;
            }
            return false;
        }
        else
        {
            return dfs(curr->next[ch - 'a'], word, idx + 1);
        }
    }

public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *curr = root;
        for (char ch : word)
        {
            if (!curr->next[ch - 'a'])
                curr->next[ch - 'a'] = new Node();
            curr = curr->next[ch - 'a'];
        }
        curr->flag = 1;
    }

    bool search(string word)
    {
        return dfs(root, word, 0);
    }
};
