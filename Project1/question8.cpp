#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;

// CSCI 1300 Fall 2023
// Author: Axel Howard
// TA name: Brenden Crowe

// All functions needed
string encryptMessage(string message, int method_choice, string  key1, string key2);
string decryptMessage(string message, int method_choice, string  key1, string key2);
char shiftchar(char c, int shift);
int getMethod3ShiftAmount(string key1, string key2);
int getMethod2ShiftAmount(string key1);
string method4(string message, string key1, string key2);
char encryptChar(char c, int method_choice, string key1, string key2);
char decryptChar(char c, int method_choice, string key1, string key2);


//Test cases for big functions
void runTestsencryptmessage(){
    assert(encryptMessage("hello world!",2,"hello","world")=="olssv dvysk!");
    assert(encryptMessage("new test case",3,"hello","world")=="qhz whvw fdvh");
    assert(encryptMessage("mix it up",4,"cu","boulder")=="nly lu xq");
}
void runTestsdecryptmessage(){
    assert(decryptMessage("olssv dvysk!",2,"hello","world")=="hello world!");
    assert(decryptMessage("qhz whvw fdvh",3,"hello","world")=="new test case");
    assert(decryptMessage("nly lu xq",4,"cu","boulder")=="mix it up");
}
void runTestsmethod2shiftamount(){
    assert(getMethod2ShiftAmount("")==0);
    assert(getMethod2ShiftAmount("h")==1);
    assert(getMethod2ShiftAmount("a")==2);
    assert(getMethod2ShiftAmount("aeiou")==10);
    assert(getMethod2ShiftAmount("aaaaaaaaaaaaa")==0);
    assert(getMethod2ShiftAmount("hello world! this is a key")==8);
}
void runtestsmethod3shiftamount(){
    assert(getMethod3ShiftAmount("hi","ho")==1);
    assert(getMethod3ShiftAmount("heyo","beno")==2);
    assert(getMethod3ShiftAmount("xi","i will use i a bunch iii")==6);
    assert(getMethod3ShiftAmount("and flipping using p a lot p  p","px")==5);
    assert(getMethod3ShiftAmount("lpl pl","ppyyll")==10);

}


int main(){
    void runTestsencryptmessage();
    void runTestsdecryptmessage();
    void runTestsmethod2shiftamount();
    void runTestsmethod3shiftamount();

    int option_choice,method;
    string key1,key2;
    char top='z',base='a';

    cout<<"Set Encryption Key 1"<<endl;
    cout<<"Set Encryption Key 2"<<endl;
    cout<<"Select Encryption Method"<<endl;
    cout<<"Encrypt Message"<<endl;
    cout<<"Decrypt Message"<<endl;
    cout<<"Exit Program"<<endl;
    cout<<"Enter an option 1-6:"<<endl;
    cin>>option_choice;

    while(cin.fail()||option_choice<1 || option_choice>6){
        cout<<"Invalid option"<<endl;
        cin.clear();
        cin.ignore(100000,10);
        cin>>option_choice;
    }
    cin.ignore(100000,10);
    

    switch(option_choice){

        case 1:

            if(key1.length()<1){
                bool valid = false;

                do{
                    cout<<"Enter key:"<<endl;
                    getline(cin,key1);
                }
            while(valid = false);
            }
            
            
            
            cout<<"Successfully set encryption key1 to "<<key1<<endl;
        break;

        case 2:
            cout<<"Enter key:"<<endl;
            getline(cin,key2);
            for(int i = 0; i<key2.length(); i++){
                char c = key2[i];
                while(key2.length()<1 || key2[i]<base|| key2[i]>top){
                cout<<"Invalid key"<<endl;
                cout<<"Enter key:"<<endl;
            }
            }
        
            cout<<"Successfully set encryption key2 to "<<key2<<endl;
        break;
        case 3:
            cout << "Select the Encrypted Method to Use:" << endl;
            cout << "1. Method 1: Shift right by 1." << endl;
            cout << "2. Method 2: Shift right by Key Formula." << endl;
            cout << "3. Method 3: Shift right by Mixed Key Formula." << endl;
            cout << "4. Mix of Method1, Method2, Method3" << endl;
            cin>>method;

            while(method<1||method>4){
                cout<<"Invalid encryption choice"<<endl;
            }
            cout<<"Successfully set encryption type to "<<method<<endl;
        
        



        
    }







}




char encryptChar(char c, int method_choice, string key1, string key2){

    int result, shift_amount, shift;
    char base = 'a',top = 'z';




    switch(method_choice){
        case 1:
            result = shiftchar(c,shift);
            if(result==123){
                result = 97;
            }
            break;
        case 2:
            shift_amount = getMethod2ShiftAmount(key1);
            result = (c + shift_amount);
            if(c<base || c>top){
                return c;
                break;
            }
            if(result>122){
                result-= 26;
            }
            break;
        case 3:
            shift_amount = getMethod3ShiftAmount(key1,key2);
            result = (c + shift_amount);
            if(c<base || c>top){
                return c;
                break;
            }
            if(result>122){
                result-=26;
            }

            break;
        default:
            cout<<"Invalid encryption method"<<endl;
            return c;
            break;
    }
    return result;

}

char decryptChar(char c, int method_choice, string key1, string key2){

     int result, shift_amount, shift;
    char base = 'a',top = 'z';

    switch(method_choice){
        case 1:
            result = shiftchar(c,shift);
            if(result==96){
                result = 122;
            }
            break;
        case 2:
            shift_amount = getMethod2ShiftAmount(key1);
            result = (c - shift_amount);
            if(c<base || c>top){
                return c;
                break;
            }
            if(result<97){
                result+= 26;
            }
            break;
        case 3:
            shift_amount = getMethod3ShiftAmount(key1,key2);
            result = (c - shift_amount);
            if(c<base || c>top){
                return c;
                break;
            }
            if(result<97){
                result+=26;
            }

            break;
        default:
            cout<<"Invalid decrypt method"<<endl;
            return c;
            break;
    }
    return result;


}

