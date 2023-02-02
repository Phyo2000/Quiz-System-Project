#include <dos.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

int wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD  result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
  }

int wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD  result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
  }
  
///////////////////////////////////////////////////////////////////

int mark=0;
void COVER();
void PRINTSTAR();
void TEACHER();
void STUDENT(); 
void ABOUT_US(); 
void ADD_QUESTION();
void VIEWALLQUESTIONS();
void EDIT_QUESTION();
void DELETE_Q();
void Take_Quiz();
void View_Score();
  
//////////////////////////////////////////////////////////////////
  
class Questions
{
	private:
		char Question_NO[3];
		char Question[200];
		char Answer_A[50];
		char Answer_B[50];
		char Answer_C[50];
		char Answer_D[50];
		char Correct_Answer;
		char ans;

	public:
		void Create()
		{
			cout<<"\n\n\n\n\n\n\n\t\t\t\tEnter Question No = ";
			gets(Question_NO);
			cout<<"\n\t\t\t\tEnter Question = ";
			cin.getline(Question,200);
			cout<<"\n\t\t\t\tEnter Answer A = ";
			cin.getline(Answer_A,50);
			cout<<"\n\t\t\t\tEnter Answer B = ";
			cin.getline(Answer_B,50);
			cout<<"\n\t\t\t\tEnter Answer C = ";
			cin.getline(Answer_C,50);
			cout<<"\n\t\t\t\tEnter Answer D = ";
			cin.getline(Answer_D,50);
			cout<<"\n\t\t\t\tEnter Correct Answer = ";
			cin>>Correct_Answer;
		}

		void Show()
		{
			cout<<setw(5)<<Question<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(A) "<<Answer_A<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(B) "<<Answer_B<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(C) "<<Answer_C<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(D) "<<Answer_D<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"Answer = "<<Correct_Answer<<endl<<endl;
		}
		
		void Quiz()
		{
			cout<<setw(5)<<Question<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(A) "<<Answer_A<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(B) "<<Answer_B<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(C) "<<Answer_C<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(D) "<<Answer_D<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"What is your answer? ";
			cin>>ans;
			while(ans != 'a' && ans !='A' && ans !='b' && ans !='B' 
				&&ans != 'c' && ans !='C' && ans !='d' && ans !='D')
			{cout<<setw(10)<<"\t\t\t\t"<<"Please Enter only A to D : ";
			cin>>ans;}
			if(Correct_Answer==ans || Correct_Answer==ans+32 || Correct_Answer==ans-32 || Correct_Answer-32==ans || Correct_Answer+32==ans)
			mark++;
		}
		
		void Edit_Q()
		{
			cin.ignore();
			gotoxy(40,13);
			cout<<"Edit Queston Text : ";
			cin.getline(Question,200); 	
		}	
		void Edit_A()
		{
			cin.ignore();
			gotoxy(40,13);
			cout<<"Edit Answer A : ";
			cin.getline(Answer_A,50); 	
		}	
		void Edit_B()
		{
			cin.ignore();
			gotoxy(40,13);
			cout<<"Edit Answer B : ";
			cin.getline(Answer_B,50); 	
		}
		void Edit_C()
		{
			cin.ignore();
			gotoxy(40,13);
			cout<<"Edit Answer C : ";
			cin.getline(Answer_C,50); 	
		}
		void Edit_D()
		{
			cin.ignore();
			gotoxy(40,13);
			cout<<"Edit Answer D : ";
			cin.getline(Answer_D,50);	
		}

		void Edit_CA()
		{
			gotoxy(40,13);
			cout<<"Edit Correct Answer : ";
			cin>>Correct_Answer;	
		}
		
		friend void gotoxy();
		friend void TEACHER();
		friend void STUDENT();
		friend void ADD_QUESTION();
		friend void VIEWALLQUESTIONS();
		friend void EDIT_QUESTION();
		friend void DELETE_Q();
		friend void Take_Quiz();
		friend void View_Score();
		friend void EXIT();
};

