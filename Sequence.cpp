#include"Sequence.h"
#include<cstring>
#include<fstream>

Sequence::Sequence(string filename)
{
  ifstream file(filename.c_str(),ios::in);
  string a;
  while(getline(file,a))
    dna+=a;
}

Sequence::~Sequence()
{

}

int Sequence::length()
{
  int n=dna.length();
  return n;
}

int Sequence::numberOf(char base)
{
  int leng=dna.length();
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
  int leng=dna.length();
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

string Sequence::longestRepeated()
{
  string a;
  return a;
}




