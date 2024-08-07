#ifndef NUMBER_JUDGE
#define NUMBER_JUDGE
#include"number_judge.hpp"
#endif

const int kMaxLength=10010;
std::string kNumWord[34]={"zero","one","two","three","four","five",
	"six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen",
	"fifteen","sixteen","seventeen","eighteen","nineteen","twenty",
	"thirty","forty","fifty","sisty","seventy","eighty","ninety",
	"hundred","thousand","million","billion","inf","infinity"};
const int kNumWordLength=33;
class HugeInt{
    public:
        void Print();
        HugeInt(const char num[]);
        HugeInt();
        void WordToNum(const char *str, const int length, HugeInt& ans);
        void ScienceToNum(const char *str, const int length, HugeInt& ans);
        void FractionToNum(const char *str, const int length, HugeInt& ans);
        int meaning_left_[kMaxLength];
        int meaning_right_[kMaxLength];
        int pow_;
        bool is_fraction_,is_add_,is_inf_;
        int len_l_,len_r_;
};
void HugeInt::Print(){
    if(!is_add_) putchar('-');
    if(is_inf_){
        puts("infinity");
        return;
    }
    pow_+=len_l_-1;
    for(int i=len_l_-1;i>=0;i--){
        if(i==len_l_-2){
            printf(".");
        }
        printf("%d",meaning_left_[i]);
    }
    if(pow_!=0){
        printf("e");
        if(pow_>0){
            printf("+%d",pow_);
        }
        else{
            printf("-%d",-pow_);
        }
    }
    if(is_fraction_){
        printf(" / ");
        for(int i=len_r_-1;i>=0;i--){
            printf("%d",meaning_right_[i]);
        }
    }
}
HugeInt::HugeInt(){
    memset(meaning_left_,0,sizeof(meaning_left_));
    memset(meaning_right_,0,sizeof(meaning_right_));
    pow_=len_l_=len_r_=0;
    is_fraction_=false;
    is_add_=true;
    is_inf_=false;
}

HugeInt::HugeInt(const char *str){
    int len=strlen(str);
    memset(meaning_left_,0,sizeof(meaning_left_));
    memset(meaning_right_,0,sizeof(meaning_right_));
    pow_=len_l_=len_r_=0;
    is_fraction_=false;
    is_add_=true;
    is_inf_=false;
    if(judge_number::StrIsWord(str,len)){
        WordToNum(str,len,*this);
    }
    else if(judge_number::StrIsFraction(str,len)){
        for(int i=0;i<len;i++) if((str[i]!='e'&&str[i]!='-'&&str[i]!='/'&&str[i]!='+'&&str[i]!='.')
        &&(str[i]>57||str[i]<48)) judge_number::Fail(1);
        FractionToNum(str,len,*this);
    }
    else if(judge_number::StrIsScienceNum(str,0,len-1)){
        for(int i=0;i<len;i++) if((str[i]!='e'&&str[i]!='-'&&str[i]!='/'&&str[i]!='+'&&str[i]!='.')
        &&(str[i]>57||str[i]<48)) judge_number::Fail(1);
        ScienceToNum(str,len,*this);
    }
    else judge_number::Fail(1);
}
void HugeInt::WordToNum(const char *str, const int length, HugeInt& ans){
    int ansnum=0;
    std::string tmp=str;
    for(int i=0;i<=20&&!ansnum;i++){
        if(tmp==kNumWord[i]){
            ansnum=i;
        }
     }
     for(int i=21;i<=28&&!ansnum;i++){
        if(tmp==kNumWord[i]){
            ansnum=20+(i-20)*10;
        }
    }
    if(tmp=="thousand") ansnum=1000;
    if(tmp=="million") ansnum=1000000;
    if(tmp=="billion") ansnum=1000000000;
    if(tmp=="inf"||tmp=="infinity"){
        ans.is_inf_=true;
        return;
    }
    ans.len_r_=1;
    ans.meaning_right_[0]=1;
    for(;ansnum;ansnum/=10){
        ans.meaning_left_[ans.len_l_++]=ansnum%10;
    }
}
void HugeInt::ScienceToNum(const char *str, const int length, HugeInt& ans){
    int point_position=-1,e_position=-1;
    if(str[0]=='-'){
        ans.is_add_=false;
        ScienceToNum(str+1,length-1,ans);
        return;
    }
    ans.len_r_=1;
    ans.meaning_right_[0]=1;
    for(int i=0;i<length;i++){
        if(str[i]=='.'){
            point_position=i;
            continue;
        }
        if(str[i]=='e')
        {
            e_position=i;
            break;
        }
    }
    if(e_position==-1){
        int i=length-1,j=0;
        for(;i>=0;i--){
            if(str[i]=='.') continue;
            ans.meaning_left_[j++]=str[i]-'0';
        }
        ans.len_l_=j;
        if(point_position!=-1){
            ans.pow_-=(length-point_position-1);
        }
    }
    else{
        int opt=str[e_position+1]=='+'?1:-1;
        int j=0;
        for(int i=e_position+2;i<length;i++){
            ans.pow_=ans.pow_*10+str[i]-'0';
        }
        for(int i=e_position-1;i>=0;i--){
            if(str[i]=='.') continue;
            ans.meaning_left_[j++]=str[i]-'0';
        }
        ans.pow_*=opt;
        ans.len_l_=j;
        if(point_position!=-1){
            ans.pow_-=(e_position-point_position-1);
        }
    }
    return;
}
void HugeInt::FractionToNum(const char *str, const int length, HugeInt& ans){
    HugeInt a;
    HugeInt b;
    int frac_position;
    for(frac_position=0;frac_position<length;frac_position++){
        if(str[frac_position]=='/') break;
    }
    ScienceToNum(str,frac_position,a);
    ScienceToNum(str+frac_position+1,length-frac_position-1,b);
    ans.is_fraction_=true;
    ans.is_add_=!(a.is_add_^b.is_add_);
    ans.pow_=a.pow_-b.pow_;
    ans.len_l_=a.len_l_;
    ans.len_r_=b.len_l_;
    for(int i=0;i<ans.len_l_;i++){
        ans.meaning_left_[i]=a.meaning_left_[i];
    }
    for(int i=0;i<ans.len_r_;i++){
        ans.meaning_right_[i]=b.meaning_left_[i];
    }
    return ;
}