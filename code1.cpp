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
//=============================================================
//   FUNCTION TO DISPLAY EDIT MENU AND CALL OTHER FUNCTION
//=============================================================
 
void control::edit_menu(void)
{
char ch;
while (1)
      {
	clrscr();
	shape s;
	s.box(10,5,71,21,219);
	s.box(9,4,72,22,218);
	textcolor(LIGHTBLUE);
	textbackground(BLACK);
	gotoxy(34,10);
	cprintf(" EDIT MENU");
	textcolor(LIGHTBLUE);
	textbackground(BLACK);
	gotoxy(31,12);
	cout< <"1: MODIFY ACCOUNT :";
	gotoxy(31,13);
	cout<<"2: CLOSE ACCOUNT ";
	gotoxy(31,14);
	cout<<"0: QUIT ";
	gotoxy(31,16);
	cout<<"ENTER YOUR CHOICE: ";
	ch=getche();
	if(ch==27)
	  break;
	else
	if(ch=='1')
	{
	initial ini;
	ini.modify();
	break;
	}
	else
	if(ch=='2')
	{
	account a;
	a.close_account();
	break;
	}
	else
	if(ch=='0')
	break;
      }
}
 
//=============================================================
//           FUNCTION TO DISPLAY HELP ABOUT PROJECT
//=============================================================
 
void control::help(void)
{
clrscr();
shape s;
s.box(2,1,79,25,218);
s.box(25,2,54,4,219);
textcolor(LIGHTBLUE+BLINK);
gotoxy(27,3);
cprintf("WELCOME TO THE PROJECT BANKING ");
textcolor(LIGHTBLUE);
delay(10);
gotoxy(10,6);
cout<<"IN THIS PROJECT YOU CAN KEEP RECORD OF DAILY BANKING ";
delay(10);
gotoxy(10,7);
cout<<" TRANSACTIONS.		";
delay(10);
gotoxy(10,9);
cout<<" THIS PROGRAMME IS CAPABLE OF HOLDING ANY NO. OF ACCOUNTS ";
delay(10);
gotoxy(10,11);
cout<<" # IN FIRST OPTION YOU CAN SEE ACCOUNT OF A PARTICULAR ";
delay(10);
gotoxy(10,12);
cout<<" PERSON BY GIVING SIMPLY ACCOUNT NO. OF THAT PERSON";
delay(10);
gotoxy(10,14);
cout<<"# IN SECOND OPTION YOUN CAN SEE THE LIST OF ALL ACCOUNTS. ";
delay(10);
gotoxy(10,16);
cout<<"# THROUGH THIRD OPTION YOU CAN DO BANKING TRANSACTIONS ";
delay(10);
gotoxy(10,17);
cout<<" ( DEPOSIT / WITHDRAW )";
delay(10);
gotoxy(10,19);
cout<<"# IN FOURTH OPTION YOU CAN OPEN NEW ACCOUNT. ";
delay(10);
gotoxy(10,20);
cout<<" NOTE: OPENING AMOUNT SHOULD NOT LESS THAN Rs.500/-. ";
delay(10);
gotoxy(10,22);
cout<<"# IN THE FIFTH OPTION YOU CAN MODIFY OR DELETE ANY ACCOUNT. ";
delay(10);
gotoxy(10,24);
cout<<"# AND LAST OPTION IS QUIT (EXIT TO DOS).";
delay(10);
textcolor(LIGHTBLUE+BLINK); textbackground(BLACK);
gotoxy(26,25);
cprintf(" PRESS ANY KEY TO CONTINUE ");
textcolor(LIGHTBLUE);textbackground(BLACK);
gotoxy(25,2);
getch();
for(int i=25;i>=1;i--)
   {
   delay(20);
   gotoxy(1,i);clreol();
   }
}
//============================================================
//  THIS FUNCTION DISPLAY RECORD FROM THE FILE BANKING.DAT
//============================================================
 
