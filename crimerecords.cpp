#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
char visitor;
void start();
void homemenu();

//admin module
void adminmenu();
void AdminLogin();
void adminsection();

//user module
void usermenu();
void UserLogin();
void usercreate();
void usersection();
void firstatus();

int crim_id_gen();
int fir_number_gen();
void addcriminal();
void modifycriminal();
void displaycriminal();
void addfir();
void displayfir();
bool isUserNameExist(char user1[]);

class criminal{
    public:
    int criminal_id;
    char name[20];
    int age;
    char contact[11];
    char address[30];
    char adhaar_number[13];
    char dob[11];
    char section[10];
    int height;
    char skin_color[10];
    char identification[15];
    criminal(){
        criminal_id = 0;
    }
    void add(){
        criminal_id = crim_id_gen();
        cout<<"\t\tCriminal ID : "<<criminal_id<<endl;
        cout<<"\t\tName : ";
        fflush(stdin);
        cin.getline(name,20);
        fflush(stdin);
        cout<<"\t\tAge : ";
        fflush(stdin);
        cin>>age;
        cout<<"\t\tAddress : ";
        fflush(stdin);
        cin.getline(address,30);
        cout<<"\t\tContact : ";
        fflush(stdin);
        cin>>contact;
        cout<<"\t\tAdhaar Number : ";
        fflush(stdin);
        cin>>adhaar_number;
        cout<<"\t\tD.O.B. : ";
        fflush(stdin);
        cin>>dob;
        cout<<"\t\tUnder section : ";
        fflush(stdin);
        cin.getline(section,10);
        cout<<"\t\tHeight (in cms): ";
        fflush(stdin);
        cin>>height;
        cout<<"\t\tSkin Colour : ";
        fflush(stdin);
        cin.getline(skin_color,10);
        cout<<"\t\tIdentification Marks : ";
        fflush(stdin);
        cin.getline(identification,15);
    }
    void display(){
        cout<<"\t\tCriminal ID : "<<criminal_id<<endl;
        cout<<"\t\tName : "<<name<<endl;
        cout<<"\t\tAge : "<<age<<endl;
        cout<<"\t\tAddress : "<<address<<endl;
        cout<<"\t\tContact : "<<contact<<endl;
        cout<<"\t\tAdhaar Number : "<<adhaar_number<<endl;
        cout<<"\t\tD.O.B. : "<<dob<<endl;
        cout<<"\t\tUnder section : "<<section<<endl;
        cout<<"\t\tHeight : "<<height<<" cms"<<endl;
        cout<<"\t\tSkin Colour : "<<skin_color<<endl;
        cout<<"\t\tIdentification Marks : "<<identification<<endl;
    }      
};
class fir{
    public:
    int fir_no;
    char date[11];
    char name[20];
    char guardianname[20];
    char address[20];
    char contact[11];
    char email[20];
    char place[15];
    char nature[15];
    char time[20];
    char section[6];
    char complaint[100];
    char fir_status[15];
    fir(){
        fir_no=0;
    }
    void add(){
        fir_no = fir_number_gen();
        cout<<"\t\tFIR number : "<<fir_no<<endl;
        cout<<"\t\tDate of FIR : ";
        fflush(stdin);
        cin>>date;
        cout<<"\t\tName of Complainant : ";
        fflush(stdin);
        cin.getline(name,20);
        cout<<"\t\tGuardian's Name of Complainant : ";
        fflush(stdin);
        cin.getline(guardianname,20);
        cout<<"\t\tAddress : ";
        fflush(stdin);
        cin.getline(address,20);
        cout<<"\t\tContact : ";
        fflush(stdin);
        cin>>contact;
        cout<<"\t\tEmail : ";
        fflush(stdin);
        cin>>email;
        cout<<"\t\tPlace : ";
        fflush(stdin);
        cin>>place;
        cout<<"\t\tType of Complaint : ";
        fflush(stdin);
        cin.getline(nature,15);
        cout<<"\t\tTime when happpened : ";
        fflush(stdin);
        cin.getline(time,20);
        cout<<"\t\tUnder section : ";
        fflush(stdin);
        cin>>section;
        cout<<"\t\tDescription of Complaint : ";
        fflush(stdin);
        cin.getline(complaint,100);
        cout<<"\t\tFIR Status : ";
        fflush(stdin);
        cin>>fir_status;
    }
    void display(){
        cout<<"\t\tFIR number : "<<fir_no<<endl;
        cout<<"\t\tDate of FIR : "<<date<<endl;
        cout<<"\t\tName of Complainant : "<<name<<endl;
        cout<<"\t\tGuardian's Name of Complainant : "<<guardianname<<endl;
        cout<<"\t\tAddress : "<<address<<endl;
        cout<<"\t\tContact : "<<contact<<endl;
        cout<<"\t\tEmail : "<<email<<endl;
        cout<<"\t\tPlace : "<<place<<endl;
        cout<<"\t\tType of Complaint : "<<nature<<endl;
        cout<<"\t\tTime when happpened : "<<time<<endl;
        cout<<"\t\tUnder section : "<<section<<endl;
        cout<<"\t\tDescription of Complaint : "<<complaint<<endl;
        cout<<"\t\tFIR Status : "<<fir_status<<endl;
    }
};
class admin_credentials{  
    public:
    char user_name[20];
    char password[20];
    admin_credentials(){
        strcpy(user_name , "");
        strcpy(password , "");
    }
    void add(){
        if(strcmp(user_name,"")){
            fstream file;
            file.open("admincredentials.dat",ios::app|ios::binary);
            file.write((char*) this , sizeof(*this));
            file.close();        
        }
    }
};
class user_credentials{
    public:
    char user_name[20];
    char password[20];
    char name[20];
    char contact[11];
    char email[20];
    char state[20];
    user_credentials(){
        strcpy(user_name,"");
    }
    void add(){
        cout<<"\n\t\tPhone number : ";
        fflush(stdin);
        cin>>contact;
        cout<<"\n\t\tName : ";
        fflush(stdin);
        cin.getline(name,20);
        cout<<"\n\t\tE-mail : ";
        fflush(stdin);
        cin>>email;
        cout<<"\n\t\tUser Name : ";
        fflush(stdin);
        cin>>user_name;
        while(isUserNameExist(user_name)){
            cout<<"\n\t\tUser Name already exists. Try  again !\n";
            cout<<"\n\t\tUser Name : ";
            fflush(stdin);
            cin>>user_name;
        }
        cout<<"\n\t\tPassword : ";
        fflush(stdin);
        cin>>password;
        cout<<"\n\t\tState : ";
        fflush(stdin);
        cin.getline(state,20);
    }
};
int main(){
    //admin_credentials admin1;
    //strcpy(admin1.user_name,"Redskull@023");
    //strcpy(admin1.password,"Red123");
    //admin1.add();
    homemenu();
    cout<<"\n\t\t";
    system("pause");
    return 0;
}
void start(){
    system("cls");
    cout<<"\n\n\n\t\t\t______________________________________";
    cout<<"\n\t\t\t| POLICE AND CITIZEN SERVICES SYSTEM |";
    cout<<"\n\t\t\t______________________________________\n\n";
}
void homemenu(){
    int choice;
    bool flag=true;
    start();
    cout<<"\n\n\t\tHOME\n\t\t____";
    cout<<"\n\n \t\t1. Police";
    cout<<"\n\t\t2. Citizens";
    cout<<"\n\t\t3. Exit\n\n";
    while(flag){
        cout<<"\t\tCHOICE : ";
        cin>>choice;
        switch(choice){
            case 1 :    adminmenu();
                        flag = false;
                        break;
            case 2 :    usermenu();
                        flag = false;
                        break;
            case 3 :    return;
                        flag = false;
                        break;
            default : cout<<"\n\t\tRetry! Wrong choice !\n";
                        break;
        }
    }
}
void adminmenu(){
    start();
    cout<<"\n\n\t\tPOLICE\n\t\t_____";
    cout<<"\n\n\n \t\t1. Login";
    cout<<"\n\t\t2. Back\n\n";
    int choice;
    int flag=true;
    while(flag){
        cout<<"\t\tCHOICE : ";
        cin>>choice;
        switch(choice){
            case 1 :   AdminLogin();
                        flag = false;
                        break;
            case 2 :    homemenu();   
                        flag = false;
                        break;
            default : cout<<"\n\t\tRetry! Wrong choice !\n";
                        break;
        }
    }
}
void AdminLogin(){
    int choice;
    admin_credentials admin , admin1;
    start();
    bool login_status = false;
    while(!login_status){
        cout<<"\n\n\t\tLogIn\n\t\t____";
        cout<<"\n\n \t\tuser name : ";
        cin>>admin1.user_name;
        cout<<"\n\t\tpassword : ";
        cin>>admin1.password;
        ifstream file;
        file.open("admincredentials.dat",ios::in|ios::binary);
        file.read((char*)&admin , sizeof(admin));
        while(!file.eof()){
            if(!strcmp(admin1.user_name,admin.user_name)){
                if(!strcmp(admin1.password,admin.password)){
                    cout<<"\n\t\tLogin successfully!.\n\n";
                    visitor = 'a';
                    cout<<"\t\t";
                    system("pause");
                    login_status = true;
                    break;
                }
                else{
                    cout<<"\n\t\tWrong Password!\n";
                    cout<<"\t\tEnter Password again : ";
                    cin>>admin1.password;
                }
            }
            else
            {
                file.read((char*)&admin , sizeof(admin));
            }
        }
        if(!login_status){
            cout<<"\n\t\tWrong username.\n";
            cout<<"\t\t1. Retry\n\t\t2. Back\n";   
            bool flag=true;
            while(flag){
                cout<<"\t\tCHOICE : ";
                cin>>choice;
                switch(choice){
                    case 1 :    flag = false;
                                break;
                    case 2 :    adminmenu();
                                return;
                                flag = false;
                                break;
                    default :  cout<<"\n\t\tRetry! Wrong choice !\n";
                                break;
                }
            }
        }
    }
    if(login_status){
        adminsection();
    }         
}
void adminsection(){
    start();
    cout<<"\n\n\t\tPolice Section\n\t\t______________";
    cout<<"\n\n \t\t1. View details of FIR ";
    cout<<"\n\t\t2. Add FIR ";
    cout<<"\n\t\t3. View details of criminal ";
    cout<<"\n\t\t4. Add profile of criminal ";
    cout<<"\n\t\t5. Modify record of criminal ";
    cout<<"\n\t\t6. Back\n\n";
    int choice;
    int flag=true;
    while(flag){
        cout<<"\t\tCHOICE : ";
        cin>>choice;
        switch(choice){
            case 1 :   displayfir();
                        flag = false;
                        break;
            case 2 :    addfir();   
                        flag = false;
                        break;
            case 3 :    displaycriminal();   
                        flag = false;
                        break;
            case 4 :    addcriminal();   
                        flag = false;
                        break;
            case 5 :    modifycriminal();   
                        flag = false;
                        break;
            case 6 :    homemenu();   
                        flag = false;
                        break;
            default : cout<<"\n\t\tRetry! Wrong choice !\n";
                        break;
        }
    }
}
int fir_number_gen(){
    int i = 100000;
    fir fir1;
    fstream file;
    file.open("FIRs.dat",ios::binary|ios::in);
    file.read((char*)&fir1,sizeof(fir1));
    while(!file.eof()){
        i++;
        file.read((char*)&fir1,sizeof(fir1));
    }
    file.close();
    return i;
}
int crim_id_gen(){
    int i = 100000;
    criminal crime1;
    fstream file;
    file.open("criminals.dat",ios::binary|ios::in);
    file.read((char*)&crime1,sizeof(crime1));
    while(!file.eof()){
        i++;
        file.read((char*)&crime1,sizeof(crime1));
    }
    file.close();
    return i;
}
void addcriminal(){
    criminal crime1;
    int choice;
    start();
    cout<<"\n\n\t\tADD CRIMINAL\n\t\t____________\n\n";
    crime1.add();
    if(crime1.criminal_id!=0){
            fstream file;
            file.open("criminals.dat",ios::app|ios::binary);
            file.write((char*)&crime1 , sizeof(criminal));
            file.close();        
        }
    cout<<"\t\tCriminal data Successfully saved!\n\n\t\t";
    system("pause");
    adminsection();
}
void displaycriminal(){
    int choice;
    int criminal_id;
    criminal crime1;
    start();
    bool crim_found = false;
    while(!crim_found){
        cout<<"\n\n\t\tCRIMINAL DETAILS\n\t\t_____________";
        cout<<"\n\t\tEnter Criminal ID : ";
        cin>>criminal_id;
        fstream file;
        file.open("criminals.dat",ios::in|ios::binary);
        file.read((char*)&crime1 , sizeof(criminal));
        while(!file.eof()){
            if(criminal_id==crime1.criminal_id){
                start();
                cout<<"\n\n\t\tCRIMINAL DETAILS\n\t\t_____________\n\n";
                crime1.display();
                cout<<"\t\t";
                system("pause");
                crim_found = true;
                break;
            }
            else
            {
                file.read((char*)&crime1 , sizeof(crime1));
            }
        }
        if(!crim_found){
            cout<<"\n\t\tCRIMINAL DOES NOT EXIST!\n";
            cout<<"\t\t1. Retry\n\t\t2. Back\n";   
            bool flag=true;
            while(flag){
                cout<<"\t\tCHOICE : ";
                cin>>choice;
                switch(choice){
                    case 1 :    flag = false;
                                break;
                    case 2 :    adminsection();
                                return;
                                flag = false;
                                break;
                    default :  cout<<"\n\t\tRetry! Wrong choice !\n";
                                break;
                }
            }
        }
    }
    adminsection();
}
void modifycriminal(){
    int choice ,pos ;
    int criminal_id;
    criminal crime1;
    start();
    bool crim_found = false;
    while(!crim_found){
        cout<<"\n\n\t\tCRIMINAL DETAILS\n\t\t_____________";
        cout<<"\n\t\tEnter Criminal ID : ";
        cin>>criminal_id;
        fstream file;
        file.open("criminals.dat",ios::in|ios::binary|ios::out|ios::ate);
        file.seekg(0);
        file.read((char*)&crime1 , sizeof(criminal));
        while(!file.eof()){
            pos = int(file.tellg()) - int(sizeof(criminal));
            if(criminal_id==crime1.criminal_id){
                start();
                cout<<"\n\n\t\tCRIMINAL DETAILS\n\t\t_____________\n\n";
                crime1.display();
                cout<<"\n\n\t\tMODIFY CRIMINAL DETAILS\n\t\t____________________";
                cout<<"\n\n\t\t1. Name";
                cout<<"\n\t\t2. Age";
                cout<<"\n\t\t3. Contact";
                cout<<"\n\t\t4. Address";
                cout<<"\n\t\t5. Adhaar Number";
                cout<<"\n\t\t6. Date of Birth";
                cout<<"\n\t\t7. Section";
                cout<<"\n\t\t8. Height";
                cout<<"\n\t\t9. Skin Colour";
                cout<<"\n\t\t10. Identification";
                cout<<"\n\t\t11. Back\n";    
                bool flag=true;
                while(flag){
                cout<<"\t\tChoose what you want to change : ";
                cin>>choice;
                switch(choice){
                    case 1 :    cout<<"\t\tNew Name :";
                                fflush(stdin);
                                cin.getline(crime1.name,20);
                                flag = false;
                                break;
                    case 2 :    cout<<"\t\tNew Age :";
                                fflush(stdin);
                                cin>>crime1.age;
                                flag = false;
                                break;
                    case 3 :    cout<<"\t\tNew Contact :";
                                fflush(stdin);
                                cin>>crime1.contact;
                                flag = false;
                                break;
                    case 4 :    cout<<"\t\tNew Address :";
                                fflush(stdin);
                                cin.getline(crime1.address,30);
                                flag = false;
                                break;
                    case 5 :    cout<<"\t\tNew Adhaar number :";
                                fflush(stdin);
                                cin>>crime1.adhaar_number;
                                flag = false;
                                break;
                    case 6 :    cout<<"\t\tNew Date of birth :";
                                fflush(stdin);
                                cin>>crime1.dob;
                                flag = false;
                                break;
                    case 7 :    cout<<"\t\tNew Section :";
                                fflush(stdin);
                                cin.getline(crime1.section,10);
                                flag = false;
                                break;
                    case 8 :    cout<<"\t\tNew Height (in cms) :";
                                fflush(stdin);
                                cin>>crime1.height;
                                flag = false;
                                break;
                    case 9 :    cout<<"\t\tNew Skin colour :";
                                fflush(stdin);
                                cin.getline(crime1.skin_color,10);
                                flag = false;
                                break;
                    case 10 :   cout<<"\t\tNew Identification marks :";
                                fflush(stdin);
                                cin.getline(crime1.identification,15);
                                flag = false;
                                break;
                    case 11 :   adminsection();
                                return;
                                flag = false;
                                break;
                    default :  cout<<"\n\t\tRetry! Wrong choice !\n";
                                break;
                }
            } 
                file.seekp(pos);
                file.write((char*)&crime1,sizeof(criminal));
                cout<<"\n\t\tRecord modified successfully!\n\t\t";
                system("pause");
                crim_found = true;
                break;
            }
            else
            {
                file.read((char*)&crime1 , sizeof(criminal));
            }
        }
        file.close();
        if(!crim_found){
            cout<<"\n\t\tCRIMINAL DOES NOT EXIST!\n";
            cout<<"\t\t1. Retry\n\t\t2. Back\n";   
            bool flag=true;
            while(flag){
                cout<<"\t\tCHOICE : ";
                cin>>choice;
                switch(choice){
                    case 1 :    flag = false;
                                break;
                    case 2 :    adminsection();
                                return;
                                flag = false;
                                break;
                    default :  cout<<"\n\t\tRetry! Wrong choice !\n";
                                break;
                }
            }
        }
    }
    adminsection();
}
void addfir(){
    fir fir1;
    int choice;
    start();
    cout<<"\n\n\t\tADD FIR\n\t\t_______\n\n";
    fir1.add();
    if(fir1.fir_no!=0){
            fstream file;
            file.open("FIRs.dat",ios::binary|ios::out|ios::app);
            file.write((char*)&fir1 , sizeof(fir));
            file.close();        
        }
    cout<<"\t\tFIR Successfully saved!\n\n\t\t";
    system("pause");
    adminsection();
}
void displayfir(){
    int choice;
    int fir_no;
    fir fir1;
    start();
    bool fir_found = false;
    while(!fir_found){
        cout<<"\n\n\t\tFIR DETAILS\n\t\t________";
        cout<<"\n\t\tEnter FIR Number : ";
        cin>>fir_no;
        fstream file;
        file.open("FIRs.dat",ios::in|ios::binary);
        file.seekg(0);
        file.read((char*)&fir1 , sizeof(fir1));
        while(!file.eof()){
            if(fir_no == fir1.fir_no){
                start();
                cout<<"\n\n\t\tFIR DETAILS\n\t\t________\n\n";
                fir1.display();
                cout<<"\t\t";
                system("pause");
                fir_found = true;
                break;
            }
            else
            {
                file.read((char*)&fir1 , sizeof(fir1));
            }
        }
        file.close();
        if(!fir_found){
            cout<<"\n\t\tFIR DOES NOT EXIST!\n";
            cout<<"\t\t1. Retry\n\t\t2. Back\n";   
            bool flag=true;
            while(flag){
                cout<<"\t\tCHOICE : ";
                cin>>choice;
                switch(choice){
                    case 1 :    flag = false;
                                break;
                    case 2 :    adminsection();
                                return;
                                flag = false;
                                break;
                    default :  cout<<"\n\t\tRetry! Wrong choice !\n";
                                break;
                }
            }
        }
    }
    if(visitor=='a')
        adminsection();
    else
        usersection();
       
}
void usermenu(){
    start();
    cout<<"\n\n\t\tCITIZEN\n\t\t_______";
    cout<<"\n\n\n \t\t1. Login";
    cout<<"\n\t\t2. Create account";
    cout<<"\n\t\t3. Back\n\n";
    int choice;
    int flag=true;
    while(flag){
        cout<<"\t\tCHOICE : ";
        cin>>choice;
        switch(choice){
            case 1 :   UserLogin();
                        flag = false;
                        break;
            case 2 :   usercreate();
                        flag = false;
                        break;
            case 3 :    homemenu();   
                        flag = false;
                        break;
            default : cout<<"\n\t\tRetry! Wrong choice !\n";
                        break;
        }
    }
}
void UserLogin(){
    int choice;
    user_credentials user , user1;
    start();
    bool login_status = false;
    while(!login_status){
        cout<<"\n\n\t\tLogIn\n\t\t____";
        cout<<"\n\n \t\tuser name : ";
        cin>>user1.user_name;
        cout<<"\n\t\tpassword : ";
        cin>>user1.password;
        ifstream file;
        file.open("usercredentials.dat",ios::in|ios::binary);
        file.read((char*)&user , sizeof(user));
        while(!file.eof()){
            if(!strcmp(user1.user_name,user.user_name)){
                if(!strcmp(user1.password,user.password)){
                    cout<<"\n\t\tLogin successfully!.\n\n";
                    visitor = 'u';
                    cout<<"\t\t";
                    system("pause");
                    login_status = true;
                    break;
                }
                else{
                    cout<<"\n\t\tWrong Password!\n";
                    cout<<"\t\tEnter Passwor again : ";
                    cin>>user1.password;
                }
            }
            else
            {
                file.read((char*)&user , sizeof(user));
            }
        }
        if(!login_status){
            cout<<"\n\t\tWrong username.\n";
            cout<<"\t\t1. Retry\n\t\t2. Back\n";   
            bool flag=true;
            while(flag){
                cout<<"\t\tCHOICE : ";
                cin>>choice;
                switch(choice){
                    case 1 :    flag = false;
                                break;
                    case 2 :    usermenu();
                                return;
                                flag = false;
                                break;
                    default :  cout<<"\n\t\tRetry! Wrong choice !\n";
                                break;
                }
            }
        }
    }
    if(login_status){
        usersection();
    }         
}
bool isUserNameExist(char user1[]){
    user_credentials user;
    fstream file;
    file.open("usercredentials.dat",ios::binary|ios::in);
    file.read((char*)&user , sizeof(user));
    while(!file.eof()){
        if(!strcmp(user.user_name,user1)){
            file.close();
            return true;
        }
    file.read((char*)&user , sizeof(user));    
    }
    file.close();
    return false;
}
void usercreate(){
    user_credentials user1;
    start();
    cout<<"\n\n\t\tCreate account\n\t\t______________";
    user1.add();
    if(strcmp(user1.user_name,"")){
            fstream file;
            file.open("usercredentials.dat",ios::binary|ios::out|ios::app);
            file.write((char*)&user1 , sizeof(user1));
            file.close();        
        }
    cout<<"\t\tAccount Successfully created!\n\n\t\t";
    system("pause");
    usermenu();
}
void usersection(){
    start();
    cout<<"\n\n\t\tCitizen Section\n\t\t_______________";
    cout<<"\n\n \t\t1. View copy of FIR ";
    cout<<"\n\t\t2. Status of FIR ";
    cout<<"\n\t\t3. Back\n\n";
    int choice;
    int flag=true;
    while(flag){
        cout<<"\t\tCHOICE : ";
        cin>>choice;
        switch(choice){
            case 1 :   displayfir();
                        flag = false;
                        break;
            case 2 :    firstatus();   
                        flag = false;
                        break;
            case 3 :    homemenu();   
                        flag = false;
                        break;
            default : cout<<"\n\t\tRetry! Wrong choice !\n";
                        break;
        }
    }
}
void firstatus(){
int choice;
    int fir_no;
    fir fir1;
    start();
    bool fir_found = false;
    while(!fir_found){
        cout<<"\n\n\t\tFIR STATUS\n\t\t_________";
        cout<<"\n\t\tEnter FIR Number : ";
        cin>>fir_no;
        fstream file;
        file.open("FIRs.dat",ios::in|ios::binary);
        file.seekg(0);
        file.read((char*)&fir1 , sizeof(fir1));
        while(!file.eof()){
            if(fir_no == fir1.fir_no){
                start();
                cout<<"\n\n\t\tFIR STATUS\n\t\t_________\n\n";
                cout<<"\t\tFIR STATUS : "<<fir1.fir_status<<endl;
                cout<<"\t\t";
                system("pause");
                fir_found = true;
                break;
            }
            else
            {
                file.read((char*)&fir1 , sizeof(fir1));
            }
        }
        file.close();
        if(!fir_found){
            cout<<"\n\t\tFIR DOES NOT EXIST!\n";
            cout<<"\t\t1. Retry\n\t\t2. Back\n";   
            bool flag=true;
            while(flag){
                cout<<"\t\tCHOICE : ";
                cin>>choice;
                switch(choice){
                    case 1 :    flag = false;
                                break;
                    case 2 :    usersection();
                                return;
                                flag = false;
                                break;
                    default :  cout<<"\n\t\tRetry! Wrong choice !\n";
                                break;
                }
            }
        }
    }
    usersection();
}