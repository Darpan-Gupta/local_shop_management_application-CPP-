#include<iostream>
#include<string>
#include<vector>
#include<conio.h>

using namespace std;

void menu();
void products_data();
void costomer_input();
void reciept();



class product{
    int id, price, stock;
    string name;
    public:
    void input(){
        cin>>id>>name>>price>>stock;
    }

    void output(){
        cout<<id<<"\t\t"<<name<<"\t\t"<<price<<"\t\t"<<stock<<endl;
    }
};




int start_condition, no_of_products;
vector<product> p;



int main()
{
    start:
    cout<<"if u are seller enter 1"<<endl;
    cout<<"if u are buyer enter 2"<<endl;
    cin>>start_condition;
    if (start_condition==1)
    {
        products_data();
        cout<<"Products have been registered successfully"<<endl<<endl<<endl;
        cout<<"Press any key to return to start"<<endl;
        getch();
        // so that program can pause and start when we enter something
        system("cls");
        // to clear the terminal 
        goto start;
    } 

    else if(start_condition==2){
        cout<<"Hello Dear customer"<<endl<<"Our Products"<<endl;
        menu();        
    }

    else {
        cout<<"Please enter a valid input"<<endl<<endl<<endl;
        cout<<"Press any key to return to start"<<endl;
        getch();
        system("cls");
        goto start;
    }
    
    return 0;
}


void products_data(){
    cout<<"how many products u have ";
        cin>>no_of_products;
        product a;       
        cout<<"enter id name price and stock";

        for (int i = 0; i < no_of_products; i++)
        {
            a.input();
            p.push_back(a);
        }  
}


void menu (){
     cout<<"id\t\tname\t\tprice\t\tstock"<<endl;
        for (int i = 0; i < no_of_products; i++)
        {
            p[i].output();
        }
}

