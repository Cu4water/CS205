# CS205 C/ C++ Programming - Lab Project 1
---
**Name**: 杨博乔
**SID**: 12112805

---
## Part 1. Analysis

> The two numbers should be input through the command line arguments. If the two numbers are integers, the program will multiply them in integer format.

To solve this problem, there are 4 steps: 

 - Identifies whether a string is a number, I put this part of code in the "judge.hpp"
 - change a string to a number, I put this part of code in the "huge_int.hpp"
 - calculate the answer of two numbers, traditionally, we can use 2 loops to calculate char by char, but we can do
that in an faster way, FFT. ( But I were wrong, at which the nlogn got bigger than n^2 with its constant, so I cut it)
- For the need to reduce the fractional part, because I finally did not afford to make a big integer factorization, then I cut it, and I Retains the ability to multiply fractions and determine whether the denominator is 0
- ps. 实现了小数，英语，无穷，分数，和不那么科学的科学计数法（允许用户使用各种各样离谱的a.be+c这类输入，若ab缺省则填入1）的处理,尽可能的遵循了google的代码风格
 - print the answer, this is a simple task (It is tooooooo hard to overload "<<", and has been banned by Google)
---
## Part 2. Code

```cpp
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
```
This is the "main.cpp", while "calc.hpp" is to multiply two huge integers. 

---
```cpp
//calc.hpp
#ifndef HUGEINT
#define HUGEINT
#include"huge_int.hpp"
#endif
HugeInt Mul(HugeInt a,HugeInt b)
{
    HugeInt ans;
    ans.is_add_=!(a.is_add_^b.is_add_);
    if(a.is_inf_||b.is_inf_){
        ans.is_inf_=true;
        return ans;
    }
    ans.pow_=a.pow_+b.pow_;
    ans.len_l_=a.len_l_+b.len_l_-1;
    for(int i=0;i<a.len_l_;i++){
        for(int j=0;j<b.len_l_;j++){
            ans.meaning_left_[i+j]+=a.meaning_left_[i]*b.meaning_left_[j];
        }
    }
    for(int j=0;j<ans.len_l_;j++){
        if(ans.meaning_left_[j]>9){
            ans.meaning_left_[j+1]+=ans.meaning_left_[j]/10;
            ans.meaning_left_[j]%=10;
        }
    }
    if(ans.meaning_left_[ans.len_l_]>0){
        ans.len_l_++;
    }
    ans.is_fraction_=false;
    if(a.is_fraction_||b.is_fraction_){
        ans.is_fraction_=true;
        ans.len_r_=a.len_r_+b.len_r_-1;
        for(int i=0;i<a.len_r_;i++){
            for(int j=0;j<b.len_r_;j++){
                ans.meaning_right_[i+j]+=a.meaning_right_[i]*b.meaning_right_[j];
            }
        }
        for(int j=0;j<ans.len_r_;j++){
            if(ans.meaning_right_[j]>9){
                ans.meaning_right_[j+1]+=ans.meaning_right_[j]/10;
                ans.meaning_right_[j]%=10;
            }
        }
        if(ans.meaning_right_[ans.len_r_]>0){
            ans.len_r_++;
        }
    }
    for(;ans.meaning_left_[ans.len_l_-1]==0&&ans.len_l_>1;ans.len_l_--);
    for(;ans.meaning_right_[ans.len_r_-1]==0&&ans.len_r_>1;ans.len_r_--);
    return ans;
}
```
---
```cpp
//huge_int.hpp
//len_l_&meaning_l_ : numerator
//len_r_&meaning_r_ : denominator
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
```
---

