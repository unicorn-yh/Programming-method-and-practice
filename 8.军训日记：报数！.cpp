/*小军的军训正在如火如荼的进行着，而他仍然继续着他写日记的伟大事业。
报数永远是军训中很无聊的环节，教官为了让报数不那么无聊，以至于有人真的去“抱树”，他规定了一个船新的报数方案，方案如下：
第一个人报数x的后三位，之后第i个人报第i-1人所报数的x倍的后三位，即第i个人需要报x^i(x的i次方)的后三位。
站在队列中第n位的小军很想知道自己需要报多少，这样他就可以放心走神了，请问小军需要报多少呢？
数据范围与提示：0≤x≤999，1≤n≤10^1000
输出格式：行末无空格，文末有回车。 注意，1的后三位是1，而1001的后三位是001。*/

/*n必须用字符数组来读取
• 在n<1000时，算出后n位的和（n<=3）利用for 循环和sum*=x%1000,可以十分轻松的求得答案
• 当n>=1000时，最后的三位数必然会出现重复，所以直接让周期=1000；
• 接上，因为T=1000，所以对于位数>=4的数，只取后三位，并算出它的和sum=10*n[i-2]+n[i-1]+100*n[i-3]，
然后sum+=1000（防止000和001等等的情况出现）, 利用公式sum*=x%1000时，注意n>1000标记一下
• 最后，根据位数和标记来判断是否需要特殊的格式（如%00d，%0d等等），即可轻松AC*/

#include <stdio.h>
#include<math.h>
#include<string.h>
 int main(){
    long long ans=1,i=1,x,num;
    int hundred,ten,one;
    char n[1000000];
    scanf("%d %s",&x,n);
    if(strlen(n)==1)num=n[0]-'0';
    else if(strlen(n)==2)num=(n[0]-'0')*10+(n[1]-'0');
    else if(strlen(n)==3)num=(n[0]-'0')*100+(n[1]-'0')*10+(n[2]-'0');
    else{
        num=(n[strlen(n)-1]-'0')+(n[strlen(n)-2]-'0')*10+(n[strlen(n)-3]-'0')*100;
        num=num+1000;
    }
    for(i=1;i<=num;i++) ans=ans*x%1000;  
    if(ans<1000)printf("%ld\n",ans);
    else{
        hundred=(ans%1000)/100;
        ten=(ans%100)/10;
        one=ans%10;
        printf("%d%d%d\n",hundred,ten,one);
    }
    return 0;
}