void account::display_account(void)
{
   clrscr();
   char t_acc[10];
   int t,t_accno;
   gotoxy(71,1);
   cout<<"&lt;0>=EXIT";
   gotoxy(5,5);
   cout< <"ENTER THE ACCOUNT NO.";
   gets(t_acc);
   t=atoi(t_acc);
   t_accno=t;
   if(t_accno==0)
       return;
   clrscr();
   initial ini;
   if(!ini.found_account(t_accno))
   {
     gotoxy(5,5);
     cout<<"\7ACCOUNT NOT FOUND";
     getch();
     return;
   }
   box_for_display(t_accno);
   int row=7,flag;
   fstream file;
   file.open("BANKING.DAT",ios::in);
   while(file.read((char*)this,sizeof(account)))
      {
         if(accno==t_accno)
           {
             flag=0;
             delay(10);
             gotoxy(4,row);
             cout<<dd  <<"/"<<mm  <<"/" <<yy;
             gotoxy(16,row);
             cout<<type;
             if(tran=='D')
               gotoxy(30,row);
             else
               gotoxy(42,row);
             cout<<amount;
             gotoxy(56,row);
             cout<<interest;
             gotoxy(66,row);
             cout<<balance;
             row++;
             if(row==23)
             {
               flag=1;
               row=7;
               gotoxy(4,24);
               cout<<" PRESS ANY KEY TO CONTINUE.... ";
               getch();
               clrscr();
               box_for_display(t_accno);
             }
           }
      }
      file.close();
      if(!flag)
      {
        gotoxy(4,24);
        cout<<"PRESS ANY KEY TO CONTINUE.....";
        getch();
      }
}
//=========================================================
//  THIS FUNCTION RETURNS THE DIFFERENCE BETWEEN 2 DATES
//=========================================================

int account::no_of_days(int d1,int m1,int y1,int d2,int m2,int y2)
{
   static int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
   int days=0;
   while(d1!=d2 || m1!=m2 || y1!=y2)
        {
          days++;
          d1++;
          if(d1>month[m1-1])
            {
              d1=1;
              m1++;
            }
          if(m1>12)
            {
              m1=1;
              y1++;
            }
        }
   return days;
}

//=============================================================
//            THIS FUNCTION CALCULATES INTEREST
//=============================================================

float account::calculate_interest(int t_accno,float t_balance)
{
   fstream file;
   file.open("BANKING.DAT",ios::in);
   file.seekg(0,ios::beg);
   int d1,m1,y1,days;
   while(file.read((char *)this, sizeof(account)))
        {
           if(accno==t_accno)
             {
               d1=dd;
               m1=mm;
               y1=yy;
               break;
             }
        }
   int d2,m2,y2;
   struct date d;
   getdate(&d);
   d2=d.da_day;
   m2=d.da_mon;
   y2=d.da_year;
   float t_interest=0.0;
   if((y2<y1 )||(y2==y1 && m2<m1)||(y2==y1&&m2==m1&&d2<d1))
       return t_interest;
   days=no_of_days(d1,m1,y1,d2,m2,y2);
   int months=0;
   if(days>=30)
     {
       months=days/30;
       t_interest=((t_balance*2)/100*months);
     }
   file.close();
   return t_interest;
}
//============================================================
//    THIS FUNCTION MAKES TRANSACTIONS (DEPOSIT/WITHDRAW)
//============================================================
 
