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

#define MAX 300000
#define MOD 1000000007
#define inf 0x7fffffff

long long int tree[MAX];
long long int lazyAdd[MAX];
long long int lazyMul[MAX];
long long int lazyVal[MAX];
long long int arr[MAX];
long long int cnt[MAX];
void build_tree(int node,int a,int b)
{
    if(a>b) return;
    if(a==b)
    {
        tree[node]= arr[a];
        return;
    }
    build_tree(2*node,a,(a+b)/2);
    build_tree(2*node+1,1+((a+b)/2),b);
    tree[node] = tree[2*node] + tree[2*node+1];
}
void build_cnt_tree(int node,int a,int b)
{
    if(a>b) return;
    if(a==b)
    {
        cnt[node]= 1;
        return;
    }
    build_cnt_tree(2*node,a,(a+b)/2);
    build_cnt_tree(2*node+1,1+((a+b)/2),b);
    cnt[node] = cnt[2*node] + cnt[2*node+1];
}
/*void updateAdd_tree(int node, int a, int b, int i, int j, int value) {

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a == b) { // Leaf node
    		tree[node] = (tree[node]+ value)%MOD;
    		return;
	}
	updateAdd_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	updateAdd_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = (tree[node*2] + tree[node*2+1])%MOD; // Updating root with max value
}

void updateMul_tree(int node, int a, int b, int i, int j, int value) {

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a == b) { // Leaf node
    		tree[node] = (tree[node]* value)%MOD;
    		return;
	}
	updateMul_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	updateMul_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = (tree[node*2] + tree[node*2+1])%MOD; // Updating root with max value
}

long long int quer_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return -inf; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	long long int q1 = quer_tree(node*2, a, (a+b)/2, i, j); // Query left child
	long long int q2 = quer_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	long long int res = (q1+ q2)%MOD; // Return final result

	return res;
}*/

void updateAdd_tree(int node,int a,int b,int i,int j,int value)
{
        if(lazyAdd[node]!=0)
        {
            tree[node]=(tree[node]+(cnt[node]*lazyAdd[node]))%MOD;
           // cout << node << " up " << tree[node] << endl;
            if(a!=b)
            {
                lazyAdd[2*node]=(lazyAdd[2*node]+(cnt[2*node]*lazyAdd[node]))%MOD;
                lazyAdd[2*node+1]=(lazyAdd[2*node+1]+(cnt[2*node+1]*lazyAdd[node]))%MOD;
            }
            lazyAdd[node]=0;
        }
        if(lazyMul[node]!=1)
        {
            tree[node]=(tree[node]*lazyMul[node])%MOD;
            if(a!=b)
            {
                lazyMul[2*node]=(lazyMul[2*node]*lazyMul[node])%MOD;
                lazyMul[2*node+1]=(lazyMul[2*node+1]*lazyMul[node])%MOD;
            }
            lazyMul[node]=1;
        }
         if(lazyVal[node]!=0)
        {
            tree[node]=(cnt[node]*lazyVal[node])%MOD;
            if(a!=b)
            {
                lazyVal[2*node]=(cnt[2*node]*lazyVal[node])%MOD;
                lazyVal[2*node+1]=(cnt[2*node+1]*lazyVal[node])%MOD;
            }
            lazyVal[node]=0;
        }
        if(a > b || a > j || b < i)
		return;

  	if(a >= i && b <= j) {
    		tree[node] = (tree[node]+(cnt[node]*value))%MOD;
            //cout << node << " down " << tree[node] << endl;
		if(a != b) { // Not leaf node
			lazyAdd[2*node]=(lazyAdd[2*node]+(cnt[2*node]*value))%MOD;
                lazyAdd[2*node+1]=(lazyAdd[2*node+1]+(cnt[2*node+1]*value))%MOD;
		}
    		return;
	}
        updateAdd_tree(node*2, a, (a+b)/2, i, j, value);
	updateAdd_tree(1+node*2, 1+(a+b)/2, b, i, j, value);

	tree[node] = (tree[node*2]+tree[node*2+1])%MOD; // Updating root with max value
}
void updateMul_tree(int node,int a,int b,int i,int j,int value)
{
        if(lazyAdd[node]!=0)
        {
            tree[node]=(tree[node]+(cnt[node]*lazyAdd[node]))%MOD;
            //cout << node << " up " << tree[node] << endl;
            if(a!=b)
            {
                lazyAdd[2*node]=(lazyAdd[2*node]+(cnt[2*node]*lazyAdd[node]))%MOD;
                lazyAdd[2*node+1]=(lazyAdd[2*node+1]+(cnt[2*node+1]*lazyAdd[node]))%MOD;
            }
            lazyAdd[node]=0;
        }
        if(lazyMul[node]!=1)
        {
            tree[node]=(tree[node]*lazyMul[node])%MOD;
            if(a!=b)
            {
                lazyMul[2*node]=(lazyMul[2*node]*lazyMul[node])%MOD;
                lazyMul[2*node+1]=(lazyMul[2*node+1]*lazyMul[node])%MOD;
            }
            lazyMul[node]=1;
        }
         if(lazyVal[node]!=0)
        {
            tree[node]=(cnt[node]*lazyVal[node])%MOD;
            if(a!=b)
            {
                lazyVal[2*node]=(cnt[2*node]*lazyVal[node])%MOD;
                lazyVal[2*node+1]=(cnt[2*node+1]*lazyVal[node])%MOD;
            }
            lazyVal[node]=0;
        }
        if(a > b || a > j || b < i)
		return;

  	if(a >= i && b <= j) {
    		tree[node] = (tree[node]*value)%MOD;

		if(a != b) { // Not leaf node
			lazyMul[node*2] = (lazyMul[node*2]*value)%MOD;
			lazyMul[node*2+1] = (lazyMul[node*2+1]*value)%MOD;
		}

    		return;
	}
        updateMul_tree(node*2, a, (a+b)/2, i, j, value);
	updateMul_tree(1+node*2, 1+(a+b)/2, b, i, j, value);

	tree[node] = (tree[node*2]+tree[node*2+1])%MOD; // Updating root with max value
}
void updateVal_tree(int node,int a,int b,int i,int j,int value)
{
     if(lazyAdd[node]!=0)
        {
            tree[node]=(tree[node]+(cnt[node]*lazyAdd[node]))%MOD;
           // cout << node << " up " << tree[node] << endl;
            if(a!=b)
            {
                lazyAdd[2*node]=(lazyAdd[2*node]+(cnt[2*node]*lazyAdd[node]))%MOD;
                lazyAdd[2*node+1]=(lazyAdd[2*node+1]+(cnt[2*node+1]*lazyAdd[node]))%MOD;
            }
            lazyAdd[node]=0;
        }
        if(lazyMul[node]!=1)
        {
            tree[node]=(tree[node]*lazyMul[node])%MOD;
            if(a!=b)
            {
                lazyMul[2*node]=(lazyMul[2*node]*lazyMul[node])%MOD;
                lazyMul[2*node+1]=(lazyMul[2*node+1]*lazyMul[node])%MOD;
            }
            lazyMul[node]=1;
        }
         if(lazyVal[node]!=0)
        {
            tree[node]=(cnt[node]*lazyVal[node])%MOD;
            if(a!=b)
            {
                lazyVal[2*node]=(cnt[2*node]*lazyVal[node])%MOD;
                lazyVal[2*node+1]=(cnt[2*node+1]*lazyVal[node])%MOD;
            }
            lazyVal[node]=0;
        }
        if(a > b || a > j || b < i)
		return;

        	if(a >= i && b <= j) {
    		tree[node] = (cnt[node]*value)%MOD;

		if(a != b) { // Not leaf node
			lazyVal[node*2] = (cnt[2*node]*value)%MOD;
			lazyVal[node*2+1] = (cnt[2*node+1]*value)%MOD;
		}

    		return;
	}

        updateVal_tree(node*2, a, (a+b)/2, i, j, value);
	updateVal_tree(1+node*2, 1+(a+b)/2, b, i, j, value);

	tree[node] = (tree[node*2]+tree[node*2+1])%MOD; // Updating root with max value
}

