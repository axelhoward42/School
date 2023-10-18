#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;


// CSCI 1300 Fall 2023
// Author: Axel Howard
// TA name: Brenden Crowe





int getMethod2ShiftAmount(string key1);
int getMethod3ShiftAmount(string key1, string key2);
char shiftchar(char c, int shift);
char encryptChar(char c, int method_choice, string key1, string key2);



void runTestsShiftChar(){
    assert(shiftChar(' ',10)==' ');
    assert(shiftChar(';',4)==';');
    assert(shiftChar('H',5)=='H');
    assert(shiftChar('a',1)=='b');
    assert(shiftChar('g',-1)=='f');
    assert(shiftChar('a',100)=='w');
    assert(shiftChar('a',-100)=='e');

}

void runTestsmethod2shiftamount(){
    assert(getMethod2ShiftAmount());
    assert(getMethod2ShiftAmount());
    assert(getMethod2ShiftAmount());
    assert(getMethod2ShiftAmount());
    assert(getMethod2ShiftAmount());
    assert(getMethod2ShiftAmount());
    assert(getMethod2ShiftAmount());

}

// void runtestsmethod3shiftamount(){
//     assert(getMethod3ShiftAmount());
//     assert(getMethod3ShiftAmount());
//     assert(getMethod3ShiftAmount());
//     assert(getMethod3ShiftAmount());
//     assert(getMethod3ShiftAmount());
//     assert(getMethod3ShiftAmount());
//     assert(getMethod3ShiftAmount());



// }






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


int main(){
    char c;
    int method_choice,shift;
    string key1,key2;

    

    cout<<"Enter a letter to encrypt:"<<endl;
    cin>>c;



    cout<<"Enter key 1:"<<endl;
    cin.ignore(10000,10);
    getline(cin,key1);
    
    
    cout<<"Enter key 2:"<<endl;
    getline(cin,key2);
    
    cout<<"Select the Encryption Method to use:"<<endl;
    
    cout<<"1) Method 1: Shift Right by 1."<<endl;
    cout<<"2) Method 2: Shift Right by Key Formula."<<endl;
    cout<<"3) Method 1: Shift Right by Mixed Key Formula"<<endl;
    cin>>method_choice;
    

    cout<<"The encrypted letter is: "<<encryptChar(c,method_choice,key1,key2)<<endl;


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
    
    char encrypt;
    char base = 'a',top = 'z';
    

    if(c<base || c>top){
        return c;
    }

    else{
        encrypt = ((c-base + shift)%26 + 26)%26 + base;
        return encrypt;
    }

    return encrypt;
}