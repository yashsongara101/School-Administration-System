//***************************************************************
//       HEADER FILE AND GLOBAL VARIABLES USED IN PROJECT
//****************************************************************

#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<process.h>
char pass[10],pass1[10];
char *pass2,*passcur;
//***************************************************************
//    	function declaration
//****************************************************************
void chpass();     // To Set & Change the Password
void mainpass();  //Dispaly Password Menu
void write_student();	//write the record in binary file
void display_sp(int n);	//accept srno and read record from binary file
void display_dp(int,int);   // Accept srno and read details of the student
void display_nm(char n[]);// accept name and read details of the student
void search();   // To search the student record
void modify_student(int);	//accept srno and update record of student from  binary file
void class_result();	//display all records in tabular format from binary file
void result();	//display result menu
void intro();	//display welcome screen
void entry_menu();	//display entry menu on screen
void main_menu();  //Display Main Menu Screen
void staff_menu(); //display staff menu
void addstaff(); // To create staff record
void showstaff();//To show staff informtion
void viewstaff(char n[]);// to View staff Information
void modify_staff(char n[]);// To nmodify Staff information
void housedetail(); // To show House Details
void arsr(); // To show details of arawali senior
void arjr();
void astu();  // To show Student of House
void ajstu();
void nsr(); // To how details of arawali senior
void njsr();
void nstu();  // To show Student of House
void njstu();
void ssr(); // To show details of arawali senior
void sjsr();
void sstu();  // To show Student of House
void sjstu();
void usr(); // To show details of arawali senior
void ujsr();
void ustu();  // To show Student of House
void ujstu();
void sturesult(int);
void studetails(int);
void disstu(int);
void stmenu();
void stucursta(int n);

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
class staff
{    char f_name[50],mob[20];
     char desg[50];
     char jdob[20];
     public :
	  char name[50];
	  void getdata();
	  void showtabular();
	  void showdata();
	  };
void staff::getdata()
{  textcolor(YELLOW);
   cout<<"\n\n";cprintf(" * Enter the Details >>>>> ");textcolor(GREEN);
   cout<<"\n\n";cprintf("  * Name : ");
   gets(name);
   cout<<"\n\n";cprintf("  * Father's Name : ");
   gets(f_name);
   cout<<"\n\n";cprintf("  * Date of Joining : ");
   gets(jdob);
   cout<<"\n\n";cprintf("  * Designation : ");
   gets(desg);
   cout<<"\n\n";cprintf("  * Mobile Number : ");
   gets(mob);
   getch();
   clrscr();
   cout<<"\n\n\n\n\t\t";textcolor(YELLOW+BLINK);cprintf(" !!!!  Staff Record has Been Created  !!!! ");
}
void staff :: showdata()
{  textcolor(3);
   cout<<"\n\n\t\t\t";textcolor(YELLOW);cprintf(" :: S T A F F  D E T A I L S ::  ");textcolor(GREEN);
   cout<<"\n\n\t\t";cprintf("  * Name : ");cout<<name;
   cout<<"\n\n\t\t";cprintf("  * Father's Name : ");cout<<f_name;
   cout<<"\n\n\t\t";cprintf("  * Date of Joining : ");cout<<jdob;
   cout<<"\n\n\t\t";cprintf("  * Designation : ");cout<<desg;
   cout<<"\n\n\t\t";cprintf("  * Mobile Number : ");cout<<mob;

}
void  showstaff()
{
	staff st;
	ifstream inFile;
	inFile.open("staff.dat",ios::binary);
	if(!inFile)
	{     		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		getch();
		textcolor(GREEN);
		clrscr();
		main_menu();
	}
	cout<<"\n"; textcolor(WHITE);cprintf(" :: S T A F F  I N F O R M A T I O N :: ");cout<<"\n\n";
	textcolor(GREEN);cprintf("================================================================================");cout<<"\n";
	cprintf("    Name       Father's Name     Designation     Date of joining      Contact ");cout<<endl;
	cprintf("================================================================================");cout<<"\n";
	while(inFile.read((char *) &st, sizeof(st)))
	{       cout<<"\n";
		st.showtabular();
	}

	getch();
	inFile.close();
	clrscr();
	staff_menu();
 }
 void staff::showtabular()
{    textcolor(3);
	cout<<name;
	cout<<setw(18)<<f_name ;
	cout<<setw(16)<<desg;
	cout<<setw(18)<<jdob;
	cout<<setw(17)<<mob;
}


