/*
프로젝트명:산성비(acid rain)
시작날짜:2020년 9월 3일
*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

char *word[3]=
{
  "main",
  "int",
  "void"
};
  

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



void rain(char *text[]) //call-by-reference 개념 사용
{
  srand(time(NULL));//의사난수 생성(윤성우 책 408페이지)
  int x_pos=rand()%100;
  char *random_word=text[rand()%3];//단어들 중 하나가 랜덤으로 선정
  for(int j=0;j<10;j++)
  {
    move(x_pos,j);
    cout<<random_word<<endl;
    mysleep(100);
    system("clear");//system("cls")가 실행이 안되서 대신 넣음
  }
}




int main() 
{ 
  rain(word);//키포인트:&word[0]=word,word[i]=*(word+i)
}