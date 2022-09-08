#include <iostream>
#include <string>
using namespace std;
//attempt 1
void reverseStr(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    cout << s[s.length() - 1];
    reverseStr(s.substr(0, s.length() - 1));
}
//attempt 2
string reverseStr2(string s, int lo, int hi)
{
    if (lo >= hi)
    {
        return s;
    }
    swap(s[lo], s[hi]);
    reverseStr2(s, lo + 1, hi - 1);
    return s;
}

//attempt 1
void checkPal(string s, int lo, int hi)
{
    if (lo >= hi)
    {
        return;
    }
    if (s[lo] != s[hi])
    {
        cout << "Not a palindrome" << endl;
        return;
    }
    reverseStr2(s, lo + 1, hi - 1);
    cout << "It is a palindrome" << endl;
}
bool checkPal2(string s, int lo, int hi)
{
    if (lo >= hi)
    {

        return true;
    }
    if (s[lo] == s[hi])
    {
        return checkPal2(s, lo + 1, hi - 1);
    }
    else
    {
        return false;
    }
}
int main()
{
    string s;
    cin >> s;
    cout << reverseStr2(s, 0, s.length() - 1) << endl;
    checkPal(s, 0, s.length() - 1);
    if (checkPal2(s, 0, s.length() - 1))
    {
        cout << "yes it is a palindrome" << endl;
    }
    else
    {
        cout << "no it is not a palindrome" << endl;
    }
    return 0;
}