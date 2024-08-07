struct stuinfo
{
     char name[20];
     int score[3];
     double ave;
};
void inputstu(stuinfo *stu,int n);
void showstu(stuinfo *stu , int n);
void sortstu(stuinfo *stu , int n);
bool findstu(stuinfo *stu , int n, char *str_name);
bool operator > (const stuinfo &a,const stuinfo &b);
bool operator < (const stuinfo &a,const stuinfo &b);