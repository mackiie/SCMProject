#include<iostream .h>
#include<fstream .h>
#include<process .h>
#include<string .h>
#include<stdlib .h>
#include<stdio .h>
#include<ctype .h>
#include<conio .h>
#include<dos .h>
 
//===========================================================
//  THIS CLASS CONTAINS FUNCTIONS RELATED TO DRAW BOX ETC.
//===========================================================
 
class shape
{
   public :
	    void line_hor(int, int, int, char);
	    void line_ver(int, int, int, char);
	    void box(int,int,int,int,char);
};
 
//===========================================================
//     THIS CLASS CONTROL ALL THE FUNCTIONS IN THE MENU
//===========================================================
 
class control
{
  public :
	   void main_menu(void);
	   void help(void);
  private:
	   void edit_menu(void);
};
 
//===========================================================
// THIS CLASS CONTAINS FUNCTIONS RELATED TO INITIAL DEPOSIT
//===========================================================
 
class initial
{
   public :
	    void add_to_file(int,char t_name[30],char t_address[60],float);
	    void display_list(void);
	    void delete_account(int);
	    void update_balance(int,float);
	    void modify(void);
	    int last_accno(void);
	    int found_account(int);
	    char *return_name(int);
	    char *return_address(int);
	    float give_balance(int);
	    int recordno(int);
	    void display(int);
   private:
	    void modify_account(int,char t_name[30],char t_address[60]);
	    void box_for_list(void);
 
	    int accno;
	    char name[30],address[60];
	    float balance;
};
//===========================================================
//   THIS CLASS CONTAINS FUNCTIONS RELATED TO TRANSACTIONS
//===========================================================
 
class account
{
  public :
	   void new_account(void);
	   void close_account(void);
	   void display_account(void);
	   void transaction(void);
	   void clear(int,int);
  private :
	   void add_to_file(int,int,int,int,char,char t_type[10],float,float,float);
	   void delete_account(int);
	   int no_of_days(int,int,int,int,int,int);
	   float calculate_interest(int,float);
	   void display(int);
	   void box_for_display(int);
	   int accno;
	   char type[10];  //Cheque or Cash
	   int dd,mm,yy;  //Date
	   char tran ;  // Deposit or withdrawl
	   float interest,amount,balance;
};
 
//===========================================================
//     FUNCTION TO DRAW HORIZONTAL LINE
//===========================================================
 
void shape::line_hor(int column1,int column2,int row,char c)
{
 for(column1;column1< =column2;column1++)
    {
    gotoxy(column1,row);
    cout<<c;
    }
}
 
//===========================================================
//             FUNCTION TO DRAW VERTICAL LINE
//===========================================================
 
void shape::line_ver(int row1,int row2,int column,char c)
{
for(row1;row1<=row2;row1++)
   {
    gotoxy(column,row1);
    cout<<c;
   }
}
 
//============================================================
//              FUNCTION TO DRAW BOX LINE
//============================================================
 
void shape::box(int column1,int row1,int column2,int row2,char c)
{
char ch=218;
char c1,c2,c3,c4;
char l1=196,l2=179;
if(c==ch)
{
c1=218;
c2=191;
c3=192;
c4=217;
l1=196;
l2=179;
}
else
{
c1=c;
c2=c;
c3=c;
c4=c;
l1=c;
l2=c;
}
gotoxy(column1,row1);
cout<<c1;
gotoxy(column2,row1);
cout<<c2;
gotoxy(column1,row2);
cout<<c3;
gotoxy(column2,row2);
cout<<c4;
column1++;
column2--;
line_hor(column1,column2,row1,l1);
line_hor(column1,column2,row2,l1);
column1--;
column2++;
row1++;
row2--;
line_ver(row1,row2,column1,l2);
line_ver(row1,row2,column2,l2);
}
//============================================================
//  FUNCTION TO DISPLAY MAIN MENU AND CALL OTHER FUNCTIONS
//============================================================
 
void control::main_menu(void)
{
char ch;
while (1)
      {
	clrscr();
	shape s;
	s.box(10,5,71,21,219);
	s.box(9,4,72,22,218);
	textcolor(LIGHTBLUE+BLINK);
	textbackground(BLACK);
	gotoxy(32,7);
	cprintf(" B A N K I N G ");
	gotoxy(35,9);
	cprintf(" OPTIONS ");
	textcolor(LIGHTBLUE);
	textbackground(BLACK);
	gotoxy(30,11);
	cout<<"1: SEE ACCOUNT ";
	gotoxy(30,12);
	cout<<"2: LIST OF ACCOUNTS ";
	gotoxy(30,13);
	cout<<"3: TRANSACTIONS ";
	gotoxy(30,14);
	cout<<"4: OPEN NEW ACCOUNT ";
	gotoxy(30,15);
	cout<<"5: EDIT ACCOUNTS ";
	gotoxy(30,16);
	cout<<"6: HELP ";
	gotoxy(30,17);
	cout<<"0: QUIT ";
	gotoxy(30,19);
	cout<<" ENTER YOUR CHOICE:";
	ch=getche();
	if(ch==27)
	  break;
	else
	    if(ch=='1')
	      {
	      account a;
	      a.display_account();
	      }
	else
	    if(ch=='2')
	    {
	    initial ini;
	    ini.display_list();
	    }
	else
	    if(ch=='3')
	    {
	    account a ;
	    a.transaction();
	    }
	else
	    if(ch=='4')
	    {
	    account a;
	    a.new_account();
	    }
	else
	    if(ch=='5')
	    edit_menu();
	else
	    if(ch=='6')
	    help();
	else
	    if(ch=='0')
	    break;
      }
	for(int i=25;i>=1;i--)
	{
	delay(20);
	gotoxy(1,i); clreol();
	}
}

