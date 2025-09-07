//Made by Naman Singh
#include<iostream>
using namespace std;
char compute(char c, int a){
    int temp=c+a;
    if(32<=temp and temp<=126){
        return temp;
    }
    if(temp<32){
        // a must be negative
        return compute(126,-(31-temp));
    }
    else{
        //temp>126
        //a must be positive
        return compute(32,temp-127);
    }
}
string encrypt_helper(string s){
    int n=s.size();
    int a=1;
    for(int i=0;i<n;i++){
        s[i]=compute(s[i],a);
        if(a>0){
            //a is positive
            a=-a;
        }
        else{
            // a is negative
            a=-a;
            a++;
        }
    }
    return s;
}
string decrypt_helper(string s){
    int n=s.size();
    int a=-1;
    for(int i=0;i<n;i++){
        s[i]=compute(s[i],a);
        if(a<0){
            //a is negative
            a=-a;
        }
        else{
            // a is positive
            a=-a;
            a--;
        }
    }
    return s;
}
void encrypt(string s){
    cout<<encrypt_helper(s);
}
void decrypt(string s){
    cout<<decrypt_helper(s);
}
int main(){
    cout<<endl<<endl;
    string information;
    cout<<"enter the string:";
    getline(cin,information);//unable to receive " if you don't input
    cout<<"if you wish to encrypt your string (real string to code), press 0"<<endl;
    cout<<"if you wish to decrypt your string (code to real string), press 1"<<endl;
    int n;
    cin>>n;
    cout<<endl<<endl;
    cout<<"copy the entire string between START| and |END, all the symbols, EVEN SPACE as well "<<endl<<endl;
    cout<<"START|";
    if(n==0){
        encrypt(information);
    }
    else{
        decrypt(information);
    }
    cout<<"|END";
    cout<<endl<<endl;

}