class student
{       char f_name[50],m_name[50],Arts;
	int sr_no;
	char mob[20],add[50],dob[20],email[50],cat[20],area[10],bg[10],ident[50];
	int marks6[5],marks7[5],marks8[5],marks9[5],marks10[5], marks11[5],marks12[5];
	float per[7];
	char grade[7];
	void calculate();	//function to calculate grade
public:
	char hname[50],name[50];int Class,proceed;int session[8],rollno[7];
	void getdata();	//function to accept data from user
	void showdata();	//function to show data on screen
	void show_tabular();
	void show_tabulardt();
	void showstu();
	int retsrno();
	void stucur();
	void inclass6();
	void inclass7();
	void inclass8();
	void inclass9();
	void inclass10();
	void inclass11();
	void inclass12();
	void outclass6();
	void outclass7();
	void outclass8();
	void outclass9();
	void outclass10();
	void outclass11a();
	void outclass11b();
	void outclass12a();
	void outclass12b();
	void result();
}; //class ends here
void student :: stucur()
{ if(proceed==0){Class=6;session[7]=session[0];}
else if(proceed==1){Class=7;session[7]=session[1]; }
else if(proceed==2){Class=8;session[7]=session[2]; }
else if(proceed==3){Class=9;session[7]=session[3]; }
else if(proceed==4){Class=10;session[7]=session[4]; }
else if(proceed==5){Class=11;session[7]=session[5]; }
else if(proceed==6){Class=12;session[7]=session[6];}
else if(proceed==7){  clrscr();
 cout<<"\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf(" HEY!!! ");
 cout<<"\n\n\t";textcolor(RED);cprintf(" This Student is Passout From the School ");
 cout<<"\n\n\t\t";cprintf("In session :: ");cout<<session[6]+1;
}
else {clrscr();
cout<<"\n\n\t";textcolor(WHITE);cprintf(" ::  C U R R E N T   S T A T U S  :: ");
cout<<"\n\n\n\t";textcolor(YELLOW);cprintf("* Name :: ");cout<<name;
cout<<"\n\n\t";cprintf("* Class :: ");cout<<Class;
cout<<"\n\n\t";cprintf("* Session :: ");cout<<session[7];
cout<<"\n\n\t";cprintf("* Sr.No. :: ");cout<<sr_no;
cout<<"\n\n\t";cprintf("* House :: ");cout<<hname;}


}
void student :: outclass6()
{ if(proceed!=0){ clrscr();
   textcolor(WHITE);
  cout<<"     ";cprintf(":: J A W A H A R   N A V O D A Y A   V I D Y A L A Y A  J A L O R E :: ");
  cout<<"\n\n\t\t\t";textcolor(YELLOW+BLINK);cprintf(" ::   R E P O R T   C A R D   :: ");
  cout<<"\n\n\t\t\t       ";textcolor(YELLOW);cprintf("Session :: ");cout<<session[0]<<"-"<<session[0]+1;
  cout<<"\n\n";cprintf(" * CLASS - 6");cout<<"\t\t\t\t\t"; cprintf("* Roll No. ");cout<<rollno[0];
  cout<<"\n\n";cprintf(" * Name :: ");cout<<setw(20)<<name<<"\t\t\t";cprintf("* Sr.No. :: ");cout<<sr_no;
  cout<<"\n\n";cprintf(" * Father's Name :: ");cout<<setw(20)<<f_name<<"\t"; cprintf("* D O B :: ");cout<<dob;
  cout<<"\n\n";cprintf(" * Mother's Name :: ");cout<<setw(20)<<m_name<<"\t";cprintf("* E-Mail :: ");cout<<email;
  cout<<"\n\n";cprintf(" * Marks details >>>>");
  cout<<"\n";cprintf("     Subject                 Maximum Marks             Obtained Marks  ");
  cout<<"\n\n   ";cprintf(" > English                    100            ::          ");cout<<marks6[0];
  cout<<"\n ";cprintf("   > Social Studies             100            ::          ");cout<<marks6[1];
  cout<<"\n ";cprintf("   > Science                    100            ::          ");cout<<marks6[2];
  cout<<"\n ";cprintf("   > Hindi                      100            ::          ");cout<<marks6[3];
  cout<<"\n ";cprintf("   > Maths                      100            ::          ");cout<<marks6[4];
  cout<<"\n\n";
  cprintf(" * Percentage  :: ");
  cout<<per[0]<<" %";
  cout<<"\t\t\t";
  cprintf(" * Grade  :: ");
  cout<<grade[0];}
  else
      {


       clrscr();
	cout<<"\n\n\n\t\t";textcolor(RED+BLINK);cprintf("Hey !!!");textcolor(RED);cout<<"\n\n\t\t";cprintf(" Student Not Completed his 6th Class ");
	cout<<"\n\n\t\t";cprintf(" After Completion Of 6th Class Report Card is Viewed ");
      }

}
void student :: outclass7()
{ if(proceed!=1&&proceed>=1)
{ clrscr();
   textcolor(WHITE);
  cout<<"     ";cprintf(":: J A W A H A R   N A V O D A Y A   V I D Y A L A Y A  J A L O R E :: ");
  cout<<"\n\n\t\t\t";textcolor(YELLOW+BLINK);cprintf(" ::   R E P O R T   C A R D   :: ");
  cout<<"\n\n\t\t\t       ";textcolor(YELLOW);cprintf("Session :: ");cout<<session[1]<<"-"<<session[1]+1;
  cout<<"\n\n";cprintf(" * CLASS - 7");cout<<"\t\t\t\t\t"; cprintf("* Roll No. :: ");cout<<rollno[1];
  cout<<"\n\n";cprintf(" * Name :: ");cout<<setw(20)<<name<<"\t\t\t";cprintf("* Sr.No. :: ");cout<<sr_no;
  cout<<"\n\n";cprintf(" * Father's Name :: ");cout<<setw(20)<<f_name<<"\t"; cprintf("* D O B :: ");cout<<dob;
  cout<<"\n\n";cprintf(" * Mother's Name :: ");cout<<setw(20)<<m_name<<"\t";cprintf("* E-Mail :: ");cout<<email;
  cout<<"\n\n";cprintf(" * Marks details >>>>");
  cout<<"\n";cprintf("     Subject                 Maximum Marks             Obtained Marks  ");
  cout<<"\n\n   ";cprintf(" > English                    100            ::          ");cout<<marks7[0];
  cout<<"\n ";cprintf("   > Social Studies             100            ::          ");cout<<marks7[1];
  cout<<"\n ";cprintf("   > Science                    100            ::          ");cout<<marks7[2];
  cout<<"\n ";cprintf("   > Hindi                      100            ::          ");cout<<marks7[3];
  cout<<"\n ";cprintf("   > Maths                      100            ::          ");cout<<marks7[4];
  cout<<"\n\n";
  cprintf(" * Percentage  :: ");
  cout<<per[1]<<" %";
  cout<<"\t\t\t";
  cprintf(" * Grade  :: ");
  cout<<grade[1];
  }
   else
      { clrscr();

	cout<<"\n\n\n\t\t";textcolor(RED+BLINK);cprintf("Hey !!!");textcolor(RED);cout<<"\n\n\t\t";cprintf(" Student Not Completed his 7th Class ");
	cout<<"\n\n\t\t";cprintf(" After Completion Of 7th Class Report Card is Viewed ");
      }
}
void student :: outclass8()
{ if(proceed!=2&&proceed>=2)
{

clrscr();
   textcolor(WHITE);
  cout<<"     ";cprintf(":: J A W A H A R   N A V O D A Y A   V I D Y A L A Y A  J A L O R E :: ");
  cout<<"\n\n\t\t\t";textcolor(YELLOW+BLINK);cprintf(" ::   R E P O R T   C A R D   :: ");
  cout<<"\n\n\t\t\t       ";textcolor(YELLOW);cprintf("Session :: ");cout<<session[2]<<"-"<<session[2]+1;
  cout<<"\n\n";cprintf(" * CLASS - 8");cout<<"\t\t\t\t\t"; cprintf("* Roll No. :: ");cout<<rollno[2];
  cout<<"\n\n";cprintf(" * Name :: ");cout<<setw(20)<<name<<"\t\t\t";cprintf("* Sr.No. :: ");cout<<sr_no;
  cout<<"\n\n";cprintf(" * Father's Name :: ");cout<<setw(20)<<f_name<<"\t"; cprintf("* D O B :: ");cout<<dob;
  cout<<"\n\n";cprintf(" * Mother's Name :: ");cout<<setw(20)<<m_name<<"\t";cprintf("* E-Mail :: ");cout<<email;
  cout<<"\n\n";cprintf(" * Marks details >>>>");
  cout<<"\n";cprintf("     Subject                 Maximum Marks             Obtained Marks  ");
  cout<<"\n\n   ";cprintf(" > English                    100            ::          ");cout<<marks8[0];
  cout<<"\n ";cprintf("   > Social Studies             100            ::          ");cout<<marks8[1];
  cout<<"\n ";cprintf("   > Science                    100            ::          ");cout<<marks8[2];
  cout<<"\n ";cprintf("   > Hindi                      100            ::          ");cout<<marks8[3];
  cout<<"\n ";cprintf("   > Maths                      100            ::          ");cout<<marks8[4];
  cout<<"\n\n";
  cprintf(" * Percentage  :: ");
  cout<<per[2]<<" %";
  cout<<"\t\t\t";
  cprintf(" * Grade  :: ");
  cout<<grade[2];
 }
  else
      { clrscr();

	cout<<"\n\n\n\t\t";textcolor(RED+BLINK);cprintf("Hey !!!");textcolor(RED);cout<<"\n\n\t\t";cprintf(" Student Not Completed his 8th Class ");
	cout<<"\n\n\t\t";cprintf(" After Completion Of 8th Class Report Card is Viewed ");
      }


}
void student :: outclass9()
{if(proceed!=3&&proceed>=3)
{
clrscr();
   textcolor(WHITE);
  cout<<"     ";cprintf(":: J A W A H A R   N A V O D A Y A   V I D Y A L A Y A  J A L O R E :: ");
  cout<<"\n\n\t\t\t";textcolor(YELLOW+BLINK);cprintf(" ::   R E P O R T   C A R D   :: ");
  cout<<"\n\n\t\t\t       ";textcolor(YELLOW);cprintf("Session :: ");cout<<session[3]<<"-"<<session[3]+1;
  cout<<"\n\n";cprintf(" * CLASS - 9");cout<<"\t\t\t\t\t"; cprintf("* Roll No. :: ");cout<<rollno[3];
  cout<<"\n\n";cprintf(" * Name :: ");cout<<setw(20)<<name<<"\t\t\t";cprintf("* Sr.No. :: ");cout<<sr_no;
  cout<<"\n\n";cprintf(" * Father's Name :: ");cout<<setw(20)<<f_name<<"\t"; cprintf("* D O B :: ");cout<<dob;
  cout<<"\n\n";cprintf(" * Mother's Name :: ");cout<<setw(20)<<m_name<<"\t";cprintf("* E-Mail :: ");cout<<email;
  cout<<"\n\n";cprintf(" * Marks details >>>>");
  cout<<"\n";cprintf("     Subject                 Maximum Marks             Obtained Marks  ");
  cout<<"\n\n   ";cprintf(" > English                    100            ::          ");cout<<marks9[0];
  cout<<"\n ";cprintf("   > Social Studies             100            ::          ");cout<<marks9[1];
  cout<<"\n ";cprintf("   > Science                    100            ::          ");cout<<marks9[2];
  cout<<"\n ";cprintf("   > Hindi                      100            ::          ");cout<<marks9[3];
  cout<<"\n ";cprintf("   > Maths                      100            ::          ");cout<<marks9[4];
  cout<<"\n\n";
  cprintf(" * Percentage  :: ");
  cout<<per[3]<<" %";
  cout<<"\t\t\t";
  cprintf(" * Grade  :: ");
  cout<<grade[3];
 }
  else
      { clrscr();

	cout<<"\n\n\n\t\t";textcolor(RED+BLINK);cprintf("Hey !!!");textcolor(RED);cout<<"\n\n\t\t";cprintf(" Student Not Completed his 9th Class ");
	cout<<"\n\n\t\t";cprintf(" After Completion Of 9th Class Report Card is Viewed ");
      }


}
void student :: outclass10()
{if(proceed!=4&&proceed>=4)
{
 clrscr();
   textcolor(WHITE);
  cout<<"     ";cprintf(":: J A W A H A R   N A V O D A Y A   V I D Y A L A Y A  J A L O R E :: ");
  cout<<"\n\n\t\t\t";textcolor(YELLOW+BLINK);cprintf(" ::   R E P O R T   C A R D   :: ");
  cout<<"\n\n\t\t\t       ";textcolor(YELLOW);cprintf("Session :: ");cout<<session[4]<<"-"<<session[4]+1;
  cout<<"\n\n";cprintf(" * CLASS - 10");cout<<"\t\t\t\t\t"; cprintf("* Roll No. :: ");cout<<rollno[4];
  cout<<"\n\n";cprintf(" * Name :: ");cout<<setw(20)<<name<<"\t\t\t";cprintf("* Sr.No. :: ");cout<<sr_no;
  cout<<"\n\n";cprintf(" * Father's Name :: ");cout<<setw(20)<<f_name<<"\t"; cprintf("* D O B :: ");cout<<dob;
  cout<<"\n\n";cprintf(" * Mother's Name :: ");cout<<setw(20)<<m_name<<"\t";cprintf("* E-Mail :: ");cout<<email;
  cout<<"\n\n";cprintf(" * Marks details >>>>");
  cout<<"\n";cprintf("     Subject                 Maximum Marks             Obtained Marks  ");
  cout<<"\n\n   ";cprintf(" > English                    100            ::          ");cout<<marks10[0];
  cout<<"\n ";cprintf("   > Social Studies             100            ::          ");cout<<marks10[1];
  cout<<"\n ";cprintf("   > Science                    100            ::          ");cout<<marks10[2];
  cout<<"\n ";cprintf("   > Hindi                      100            ::          ");cout<<marks10[3];
  cout<<"\n ";cprintf("   > Maths                      100            ::          ");cout<<marks10[4];
  cout<<"\n\n";
  cprintf(" * Percentage  :: ");
  cout<<per[4]<<" %";
  cout<<"\t\t\t";
  cprintf(" * Grade  :: ");
  cout<<grade[4];
}
 else
      { clrscr();

	cout<<"\n\n\n\t\t";textcolor(RED+BLINK);cprintf("Hey !!!");textcolor(RED);cout<<"\n\n\t\t";cprintf(" Student Not Completed his 10th Class ");
	cout<<"\n\n\t\t";cprintf(" After Completion Of 10th Class Report Card is Viewed ");
      }


}
void student :: outclass11a()
{if(proceed!=5&&proceed>=5)
{
clrscr();
    textcolor(WHITE);
  cout<<"     ";cprintf(":: J A W A H A R   N A V O D A Y A   V I D Y A L A Y A  J A L O R E :: ");
  cout<<"\n\n\t\t\t";textcolor(YELLOW+BLINK);cprintf(" ::   R E P O R T   C A R D   :: ");
  cout<<"\n\n\t\t\t       ";textcolor(YELLOW);cprintf("Session :: ");cout<<session[5]<<"-"<<session[5]+1;
  cout<<"\n\n";cprintf(" * CLASS - 11");cout<<"\t\t\t\t\t"; cprintf("* Roll No. :: ");cout<<rollno[5];
  cout<<"\n\n";cprintf(" * Name :: ");cout<<setw(20)<<name<<"\t\t\t";cprintf("* Sr.No. :: ");cout<<sr_no;
  cout<<"\n\n";cprintf(" * Father's Name :: ");cout<<setw(20)<<f_name<<"\t"; cprintf("* D O B :: ");cout<<dob;
  cout<<"\n\n";cprintf(" * Mother's Name :: ");cout<<setw(20)<<m_name<<"\t";cprintf("* E-Mail :: ");cout<<email;
  cout<<"\n\n";cprintf(" * Marks details >>>>");
  cout<<"\n\n";cprintf("     Subject                 Maximum Marks             Obtained Marks  ");
  cout<<"\n\n";cprintf("    > English                    100            ::          ");cout<<marks11[0];
  cout<<"\n ";cprintf("   > Computer Science/Hindi     100            ::          ");cout<<marks11[1];
  cout<<"\n ";cprintf("   > Physics                    100            ::          ");cout<<marks11[2];
  cout<<"\n ";cprintf("   > Chemistry                  100            ::          ");cout<<marks11[3];
  cout<<"\n ";cprintf("   > Maths/Biology              100            ::          ");cout<<marks11[4];
  cout<<"\n\n";
  cprintf(" * Percentage  :: ");
  cout<<per[5]<<" %";
  cout<<"\t\t\t";
  cprintf("    * Grade  :: ");
  cout<<grade[5];
 }
  else
      { clrscr();

	cout<<"\n\n\n\t\t";textcolor(RED+BLINK);cprintf("Hey !!!");textcolor(RED);cout<<"\n\n\t\t";cprintf(" Student Not Completed his 11th Class ");
	cout<<"\n\n\t\t";cprintf(" After Completion Of 11th Class Report Card is Viewed ");
      }

}
void student :: outclass11b()
{ if(proceed!=5&&proceed>=5)
{
 clrscr();

   textcolor(WHITE);
  cout<<"     ";cprintf(":: J A W A H A R   N A V O D A Y A   V I D Y A L A Y A  J A L O R E :: ");
  cout<<"\n\n\t\t\t";textcolor(YELLOW+BLINK);cprintf(" ::   R E P O R T   C A R D   :: ");
  cout<<"\n\n\t\t\t       ";textcolor(YELLOW);cprintf("Session :: ");cout<<session[5]<<"-"<<session[5]+1;
  cout<<"\n\n";cprintf(" * CLASS - 11");cout<<"\t\t\t\t\t"; cprintf("* Roll No. :: ");cout<<rollno[5];
  cout<<"\n\n";cprintf(" * Name :: ");cout<<setw(20)<<name<<"\t\t\t";cprintf("* Sr.No. :: ");cout<<sr_no;
  cout<<"\n\n";cprintf(" * Father's Name :: ");cout<<setw(20)<<f_name<<"\t"; cprintf("* D O B :: ");cout<<dob;
  cout<<"\n\n";cprintf(" * Mother's Name :: ");cout<<setw(20)<<m_name<<"\t";cprintf("* E-Mail :: ");cout<<email;
  cout<<"\n\n";cprintf(" * Marks details >>>>");
  cout<<"\n\n";cprintf("     Subject                 Maximum Marks             Obtained Marks  ");
  cout<<"\n\n";cprintf("    > English                     100            ::          ");cout<<marks11[0];
  cout<<"\n ";cprintf("   > Geography                   100            ::          ");cout<<marks11[1];
  cout<<"\n ";cprintf("   > History                     100            ::          ");cout<<marks11[2];
  cout<<"\n ";cprintf("   > Hindi/IP                    100            ::          ");cout<<marks11[3];
  cout<<"\n ";cprintf("   > Economics                   100            ::          ");cout<<marks11[4];
  cout<<"\n\n";
  cprintf(" * Percentage  :: ");
  cout<<per[5]<<" %";
  cout<<"\t\t\t";
  cprintf("    * Grade  :: ");
  cout<<grade[5];
 }
   else
      { clrscr();
	cout<<"\n\n\n\t\t";textcolor(RED+BLINK);cprintf("Hey !!!");textcolor(RED);cout<<"\n\n\t\t";cprintf(" Student Not Completed his 11th Class ");
	cout<<"\n\n\t\t";cprintf(" After Completion Of 11th Class Report Card is Viewed ");
      }

}
void student :: outclass12a()
{ if(proceed!=6&&proceed>=6)
{ clrscr();
    textcolor(WHITE);
  cout<<"     ";cprintf(":: J A W A H A R   N A V O D A Y A   V I D Y A L A Y A  J A L O R E :: ");
  cout<<"\n\n\t\t\t";textcolor(YELLOW+BLINK);cprintf(" ::   R E P O R T   C A R D   :: ");
  cout<<"\n\n\t\t\t       ";textcolor(YELLOW);cprintf("Session :: ");cout<<session[6]<<"-"<<session[6]+1;
  cout<<"\n\n";cprintf(" * CLASS - 12");cout<<"\t\t\t\t\t"; cprintf("* Roll No. :: ");cout<<rollno[6];
  cout<<"\n\n";cprintf(" * Name :: ");cout<<setw(20)<<name<<"\t\t\t";cprintf("* Sr.No. :: ");cout<<sr_no;
  cout<<"\n\n";cprintf(" * Father's Name :: ");cout<<setw(20)<<f_name<<"\t"; cprintf("* D O B :: ");cout<<dob;
  cout<<"\n\n";cprintf(" * Mother's Name :: ");cout<<setw(20)<<m_name<<"\t";cprintf("* E-Mail :: ");cout<<email;
  cout<<"\n\n";cprintf(" * Marks details >>>>");
  cout<<"\n\n";cprintf("     Subject                 Maximum Marks             Obtained Marks  ");
  cout<<"\n\n";cprintf("    > English                    100            ::          ");cout<<marks12[0];
  cout<<"\n ";cprintf("   > Computer Science/Hindi     100            ::          ");cout<<marks12[1];
  cout<<"\n ";cprintf("   > Physics                    100            ::          ");cout<<marks12[2];
  cout<<"\n ";cprintf("   > Chemistry                  100            ::          ");cout<<marks12[3];
  cout<<"\n ";cprintf("   > Maths/Biology              100            ::          ");cout<<marks12[4];
  cout<<"\n\n";
  cprintf(" * Percentage  :: ");
  cout<<per[6]<<" %";
  cout<<"\t\t\t";
  cprintf("    * Grade  :: ");
  cout<<grade[6];
 }
  else
      { clrscr();
	cout<<"\n\n\n\t\t";textcolor(RED+BLINK);cprintf("Hey !!!");textcolor(RED);cout<<"\n\n\t\t";cprintf(" Student Not Completed his 12th Class ");
	cout<<"\n\n\t\t";cprintf(" After Completion Of 12th Class Report Card is Viewed ");
      }


}
void student :: outclass12b()
{ if(proceed!=6&&proceed>=6)
{

 clrscr();

   textcolor(WHITE);
  cout<<"     ";cprintf(":: J A W A H A R   N A V O D A Y A   V I D Y A L A Y A  J A L O R E :: ");
  cout<<"\n\n\t\t\t";textcolor(YELLOW+BLINK);cprintf(" ::   R E P O R T   C A R D   :: ");
  cout<<"\n\n\t\t\t       ";textcolor(YELLOW);cprintf("Session :: ");cout<<session[5]<<"-"<<session[6]+1;
  cout<<"\n\n";cprintf(" * CLASS - 12");cout<<"\t\t\t\t\t"; cprintf("* Roll No. :: ");cout<<rollno[6];
  cout<<"\n\n";cprintf(" * Name :: ");cout<<setw(20)<<name<<"\t\t\t";cprintf("* Sr.No. :: ");cout<<sr_no;
  cout<<"\n\n";cprintf(" * Father's Name :: ");cout<<setw(20)<<f_name<<"\t"; cprintf("* D O B :: ");cout<<dob;
  cout<<"\n\n";cprintf(" * Mother's Name :: ");cout<<setw(20)<<m_name<<"\t";cprintf("* E-Mail :: ");cout<<email;
  cout<<"\n\n";cprintf(" * Marks details >>>>");
  cout<<"\n\n";cprintf("     Subject                 Maximum Marks             Obtained Marks  ");
  cout<<"\n\n";cprintf("    > English                     100            ::          ");cout<<marks12[0];
  cout<<"\n ";cprintf("   > Geography                   100            ::          ");cout<<marks12[1];
  cout<<"\n ";cprintf("   > History                     100            ::          ");cout<<marks12[2];
  cout<<"\n ";cprintf("   > Hindi/IP                    100            ::          ");cout<<marks12[3];
  cout<<"\n ";cprintf("   > Economics                   100            ::          ");cout<<marks12[4];
  cout<<"\n\n";cprintf(" * Percentage  :: ");cout<<per[6]<<" %";cout<<"\t\t\t";cprintf("    * Grade  :: ");cout<<grade[6];
 }
  else
      { clrscr();
	cout<<"\n\n\n\t\t";textcolor(RED+BLINK);cprintf("Hey !!!");textcolor(RED);cout<<"\n\n\t\t";cprintf(" Student Not Completed his 12th Class ");
	cout<<"\n\n\t\t";cprintf(" After Completion Of 12th Class Report Card is Viewed ");
      }

}
void student::inclass6()
{  clrscr(); char sh;   cprintf(" * WILL STUDENT COMPLETED CLASS 6 IN J N V ???? (Y/N):: ");
       cin>>sh;
       if(sh=='y'||sh=='Y')
       {
       clrscr();
	textcolor(YELLOW);
	cout<<"\n";cprintf(" * Enter the Roll No. in Class 6 :: ");cin>>rollno[0];
	cout<<"\n";cprintf(" * Enter Marks Out of 100 :: ");
	cout<<"\n\n";cprintf("  > English          :: ");
	cin>>marks6[0];
	cout<<"\n";cprintf("  > Social Studies :: ");
	cin>>marks6[1];
	cout<<"\n";cprintf("  > Science          :: ");
	cin>>marks6[2];
	cout<<"\n";cprintf("  > Hindi        :: ");
	cin>>marks6[3];
	cout<<"\n";cprintf("  > Mathematics       :: ");
	cin>>marks6[4];
	delay(500);
	inclass7();
	 }
	else
	 { proceed=0;  cprintf(" Okay.....");delay(500);

	 }
}
void student::inclass7()
{ clrscr();  char sh;   cprintf(" * WILL STUDENT COMPLETED CLASS 7 IN J N V ???? (Y/N):: ");
       cin>>sh;
       if(sh=='y'||sh=='Y')
       {
       clrscr();
	textcolor(YELLOW);
	cout<<"\n";cprintf(" * Enter the Roll No. in Class 7 :: ");cin>>rollno[1];
	cout<<"\n";cprintf(" * Enter Marks Out of 100 :: ");
	cout<<"\n\n";cprintf("  > English          :: ");
	cin>>marks7[0];
	cout<<"\n";cprintf("  > Social Studies :: ");
	cin>>marks7[1];
	cout<<"\n";cprintf("  > Science          :: ");
	cin>>marks7[2];
	cout<<"\n";cprintf("  > Hindi        :: ");
	cin>>marks7[3];
	cout<<"\n";cprintf("  > Mathematics       :: ");
	cin>>marks7[4];
	delay(500);
	inclass8(); }
	else
	  { proceed=1;
	   cprintf(" Okay.....");
	   delay(500);
	   }
}
void student::inclass8()
{ clrscr();  char sh;  cprintf(" * WILL STUDENT COMPLETED CLASS 8 IN J N V ???? (Y/N):: ");
       cin>>sh;
       if(sh=='y'||sh=='Y')
       {
       clrscr();
	textcolor(YELLOW);
	cout<<"\n";cprintf(" * Enter the Roll No. in Class 8 :: ");cin>>rollno[2];
	cout<<"\n";cprintf(" * Enter Marks Out of 100 :: ");
	cout<<"\n\n";cprintf("  > English          :: ");
	cin>>marks8[0];
	cout<<"\n";cprintf("  > Social Studies :: ");
	cin>>marks8[1];
	cout<<"\n";cprintf("  > Science          :: ");
	cin>>marks8[2];
	cout<<"\n";cprintf("  > Hindi        :: ");
	cin>>marks8[3];
	cout<<"\n";cprintf("  > Mathematics       :: ");
	cin>>marks8[4];
	delay(500);
	inclass9(); }
	else
	  { proceed=2; cprintf(" Okay.....");delay(500);   }
}void student::inclass9()
{ clrscr();  char sh;   cprintf(" * WILL STUDENT COMPLETED CLASS 9 IN J N V ???? (Y/N):: ");
       cin>>sh;
       if(sh=='y'||sh=='Y')
       {
       clrscr();
	textcolor(YELLOW);
	cout<<"\n";cprintf(" * Enter the Roll No. in Class 9 :: ");cin>>rollno[3];
	cout<<"\n";cprintf(" * Enter Marks Out of 100 :: ");
	cout<<"\n\n";cprintf("  > English          :: ");
	cin>>marks9[0];
	cout<<"\n";cprintf("  > Social Studies :: ");
	cin>>marks9[1];
	cout<<"\n";cprintf("  > Science          :: ");
	cin>>marks9[2];
	cout<<"\n";cprintf("  > Hindi        :: ");
	cin>>marks9[3];
	cout<<"\n";cprintf("  > Mathematics       :: ");
	cin>>marks9[4];
	delay(500);
	inclass10(); }
	else
	   {proceed=3; cprintf(" Okay.....");delay(500);}
}
void student::inclass10()
{  clrscr(); char sh;   cprintf(" * WILL STUDENT COMPLETED CLASS 10 IN J N V ???? (Y/N):: ");
       cin>>sh;
       if(sh=='y'||sh=='Y')
       {
       clrscr();
	textcolor(YELLOW);
	cout<<"\n";cprintf(" * Enter the Roll No. in Class 10 :: ");cin>>rollno[4];
	cout<<"\n";cprintf(" * Enter Marks Out of 100 :: ");
	cout<<"\n\n";cprintf("  > English          :: ");
	cin>>marks10[0];
	cout<<"\n";cprintf("  > Social Studies :: ");
	cin>>marks10[1];
	cout<<"\n";cprintf("  > Science          :: ");
	cin>>marks10[2];
	cout<<"\n";cprintf("  > Hindi        :: ");
	cin>>marks10[3];
	cout<<"\n";cprintf("  > Mathematics       :: ");
	cin>>marks10[4];
	delay(500);
	inclass11(); }
	else
	 { proceed=4;  cprintf(" Okay....."); delay(500);  }
}
void student::inclass11()
{  clrscr(); char sh,ch;   cprintf(" * WILL STUDENT COMPLETED CLASS 11 IN J N V ???? (Y/N):: ");
       cin>>sh;
       if(sh=='y'||sh=='Y')
       {  cprintf("Is Student of  Arts (Y/N) ");cin>>ch;
	  if(ch=='Y'||ch=='y')
	  { Arts='Y';
	    clrscr();
	textcolor(YELLOW);
	cout<<"\n";cprintf(" * Enter the Roll No. in Class 11 :: ");cin>>rollno[5];
	cout<<"\n";cprintf(" * Enter Marks Out of 100 :: ");
	cout<<"\n\n";cprintf("  > English          :: ");
	cin>>marks11[0];
	cout<<"\n";cprintf("  > Geography :: ");
	cin>>marks11[1];
	cout<<"\n";cprintf("  > History          :: ");
	cin>>marks11[2];
	cout<<"\n";cprintf("  > Economics  :: ");
	cin>>marks11[4];
	cout<<"\n";cprintf("  > Hindi/IP       :: ");
	cin>>marks11[3];
	delay(500);
	inclass12();
	    }
	  else
	   { Arts='N';
       clrscr();
	textcolor(YELLOW);
	cout<<"\n";cprintf(" * Enter the Roll No. in Class 11 :: ");cin>>rollno[5];
	cout<<"\n";cprintf(" * Enter Marks Out of 100 :: ");
	cout<<"\n\n";cprintf("  > English          :: ");
	cin>>marks11[0];
	cout<<"\n";cprintf("  > Chemistry :: ");
	cin>>marks11[3];
	cout<<"\n";cprintf("  > Physics          :: ");
	cin>>marks11[2];
	cout<<"\n";cprintf("  > Computer Science/Hindi  :: ");
	cin>>marks11[1];
	cout<<"\n";cprintf("  > Mathematics/Biology       :: ");
	cin>>marks11[4];
	delay(500);
	inclass12();} }
	else
	 { proceed=5;  cprintf(" Okay....."); delay(500);   }
}
void student::inclass12()
{  clrscr(); char sh;   cprintf(" * WILL STUDENT COMPLETED CLASS 12 IN J N V ???? (Y/N):: ");
       cin>>sh;
       if(sh=='y'||sh=='Y')
       { proceed=7;
	  if(Arts=='Y')
	  { clrscr();
	textcolor(YELLOW);
	cout<<"\n";cprintf(" * Enter the Roll No. in Class 12 :: ");cin>>rollno[6];
	cout<<"\n";cprintf(" * Enter Marks Out of 100 :: ");
	cout<<"\n\n";cprintf("  > English          :: ");
	cin>>marks12[0];
	cout<<"\n";cprintf("  > Geography :: ");
	cin>>marks12[1];
	cout<<"\n";cprintf("  > History          :: ");
	cin>>marks12[2];
	cout<<"\n";cprintf("  > Economics  :: ");
	cin>>marks12[4];
	cout<<"\n";cprintf("  > Hindi/IP       :: ");
	cin>>marks12[3];
	calculate();
	delay(500);
	    }
	  else if(Arts=='N')
	   {
       clrscr();
	textcolor(YELLOW);
	cout<<"\n";cprintf(" * Enter the Roll No. in Class 12 :: ");cin>>rollno[6];
	cout<<"\n";cprintf(" * Enter Marks Out of 100 :: ");
	cout<<"\n\n";cprintf("  > English          :: ");
	cin>>marks12[0];
	cout<<"\n";cprintf("  > Chemistry :: ");
	cin>>marks12[3];
	cout<<"\n";cprintf("  > Physics          :: ");
	cin>>marks12[2];
	cout<<"\n";cprintf("  > Computer Science/Hindi  :: ");
	cin>>marks12[1];
	cout<<"\n";cprintf("  > Mathematics/Biology       :: ");
	cin>>marks12[4];
	calculate();
	delay(500);
	} }
	else
	{ proceed=6;   cprintf(" Okay.....");delay(500);}
}
void student::calculate()
{
	per[0]=(marks6[0]+marks6[1]+marks6[2]+marks6[3]+marks6[4])/5.0;
	per[1]=(marks7[0]+marks7[1]+marks7[2]+marks7[3]+marks7[4])/5.0;
	per[2]=(marks8[0]+marks8[1]+marks8[2]+marks8[3]+marks8[4])/5.0;
	per[3]=(marks9[0]+marks9[1]+marks9[2]+marks9[3]+marks9[4])/5.0;
	per[4]=(marks10[0]+marks10[1]+marks10[2]+marks10[3]+marks10[4])/5.0;
	per[5]=(marks11[0]+marks11[1]+marks11[2]+marks11[3]+marks11[4])/5.0;
	per[6]=(marks12[0]+marks12[1]+marks12[2]+marks12[3]+marks12[4])/5.0;
	for(int i=0;i<7;++i)
	{
	if(per[i]>=60)
		grade[i]='A';
	else if(per[i]>=50)
		grade[i]='B';
	else if(per[i]>=33)
		grade[i]='C';
	else
		grade[i]='F'; }
}
void student::getdata()
{       textcolor(WHITE);
	cout<<"\n";cprintf("::  E N T E R   S T U D E N T   D E T A I L S :: ");
	cout<<"\n\n";textcolor(3);
	cprintf("* Scholar Registration Number :: ");
	cin>>sr_no;
	cout<<"\n";cprintf("* Session of Class 6   ::  ");cin>>session[0];
	session[1]=session[0]+1;
	session[2]=session[1]+1;
	session[3]=session[2]+1;
	session[4]=session[3]+1;
	session[5]=session[4]+1;
	session[6]=session[5]+1;
	cprintf("\n* Name               ::  ");
	gets(name);
	cout<<"\n";cprintf("* Father's Name      ::  ");
	gets(f_name);
	cout<<"\n";cprintf("* Mother's Name      ::  ");
	gets(m_name);
	clrscr();inclass6();
	clrscr();
	textcolor(GREEN);
	cout<<"\n\n";cprintf("* Personal Details >>>>> ");
	cout<<"\n\n";cprintf(" > House :: ");
	gets(hname);
	cout<<"\n";cprintf(" > Date Of Birth         :: ");
	gets(dob);
	cout<<"\n";cprintf(" > Address              ::   ");
	gets(add);
	cout<<"\n";cprintf(" > E-mail ID            :: ");
	gets(email);
	cout<<"\n";cprintf(" > Mobile Number       ::  ");
	gets(mob);
	cout<<"\n";cprintf(" > Category            :: ");
	gets(cat);
	cout<<"\n";cprintf(" > Area(Rural/Urban)       :: ");
	gets(area);
	cout<<"\n";cprintf(" > Blood Group      ::   ");
	gets(bg);
	cout<<"\n";cprintf(" > Student Identification  :: ");
	gets(ident);
 if(proceed==0){Class=6;session[7]=session[0];}
if(proceed==1){Class=7;session[7]=session[1]; }
if(proceed==2){Class=8;session[7]=session[2]; }
if(proceed==3){Class=9;session[7]=session[3]; }
if(proceed==4){Class=10;session[7]=session[4]; }
if(proceed==5){Class=11;session[7]=session[5]; }
if(proceed==6){Class=12;session[7]=session[6];}

}
void student::showdata()
{      textcolor(3); clrscr();
	cout<<"\n\t\t\t";textcolor(WHITE);cprintf(":: S T U D E N T  D E T A I L S :: ");
	cout<<"\n\n ";textcolor(YELLOW);cprintf(" * Name  :: ");cout<<name<<setw(25)<<" ";                 cprintf("* Sr.No. :: ");cout<<sr_no;
	cout<<"\n\n ";cprintf(" * Father's Name :: ");cout<<" Mr."<<f_name;cout<<"\t  ";
	cout<<"\n\n ";cprintf(" * Mother's Name :: ");cout<<" Mrs."<<m_name;
	cout<<"\n\n ";cprintf("* Date of Birth :: ");cout<<dob;
	cout<<"\n\n ";cprintf(" * Category :: ");cout<<cat;cout<<"\t\t\t    ";cprintf("* Area   :: ");cout<<area;
	cout<<"\n\n ";cprintf(" * Blood Group ::  ");cout<<bg;cout<<"\t\t    ";cprintf("* House :: ");cout<<hname;
	cout<<"\n\n ";cprintf(" * Student Identification :: ");cout<<ident;
	cout<<"\n\n ";cprintf(" * Contact Details >>>> ");
	cout<<"\n\n ";cprintf("      >  Address          ::   ");cout<<add;
	cout<<"\n\n ";cprintf("      >  E-mail ID        ::   ");cout<<email;
	cout<<"\n\n ";cprintf("      >  Mobile Number    ::   ");cout<<mob;
}


