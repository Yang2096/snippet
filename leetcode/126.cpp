#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<unordered_set>

using namespace std;
bool compare(string &a, string &b)
{
    int count = 0, n = a.length();
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            if (++count > 1)
                return false;
        }
    }
    return count == 1;
}
vector<vector<string>> ans;
string _begin;
void addLine(vector<string> &line, int current, vector<unordered_set<int>> &path, vector<string> &wordList)
{
    for(int next : path[current])
    {
        if(next == -1)
        {
            line.push_back(_begin);
            ans.emplace_back(line.rbegin(), line.rend());
            line.pop_back();
            break;
        }
        line.push_back(wordList[next]);
        addLine(line, next, path, wordList);
        line.pop_back();
    }
}


vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    ans.clear();
    int size = wordList.size();
    if (size == 0)
        return ans;

    vector<string> line;

    int i = 0;
    bool beginExist = false;
    for (; i < size; ++i)
    {
        if (!beginExist && beginWord == wordList[i])
            beginExist = true;
        if (endWord == wordList[i])
            break;
    }
    if (i == size)
        return ans;
    if (beginExist && compare(beginWord, endWord))
    {
        line.push_back(beginWord);
        line.push_back(endWord);
        ans.push_back(line);
        return ans;
    }
    _begin = beginWord;
    vector<int> mark(size, -2);
    vector<unordered_set<int>> path(size + 1);
    int end = -1;
    int q_size = 1, parent, layer = 0;
    string cur;
    queue<int> q;
    q.push(-1);    // beginWord 的下标为 -1
    while (!q.empty())
    {
        while (q_size-- > 0)
        {
            parent = q.front();
            if(parent == -1)
                cur = beginWord;
            else
                cur = wordList[parent];
            q.pop();

            for (int j = 0; j < size; ++j)
            {
                if ((mark[j] == -2 || mark[j] == layer + 1) && compare(cur, wordList[j]))
                {
                    path[j].insert(parent);   // 记录当前节点的前驱
                    if (endWord == wordList[j])
                    {
                        end = j;
                    }
                    else if(mark[j] != layer + 1)
                    {
                        q.push(j);
                        mark[j] = layer + 1;
                    }
                }
            }
        }
        if(end != -1)
            break;
        ++layer;
        q_size = q.size();
    }
    line.push_back(endWord);
    if(end != -1)
    addLine(line, end, path, wordList);
    return ans;
}

int main()
{
    vector<string> wordList = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee" };
    auto a = findLadders("red", "tax", wordList);
    for (auto &line : a)
    {
        for (auto b : line)
        {
            cout << b << ' ';
        }
        cout << endl;
    }
    wordList = {"d", "b", "c"};
    a = findLadders("a", "c", wordList);
    for (auto &line : a)
    {
        for (auto b : line)
        {
            cout << b << ' ';
        }
        cout << endl;
    }
    wordList = {"hot", "dog"};
    a = findLadders("hot", "dog", wordList);
    for (auto &line : a)
    {
        for (auto b : line)
        {
            cout << b << ' ';
        }
        cout << endl;
    }
}