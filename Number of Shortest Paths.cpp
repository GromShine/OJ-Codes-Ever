/*
最短路的数量，Floyd算法
Description

You are a manager working in a big logistics company, and you have to investigate routes of packages in the city. There are a lot of transfer stations in this city, and packages can only be transfered from one station to another. Now you focus on delivery routes between 2 specific stations. Suppose there are n stations in the city, represented by 0,1,...,n-1, and 0 is the start point, n-1 is the end point. You have to figure out how many paths from 0 to n-1 are the shortest paths at the same time, given the distance of every station pair if one road exists between 2 stations of this pair. Notice that all the roads are two-way, and at most one road exists between 2 stations.

Sample Input

An integer number n representing total number of stations is in the first line (string form).

For the remaining lines, each line is the string form of 3 numbers [a,b,c] (split by space), showing that the distance between a and b is c. Notice that only one of [a,b,c] and [b,a,c] appears, and a≠ b.

3
0 1 4
1 2 5
0 2 9
Sample Output

An integer.

2
Explanation of Sample

There are 2 shortest paths from 0 to 2: 0-1-2 and 0-1, and both of them are of length 9.

Constraints of 10 test cases

Case 1-4: 1<n<50

Case 5-7: 51<n<100

Case 8-10: 101<n<200

For all the cases: 1<number of the remaining lines≤n(n-1)/2
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

#define INF 0x3fffffff
#define N 505
int g[N][N],f[N][N];
int n,m;
int main(){
    cin>>m;
    int i,j,k,a,b,w;
    memset(f,0,sizeof(f));
    for(i = 0;i<m;i++)
        for(j = 0;j<m;j++){
            if(i!=j)
                g[i][j] = INF;
            else
                g[i][j] = 0;
        }
    while(cin>>a>>b>>w){
        g[a][b] = w;
        g[b][a] = w;
        f[a][b]++;
        f[b][a]++;
    }
    for(k = 0;k<m;k++)
        for(i = 0;i<m;i++)
            for(j = 0;j<m;j++){
                if(g[i][j]>g[i][k]+g[k][j]){
                    g[i][j] = g[i][k]+g[k][j];
                    f[i][j] = f[i][k]*f[k][j];
                }else if(g[i][j] == g[i][k]+g[k][j]){
                    f[i][j] += f[i][k]*f[k][j];
                }
            }
    if(g[0][m-1]!=INF)
        cout<<f[0][m-1]<<"\n";
    else
        cout<<"0\n";
	return 0;
}