void stucursta(int n)
{   int flag=0;
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{       cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);
		cprintf("Sorry!!!");textcolor(RED);
		cout<<"\n\n\t\t";
		cprintf("* No Record Found in File!!!");
		cout<<" \n\n\t\t";cprintf("Please Update Record....");
		 flag=1;
		 getch();
		 clrscr();
		 main_menu();

	}

	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retsrno()==n)
		{
			 st.stucur();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		{cout<<"\n\n\t\t";cprintf(" * Record not exist !!!");}

	getch();
	clrscr();
	stmenu();}



void sturesult(int n)
{   int flag=0;
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{       cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);
		cprintf("Sorry!!!");textcolor(RED);
		cout<<"\n\n\t\t";
		cprintf("* No Record Found in File!!!");
		cout<<" \n\n\t\t";cprintf("Please Update Record....");
		 flag=1;
		 getch();
		 clrscr();
		 main_menu();

	}

	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retsrno()==n)
		{
			 st.result();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		{cout<<"\n\n\t\t";cprintf(" * Record not exist !!!");}

	getch();
	clrscr();
	stmenu();}

void student :: result()
{
stu :  clrscr();int c; char ch;
   cout<<"\n\n\t";textcolor(WHITE);cprintf(" :: R E S U L T  O F  S T U D E N T :: ");cout<<name;
   cout<<"\n\n\n\t\t\t   ";textcolor(YELLOW);cprintf(" 01. CLASS - 6 ");
   cout<<"\n\n\t\t\t   ";cprintf(" 02. CLASS - 7 ");
   cout<<"\n\n\t\t\t   ";cprintf(" 03. CLASS - 8 ");
   cout<<"\n\n\t\t\t   ";cprintf(" 04. CLASS - 9 ");
   cout<<"\n\n\t\t\t   ";cprintf(" 05. CLASS - 10");
   cout<<"\n\n\t\t\t   ";cprintf(" 06. CLASS - 11");
   cout<<"\n\n\t\t\t   ";cprintf(" 07. CLASS - 12");
   cout<<"\n\n\t\t\t   ";textcolor(3);cprintf(" 08. BACK ");
   cout<<"\n\n\t\t\t   ";textcolor(GREEN);cprintf("* Enter Your Choice :: ");
   cin>>c;
   switch(c)
   {case 1 : clrscr();outclass6();break;
    case 2 : clrscr();outclass7();break;
    case 3 : clrscr();outclass8();break;
    case 4 : clrscr();outclass9();break;
    case 5 : clrscr();outclass10();break;
    case 6 : clrscr();if(Arts=='Y')outclass11b();else if(Arts=='N')outclass11a();break;
    case 7 : clrscr();if(Arts=='Y')outclass12b();else if(Arts=='N')outclass12a();break;
    case 8 : clrscr();stmenu();
    default :clrscr(); 	cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			stmenu();
			else if(ch=='y'||ch=='Y')
			 goto stu;}
}



