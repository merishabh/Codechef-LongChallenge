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
	int t;
	cin >> t;
	while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        int l= s1.length();
        bool fi=true;
        for(int i=0;i<l;i++)
        {
            if(s1[i]=='#' && s2[i]=='#')
            {fi=false;break;}
        }
       if(!fi)
       {
           cout << "No" << endl;
       }
       else
       {
           cout << "Yes" << endl;
           int cnt=-1;
           if(s1[0]=='.')
            {
               cnt=0;
               int val=1  ;
           for(int i=1;i<l;i++)
           {
               if(s2[i]=='.' && s1[i]=='#')
               { if(val==1){cnt++;val=2;}}
               else if(s1[i]=='.' && s2[i]=='#')
               { if(val==2){cnt++;val=1;}}
           }
           }
          int cmt=-1;
          if(s2[0]=='.')
            {
                cmt=0;
               int val=2;
           for(int i=1;i<l;i++)
           {
               if(s2[i]=='.' && s1[i]=='#')
               { if(val==1){cmt++;val=2;}}
               else if(s1[i]=='.' && s2[i]=='#')
               {
                 if(val==2)
                {cmt++;val=1;}
                }
           }
          }
          if(cnt==-1)
            cout << cmt << endl;
          else if(cmt==-1)
            cout << cnt << endl;
          else
          cout << min(cmt,cnt) << endl;
       }
    }
}
