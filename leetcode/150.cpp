#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

int evalRPN(vector<string>& tokens) {
    int ans = 0;
    stack<int> s;
    int a, b;
    for(auto& token : tokens)
    {
        if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            switch(token[0])
            {
                case '+':
                    s.push(b + a);
                    break;
                case '-':
                    s.push(b - a);
                    break;
                case '*':
                    s.push(b * a);
                    break;
                case '/':
                    s.push(b / a);
                    break;
            }
        }else
            s.push(std::stoi(token));
    }
    return s.top();
}