void student::show_tabular()
{  if(Class==6)
     {	cout<<sr_no;
	cout<<setw(7)<<rollno[0];
	textcolor(3);
	cout<<setw(18)<<name;
	textcolor(YELLOW);
	cout<<setw(7)<<marks6[0] ;
	cout<<setw(6)<<marks6[1];
	cout<<setw(6)<<marks6[2];
	cout<<setw(6)<<marks6[3];
	cout<<setw(6)<<marks6[4];
	textcolor(YELLOW);
	cout<<setw(10)<<per[0];cprintf(" %");
	cprintf("    ");cout<<grade[0]<<endl;}
   else if(Class==7)
       {
	cout<<sr_no;
	cout<<setw(7)<<rollno[1];
	textcolor(3);
	cout<<setw(18)<<name;
	textcolor(YELLOW);

	cout<<setw(7)<<marks7[0] ;
	cout<<setw(6)<<marks7[1];
	cout<<setw(6)<<marks7[2];
	cout<<setw(6)<<marks7[3];
	cout<<setw(6)<<marks7[4];
	textcolor(YELLOW);
	cout<<setw(10)<<per[1];cprintf(" %");
	cprintf("    ");cout<<grade[1]<<endl;}
	else if(Class==8)
	     {
	cout<<sr_no;
	cout<<setw(7)<<rollno[2];
	textcolor(3);
	cout<<setw(18)<<name;
	textcolor(YELLOW);

	cout<<setw(7)<<marks8[0] ;
	cout<<setw(6)<<marks8[1];
	cout<<setw(6)<<marks8[2];
	cout<<setw(6)<<marks8[3];
	cout<<setw(6)<<marks8[4];
	textcolor(YELLOW);
	cout<<setw(10)<<per[2];cprintf(" %");
	cprintf("    ");cout<<grade[2]<<endl;}
       else if(Class==9)
	  {
	cout<<sr_no;
	cout<<setw(7)<<rollno[3];
	textcolor(3);
	cout<<setw(18)<<name;
	textcolor(YELLOW);

	cout<<setw(7)<<marks9[0] ;
	cout<<setw(6)<<marks9[1];
	cout<<setw(6)<<marks9[2];
	cout<<setw(6)<<marks9[3];
	cout<<setw(6)<<marks9[4];
	textcolor(YELLOW);
	cout<<setw(10)<<per[3];cprintf(" %");
	cprintf("    ");cout<<grade[3]<<endl;}
	else if(Class==10)
       {
	cout<<sr_no;
	cout<<setw(7)<<rollno[4];
	textcolor(3);
	cout<<setw(18)<<name;
	textcolor(YELLOW);

	cout<<setw(7)<<marks10[0] ;
	cout<<setw(6)<<marks10[1];
	cout<<setw(6)<<marks10[2];
	cout<<setw(6)<<marks10[3];
	cout<<setw(6)<<marks10[4];
	textcolor(YELLOW);
	cout<<setw(10)<<per[4];cprintf(" %");
	cprintf("    ");cout<<grade[4]<<endl;}
	else if(Class==11)
       {
	cout<<sr_no;
	cout<<setw(7)<<rollno[5];
	textcolor(3);
	cout<<setw(18)<<name;
	textcolor(YELLOW);


	cout<<setw(7)<<marks11[0] ;
	cout<<setw(6)<<marks11[1];
	cout<<setw(6)<<marks11[2];
	cout<<setw(6)<<marks11[3];
	cout<<setw(6)<<marks11[4];
	textcolor(YELLOW);
	cout<<setw(10)<<per[5];cprintf(" %");
	cprintf("    ");cout<<grade[5]<<endl;}
	else if(Class==12)
     {	cout<<sr_no;
	cout<<setw(7)<<rollno[6];
	textcolor(3);
	cout<<setw(18)<<name;
	textcolor(YELLOW);

	cout<<setw(7)<<marks12[0] ;
	cout<<setw(6)<<marks12[1];
	cout<<setw(6)<<marks12[2];
	cout<<setw(6)<<marks12[3];
	cout<<setw(6)<<marks12[4];
	textcolor(YELLOW);
	cout<<setw(10)<<per[6];cprintf(" %");
	cprintf("    ");cout<<grade[6]<<endl;}


}
void student::show_tabulardt()
{       cout<<"\n";
	cout<<sr_no;
	textcolor(3);
	cout<<setw(18)<<name;
	cout<<setw(20)<<f_name ;
	cout<<setw(22)<<m_name;
	textcolor(YELLOW);
	cout<<setw(15)<<mob;

}

