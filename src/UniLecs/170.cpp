#include <iostream>
#include <string>
#include <vector>
using namespace std;

char alphabet[8] = {'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};

void recursion(int start, string digits, string sb, vector<string> &result)
{
    if (start == digits.length())
    {
        result.push_back(sb);
        return;
    }
    int bound = digits[start] - '0' == 7 || digits[start] - '0' == 9 ? 4 : 3;
    for (int j = 0; j < bound; j++)
    {
        sb += (char)(alphabet[(digits[start] - '0') - 2] + j);
        recursion(start + 1, digits, sb, result);
        sb.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    string digits, sb = "";
    vector<string> result;
    cin >> digits;
    recursion(0, digits, sb, result);
    for (auto i : result)
        cout << i << ' ';
    cout << endl;
    return 0;
}
