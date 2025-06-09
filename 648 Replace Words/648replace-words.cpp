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

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *curr = root;
        for (auto it : word)
        {
            if (curr->next[it - 'a'])
            {
                curr = curr->next[it - 'a'];
            }
            else
            {
                curr->next[it - 'a'] = new Node();
                curr = curr->next[it - 'a'];
            }
        }
        curr->flag = 1;
    }
    string search(string word)
    {
        string ans = "";
        Node *curr = root;
        for (auto it : word)
        {
            if (curr->next[it - 'a'])
            {
                ans.push_back(it);
                curr = curr->next[it - 'a'];
                if (curr->flag)
                    return ans;
            }
            else
                return word;
        }
        return word;
    }
};
class Solution
{
public:
    string replaceWords(vector<string> &words, string sentence)
    {
        Trie trie;
        for (auto &word : words)
        {
            trie.insert(word);
        }
        stringstream ss(sentence);
        string word;
        string ans = "";
        while (ss >> word)
        {
            ans += (trie.search(word) + " ");
        }
        ans.pop_back();
        return ans;
    }
};