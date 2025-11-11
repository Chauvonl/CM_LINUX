#include<stdio.h>
#include"strutils.h"

int main()
{
    char str1[] = "     Hello World!     ";
    char str2[] = "OpenAi";
    char str3[] = "1234";

    printf("Chuỗi bao đầu: %s\n",str1);
    str_trim(str1);
    printf("Chuỗi sau khi trim: %s\n",str1);

    printf("Chuỗi trước khi đảo: %s\n",str2);
    //str_reverse(str2);
    printf("Chuỗi sau khi đảo: %s\n",str_reverse(str2));

    printf("Chuỗi bao đầu: %s\n",str3);
    int result = str_to_int(str3);
    printf("Chuỗi sau khi chuyển sang int: %d\n", result);
    return 0;
}
