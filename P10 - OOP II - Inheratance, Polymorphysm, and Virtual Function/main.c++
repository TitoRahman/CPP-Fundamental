#include <iostream>

using namespace std;

// Polymorphism -> Create a function that have many form.
// Overide
// Public, Protected, Private
class Animal {
    protected :
        string name;
    public :
        Animal(string name){
            this->name = name;
        }
        // Virtual Function
        virtual void sound(){
            cout << "animal create a sound!";
        }
};

class Dog : public Animal {
    public :
        Dog (string _name) : Animal(_name){}

        void sound() override{
            cout << this->name << " Dog bark!";
        }
};

class Cat : public Animal {
    public :
        Cat (string _name) : Animal(_name){}
        void sound(){
            cout << this->name << " Cat meow!";
        }
};
int main() {
    Animal* animal;

    Dog dog("Doggy");
    dog.sound();
    animal = &dog;
    
    Cat cat1("Kitty");
    animal = &cat1;
    animal->sound();

    Cat cat2("Juan");
    animal = &cat2;
    animal->sound();
    return 0;
}