int student::retsrno()
{
      return sr_no;
}




//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************
 void main()
 {    textbackground(BLACK);
      textcolor(YELLOW);  intro();
       main_menu();
       getch();
 }
//***************************************************************
//    	THE MAIN MENU FUNCTION OF PROGRAM
//****************************************************************
void main_menu()
{        textcolor(YELLOW);

	char sh;int ch;
	ifstream fin;
	fin.open("pass.dat",ios::in);
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); // program outputs decimal number to two decimal places
	clrscr();
    for(int i=0;i<3;i++)
     {

     do
	{                		clrscr();
		cout<<"\n";textcolor(RED);cprintf("********************* JAWAHAR NAVODAYA VIDYAYLAYA JASWANTPURA ******************");cout<<"\n\n\n";
		cout<<"\t\t\t";textcolor(WHITE);cprintf(":: M A I N   M E N U ::");cout<<"\n\n";textcolor(YELLOW);
		cout<<"\t\t\t";cprintf("01. CLASS MENU ");cout<<"\n\n";
		cout<<"\t\t\t";cprintf("02. ENTRY/EDIT MENU");cout<<"\n\n";
		cout<<"\t\t\t";cprintf("03. STAFF'S MENU "); cout<<"\n\n";
		cout<<"\t\t\t";cprintf("04. HOUSE DETAILS "); cout<<"\n\n";
		cout<<"\t\t\t";cprintf("05. PASSWORD MENU");  cout<<"\n\n";
		cout<<"\t\t\t";textcolor(3);cprintf("06. EXIT");cout<<"\n\n";
		cout<<"\t\t\t";textcolor(GREEN);cprintf("* Please Select Your Option (1-6) ::  ");
		cin>>ch;
		char passp[10];

		clrscr();
		switch(ch)
		{

			case 1: result();break;
			case 2:{
					use:  char ch;

					     {
					       clrscr();
					       cout<<"\n\n\n\t\t";textcolor(WHITE+BLINK);cprintf("!!!!  OPTION IS PROTECTED WITH PASSWORD !!!! ");
					      cout<<"\n\n\n\n\n\n\t\t";textcolor(YELLOW);cprintf(" * Enter the Password to Proceed :: ");
					      pass2=getpass("********");
					      fin.getline(passp,8);
					      if(strcmp(pass2,passp)!=0)
					      {
						 clrscr();


						     cout<<" \n\n\n\n\n\n\n\t\t\t ";textcolor(RED+128);cprintf("!!!!!! ACCESS DENIED !!!!!!     ");
						      delay(3000);
						      textcolor(YELLOW);
						      continue;
							  }
					     else
					    {      fin.close();
						   clrscr();
						   cout<< "\n\n\n\n\n\n\n\n\t\t\t";textcolor(YELLOW+BLINK);cprintf("*** !!!! ACCESS SUCCESSFUL !!!! ***");cout<<"\n\n " ;
						   delay(2000);
						   textcolor(YELLOW);
						   clrscr();
						  entry_menu();

					     }


					    fin.close(); break;

			case 3: staff_menu();break;
			case 4: housedetail();break;
			case 5: mainpass();break;
			case 6: cout<<"\n\n\n\n\n\n\t\t\t";textcolor(YELLOW+BLINK);cprintf(" THANK YOU.... !!!!!!!!");
				  delay(2000);
				  exit(0);
			default :cout<<"\n\n\n\n\n\n\n\n\t\t";cprintf("!!!! Please enter the correct choice !!!! ");
				 cout<<"\n\n\t\t\t";cprintf("Want to Re-Type Choice(Y/N) ::  ");
				cin>>sh; }}
		if(sh=='n'||sh=='N')
		    main_menu();
					 }
	     }while(sh=='Y'||sh=='y');}
	       if (i==3)
						      {
						      fin.close();
						       sound(1000);
						       delay(10000);
						       clrscr();
						       cout<<"\n\n\n\n\n\n\n\t\t\t";cprintf("!!!! SECURITY SYSTEM ALERTED !!!! ");
						       delay(1000);
						       exit(0);
						       }
}

