#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

class Address  //this class aggregated by Registration class
{
    private:
        string houseNo;
        string locality;
        string city;
        string pin;

    public:
        Address(string h = "",string l ="",string c ="",string p ="")
        {
            houseNo = h;
            locality = l;
            city = c;
            pin = p;
        }
        void SetAddress()
        {
            cout<<"Enter your house number: ";
            cin>>houseNo;
            cin.ignore();
            cout<<"Enter your locality: ";
            getline(cin,locality);
            cout<<"Enter your city name: ";
            getline(cin,city);
            cout<<"Enter your pincode: ";
            cin>>pin;
        }
        string getFullAddress()
        {
            return houseNo+","+locality+","+city+","+pin+".";
        }
};
class Registration
{
    string Full_Name;
    string gender;
    string Phone_Number;
    string email;
    Address *address; //Aggregation
    string username;
    string password;
    string retrieve_un;
    string retrieve_pw;
    

    public:
     Registration(); //default constructor
     void setFull_Name()
     {
        cout<<"Enter your full name : ";
        cin.ignore();
        getline(cin,Full_Name);
     }

     string getFull_Name()
     {
        return Full_Name;
     }
     void setGender()
     {
     A:
        cout<<"Are you Male or Female :";
        cin>>gender;
        if((gender=="Male") || (gender=="male") || (gender=="Female") || (gender=="female"))
        {
        }
        else
        {
            cout<<"Input Error! Please try again.\n";
            goto A;
        }
     }

     string getGender()
     { return gender;}

     void setPhone_Number()
     {
        cout<<"Enter your phone number: ";
        cin>>Phone_Number;
     }
     string getPhone_Number()
     {return Phone_Number;}

     void setEmail()
     {
        cout<<"Enter your email address: ";
        cin.ignore();
        getline(cin,email);
     }
     string getEmail()
     {return email;}

     void setAddress()
     {
        address->SetAddress();
     }
     string getAddress()
     {return address->getFullAddress();}
     
     

     bool enter();                       //Asks for registration of people
     void DoRegistration();              //user registration form
     void Register_administrator();
     void Register_customer();
     bool DoLogin();                     //this function ask and verifies id and password for user login
     ~Registration() { delete address; }     //destructor
};

Registration::Registration()  //outsider member function
{
    username = password = retrieve_un = retrieve_pw = "";
    address= new Address;
}

bool Registration::enter()
{
    int choice;
    cout<<endl
        <<"\t(1).Registration\n"
        <<"\t(2).Log-In\n"
        <<"\tChoose an option- ";
    cin>>choice;
    std::system("cls");
    if(choice ==1)
    {
        DoRegistration();
        Register_customer();
    }
    if(choice==2)
    {
       return DoLogin();
    }
    return true;
}

void Registration::DoRegistration()
{
    cout<<"--------------------------------------"<<endl
        <<"         ACCOUNT REGISTRATION         "<<endl
        <<"--------------------------------------"<<endl
        <<endl
        <<endl;
    setFull_Name();
    setGender();
    setPhone_Number();
    setEmail();
    address->SetAddress();
    cout << endl
         <<endl;
}
void Registration::Register_administrator()
{

    ofstream file;
    file.open("user.dat",ios::binary | ios::app);
    file<<getFull_Name()<<endl;
    file<<getGender()<<endl;
    file<<getPhone_Number()<<endl;
    file<<getEmail()<<endl;
    file<<getAddress()<<endl;
    file.close();
    cout<<"\nDear User,Your Registration is Successful!!"<<endl;
  
}
void Registration::Register_customer()
{
    cout<<"Enter any username: ";
    cin>>username;
    cout<<"Enter any password: ";
    cin>>password;
    ofstream file;
    file.open("user.dat",ios::binary | ios::app);
    file<<username<<endl;
    file<<password<<endl;
    file<<getFull_Name()<<endl;
    file<<getGender()<<endl;
    file<<getPhone_Number()<<endl;
    file<<getEmail()<<endl;
    file<<getAddress()<<endl;
    file.close();
    
    int choice;
    cout<<"\nDear User,Your Registration is Successful!!"<<endl;
B:
    cout<<"\nPlease choose what you would like to do."
        <<"\n(1).Log-In"
        <<"\n(2).Exit"
        <<"\nChoose an option";
    cin>>choice;
    if(choice == 1)
    {
        DoLogin();
    }

    else if(choice == 2)
    {
        exit(0);
    }
    else
    {
        cout<<"\nInput Error!\n";
        goto B;
    }
}