string encryptMessage(string message, int method_choice, string  key1, string key2){

   int messagelength2 = message.length();
   string finalencryptedmessage = message;

   switch(method_choice){

    case 1:
        for (int i = 0; i<messagelength2; i++){
            finalencryptedmessage[i]= message[i] + 1;
            if(finalencryptedmessage[i]>122){
                finalencryptedmessage[i]-=26;
            }
            if(message[i]<97 || message[i]>122){
                finalencryptedmessage[i] = message[i];
            }
            
        }
        break;
    case 2:
        for(int i = 0; i<messagelength2; i++){
            finalencryptedmessage[i]=message[i]+ getMethod2ShiftAmount(key1);
            if(finalencryptedmessage[i]>122){
                finalencryptedmessage[i]-=26;
            }
            if(message[i]<97 || message[i]>122){
                finalencryptedmessage[i] = message[i];
            }
            
        }
        break;
    case 3:
        for(int i = 0; i<messagelength2; i++){
            finalencryptedmessage[i]=message[i]+getMethod3ShiftAmount(key1,key2);
            if(finalencryptedmessage[i]>122){
                finalencryptedmessage[i]-=26;
            }
            if(message[i]<97 || message[i]>122){
                finalencryptedmessage[i] = message[i];
            }
        }
        break;
    case 4:
        finalencryptedmessage = method4(message,key1,key2);
        break;
    default:
        cout << "Invalid encryption method" << endl;
        return message;
   }
   return finalencryptedmessage;


}

string decryptMessage(string message, int method_choice, string  key1, string key2){

   int messagelength2 = message.length();
   string finaldecryptedmessage = message;

   switch(method_choice){

    case 1:
        for (int i = 0; i<messagelength2; i++){
            finaldecryptedmessage[i]= message[i] - 1;
            if(finaldecryptedmessage[i]<97){
                finaldecryptedmessage[i]+=26;
            }
            if(message[i]<97 || message[i]>122){
                finaldecryptedmessage[i] = message[i];
            }
            
        }
        break;
    case 2:
        for(int i = 0; i<messagelength2; i++){
            finaldecryptedmessage[i]=message[i]- getMethod2ShiftAmount(key1);
            if(finaldecryptedmessage[i]<97){
                finaldecryptedmessage[i]+=26;
            }
            if(message[i]<97 || message[i]>122){
                finaldecryptedmessage[i] = message[i];
            }
            
        }
        break;
    case 3:
        for(int i = 0; i<messagelength2; i++){
            finaldecryptedmessage[i]=message[i]- getMethod3ShiftAmount(key1,key2);
            if(finaldecryptedmessage[i]<97){
                finaldecryptedmessage[i]+=26;
            }
            if(message[i]<97 || message[i]>122){
                finaldecryptedmessage[i] = message[i];
            }
        }
        break;
    case 4:
        finaldecryptedmessage = method4(message,key1,key2);
        break;
    default:
        cout << "Invalid decryption method" << endl;
        return message;
   }
   return finaldecryptedmessage;


}

string method4(string message,string key1, string key2){
    int messagelength = message.length();
    int newmessage[messagelength];
    string finalmessage= message;


    for(int i = 0; i < messagelength; i+=3){
        newmessage[i] = message[i] - 1;

        if(newmessage[i]<97){
            newmessage[i]+=26;
        }
        if(message[i]<97 || message[i]>122){
            newmessage[i] = message[i];
        }

    }

    
    for(int i = 1; i<messagelength; i+=3){
        newmessage[i]=message[i]-getMethod2ShiftAmount(key1);

        if(newmessage[i]<97){
            newmessage[i]+=26;
        }
        if(message[i]<97 || message[i]>122){
            newmessage[i] = message[i];
        }

    }
    
    for(int i = 2; i<messagelength; i+=3){
        newmessage[i]= message[i]- getMethod3ShiftAmount(key1,key2);

        if(newmessage[i]<97){
            newmessage[i]+=26;
        }
        if(message[i]<97 || message[i]>122){
            newmessage[i] = message[i];
        }

    }
    for(int i = 0; i<messagelength; i++){
        finalmessage[i]= newmessage[i];
    }
    return finalmessage;
    

}

int getMethod3ShiftAmount(string key1, string key2){
    int sharedchars = 0;

    for(int i =0; i<key1.length(); i++){
        char currentchar = key1[i];

        for(int j = 0; j<key2.length(); j++)
            if(currentchar == key2[j]){
                sharedchars++;
                if(sharedchars>=27){
                    sharedchars = 0;
                    sharedchars++;
                }
            }
    }
    return sharedchars;

}

int getMethod2ShiftAmount(string key1){

    int length = key1.length();
    int vowel_count = 0;
    char vowels;

    for(char vowels : key1) {
        if(vowels=='a'|| vowels=='e'|| vowels=='o'||vowels=='u'||vowels=='i'|| vowels=='y'){
            vowel_count += 1;
        }
          
    }
    return (vowel_count + length) % 26;

}
char shiftchar(char c, int shift){
    
    int result;

    if(c>= 97 && c<=122){
        result = c+1;

        if(result==122){
            result = 96;
        }
        return result;
        
    }
    else{
        return c;
    }
}

