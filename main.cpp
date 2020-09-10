/*
프로젝트명:산성비(acid rain)
시작날짜:2020년 9월 3일
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

char word[100]="abcdefghijklmnopqrstuvwxyz";

using namespace std;

/*
sleep함수 정의
<ctime>헤더파일 사용, clock()함수와 clock_t자료형 사용
*/

void mysleep(int sec)
{
  clock_t start_clk=clock();
  sec--;
  while(1)
  {
    if((clock()-start_clk)/1000>sec)
    {
      break;
    }
  }
}


/*
지정한 x,y값으로 좌표를 이동시키는 함수
*/

void move(int x,int y)
{
  for(int j=1;j<y;j++)
  {
  cout<<" "<<endl;
  }
  for(int i=0;i<x;i++)
  {
  cout<<" ";
  }
}



void rain(char *text) //call-by-reference 개념 사용
{
  for(int j=0;j<10;j++)
  {
    move(0,j);
    cout<< *text<<endl;
    mysleep(100);
  }
}

int main() 
{ 
  rain(word);//키포인트:&word[0]=word,word[i]=*(word+i)
  
  
}