/////////////////////////////////////////////////////////////
Questions q;
/////////////////////////////////////////////////////////////

int main()
{
	gotoxy(40,7);
	cout<<"MINISTRY OF SCIENCE AND TECHNOLOGY"<<endl;
	gotoxy(40,9);
	cout<<"TECHNOLOGICAL UNIVERSITY  TAUNGGYI"<<endl;
	gotoxy(39,11);
	cout<<"DEPARTMENT OF INFORMATION TECHNOLOGY"<<endl;
	gotoxy(55,13);
	cout<<"QUIZZ"<<endl;
	gotoxy(48,15);
	cout<<"SECOND YEAR PROJECT"<<endl;
	gotoxy(54,17);
	cout<<"GROUP-2"<<endl;
	gotoxy(46,19);
	cout<<"2018-2019 ACADEMIC YEAR"<<endl;
	gotoxy(47,21);
	cout<<"Press Enter to START ";
	getch();
	COVER();
	return 0;
}
//////////////////////////////////////////////////////////////////
void PRINTSTAR()
{
	cout<<"\t\t\t\t  ******************************************************"<<endl;
}
//////////////////////////////////////////////////////////////////

void COVER()
{     
	system("CLS");
	int c;
  	do{
        system("CLS");
		int i;
		
   		for(i=30;i<=90;i++)
		{
			gotoxy(i,1);
			cout<<"*";
			gotoxy(i,5);
			cout<<"*";
			gotoxy(i,9);
			cout<<"*";
			gotoxy(i,13);
			cout<<"*";
		}

		for(i=2;i<=13;i++)
		{
			gotoxy(30,i);
			cout<<"*";
			gotoxy(90,i);
			cout<<"*";
		}


		for(i=5;i<=13;i++)
		{
			gotoxy(60,i);
			cout<<"*";
		}

      	gotoxy(58,3);
      	cout<<"QUIZZ ";
		gotoxy(40,7);
		cout<<"[1] TEACHER";
		gotoxy(70,7);
		cout<<"[2] STUDENT";
		gotoxy(40,11);
		cout<<"[3] ABOUT US";
		gotoxy(70,11);
		cout<<"[4] EXIT";
	 	gotoxy(30,15);
		cout<<"TYPE THE NUMBER OF OPTION : ";
      	cin>>c;
		
		switch(c)
		{
			case 1:
			{
			system("CLS");
			string id;
	 		string pwd;
	 		cout<<endl<<"\n\t\t\t\t\tEnter Your ID and Password \n\n";
			cout<<"\t\t\t\t\t\tID: ";
			cin>>id;
			cout<<"\n\n\t\t\t\t\t\tPassword: ";
			cin>>pwd;
			if(id=="1234" && pwd=="teacher")
			TEACHER();
			else
				{
				system("CLS");
				gotoxy(40,13);
				cout<<"Can Not Be Identified...!!!";
				getch();
				}
			break;
			}
			case 2:STUDENT();break;
			case 3:ABOUT_US();break;
			case 4:EXIT();break;
			default:
			system("CLS");
			gotoxy(40,13);
			cout<<"ENTER FROM 1 TO 4 PLEASE";
			gotoxy(40,15);
			cout<<"PRESS \"ENTER\" KEY TO CONTINUE...";
			getch();
		}
	}while(c!=4);
}
///////////////////////////////////////////////////////////////////

