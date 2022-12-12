#include<bits/stdc++.h>
using namespace std; 

/*
Clients can add items to their cart and checkout to successfully place an order
Every nth order gets a 10% discount using a code and can apply to their cart.
design and implement APIs for adding items to cart and checkout functionality.
The checkout API would validate if the discount code is valid before giving the discount.
The store also had two admin API 
1) to generate a discount code if the condition above is satisfied. 
2) Admin API also lists count of items purchased, total purchase amount, 
list of discount codes and total discount amount.
*/

static int discount_code=0; 
// discount code
class Ecommerce_store {
    public:
    // Thses all are for admin
    unordered_map<string,float>products_in_store;
    float total_amount = 0; // Total amount;
    int total_item = 0; // Total no. of item has been purchase
    float discount;
    static float total_discount_amount;
    int nth_customer = 3;
    public:
    Ecommerce_store(){
        discount = 0.1; // 10% discount
    }
    void add_product(string product, float price){
        products_in_store[product]=price;
    }


    void Display(){
        for(auto itr = products_in_store.begin() ; itr!=products_in_store.end(); itr++){
            cout<<itr->first <<"-> "<<itr->second<<" Rs."<<endl;
        }
    }

    void set_n_for_discout(int n){
        nth_customer = n;
    }
    //Checkout validity
    void chechOut(){
        if(discount_code%nth_customer==0){

           total_amount = total_amount - total_amount*discount;
           total_discount_amount += total_amount*discount;
        }
        else{
           total_amount = total_amount;
           total_discount_amount += 0;
        }
    }
    void Validate(){

        if(discount_code%nth_customer != 0){
           cout<<"You are not Eligible for the Discount"<<endl;
        }
        else if(discount_code%nth_customer == 0){
             cout<<"You are Eligible for the Discount"<<endl;
        }
        
    }
    void Display_total_amount(void){
        cout<<"Your total Amount of purchase is : "<<total_amount<<endl;
    }
    void Display_total_items(void){
        cout<<"Your total Amount of purchase is : "<<total_item<<endl;
    }
    
};
float Ecommerce_store :: total_discount_amount =0;
//customer id starting from 100
class customer : public Ecommerce_store{
    private:
    static int cust_id; // Customer id
    string cust_name; // Customer name
    unordered_map<string,float>cart; // It will store the products according to their name
    public:
     // Customer Class
    //Constructor
    customer(string name){

        // The Mandatory things that need to be Set:
        this -> cust_name = name;
        discount_code++;
        cust_id++;
    }
    ~customer(){
        discount_code--;
    }
    
    // friend class Ecommerce_store;  Ecommerse store is a freind class of Customer so that it can access the 
    // the private memeber of the customer
    
     // Function to add items
    void add_Item(string product, int quantity){
        
        cart[product] = products_in_store[product]*quantity;
        // Total_price
        total_amount += products_in_store[product]*quantity;
        total_item += quantity;
    }

    void Display_amout_of_purchase(){

         float total_cart_value = 0.0;
         for(auto itr = cart.begin() ; itr!= cart.end(); itr++){
           total_cart_value += itr->second;
        }
        cout<<"Your Total value of Cart is : "<<total_cart_value<<endl;
    }

    void get_cust_name(void){
        cout<<"Your Customer Name is : "<<cust_name<<endl;
    }
    void get_cust_id(void){
         cout<<"Your Customer ID is : "<<cust_id<<endl;
    }
    
};   
int customer :: cust_id = 100;

int main(){
    
    Ecommerce_store Singh_limited;
    Singh_limited.set_n_for_discout(3);

    Singh_limited.add_product("Sticker",10.0);
    Singh_limited.add_product("Tyre",200.0);
    Singh_limited.add_product("flower",50.0);
    Singh_limited.add_product("spoon",15.0);
    Singh_limited.add_product("plate",40.0);

    Singh_limited.Display();

    customer first("Prateek");
    first.add_Item("sticker",4);
    first.add_Item("spoon",3);
    first.get_cust_name();
    first.get_cust_id();
    first.Display_amout_of_purchase();
    first.Validate();

    cout<<endl;

    customer second("Ketan");
    second.add_Item("plate",2);
    second.add_Item("flower",6);
    second.get_cust_name();
    second.get_cust_id();
    second.Validate();

    cout<<endl;

    customer third("Puneet");
    third.add_Item("plate",2);
    third.add_Item("flower",6);
    third.get_cust_name();
    third.get_cust_id();

    third.Validate();


    return 0;          
}                      