bool Registration::DoLogin()
{
    A:
    std::system("cls");
    cout<<"-----------------------------"<<endl
        <<"         USER LOG IN         "<<endl
        <<"-----------------------------"<<endl
        <<endl
        <<endl;
        
    cout<<"Enter your username: ";
    cin>>username;
    cout<<"Enter your password: ";
    cin>>password;

    ifstream getfile("user.dat");
    
    if (!getfile.is_open()) {
        cout << "Error: Unable to open user.dat" << endl;
         return false;
    }

    bool loggedIn = false;
    string storedUsername;
    string storedPassword;
        
        while (getfile >> storedUsername)
        {
            if (storedUsername == username)
            {
                getfile >> storedPassword;
                if(storedPassword == password)
                {
                    loggedIn = true;
                    break;
                }
            }
        }
        getfile.close();
        if (loggedIn)
        {
            cout << endl
                 << "Login successful..." << endl
                 << endl;
            return true;
        }
        else 
        {
            cout << endl
                 << "Invalid username or password" << endl
                 <<"Try again\n\n";
            std::system("pause");
            return false;
        }
}


class Product
{
    private:
        string product_ID;
        string product_Name;
        double product_Price;
    public:
        Product(string id = "",string name = "",double price = 0.0)
        {
            product_ID=id;
            product_Name=name;
            product_Price=price;
        }
        
        virtual string getID()
        {
            return product_ID;
        }

        string getName()
        {
            return product_Name;
        }
        double getPrice()
        {
            return product_Price;
        }
        void displayProduct()
        {
            cout<<setw(10)<<product_ID<<setw(30)<<product_Name<<setw(20)<<product_Price<<endl;
        }



};

class Product_List
{
    private:
        vector<Product> productList;
    public:
        void products(vector<Product>& p)
        {
            productList = p;
        }
        void displayProduct_List()
        {
            cout<<setw(15)<<"Product_ID"<<setw(25)<<"Product_Name"<<setw(20)<<"Product_Price\n";
            for(int i=0 ; i < productList.size() ; i++)
            {
                productList[i].displayProduct();
            }
        }
        virtual void addProduct(string i,string n,double p)
        {
            int count=0;
            for(int a=0;a<productList.size();a++)
            {
                if(productList[a].getID() == i)
                {
                    cout<<"Enter unique product id\n\n";
                    count++;
                    break;
                }
            }
            if(count == 0)
            {
                productList.emplace_back(i,n,p);
            }
            
            displayProduct_List();
        }
        void removeProduct(string r)
        {
            vector<Product>::iterator it;
            for(it = productList.begin(); it != productList.end(); ++it)
            {
                if(it->getID() == r)
                {
                    it = productList.erase(it); 
                        break; 
                }
            }
            displayProduct_List();    
        }
        virtual vector<Product> getproductList()
        {
            return productList;
        }

};


class Administrator :public Registration,public Product_List
{
    string Admin_ID;

    public:
     Administrator(){}

     void setID()
     {
     S:
        int choice;
        cout<<"\nDo you want to register or login?\n"
            <<"(1)Register.\n"
            <<"(2)Login."
            <<endl
            <<endl;
        cin>>choice;
        if(choice == 1)
        {
            Registration::DoRegistration();
            Registration::Register_administrator();
            M:
            {
            int x;
            cout<<"\nDo you want to login or exit?\n"
            <<"(1)Login.\n"
            <<"(2)Exit."
            <<endl;
            cin>>x;
            if(x==1)
            {
               cout<<"Enter your staff id: ";
            cin>>Admin_ID;
            if((Admin_ID == "123456") || (Admin_ID == "098765") || (Admin_ID == "956874") || (Admin_ID == "563537"))
            {
                cout<<"Login Successful !!!\n\n";
            }
            else
            {
                cout<<"Invalid staff id!Please try again.\n";
                goto S;
            } 
            }
            else if(x==2)
            {
                exit(0);
            }
            else
            {
                cout<<"\n Input error. Try again.";
                goto M;
            }
            }
        } 
        else if(choice == 2)
        {
            cout<<"Enter your staff id: ";
            cin>>Admin_ID;
            if((Admin_ID == "123456") || (Admin_ID == "098765") || (Admin_ID == "956874") || (Admin_ID == "563537"))
            {
                cout<<"Login Successful !!!\n\n";
            }
            else
            {
                cout<<"Invalid staff id!Please try again.\n";
                goto S;
            }
        }
        else
        {
            cout<<"\nInput Error!Please try again.\n";
            goto S;
        }
     }
     void setAdmin_Details()
     {
        setID();
     }

