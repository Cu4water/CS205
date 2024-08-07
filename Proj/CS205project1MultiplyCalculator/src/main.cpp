#include"calc.hpp"
int main(int argc, char *argv[]){
    if(argc!=3) judge_number::Fail(2);
    HugeInt a=HugeInt(argv[1]);
    HugeInt b=HugeInt(argv[2]);
    HugeInt ans=Mul(a,b);
    printf("(%s) * (%s) = ",argv[1],argv[2]);
    ans.Print();
    printf("\n");
    return 0;
}