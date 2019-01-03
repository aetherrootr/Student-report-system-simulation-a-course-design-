/**
 * @FileName input.h
 * @Function input a int
 */
#ifndef input_h
#define input_h
#include <cstdio>

int input(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return f? -x:x;
}

#endif