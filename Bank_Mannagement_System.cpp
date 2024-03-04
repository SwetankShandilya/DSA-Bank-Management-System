# include<iostream>
#include<vector>
#include<string>
using  namespace std;
class account_details{

    public:

    string name;
    string address;
    char acc_type;
    int dep_amt;
    int UID;
};


void open_account(vector<account_details>&database){
    account_details temp;
    cout<<"Enter full name:";
    cin.ignore();
    getline(cin,temp.name);
    cout<<endl;

    cout<<"Enter address:";
    getline(cin,temp.address);
    cout<<endl;

    cout<<"Enter account type:";
    cin>>temp.acc_type;
    cout<<endl;

    cout<<"Enter deposit amount:";
    cin>>temp.dep_amt;
    cout<<endl;
    
    temp.UID=database.size();

    cout<<"Account created. Your UID is:"<<temp.UID<<endl;
    database.push_back(temp);
    cout<<endl;
}

void deposit_money(vector<account_details>&database){

    int ind,amt;
    cout<<"Enter your UID:";
    cin>>ind;
    cout<<endl;

    if (ind < 0 || ind >= database.size()) {
        cout << "Invalid UID." << endl;
        return;
    }

    cout<<"Enter amount to be deposited:";
    cin>>amt;
    database[ind].dep_amt+=amt;
    cout<<endl;
    cout<<"Amount deposited.Total account balance:"<<database[ind].dep_amt<<endl;
    cout<<endl;
}

void withdraw_money(vector<account_details>&database){

    int ind,amt;
    cout<<"Enter your UID:";
    cin>>ind;
    cout<<endl;

    if (ind < 0 || ind >= database.size()) {
        cout << "Invalid UID." << endl;
        return;
    }

    cout<<"Enter amount to be withdrawn:";
    cin>>amt;

    if (amt > database[ind].dep_amt) {
        cout << "Insufficient balance." << endl;
        cout<<endl;
        return;
    }

    database[ind].dep_amt-=amt;

    cout<<"Amount withdrawn. Please collect your money."<<endl;
    cout<<"Total account balance:"<<database[ind].dep_amt<<endl;
    cout<<endl;
    cout<<endl;

}

void display_account(vector<account_details>&database){
    int ind;
    cout<<"Enter your UID:";
    cin>>ind;
    cout<<endl;

    cout<<"Account name:"<<database[ind].name<<endl;
    cout<<"Address of account holder:"<<database[ind].address<<endl;
    cout<<"Type of account:"<<database[ind].acc_type<<endl;
    cout<<"The amount in your account is:"<<database[ind].dep_amt<<endl;
    cout<<endl;
}

int main(){

    vector<account_details>database;
    
    while(true)
    {int choice;
    cout<<"Here is the list of actions. Plese choose your desired action:"<<endl;
    cout<<"1. To open account."<<endl;
    cout<<"2. To deposit money in your account."<<endl;
    cout<<"3. To withdraw money."<<endl;
    cout<<"4. To get account details."<<endl;
    cout<<"0. To exit."<<endl;
    cin>>choice;

    switch(choice){

        case 1: open_account(database);
            break;
        case 2: deposit_money(database);
            break;
        case 3: withdraw_money(database);
            break;
        case 4: display_account(database);
            break;
        case 0: exit(0);
            break;
        default : cout<<"Choose a valid option from above.";
    }
}
    return 0;
}