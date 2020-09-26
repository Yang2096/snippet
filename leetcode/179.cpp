#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string largestNumber(vector<int> &nums)
{
    vector<string> data;
    transform(nums.begin(), nums.end(), back_inserter(data), [](int a)-> string{
        return to_string(a);
    });

    sort(data.begin(), data.end(), [](const string &a, const string &b) -> bool {
        int len1, len2;
        const string *s1, *s2;
        if (a.length() < b.length())
        {
            len1 = a.length();
            len2 = b.length();
            s1 = &a;
            s2 = &b;
        }
        else
        {
            len1 = b.length();
            len2 = a.length();
            s1 = &b;
            s2 = &a;
        }
        bool flag = true;
        int round = len1;
        while(round < len2)
            round += len1;
        for (int i = 0; i < round; ++i)
        {
            if (s1->at(i % len1) < s2->at(i % len2))
            {
                flag = false;
                break;
            }
            else if (s1->at(i % len1) > s2->at(i % len2))
            {
                break;
            }
        }
        if (a.length() < b.length())
        {
            return flag;
        }
        else
        {
            return !flag;
        }
    });
    if(data[0] == "0")
        return "0";
    string ans;
    for(auto & a : data)
        ans += a;

    return ans;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums) << endl;
    nums = {3, 340, 34, 5, 9};
    cout << largestNumber(nums) << endl;
    nums = {3, 343435, 34, 35, 3435};
    cout << largestNumber(nums) << endl;
    nums = {9051, 5526, 2264, 5041, 1630, 5906, 6787, 8382, 4662, 4532, 6804, 4710, 4542, 2116, 7219, 8701, 8308, 957, 8775, 4822, 396, 8995, 8597, 2304, 8902, 830, 8591, 5828, 9642, 7100, 3976, 5565, 5490, 1613, 5731, 8052, 8985, 2623, 6325, 3723, 5224, 8274, 4787, 6310, 3393, 78, 3288, 7584, 7440, 5752, 351, 4555, 7265, 9959, 3866, 9854, 2709, 5817, 7272, 43, 1014, 7527, 3946, 4289, 1272, 5213, 710, 1603, 2436, 8823, 5228, 2581, 771, 3700, 2109, 5638, 3402, 3910, 871, 5441, 6861, 9556, 1089, 4088, 2788, 9632, 6822, 6145, 5137, 236, 683, 2869, 9525, 8161, 8374, 2439, 6028, 7813, 6406, 7519};
    cout << largestNumber(nums) << endl;
}