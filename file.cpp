
#include <iostream>
#include <queue>
#include <string>
#include <bitset>
using namespace std;
int a[10];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i;
  cin >> i;
  for (int j = 0; j < i; j++)
  {
    cin >> a[j];
  }
  for (int j = 0; j < i; j++)
  {
    cout << a[j] << endl;
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}

void solve()
{
}
