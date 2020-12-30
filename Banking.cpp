#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;
class Customer{
    char acc_number[10];
    char first_name[20];
    char last_name[20];
    char t;
    float amount;
    public:
    void opening();
    void deposit();
    void withdrawl();
    void display();
    char *accno();
};
char * Customer::accno(){
    return acc_number;
}
void Customer::opening(){
    fflush(stdin);
    fflush(stdout);
    cout<<"Enter first name"<<endl;
    cin.getline(first_name,20);
    cout<<"Enter last name"<<endl;
    cin.getline(last_name,20);
    cout<<"Enter 10 digit account number"<<endl;
    cin.getline(acc_number,10);
    cout<<"Enter type of account (s) for saving and (c) for current "<<endl;
    cin>>t;
    cout<<"Amount you want to deposit "<<endl;
    cin>>amount;
    cout<<"Your account with Name "<<first_name<<" "<<last_name<<" with balance "<<amount<<" deposit in it\n";
}
void Customer::deposit(){
    fflush(stdin);
    fflush(stdout);
    float a;
    cout<<"Enter amount you want to deposit"<<endl;
    cin>>a; 
    this->amount+=a;
    cout<<"Your account details are :\nName: "<<first_name<<" "<<last_name<<endl;
    cout<<"Account Number "<<acc_number<<" with balance "<<amount<<endl;
}
void Customer::withdrawl(){
    fflush(stdin);
    fflush(stdout);
    float a=0.0;
    char b='n';
    while(b=='n'){
        cout<<"Enter the amount you wish to withdrawl"<<endl;
        cin>>a;
        if(a<amount){
            amount=amount-a;
            b='y';
        }
        else
        {
            cout<<"Enter valid amount"<<endl;
        }
        
    }
    cout<<"Your account details are :\nName: "<<first_name<<" "<<last_name<<endl;
    cout<<"Account Number "<<acc_number<<" with balance "<<amount<<endl;
}
void Customer::display(){
    cout<<"Your account details are :\nName: "<<first_name<<" "<<last_name<<endl;
    cout<<"Account Number "<<acc_number<<" with balance "<<amount<<endl;
}

int main(){
    int a;
    char acc[10];
    char x;
    ifstream fin;
    ofstream fout;
    Customer b;
do{
    cout<<"Select Option from below"<<endl;
    cout<<"1) Open Account"<<endl;
    cout<<"2) Deposit Money"<<endl;
    cout<<"3) Withdrawl Money"<<endl;
    cout<<"4) Display Account"<<endl;
    cout<<"5) Exit"<<endl;
    cin>>a;
    switch(a){
        case 1:
        fflush(stdin);
    fflush(stdout);
        b.opening();
        fout.open("bank.dat",ios::out|ios::binary|ios::app);
        fout.write((char*)&b,sizeof(b));
        fout.close();
        break;
        case 2:
        fflush(stdin);
        fflush(stdout);
        int pos;
        cout<<"Enter the account number";
        cin.getline(acc,10);
        fin.open("bank.dat",ios::in|ios::binary);
        fout.open("bank.dat",ios::out|ios::binary|ios::app);
        while(!fout.eof()){
            pos=fin.tellg();
            fin.read((char*)&b,sizeof(b));
            if(!strcmp(b.accno(),acc)){
                b.deposit();
                fout.seekp(pos);
                fout.write((char*)&b,sizeof(b));
                fout.close();
                fin.close();
                break;
            }
            
        }
        fout.close();
        fin.close();
        break;
        case 3:
        fflush(stdin);
        fflush(stdout);
        cout<<"Enter the account number";
        cin.getline(acc,10);
        fin.open("bank.dat",ios::in|ios::binary);
        fout.open("bank.dat",ios::out|ios::binary|ios::app);
        while(!fout.eof()){
            pos=fin.tellg();
            fin.read((char*)&b,sizeof(b));
            if(!strcmp(b.accno(),acc)){
                b.withdrawl();
                fout.seekp(pos);
                fout.write((char*)&b,sizeof(b));
                fin.close();
                fout.close();
                break;
            }
        }
        fin.close();
        fout.close();
        break;
        case 4:
        fflush(stdin);
        fflush(stdout);
        cout<<"Enter the account number";
        cin.getline(acc,10);
        fin.open("bank.dat",ios::in|ios::binary);
        while(!fin.eof()){
            fin.read((char*)&b,sizeof(b));
            if(!strcmp(b.accno(),acc)){
                b.display();
                fin.close();
                break;
            }
        }
        fin.close();
        break;
        case 5:
        if(a==5){
            exit(1);
        }
        default:
        cout<<"This is not valid try again \n";
    }
    cout<<"Do u want to select next option ::y/n";
    cin>>x;
    if(x=='n'||x=='N')
    exit(1); 
}while(x=='y'||x=='Y');

    return 0;
}