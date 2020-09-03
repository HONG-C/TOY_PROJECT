/*
프로젝트명:산성비(acid rain)
시작날짜:2020년 9월 3일
*/

#include <iostream>

using namespace std;

void move(int x,int y)
{
  for(int j=1;j<y;j++)
  {
  cout<<"1"<<endl;
  }
  for(int i=0;i<x;i++)
  {
  cout<<"2";
  }
}

int main() 
{ 
  move(3,3);
  std::cout << "Hello World!\n";
}