/*
프로젝트명:산성비(acid rain)
시작날짜:2020년 9월 3일
*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <thread>

using namespace std;

//함수의 선언부분
void mysleep(int sec);
void move(int x,int y);
void rain(char *text[],int i);
int check_typing(void);
void test_thread(void)
{
  cout<<"this is thread";
}
void test_thread_2(void)
{
  cout<<"this is  also thread";
}


char *raining_word="hello world";//상수형태의 문자열이라 오류가 발생하는듯..수정필요

char *word[3]=
{
  "main",
  "int",
  "void"
};
  



//함수의 정의 부분

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

/*
단어가 비처럼 내리는 것을 구현한 rain 함수 구현
call-by-reference 개념 사용,i는 정답입력 확인을 위한 인자
*/

void rain(char *text[],int i=0)
{
  srand(time(NULL));//의사난수 생성(윤성우 책 408페이지)
  int x_pos=rand()%30;
  char *random_word=text[rand()%3];//단어들 중 하나가 랜덤으로 선정
  raining_word=random_word;
  for(int j=0;j<10;j++)
  {
    move(x_pos,j);
    cout<<random_word<<endl;
    if(i==1)
    {
        break;       
    }
    else
    mysleep(100);
    system("clear");//system("cls")가 실행이 안되서 대신 넣음
  }
}

 
int check_typing(void)
{
  cout<<"raining word: "<<raining_word<<endl;
  cout<<"type the word"<<endl;
  char typed_word[20];//이 부분을 char *typed_word로 선언하면 상수형태 문자열이라 에러남
  cin>>typed_word;
  cout<<typed_word<<endl;
  if(*raining_word==*typed_word)//이 부분 복습!
  {
    cout<<"correct!"<<endl;
    return 1;
  }
  else
  {
    cout<<"wrong!"<<endl;
    return 0;
  }
}




int main() 
{ 
  /*
  raining_word=word[0];
  int check_num=check_typing();
  rain(word,check_num);//키포인트:&word[0]=word,word[i]=*(word+i)
  */
  thread t1(test_thread);
  thread t2(test_thread_2);
  
  t1.join();
  t2.join();
}