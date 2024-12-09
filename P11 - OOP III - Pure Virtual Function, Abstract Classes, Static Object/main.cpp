// #include <iostream>
// #include <string>

// using namespace std;


// enum jenisBarang {
//     bekas = false, // 0
//     baru = true // 1
// } barang;


// // Static Class
// class MathUtils {
//     private :
//         MathUtils() {
//             // Private Constructor
//         }

//         int n =0;
//     public:
//         // Static Function
//         static int add(int a, int b) {
//             return a + b;
//         }

//         // Static Function
//         static int subtract(int a, int b) {
//             return a - b;
//         }
// };

// // Abstract Class
// class Shape {
//     public:
//         // Pure Virtual Function
//         virtual void draw() = 0;
// };

// class Circle : public Shape {
//     public:
//         void draw() {
//             cout << "Drawing Circle" << endl;
//         }
// };

// class Rectangle : public Shape {
//     public:
//         void draw() {
//             cout << "Drawing Rectangle" << endl;
//         }
// };
// int counter2 = 0;

// // static int counter = 0;
// void coutner() {
//     static int counter = 0;
//     counter++;
//     cout << counter << endl;
// }

// int main() {
//     coutner();
//     coutner();
//     coutner();
//     // Dynamic Polymorphism
//     Shape* shape;
//     shape = new Circle();
//     shape->draw();

//     shape = new Rectangle();
//     shape->draw();

//     // Static Polymorphism
//     Circle circle;
//     circle.draw();

//     Rectangle rectangle;
//     rectangle.draw();

//     MathUtils::add(10, 20);
//     // MathUtils mathUtils();
//     // mathUtils.add(10, 20);

//     barang = baru;
//     cout << barang << endl;
//     return 0;
// }