void stmenu()
{stu :  clrscr();
   int c,n;char ch;
     cout<<"\n";textcolor(WHITE);cout<<"\n\n\t";cprintf("::  S T U D E N T    M E N U   :: ");
     cout<<"\n\n\n\t";textcolor(YELLOW);cprintf(" 01.ACCESS STUDENT RECORD ");
     cout<<"\n\n\t";textcolor(3);cprintf(" 02.BACK TO MAIN MENU ");
     cout<<"\n\n\t";textcolor(GREEN);cprintf(" * Enter Your Choice :: ");
     cin>>c;
     switch(c)
     {
       case 1 : clrscr();textcolor(YELLOW);cout<<"\n\n\n\t\t";cprintf(" * Sr.No. Of Student :: ");cin>>n;
		disstu(n);break;
       case 2 : clrscr();main_menu();break;
       default :clrscr();cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			 goto stu;
  }}


  void disstu(int n)
  {
     stu : clrscr();
     int sh;char ch;
     cout<<"\n\n\t";textcolor(WHITE);cprintf("::  D E T A I L   O P T I O N  :: ");
     cout<<"\n\n\t";textcolor(YELLOW);cprintf(" 01. Personal Details ");cout<<"\n";
     cout<<"\n\t";cprintf(" 02. Result Details ");
     cout<<"\n\n\t";cprintf(" 03. Current Status ");
     cout<<"\n\n\t";textcolor(3);cprintf(" 04. Back to Menu ");
     cout<<"\n\n\t";textcolor(GREEN);cprintf(" * Enter Your Choice :: ");
     cin>>sh;
     switch(sh)
     {
	case 1 : clrscr();display_sp(n);break;
	case 2 : clrscr();sturesult(n);break;
	case 3 : clrscr();stucursta(n);break;
	case 4 : clrscr();stmenu();break;
	default:      re: clrscr();cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			 goto stu;
			 else
			      goto re;


}
 }

//***************************************************************
//    	function to write in file
//****************************************************************

void  write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write((char *) &st, sizeof(student));
	outFile.close();
	clrscr();
	cout<<"\n\n\n\n\n\n\t\t";textcolor(YELLOW);cprintf(" !!!! Student record Has Been Created !!! ");
	getch();
	entry_menu();
}




//***************************************************************
//    	function to read specific record from file
//****************************************************************

void  display_sp (int n)
{       int flag=0;
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
			cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		 flag=1;
		 getch();
		 clrscr();
		 stmenu();

	}

	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retsrno()==n)
		{
			 st.showdata();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		{cout<<"\n\n\t\t";cprintf(" * Record not exist !!!");}

	getch();
	clrscr();
	stmenu();
}
void display_dp(int n,int Class)
{       int flag=0;char c;
	student st;
	ifstream inFile;

	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
			cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		 flag=1;
		 getch();
		 clrscr();
		 main_menu();

	}

	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retsrno()==n)
		{ flag=1;
		  if(Class==6)st.outclass6();
		  if(Class==7)st.outclass7();
		  if(Class==8)st.outclass8();
		  if(Class==9)st.outclass9();
		  if(Class==10)st.outclass10();
		  if(Class==11)
		    {
		      cout<<"\n\n\t";cprintf(" Is student of Science ??(Y/N) :: ");cin>>c;
		      if(c=='y'||c=='Y')st.outclass11a();
		      else st.outclass11b();
		      }
		  if(Class==12)
		    {
		       cout<<"\n\n\t";cprintf(" Is student of Science ??(Y/N) :: ");cin>>c;
		       if(c=='y'||c=='Y')st.outclass12a();
		       else st.outclass12b();
		       }

		}
	}
	inFile.close();
	if(flag==0)
	 {	cout<<"\n\n\t\t";cprintf(" * Record not exist !!!");}

	getch();
	clrscr();


}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_student(int n)
{
	int found=0;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
				cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		getch();
		return;
	}

	while(File.read((char *) &st, sizeof(student)) && found==0)
	{
		if(st.retsrno()==n)
		{     char sh;
		    st.showdata();
		    cout<<"\n";cprintf(" >>>> Want To Change Record(Y/N) :: ");
		    cin>>sh;
		    if(sh=='y'||sh=='Y')
		   { clrscr();
		    cout<<"\n\n\t\t";cprintf(" <<< Please Enter The New Details of student >>>");cout<<endl;
		    st.getdata();
		    int pos=(-1)*sizeof(st);
		    File.seekp(pos,ios::cur);
		    File.write((char *) &st, sizeof(student));
		    cout<<"\n\n\t";cprintf("* Record Updated !!!");
		    found=1;}
		   else
		      entry_menu();
		}
	}
	File.close();
	if(found==0)
		{cout<<"\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Record Not Found !!!! ");   }
	getch();
	entry_menu();
}


//***************************************************************
//    	function to display all students grade report
//****************************************************************

void class_result()
{     int sh,ch;char c,sc;
      cout<<"\n\n\n\t";cprintf("* Enter The Class :: ");
       cin>>sh;
       cout<<"\n\n\t";cprintf("* Enter the Session of Class :: ");
       cin>>ch;
       if(sh==11||sh==12)
	  { cout<<" Is Students Of Science(Y/N) ???  :: ";
	   cin>>c;if(c=='y'||c=='Y')sc='Y';
	  }
	textcolor(YELLOW);
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{   		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		getch();
		clrscr();
		main_menu();
	}
	if(sh==11||sh==12)
      {	if(sc=='Y')
       {  clrscr();
	cout<<"\n\n\t\t\t     ";cprintf("ALL STUDENTS RESULT");cout<<"\n\n";
	cprintf("================================================================================");cout<<"\n";
	cprintf("Sr.No  R.No       Name            E     CS     P     C     M     %age     Grade");cout<<endl;
	cprintf("================================================================================");cout<<"\n";}
	else
	 { clrscr();
	 cout<<"\n\n\t\t\t     ";cprintf("ALL STUDENTS RESULT");cout<<"\n\n";
	cprintf("================================================================================");cout<<"\n";
	cprintf("Sr.No  R.No       Name            E     G     Hi     H     EC     %age     Grade");cout<<endl;
	cprintf("================================================================================");cout<<"\n";} }

       else
       { clrscr(); cout<<"\n\n\t\t\t     ";cprintf("ALL STUDENTS RESULT");cout<<"\n\n";
	cprintf("================================================================================");cout<<"\n";
	cprintf("Sr.No  R.No       Name            E     SS     S    H      M     %age     Grade");cout<<endl;
	cprintf("================================================================================");cout<<"\n";}

	textcolor(YELLOW);
	while(inFile.read((char *) &st, sizeof(student)))
	{    if(st.Class==sh)
	    for(int i=0;i<7;++i)
	    {  if(st.session[i]==ch )
		   st.show_tabular();}
	}

	getch();
	inFile.close();
	clrscr();
	result();
}

//***************************************************************
//    	function to display result menu
//****************************************************************

void result()
{
	char ch,sh;
	int rno,Class;
      do{	cout<<"\n\n\n\t";textcolor(WHITE);cprintf(":: R E S U L T  M E N U ::");textcolor(YELLOW);
	cout<<"\n\n\n\t";cprintf("1. Class Result");
	cout<<"\n\n\t";cprintf("2. Student Report Card");
	cout<<"\n\n\t";textcolor(3);cprintf("3. Back to Main Menu");
	cout<<"\n\n\n\t";textcolor(GREEN);cprintf("* Enter Choice (1/2/3) ::  ");
	cin>>ch;
	clrscr();
	switch(ch)
	{
	case '1' :	class_result(); break;
	case '2' :	cout<<"\n\n\t";textcolor(YELLOW);cprintf("* Enter Sr. Number Of Student :: "); cin>>rno;
			cout<<"\n\n\t";cprintf("* For Which Class You Requires Report Card :: ");cin>>Class;
			display_dp(rno,Class); break;
	case '3' :	main_menu();break;
	default:        clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>sh;
			if(sh=='n'||sh=='N')
			main_menu();  }
	     }while(sh=='Y'||sh=='y');
	}


//***************************************************************
//              	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{  nosound();
  clrscr();
  textcolor(YELLOW);
  cout<<"\n\n\n\n\n\n\t\t\t\t ";delay(500);cprintf(" A PROGRAM FOR ");
  cout<<"\n\n\t\t\t       ";delay(500);cprintf("BETTER SCHOOL SYSTEM");
  cout<<"\n\n\t\t\t        ";delay(500);cprintf("MANAGE DATA EASILY ");textcolor(GREEN);
  cout<<"\n\n\t\t\t   ";delay(500);cprintf(" DEVELOPED BY : TUSHAR DAVE ");
  cout<<"\n\n\t\t\t   ";delay(500);cprintf(" GUIDED BY : MR.B.S.YADAV");
  cout<<"\n\n\t\t\t       ";textcolor(RED);delay(500);cprintf(" NVS  JAIPUR REGION    ");
  cout<<"\n\n\t\t      ";delay(500);cprintf("JAWAHAR NAVODAYA VIDYALAYA JASWANTPURA ");
  delay(2000);


}

//***************************************************************
//    	ENTRY / EDIT MENU FUNCTION
//****************************************************************

void entry_menu()
{
	char ch,sh;
	int num;
	clrscr();
      do{ int sno;
	cout<<"\n\n\n\t";textcolor(WHITE);cprintf(":: E N T R Y   M E N U ::");
	cout<<"\n\n\t";textcolor(YELLOW);cprintf("1. STUDENT MENU ");
	cout<<"\n\n\t";cprintf("2.CREATE STUDENT RECORD ");
	cout<<"\n\n\t";cprintf("3.SEARCH STUDENT RECORD ");
	cout<<"\n\n\t";cprintf("4.MODIFY STUDENT RECORD");
	cout<<"\n\n\t";textcolor(3);cprintf("5.BACK TO MAIN MENU");
	cout<<"\n\n\t";textcolor(GREEN);cprintf("* Please Enter Your Choice (1-5) :: ");
	cin>>ch;
	clrscr();
	switch(ch)
	{
	case '2':	write_student(); break;
	case '1':     stmenu();break;
	case '3':     clrscr();
		      search();break;
	case '4':	cout<<"\n\n\t";textcolor(YELLOW);cprintf("Please Enter The Sr.No. of Student:: "); cin>>num;
			       textcolor(YELLOW);  modify_student(num);break;
	case '5':       main_menu();break;
	default:        clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>sh;
			if(sh=='n'||sh=='N')
			main_menu();
	}
	     }while(sh=='Y'||sh=='y');

	}


