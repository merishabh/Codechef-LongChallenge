#include <iomanip>
#include <cstdio>
using namespace std;

int n;
long long int tree[2099999];
long long int lazy[2099999];

void build_tree(int node,int a,int b)
{
    if(a>b) return;
    if(a==b)
    {
        tree[node]=n;
        lazy[node]=0;
        return;
    }
    build_tree(2*node,a,(a+b)/2);
    build_tree(2*node+1,(a+b)/2+1,b);
    tree[node]=(tree[2*node]+tree[2*node+1]);
    lazy[node]=(lazy[2*node]+lazy[2*node+1]);
}

void update_tree(int node,int a,int b,int i,int j,int value)
{
    if(lazy[node]!=0)
    {
//        int tempval= (int)((b-a+1)*lazy[node]);
//        tree[node]=tree[node]-(tempval);

        tree[node]= tree[node] -((b-a+1)*lazy[node]);
        if(a!=b)
        {
            lazy[2*node] += lazy[node] ;
            lazy[2*node+1] += lazy[node];
        }
        lazy[node]=0;
    }
    if(a>b || b<i || a>j)
        return;
    if(i<=a && j>=b)
    {

//       int tempval= (int)((b-a+1)*value);
//        tree[node]=tree[node] - (tempval);

        tree[node]= tree[node] -((b-a+1)*value);
        if(a!=b)
        {
            lazy[2*node] += value;
            lazy[2*node+1] += value;
        }
        return;
    }
    update_tree(node*2, a, (a+b)/2, i, j, value);
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
    tree[node]=(tree[2*node]+tree[2*node+1]);
}

long long int query_tree(int node,int a,int b,int i,int j)
{
    if(a>b || b<i || a>j)
        return 0;
    if(lazy[node]!=0)
    {
//       int tempval= (int)((b-a+1)*lazy[node]);
//        tree[node]= tree[node] -(tempval);
        tree[node]= tree[node] -((b-a+1)*lazy[node]);
        if(a!=b)
        {
            lazy[2*node] += lazy[node] ;
            lazy[2*node+1] += lazy[node];
        }
        lazy[node]=0;
    }
    if(i<=a && j>=b)
    {
       return tree[node];
    }
//    long long int q1 = query_tree(node*2, a, (a+b)/2, i, j);
//	long long int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
//    return q1+q2;
    return (query_tree(node*2, a, (a+b)/2, i, j) + query_tree(1+node*2, 1+(a+b)/2, b, i, j));
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
           int k;
           scanf("%d %d",&n,&k);
           build_tree(1,0,n-1);
           for(int i=0;i<n;i++)
           {
                 int val1 , val2;
                 scanf("%d %d",&val1,&val2);
                 update_tree(1,0,n-1,val1,val2,1);
           }
           long long int ans=(long long int)k*n;
           for(int i=0;i<=n-k;i++)
           {
               long long int val_ans = query_tree(1,0,n-1,i,i+k-1);
               if(ans>val_ans)
                    ans = val_ans;
           }
          printf("%lld\n",ans);
    }
}