void account::transaction(void)
{
  clrscr();
  char t_acc[10];
  int t,t_accno,valid;
  gotoxy(71,1);
  cout< <"&lt;0>=EXIT";
  gotoxy(5,5);
  cout< <"ENTER THE ACCOUNT NO.";
  gets(t_acc);
  t=atoi(t_acc);
  t_accno=t;
  if(t_accno==0)
     return;
  clrscr();
  initial ini;
  if(!ini.found_account(t_accno))
    {
      gotoxy(5,5);
      cout<<"\7ACCOUNT NOT FOUND";
      getch();
      return;
    }
  shape s;
  s.box(2,2,79,24,218);
  s.line_hor(3,78,4,196);
  s.line_hor(3,78,22,196);
  gotoxy(71,1);
  cout<<"&lt;0>=EXIT";
  textbackground(BLACK);
  gotoxy(3,3);
  for(int i=1;i< =76;i++) cprintf(" ");
  textbackground(BLACK);
  textcolor(LIGHTBLUE+BLINK); textbackground(BLACK);
  gotoxy(29,3);
  cprintf("TRANSACTION IN ACCOUNT");
  textcolor(LIGHTBLUE); textbackground(BLACK);
  int d1,m1,y1;
  struct date d;
  getdate(&d);
  d1=d.da_day;
  m1=d.da_mon;
  y1=d.da_year;
  gotoxy(5,6);
  cout<<"DATE: "<<d1<<"/"<<m1<<"/"<<y1;
  gotoxy(5,8);
  cout<<"ACCOUNT NO. #"<<t_accno;
  char t_name[30];
  char t_address[60];
  float t_balance;
  strcpy(t_name,ini.return_name(t_accno));
  strcpy(t_address,ini.return_address(t_accno));
  t_balance=ini.give_balance(t_accno);
  s.box(25,10,75,13,218);
  gotoxy(27,11);
  cout<<"NAME  :"<<t_name;
  gotoxy(27,12);
  cout<<"ADDRESS:  "<<t_address;
  gotoxy(5,15);
  cout<<"LAST BALANCE  : RS."<<t_balance;
  char t_tran,t_type[10],tm[10];
  float t_amount,t_amt;
  do
  {
     clear(5,18);
     valid=1;
     gotoxy(5,18);
     cout<<"DEPOSIT OR WITHDRAW (D/W) :";
     t_tran=getche();
     if(t_tran=='0')
         return;
     t_tran=toupper(t_tran);
  }
  while(t_tran!='D' && t_tran!='W');
  do
  {
      clear(5,19);
      clear(5,23);
      gotoxy(5,23);
      cout<<"ENTER TRANSACTIONS BY CASH OR CHEQUE";
      valid=1;
      gotoxy(5,19);
      cout<<"(CASH/CHEQUE):";
      gets(t_type);
      strupr(t_type);
      if(t_type[0]=='0')
          return;
      if(strcmp(t_type,"CASH") && strcmp(t_type,"CHEQUE"))
      {
        valid=0;
        gotoxy(5,23);
        cprintf("\7ENTER CORRECTLY               ");
        getch();
      }
  }while(!valid);
  do
  {
    clear(5,21);
    clear(5,23);
    gotoxy(5,23);
    cout<<"ENTER AMOUNT FOR TRANSACTION";
    valid=1;
    gotoxy(5,21);
    cout<<"AMOUNT :RS.";
    gets(tm);
    t_amt=atof(tm);
    t_amount=t_amt;
    if(tm[0]=='0')
         return;
    if((t_tran=='W' && t_amount>t_balance)||(t_amount&lt;1))
    {
       valid=0;
       gotoxy(5,23);
       cprintf("\7INVALID DATA ENTERED             ");
       getch();
    }
  }while(!valid);
  char ch;
  clear(5,23);
  do
  {
     clear(40,20);
     valid=1;
     gotoxy(40,20);
     cout< <"SAVE TRANSACTION (Y/N):  ";
     ch=getche();
     if(ch=='0')
         return;
     ch=toupper(ch);
  }while(ch!='N' && ch!='Y');
  if(ch=='N')
      return;
  float t_interest;
  t_interest=calculate_interest(t_accno,t_balance);
  if(t_tran=='D')
    t_balance=t_balance+t_amount+t_interest;
  else
    t_balance=(t_balance-t_amount)+t_interest;
  ini.update_balance(t_accno,t_balance);
  add_to_file(t_accno,d1,m1,y1,t_tran,t_type,t_interest,t_amount,t_balance);
}