void TEACHER()
{
	system("cls");
	int num;
	cout<<endl;
	PRINTSTAR();
	cout<<"\n\t\t\t\t\t\t\t***TEACHER***"<<endl;
	cout<<"\n\t\t\t\t\t\t(1) Add Questions"<<endl;
	cout<<"\n\t\t\t\t\t\t(2) View All Questions"<<endl;
	cout<<"\n\t\t\t\t\t\t(3) Edit Questions"<<endl;
	cout<<"\n\t\t\t\t\t\t(4) Delete Questions"<<endl;
	cout<<"\n\t\t\t\t\t\t(5) Back"<<endl<<endl;
	PRINTSTAR();
	cout<<"\t\t\t\t\tType the number of option : ";
	cin>>num;
	
	switch(num)
	{
		case 1:
			system("cls");
			ADD_QUESTION();
		 	return TEACHER(); break;
		
		case 2:
		{
			system("cls");
			VIEWALLQUESTIONS(); 
			return TEACHER(); break;	
		}

		case 3: 
		{
			system("cls");
			EDIT_QUESTION(); 
			return TEACHER();break;
		}	
			
		case 4:
		system("cls");
		DELETE_Q();
		return TEACHER();
	 	break;
		
		case 5:
			system("cls");
			return COVER(); break;
			
		default:
			system("cls");
			gotoxy(40,13);
			cout<<"ENTER FROM 1 TO 5 PLEASE";
			gotoxy(40,15);
			cout<<"PRESS \"ENTER\" KEY TO CONTINUE...";
			cin.ignore();
			getch();
			return TEACHER();
		}while(num!=5);
}
////////////////////////////////////////////////////////////

void STUDENT()
{
	system("cls");
	int num;
	cout<<endl;
	PRINTSTAR();
	cout<<"\n\t\t\t\t\t\t\t***STUDENT***"<<endl;
	cout<<"\n\t\t\t\t\t\t(1) Take Quizz"<<endl;
	cout<<"\n\t\t\t\t\t\t(2) View Score"<<endl;
	cout<<"\n\t\t\t\t\t\t(3) Back"<<endl<<endl;
	PRINTSTAR();
	cout<<"\n\t\t\t\t\tType the number of option : ";
	cin>>num;
	
	switch(num)
	{
		case 1:
		{
			system("cls");
			cout<<endl<<"\n\t\t\t\t\tPress Enter if You are Ready..!";
			getch();
			system("cls");
			Take_Quiz(); break;
		}
		
		case 2: 
			system("CLS");
			View_Score(); break;
		
		case 3: 
			return COVER(); break;
				
		default:
			system("cls");
			gotoxy(40,13);
			cout<<"ENTER FROM 1 TO 3 PLEASE";
			gotoxy(40,15);
			cout<<"PRESS \"ENTER\" KEY TO CONTINUE...";
			cin.ignore();
			getch();
			return STUDENT();
	}
}
///////////////////////////////////////////////////////////

void ABOUT_US()
{
system("CLS");
gotoxy(45,11);
cout<<"SUPERVISOR : U HSAN LYNN ";
gotoxy(42,13);
cout<<"CO-SUPERVISOR :  "<<endl;
getch();

system("CLS");
gotoxy(50,2);
cout<<"PROJECT MEMBERS";
gotoxy(35,4);
cout<<setw(3)<<"NO."<<setw(10)<<"  ROLL NO."<<setw(22)<<"  STUDENT NAME         "<<setw(8)<<"     REMARK"<<endl;
gotoxy(35,6);
cout<<setw(3)<<"1."<<setw(10)<<"2IT- 2 "<<setw(22)<<"  Mg Phyo Aung Zay        "<<setw(8)<<"LEADER"<<endl;
gotoxy(35,7);
cout<<setw(3)<<"2."<<setw(10)<<"2IT- 4 "<<setw(22)<<"  Ma Soe May Aung         "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,8);
cout<<setw(3)<<"3."<<setw(10)<<"2IT- 6 "<<setw(22)<<"  Ma Hla Bwe Yue          "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,9);
cout<<setw(3)<<"4."<<setw(10)<<"2IT- 8 "<<setw(22)<<"  Ma Aye Theingi          "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,10);
cout<<setw(3)<<"5."<<setw(10)<<"2IT-10 "<<setw(22)<<"  Mg Tin Min Lwin         "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,11);
cout<<setw(3)<<"6."<<setw(10)<<"2IT-12 "<<setw(22)<<"  Mg Thaw Lin Tun         "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,12);
cout<<setw(3)<<"7."<<setw(10)<<"2IT-14 "<<setw(22)<<"  Mg Ent Moe Lwin         "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,13);
cout<<setw(3)<<"8."<<setw(10)<<"2IT-16 "<<setw(22)<<"  Mg La Min Htet Aung     "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,14);
cout<<setw(3)<<"9."<<setw(10)<<"2IT-18 "<<setw(22)<<"  Mg Zaw Lin Htet Naing   "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,15);
cout<<setw(3)<<"10."<<setw(10)<<"2IT-20 "<<setw(22)<<"  Ma Pyae Phyo Thiri Kyaw "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,16);
cout<<setw(3)<<"11."<<setw(10)<<"2IT-22 "<<setw(22)<<"  Mg Ngwe Kabar Phyo      "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,17);
cout<<setw(3)<<"12."<<setw(10)<<"2IT-24 "<<setw(22)<<"  Mg Nyan Soe Aung        "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,18);
cout<<setw(3)<<"13."<<setw(10)<<"2IT-26 "<<setw(22)<<"  Mg Shin Thant Maung     "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,19);
cout<<setw(3)<<"14."<<setw(10)<<"2IT-28 "<<setw(22)<<"  Mg Wai Yan Hein         "<<setw(8)<<"MEMBER"<<endl;
gotoxy(35,20);
cout<<setw(3)<<"15."<<setw(10)<<"2IT-30 "<<setw(22)<<"  Mg Khant Si Thu         "<<setw(8)<<"MEMBER"<<endl;
getch();
}

