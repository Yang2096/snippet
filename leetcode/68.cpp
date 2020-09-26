#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int current_len, len_sum;
    string current_line;
    vector<string> ans;
    int begin, end, empties;
    for(int i = 0; i < words.size();)
    {
        current_len = len_sum = 0;
        begin = i;
        while(i < words.size())
        {
            current_len += (words[i].length() + (current_len == 0 ? 0 : 1));
            if(current_len > maxWidth)
                break;
            len_sum += words[i].length();
            ++i;
        }
        if(i == words.size())
        {
            current_line += words[begin];
            for(int j = begin + 1; j < i; ++j)
            {
                current_line += ' ' + words[j];
            }
        }
        else
        {
            empties = max(1, i - begin - 1);
            end = i - 1; 
            int ex_space = (maxWidth - len_sum) % empties;
            int avg_space = (maxWidth - len_sum) / empties;
            for(int j = begin; j < end; ++j)
            {
                current_line += words[j] + string(avg_space + (ex_space > 0 ? 1 : 0), ' ');
                --ex_space;
            }
            current_line += words[end];
        }
        if(current_line.length() != maxWidth)
        {
            current_line += string(maxWidth - current_line.length(), ' ');
        }
        cout << current_line << ',' << endl;
        ans.emplace_back(std::move(current_line));   
    }
    cout << endl;
    return ans;
}

int main(int argc, char* argv[])
{
 
    vector<string> input = {"Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"};

    fullJustify(input, 20);
    fullJustify(input, 10);
    input = {"What","must","be","acknowledgment","shall","be"};
    fullJustify(input, 16);
    input = {"This", "is", "an", "example", "of", "text", "justification."};
    fullJustify(input, 16);
    input = {"hello"};
    fullJustify(input, 5);
}