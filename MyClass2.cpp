#include "MyClass2.h"
#include <stdlib.h>
#include <cstdlib>


string Pass::GenPass(){
    //cout<<"Зашли";
    string part1=PreRand();
    string part2=Rand();
    string part3=Ostat(part1,part2);
    //cout<<part1<<"\n"<<part2<<"\n"<<part3<<endl;
    return Merge(part1,part2,part3);
}

MiemPass::MiemPass(int gender,int day,int month,int year){
    if (gender==2 || gender==1){
        this->gender=gender*2;
    }
    else{
        this->gender=gender;
    }
    this->day=day;
    this->month=month;
    this->year=year;
    this->c=0;
}
string MiemPass::PreRand(){
    string pass="";
    string strday=day/10==0?"0"+to_string(this->day):to_string(this->day);
    string strmonth=month/10==0?"0"+to_string(this->month):to_string(this->month);
    pass=pass+to_string(this->gender)+to_string(this->year)+strmonth+strday;
    return pass;
}
string MiemPass::Rand(){
    srand(time(NULL));
    int num=rand()%89999 +10000;
    return to_string(num);
}

string MiemPass::Ostat(string preran,string ran){
    string pass=preran+ran;
    int lennPass=pass.size();
    int summ=SumStrKrat(pass,lennPass);
    int c=0;
    //cout<<summ<<endl;
    while((summ+c)%11!=0)c++;
    //cout<<"Вышли"<<endl;
    return to_string(c);
}
string MiemPass::Merge(string preran,string ran,string ostat){
    string pass=preran+ran+ostat;
    return pass;
}
/*string MiemPass::GenPass(){
    string pass="";
    string strday=day/10==0?"0"+to_string(this->day):to_string(this->day);
    string strmonth=month/10==0?"0"+to_string(this->month):to_string(this->month);
    pass=pass+to_string(this->gender)+to_string(this->year)+strmonth+strday;
    srand(time(NULL));

    int num=rand()%89999 +10000;
    pass+=to_string(num);
    int lennPass=pass.size();
    int summ=SumStrKrat(pass,lennPass);
    int c=0;
    while((summ+(lennPass+1)*c)%11!=0)c++;
    pass+=to_string(c);

    return pass;
}*/
void MiemPass::GetInfo(){
            std::cout<<"Data in "<<this<<" :"<<this->gender<<" "<<this->day<<" "<<this->month<<" "<<this->year<<" "<<this->c;
}

SauronPass::SauronPass(int gender,int day,int month,int year){
    if (gender==8 || gender==4){
        this->gender=gender/4;
    }
    else{
        this->gender=gender;
    }
    this->day=day;
    this->month=month;
    this->year=year;
    this->c=0;
    //cout<<"Создан саурон :"<<this<<endl;
}
string SauronPass::PreRand(){
    //cout<<"Запустили преранд саурона"<<endl;
    string pass="";
    string strday=day/10==0?"0"+to_string(this->day):to_string(this->day);
    string strmonth=month/10==0?"0"+to_string(this->month):to_string(this->month);
    pass=pass+to_string(this->gender)+to_string(this->year)+strmonth+strday;
    //cout<<pass<<endl;
    return pass;
}
string SauronPass::Rand(){
    srand(time(NULL));
    int num=rand()%8999 +1000;
    return to_string(num);
}

string SauronPass::Ostat(string preran,string ran){
    string pass=preran+ran;
    int lennPass=pass.size();
    int summ=SumStrKrat(pass,lennPass);
    int c=0;
    //cout<<summ<<endl;
    while((summ+c)%10!=0){
            c++;cout<<c;
    }
    //cout<<"Цикл"<<endl;
    return to_string(c);
}
string SauronPass::Merge(string preran,string ran,string ostat){
    string pass=preran+ran+ostat;
    return pass;
}
/*string SauronPass::GenPass(){
    string pass="";
    string strday=day/10==0?"0"+to_string(this->day):to_string(this->day);
    string strmonth=month/10==0?"0"+to_string(this->month):to_string(this->month);
    pass=pass+to_string(this->gender)+to_string(this->year)+strmonth+strday;
    srand(time(NULL));
    int num=rand()%8999 +1000;
    pass+=to_string(num);
    int lennPass=pass.size();
    int summ=SumStrKrat(pass,lennPass);
    int c=0;
    while((summ+(lennPass+1)*c)%10!=0)c++;
    pass+=to_string(c);
    return pass;
}
*/
Admin::Admin(){
    this->accessLevel=0;
}
Admin::Admin(int access){
    this->accessLevel=access;
}
string Admin::GivePassCard(Pass&procedure){
    return procedure.GenPass();
}
