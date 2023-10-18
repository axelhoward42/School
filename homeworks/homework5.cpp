#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <iterator>
using namespace std;

/*#1

int main(){
    
    string card_names[9]={"Ace","Clubs","Diamonds","Hearts","Spades","Jack","Queen","King","Joker"};
    int length = sizeof(card_names)/sizeof(card_names[0]);

    for(int i=0; i<length; i++){
        cout<<card_names[i]<<endl;
    }


    const int arraysize = 11;
    double sq_root_num[arraysize];
    for(int i = 1; i<arraysize; i++){
        sq_root_num[i]=(sqrt(i));
        cout<<fixed<<setprecision(3)<<sq_root_num[i]<<endl;
        
    }

    
    const int arraysize2 = 7;
    int numbers[arraysize2]={};
    int length2 = sizeof(numbers)/sizeof(numbers[0]);
    
    for(int i = 50; i<=100; i++){
        if(i%7==0){
            cout<<i<<endl;

        }
        
    }

    char letters[52]={'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z'};
    int length3 = sizeof(letters)/sizeof(letters[0]);
    for(int i =0; i<length3; i++){
        cout<<letters[i]<<endl;
    }
    


    return 0;
}
*/

/*#2
double temperatureMean(double new_temperature[],const int TEMP_SIZE){
    double total = 0;
    double mean = 0;
    
    for(int i = 0; i<TEMP_SIZE; i++){
        total += new_temperature[i];

    }
    mean = total/TEMP_SIZE;
    return mean;

}

double temperatureRange(double new_temperature[],const int TEMP_SIZE){
    double max ={new_temperature[0]},min = {new_temperature[0]},range;
    for(int i = 0; i<TEMP_SIZE; i++){
        if(new_temperature[i]>max){
            max = new_temperature[i];
        }
        else if(new_temperature[i]<min){
            min = new_temperature[i];
        }
    }
    range = max- min;
    return max;
    
}

void temperatureDelta(double new_temperature[],double old_temperature[],double delta[],const int TEMP_SIZE){
    for(int i = 0; i<TEMP_SIZE; i++){
        delta[i]= old_temperature[i] -new_temperature[i];

    }

}
*/



void mostPopularWord(string words[], const int WORD_SIZE){
    int frequency = 0;
    string popular;

    for (int i = 0; i<WORD_SIZE; i++){
        if(words[i]==words[i]){
            frequency+=1;
            
        }
        
    }
    cout<<"The msot popular word: "<<popular<<endl;
    cout<<"Frequency: "<<frequency<<endl;
    


}








