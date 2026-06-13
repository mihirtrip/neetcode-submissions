class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {

        TrieNode* curr = root;

        for(char ch : word) {

            int idx = ch - 'a';

            if(curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }

    bool dfs(TrieNode* node, string& word, int index) {

        if(node == nullptr) {
            return false;
        }

        if(index == word.length()) {
            return node->isEnd;
        }

        char ch = word[index];

        if(ch == '.') {

            for(int i = 0; i < 26; i++) {

                if(node->children[i] != nullptr) {

                    if(dfs(node->children[i], word, index + 1)) {
                        return true;
                    }
                }
            }

            return false;
        }

        int idx = ch - 'a';

        return dfs(node->children[idx], word, index + 1);
    }

    bool search(string word) {

        return dfs(root, word, 0);
    }
};