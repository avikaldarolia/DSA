// Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

class WordDictionary {
public:
    struct Trie{
        Trie* children[26];
        bool end;
    } *root;

    Trie* gen(){
        Trie* node = new Trie();
        for(int i = 0; i < 26; i++){
            node->children[i] = NULL;
        }
        node->end = false;
        return node;
    }

    WordDictionary() {
        root = gen();
    }
    
    void addWord(string word) {
        Trie *c = root;

        for(int i = 0; i < word.size(); i++){
            int indx = word[i] - 'a';
            if(c->children[indx] == NULL){
                c->children[indx] = gen();
            }

            c = c->children[indx];
        }

        c->end = true;
    }

    bool sHelper(string word, Trie *c){
         for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(ch == '.'){
                for(auto x: c->children){
                    if(x && sHelper(word.substr(i + 1), x)){
                        return true;
                    }
                }
                return false;
            }
            else{
                int indx = ch - 'a';
                if(c->children[indx] == NULL){
                    return false;
                }

                c = c->children[indx];
            }
        }

        return (c != NULL && c->end);
    }
    
    bool search(string word) {
        return sHelper(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */