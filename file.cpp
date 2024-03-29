#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<time.h>
#include<fstream>

using namespace std;

void menu();
void products_data();
void category_display();
void customer_input();
void reciept();
// void user_registration();



class product{
    public:
    int id, price,category;
    string name;
    void input(){
        cin>>id>>category>>name>>price;
    }

    void output(){
        cout<<id<<"\t\t"<<name<<"    \t\t"<<price<<endl;
    }

};

class bill{
     public:
    int id, price,  category, quantity;
    string name;
    void output(){
        cout<<id<<"\t\t"<<name<<"    \t\t"<<price<<"\t\t"<<quantity<<endl;
    }
};



int start_condition, no_of_products, input_category;
vector<product> p;
vector<bill> input_products;



int main()
{
    system("cls");
    start:
    cout<<"If you are seller enter 1"<<endl;
    cout<<"If you are buyer enter 2"<<endl<<endl;
    cout<<"Enter your input here: ";
    cin>>start_condition;
    if (start_condition==1)
    {
        // security:
        string username, password;
        char ch;
        cout<<"Hello owner"<<endl;
        cout<<"please enter username: ";
        cin>>username;
        cout<<"please enter password: ";
        ch = getch();
         while (ch!=13){
            password.push_back(ch);
            cout<<"x";
            ch = getch();
        }
        cout<<endl;        
        
        if (username=="mini_market" && password=="uiet@2025"   )
        {
            products_data();
            cout<<"\n\nProducts have been registered successfully"<<endl<<endl<<endl;
            cout<<"Press any key to return to start"<<endl;
            getch();
            // so that program can pause and start when we enter something
            system("cls");
            // to clear the terminal 
            goto start;
        }
        
        else{
            cout<<"Please enter correct username and password"<<endl<<endl;
            cout<<"press any key to retry";
            getch();
            system("cls");
            goto start;
        }
        
        
    } 

    else if(start_condition==2){
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
//    cout<<"How many products u have ";
    cout<<"Enter the name of Product data file: ";
    string name;
    cin>>name;
    fstream myfile;
    myfile.open(name);
    if(myfile.is_open()){
    myfile>>no_of_products;
    product s1;
    for (int i = 0; i < no_of_products; i++)
    {
        myfile>>s1.id>>s1.category>>s1.name>>s1.price;
        /* code */
        p.push_back(s1);
    }
    
    }  
    else{
        cout<<"error";
    }
    myfile.close();
}

void menu (){
    level_category:
    system("cls");
    cout<<"Hello Dear customer"<<endl<<endl;
    cout<<"Please select the catagory of products you want to buy"<<endl<<endl;
    cout<<"1-> Electronics procducts"<<endl;
    cout<<"2-> Food items "<<endl;
    cout<<"3-> Stationary products"<<endl;
    cout<<"4-> Selfcare products "<<endl;
    cout<<"5-> All products"<<endl<<endl;

    cout<<"Please enter the product category you want to view here: ";
    cin>>input_category;

    system("cls");
    cout<<"Please select the id of product you want to buy"<<endl<<endl;
    switch (input_category)
    {
    case 1:
        cout<<"Id\t\tName    \t\tPrice"<<endl<<endl;
        for (int i = 0; i < no_of_products; i++)
        {
            if (p[i].category==1)
            {
                p[i].output();
            }         
        }
        customer_input();
        break;
    case 2:
        cout<<"Id\t\tName    \t\tPrice"<<endl<<endl;
        for (int i = 0; i < no_of_products; i++)
        {
            if (p[i].category==2)
            {
                p[i].output();
            }
        }
        customer_input();
        break;
    case 3:
        cout<<"Id\t\tName    \t\tPrice"<<endl<<endl;
        for (int i = 0; i < no_of_products; i++)
        {
             if (p[i].category==3)
            {
                p[i].output();
            }
        }
        customer_input();
        break;
    case 4:
        cout<<"Id\t\tName    \t\tPrice"<<endl<<endl;
        for (int i = 0;i < no_of_products; i++)
        {
             if (p[i].category==4)
            {
                p[i].output();
            }
        }
        customer_input();
        break;
    case 5:
        cout<<"Id\t\tName    \t\tPrice"<<endl<<endl;
        for (int i = 0; i < no_of_products; i++)
        {
            p[i].output();
        }
        customer_input();
        break;
    
    default:
        cout<<"Please enter a valid input";
        getch();
        system("cls");
        goto level_category;
        break;
    }
    
}

void customer_input(){
    cout<<"\n\nPress 0 to return to main menu"<<endl<<endl<<endl;
    cout<<"Enter your input here: ";
    int product_input_id, product_quantity;
    cin>>product_input_id;
    if (product_input_id==0 )
    {
        menu();
    }
    
    cout<<"\nEnter the number of pieces you want to buy: ";
    cin>>product_quantity;
    bill b;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].id==product_input_id)
        {
            b.id=p[i].id;
            b.name=p[i].name;
            b.price=p[i].price;
            b.quantity=product_quantity;
            input_products.push_back(b);
        }       
    }
    
    level_customer_input:
    
    cout<<"\n\n\nIf you want to buy more products enter 1"<<endl;
    cout<<"If you want to checkout enter 2"<<endl;
    cout<<"To cancel your order press 3 "<<endl;
    
    int number;
    cin>>number;

    if (number==1)
    {
        menu();
    }
    else if(number == 2){
        reciept();
    }
    else if(number == 3){
        system("cls");
        input_products.clear();
        main();
    } 
    else{
        cout<<"Please enter a valid input"<<endl;
        cout<<"Press any key to continue";
        getch();
        goto level_customer_input;
    }
    
}

void reciept(){
    system("cls");
    int bill_amount=0;
    cout<<"Thanks for purchasing"<<endl<<endl;
    time_t mytime = time(NULL);
    cout<<"Purchase was made at: "<<ctime(&mytime)<<endl;
    cout<<"your bill"<<endl<<endl;
    cout<<"Id\t\tName    \t\tPrice\t\tQuantity"<<endl<<endl;
    for (int i = 0; i < input_products.size() ; i++)
    {
        input_products[i].output();
        bill_amount += (input_products[i].price*input_products[i].quantity);
    }
    
    cout<<"\nTotal amount to be paid: "<<bill_amount<<endl<<endl;
    cout<<"Press any key to exit";
    getch();
    system("cls");
    input_products.clear();
    main();
}

