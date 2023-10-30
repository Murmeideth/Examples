//здесь подключены библиотеки

#include <iostream> //эта нужна для ввода и вывода
#include <string>   //эта нам пригодится для работы со строками
#include <stdio.h>  //здесь у нас лежит рандом
#include <ctime>    //а эта нам помогает делать рандомные числа более рандомными

using namespace std;

class Character{
    private:
    //основные характеристики персонажа: сила, ловкость, мудрость, харизма и удача
    int mStreight, mAgility, mWisdom, mCharisma, mLuck;
    int mHP;
    //имя персонажа
    string mName;
    public:
    //метод для вывода характеристик персонажа
    void PrintStats(){
        cout<<"_________________________\n";
        cout<<"|                       |\n";
        cout<<"|\tHP\t"<< mHP <<"\t|\n";
        cout<<"|\tStr\t"<<mStreight<<"\t|\n";
        cout<<"|\tAgl\t"<<mAgility<<"\t|\n";
        cout<<"|\tWis\t"<<mWisdom<<"\t|\n";
        cout<<"|\tCha\t"<<mCharisma<<"\t|\n";
        cout<<"|\tLck\t"<<mLuck<<"\t|\n";
        cout<<"|_______________________|\n\n";
    }
    //конструктор класса для рандомных значений персонажа
    Character(string _name){
        this->mName = _name;
        srand(time(NULL));
        mStreight = rand() % 10 + 1;
        mAgility = rand() % 10 + 1;
        mWisdom = rand() % 10 + 1;
        mCharisma = rand() % 10 + 1;
        mLuck = rand() % 10 + 1;        
        mHP = 10 + (mStreight / 5);
        cout<<_name<<" has been created!"<<endl;
    }
};
//это будет наша рекурсивная функция, которая и будет отвечать за вывод текста
//и хранение информации на время работы приложения
void func(Character *OurHero){
    cout<<"For now you can: "<<endl<<"1. Show your stats."<<endl<<"2. Drop character and create new."<<endl
        <<"0. Exit."<<endl<<endl;
    string text;
    cin>>text;
    try{
        if(text == "1"||text == "show stats"||text == "stats"){
            //выводим инормацию о хараактеристиках
            cout<<"Here stats for your character."<<endl;
            OurHero->PrintStats();                
            func(OurHero);        
        }else if(text == "2"||text == "new character"||text == "recreate"){
            //пересоздаем персонажа и запускаем новую рекурсивную функцию, только уже с другим персонажем
            cout<<"Alright then. Give me a new name for character: ";
            string _name;
            cin>>_name;
            Character _u(_name);
            func(&_u);
        }else if(text == "0"||text=="exit")
            exit(0);
    }catch(exception){ //здесь мы ловим наши ошибки
        cout<<"You did something wrong. Try again."<<endl;
        func(OurHero); //и перезапускаем функцию
    }
}

int main(){
    //создаем экземпляр нашего персонажа    
    cout<<"Welcome to this little [not]rougelike piece of game."<<endl;
    cout<<"Create your character! Just put here his name: ";
    //создаем переменную с именем
    string text;
    getline(cin, text);
    //создаем экземпляр персонажа
    Character u1(text);
    //передаем все в функцию
    func(&u1);
    cout<<"Come back later. Maybe we fix something here."<<endl;    
}