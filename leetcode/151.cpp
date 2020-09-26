#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
#include<numeric>
using namespace std;

string reverseWords(string s)
{
    vector<string> vs;
    istringstream iss(s);
    istream_iterator<string> is_it(iss);
    transform(is_it, istream_iterator<string>(), std::back_insert_iterator(vs), [](string s) -> string { return s; });
    reverse(vs.begin(), vs.end());
    string ans = vs[0];
    return accumulate(next(vs.begin()), vs.end(), ans, [](string& a, string& b) -> string {
        return a + ' ' + b;
    });
}

int main()
{
    string s = " hell o wor ld    ";
    cout << reverseWords(s) << endl;
}