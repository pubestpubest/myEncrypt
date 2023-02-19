#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>

using namespace std;

void keyGen(string &);
int getCommand();
void encrypt(string);
void decrypt(string);

int main(int argc, char const *argv[])
{
    srand(time(0));
    string key(52,' ');
    cout<<"START."<<endl;
    keyGen(key);
    bool loop = true;
    do{
    cout<<"KEY : "<<key<<endl;
        switch(getCommand()){
            case 1:encrypt(key);
                break;
            case 2:decrypt(key);
                break;
            case 3: loop = false;
                break;
        }
    }while(loop);
    return 0;
}

void keyGen(string &key){
    vector<bool> allow(52,false);
    for(unsigned int i=0;i<52;i++){
        int ran=0;
        do{
            ran=rand()%52;
        }while(allow[ran]);
        allow[ran]=true;
        if(ran>25)  ran+=6;
        key.at(i)='A'+ran;
    }
}

int getCommand(){
    int command;
    do{
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"Choose an action."<<endl;
        cout<<"1 : Encrypt\n2 : Decrypt\n3 : Exit\n";
        cout<<"Command : ";
        cin>>command;
        if(command<1||command>3) cout<<"***Invalid command try again***\n";
    }while(command<1||command>3);
    return command;
}

void encrypt(string key){
    string text;
    cout<<"___ENCRYPT___\nPlain text \t: ";
    cin.ignore();
    getline(cin,text);
    string enText(text.size(),' ');
    for(unsigned int i=0;i<text.size();i++){
        if(text[i]>='A'&&text[i]<='Z')  enText[i]=key[text[i]-'A'];    
        else if(text[i]>='a'&&text[i]<='z') enText[i]=key[text[i]-'A'-6];
        else    enText[i]=text[i];
    }
    cout<<"Encrypted text \t: "<<enText<<endl<<endl;
}

void decrypt(string key){
    string enText;
    cout<<"___DECRYPT___\nEncrypted text : ";
    cin.ignore();
    getline(cin,enText);
    string text(enText.size(),' ');
    for(unsigned int i=0;i<text.size();i++){
        if(key.find_first_of(enText[i])<25&&key.find_first_of(enText[i])>=0)    text[i]='A'+key.find_first_of(enText[i]);
        else if(key.find_first_of(enText[i])<52&&key.find_first_of(enText[i])>=25)  text[i]=6+'A'+key.find_first_of(enText[i]);
        else    text[i]=enText[i];
    }
    cout<<"Plain text : "<<text<<endl<<endl;
}