#include <iostream>
#include <string>
using namespace std;

const string lessThan20[] = {
    "", "One", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen",
    "Fifteen", "Sixteen", "Seventeen",
    "Eighteen", "Nineteen"};

const string tenDivisors[] = {
    "", "Ten", "Twenty", "Thirty", "Forty", "Fifty",
    "Sixty", "Seventy", "Eighty", "Ninety"};

const string biggerNums[] = {"", "Thousand", "Million", "Billion"};

string smallNumberConverter(int n) {
    if (n == 0) return "";
    if (n < 20) return lessThan20[n] + " ";
    if (n < 100) return tenDivisors[n / 10] + " " + smallNumberConverter(n % 10);
    return lessThan20[n / 100] + " Hundred " + smallNumberConverter(n % 100); 
}

string numberToWords(int num) {
    if (num == 0) return "Zero";
    string result = "";
    for (int i = 0; i < 4; i++) {
        if (num % 1000 != 0) {
            result = smallNumberConverter(num % 1000) + biggerNums[i] + " " + result;
        }
        num /= 1000;
    }
    result.erase(result.find_last_not_of(" ") + 1);
    return result;
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << numberToWords(n) << endl;
    return 0;
}
