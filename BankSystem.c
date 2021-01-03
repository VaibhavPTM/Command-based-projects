#include<stdio.h>
#include<conio.h>
#include<time.h>
int main()
{
  system("CLS");
  float draw,dep,tran;
  char name[30];
  float bal=5000;
  int type;
  int ac1,ac2,ac3;
  int trang=1;
  time_t mytime = time(NULL);

  printf("\n\t\t\t\tBANKING SYSYTEM\n\n");
  printf("\t\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
  printf("\t\t\4\t\t\t\t\t\4\n");
  printf("\t\t\4   WELCOME TO OUR BANKING SYSTEM\t\4\n");
  printf("\t\t\4\t\t\t\t\t\4\n");
  printf("\t\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");

  printf("enter your name:");
  scanf("%[^\n]s",name);
  printf("enter your accont no.:");
  scanf("%d",&type);

  while(trang==1)
  {
    int option;
    printf("\nchoose what you want to do:");
    printf("\n1 - Blance inquiry\n");
    printf("\n2 - deposite\n");
    printf("\n3 - withdraw\n");
    printf("\n4 - transfer\n>>");
    scanf("%d",&option);

    switch(option)
    {
       case 1:
	      printf("\t\t\t*BALANCE INQUIRY*\n");
	      printf("your currunt balance is: %.2fRs\n",bal);
	      break;
       case 2:
	      printf("\t\t\t*DEPOSITE AMMOUNT*\n");
	      printf("how much ruppyes do you want to deposite?:");
	      scanf("%f",&dep);
	      if(dep>0 && dep <=20000)
	      {
		 printf("\nyour %.2fRp deposted in your accont\n",dep);
		 bal+=dep;
	      }
	      else if(dep >20000)
	      {
		 printf("\n you can't deposite that much ammont in one time.\n\n");
	      }
	      else
	      {
		 printf("\ninvalide ammount\n");
	      }
	      break;
       case 3:
	      printf("\t\t\t*WITHDREOW AMMOUNT*\n");
	      printf("how much money do you want to withdraw?:");
	      scanf("%f",&draw);
	      if(draw<=bal && draw<20000)
	      {
		 printf("\nyour %.2fRp withdrawrd from your accont\n",draw);
		 bal-=draw;
	      }
	      else if(draw>20000)
	      {
		 printf("\n you can't withdrawrd that much ammont in one time.\n\n");
	      }
	      else
	      {
		 printf("\nyou don't have enough money\n");
	      }
	      break;
       case 4:
	      printf("\t\t\t*TRANSEFER AMMOUNT*\n");
	      printf("\n\t\tAccont you wnat to trancefer:");
	      scanf("%d",&ac3);
	      printf("\nhow much ammount?:");
	      scanf("%f",&tran);

	      if(bal>=tran)
	      {
		  printf("\nyour %.2fRs successfullly transferd\n\n",tran);
		  bal-=tran;
	      }
	      else
	      {
		  printf("\nyou don't have sufficianat balance.");
	      }
	      break;
       default:
	       printf("invalid transaction\n");
       }
       trang=0;
       while(trang!=1 && trang!=2)
       {
	  printf("\ndo you want to do another transction?\n");
	  printf("1. yes 2. no\n");
	  scanf("%d",&trang);
	  if(trang!=1 && trang!=2)
	  {
	      printf("invalid no. \nchoose between 1 & 2 only\n");
	  }
       }
       }
       //clrscr();
       printf("\n\t\t\t\t__________________\n");
       printf("\n\t\t\t\t V.H BANK LIMITED\n");
       printf("\t\t\t\t__________________\n\n");printf("\t\t\tday| date |  time  | year\n");
       printf("\t\t\t\%s\n",ctime(&mytime));
       printf("\t\t\tyour name :%s\n\n",name);
       printf("\t\t\tyour accont no:%d\n\n",type);
       if(dep>=0 && dep<20000)
       {
       printf("\t\t\t you have deposited %.2fRs\n",dep);
       }
       else
       {
       printf("\n\t\t\tyou have deposited 0Rs");
       }
       if(draw>=0 && draw<20000 && draw<=bal)
       {
       printf("\n\t\t\t you have withdrawed %.2fRs\n",draw);
       }
       else
       {
       printf("\n\t\t\tyou have withdrawed 0Rs");
       }
       if(tran>=0 && tran<20000 && tran<=bal)
       {
       printf("\n\t\t\t you have transefered %.2fRs\n",tran);
       }
       else
       {
       printf("\n\t\t\tnyou have transefered 0Rs");
       }
       printf("\n\t\t\t        Thank you! \n");
       printf("\t\t\t Welcome to V.H Bank System\n");
       printf("\t\t\t   www.v.hbakingsystem.com");
getch();
return(0);
}