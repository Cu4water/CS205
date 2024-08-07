void Swap1(int a,int b)
{
    return ;
}
void Swap2(int &a,int &b)
{
    int tmp=a;
    a=b,b=tmp;
}
void Swap3(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}