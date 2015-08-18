#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <memory.h>
#include<cstring>
using namespace std;
long long int arr[100];
 void func()
 {
    arr[0]=1;
    arr[1]=2;
    for(int i=2;i<=90;i++)
    {
      arr[i] = arr[i-1]+arr[i-2];
    }
 }
int main() {
    int t;
    cin >>  t;
    func();
    while(t--)
    {
        long long int n;
        cin >> n;
        int cnt=1;
        for(int i=0;i<=90;i++)
        {
            if(n==arr[i])
                {
                    cnt = i+1;
                    break;
                }
            if(n<arr[i])
                {
                    cnt = i;
                    break;
                }
        }
        cout << cnt << endl;
    }
}
