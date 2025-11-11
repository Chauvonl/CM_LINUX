#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "strutils.h"

// ĐẠO ngược chuỗi
char* str_reverse(char str[])
{
    int left = 0, right = strlen(str) - 1;
    while (left < right)
    {
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        ++left, --right;
    }
    return str;
    
}

// Loại bỏ khoảng trắng
void str_trim(char *str)
{
    int start = 0, end = strlen(str) - 1;

    // Bỏ khoảng trắng đầu
    while (isspace((unsigned char)str[start]))
    {
        start++;
    }
    
    // Bỏ khoảng trắng cuối
    while (end >= start && isspace((unsigned char)str[end]))
    {
        end--;
    }

    // Dịch chuỗi về đầu
    int i, j = 0;
    for( i = start; i <= end; i++)
    {
        str[j++] = str[i];
    }
    str[j] = '\0';
    
}

// Chuyển chuỗi sang số nguyên
int str_to_int(char str[])
{
    int res = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        res = res * 10 + str[i] - '0';
    }
    return res;
}