```cpp
//number_judge.hpp
//judge whether a string is a number
//kill unmathematically number
// comments under are some demonstration of erroneous data
//Fail(opt): break with an RE, and the opt is the return of code(is not number, /0, ...)
#ifndef CSTDIO
#define CSTDIO
#include<cstdio>
#endif
#ifndef CSTRING
#define CSTRING
#include<cstring>
#endif
#ifndef CSTDLIB
#define CSTDLIB
#include<cstdlib>
#endif
#ifndef STRING
#define STRING
#include<string>
#endif

namespace judge_number{
	std::string kNumWord[34]={"zero","one","two","three","four","five",
	"six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen",
	"fifteen","sixteen","seventeen","eighteen","nineteen","twenty",
	"thirty","forty","fifty","sisty","seventy","eighty","ninety",
	"hundred","thousand","million","billion","inf","insinity"};
	int kNumWordLength=33;
	void Fail(int opt){
		switch (opt){
			case 1:
				printf("The input cannot be interpret as numbers!\n");
				exit(opt);
				break;

			case 2:
				printf("Unacceptable amount of numbers\n");
				exit(opt);
				break;

			case 3:
				printf("/0 WRONG\n");
				exit(opt);
				break;

			default:
				exit(opt);
				break;
		}
		
	}
	bool ScienceNumIsZero(const char *str, const int left, const int right){
		int pos_start=0;
		if(str[left]=='-') pos_start++;
		bool has_num=false;
        for(int i=left+pos_start;i<=right&&(!has_num);++i){
			if(str[i]>'0'&&str[i]<='9') has_num=true;
			if(str[i]=='e') break;
		}
		return !has_num;
	}
	bool StrIsScienceNum(const char *str, const int left, const int right){
		int start_pos=0;
		if(str[left]=='-') start_pos++;
		if(left+start_pos>right) Fail(1);
		int num_of_point=0, num_of_e_add=0;
		for(int i=left+start_pos; i<=right; ++i){
			if(str[i]=='e'){
				if(i!=left&&str[i-1]=='.') Fail(1);                  // 1.e+200
				if(i==right) Fail(1);                                // 123e
				if(str[i+1]!='+'&&str[i+1]!='-') return false;     	 // 123e*456 or "eight"
				if(num_of_e_add!=0) Fail(1);                         // 123e+e+200
				++num_of_e_add;
				num_of_point=0;
				continue;
				// e+200 = 1e+200
			} 
			if(str[i]=='.'){
				if(num_of_point!=0) Fail(1);                         // 1.1.
				++num_of_point;
				continue;
				// .9 = 0.9
			}
			if(str[i]>='0'&&str[i]<='9'){
				continue;
			}
			if(str[i]=='-'){
				if(str[i-1]=='e') continue;
				Fail(1);											//-123-456e+23
			}
		}
		return true;
	}
	bool StrIsFraction(const char *str, const int length){			// only 1 '/' && right part !=0
		int position_of_division=0;
		int num_of_division=0;
		for(int i=0; i<length; ++i)
			if(str[i]=='/'){
				position_of_division=i;
				++num_of_division;
				if(num_of_division==2) Fail(1);						// any statement can not be 2 '/'
			}
		if(num_of_division==0) return false;
		if(ScienceNumIsZero(str,position_of_division+1,length-1)) Fail(3); // 123/0e+123
		if(StrIsScienceNum(str,0,position_of_division) 
		&& StrIsScienceNum(str,position_of_division+1,length-1)) return true;
		return false;
	}
	bool StrIsWord(const char *str, const int length){
		std::string tmp=str;
		for(int i=0;i<=kNumWordLength;i++){
			if(tmp==kNumWord[i]) return true;
		}
		return false;
	}

}

```

---
## Part 3. Result & Verification

**Test Case #1 :**
>  input: ./main 2 3
> output: (2) * (3) = 6


**Test Case #2 :**
>  input: ./main 3.1415926 2
> output: (3.1415926) * (2) = 6.2831852

**Test Case # 3:**
>  input:  ./main 3.1415 2.0e-2
> output: (3.1415) * (2.0e-2) = 6.28300e-2

**Test Case # 4:**
>  input: ./main a 2
> output: The input cannot be interpret as numbers!

**Test Case # 4.5:**
>  input: ./main five 2
> output: (five) * (2) = 1.0e+1

**Test Case # 5:**
>  input:  ./main 1234567890 1234567890
> output: (1234567890) * (1234567890) = 1.524157875019052100e+18

**Test Case # 6:**
>  input: ./main 1.0e+200 1.0e+200
> output: (1.0e+200) * (1.0e+200) = 1.00e+400

**Test Case # 7:**
>  input: ./main 1.0e+200 1.0e-200
> output: (1.0e+200) * (1.0e-200) = 1.00

**Test Case # :8**
>  input: ./main five 1.11111e+200/-2.22223e-15
> output: (five) * (1.11111e+200/-2.22223e-15) = -5.55555e+220 / 222223

**Test Case # :9**
>  input: ./main inf million
> output:(inf) * (million) = infinity

**Test Case # :10**
>  input: ./main 12345 1/0
> output: /0 WRONG, with return 3

**Test Case # :11**
>  input: ./main 123456
> output: Unacceptable amount of numbers
---
## Part 4. Difficulties & Solutions

 - [ ] 乘法没做FFT
 - [ ] 没支持3个以上数字相乘
 - [ ] 科学计数法精度过高问题仍需解决
 - [ ] solution我都写在上面了（逃）



