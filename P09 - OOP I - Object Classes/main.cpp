// OOP - OBJECT ORIENTED PROGRAMMING
// CREATE A BLUEPRINT
#include <iostream>
#include <vector>

using namespace std;

// class Person {
//     private :
//         string name;
//         int height;
//         int age;
//         double weight;
//     public :
//         // CONSTRUCTOR -> Special method that runs when object is created
//         Person (string name, int age, int height, double weight){ 
//             this->name = name;
//             this->age = age;
//             this->height = height;
//             this->weight = weight;
//         }
//         Person (string name){ 
//             this->name = name;
//             this->age = 0;
//             this->height = 0.0;
//             this->weight = 0.0;
//         }
//         void setAge (int age){
//             if (age < 0){
//                 cout << "Invalid age" << endl;
//             }else {
//                 this->age = age;
//             }
//         }
//         void info(){
//             cout << "Person Information" << endl;
//             cout << "Name: " << this->name << endl;
//             cout << "Age: " << this->age << endl;
//             cout << "Height: " << this->height << endl;
//             cout << "Weight: " << this->weight << endl;
//         }
// };

class Animal {
    public :
        string name;
        int age;
        double weight;
        Animal(string name, int age, double weight){
            this->name = name;
            this->age = age;
            this->weight = weight;
        }

        virtual void info() {
            cout << "Generate Animal Information" << endl;
        }
};

class Dog : public Animal {
    private :
        string breed;
    public :
        Dog(string name, int age, double weight, string breed) 
        : Animal(name, age, weight){
            this->breed = breed;
        }
        void setBreed(string breed){
            this->breed = breed;
        }
        void bark(){
            cout << "Bark" << endl;
        }
        void info() override {
            cout << "Dog Information" << endl;
            cout << "Name: " << this->name << endl;
            cout << "Age: " << this->age << endl;
            cout << "Weight: " << this->weight << endl;
            cout << "Breed: " << this->breed << endl;
        }
        ~Dog(){
            cout << "Dog is destroyed" << endl;
        }
};

class Cat : public Animal {
    public :
        Cat(string name, int age, double weight, string color) 
        : Animal(name, age, weight){
            this->color = color;
        }
        string color;
        void meow(){
            cout << "Meow" << endl;
        }
        void info() override {
            cout << "Cat Information" << endl;
            cout << "Name: " << this->name << endl;
            cout << "Age: " << this->age << endl;
            cout << "Weight: " << this->weight << endl;
            cout << "Color: " << this->color << endl;
        }
};

int main() {
    // Person person1("John", 21, 170, 60.5);
    // person1.info();

    // cout << endl;
    // Person person2("Doe");
    // person2.setAge(-5);
    // person2.info();

    // Dog dog1("Dog 1", 5, 10.5, "Golden Retriever");
    // dog1.bark();
    // dog1.info();

    // // Cat cat1("Cat 1", 3, 5.5, "White");
    // // cat1.meow();
    // // cat1.info();
    // Animal animal1("Animal 1", 10, 20.5);
    // animal1.info();


    vector<Dog> dogs;
    dogs.push_back(Dog("Dog 1", 5, 10.5, "Golden Retriever"));
    dogs.push_back(Dog("Dog 2", 5, 10.5, "Puddle"));

    vector<Cat> cats;
    cats.push_back(Cat("Cat 1", 3, 5.5, "White"));
    cats.push_back(Cat("Cat 2", 3, 5.5, "Black"));
    for (int i = 0; i < dogs.size(); i++) {
        dogs[i].info();
    }
    
    for (int i = 0; i < cats.size(); i++) {
        cats[i].info();
    }
    return 0;
}
