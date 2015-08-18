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

int main() {
	ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--)
    {
        int n,m;
        cin >> n >> m;
        if(n>m)
        {
           int cnt=0;
           int tempn =n;
           int tempm =m;
           while(tempn>tempm)
           {
               tempn=(tempn%2==1)?((tempn-1)/2):(tempn/2);
               cnt++;
           }
           int ans = -1;
           if(tempn==tempm)
               ans = cnt;
            else
            {
                cnt=0;
                tempn =n;
                tempm =m;
                while(true)
                 {
                      if((tempn<=tempm) && ((int)(tempn & (tempn-1)) ==0))break;


                      tempn=(tempn%2==1)?((tempn-1)/2):(tempn/2);
                     cnt++;
                 }
              while(tempn<tempm)
              {
               tempn=(tempn*2);
               cnt++;
              }
              if(tempn==tempm)
               { if(ans!=-1)ans = min(ans,cnt); else ans = cnt;}
            }
           cout << ans << endl;
        }
        else if(m>n)
        {
            int cnt=0;
           int tempn =n;
           int tempm =m;
           int ans = -1;
           while(tempm>tempn)
           {
               tempn=tempn*2;
               cnt++;
           }
           if(tempn==tempm)
           { if(ans!=-1)ans = min(ans,cnt); else ans = cnt;}
            else
            {
                cnt=0;
                 tempn =n;
                 tempm =m;
                 while(true)
                 {
                     if((tempn<=tempm) && ((int)(tempn & (tempn-1)) ==0))break;

                      tempn=(tempn%2==1)?((tempn-1)/2):(tempn/2);
                     // cout << tempn << " " << (int)(tempn & (tempn-1)) << endl;
                     cnt++;
                 }
              while(tempn<tempm)
              {
               tempn=(tempn*2);
               cnt++;
              }
              if(tempn==tempm)
               { if(ans!=-1)ans = min(ans,cnt); else ans = cnt;}
            }

        cout << ans << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}
