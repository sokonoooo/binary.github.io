#include <iostream>
#include <vector>
#include <string>
using namespace std;

//zulaa
//Эх класс тодорхойлох
class Person {
private:
    //гишүүн өгөгдлүүд
    string name;
    string ssnum;
    int age;

public:
    // Getter функцүүд
    string getName() {
        return name;
    }
    string getSSNum() {
        return ssnum;
    }
    int getAge() {
        return age;
    }
    // Setter функцүүд
    void setName(string n) {
        name = n;
    }
    void setSSNum(string ss) {
        ssnum = ss;
    }
    void setAge(int a) {
        age = a;
    }
};
//.

// Класс хоорондын харилцааны жишээ:
class person{ char *name; }
class spouse:public person { int annDate; }
class child: public person { char * favToy; }
class division{ ... }
class jd { ... }

class employee : public person{
    spouse *s; // 0..1    
    vector<child> children; // 0..n or child **c;
    division *d; // 1
    vector<*jd> jds; // 1..n
    employee(division dd, jd j){
        this->d = &dd;
        this->jds.push_back(&j);
    }
}

int main(){
    division dics;
    jd bagsh, ceo;
    employee bat(dics, bagsh);
    spouse s;
    bat.s = &s;
    bat.jds.push_back(ceo);
    
    child c;
    bat.children.push_back(c);
}
