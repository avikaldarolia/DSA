// Link: https://leetcode.com/problems/design-browser-history/description/

class BrowserHistory {
public:
    vector<string> urls;
    int cur;
    BrowserHistory(string homepage) {
        urls.push_back(homepage);
        cur = 0;
    }
    
    void visit(string url) {
        ++cur;
        urls.resize(cur);
        urls.push_back(url);
    }
    
    string back(int steps) {
        cur = max(0, cur - steps);
        return urls[cur];
    }
    
    string forward(int steps) {
        cur = min((int)urls.size() - 1, steps +cur);
        return urls[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */