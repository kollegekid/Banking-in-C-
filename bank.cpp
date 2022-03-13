#include<bits/stdc++.h>
using namespace std;
long main_balance =0;
int menu();
int deposit(){
    cout<<"Enter deposit Amount\n";
    long lamount;
    cin>>lamount;
    if(lamount>0){
        main_balance += lamount;
        cout<<"Amount added Successfully\n";
    }
    cout<<"Do you want any other transaction?\n";
    cout<<"If 'Yes' Press '1' otherwise Press '0'\n";
    int t;
    cin>>t;
    if(t==1){
        menu();
    }
    return 0;
}
int withdraw(){
    cout<<"Enter Withdraw Amount\n";
    long wamount;
    cin>>wamount;
    if(wamount>0 && wamount<= main_balance){
        main_balance = main_balance - wamount;
        cout<<"Amount Withdrawn Successfully.\n";
    }
    else if(wamount> main_balance){
        cout<<"Transaction failed due to insufficient Balance\n";
    }
    else {
        cout<<"Invalid Amount\n";
    }
    cout<<"Do you want any other transaction?\n";
    cout<<"If 'Yes' Press '1'\n";
    int t;
    cin>>t;
    if(t==1){
        menu();     
    }
    return 0;
}
int balenq(){
    cout<<"Your Current Balance is : "<<main_balance<<" Rs\n"<<endl;
    cout<<"Do you want any other transaction?\n";
    cout<<"If 'Yes' Press '1'\n";
    int t;
    cin>>t;
    if(t==1){
        menu();
    }
    return 0;
}





int menu(){
    cout<<"1. Deposit"<<endl<<"2. Withdraw"<<endl<<"3. Balance Enquiry"<<endl;
    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
        deposit();
        break;
    case 2:
        withdraw();
    case 3:
        balenq();
    
    default:
        exit(1);
    }
    return 0;
}
int pinenter(){
    static int s = 0;
    if(s==0){
        cout<<"Enter PIN\n";
    }
    else{
        cout<<"Re-enter PIN\n";
    }
    int pin ; 
    cin>>pin;
    if(pin>999 && pin <10000  ){
            menu();
    }
    else{
        
        cout<<"Wrong PIN\n";
       s++;
       pinenter();  
       
    }
    return 0;
}
bool process_transaction(int &a,int &b){
    if (a==b){
        
        return true;
    }
    else {
        return false;
        
    }
}

int main(){
    cout<<"Welcome to SBI\n";
    srand(time(0));
    int l1 = rand()%10000;
    cout<<l1<<endl;
    cout<<"Enter the numbers below\n";
    int l2;
    cin>>l2;
    
    bool tf = true;
    while (true)
    {   
        tf = process_transaction(l1,l2);
        if(tf){
            pinenter();
            cout<<"Thank you for banking\n";
            exit(1);
        }
        else{
            cout<<"Enter correct numbers\n";
            cin>>l2;
            tf = process_transaction(l1,l2);
        }
    }
    


    return 0;

}