void chpass()
 {  char ch,passp[10];
   ifstream fin;
   ofstream fout;
   fin.open("pass.dat",ios::in);
  fout.open("pass.dat",ios::out);
   if(!fin)
   {
   pamen:
    clrscr();
    cout<<" \n\n";textcolor(YELLOW);printf(" * Enter New password (MAX.8 Character) ::  ");
    gets(pass);
    cout<<"\n\n ";cprintf(" * Re-type password ::  ");
    gets(pass1);
    if(strcmp(pass,pass1)!=0)
    {
    cout<<" \n\n";textcolor(RED+BLINK);printf("Password does not match\n\n ");
    cout<<" \n\n";textcolor(RED);cprintf("Want to Re-Type Password (Y/N) ::  ");
    cin>>ch;
    if(ch=='y'||ch=='Y')
	goto pamen;
    else
       mainpass(); }
   else
    {  strcpy(passp,pass1);
	fout<<passp;
    cout<< "\n\n\n\n\t\t ";textcolor(YELLOW);cprintf(" *** !!!!! Successfully Uploaded !!!!! ***");cout<<"\n\n " ;}
		fin.close();
		fout.close();
		getch();
		main_menu();
	}
   else
  {fin.seekg(0);
  cout<<"\n\n\t\t";textcolor(WHITE);cprintf(":: P A S S  W O R D  C H A N G I N G  M E N U ::");cout<<"\n\n\n ";
  cout<<"\n\n\n\t\t";textcolor(YELLOW);cprintf(" * Enter Current Password ::  ");
  passcur=getpass("********");
  fin.getline(passp,8,'\n');
  do{
     if(strcmp(passcur,passp)==0)
      {
    clrscr();
    cout<<"\n\n";textcolor(YELLOW);cprintf("* Enter New password (MAX. 8 Character) ::  ");
    gets(pass);
    cout<<"\n\n";cprintf(" * Re-type password ::  ");
    gets(pass1);
    if(strcmp(pass,pass1)!=0)
    {   fin.close();
    cout<<" \n\n\t\t";textcolor(RED+BLINK);cprintf(" Password Not Match !!!!!");cout<<" \n\n " ;
    delay(2000);
    chpass();
     }
     else
     {  strcpy(passp,pass1);
	fout<<passp;
	fin.close();
	fout.close();
	clrscr();
	cout<<"\n\n\n\n\n\n\n\t\t";textcolor(YELLOW);cprintf("  *** !!!! Successfully Uploaded !!!! ***");cout<<"\n\n ";
	delay(2000);
	 main_menu() ;}}
 else
     { clrscr();
      cout<<"\n\n\n\n\n\n\n\n\n";textcolor(RED+BLINK);cprintf(" ***** !!!! Password Does Not Match With Your Current Password !!!! *****");
      delay(3000);
      main_menu();}
     }while(ch=='y'||ch=='Y'); }

}

 void mainpass()
{ clrscr();
  char sh;
   int choice;
  do{
   clrscr();
	 cout<<"\n\n\t\t\t";textcolor(WHITE);cprintf(":: P A S S W O R D  M E N U :: ");cout<<"\n\n ";
	 cout<<"\n\n\t\t";textcolor(YELLOW);cprintf("1. Set New Password ");
	 cout<<"\n\n\t\t";textcolor(3);cprintf("2. Back To Main Menu ");
	 cout<<"\n\n\t\t";textcolor(GREEN);cprintf("* Enter Your Choice ::  ");
	 cin>>choice;
	 switch(choice)
	 {
	  case 1 : clrscr();chpass();break;
	  case 2 : clrscr();main_menu();break;
	 default :  clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>sh;
			if(sh=='n'||sh=='N')
			main_menu();
	}
	     }while(sh=='Y'||sh=='y');
}

