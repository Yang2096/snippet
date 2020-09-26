#include<unordered_map>
#include<iostream>
#include<list>

using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity) : _capacity(capacity)
    {
    }

    int get(int key)
    {
        auto ret = map.find(key);
        if(ret == map.end())
            return -1;
        else
        {
            auto ans = *(ret->second);
            cache.erase(ret->second);
            cache.push_front(ans);
            map[ret->first] = cache.begin();
            return ans.second;
        }
    }

    void put(int key, int value)
    {
        auto ret = map.find(key);
        if (ret == map.end())
        {
            if (cache.size() >= _capacity)
            {
                auto p = cache.back();
                cache.pop_back();
                map.erase(p.first);
            }
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
        else
        {
            cache.erase(ret->second);
            cache.push_front(make_pair(key,value));
            map[ret->first] = cache.begin();
        }
    }
private:
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> map;
    int _capacity;
};