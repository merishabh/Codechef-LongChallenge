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
        bool flag=false;
       string frnt, bck, left, right, top ,bottom;
       cin >>  frnt >>  bck >> left>> right >> top >> bottom;
       if(frnt==right)
       {
           string temp =frnt;
           if(temp==top || temp==bottom)
                 flag=true;
       }
       if(right==bck)
       {
           string temp =right;
           if(temp==top || temp==bottom)
                 flag=true;
       }
       if(bck==left)
       {
           string temp =bck;
           if(temp==top || temp==bottom)
                 flag=true;
       }
       if(left==frnt)
       {
           string temp =frnt;
           if(temp==top || temp==bottom)
                 flag=true;
       }
//       if(left==right)
//       {
//           string temp =left;
//           if(temp==frnt || temp==bck|| temp==top || temp==bottom)
//                 flag=true;
//       }
//       if(frnt==bck)
//       {
//           string temp =frnt;
//           if(temp==left || temp==right|| temp==top || temp==bottom)
//                 flag=true;
//       }
//       if(top==bottom)
//       {
//           string temp =top;
//           if(temp==frnt || temp==bck|| temp==left || temp==right)
//                 flag=true;
//       }
       if(flag)
        cout << "YES" << endl;
        else
        cout << "NO" << endl;
    }
}
