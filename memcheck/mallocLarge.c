#include<stdio.h>
#include<stdlib.h>

void g()
{
int *c = malloc(sizeof(char)*512);
}
void f()
{
int *b = malloc(sizeof(double)*1024);
g();
}
int main()
{
int *a =  malloc(sizeof(int)*1024*10);
f();
int i;
int *b[100];
for(i=0;i<100;i++)
{
 b[i] = malloc(sizeof(char)*256);
}

}