//============================================================
//      THIS FUNCTION CLOSE THE ACCOUNT (DELETE ACCOUNT)
//============================================================
void account::close_account(void)
{
   clrscr();
   char t_acc[10];
   int t,t_accno;
   gotoxy(71,1);
   cout<<"&lt;0>=EXIT";
   gotoxy(5,5);
   cout< <"ENTER THE ACCOUNT NO.";
   gets(t_acc);
   t=atoi(t_acc);
   t_accno=t;
   if(t_accno==0)
      return;
   clrscr();
   initial ini;
   if(!ini.found_account(t_accno))
     {
       gotoxy(5,5);
       cout<<"\7ACCOUNT NOT FOUND";
       getch();
       return;
     }
   shape s;
   s.box(2,2,79,24,218);
   s.line_hor(3,78,4,196);
   s.line_hor(3,78,22,196);
   gotoxy(71,1);
   cout<<"&lt;0>=EXIT";
   textbackground(BLACK);
   gotoxy(3,3);
   for(int i=1;i< =76;i++) cprintf("  ");
   textbackground(BLACK);
   textcolor(GREEN+BLINK); textbackground(BLACK);
   gotoxy(30,3);
   cprintf("CLOSE ACCOUNT SCREEN");
   textcolor(LIGHTBLUE); textbackground(BLACK);
   int d1,m1,y1;
   struct date d;
   getdate(&d);
   d1=d.da_day;
   m1=d.da_mon;
   y1=d.da_year;
   gotoxy(62,5);
   cout<<"DATE:  "<<d1<<"/"<<m1<<"/"<<y1;
   char ch;
   ini.display(t_accno);
   do
   {
     clear(5,15);
     gotoxy(5,15);
     cout<<"CLOSE THIS ACCOUNT(Y/N):";
     ch=getche();
     if(ch=='0')
       return;
     ch=toupper(ch);
   }while(ch!='N' && ch!='Y');
   if(ch=='N')
      return;
   ini.delete_account(t_accno);
   delete_account(t_accno);
   gotoxy(5,20);
   cout<<"\7RECORD DELETED";
   gotoxy(5,23);
   cout<<"PRESS ANY KEY TO CONTINUE...";
   getch();
}
 
//===============================================================
//THIS IS MAIN FUNCTION CALLING HELP AND MAIN MENU
//FUNCTIONS
//===============================================================
 
void main(void)
{
  control c;
  c.help();
  c.main_menu();
}

 

//============================================================
//THIS FUNCTION GIVE THE DATA TO MODIFY THE RECORD IN THE
//FILE INITIAL.DAT
//============================================================
 
