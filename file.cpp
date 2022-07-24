#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<time.h>

using namespace std;

void menu();
void products_data();
void category_display();
void customer_input();
void reciept();



class product{
    public:
    int id, price,category;
    string name;
    void input(){
        cin>>id>>category>>name>>price;
    }

    void output(){
        cout<<id<<"\t\t"<<name<<"\t\t"<<price<<endl;
    }

};

class bill{
     public:
    int id, price,  category, quantity;
    string name;
    void output(){
        cout<<id<<"\t\t"<<name<<"\t\t"<<price<<"\t\t"<<quantity<<endl;
    }
};



int start_condition, no_of_products, input_category;
vector<product> p;
vector<bill> input_products;



int main()
{
    system("cls");
    start:
    cout<<"if u are seller enter 1"<<endl;
    cout<<"if u are buyer enter 2"<<endl;
    cin>>start_condition;
    if (start_condition==1)
    {
        // security:
        string username, password;
        cout<<"hello owner"<<endl;
        cout<<"please enter username: ";
        cin>>username;
        cout<<"please enter password: ";
        cin>>password;
        if (username=="jaggi" && password=="xyz"   )
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
        
        else{
            cout<<"Please enter correct username and password"<<endl<<endl;
            cout<<"press any key to retry";
            getch();
            system("cls");
            goto start;
        }
        
        
    } 

    else if(start_condition==2){
        // category_display();
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
        cout<<"enter id category name and price of the product"<<endl;

        for (int i = 0; i < no_of_products; i++)
        {
            a.input();
            p.push_back(a);
        }  
}

void menu (){
    level_category:
    system("cls");
    cout<<"Hello Dear customer"<<endl;
    cout<<"Please select the catagory of products you want to buy"<<endl<<endl;
    cout<<"To view electronics procducts enter 1"<<endl;
    cout<<"To view food items enter 2"<<endl;
    cout<<"To view stationary products enter 3"<<endl;
    cout<<"To view selfcare products 4"<<endl;
    cout<<"To view all products enter 5"<<endl;
    cin>>input_category;

    system("cls");

    switch (input_category)
    {
    case 1:
        cout<<"id\t\tname\t\tprice"<<endl<<endl;
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
        cout<<"id\t\tname\t\tprice"<<endl<<endl;
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
        cout<<"id\t\tname\t\tprice"<<endl<<endl;
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
        cout<<"id\t\tname\t\tprice"<<endl<<endl;
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
        cout<<"id\t\tname\t\tprice"<<endl<<endl;
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
    cout<<"\n\nEnter the id the product you want to buy"<<endl<<"Or if you want to return to main menu enter 0 "<<endl;
    int product_input_id, product_quantity;
    cin>>product_input_id;
    if (product_input_id==0 )
    {
        menu();
    }
    
    cout<<"how many pieces you want to buy: "<<endl;
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
    
    cout<<"If you want to buy more products enter 1"<<endl;
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
    cout<<"id\t\tname\t\tprice\t\tquantity"<<endl;
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

