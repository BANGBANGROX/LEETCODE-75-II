#include<bits/stdc++.h>
using namespace std;

class Trie {
    struct TrieNode {
        bool isEnd;
        TrieNode* children[26];

        TrieNode() {
            for (int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
            isEnd = false;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* pCrawl = root;

        for (char ch : word) {
            int idx = ch - 'a';
            if (pCrawl->children[idx] == NULL) pCrawl->children[idx] = new TrieNode();
            pCrawl = pCrawl->children[idx];
        }

        pCrawl->isEnd = true;
    }

    bool search(string word) {
        TrieNode* pCrawl = root;

        for (char ch : word) {
            int idx = ch - 'a';
            if (pCrawl->children[idx] == NULL) return false;
            pCrawl = pCrawl->children[idx];
        }

        return pCrawl->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* pCrawl = root;

        for (char ch : prefix) {
            int idx = ch - 'a';
            if (pCrawl->children[idx] == NULL) return false;
            pCrawl = pCrawl->children[idx];
        }

        return true;
    }
};


int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}