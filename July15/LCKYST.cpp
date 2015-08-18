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
	long long int n;
	cin >> n;
	long long int arr[n];
	for(long long int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    long long int res=0;
     for(long long int i=0;i<n;i++)
    {
        res=arr[i];
       while(res!=0 && res%10==0)
       {
            res=res/10;
       }
       if(res%10==5)
       {
           res=1;
       while(arr[i]!=0 && (arr[i]%10==5 || arr[i]%10==0))
       {
           res = (arr[i]*4);
           long long int temp=res;
           while(temp!=0 && temp%10==0)
       {
            temp=temp/10;
       }
          if(temp%10!=5)
               break;
          arr[i]=res;
       }
       }
       else
        res=arr[i];
       cout << res << endl;
    }


}
