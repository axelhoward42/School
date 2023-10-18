#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;


string encryptMessage(string message, int method_choice, string  key1, string key2);
char shiftchar(char c, int shift);
int getMethod3ShiftAmount(string key1, string key2);
int getMethod2ShiftAmount(string key1);
string method4(string message, string key1, string key2);



void runTests(){
    assert(encryptMessage("hello world!",2,"hello","world")=="olssv dvysk!");
    assert(encryptMessage("new test case",3,"hello","world")=="qhz whvw fdvh");
    assert(encryptMessage("mix it up",4,"cu","boulder")=="nly lu xq");
}

int main(){
    string key1, key2, message;
    int method_choice,shift;

    runTests();

    cout<<"Enter a message to encrypt:"<<endl;
    getline(cin,message);

    cout<<"Enter key 1:"<<endl;
    getline(cin,key1);
    
    cout<<"Enter key 2:"<<endl<<endl;
    getline(cin,key2);
    
    cout<<"Select the Encryption Method to use:"<<endl;
    
    cout<<"1) Method 1: Shift Right by 1."<<endl;
    cout<<"2) Method 2: Shift Right by Key Formula."<<endl;
    cout<<"3) Method 1: Shift Right by Mixed Key Formula"<<endl;
    cout<<"4) Mehtod 4: Combination of methods 1, 2, and 3."<<endl;
    cin.ignore(10000,10);
    cin>>method_choice;
    
    cout<<"The encrypted message is: "<<encryptMessage(message,method_choice,key1,key2)<<endl;

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

string method4(string message,string key1, string key2){
    int messagelength = message.length();
    int newmessage[messagelength];
    string finalmessage= message;


    for(int i = 0; i < messagelength; i+=3){
        newmessage[i] = message[i] + 1;

        if(newmessage[i]>122){
            newmessage[i]-=26;
        }
        if(message[i]<97 || message[i]>122){
            newmessage[i] = message[i];
        }

    }

    
    for(int i = 1; i<messagelength; i+=3){
        newmessage[i]=message[i]+getMethod2ShiftAmount(key1);

        if(newmessage[i]>122){
            newmessage[i]-=26;
        }
        if(message[i]<97 || message[i]>122){
            newmessage[i] = message[i];
        }

    }
    
    for(int i = 2; i<messagelength; i+=3){
        newmessage[i]= message[i]+ getMethod3ShiftAmount(key1,key2);

        if(newmessage[i]>122){
            newmessage[i]-=26;
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