    void addProduct() //Polymorphism function
     {
        int count;
        cout<<"\nAdd Products: \n"
            <<"How many products do you want to add ? : ";
        cin>>count;

        for(int i=0;i<count;i++)
        {
            string id,name;
            double price;
            cout<<"#"<<i+1<<endl
                <<"Give product ID : ";
            cin.ignore();
            cin>>id;
            cout<<"Give product name : ";
            cin.ignore();
            getline(cin,name);
            cout<<"Give product price : ";
            cin>>price;

            Product_List::addProduct(id,name,price);
        }
        cout<<endl;
     }

     void removeProduct()
     {
        int count;
        string id;
        std::system("cls");
        cout<<"\nRemove Product: \n"
            <<"How many products do you want to remove ? : ";
        cin>>count;

        for(int i= 0; i<count; i++)
        {
            

            cout<<"Mention product id: ";
            cin>>id;
            Product_List::removeProduct(id);
            
            cout<<endl;
        }
     }
    vector<Product> getproductList()
    {
        return Product_List::getproductList();
    }
};

class Shopping_Cart
{
    protected:
        vector<Product> SelectedProduct;
        double TotalPrice =0.0;
        string id="";
        string name;
        int ADD;
    
    public:
        Shopping_Cart()
        {
        }

        void calcTotalPrice()
        {
            for(int i = 0; i<SelectedProduct.size();i++)
            {
                TotalPrice += SelectedProduct[i].getPrice();
            }
        }
        double getTotal_Price()
        {
            return TotalPrice;
        }
        int getTotal_Quantity()
        {
            return SelectedProduct.size();
        }
        
        void addSelectedProduct(vector<Product>& p)
        {
            int count;
            int j;
            cout<<"\n\nAdd to Shopping Cart\n"
                <<"How many products do you want to purchase ? : ";
            cin>>count;

            for(int i = 0; i<count; i++)
            {
                T:
                cout<<"#"<<i+1<<endl
                    <<"Write Product ID: ";
                cin>>id;

                for( j=0;j<p.size();j++)
                {
                    if(p[j].getID() == id)
                    {
                        ADD=j;
                        break;
                    }
                    
                }
                if(ADD==j)
                {
                SelectedProduct.emplace_back(p[ADD].getID(),p[ADD].getName(),p[ADD].getPrice());    
                }
                else{
                    cout<<"Enter a valid product id.\n";
                goto T;
                }
            }
            
            cout<<endl;
        }
        void removeProduct()
        {
            int count;
            string id;
            S:
            cout<<"Write product id : ";
            cin>>id;

            int RE;
            int i;
            for(i=0;i<SelectedProduct.size();i++)
            {
                if(SelectedProduct[i].getID() == id)
                {
                    RE=i;
                    break;
                }
            }
            if(RE == i)
            {
                SelectedProduct.erase(SelectedProduct.begin() + RE);
                Shopping_Cart::displaySelectedProduct();
            }
            else
            {
                cout<<"Enter a valid product id.\n";
                goto S;
            }
            
        
            cout<<endl;
        }

        void displaySelectedProduct()
        {
            std::system("cls");
            cout<<"-------------------------------------------------------"<<endl
                <<"                          MY                           "<<endl
                <<"                     SHOPPING CART                     "<<endl
                <<"-------------------------------------------------------"<<endl
                <<endl
                <<endl;
            cout<<setw(15)<<"PRODUCT_ID"<<setw(25)<<"PRODUCT_NAME"<<setw(20)<<"PRODUCT_PRICE\n";
            for(int i=0;i<SelectedProduct.size();i++)
            {
                SelectedProduct[i].displayProduct();
            }
            cout<<endl;
        }
        void ClearCart()
        {
            SelectedProduct.clear();
        }
};

class Payment
{
    private:
        double PayNetAmount;
        string cardNumber,digit;
        int pinNumber,payment,upin;
        string ibankUserId,ibankingPassword;
        string upi;
    public:
        Payment()
        {
        }
        Payment(double PayNetAmount,string cardNumber,int pinNumber,string ibankUserId,string ibankingPassword,int upin,string upi)
        {
            this->PayNetAmount = PayNetAmount;
            this->cardNumber = cardNumber;
            this->pinNumber = pinNumber;
            this->ibankUserId = ibankUserId;
            this->ibankingPassword = ibankingPassword;
            this->upi = upi;
            this->upin = upin;

        }
        void setPayNetAmount(double PayNetAmount)
        {
            this->PayNetAmount = PayNetAmount;
        }
        
