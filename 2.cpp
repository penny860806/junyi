#include <stdio.h>

int main()
{
    int N=0;
    scanf("%d", &N);
    if(N<1) //數字應該是從1開始
    {
        printf("fail");
    }
    else
    {
        //扣除掉所有 3 的倍數以及 5 的倍數，但是需要保留留同時是 3 和 5 的倍數的總數字數
        int len=N-(N/3+N/5-N/15)+(N/15);//N-3倍數和5倍數，加回3和5最小公倍數15倍數，再加上15倍數(自數)
        printf("%d", len);
    }

    return 0;
}