//////////////////////////////////////////////////////////

void EXIT()
{
	system("cls");
	cout<<endl;
	PRINTSTAR();
	cout<<endl;
	cout<<"\t\t\t\t\t\t   Goodbye, Thank you!"<<endl;
	cout<<endl;
	PRINTSTAR();
	cout<<endl;
	gotoxy(34,8);
	exit(0);
}
///////////////////////////////////////////////////////////

void ADD_QUESTION()
{
	system("CLS");
	char c;
	do
	{
	system("CLS");
	cin.ignore();
	q.Create();
	ofstream out("questions.dat",ios::app);
	if(!out)cout<<"cannot open the user dat file.\n";
	out.write((char*) &q,sizeof(Questions));
	cout<<"\n\t\tDo You Want To Add More Questions (y/n?) = ";
	cin>>c;
	out.close();
	}while(c=='y'||c=='Y');
}
//////////////////////////////////////////////////////////

void VIEWALLQUESTIONS()
{
	system("CLS");
	int No=0;
	ifstream in("questions.dat");
	if(!in)
	{
	gotoxy(40,13);
	cout<<"Question not Found.......!!!!!!!!!";
	gotoxy(40,15);
	cout<<"Press Enter to continue...";
	getch();
	return TEACHER();
	}

	else
	{
		cout<<"\n\n\t\t\t\t\t\tQuestions Lists\n";
		cout<<endl;
		while(in.read((char*)&q,sizeof(Questions)))
		{
		cout<<"\t\t\t\t"<<setw(3)<<++No<<". ";
		q.Show();
		cout<<endl;
		}
		in.close();
	}
	cout<<"\t\t\t\tPress Enter to continue...";
	getch();	
}
///////////////////////////////////////////////////////////

