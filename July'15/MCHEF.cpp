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


long long dp[100005][502];
struct temp
{
   int l;
   int r;
   int c;
}task[500005];

int tree[400005];
int lazy[400005];

bool acompare(temp lhs, temp rhs)
{
   return lhs.c <= rhs.c;
}

void build_tree(int node,int a,int b)
{
    if(a>b) return;
    if(a==b)
    {
        tree[node]=1000;
        return;
    }
    build_tree(2*node,a,(a+b)/2);
    build_tree(2*node+1,(a+b)/2+1,b);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
int query_tree(int node,int a,int b,int i,int j)
{
    if(a>b || b<i || a>j)
        return 1000;
    if(lazy[node]!=0)
    {
        tree[node]=min(tree[node],lazy[node]);
        if(a!=b)
        {
            lazy[2*node]=(lazy[2*node]!=0)?min(lazy[node],lazy[2*node]):lazy[node];
            lazy[2*node+1]=(lazy[2*node+1]!=0)?min(lazy[node],lazy[2*node+1]):lazy[node];
        }
        lazy[node]=0;
    }
    if(i<=a && j>=b)
        return tree[node];

    int q1 = query_tree(node*2, a, (a+b)/2, i, j);
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);

    return min(q1,q2);
}

void update_tree(int node,int a ,int b,int i,int j,int value)
{
    if(lazy[node]!=0)
    {
        tree[node]=min(lazy[node],tree[node]);
        if(a!=b)
        {
            lazy[2*node]=(lazy[2*node]!=0)?min(lazy[node],lazy[2*node]):lazy[node];
            lazy[2*node+1]=(lazy[2*node+1]!=0)?min(lazy[node],lazy[2*node+1]):lazy[node];
        }
        lazy[node]=0;
    }
    if(a>b || b<i || a>j)
        return;
    if(i<=a && j>=b)
    {
        tree[node]=min(tree[node],value);
        if(a!=b)
        {
            lazy[2*node]=(lazy[2*node]!=0)?min(value,lazy[2*node]):value;
            lazy[2*node+1]=(lazy[2*node+1]!=0)?min(value,lazy[2*node+1]):value;
        }
        return;
    }
    update_tree(node*2, a, (a+b)/2, i, j, value);
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);

}

int main() {
	//ios_base::sync_with_stdio(0);
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int N,M,K;
        scanf("%d %d %d",&N,&K,&M);
        long long arr[N];
        long long sum=0;
        long long mini= -1000000007;
        for(long long i=0;i<N;i++)
            {
                int value_curr;
                scanf("%d",&value_curr);
                arr[i]=value_curr;
                sum +=arr[i];
                mini=max(mini,arr[i]);
            }
//            for(long long i=0;i<N;i++)
//               cout << arr[i] << endl;
            build_tree(1,0,N-1);
//     long long dp[N+2][K+2];
   // cout << "hi" << endl;
        for(int i=0;i<M;i++)
        {
            int left,right,cst;
           scanf("%d %d %d",&left,&right,&cst);
           task[i].l=left;
           task[i].r=right;
           task[i].c=cst;
            task[i].l--;
            task[i].r--;
            update_tree(1,0,N-1,task[i].l,task[i].r,task[i].c);
        }
         /*for(int i=1;i<20;i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;*/
      //sort(task,task+M,acompare);
//cout << "hi" << endl;




//cout << "hi" << endl;

//           for(long long i=0;i<M;i++)
//        {
//            cout << task[i].l << " " << task[i].r << " " << task[i].c << endl;
//        }
        int cost[N];
       for(int i=0;i<N;i++)
        {
            cost[i]=query_tree(1,0,N-1,i,i);
        }
//       for(int i=0;i<N;i++)
//            cout << cost[i] << " ";
//        cout << endl;
//  cout << "hi" << endl;

//        for(int i=task[0].l;i<=task[0].r;i++)
//        {
//              cost[i]=task[0].c;
//        }
//        for(int i=1;i<M;i++)
//        {
//            for(int s=task[i].l;s<=task[i].r;s++)
//            {
//                if(cost[s]==1000)
//                    cost[s]=task[i].c;
//            }
//        }
//        for(long long i=1;i<=N;i++)
//          cout << cost[i] << " ";
//          cout << endl;
        for(int i=1;i<=K;i++)
        {
            if(arr[0]<0)
            {
                if(i>=cost[0])
                    dp[0][i]=arr[0];
                else
                    dp[0][i]=0;
             }
        }
        for(int i=1;i<N;i++)
        {
           for(int j=1;j<=K;j++)
        {
             if(j>=cost[i])
             {
                 dp[i][j]=min(dp[i-1][j],arr[i]+dp[i-1][j-cost[i]]);
             }
             else
             {
                 dp[i][j]=dp[i-1][j];
             }
        }
        }
        long long res = sum-dp[N-1][K];
        if(res!=0)
        cout << res<<endl;
        else
            cout << mini << endl;

}
}
