#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;


//#1

//  int main(){

//     char c;
//     int shift;

//     cout<<"Enter a letter to encrypt:"<<endl;
//     cin>>c;

//     cout<<"Enter an integer to shift the letter by:"<<endl;
//     cin>>shift;

//     cout<<"Your encrypted letter is: "<<shiftChar(c,shift)<<endl;
// }




//#2
// int main(){

//     runTest();

//     string key1;
    
//     cout<<"Enter key 1:"<<endl;
//     getline(cin, key1);

//     cout<<"The Method 2 Shift Value is : "<<getMethod2ShiftAmount(key1)<<endl;

// }






//#3

// // int main(){

//     string key1, key2;

//     cout<<"Enter key 1:"<<endl;
//     cin>>key1;

//     cout<<"Enter key 2:"<<endl;
//     cin>>key2;

//     cout<<"The Method 3 Shift Value is: "<<getMethod3ShiftAmount(key1,key2)<<endl;

// }

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
        encrypt = ((c-base - shift)%26 + 26)%26 + base;
        return encrypt;
    }

    return encrypt;
}