void EDIT_QUESTION()
{	
	fstream inout;
	int choice;
	char Qno[3];
	char x;
	int flag=0;
	
	do
	{
	system("CLS");
	cin.ignore();
	cout<<"\n\n\n\n\n\n\n\t\tEnter Question number you want to Edit : ";
	gets(Qno);
	inout.open("questions.dat",ios::in|ios::out);
	while(inout.read((char*)&q,sizeof(Questions)))
	{
		if(strcmpi(q.Question_NO,Qno)==0 && flag==0)
		{
		system("CLS");
		cout<<"\n\n\t\t\t\t\t\tQuestion List\n";
		cout<<"\t\t\t\t\t\t"<<"-------------"<<endl;
		cout<<"\t\t\t\t";
	
			cout<<setw(5)<<q.Question<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(A) "<<q.Answer_A<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(B) "<<q.Answer_B<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(C) "<<q.Answer_C<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"(D) "<<q.Answer_D<<endl;
			cout<<setw(10)<<"\t\t\t\t"<<"Answer = "<<q.Correct_Answer<<endl<<endl;
			
		flag=1;
		cout<<"\t\t\t\tChoose the Part of Question you want to Edit "<<endl;
		cout<<"\t\t\t\t(1) Question"<<endl;
		cout<<"\t\t\t\t(2) Answer A"<<endl;
		cout<<"\t\t\t\t(3) Answer B"<<endl;		
		cout<<"\t\t\t\t(4) Answer C"<<endl;
		cout<<"\t\t\t\t(5) Answer D"<<endl;		
		cout<<"\t\t\t\t(6) Correct Answer"<<endl;
		cin>>choice;
		switch(choice)			
		{
			case 1:
				{system("CLS");
				q.Edit_Q();
				inout.seekg(0,ios::cur);
				int endposition=inout.tellg();
				int position=endposition-sizeof(Questions);
				inout.seekg(position);
				inout.write((char*)&q,sizeof(Questions));}
				break;
				
			case 2:
				{system("CLS");
				q.Edit_A(); 
				inout.seekg(0,ios::cur);
				int endposition=inout.tellg();
				int position=endposition-sizeof(Questions);
				inout.seekg(position);
				inout.write((char*)&q,sizeof(Questions));}
				break;
			
			case 3:
				{system("CLS");
				q.Edit_B();
				inout.seekg(0,ios::cur);
				int endposition=inout.tellg();
				int position=endposition-sizeof(Questions);
				inout.seekg(position);
				inout.write((char*)&q,sizeof(Questions));}
			 	break;
			
			case 4:
				{system("CLS");
				q.Edit_C(); 
				inout.seekg(0,ios::cur);
				int endposition=inout.tellg();
				int position=endposition-sizeof(Questions);
				inout.seekg(position);
				inout.write((char*)&q,sizeof(Questions));}
				break;
			
			case 5:
				{system("CLS");
				q.Edit_D();
				inout.seekg(0,ios::cur);
				int endposition=inout.tellg();
				int position=endposition-sizeof(Questions);
				inout.seekg(position);
				inout.write((char*)&q,sizeof(Questions));}
			 	break;
			
			case 6:
				{system("CLS");
				q.Edit_CA(); 
				inout.seekg(0,ios::cur);
				int endposition=inout.tellg();
				int position=endposition-sizeof(Questions);
				inout.seekg(position);
				inout.write((char*)&q,sizeof(Questions));}
				break;
				
			default:
				system("cls");
				gotoxy(40,13);
				cout<<"ENTER FROM 1 TO 6 PLEASE";
				gotoxy(40,15);
				cout<<"PRESS \"ENTER\" KEY TO CONTINUE...";
				cin.ignore();
				getch(); 
				return EDIT_QUESTION();	
		}
		}
	}
	if(flag==0)
	{
		system("CLS");
		cout<<"\n\n\n\n\n\n\n\t\tQuestion Not Found.....!!!!!!!!";
	}
	flag=0;
	
	cout<<"\n\n\t\t\t\tDo you want to Edit Question again..(y/n?) = ";
	cin>>x;
	inout.close();
	}while(x=='y'||x=='Y');	
}
//////////////////////////////////////////////////////////

