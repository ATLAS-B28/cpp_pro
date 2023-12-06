#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class hospital {
    int pid;
    char pname[50];
    char fname[50];
    char mname[50];
    char hname[50];
    char ren[50];
    char rer[50];
    char gen[50];
    float age;
    char mob[50];
    char status[50];

    public:
      void in(){
        _cprintf("Enter the information of the patient:");
        cout<<endl<<endl;
        _cprintf("Enter patient id:");
        cout<<endl;
        cin>>pid;
        _cprintf("Enter patient first name:");
        cout<<endl;
        cin>>pname;
        _cprintf("Enter patient age:");
        cout<<endl;
        cin>>age;
        _cprintf("Enter patient gender:");
        cout<<endl;
        cin>>gen;
        _cprintf("Marital status:");
        cout<<endl;
        cin>>status;

        if(strcmpi(gen,"female")==0){
            if(strcmpi(status,"yes")==0){
                _cprintf("Enter patient's husband's name:");
                cout<<endl;
                cin>>hname;
            } else if(strcmpi(status,"no")==0){
                _cprintf("Enter patient's father's name:");
                cout<<endl;
                cin>>fname;
                _cprintf("Enter patient's mother's name:");
                cout<<endl;
                cin>>mname;
            }
        }else{
            _cprintf("Enter patient's father name:");
            cout<<endl;
            cin>>fname;
            _cprintf("Enter the name of person who reffered the patient:");
            cout<<endl;
            cin>>ren;
            _cprintf("Please enter the relation of person who reffered the patient : ");
            cout<<endl;
            cin>>rer;
            _cprintf("Enter the mobile number:");
            cout<<endl;
            cin>>mob;
        }
      }

      void out(){
        cout<<endl;
        _cprintf("Patient id:");
        cout<<pid;
        cout<<endl;
        _cprintf("Patient name:");
        cout<<pname;
        cout<<endl;
        _cprintf("Patient age:");
        cout<<age;
        cout<<endl;
        _cprintf("Patient gender:");
        cout<<gen;
        cout<<endl;
        _cprintf("Marital status:");
        cout<<status;
        cout<<endl;

        if(strcmpi(gen,"female")==0){
            if(strcmpi(status,"yes")==0)
            {
                _cprintf("Patient's  husband's name : ");
                cout<<hname;
                cout<<endl;
            }
            else if(strcmpi(status,"no")==0)
            {
                _cprintf("Patient's father name : ");
                cout<<fname;
                cout<<endl;
                _cprintf("Patient's  mother name : ");
                cout<<mname;
                cout<<endl;
            }
        }else{
            _cprintf("Patient's father name : ");
            cout<<fname;
            cout<<endl;
            _cprintf("Refferer's name : ");
            cout<<ren;
            cout<<endl;
            _cprintf("Refferer's relation : ");
            cout<<rer;
            cout<<endl;
            _cprintf("Mobile number : ");
            cout<<mob;
            cout<<endl;
        }
    }

    int record(){
        return pid;
    }

    void update()
    {
        char choice1[20];
        char choice2[20];
        char pn[50];
        char hn[50];
        char fn[50];
        char mn[50];
        char phone[50];
        char state[50];

        _cprintf("Do you want to really change the record (YES or NO): ");
        cout<<endl;
        cin>>choice1;
        if(strcmpi(choice1,"yes")==0){
            _cprintf("What do you want to change: ");
            cout<<endl;
            cin>>choice2;
            cout<<endl;
            if (strcmpi(choice2,"pname")==0){
                _cprintf("Enter the new patient's name: ");
                cout<<endl;
                cin>>pn;
                strcpy(pname,pn);
            } else if(strcmpi(choice2,"fname")==0){
                _cprintf("Enter the new father's name: ");
                cout<<endl;
                cin>>fn;
                strcpy(pname,fn);
            } else if(strcmpi(choice2,"hname")==0){
                _cprintf("Enter the new husband's name: ");
                cout<<endl;
                cin>>hn;
                strcpy(fname,hn);
            } else if(strcmpi(choice2,"mname")==0){
                _cprintf("Enter the new mother's name: ");
                cout<<endl;
                cin>>mn;
                strcpy(mname,mn);
            } else if (strcmpi(choice2,"mob")==0){
                _cprintf("Enter the new mobile number: ");
                cout<<endl;
                cin>>phone;
                strcpy(mob,phone);
            } else if (strcmpi(choice2,"status")==0){
                _cprintf("Enter the new marital status: ");
                cout<<endl;
                cin>>state;
                strcpy(status,state);
            }
            
        } else
        exit(0);
    }
}h;

void add(){
    cout<<"\nNo Spaces are allowed in name\n";
    fstream file("hospital.dat",ios::binary|ios::out|ios::app);
    h.in();
    file.write((char*)&h, sizeof(h));
}

void show(){
    fstream file("hospital.dat",ios::binary|ios::in);
    file.seekg(0);
    while(!file.eof()){
        file.read((char*)&h, sizeof(h));
        if(file.eof())
        break;
        else
        h.out();
    }
    file.close();
}