        double getPayNetAmount()
        {
            return PayNetAmount;
        }
        string getCardNumber()
        {
            return cardNumber;
        }
        int getPinNumber()
        {
            return pinNumber;
        }
        int getpayment()
        {
            return payment;
        }
        string getIbankUserId()
        {
            return ibankUserId;
        }
        string getIbankingPassword()
        {
            return ibankingPassword;
        }
        string getdigit()
        {
            return digit;
        }
        string getupi()
        {
            return upi;
        }
        int getupin()
        {
            return upin;
        }
        void paymentpreference()
        {
        A:    
            cout<<"-------------------------------------"<<endl
                <<"   PLEASE CHOOSE A PAYMENT GATEWAY   "<<endl
                <<"-------------------------------------"<<endl
                <<"(1).DEBIT/CREDIT CARD"<<endl
                <<"(2).ONLINE BANKING"<<endl
                <<"(3). UPI PAYMENT GATEWAY"<<endl
                <<"(4). CASH ON DELIVERY"<<endl
                <<"CHOOSE AN OPTION";
            cin>>payment;
            std::system("cls");

            switch(payment)
            {
                case 1:
                    cout<<"-------------------------------"<<endl
                        <<"   DEBIT/CREDIT CARD PAYMENT   "<<endl
                        <<"-------------------------------"<<endl
                        <<endl;
                    
                    cout<<"Enter your card number : ";
                    cin>>cardNumber;
                    cout<<"Enter your pin         : ";
                    cin>>pinNumber;
                    cout<<"\nNet Amount:"<<getPayNetAmount()<<"Rs. Card No. ************";
                    for(int i=(cardNumber.length()-4.0);i<=cardNumber.length(); i++)
                    {
                        digit += cardNumber[i];
                    }
                    cout<<digit<<"\n";
                    cout<<"Rs."<<PayNetAmount<<" has been deducted from your account.\n\n\n";
                    cout<<"-------------------------------------"<<endl
                        <<"          PAYMENT SUCCESSFUL         "<<endl
                        <<"-------------------------------------"<<endl
                        <<endl
                        <<endl;
                    cout<<"For Receipt,"<<endl;
                    std::system("pause");
                    std::system("cls");
                    break;
                
                case 2:
                    cout<<"-------------------------------"<<endl
                        <<"    ONLINE BANKING PAYMENT     "<<endl
                        <<"-------------------------------"<<endl
                        <<endl;
                    cout<<" ENTER YOUR ONLNE BANKING ID : ";
                    cin>>ibankUserId;
                    cout<<" ENTER YOUR PASSWORD         : ";
                    cin>>ibankingPassword;
                    cout<<"\nRs."<<getPayNetAmount() << " has been deducted from your account.\n\n\n"
                        <<"----------------------------------"<<endl
                        <<"       PAYMENT SUCCESSFUL         "<<endl
                        <<"----------------------------------"<<endl
                        <<endl
                        <<endl;
                    cout<<"For Receipt,"<<endl;
                    std::system("pause");
                    std::system("cls");
                    break;
                case 3:
                    cout<<"-------------------------------"<<endl
                        <<"      UPI PAYMENT GATEWAY      "<<endl
                        <<"-------------------------------"<<endl
                        <<endl;
                    cout<<" ENTER UPI ID : ";
                    cin>>upi;
                    cout<<" ENTER YOUR PIN : ";
                    cin>>upin;
                    cout<<"\nRs."<<getPayNetAmount() << " has been deducted from your account.\n\n\n"
                        <<"----------------------------------"<<endl
                        <<"       PAYMENT SUCCESSFUL         "<<endl
                        <<"----------------------------------"<<endl
                        <<endl
                        <<endl;
                    cout<<"For Receipt,"<<endl;
                    std::system("pause");
                    std::system("cls");
                    break;
                case 4:
                    cout<<"-------------------------------"<<endl
                        <<"        CASH ON DELIVERY       "<<endl
                        <<"-------------------------------"<<endl
                        <<endl;
                    cout<<"\n You need to pay Rs."<<getPayNetAmount() << " in cash to the delivery incharge.\n\n"
                    <<endl
                        <<endl;
                    cout<<"For Receipt,"<<endl;
                    std::system("pause");
                    std::system("cls");
                    break;
                default:
                    cout<<"\nInput Error!\n";
                    goto A;
            }
        }
};

