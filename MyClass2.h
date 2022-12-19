#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funcs.h"

using std::string;
using std::to_string;
using std::rand;
using std::srand;
using std::time;

class Pass{
public:
    virtual string PreRand()=0;
    virtual string Rand()=0;
    virtual string Ostat(string preran,string ran)=0;
    virtual string Merge(string preran,string ran,string ostat)=0;
    string GenPass();

};
class MiemPass:public Pass{
    public:
        string PreRand() override;
        string Rand() override;
        string Ostat(string preran,string ran) override;
        string Merge(string preran,string ran,string ostat)override;
        MiemPass(int gender,int day,int month,int year);
        void GetInfo();
    protected:
        int day;
        int month;
        int year;
        int gender;
        int c;
        string pass;
};
class SauronPass:public Pass{
    public:
        string PreRand() override;
        string Rand() override;
        string Ostat(string preran,string ran) override;
        string Merge(string preran,string ran,string ostat)override;
        SauronPass(int gender,int day,int month,int year);
    protected:
        int day;
        int month;
        int year;
        int gender;
        int c;
        string pass;
};
class Admin{
public:
    Admin();
    Admin(int access);
    string GivePassCard(Pass&procedure);
private :
    int accessLevel;
};

