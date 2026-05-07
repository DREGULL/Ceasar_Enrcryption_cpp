#include<iostream>
#include<string>

std::string Ceasar_Encryption(std::string &_plainText , int _shift);
void changeLetter(char &_lett, int _lettRank);
int rankingLetter(char _letter);

int main (){
    std::string _plainText;
    std::cout<<"Enter string: ";
    std::cin>>_plainText;
    int _shift;
    std::cout<<"Enter Shift_numb: ";
    std::cin>>_shift;
    Ceasar_Encryption(_plainText,_shift);
    std::cout<<_plainText<<std::endl;
    return 0;
}


std::string Ceasar_Encryption(std::string &_plainText, int _shift){
    if(_shift < 0)return"Change \"Shift_numb\"'s Value To Positive Value";
    for (size_t i = 0; i < _plainText.size(); i++)
    {
        
        int curentLettRank = rankingLetter(_plainText[i]);
        if(curentLettRank == -1) continue;
        int letterRank = (curentLettRank + _shift) % 26;
        if(islower(_plainText[i])){changeLetter(_plainText[i],letterRank); _plainText [i] = tolower(_plainText[i]);}
        else changeLetter(_plainText[i],letterRank);
        
    }return _plainText;
    
}

void changeLetter(char &_letter, int _lettRank){
    const char* _letter_s = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    _letter = _letter_s[_lettRank];
}

int rankingLetter(char _letter){
    const char* _letter_s = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    for (size_t i = 0; i < 26; i++)
    {
        if (_letter == _letter_s[i]) return i;
        else if(_letter == std::tolower(_letter_s[i])) return i;
    }return -1;
    
}