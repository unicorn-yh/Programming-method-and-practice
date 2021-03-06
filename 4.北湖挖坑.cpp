/*Description
十一年前，北湖曾经是一片平整的土地，北湖的施工队打算将其挖出深坑，注水造出人工湖。
为了简化运算，我们假设北湖的地面是一维的，每一块宽度都为1，高度是非负整数，那么可以用一个数组来表达一块地面。
一开始北湖是一片平地，每一块的高度为 h 。下图是 h=3 的情况，用数组表示为[3,3,3,3,3,3,3,3,3,3,3,3]。
施工队根据图纸想将其挖成凹凸不平的形状，如下图所示，数组表示为[0,1,0,2,1,0,1,3,2,1,2,1]。
施工队有一台挖土机，每一天挖土机可以将连续一段区间挖掉一格土。包工头小张想尽快完成任务，请你告诉他将平整的土地挖成图纸所示的情况最少需要多少天？

Input
第一行输入两个整数 n(1 \leq n \leq 100000 ),h(1 \leq h \leq 1000000 ) 。表示北湖的总宽度和初始每一块的高度。
接下来一行 n 个整数 a_i (0 \leq a_i \leq h ) ，表示图纸上每一个位置的高度。

Output
一个整数表示最少几天能将北湖挖好。

Notes
9天挖土的区间为[1,7]，[1,3]，[5,7]，[1,1]，[3,3]，[6,6]，[9,12]，[10,10]，[12,12]。*/

#include <stdio.h>
#define LEN 100005
long long height[LEN];

main(){
    long long ccount,rcount,i,j;
    scanf("%lld %lld",&ccount,&rcount);
    for(i=0;i<ccount;i++){
        long long t;
        scanf("%lld",&t);
        height[i]=rcount-t;     //需要挖去的高度
    }
    long long result=height[0];
    for(i=1;i<ccount;i++){
        if(height[i]>height[i-1])
            result+=(height[i]-height[i-1]); //加时
    }
    printf("%lld\n",result);
}