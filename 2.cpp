#include <stdio.h>

int main()
{
    int N=0;
    scanf("%d", &N);
    if(N<1)
    {
        printf("fail");
    }
    else
    {
        int len=N-(N/3+N/5-N/15)+(N/15);
        printf("%d", len);
    }

    return 0;
}