void DELETE_Q()
{
	system("CLS");
	cin.ignore();
	char Q_no[3];
	char c;
	int flag=0;
	fstream f1;
	fstream f2;
	cout<<"\n\n\n\n\n\n\n\t\t\tEnter the Question number to Delete : ";
	gets(Q_no);

	f1.open("questions.dat",ios::in|ios::out);
	f2.open("temp.dat",ios::out);
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&q,sizeof(Questions)))
	{
	if(strcmpi(q.Question_NO,Q_no)!=0) f2.write((char*) &q,sizeof(Questions));

	else
	{
	flag=1;
	system("CLS");
	cout<<"\n\n\t\t\t\t\t\t"<<setw(10)<<"Question List"<<endl;
	cout<<"\t\t\t\t\t\t"<<"-------------"<<endl<<endl;
	cout<<"\t\t\t\t";
	q.Show();}
	}

	f2.close();
	f1.close();

	if(flag==1)
	{
	cout<<"\n\t\t\tAre you sure want to Delete (y/n)? = ";
	cin>>c;
	if(c=='y'||c=='Y')
	{
	remove("questions.dat");
	rename("temp.dat","questions.dat");
	cout<<"\n\t\t\tQuestion Deleted....!!!!!!!!!";}
	}
	else
	{
	remove("temp.dat");
	cout<<"\n\t\t\tQuestion Not Found....!!!!!!!!!";
	}
	getch();
}
////////////////////////////////////////////////////////////////

void Take_Quiz()
{
	int N=0;
	ifstream in("questions.dat");
	if(!in)
	{
	gotoxy(40,13);
	cout<<"Question not Found.......!!!!!!!!!";
	gotoxy(40,15);
	cout<<"Press Enter to continue...";
	getch();
	return STUDENT();
	}

	else
	{
		mark=0;
		while(in.read((char*)&q,sizeof(Questions)))
		{
		cout<<endl;
		cout<<"\t\t\t\t"<<setw(3)<<++N<<". ";
		q.Quiz();
		cout<<endl<<endl;
		cout<<"\t\t\t\t"<<"Press Enter to next Question ";
		getch();
		system("cls");
		}
		in.close();
		cout<<endl<<endl<<endl;
		cout<<"\t\t\t\tEnd of Questions!!"<<endl;
		cout<<"\t\t\t\tPress Enter to Continue..!!";
		getch();
	}
	
		system("cls");
		gotoxy(40,4);
		cout<<"Your Score is "<<mark<<" Mark(s)."<<endl;
		getch();
		if(mark>=5)
		{
			PRINTSTAR();
			cout<<"\n\t\t\t\t\tCongratulations!!"<<endl;
			cout<<"\n\t\t\t\t\tYou have passed the Quizz!!"<<endl<<endl;
			PRINTSTAR();
		}
		else
		{
			cout<<endl;
			PRINTSTAR();
			cout<<"\n\t\t\t\t\tSorry!!"<<endl;
			cout<<"\n\t\t\t\t\tYou failed the Quizz!!"<<endl;
			cout<<"\n\t\t\t\t\tTry again later!!"<<endl<<endl;
			PRINTSTAR();
		}
	cout<<"\t\t\t\t\tPress Enter to continue...";
	getch();
	return STUDENT();	
}
////////////////////////////////////////////////////////////////

void View_Score()
{
	ifstream in("questions.dat");
	if(!in)
	{
	gotoxy(40,13);
	cout<<"File not Found.......!!!!!!!!!";
	gotoxy(40,15);
	cout<<"Press Enter to continue...";
	getch();
	return STUDENT();
	}

	else
	{
		in.close();
		gotoxy(40,4);
		cout<<"Your Score is "<<mark<<" Mark(s)."<<endl;
		getch();
		if(mark>=5)
		{
			PRINTSTAR();
			cout<<"\n\t\t\t\t\tCongratulations!!"<<endl;
			cout<<"\n\t\t\t\t\tYou have passed the Quizz!!"<<endl<<endl;
			PRINTSTAR();
		}
		else
		{
			cout<<endl;
			PRINTSTAR();
			cout<<"\n\t\t\t\t\tSorry!!"<<endl;
			cout<<"\n\t\t\t\t\tYou failed the Quizz!!"<<endl;
			cout<<"\n\t\t\t\t\tTry again later!!"<<endl<<endl;
			PRINTSTAR();
		}
	}
	cout<<"\t\t\t\t\tPress Enter to continue...";
	getch();
	return STUDENT();	
}
/////////////////////////////////////////////////////