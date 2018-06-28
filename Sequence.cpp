#include"Sequence.h"
#include<cstring>
#include<fstream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<cstdlib>

int compare(const void*, const void*);
int coml(const char* ,const char*);

Sequence::Sequence(string filename)
{
  ifstream file(filename.c_str(),ios::in);
  if(!file)
  {
    cerr<<"The file can't be open!"<<endl;
    exit(EXIT_FAILURE);
  }
  string a;
  while(getline(file,a))
    dna+=a;
  leng=dna.length();
}

Sequence::~Sequence()
{

}

int Sequence::length()
{
  return leng;
}

int Sequence::numberOf(char base)
{
  int n=0;
  for(int i=0;i<leng;i++)
    if(dna[i]==base)
      n++;
  return n;
}

string Sequence::longestConsecutive()
{
  bool start=1;
  bool who=1; //who=1 represent a1; who=0 represent a2
  string a1,a2;
  for(int i=0;i<leng;i++)
  {
     if(start)
       a1=dna[i],start=0;
     else
     {
       if(who)
       {
         if(a1[0]==dna[i])
           a1+=dna[i];
         else
         {
           if(a1.length()>a2.length())
             who=0,a2=dna[i];
           else
             a1=dna[i];
         }
       }
       else
       {
         if(a2[0]==dna[i])
           a2+=dna[i];
         else
         {
           if(a2.length()>a1.length())
             who=1,a1=dna[i];
           else
             a2=dna[i];
         }
       }   
     }
  }

  if(a1.length()>a2.length())
    return a1;
  else if(a1.length()<a2.length()) 
    return a2;
  else
  {
    if(who)
      return a1;
    else
      return a2;
   }
}

char a[2000000];
char* s[2000000];
string Sequence::longestRepeated()
{
  for(int i=0;i<leng;i++)
  {
    a[i]=dna[i];
    s[i]=&a[i];
  }
  qsort(s,leng,sizeof(char*),compare);//待排序数组，数组长度，各元素所占空间大小，比较函数
  int longest=0,intext;
  for(int i=0;i<leng-1;i++)
  {
    int n=coml(s[i],s[i+1]);
    if(n>longest)
    longest=n,intext=i;
  } 
  string b;
  for(int i=0;i<longest;i++)
  {
    b+=(*s[intext]);
    s[intext]++;
  }
  return b;
}

int compare(const void* p,const void* q)//返回值<0,则，前一个元素放在前面
{
  return strcmp(*(char **)p, *(char **)q);//比较string的大小，如果前一个小于后一个，返回-1
}


int coml(const char* s1,const char* s2)
{
  int n=0;
  while(s1!=NULL&&s2!=NULL&&(*s1)==(*s2))
  {
    s1++;
    s2++;
    n++;
  }
   return n;
}

