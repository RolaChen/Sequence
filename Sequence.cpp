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
  string a;
  return a;
}

string Sequence::longestRepeated()
{
  string a;
  return a;
}




