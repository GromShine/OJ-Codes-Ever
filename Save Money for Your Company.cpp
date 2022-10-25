/*
Description
最小矩形覆盖（非计算几何）/找出N条直线相交点的边缘点/ find the dominating points of N lines

You are the director of a mining enterprise, aiming to purchase an mining land for your company. This land has already been criss-crossed with a lot of mining tunnels. In the trading, the vendor demand to restrict the area of purchased land by a rectangle, and the direction of the width of this rectangular is fixed. For the smooth running of mining activities, you have to make this area contains all the intersections of mining tunnels, otherwise the ore may enter the unauthorized (unpurchased) area in the process of transportation or exploitation. Now there is question for you: what is the minimum area of this rectangle? This makes sense because you have to save the cost of purchasing land by shrinking the rectangular area as much as possible.

One can introduce coordinate system into this. Let the x,y coordinate axis parallel to the width and height of this rectangle, and use straight lines to represent mining tunnels. For 
:
https://pic.jitudisk.com/public/2022/10/18/120d1336deefc.png


There are 3 tunnels and 3 intersections. Find a minimum rectangle to contain all the intersections (Notice that the width and height are parallel to the axis):
https://pic.jitudisk.com/public/2022/10/18/e7e7db7efb5d5.png


This is the answer.

In this question, you have to work out an algorithm to calculate the minimum area of rectangle stated above, given the (a,b) pairs of the coefficients in the equations (y=ax+b) representing mining tunnels. If no such rectangle exists, return 0. Your answer is true if relative error or absolute error is smaller than 10^(-4).

Notice that, in this question, a > 0, and a, b are integers.

Sample Input 1

Lines of strings, and each line is the string form of 2 numbers [a,b] (split by space)

2 3
1 2
3 4
Sample Output 1

A floating point number.

 0.00000
Explanation of Sample 1

3 straight lines: y=2x+3,y=x+2,y=3x+4. These 3 lines intersect at the same point: (-1, 1). Therefore, the rectangle does not exist.

Sample Input 2

Lines of strings, and each line is the string form of 2 numbers [a,b] (split by space)

4 1
2 3
3 0
Sample Output 2

A floating point number.

 48.00000
Explanation of Sample 2

3 straight lines: y=4x+1,y=2x+3,y=3x. These 3 lines intersect at the 3 points: (3, 9)(-1, -3)(1, 5). Therefore, the rectangle formed by (3, 9)(-1, -3) is the smallest, and the area is 48.00000.

Constraints of 10 test cases

Case 1: 1<number of tunnels<10

Case 2-4: 100<number of tunnels<1000

Case 5-7: 1000<number of tunnels<10000

Case 8-10: 10000<number of tunnels<100000
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
struct node{
    long double x,y;
};
node vex[100005];

bool cmp1(node a,node b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int main(){
    int n=0;
    while(scanf("%Lf%Lf",&vex[n].x,&vex[n].y)!=EOF)
        n++;

    if(n==1||n==2)
        printf("0.00000\n");
    else{
        sort(vex,vex+n,cmp1);
        long double MIN_X=1e15,MIN_Y=1e15,MAX_X=-1e15,MAX_Y=-1e15;
        int prevl=0;
        int last = -1;
        long double cur_a1,cur_b1,cur_b2,last_a1,last_b1,last_b2;
        for(int i=1;i<n;i++){
            if(i==n-1||vex[prevl].x!=vex[i].x){
                cur_a1 = vex[prevl].x;
                cur_b1 = vex[prevl].y;
                cur_b2 = vex[i-1].y;
                if(last!=-1){
                    MAX_X = max(MAX_X, (cur_b2-last_b1)/(cur_a1-last_a1));
                    MIN_X = min(MIN_X, (cur_b1-last_b2)/(cur_a1-last_a1));
                    MAX_Y = max(MAX_Y,(cur_a1*last_b2-cur_b1*last_a1)/(cur_a1-last_a1));
                    MIN_Y = min(MIN_Y,(cur_a1*last_b1-cur_b2*last_a1)/(cur_a1-last_a1));
                }
                last_a1=cur_a1;
                last_b1=cur_b1;
                last_b2=cur_b2;
                prevl=i;
                last=2;
            }
        }
        printf("%.5Lf\n",(MAX_X-MIN_X)*(MAX_Y-MIN_Y));
    }
}