class Customer : public Registration, public Shopping_Cart
{
private:
   Payment payment;
   int count;

public:
   Customer()
   {

   }
   void setCustomerDetails()
   {
    Registration :: enter();
   }
   void print()
   {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    localTime->tm_hour;
    localTime->tm_min;

    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localTime);
    std::system("cls");
    cout<<"----------------------------------------------"<<endl
        <<"               CUSTOMER INVOICE               "<<endl
        <<"**********************************************"<<endl
        <<"    E-COMMERCE SHOPPING MANAGEMENT SYSTEM     "<<endl
        <<endl;

    for (int i = 0 ; i < 1; i++)
    {
        int value=rand();
        cout<<"Transaction Number      :NADSN6367CHS"<<value<<"\n";

    }
    cout<<"Date and Time is        : "<<buffer<<endl;
    cout<<"Customer Name           : "<<Registration::getFull_Name()<<endl
        <<"Customer Gender         : "<<Registration::getGender()<<endl
        <<"Customer Contact Number : "<<Registration::getPhone_Number()<<endl
        <<"Customer Email          : "<<Registration::getEmail()<<endl
        <<"Shipping Address        : "<<Registration::getAddress()<<endl
        <<endl
        <<setw(15)<<"Product-ID"<<setw(25)<<"Product Name"<<setw(20)<<"Product Price\n";

    for (int i=0;i<SelectedProduct.size();i++)
    {
        cout<<setw(15)<<Shopping_Cart::SelectedProduct[i].getID()<<setw(25)
            <<Shopping_Cart::SelectedProduct[i].getName()<<setw(20)
            <<Shopping_Cart::SelectedProduct[i].getPrice()<<endl;
    }
    cout<<"\nTotal Item        : "<<Shopping_Cart::getTotal_Quantity()<<endl
        <<"Total cost        : "<<Shopping_Cart::getTotal_Price()<<endl
        <<endl;
    if(payment.getpayment() == 1)
    {
        cout<<"Card Payment     : "<<Shopping_Cart::getTotal_Price()<<endl
            <<"Card digit       : ************";
        cout<<payment.getdigit();
        cout<<"\n\n";
        cout<<"\n\n************************************************"<<endl
        <<endl
        <<"           Exchange and Refund may be allowed   \n"
        <<"      Within 3 days with the original tax invoice  \n"
        <<"               Thanks for your patience.      \n";
    }
    else if(payment.getpayment() == 2)
    {
        cout<<"Your online bank id    :";
        cout<<payment.getIbankUserId()<<endl;
        cout<<"Rs."<<Shopping_Cart::getTotal_Price()<<"has been deducted from your account.\n\n";
        cout<<"\n\n************************************************"<<endl
        <<endl
        <<"           Exchange and Refund may be allowed   \n"
        <<"      Within 3 days with the original tax invoice  \n"
        <<"               Thanks for your patience.      \n";
    }
    else if(payment.getpayment() == 3)
    {
        cout<<" Your upi id   :";
        cout<<payment.getupi()<<endl;
        cout<<"Rs."<<Shopping_Cart::getTotal_Price()<<"has been deducted from your account.\n\n";
        cout<<"\n\n************************************************"<<endl
        <<endl
        <<"           Exchange and Refund may be allowed   \n"
        <<"      Within 3 days with the original tax invoice  \n"
        <<"               Thanks for your patience.      \n";
    }
    else
    {
        cout<< "Pay Rs. "<<Shopping_Cart::getTotal_Price()<<" once your order is delivered.\n\n";
        cout<<"\n\n************************************************"<<endl
        <<endl
        <<"                Exchange may be allowed   \n"
        <<"      Within 3 days with the original tax invoice  \n"
        <<"               Thanks for your patience.      \n";
    }
    Shopping_Cart::ClearCart();
    
   }

   void Shopping_Cart_Details(vector<Product>& p)
   {
    Shopping_Cart::addSelectedProduct(p);
    Shopping_Cart::displaySelectedProduct();
    
    cout<<"Do you want to remove any product ?\n"
        <<"(1).Yes\n"
        <<"(2).No\n"
        <<"Choose an option";
    cin>>count;
    if(count == 1)
    {
        Shopping_Cart::removeProduct();
    }
    Shopping_Cart::displaySelectedProduct();
    
   }

   void PaymentWork()
   {
    Shopping_Cart::calcTotalPrice();
    cout<<"\nTotal item             :"<<Shopping_Cart::getTotal_Quantity()<<endl
        <<"Total cost             :"<<Shopping_Cart::getTotal_Price()<<"Rs"<<endl
        <<endl;
    payment.setPayNetAmount(Shopping_Cart::getTotal_Price());
    payment.paymentpreference();
   }

};

