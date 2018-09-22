#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
class container
  {
    int contno,cap,v,vol,pass;
     char user[15];
    long float shipid;
   public:
     void getdata(char a[15])
      {
	user[15]=a[15];
	v=0;
	shipid=9846224544;
	pass=2212;
	cout<<"Enter volume required ";
	cin>>vol;
	if(v+vol<=cap)
	   {
	    cout<<"shipment id is "<<shipid++;
	    cout<<"password is "<<pass++;
	   }
	 else
	  {
	   cout<<"sorry out of space.";
	   cout<<"can u reduce the volume to "<<cap-vol;
	   }
       }
      void getdata()
       {
	  cout<<"Enter container id";
	  cin>>contno;
	  cout<<"Enter capacity";
	  cin>>cap;
	}
       void putdata()
	 {
	  cout<<"user name is "<<user;
	  cout<<"shipment id is "<<shipid;
	  cout<<"volume alloted is "<<vol;
	  }
  }

void app()
{ container s;
 fstream f("missori.dat",ios::binary|ios::app|ios::out);
 s.getdata();
 f.write((char*)&s,sizeof(s));
 f.close();
 }
/*
void app(char a[15])
{ container s;
 fstream f("missori.dat",ios::binary|ios::app|ios::out);
 s.getdata(a);
 f.write((char*)&s,sizeof(s));
 f.close();
 }*/
void display()
{ container s;
ifstream f("missori.dat",ios::binary|ios::in);
while(f.read((char*)&s,sizeof(s)))
{ s.putdata();
  cout<<"\n";
}
f.close();
}
void Show()
{ container s;
 int kEy,a=0;
 long float id;
 cout<<"\n\t\t\t Enter shipment id - ";
 cin>>id;
 cout<<"\n\t\t\t Enter password - ";
 cin>>kEy;
ifstream f("missori.dat",ios::binary|ios::in);
while(f.read((char*)&s,sizeof(s)))
{
if((s.shipid()==id)&&(s.pass=kEy))
 {
  cout<<"\n\t\t\t SHIPMENT DETAILS \n";
  s.putdata();
  a=1;
  break;
  }  }
  if(a==0)
  cout<<"\n\t\t\t user not found ";
  f.close();
  }
void search()
 {
  container s;
 int a=0;
 long float id;
 cout<<"\n\t\t\t Enter shipment id - ";
 cin>>id;
ifstream f("missori.dat",ios::binary|ios::in);
while(f.read((char*)&s,sizeof(s)))
{
if((s.shipid()==id)
 {
  cout<<"\n\t\t\t SHIPMENT DETAILS \n";
  s.putdata();
  a=1;
  break;
  }  }
  if(a==0)
  cout<<"\n\t\t\t user not found ";
  f.close();
 }
void deletE()
  {
  container s;
  long float id;
  cout<<"\n Enter shipment id to be deleted - ";
  cin>>id;
  ifstream f("missori.dat",ios::binary|ios::in);
  ofstream f1("temp.dat",ios::binary|ios::app);
  while(f.read((char*)&s,sizeof(s)))
  { if(s.shipid()!=id)
  { f1.write((char*)&s,sizeof(s));
  }
  }
  f.close();
  f1.close();
  remove("missori.dat");
  rename("temp.dat","missori.dat");
  }
void del()
  { 
  container s;
  int kEy,a=0;
  long float id;
  cout<<"\n\t\t\t Enter shipment id - ";
  cin>>id;
  cout<<"\n\t\t\t Enter password - ";
  cin>>pass;
  ifstream f("missori.dat",ios::binary|ios::in);
  ofstream f1("temp.dat",ios::binary|ios::app);
  while(f.read((char*)&s,sizeof(s)))
  {
  if((s.shipid()==item)&&(s.pass=kEy))
  if(s.shipid()!=id)
  { f1.write((char*)&s,sizeof(s));
  }
  }
  f.close();
  f1.close();
  remove("missori.dat");
  rename("temp.dat","missori.dat");
  a=1;
break;
  }
  if(a==0)
  cout<<"\n\t\t\t user not found ";
  f.close();
  f1.close();
  }
void main()
 {
  char user[15];
  int ch;
  cout<<"Enter user name\n";
  gets(user);
  if(strcmpi ("admin",user)==0)
   {
   char password;
   cout<<"Enter password \n";
   cin>>password;
    if(strcmpi ("2k18",password)==0)
     {
     do{
  cout<<"\n\n\n\t\t\t *************************MENU******************************";
  cout<<"\n\t\t\t1.Add Container \n\t\t\t2.Display Shipments details \n\t\t\t3.Search shipments \n\t\t\t4.Delete shipments \n\t\t\t5.Exit ";
   cout<<"\n\t\t\t Enter choice- ";
   cin>>ch;
   switch(ch)
   { case 1:
      app();
      break;
      case 2:
      display();
      break;
      case 3:
      search();
      break;
      case 4:
      deletE();
      break;
      case 5:
      exit(0);
      }
      }while(ch<6);
   }
   else
   {
     do{
  cout<<"\n\n\n\t\t\t *************************MENU******************************";
  cout<<"\n\t\t\t1.Add Shipment \n\t\t\t2.Display Shipments details \n\t\t\t3.Delete Shipment details \n\t\t\t4.Exit ";
   cout<<"\n\t\t\t Enter choice- ";
   cin>>ch;
   switch(ch)
   { case 1:
      app(user[15]);
      break;
      case 2:
      show();
      break;
      case 3:
      del();
      break;
      case 4:
      exit(0);
      }
      }while(ch<5);
   }
 }
