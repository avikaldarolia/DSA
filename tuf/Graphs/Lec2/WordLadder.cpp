// Link: https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if(dict.find(endWord) == dict.end()){
            return 0;
        }   

        int level = 1;

        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);

        while(!q.empty()){
            int cnt = q.size();
            while(cnt--){
                string word = q.front();
                q.pop();
                if(word == endWord){
                    return level;
                }
                
                for(int pos = 0; pos < word.size(); pos++){
                    char temp = word[pos];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        word[pos] = ch;
                        if(dict.contains(word)){
                            q.push(word);
                            dict.erase(word);
                        }
                        word[pos] = temp;
                    }
                }
            }

            level++;
        }

        return 0;
    }
};