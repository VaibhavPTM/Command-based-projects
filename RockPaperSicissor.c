#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int you,computer;
int menu()
{
  int ch;
  printf("\n1. select rock.");
  printf("\n2. select paper.");
  printf("\n3. select scissor.");
  printf("\n4. Exit.");
  printf("\nEnter your choise.");
  scanf("%d",&ch);
  return(ch);
}
void setup()
{
    label:
    computer=rand()%4;
    if(computer==0)
    goto label;

    you=menu();

}
void logic()
{
 switch(you)
 {
   case 1:
	 if(computer==1)
	 {
	 printf("\ngame draw.");
	 printf("\nyou=rock\ncomputer=rock");
	 }
	 else if(computer==2)
	 {
	 printf("\ncomputer won.");
	 printf("\nyou=rock\ncomputer=paper");
	 }
	 else
	 {
	 printf("\nyou won.");
	 printf("\nyou=rock\ncomputer=scissor");
	 }
	 break;
   case 2:
	 if(computer==1)
	 {
	 printf("\nyou won.");
	 printf("\nyou=paper\ncomputer=rock");
	 }
	 else if(computer==2)
	 {
	 printf("\nmatch draw.");
	 printf("\nyou=paper\ncomputer=paper");
	 }
	 else
	 {
	 printf("\ncomputer won.");
	 printf("\nyou=paper\ncomputer=scissor");
	 }
	 break;
   case 3:
	 if(computer==1)
	 {
	 printf("\ncomputer won.");
	 printf("\nyou=scissor\ncomputer=rock");
	 }
	 else if(computer==2)
	 {
	 printf("\ncyou won.");
	 printf("\nyou=scissor\ncomputer=paper");
	 }
	 else
	 {
	 printf("\nmatch draw.");
	 printf("\nyou=scissor\ncomputer=scissor");
	 }
	 break;
   case 4:
	 exit(0);
   default:
	 printf("\nInvalid user input.");
 }
}

int main()
{
while(1)
 {
  system("CLS");
  setup();
  logic();
  getch();
 }
return 0;
}
