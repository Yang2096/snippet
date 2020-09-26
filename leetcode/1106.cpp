#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool parseBoolExpr(string expression) {
    if(expression.size() == 1)
    {
        return expression[0] == 'f' ? false : true;
    }
    stack<char> ops;
    stack<bool> values;
    stack<int> numbers;
    int count = 0;
    for(auto ch : expression)
    {
        switch(ch)
        {
            case 'f':
            {
                values.push(false);
                break;
            }
            case 't':
            {
                values.push(true);
                break;
            }
            case ',':
            {
                ++numbers.top();
                break;
            }
            case '(':
                continue;
            case '!':
            case '&':
            case '|':
            {
                ops.push(ch);
                numbers.push(1);
                break;
            }
            case ')':
            {
                count = numbers.top(); numbers.pop();
                bool cal = values.top();
                switch(ops.top())
                {
                    case '&':
                    {
                        for(int i = 0; i < count; ++i)
                        {
                            cal &= values.top(); values.pop();
                        }
                        values.push(cal);
                        break;
                    }
                    case '|':
                    {
                        for(int i = 0; i < count; ++i)
                        {
                            cal |= values.top(); values.pop();
                        }
                        values.push(cal);
                        break;
                    }
                    case '!':
                    {
                        values.top() = !cal;
                        break;
                    }
                }
                ops.pop();
                break;
            }
        }
    }
    return values.top();
}

int main(int argc, char const *argv[])
{
    string expression("!(f)");
    cout << parseBoolExpr(expression) << endl; 
    return 0;
}