void initial::modify(void)
{
   clrscr();
   char t_acc[10];
   int t, t_accno;
   gotoxy(71,1);
   cout<<"&lt;0>=EXIT";
   gotoxy(5,5);
   cout< <"ENTER THE ACCOUNT NO.";
   gets(t_acc);
   t=atoi(t_acc);
   t_accno=t;
   if(t_accno==0)
       return;
   clrscr();
   if(!found_account(t_accno))
   {
     gotoxy(5,5);
     cout<<"\7ACCOUNT NOT FOUND";
     getch();
     return;
   }
   shape s;
   s.box(2,2,79,24,218);
   s.line_hor(3,78,4,196);
   s.line_hor(3,78,22,196);
   gotoxy(71,1);
   cout<<"&lt;0>=EXIT";
   textbackground(BLACK);
   gotoxy(3,3);
   for(int i=1;i< =76;i++) cprintf("  ");
   textbackground(BLACK);
   textcolor(LIGHTBLUE+BLINK); textbackground(BLACK);
   gotoxy(30,3);
   cprintf("MODIFY ACCOUNT SCREEN");
   textcolor(LIGHTBLUE); textbackground(BLACK);
   int d1,m1,y1;
   struct date d;
   getdate(&d);
   d1=d.da_day;
   m1=d.da_mon;
   y1=d.da_year;
   gotoxy(62,5);
   cout<<"DATE:"<<d1<<"/"<<m1<<"/"<<y1;
   char ch;
   display(t_accno);
   account a;
   do
   {
     a.clear(5,13);
     gotoxy(5,13);
     cout<<"MODIFY THIS ACCOUNT(Y/N):";
     ch=getche();
     if(ch=='0')
           return;
     ch=toupper(ch);
   }while(ch!='N' && ch!='Y');
   if(ch=='N')
      return;
   int modified=0,valid;
   char t_name[30], t_address[60];
   gotoxy(5,15);
   cout<<"NAME   :";
   gotoxy(5,16);
   cout<<"ADDRESS  :";
   do
   {
     a.clear(15,15);
     a.clear(5,23);
     gotoxy(5,23);
     cout<<"ENTER NAME OR PRESS <ENTER> FOR NO CHANGE";
     valid=1;
     gotoxy(15,15);
     gets(t_name);
     strupr(t_name);
     if(t_name[0]=='0')
          return;
     if(strlen(t_name)>25)
     {
        valid=0;
        gotoxy(5,23);
        cprintf("\7NAME SHOULD NOT GREATER THAN 25");
        getch();
     }
   }while(!valid);
   if(strlen(t_name)>0)
       modified=1;
   do
   {
      a.clear(15,16);
      a.clear(5,23);
      gotoxy(5,23);
      cout< <"ENTER ADDRESS OR PRESS <ENTER> FOR NO CHANGE";
      valid=1;
      gotoxy(15,16);
      gets(t_address);
      strupr(t_address);
      if(t_address[0]=='0')
           return;
      if(strlen(t_address)>55)
      {
        valid=0;
        gotoxy(5,23);
        cprintf("\7SHOULD NOT BLANK OR GREATER THAN 55");
        getch();
      }
   }while(!valid);
   if(strlen(t_address)>0)
      modified=1;
   if(!modified)
       return;
   a.clear(5,23);
   do
   {
     a.clear(5,18);
     gotoxy(5,18);
     cout< <"DO YOU WANT TO SAVE CHANGES  (Y/N):";
     ch=getche();
     if(ch=='0')
        return;
     ch=toupper(ch);
   }while(ch!='N' && ch!='Y');
   if(ch=='N')
     return;
   modify_account(t_accno,t_name,t_address);
   gotoxy(5,21);
   cout<<"\7RECORD MODIFIED";
   gotoxy(5,23);
   cout<<"PRESS ANY KEY TO CONTINUE...";
   getch();
}
//=============================================================
//       THIS FUNCTION CLEAR THE GIVEN ROW AND COLUMNS
//=============================================================
 
void account::clear(int col, int row)
{
   for(int i=col;i<=78;i++)
      {
        gotoxy(i,row);
        cout<<"       ";
      }
}
 
//============================================================
//THIS FUNCTION ADDS THE GIVEN DATA INTO THE FILE
//BANKING.DAT
//============================================================
void account::add_to_file(int t_accno,int d1,int m1, int y1,
                         char t_tran,char t_type[10],float t_interest,
                         float t_amount, float t_balance)
{
   fstream file;
   file.open("BANKING.DAT",ios::app);
   accno=t_accno;
   dd=d1;
   mm=m1;
   yy=y1;
   tran=t_tran;
   strcpy(type,t_type);
   interest=t_interest;
   amount=t_amount;
   balance=t_balance;
   file.write((char*)this,sizeof(account));
   file.close();
}

//===============================================================
//THIS FUNCTION DELETES THE RECORD FOR GIVEN ACCOUNT NO.
//FROM FILE BANKING.DAT
//===============================================================
 
void account::delete_account(int t_accno)
{
    fstream file;
    file.open("BANKING.DAT", ios::in);
    fstream temp;
    temp.open("temp.dat",ios::out);
    file.seekg(0,ios::beg);
    while(!file.eof() )
    {
      file.read((char *) this,sizeof(account));
      if(file.eof())
          break;
      if(accno!= t_accno)
           temp.write((char *) this,sizeof(account));
    }
    file.close();
    temp.close();
    file.open("BANKING.DAT",ios::out);
    temp.open("temp.dat",ios::in);
    temp.seekg(0,ios::beg);
    while(!temp.eof())
    {
      temp.read((char *)this,sizeof(account));
      if(temp.eof())
          break;
      file.write((char *) this, sizeof(account));
    }
    file.close();
    temp.close();
}
//================================================================
//THIS FUNCTION ACCEPTS THE DATA TO ADD RECORDS IN THE
//FILE BANKING.DAT
//================================================================

