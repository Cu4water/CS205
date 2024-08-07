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
	// bool StrIsLegalNum(const char *str)
	// {
	// 	int length=strlen(str);
	// 	if(StrIsFraction(str,length)) return true;
	// 	return false;
	// }

}
