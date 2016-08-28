#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum class ProductType : char { None = 'N', Concrete = 'C', Definite = 'D' };

class Product {
    ProductType type = ProductType::None;
public:
   ~Product(){}
    Product(): Product(ProductType::None){}
    Product(ProductType t): type(t){}
    ostream & puts(ostream & s){ return s << static_cast<char>(type); }
    friend ostream & operator<<(ostream & s, Product & product){ return product.puts(s); }
};

class ConcreteProduct : public Product {
public:
    ConcreteProduct(): Product(ProductType::Concrete){}
};
class DefiniteProduct : public Product {
public:
    DefiniteProduct(): Product(ProductType::Definite){}
};

class Creator {
public:
    virtual ~Creator(){}
    virtual Product * create() = 0;     // Factory Method
};

class ConcreteCreator : public Creator {
public:
    virtual Product * create() override { return new ConcreteProduct; }
};

class DefiniteCreator : public Creator {
public:
    virtual Product * create() override { return new DefiniteProduct; }
};

int main()
{
    Creator * creator = new DefiniteCreator;
    Product * product = creator->create();
    cout << *product;
    delete creator; delete product;
    atexit([](){ cout << endl; });
}
