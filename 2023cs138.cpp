#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
using namespace std;


void gotoxy(int x, int y){
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void border(){
    
    for(int i=0; i<80; i++){
        
        gotoxy(i,0);
        cout<<"-";
        gotoxy(i,40);
        cout<<"-";

    }

}

void clearScreen()
{
    gotoxy(50,35);
    cout << "Press Any Key to Continue" << endl;
    getch();
    system("cls");
}

void header(){


    gotoxy(20,5);
    cout<<"#     #                                    #####                              "<<endl;         
    gotoxy(20,6);
    cout<<"#     # ######   ##   #      ##### #    # #     # #    #   ##   #####  #####  "<<endl; 
    gotoxy(20,7);
    cout<<"#     # #       #  #  #        #   #    # #       #    #  #  #  #    # #    # "<<endl;
    gotoxy(20,8);
    cout<<"####### #####  #    # #        #   ###### #  #### #    # #    # #    # #    # "<<endl;
    gotoxy(20,9);
    cout<<"#     # #      ###### #        #   #    # #     # #    # ###### #####  #    # "<<endl;
    gotoxy(20,10);
    cout<<"#     # #      #    # #        #   #    # #     # #    # #    # #   #  #    # "<<endl;
    gotoxy(20,11);
    cout<<"#     # ###### #    # ######   #   #    #  #####   ####  #    # #    # #####  "<<endl;
                                                                                                                                                                     
}

void signInBorder(){

    header();

    gotoxy(44,15);
    cout<<"-----------------------------"<<endl;
    gotoxy(44,16);
    cout<<"'                           '"<<endl;
    gotoxy(44,17);
    cout<<"'                           '"<<endl;
    gotoxy(44,18);
    cout<<"'                           '"<<endl;
    gotoxy(44,19);
    cout<<"'                           '"<<endl;
    gotoxy(44,20);
    cout<<"'                           '"<<endl;
    gotoxy(44,21);
    cout<<"'                           '"<<endl;
    gotoxy(44,22);
    cout<<"-----------------------------"<<endl;

}

int mainMenu(){

    header();
    signInBorder();

    int choice;

    do {
        gotoxy(48,17);
        cout<<"1. Admin Login";
        gotoxy(48,18);
        cout<<"2. User Login";
        gotoxy(48,19);
        cout<<"3. Exit";

        gotoxy(50,25);
        cout<<"Desired action: ";
        cin>>choice;

        if(choice < 1 || choice > 3) {
            gotoxy(50,28);
            cout << "Invalid choice.";
            cin>>choice;
        }
    
    } while(choice < 1 || choice > 3);

    clearScreen();
    return choice;

    
    

}

bool adminLogin(string adminusername, string adminpassword){

    header();
    signInBorder();

    string username, password;
           
    gotoxy(48,17);
    cout<<"Username: ";
    cin>>username;

    gotoxy(48,18);
    cout<<"Password: ";                
    cin>>password; 

    if(username==adminusername && password==adminpassword)
        return true;

    else{                                                                       
        
        gotoxy(50,25);
        cout<<"User not found or invalid input..."<<endl;
        
        return false;
    }

    
}

bool signUp(string users[], string passwords[], int &user_count){
    
    header();

    bool final=true;
    string username;
    
    gotoxy(48,17);
    cout<<"Enter a new username: ";
    cin>>username;

    bool validation=false;
    for (int i=0; i< user_count; i++) {
        
        if (users[i]==users[user_count]) {
            
            validation=true;
            break;

        }

    }

    if(validation){
        
        gotoxy(50,25);
        cout<<"Username already exists. Please choose a different username.";
        final=false;
    
    }

    else{
    
        gotoxy(48,18);
        cout<<"Enter a new password: ";
        cin>>passwords[user_count];
        users[user_count]=username;
        user_count+=1;
    
    }
    
    
    clearScreen();
    return final;

}

int adminMenu(){

    system("cls");

    header();

    gotoxy(50,15);
    cout<<"-Admin-";
    gotoxy(48,17);
    cout<<"1. Manage users";
    gotoxy(48,18);
    cout<<"2. Manage products";
    gotoxy(48,19);
    cout<<"3. Previous menu";
    cout<<endl<<endl;

    int choice;

    gotoxy(50,25);
    cout<<"Desired action: ";
    cin>>choice;
    return choice;

}

void editUserByAdmin(string users[], string passwords[], int &user_count){

     
    header();

    string edit_username;
    gotoxy(48,17);
    cout<<"Enter the username to edit: ";
    cin>>edit_username;

    clearScreen();

    int index=-1;

    for(int i=0; i<user_count; i++){
        
        if(users[i]==edit_username){
            
            index=i;
            break;

        }

    }

    if(index != -1){
        
        header();

        gotoxy(48,17);
        cout<<"Enter new username for "<<users[index]<<": ";
        cin>>users[index];
        gotoxy(48,18);
        cout<<"Enter new password for "<<users[index]<<": ";
        cin>>passwords[index];
        gotoxy(50,25);
        cout<<"User '"<<edit_username<<"' edited successfully."<<endl;
        clearScreen();
    } 
    
    else{
        
        header();

        gotoxy(50,25); 
        cout << "User not found."<<endl;
    
    }


}

void viewAllUsers(string users[], string passwords[], int &user_count){

    header();

    int y=19;
    
    gotoxy(48,17);
    cout<<"Username: ";
    gotoxy(68,17);
    cout<<"Password: ";

    for(int i=0; i<user_count; i++){

        gotoxy(48,y);
        cout<<users[i];

        gotoxy(68,y);
        cout<<passwords[i];

        y+=1;

    }

    clearScreen();

    return;

}

void deleteUserByAdmin(string users[], string passwords[], int &user_count){

    header();

    string delete_username;
    gotoxy(48,17);
    cout<<"Enter the username to delete: ";
    cin>>delete_username;


    int index=-1;

    for(int i=0; i<user_count; i++){
        
        if(users[i]==delete_username){
            
            index=i;
            break;

        }

    }

    if(index != -1){
        
        for(int i=index; i<user_count; i++){
            
            users[i]=users[i+1];
            passwords[i]=passwords[i+1];

        }

        user_count-=1;
        gotoxy(50,25);
        cout<<"User '"<<delete_username<<"' deleted successfully."<<endl;
        clearScreen();

    } 
    
    else{
        
        gotoxy(50,25);
        cout << "User not found."<<endl;
        
    
    }

    clearScreen();

}

void manageUsers(string users[], string passwords[], int &user_count){

    header();

    int choice;

    gotoxy(50,15);
    cout<<"-Manage users-";

    gotoxy(48,17);
    cout<<"1. Add user";
    gotoxy(48,18);
    cout<<"2. Edit user";
    gotoxy(48,19);
    cout<<"3. Delete user";
    gotoxy(48,20);
    cout<<"4. View all users";
    gotoxy(48,21);
    cout<<"5. Previous Menu";

    gotoxy(50,25);
    cout<<"Desired choice: ";
    cin>>choice;

    if(choice==1){

        clearScreen();
        signUp(users, passwords, user_count);
        return;

    }

    else if(choice==2){

        clearScreen();
        editUserByAdmin(users, passwords, user_count);
        return;

    }

    else if(choice==3){

        clearScreen();
        deleteUserByAdmin(users, passwords, user_count);
        return;

    }

    else if(choice==4){

        clearScreen();
        viewAllUsers(users, passwords, user_count);
        return;

    }

    else if(choice==5){

        clearScreen();
        return;

    }

    else{

        clearScreen();
        gotoxy(50,25);
        cout<<"Invalid input, try again."<<endl;
        clearScreen();
        manageUsers(users, passwords, user_count);

    }
    

}

int userMenu(){

    system("cls");

    header();

    gotoxy(50,15);
    cout<<"-User-";
    gotoxy(48,17);
    cout<<"1. View Products";
    gotoxy(48,18);
    cout<<"2. Place An Order";
    gotoxy(48,19);
    cout<<"3. View Order History";
    gotoxy(48,20);
    cout<<"4. Account Settings";
    gotoxy(48,21);
    cout<<"5. Previous Menu";
    cout<<endl<<endl;

    int choice;
    gotoxy(50,25);
    cout<<"Desired action: ";
    cin>>choice;
    return choice;

}

int viewProductCatalog(string productnames[], int productqty[], float product_price[], int &size){

    header();

    int y=19;
    
    gotoxy(48,17);
    cout<<"Product: ";
    gotoxy(68,17);
    cout<<"Qty: ";
    gotoxy(88,17);
    cout<<"Price per unit: ";

    for(int i=0; i<size; i++){

        gotoxy(48,y);
        cout<<productnames[i];

        gotoxy(68,y);
        cout<<productqty[i];

        gotoxy(88,y);
        cout<<product_price[i];

        y+=1;

    }

    clearScreen();

}

int viewProductCatalogUser(string productnames[], int productqty[], float product_price[], int &size){

    header();

    int y=19;
    
    gotoxy(28,17);
    cout<<"Product: ";
    gotoxy(48,17);
    cout<<"Qty: ";
    gotoxy(68,17);
    cout<<"Price per unit: ";

    for(int i=0; i<size; i++){

        gotoxy(28,y);
        cout<<productnames[i];

        gotoxy(48,y);
        cout<<productqty[i];

        gotoxy(68,y);
        cout<<product_price[i];

        y+=1;

    }

}

void placeOrder(string productnames[], int productqty[], float product_price[], int &size, string order_productname[], int order_productqty[], int orderId[], int&order_size){

    header();
    viewProductCatalogUser(productnames, productqty, product_price, size);

    string chosen_product;
    gotoxy(98,19);
    cout<<"Enter the product name to order: ";
    cin>>chosen_product;

    int index=-1;

    //searching for the product
    for(int i=0; i<size; i++){
        
        if(productnames[i]==chosen_product){
            
            index=i;
            break;

        }

    }

    if(index != -1){
        
        header();

        gotoxy(98,21);
        cout<<"Enter quantity for "<<productnames[index]<<": ";
        int order_qty;
        cin>>order_qty;

        if(order_qty > productqty[index]){
            
            gotoxy(90,25);
            cout<<"Not enough quantity available.";
            clearScreen();
            return;

        }

        else{
            
            productqty[index]-=order_qty;
            gotoxy(50,25);
            cout<<"Order placed successfully.";
            order_productname[order_size]=productnames[index];
            order_productqty[order_size]=order_qty;
            order_size+=1;
            clearScreen();
            return;

        }

    } 
    
    else{
        
        header();

        gotoxy(50,25); 
        cout<<"Product not found.";
        clearScreen();
        return;
    
    }

}

void orderHistory(string order_productnames[], int order_productqty[], float product_price[], int &order_size){

    header();

    int y=19;
    
    gotoxy(48,17);
    cout<<"Order ID: ";
    gotoxy(68,17);
    cout<<"Product: ";
    gotoxy(88,17);
    cout<<"Qty: ";
    gotoxy(108,17);
    cout<<"total Price: ";

    for(int i=0; i<order_size; i++){

        gotoxy(48,y);
        cout<<i+1;

        gotoxy(68,y);
        cout<<order_productnames[i];

        gotoxy(88,y);
        cout<<order_productqty[i];

        gotoxy(108,y);
        cout<<(product_price[i])*order_productqty[i];

        y+=1;

    }

    clearScreen();

}

int accountSettings(string users[], string passwords[], int &user_count){

    header();

    int choice;

    gotoxy(50,15);
    cout<<"-Account Settings-";

    gotoxy(48,17);
    cout<<"1. Edit account";
    gotoxy(48,18);
    cout<<"2. Delete account";
    gotoxy(48,19);
    cout<<"3. Previous Menu";

    gotoxy(50,25);
    cout<<"Desired action: ";
    cin>>choice;

    return choice;

    
}

void editUser(string username, string password, string users[], string passwords[], int &user_count){

    header();

    int index=-1;

    for(int i=0; i<user_count; i++){
        
        if(users[i]==username){
            
            index=i;
            break;

        }

    }

    gotoxy(48,17);
    cout<<"Enter current password: ";
    string current_password;
    cin>>current_password;

    if(current_password==password){
    
        if(index != -1){
        
            header();

            gotoxy(48,17);
            cout<<"Enter new username for "<<username<<": ";
            cin>>users[index];
            gotoxy(48,18);
            cout<<"Enter new password for "<<username<<": ";
            cin>>passwords[index];
            gotoxy(50,25);
            cout<<"User edited successfully.";
            clearScreen();

        } 
   
        else{
        
            header();

            gotoxy(50,25); 
            cout << "User not found."<<endl;
    
        }

    }

    else{
        
        gotoxy(50,25);
        cout<<"Incorrect password.";
        clearScreen();

    }

}

void deleteUser(string username, string password, string users[], string passwords[], int &user_count){

    header();

    int index=-1;

    for(int i=0; i<user_count; i++){
        
        if(users[i]==username){
            
            index=i;
            break;

        }

    }

    gotoxy(48,17);
    cout<<"Enter current password: ";
    string current_password;
    cin>>current_password;

    if(current_password==password){
    
        if(index != -1){
        
            for(int i=index; i<user_count; i++){
            
                users[i]=users[i+1];
                passwords[i]=passwords[i+1];

            }

            user_count-=1;
            gotoxy(50,25);
            cout<<"User deleted successfully.";
            clearScreen();

        } 
    
        else{
        
            gotoxy(50,25);
            cout << "User not found."<<endl;
            clearScreen();
    
        }

    }

    else{
        
        gotoxy(50,25);
        cout<<"Incorrect password.";
        clearScreen();

    }

}

void addProduct(string productnames[], int productqty[], float product_price[], int &size){

    header();

    gotoxy(50,15);
    cout<<"-Add Product-";

    gotoxy(48,17);
    cout<<"Enter product name: ";
    string productName;
    cin>>productName;

    // Check if product already exists
    bool productExists = false;
    
    for(int i=0; i<size; i++){
        
        if(productnames[i] == productName){
            productExists = true;
            break;
        }

    }

    if(productExists){
        
        gotoxy(50,25);
        cout<<"Product already exists.";
    
    }
    else{
        
        gotoxy(48,18);
        cout<<"Enter product quantity: ";
        cin>>productqty[size];

        gotoxy(48,19);
        cout<<"Enter product price: ";
        cin>>product_price[size];

        productnames[size] = productName;
        size+=1;

        gotoxy(50,25);
        cout<<"Product added successfully.";
    }


}

int manageProducts(){

    header();

    int choice;  

    gotoxy(50,15);
    cout<<"-Manage Products-";
    gotoxy(48,17);
    cout<<"1. Add Product";
    gotoxy(48,18);
    cout<<"2. Edit product";
    gotoxy(48,19);
    cout<<"3. Delete product";
    gotoxy(48,20);
    cout<<"4. View all products";
    gotoxy(48,21);
    cout<<"5. Previous menu";

    gotoxy(50,25);
    cout<<"Desired action: ";
    cin>>choice;

    return choice;

}

bool signIn(string users[], string passwords[], int user_count){

    header();
    signInBorder();

    string username, password;
    bool final=false;
    
    gotoxy(48,17);
    cout<<"Username: ";
    cin>>username;                      
    gotoxy(48,18);
    cout<<"Password: ";                
    cin>>password;

    for(int i=0; i<user_count; i++){
        
        if(username==users[i] && password==passwords[i]){
        
            final=true;

        }
    }

    if(!final){                                                                       
        
        gotoxy(50,25);
        cout<<"User not found...";
        gotoxy(50,26);
        cout<<"Press any key to try again";
        getch();
        
        
    }

    return final;

}

void editProduct(string productnames[], int productqty[], float product_price[], int &size){

    header();

    string edit_productname;
    gotoxy(48,17);
    cout<<"Enter the product name to edit: ";
    cin>>edit_productname;

    clearScreen(); 

    int index=-1;

    //searching for the product
    for(int i=0; i<size; i++){
        
        if(productnames[i]==edit_productname){
            
            index=i;
            break;

        }

    }

    if(index != -1){
        
        header();

        gotoxy(48,17);
        cout<<"Enter new product name for -"<<productnames[index]<<"- : ";
        cin>>productnames[index];
        gotoxy(48,18);
        cout<<"Enter new product quantity for -"<<productnames[index]<<"- : ";
        cin>>productqty[index];
        gotoxy(48,19);
        cout<<"Enter new product price for -"<<productnames[index]<<"- : ";
        cin>>product_price[index];
    
        gotoxy(50,25);
        cout<<"Product '"<<edit_productname<<"' edited successfully."<<endl;
        clearScreen();

    } 
    
    else{
        
        header();

        gotoxy(50,25); 
        cout << "Product not found."<<endl;
    
    }

}

void deleteProduct(string productnames[], int productqty[], float product_price[], int &size){

    header();

    string delete_productname;
    gotoxy(48,17);
    cout<<"Enter the product name to delete: ";
    cin>>delete_productname;

    clearScreen();

    int index=-1;

    //searching for the product
    for(int i=0; i<size; i++){
        
        if(productnames[i]==delete_productname){
            
            index=i;
            break;

        }

    }

    if(index != -1){
        
        for(int i=index; i<size; i++){
            
            productnames[i]=productnames[i+1];
            productqty[i]=productqty[i+1];
            product_price[i]=product_price[i+1];

        }

        size-=1;

        gotoxy(50,25);
        cout<<"Product '"<<delete_productname<<"' deleted successfully."<<endl;
        clearScreen();

    } 
    
    else{
        
        gotoxy(50,25);
        cout << "Product not found."<<endl;
        clearScreen();
    
    }

}

bool validation(int value){
    if(cin.fail()){
        cin.clear();
        
        return false;
    }   

    return true;

}

int getIntegerInput() {
    
    int choice;

    while(!(cin >> choice)) {
        cin.clear();
        
        cout << "Invalid input. Please enter an integer.\n";
    }

    return choice;
    
}

string getField(string record, int field){
    
    int count=0;
    string word="";

    for(int i=0; i<record.length(); i++){
        
        if(record[i]==','){
            
            count+=1;

        }

        else if(count==field){
            
            word+=record[i];

        }

    }

    return word;

}

void assignValueLogin(string users[], string passwords[], int &user_count){
    
    fstream login;
    string loginFile="login.txt";
    login.open(loginFile, ios::in);

    string line="";

    while(!login.eof()){
        
        getline(login, line);

        if(!line.empty()){
        
            users[user_count]=getField(line, 0);
            passwords[user_count]=getField(line, 1);
            user_count+=1;
        
        }

    }

    login.close();

}

void assignValueProduct(string product_names[], int product_qty[], float product_price[], int &size){
    
    fstream product;
    string productFile="product.txt";
    product.open(productFile, ios::in);

    string line="";

    while(!product.eof()){
        
        getline(product, line);

        if(!line.empty()){
        
            product_names[size]=getField(line, 0);
            product_qty[size]=stoi(getField(line, 1));
            product_price[size]=stof(getField(line, 2));
            size+=1;
        
        }

    }

    product.close();

}


int main() {
    
    

    string adminusername="admin";
    string adminpassword="password";

    string username="";
    string password="";

    int arraysize=10;
    string users[arraysize]={};
    string passwords[arraysize]{};
    int user_count=0;

    string product_names[arraysize]={};
    int product_qty[arraysize]={};
    float product_price[arraysize]={};
    int size=0;

    int orderId[arraysize]={};
    string order_productname[arraysize]={};
    int order_productqty[arraysize]={};
    int order_size=0;

    fstream login;
    string loginFile="login.txt";

    assignValueLogin(users, passwords, user_count);
    assignValueProduct(product_names, product_qty, product_price, size);
    
    //print the values of users and passwords array
    system("cls");
    
    
    for(int i=0; i<user_count; i++){
        cout<<users[i]<<" "<<passwords[i]<<endl;
    }

    for(int i=0; i<size; i++){
        cout<<product_names[i]<<" "<<product_qty[i]<<" "<<product_price[i]<<endl;
    }

    
    login.open(loginFile, ios::in);

    clearScreen();  
    
    system("cls");
    int choice;


    while(true){
        
        system("cls");
        choice=mainMenu();

        if(choice==1){
            
            if(adminLogin(adminusername, adminpassword)) {
                
                clearScreen();
                
                while(true){

                    choice=adminMenu(); 
                    
                    if(choice==1){
                    
                        clearScreen();
                        manageUsers(users, passwords, user_count);
                        
                    
                    }

                    else if(choice==2){
                    
                        while(true){
                            
                            clearScreen();
                            choice=manageProducts();
                        
                            if(choice==1){
                            
                                clearScreen();
                                addProduct(product_names, product_qty, product_price, size);
                            
                            }

                            else if(choice==2){
                        
                                clearScreen();
                                editProduct(product_names, product_qty, product_price, size);

                            }

                            else if(choice==3){
                        
                                clearScreen();
                                deleteProduct(product_names, product_qty, product_price, size);

                            }

                            else if(choice==4){
                        
                                clearScreen();
                                viewProductCatalog(product_names, product_qty, product_price, size);
                            
                            }

                            else if(choice==5){
                        
                                clearScreen();
                                break;

                            }

                        }

                    }
                    
                    else if(choice==3){
                    
                        clearScreen();
                        break;

                    }

                    else if(!validation(choice)){
                    
                        clearScreen();
                        gotoxy(50,25);
                        cout<<"Invalid input, try again."<<endl;
                        clearScreen();
                        

                    }
                

                }
                 
            }

            else{
                
                clearScreen();
                continue;

            } 
        
    
        }
    
        else if(choice==2){
            
            if(signIn(users, passwords, user_count)){

                username=users[user_count];
                password=passwords[user_count];

                clearScreen();
                
                while(true){

                    choice=userMenu(); 
                          
                    if(choice==1){

                        clearScreen();
                        viewProductCatalog(product_names, product_qty, product_price, size);

                    }
                
                    else if(choice==2){
                    
                        clearScreen();
                        placeOrder(product_names, product_qty, product_price, size, order_productname, order_productqty, orderId, order_size);
                    
                    }

                    else if(choice==3){
                        
                        clearScreen();
                        orderHistory(order_productname, order_productqty, product_price, order_size);   

                    }

                    else if(choice==4){
                        
                        clearScreen();
                        choice=accountSettings(users, passwords, user_count);

                        if(choice==1){
                            
                            clearScreen();
                            editUser(username, password, users, passwords, user_count);

                        }

                        else if(choice==2){
                            
                            clearScreen();
                            deleteUser(username, password, users, passwords, user_count);

                        }

                        else if(choice==3){
                            
                            clearScreen();
                            continue;

                        }

                        else{
                        
                            gotoxy(50,25);
                            cout<<"Invalid input, try again."<<endl;
                            clearScreen();

                        }
                        
                    }

                    else if(choice==5){
                        
                        clearScreen();
                        continue;

                    }
                
                }
                 
            }

            else{
                
                clearScreen();
                continue;

            }
        
    
        }

        else if(choice==3){
            
            header();
            gotoxy(50,25);
            cout<<"Thank you for using our system.";
            break;

        }

    }

}