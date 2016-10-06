class T {
    int value = 0;
public:
    T(int v):value(v){}
    operator int(){ return value; }
};

enum E : T { zero = T(0), one = T(1), ten = T(10) };

int main(){}