long long int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return 0; // Out of range
    if(lazyAdd[node]!=0)
        {
            tree[node]=(tree[node]+(cnt[node]*lazyAdd[node]))%MOD;
            //cout << node << " up " << tree[node] << endl;
            if(a!=b)
            {
                lazyAdd[2*node]=(lazyAdd[2*node]+(cnt[2*node]*lazyAdd[node]))%MOD;
                lazyAdd[2*node+1]=(lazyAdd[2*node+1]+(cnt[2*node+1]*lazyAdd[node]))%MOD;
            }
            lazyAdd[node]=0;
        }
        if(lazyMul[node]!=1)
        {
            //cout << lazyMul[node] << endl;
            tree[node]=(tree[node]*lazyMul[node])%MOD;
            if(a!=b)
            {
                lazyMul[2*node]=(lazyMul[2*node]*lazyMul[node])%MOD;
                lazyMul[2*node+1]=(lazyMul[2*node+1]*lazyMul[node])%MOD;
            }
            lazyMul[node]=1;
        }
         if(lazyVal[node]!=0)
        {
            tree[node]=(cnt[node]*lazyVal[node])%MOD;
            if(a!=b)
            {
                lazyVal[2*node]=(cnt[2*node]*lazyVal[node])%MOD;
                lazyVal[2*node+1]=(cnt[2*node+1]*lazyVal[node])%MOD;
            }
            lazyVal[node]=0;
        }

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	long long int q1 = query_tree(node*2, a, (a+b)/2, i, j);
	//cout << q1 << " q1" << endl; // Query left child
	long long int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
    //cout << q2 << " q2" << endl;
	long long int res = (q1+q2)%MOD; // Return final result

	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> arr[i];
        build_tree(1,0,n-1);
        build_cnt_tree(1,0,n-1);
        //memset(lazyMul,1,sizeof(lazyMul));
        for(int i=1;i<MAX;i++)
            lazyMul[i]=1;
      //  cout << tree[2] << " " << tree[3] << endl;
    for(int i=0;i<q;i++)
    {
        int ch;
        cin >> ch;
        if(ch==1)
        {
           // cout << "hi " << endl;
            int x,y,v;
            cin >> x >> y >> v;
            updateAdd_tree(1,0,n-1,x-1,y-1,v);
        }
        else if(ch==2)
        {
            //cout << "hi " << endl;
            int x,y,v;
            cin >> x >> y >> v;
            updateMul_tree(1,0,n-1,x-1,y-1,v);
        }
        else if(ch==3)
        {
            //cout << "hi " << endl;
            int x,y,v;
            cin >> x >> y >> v;
            updateVal_tree(1,0,n-1,x-1,y-1,v);
        }
        else
        {
            int x,y;
            cin >> x >> y;
            cout << query_tree(1,0,n-1,x-1,y-1)<< endl;
        }
    }
}