void staff_menu()
{  clrscr();
int choice; char ch,sn[50];
  staff:
  cout<<"\n\n\n\t\t\t";textcolor(WHITE);cprintf(":: S T A F F 'S  M E N U :: ");
  cout<<"\n\n\n\n\n\t\t\t";textcolor(YELLOW);cprintf(" 01. Staff Information ");
  cout<<"\n\n\t\t\t";cprintf(" 02. View Staff ");
  cout<<"\n\n\t\t\t";cprintf(" 03. Add Staff ");
  cout<<"\n\n\t\t\t";cprintf(" 04. Modify Staff Record ");
  cout<<"\n\n\t\t\t";textcolor(3);cprintf(" 05. Back to Main Menu ");
  cout<<"\n\n\t\t\t";textcolor(GREEN);cprintf(" * Please Enter Your Choice :: ");
  cin>> choice;
  switch(choice)
  {
  case 1 :clrscr(); showstaff(); break;
  case 2 :clrscr(); textcolor(YELLOW);cout<<"\n\n\n";cprintf(" * Name Of Staff Member  ");cout<<" :: ";gets(sn); viewstaff(sn);break;
  case 3 :clrscr(); addstaff(); break;
  case 4 :clrscr(); textcolor(YELLOW);cout<<"\n\n\n";cprintf(" * Name Of Staff Member Whose Record to Be Modified ");cout<<"\n\n\t\t\t :: ";gets(sn);modify_staff(sn);break;
  case 5 :clrscr(); main_menu(); break;
  default : clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			 goto staff;
  }}
  void addstaff()
  {  	staff st;
	ofstream outFile;
	outFile.open("staff.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write((char *) &st, sizeof(st));
	outFile.close();
	clrscr();
	cout<<"\n\n\n\n\n\n\t";textcolor(YELLOW);cprintf(" !!!! Staff record Has Been Created !!! ");
	getch();
	textcolor(YELLOW);
	clrscr();
	staff_menu();

  }
void viewstaff(char n[])
{
	int found=0;
	staff st;
	fstream File;
	File.open("staff.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\n\n\t";textcolor(RED+BLINK);cprintf("* No Record Found In File !! Please Update Reocrd...");

		getch();
		return;
	}
	 File.seekg(0);
	while(File.read((char *) &st, sizeof(staff)) && found==0)
	{
		if(strcmpi(st.name,n)==0)
		{     char sh;
		    clrscr();found=1;
		    st.showdata();

				    }
    File.close();
	if(found==0)
	{		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");}
	getch();
	clrscr();
	staff_menu();

}  }

void modify_staff(char n[])
{
	int found=0;
	staff st;
	fstream File;
	File.open("staff.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
			cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");

		getch();
		return;
	}
	 File.seekg(0);
	while(File.read((char *) &st, sizeof(staff)) && found==0)
	{
		if(strcmpi(st.name,n)==0)
		{     char sh;
		    clrscr();
		    st.showdata();
		    cout<<"\n\n\t\t";cprintf(" >>>> Want To Change Record(Y/N) :: ");
		    cin>>sh;
		    if(sh=='y'||sh=='Y')
		   { clrscr();
		    cout<<"\n\n\t\t";cprintf(" <<< Please Enter The New Details of Staff >>>");cout<<endl;
		    st.getdata();
		    int pos=(-1)*sizeof(st);
		    File.seekp(pos,ios::cur);
		    File.write((char *) &st, sizeof(staff));
		    cout<<"\n\n\t\t";cprintf("* Record Updated !!!");
		    found=1;}
		   else
		      staff_menu();
		}
	}
	File.close();
	if(found==0)
		{		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");   }
	getch();
	clrscr();
	staff_menu();
}
void housedetail()
{ house:
 clrscr();
  int cho;char ch;
  textcolor(WHITE);cout<<"\n\n\n\t\t     ";cprintf(":: H O U S E  D E T A I L S  M E N U ::");
  cout<<"\n\n\n\n\n\t\t";textcolor(BLUE);cprintf("01. Arawali Senior ");
  cout<<"\t\t";cprintf("02. Arawali Junior ");
  cout<<"\n\n\t\t";textcolor(YELLOW);cprintf("03. Nilgiri Senior ");
  cout<<"\t\t";cprintf("04. Nilgiri Junior ");
  cout<<"\n\n\t\t";textcolor(RED);cprintf("05. Shiwalik Senior ");
  cout<<"\t\t";cprintf("06. Shiwalik Junior ");
  cout<<"\n\n\t\t";textcolor(YELLOW);cprintf("07. Udaigiri Senior ");
  cout<<"\t\t";cprintf("08. Udaigiri Junior ");
  cout<<"\n\n\n\t\t\t ";textcolor(3);cprintf(" 09. Back to Main Menu ");
  cout<<"\n\n\t\t\t";textcolor(GREEN);cprintf("  * Please Enter the Choice :: ");
  cin>>cho;
  switch(cho)
  {
   case 1 : clrscr();arsr();break;
   case 2 : clrscr();arjr();break;
   case 3 : clrscr();nsr();break;
   case 4 : clrscr();njsr();break;
   case 5 : clrscr();ssr();break;
   case 6 : clrscr();sjsr();break;
   case 7 : clrscr();usr();break;
   case 8 : clrscr();ujsr();break;
   case 9 : clrscr();main_menu();break;
   default :wr: clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			     goto house;
			     else
				goto wr;
} }
void arsr()
{
  int cho;char ch;
 ahouse:
  textcolor(WHITE); cout<<"\n\n\n\t\t   ";cprintf(" :: A R A W A L I   S E N I O R   H O U S E :: ");
  cout<<"\n\n\n\n\t\t\t";textcolor(YELLOW);cprintf("01. Students Details ");
  cout<<"\n\n\t\t\t";textcolor(3);cprintf("02. Back ");
  cout<<"\n\n\n\t\t";textcolor(GREEN);cprintf("*  Please enter Your Choice :: ");
  cin>>cho;
 switch(cho)
  {
     case 1 :astu();break;
     case 2 :housedetail(); break;
     default :  wr: clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			     goto ahouse;
			     else
				goto wr;
      }
}

 void astu()
 { textcolor(YELLOW);
 clrscr();
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{     		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		getch();
		clrscr();
		housedetail();
	}
	cout<<"\n\n\t\t\t";cprintf("ALL STUDENTS  OF ARAWALI SENIOR ");cout<<"\n\n";
	cprintf("================================================================================\n");
	cprintf("Sr.No       Name           Father's Name          Mother's Name        Contact ");cout<<endl;
	cprintf("================================================================================\n");
	textcolor(YELLOW);
	while(inFile.read((char *) &st, sizeof(student)))
	{       if(strcmpi(st.hname,"Arawali Senior")==0)
			    st.show_tabulardt();
	}

	getch();
	inFile.close();
	clrscr();
	housedetail();

 }
 void arjr()
{
  int cho;char ch;
  ahouse: textcolor(WHITE); cout<<"\n\n\n\t\t   ";cprintf(" :: A R A W A L I   J U N I O R   H O U S E :: ");

  cout<<"\n\n\n\n\t\t\t";textcolor(YELLOW);cprintf("01. Students Details ");
  cout<<"\n\n\t\t\t";textcolor(3);cprintf("02. Back ");
  cout<<"\n\n\n\t\t";textcolor(GREEN);cprintf("*  Please enter Your Choice :: ");
  cin>>cho;
  switch(cho)
  {
     case 1 : ajstu();    break;
     case 2 : housedetail(); break;
     default :  wr: clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			     goto ahouse;
			     else
				goto wr;
      }
}

 void ajstu()
 { textcolor(YELLOW);
 clrscr();
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{     		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		getch();
		clrscr();
		housedetail();
	}
	cout<<"\n\n\t\t\t";cprintf("ALL STUDENTS   OF ARAWALI JUNIOR");cout<<" \n\n";
	cprintf("================================================================================\n");
	cprintf("Sr.No       Name           Father's Name          Mother's Name        Contact ");cout<<endl;
	cprintf("================================================================================\n");

	textcolor(YELLOW);while(inFile.read((char *) &st, sizeof(student)))
	{       if(strcmpi(st.hname,"Arawali Junior")==0)
			    st.show_tabulardt();
	}

	getch();
	inFile.close();
	clrscr();
	housedetail();

 }
 void nsr()
{  textcolor(YELLOW);
  int cho;char ch;
  ahouse: textcolor(WHITE); cout<<"\n\n\n\t\t   ";cprintf(" :: N I L G I R I   S E N I O R   H O U S E :: ");
  cout<<"\n\n\n\n\t\t\t";textcolor(YELLOW);cprintf("01. Students Details ");
  cout<<"\n\n\t\t\t";textcolor(3);cprintf("02. Back ");
  cout<<"\n\n\n\t\t";textcolor(GREEN);cprintf("*  Please enter Your Choice :: ");
  cin>>cho;
  switch(cho)
  {
     case 1 : nstu();    break;
     case 2 : housedetail(); break;
     default :  wr: clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			     goto ahouse;
			     else
				goto wr;
      }
}

 void nstu()
 { clrscr();textcolor(YELLOW);
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{     		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		getch();
		clrscr();
		housedetail();
	}
	cout<<"\n\n\t\t";cprintf(" ALL STUDENTS  OF NILGIRI SENIOR");cout<<" \n\n";
	cprintf("================================================================================\n");
	cprintf("Sr.No       Name           Father's Name          Mother's Name        Contact ");cout<<endl;
	cprintf("================================================================================\n");
	textcolor(YELLOW);
	while(inFile.read((char *) &st, sizeof(student)))
	{       if(strcmpi(st.hname,"Nilgiri Senior")==0)
			    st.show_tabulardt();
	}

	getch();
	inFile.close();
	clrscr();
	housedetail();

 }
  void njsr()
{
  int cho;char ch;
  ahouse: textcolor(WHITE); cout<<"\n\n\n\t\t   ";cprintf(" :: N I L G I R I   J U N I O R   H O U S E :: ");
  cout<<"\n\n\n\n\t\t\t";textcolor(YELLOW);cprintf("01. Students Details ");
  cout<<"\n\n\t\t\t";textcolor(3);cprintf("02. Back ");
  cout<<"\n\n\n\t\t";textcolor(GREEN);cprintf("*  Please enter Your Choice :: ");
  cin>>cho;
  switch(cho)
  {

     case 1 : njstu();    break;
     case 2 : housedetail(); break;
     default :  wr: clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			     goto ahouse;
			     else
				goto wr;
      }
}

 void njstu()
 { clrscr();textcolor(YELLOW);
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{     		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		getch();
		clrscr();
		housedetail();
	}
	cout<<"\n\n\t\t";cprintf("  ALL STUDENTS  OF NILGIRI JUNIOR ");cout<<"\n\n";
	cprintf("================================================================================\n");
	cprintf("Sr.No       Name           Father's Name          Mother's Name        Contact ");cout<<endl;
	cprintf("================================================================================\n");
	textcolor(YELLOW);
	while(inFile.read((char *) &st, sizeof(student)))
	{       if(strcmpi(st.hname,"Nilgiri Junior")==0)
			    st.show_tabulardt();
	}

	getch();
	inFile.close();
	clrscr();
	housedetail();

 }

  void ssr()
{
  int cho;char ch;
  ahouse: textcolor(WHITE); cout<<"\n\n\n\t\t   ";cprintf(" :: S H I W A L I K   S E N I O R   H O U S E :: ");
  cout<<"\n\n\n\n\t\t\t";textcolor(YELLOW);cprintf("01. Students Detail");
  cout<<"\n\n\t\t\t";textcolor(3);cprintf("02. Back ");
  cout<<"\n\n\t\t";textcolor(GREEN);cprintf("*  Please enter Your Choice :: ");
  cin>>cho;
  switch(cho)
  {
     case 1 : sstu();    break;
     case 2 : housedetail(); break;
     default :  wr: clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			     goto ahouse;
			     else
				goto wr;
      }
}


 void sstu()
 { clrscr();textcolor(YELLOW);
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{    		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		getch();
		clrscr();
		housedetail();
	}
	cout<<"\n\n\t\t";cprintf("     ALL STUDENTS OF SHIWALIK SENIOR");cout<<" \n\n";
	cprintf("================================================================================\n");
	cprintf("Sr.No       Name           Father's Name          Mother's Name        Contact ");cout<<endl;
	cprintf("================================================================================\n");
	textcolor(YELLOW);
	while(inFile.read((char *) &st, sizeof(student)))
	{       if(strcmpi(st.hname,"Shiwalik Senior")==0)
			    st.show_tabulardt();
	}

	getch();
	inFile.close();
	clrscr();
	housedetail();

 }
  void sjsr()
{
  int cho;char ch;
  ahouse: textcolor(WHITE); cout<<"\n\n\n\t\t   ";cprintf(" :: S H I W A L I K   J U N I O R   H O U S E :: ");
  cout<<"\n\n\n\n\t\t\t";textcolor(YELLOW);cprintf("01. Students Details ");
  cout<<"\n\n\t\t\t";textcolor(3);cprintf("02. Back ");
  cout<<"\n\n\n\t\t";textcolor(GREEN);cprintf("*  Please enter Your Choice :: ");
  cin>>cho;
  switch(cho)
  {
     case 1 : sjstu();    break;
     case 2 : housedetail(); break;
     default :  wr: clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			     goto ahouse;
			     else
				goto wr;
      }
}

 void sjstu()
 { clrscr();textcolor(YELLOW);
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{   		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		getch();
		clrscr();
		housedetail();
	}
	cout<<"\n\n\t\t";cprintf("     ALL STUDENTS  OF SHIWALIK JUNIOR");cout<<"\n\n";
	cprintf("================================================================================\n");
	cprintf("Sr.No       Name           Father's Name          Mother's Name        Contact ");cout<<endl;
	cprintf("================================================================================\n");
	textcolor(YELLOW);
	while(inFile.read((char *) &st, sizeof(student)))
	{       if(strcmpi(st.hname,"Shiwalik Junior")==0)
			    st.show_tabulardt();
	}

	getch();
	inFile.close();
	clrscr();
	housedetail();

 }
  void usr()
{
  int cho;char ch;
  ahouse:  textcolor(WHITE); cout<<"\n\n\n\t\t   ";cprintf(" :: U D A I G I R I   S E N I O R   H O U S E :: ");
  cout<<"\n\n\n\n\t\t\t";textcolor(YELLOW);cprintf("01. Students Details ");
  cout<<"\n\n\t\t\t";textcolor(3);cprintf("02. Back ");
  cout<<"\n\n\n\t\t";textcolor(GREEN);cprintf("*  Please enter Your Choice :: ");
  cin>>cho;
  switch(cho)
  {
     case 1 : ustu();    break;
     case 2 : housedetail(); break;
     default :  wr: clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			     goto ahouse;
			     else
				goto wr;
      }
}

 void ustu()
 { clrscr();textcolor(YELLOW);
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{   		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");
		getch();
		clrscr();
		housedetail();
	}
	cout<<"\n\n\t\t ";cprintf("   ALL STUDENTS  OF UDAIGIRI SENIOR");cout<<" \n\n";
	cprintf("================================================================================\n");
	cprintf("Sr.No       Name           Father's Name          Mother's Name        Contact ");cout<<endl;
	cprintf("================================================================================\n");
	textcolor(YELLOW);
	while(inFile.read((char *) &st, sizeof(student)))
	{       if(strcmpi(st.hname,"Udaigiri Senior")==0)
			    st.show_tabulardt();
	}

	getch();
	inFile.close();
	clrscr();
	housedetail();

 }
  void ujsr()
{
  int cho;char ch;
  ahouse: textcolor(WHITE); cout<<"\n\n\n\t\t   ";cprintf(" :: U D A I G I R I   J U N I O R   H O U S E :: ");
  cout<<"\n\n\n\n\t\t\t";textcolor(YELLOW);cprintf("01. Students Details ");
  cout<<"\n\n\t\t\t";textcolor(3);cprintf("02. Back ");
  cout<<"\n\n\n\t\t";textcolor(GREEN);cprintf("*  Please enter Your Choice :: ");
  cin>>cho;
  switch(cho)
  {
     case 1 : ujstu();break;
     case 2 : housedetail(); break;
     default :  wr: clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>ch;
			if(ch=='n'||ch=='N')
			main_menu();
			else if(ch=='y'||ch=='Y')
			     goto ahouse;
			     else
				goto wr;
      }
}

 void ujstu()
 { clrscr(); textcolor(YELLOW);
	student st;
	ifstream inFile,fin;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{     		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");

		getch();
		clrscr();
		housedetail();
	}
	cout<<"\n\n\t\t\t";cprintf("ALL STUDENTS   OF UDAIGIRI JUNIOR");cout<<" \n\n";
	cprintf("================================================================================\n");
	cprintf("Sr.No       Name           Father's Name          Mother's Name        Contact ");cout<<endl;
	cprintf("================================================================================\n");
	textcolor(YELLOW);
	while(inFile.read((char *) &st, sizeof(student)))
	{       if(strcmpi(st.hname,"Udaigiri Junior")==0)
			    st.show_tabulardt();
	}

	getch();
	inFile.close();
	clrscr();
	housedetail();

 }

 void search()
 {   clrscr();


     int ch,sno;char n[50],sh;
  search:  cout<<"\n\n\n\t     ";textcolor(WHITE); cprintf(":: S T U D E N T  R E C O R D  S E A R C H I N G  M E N U ::");cout<<"\n\n\n";
     cout<<"\n\n\t\t\t";textcolor(YELLOW);cprintf("01. Using Student's Name  ");cout<<"\n\n";
     cout<<"\t\t\t";cprintf("02. Using Sr.No. ");cout<<"\n\n";
     cout<<"\t\t\t";textcolor(3);cprintf("03. Back to Menu ");cout<<"\n\n";
     cout<<"\t\t\t";textcolor(GREEN);cprintf("* Enter Your Choice :: ");
     cin>>ch;
     switch(ch)
     { case 1 : clrscr();cout<<"\n\n\n\n\t\t";textcolor(YELLOW);cprintf(" * Enter the Name of the Student :: ");
		gets(n);
		display_nm(n);
       case 2 : clrscr();cout<<"\n\n\n\n\t ";textcolor(YELLOW);cprintf("* Enter the Sr. No. of the Student :: ");
		cin>>sno;
		display_sp(sno);
       case 3 : clrscr(); entry_menu();
       default :  wr:   clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\t";textcolor(RED+BLINK);cprintf("!!!! Please enter the correct choice !!!! ");
			cout<<"\n\n\t\t\t";textcolor(RED);cprintf("Want to Re-Type Choice(Y/N) ::  ");
			cin>>sh;
			if(sh=='n'||sh=='N')
			main_menu();
			else if(sh=='y'||sh=='Y')
				       goto search;
			      else
				   goto wr;



 }}
void display_nm(char n[])
{       int flag=0;
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\t\t\t\t";textcolor(RED+BLINK);cprintf("Sorry!!!");textcolor(RED);cout<<"\n\n\t\t";cprintf("* No Record Found in File!!!");cout<<" \n\n\t\t";cprintf("Please Update Record....");

		 flag=1;
		 getch();
		 clrscr();
		 main_menu();

	}

	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(strcmpi(st.name,n)==0)
		{        flag=1;
			 st.showdata();
			 getch();
			 continue;

		}
	}
	inFile.close();
	if(flag==0)
	       {	cout<<"\n\n\t\t";textcolor(RED+BLINK);cprintf(" * Record not exist !!!"); }

	getch();
	clrscr();
	main_menu();
}






//***************************************************************
//    			END OF PROJECT
//***************************************************************

