#include <iostream>
#include <limits>
using namespace std;
using decimal = long double;
void dashboard(){
    cout << "\n======================" << endl;
    cout << "     Calculator Menu" << endl;
    cout << "======================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Square" << endl;
    cout << "6. Exit" << endl;
    cout << "======================" << endl;
}

int getInt(string prompt){
    int value;
    while (true){
        cout<< prompt;
        cin>> value;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter a valid Number "<<endl;
        }
        else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } 
        
    }

}
long double getDouble(string prompt){
    decimal value;
    while (true){
        cout<< prompt;
        cin>> value;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter a valid Number "<<endl;
        }
        else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } 
        
    }

}
void print(const string& msg){
    cout<<msg;
}
void operand(decimal& a, decimal& b){
    a = getDouble("Enter Operand 1 : "); 
    b = getDouble("Enter Operand 2: ");
}
int sel(){
    return getInt("Select an Option: ");
    
}
decimal sysFunction(int selection){
    decimal a = 0; decimal b = 0; decimal result =0;
    switch(selection){
        case 1:
        operand(a , b);
        result = a +b;
        break;
        case 2:
        operand(a,b);
        result  = a-b;
        break;
        case 3:
        operand(a,b);
        result = a*b;
        break;
        case 4:
        operand(a,b);
        while (b == 0){
            cout<<"Math Error "<<endl<<endl;
            operand(a,b);
        }
        result = a/b;
        break;
        case 5:
        a = getDouble("Enter Operand: ");   
        result = a*a;
        return result;  
        break;
        case 6:
        print("Exiting Calculator Press Enter...."); 
        break;
        default:
        print("Invalid Selection");
        cout<<endl;
        break;
    }
    return result;
}
int main() {
    int selection;
    do {
        dashboard();
        selection = sel(); // Assign to the outer variable, not a new one
        if (selection != 6) {
            double answer = sysFunction(selection); // Use double instead of decimal
            cout << "Answer: " << answer << endl<<endl<<endl;
        } else {
            cout << "Exiting Calculator. Press Enter..." << endl;
        }
    } while (selection != 6);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    cin.get(); // Wait for Enter
    return 0;
}