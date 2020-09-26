#include "pch.h"

class BrowserHistory
{
public:
    BrowserHistory(string homepage)

    {
        _stack.emplace_back(move(homepage));
        size = 1;
        _max = 1;
    }

    void visit(string url)
    {
        if (_stack.size() > size)
        {
            _stack[size] = move(url);
            _max = size + 1;
        }
        else
        {
            _stack.emplace_back(move(url));
            _max = _stack.size();
        }
        size++;
    }

    string back(int steps)
    {
        size -= min(size - 1, steps);
        return _stack[size - 1];
    }

    string forward(int steps)
    {
        if (_max != size)
        {
            size += min(steps, _max - size);
        }
        return _stack[size - 1];
    }

private:
    vector<string> _stack;
    int size;
    int _max;
};


int main()
{
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");   // 你原本在浏览 "leetcode.com" 。访问 "google.com"
    browserHistory.visit("facebook.com"); // 你原本在浏览 "google.com" 。访问 "facebook.com"
    browserHistory.visit("youtube.com");  // 你原本在浏览 "facebook.com" 。访问 "youtube.com"
    cout << browserHistory.back(1) << endl;               // 你原本在浏览 "youtube.com" ，后退到 "facebook.com" 并返回 "facebook.com"
    cout << browserHistory.back(1) << endl;               // 你原本在浏览 "facebook.com" ，后退到 "google.com" 并返回 "google.com"
    cout << browserHistory.forward(1) << endl;            // 你原本在浏览 "google.com" ，前进到 "facebook.com" 并返回 "facebook.com"
    browserHistory.visit("linkedin.com"); // 你原本在浏览 "facebook.com" 。 访问 "linkedin.com"
    cout << browserHistory.forward(2) << endl;            // 你原本在浏览 "linkedin.com" ，你无法前进任何步数。
    cout << browserHistory.back(2) << endl;               // 你原本在浏览 "linkedin.com" ，后退两步依次先到 "facebook.com" ，然后到 "google.com" ，并返回 "google.com"
    cout << browserHistory.back(7) << endl;               // 你原本在浏览 "google.com"， 你只能后退一步到 "leetcode.com" ，并返回 "leetcode.com"
}