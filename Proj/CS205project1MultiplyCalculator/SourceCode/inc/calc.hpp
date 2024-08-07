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