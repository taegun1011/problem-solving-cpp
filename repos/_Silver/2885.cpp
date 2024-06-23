#include <cstdio>
int N,i,j;int main(){scanf("%d",&N);for(;(1<<i)<N;i++);for(;!((1<<j)&N);j++);printf("%d %d",1<<i,i-j);}