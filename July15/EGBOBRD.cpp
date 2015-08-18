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
	long long int t;
	cin >> t;
	while(t--)
    {
	long long int n,k;
	cin >> n >> k;
	long long int a[n];
	for(long long int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    long long int left=0;
    long long int packets=0;
    for(long long int i=0;i<n;i++)
    {
        if(left>=a[i])
        {
            left=left-a[i];
            if(left>0)
                left--;
            continue;
        }
        else
        {
            a[i]=a[i]-left;
            left=0;
        }
        if(a[i]>=k)
        {
            long long int val = a[i]/k;
            long long int rem = a[i]%k;
            if(rem)
            {
                packets +=(val+1);
                left = k-rem-1;
            }
            else
            {
                packets +=val;
            }
        }
        else
        {
              left=k-a[i]-1;
              packets +=1;
        }
    }
    cout << packets << endl;
}
}
