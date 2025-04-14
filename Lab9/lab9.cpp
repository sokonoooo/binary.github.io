
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