int main()
{
    Administrator admin;
    Customer customer;

    vector<Product> product;
    
                product.emplace_back("1","Jeans",2000.00);
                product.emplace_back("2","Shirt",750.45);
                product.emplace_back("3","Shorts",399.99);
                product.emplace_back("4","Cargo",2499.16);
                product.emplace_back("5","Jacket",3200.74);
                product.emplace_back("6","Dress",1500.60);
                product.emplace_back("7","Trousers",1600.56);
                product.emplace_back("8","Oversized Tees",600.80);
                product.emplace_back("9","Funky Pyjamas",1000.28);
                product.emplace_back("10","Co-ord Set",2700.88);

    admin.products(product);
    std::system("cls");

    string userType;
    cout << "****************************************************" << endl
        << "|   WELCOME TO ONLINE SHOPPING MANAGEMENT SYSTEM   |" << endl
        << "****************************************************" << endl
        << endl
        << endl;
    A:
    while (true)
    {
        try
        {
        cout << "Are you an Administrator or Customer?" << endl;
        cout << "(1).Administrator" << endl;
        cout << "(2).Customer" << endl;
        cout << "Enter your choice : ";
        cin >> userType;
        if(userType == "1")
        {
            admin.setID();
            cout<<"*****************************************************************"<<endl
                <<"                         PRODUCTS AVAILABLE                      "<<endl
                <<"*****************************************************************"
                <<endl
                <<endl;
            admin.displayProduct_List();
        
            int adminChoice;
            B:
                while (true)
                {
                    cout << "\nAdmin Tasks:" << endl;
                    cout << "(1). Add Product" << endl;
                    cout << "(2). Remove Product" << endl;
                    cout << "(3). Logout" << endl;
                    cout << "Choose an option: ";
                    cin >> adminChoice;

                    switch (adminChoice)
                    {
                      case 1:{
                        admin.addProduct();
                        product.clear();
                        product=admin.getproductList();
                        break;
                      }
                      case 2:{
                        admin.removeProduct();
                        product.clear();
                        product=admin.getproductList();
                        break;
                      }
                      case 3:
                        cout << "Logging out...\n\n" << endl;
                        goto A;
                        break;
                      default:
                        cout << "Invalid option. Please choose again." << endl;
                        goto B;
                    }
                    goto B;
                    if (adminChoice == 3)
                    {
                        break; // Logged Out
                    }
                    goto A;
                    
                }
                
        }
            
        
        else if (userType == "2")
        {
            C:
            cout << "Customer Portal:" << endl;
            if (customer.enter()) 
            {
                int customerChoice;
                while (true) 
                {
                
                    cout << "Welcome, " << customer.getFull_Name() << "!" << endl;
                    cout << "Customer Tasks:" << endl;
                    cout << "(1). View Products" << endl;
                    cout << "(2). Add Products to Cart" << endl;
                    cout << "(3). Remove Product from Cart" << endl;
                    cout << "(4). Checkout" << endl;
                    cout << "(5). Logout" << endl;
                    cout << "Choose an option: ";
                    cin >> customerChoice;

                    switch (customerChoice) 
                    {
                        case 1:
                            // Display products available for purchase
                            admin.displayProduct_List();
                            break;
                        case 2:
                            // Add products to the shopping cart
                            customer.Shopping_Cart_Details(product);
                            break;
                        case 3:
                            // Remove products from the shopping cart
                            customer.removeProduct();
                            break;
                        case 4:{
                            // Proceed to checkout and payment
                            customer.PaymentWork();
                            customer.print();
                            break;
                        }
                        case 5:
                            cout << "Logging out...\n\n" << endl;
                            break;
                        default:
                            cout << "Invalid option. Please choose again." << endl;
                    }

                    if (customerChoice == 5)
                    {
                        break; // Break the inner loop to logout
                    }
                }
            }
            else
            {
                goto C;
            }
        
        }
        else
        {
            throw(userType);
        }
        }
        catch(...)
        {
            cout<<"Enter a valid choice\n\n";
        }
    }
    
    return 0;
}