void search(){
    ifstream file("hospital.dat",ios::binary|ios::in|ios::out);
    file.seekg(0);
    int id;
    _cprintf("Enter the patient id you want to search: ");
    cout<<endl;
    cin>>id;
    while(!file.eof()){
        file.read((char*)&h, sizeof(h));
        if(file.eof())
        break;
        else if(h.record()==id)
        h.out();
    }
    file.close();
}

void transpose(){
    ofstream ifile("host.dat",ios::binary|ios::in|ios::out);
    ifstream file("hospittal.dat",ios::binary|ios::in|ios::out);
    file.seekg(0);
    int id1;
    int id2;
    _cprintf("Enter the patient's id in range you want to transpose: ");
    cout<<endl<<endl;
    _cprintf("Enter the patient's primary id number for rnage (x-): ");
    cout<<endl;
    cin>>id1;
    _cprintf("Enter the patient's secondary id number for rnage (-x): ");
    cout<<endl;
    cin>>id2;
    
    while(!file.eof()){
        file.read((char*)&h, sizeof(h));
        if(file.eof())
        break;
        else if(h.record()>= id1 && h.record()<=id2);
        ifile.write((char*)&h, sizeof(h));
    }
    file.close();
    ifile.close();
}

void del(){
    ofstream ifile("hos.dat",ios::binary|ios::in|ios::out);
    ifstream file("hospital.dat",ios::binary|ios::in|ios::out);
    file.seekg(0);
    int id;
    _cprintf("Enter the patient id you want to delete: ");
    cout<<endl;
    cin>>id;

    while(!file.eof()){
        file.read((char*)&h,sizeof(h));
        if(file.eof())
        break;
        else if(h.record()==id)
        h.out();
        else
        ifile.write((char*)&h, sizeof(h));
    }

    file.close();
    ifile.close();
    remove("hospital.dat");
    rename("hos.dat","hospital.dat");
}

void shot(){
    _cprintf("The transpose id's are: ");
    cout<<endl;
    fstream ifile("host.dat",ios::binary|ios::in|ios::out);

    while(!ifile.eof()){
        ifile.read((char*)&h, sizeof(h));
        if(ifile.eof())
        break;
        else
        h.out();
    }
    ifile.close();
}

void erase(){
    char choice[10];
    _cprintf("Are you sure you want to delete all records (YES or NO): ");
    cout<<endl;
    cin>>choice;

    if(strcmpi(choice,"yes")==0){
        fstream file("hospital.dat",ios::binary|ios::out|ios::trunc);
        file.write((char*)&h, sizeof(h));
        file.close();
    }
    _cprintf("All records deleted");
    cout<<endl;
}

void modify(){
    fstream file("hospital.dat",ios::binary|ios::in|ios::out);
    int id;
    _cprintf("Enter the patient id you want to modify: ");
    cout<<endl;
    cin>>id;
    int l;

    while(!file.eof()){
        l = file.tellp();
        file.read((char*)&h, sizeof(h));
        if(h.record()==id){
            file.seekg(l);
            h.update();
            file.write((char*)&h, sizeof(h));
        }
        file.close();
    }
}

int main(){
    char ch;
    char ch1;
    while(1)
    {
        _cprintf("_______________________________________________________________________________");
        cout<<endl;
        _cprintf("                                 Press Y to continue : ");
        cout<<endl;
        _cprintf("_______________________________________________________________________________");
        cout<<" ";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            _cprintf("________________________________________");
            cout<<endl;
            _cprintf(" Press 1 to add the record.            |");
            cout<<endl;
            _cprintf(" Press 2 to display the records.       |");
            cout<<endl;
            _cprintf(" Press 3 to search the record.         |");
            cout<<endl;
            _cprintf(" Press 4 to transpose the record.      |");
            cout<<endl;
            _cprintf(" Press 5 to show transposed record.    |");
            cout<<endl;
            _cprintf(" Press 6 to delete the record.         |");
            cout<<endl;
            _cprintf(" Press 7 to clear the record.          |");
            cout<<endl;
            _cprintf(" Press 8 to modify the record.         |");
            cout<<endl;
            _cprintf(" Press 9 for exit.                     |");
            cout<<endl;
            _cprintf("_______________________________________|");
            cout<<endl;
            cout<<endl;
            _cprintf("--------------------------------Enter your choice-------------------------------");
            cout<<endl;
            cin>>ch1;
            switch(ch1){
                case '1':_lrotr;
	                     add();
	                     break;
                case '2':_lrotr;
	                     show();
	                     break;
                case '3':_lrotr;
	                     search();
	                     break;
                case '4':_lrotr;
	                     transpose();
	                     break;
                case '5':_lrotr;
	                     shot();
	                     break;
                case '6':_lrotr;
	                     del();
	                     break;
                case '7':_lrotr;
	                     erase();
	                     break;
                case '8':_lrotr;
	                     modify();
	                     break;
                case '9':_lrotr;
	                     exit(0);
            }
        }
    }
    system("pause");
    return 0;
}