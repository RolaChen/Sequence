#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<iostream>
#include<string>
using namespace std;

class Sequence
{
  public:
    Sequence(string);
    ~Sequence();
    int length();
    int numberOf(char);
    string longestConsecutive();
    string longestRepeated();
  private:
    string dna;
    int leng;
};
#endif