void account::new_account(void)
{
   char ch;
   int i,valid;
   clrscr();
   initial ini;
   shape s;
   s.box(2,2,79,24,218);
   s.line_hor(3,78,4,196);
   s.line_hor(3,78,22,196);
   gotoxy(71,1);
   cout<<"&lt;0>=EXIT";
   textbackground(BLACK);
   gotoxy(3,3);
   for(i=1;i< =76;i++)
   cprintf("  ");
   textbackground(BLACK);
   textcolor(LIGHTBLUE+BLINK); textbackground(BLACK);
   gotoxy(32,3);
   cprintf("OPEN NEW ACCOUNT");
   textcolor(LIGHTBLUE);
   textbackground(BLACK);
   int d1,m1,y1;
   struct date d;
   getdate(&d);
   d1=d.da_day;
   m1=d.da_mon;
   y1=d.da_year;
   int t_accno;
   t_accno=ini.last_accno();
   t_accno++;
   if(t_accno==1)
   {
      ini.add_to_file(t_accno,"abc","xyz",1.1);
      ini.delete_account(t_accno);
      add_to_file(t_accno,1,1,1997,'D',"INITIAL",1.1,1.1,1.1);
      delete_account(t_accno);
   }
   char t_name[30],t[10],t_address[60];
   float t_bal=0.0, t_balance=0.0;
   gotoxy(5,6);
   cout<<"DATE:"<<d1<<"/"<<m1<<"/"<<y1;
   gotoxy(5,8);
   cout<<"ACCOUNT NO. # :"<<t_accno;
   gotoxy(5,10);
   cout<<"NAME   :";
   gotoxy(8,11);
   cout<<"ADDRESS  :";
   gotoxy(8,12);
   cout<<"NAME OF VARIFYING PERSON:";
   gotoxy(5,14);
   cout<<"INITIAL DEPOSIT";
   do
   {
      clear(15,10);
      clear(5,23);
      gotoxy(5,23);
      cout<<"ENTER NAME OF THE PERSON";
      valid=1;
      gotoxy(15,10);
      gets(t_name);
      strupr(t_name);
      if(t_name[0]=='0')
          return;
      if(strlen(t_name)==0||strlen(t_name)>25)
      {
         valid=0;
         gotoxy(5,23);
         cprintf("\7NAME SHOULD NOT BLANK OR GREATER THAN 25");
         getch();
      }
   }while(!valid);
   do
   {
      clear(15,11);
      clear(5,23);
      gotoxy(5,23);
      cout< <"ENTER ADDRESS OF THE PERSON";
      valid=1;
      gotoxy(23,11);
      gets(t_address);
      strupr(t_address);
      if(t_address[0]=='0')
           return;
      if(strlen(t_address)==0|| strlen(t_address)>55)
      {
        valid =0;
        gotoxy(5,23);
        cprintf("\7SHOULD NOT BLANK OR GREATER THAN 55");
        getch();
      }
   }while(!valid);
   do
   {
      char vari[30];
      clear(5,23);
      gotoxy(5,23);
      cout< <"ENTER NAME OF THE VARIFYING PERSON";
      valid=1;
      gotoxy(35,12);
      gets(vari);
      strupr(vari);
      if(vari[0]=='0')
          return;
      if(strlen(vari)==0 || strlen(vari)>25)
      {
        valid=0;
        gotoxy(5,23);
        cprintf("\7SHOULD NOT BLANK OR GREATER THAN 25");
        getch();
      }
   }while(!valid);
   do
   {
      clear(5,23);
      clear(5,23);
      gotoxy(5,23);
      cout< <"ENTER INITIAL AMOUNT TO BE DEPOSIT";
      valid=1;
<span lang="EN-
