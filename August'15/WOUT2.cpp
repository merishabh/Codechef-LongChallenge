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
	long long int t;
    scanf("%lld",&t);
	while(t--)
    {
        long long int n,k;
        scanf("%lld %lld",&n,&k);
        long long int arr[n+2];
        memset(arr,0,sizeof(arr));
        for(long long int i=0;i<n;i++)
        {
            long long int a,b;
            cin >> a >> b ;
            arr[a] += 1;
            arr[b+1] += -1;
        }
        for(long long int i=1;i<=n;i++)
        {
              arr[i] += arr[i-1];
        }
        for(long long int i=1;i<=n;i++)
        {
              arr[i] += arr[i-1];
        }
        long long int ans= arr[k-1];
        long long int val=0;
        for(long long int i=k;i<=(n);i++)
        {
            long long int sum= arr[i]-arr[val];
            ans = max(ans,sum);
            val++;
        }
        long long int tempans = k*n;
        tempans -= ans;
        printf("%lld\n",tempans);
    }
}
