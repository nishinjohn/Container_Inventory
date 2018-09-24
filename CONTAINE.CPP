#include<iostream> //Remember to change this
#include<conio.h>
#include<process.h>
#include<fstream>  //Remember to change this
#include<stdio.h>
#include<string.h>
using namespace std;     //Remember to remove this
char user[15],item[25];
int cap=0;

class container
  {
   public:
    int contno,vol;
    float shipid,pass;



    void getdata_user(char user[15])
      {

            cout<<"Enter item to ship ";
            cin.getline(item,sizeof item);
            cin.ignore();                             // May get you in trouble

            cout<<"Enter volume required ";
            cin>>vol;
                        if(vol<=cap)
                          {
                         //	    cout<<"shipment id is "<<shipid++;
                            cap-=vol;
                            cout<<"user id is"<<user;
                            cout<<"Enter desired ship id";
                            cin>>shipid;
                            cout<<"Enter desired password";
                            cin>>pass;

                          }
                        else
                          {
                               cout<<"sorry out of space.";
                               cout<<"can u reduce the volume to "<<cap<<" or less ";
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
            cout<<"user name is : ";puts(user);
            cout<<"\nshipment id is : "<<shipid;
            cout<<"password cannot be displayed due to security reasons";
            cout<<"\nitem is : ";puts(item);
            cout<<"\nvolume alloted is : "<<vol;
      }
  };

// *********** class finished ***********************
    void app()
      {
            container s;
            fstream f("missori.dat",ios::binary|ios::app);
            s.getdata();
            f.write((char*)&s,sizeof(s));
            f.close();
      }

//    void app(char use[15])
    void app_item()
      {
           container s;

           fstream f("missori.dat",ios::binary|ios::app|ios::out);   //why out ??
 //          fstream f("missori.dat",ios::binary|ios::out);
           s.getdata_user(user);//s.getdata(use);
           f.write((char*)&s,sizeof(s));
           f.close();
           cout<<"Data added to file";
      }
    void display()
      {
       container s;
        ifstream f("missori.dat",ios::binary|ios::in);
        if(!f)
        cout<<"File not opened";

                while(f.read((char*)&s,sizeof(s)))
                  {
                    s.putdata();
                    cout<<" looping in display\n";
                  }
                  /*
                else{
                cout<<"Cannot read from File";
                }*/

        f.close();
      }
    void Show()
      {
        container s;
        int kEy,rank=0;
        float id;
        cout<<"\n\t\t\t Enter shipment id - ";
        cin>>id;
        //cout<< " Details Parsed";
        cout<<"\n\t\t\t Enter password - ";
        cin>>kEy;

        ifstream f("missori.dat",ios::binary|ios::in);
            if(!f)
            cout<<"File not opened";
                    while(f.read((char*)&s,sizeof(s)))
                      {
                        s.putdata();
                        if((s.shipid==id)&&(s.pass==kEy))
                          {
                        cout<<"\n\t\t\t SHIPMENT DETAILS \n";
                        s.putdata();
                        rank=1;
                        //break;
                          }
                      }
                    /*else{
                        cout<<"Cannot read from File";
                        }*/
        if(rank==0)
        cout<<"\n\t\t\t user not found ";
        f.close();
      }
    void search()
      {
            container s;
            int exist=0;
            float id;
            cout<<"\n\t\t\t Enter shipment id - ";
            cin>>id;
            ifstream f("missori.dat",ios::binary|ios::in);
                while(f.read((char*)&s,sizeof(s)))
                  {
                    if(s.shipid==id)
                      {
                            cout<<"\n\t\t\t SHIPMENT DETAILS \n";
                            s.putdata();
                            exist=1;
                            break;
                      }
                  }
            if(exist==0)
                    cout<<"\n\t\t\t user not found ";
            f.close();
      }
    void deletE()
      {
            container s;
            float id;
            cout<<"\n Enter shipment id to be deleted - ";
            cin>>id;
            ifstream f("missori.dat",ios::binary|ios::in);
            ofstream f1("temp.dat",ios::binary|ios::trunc);  //truncated to discard previous data
            while(f.read((char*)&s,sizeof(s)))
             {
                cap+=s.vol;
               if(s.shipid!=id)
                 {
                   f1.write((char*)&s,sizeof(s));
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
            int kEy,exist=0;
            float id;
            cout<<"\n\t\t\t Enter shipment id - ";
            cin>>id;
            	cout<<"\n\t\t\t Enter password - ";
            	cin>>kEy;
            ifstream f("missori.dat",ios::binary|ios::in);
            ofstream f1("temp.dat",ios::binary|ios::trunc);
            while(f.read((char*)&s,sizeof(s)))
              {
                if((s.shipid==id)&&(s.pass==kEy))
                  {
                 while(f.read((char*)&s,sizeof(s)))
                   {
                       cap+=s.vol;
                       if(s.shipid!=id)
                    { f1.write((char*)&s,sizeof(s));
                    }
                   }
                 f.close();
                 f1.close();
                 remove("missori.dat");
                 rename("temp.dat","missori.dat");
                 exist=1;
                 break;
                  }
            if(exist==0)
              {
                cout<<"\n\t\t\t user not found ";
                f.close();
                f1.close();
               }
              }
      }
int main()    // remember to change this
  {
 //   clrscr();


    // removing current data
    ifstream f("missori.dat",ios::binary|ios::out|ios::trunc);
    if(!f)
        cout<<"File not created";
    f.close();



 //   float pass;
    int ch=0;
    char exit;
     do{
     cout<<"Enter user name\n";
    // gets(user);
	// cin.ignore();

	 cin.getline(user,sizeof user);
	 if(strcmpi("admin",user)==0)
	   {
	     char password[5];
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
			  {
			   case 1:
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
			  }
		     }while(ch<5);
		  }
	   }
	else
	 {
		    do{
			cout<<"\n\n\n\t\t\t *************************MENU******************************";
			cout<<"\n\t\t\t1.Add Shipment \n\t\t\t2.Display Shipments details \n\t\t\t3.Delete Shipment details \n\t\t\t4.Exit ";
			cout<<"\n\t\t\t Enter choice- ";
			cin>>ch;
			cin.ignore();                             // May get you in trouble
			switch(ch)
			  {
			    case 1:
			    app_item();//app(user);
			    break;
			    case 2:
			    Show();
			    break;
			    case 3:
			    del();
			    break;
			  }
		      }while(ch<4);
		  }

	    cout<<"are you sure u want to exit";
	    cin>>exit;
	    cin.ignore();                             // May get you in trouble
	  }while(exit=='n');

return 0;
  }
