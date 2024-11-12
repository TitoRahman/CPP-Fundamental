#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function Declaration
// [Return Type] [Function Name] ([Parameter Type] [Parameter Name], ...)
// Return Type :
// void => Function does not return any value
// int => Function returns an integer value
// double => Function returns a double value
// string => Function returns a string value
// char => Function returns a char value
// bool => Function returns a boolean value
// void printHelloWorld()
// {
//     cout << "Hello World" << endl;
// }
// Parameter => Variable that is used to store the value that is passed to the function
// int add(int a, const int b) {
//     int c = 10;
//     return a + b + c;
// }

int multiAdd(int n){
    int multi_total = 0;
    for (int i = 0; i < n; i+= 1)
    {
        cout << "Masukkan nilai ke-" << i+1 << ": ";
        int nilai;
        cin >> nilai;
        multi_total += nilai;
    }
    return multi_total;
}
// Function with default parameter
int add2Total(int total_a, int total_b = 0){
    return total_a + total_b;
}

// Function overloading
double add2Total(double total_a, double total_b){
    return total_a + total_b;
}

void printf(int a){
    cout << a << endl;
}

int main()
{
    // int total_1 = multiAdd(5);
    // int total_2 = multiAdd(10);
    // int total = add2Total(total_1, total_2);
    // int total = add2Total(10);
    // double total_d = add2Total(10.5, 20.10);
    // cout << "Total nilai: " << total << endl;   
    // cout << "Total nilai: " << total_d << endl;
    // printf("ABC");
    
    string word;
    ifstream file;
    file.open("test.txt");
    // file >> words;
    // EOF => End of File
    string words = "";
    while(getline(file, word)){
        words += word + "\n";
    }
    cout << words;
    cout << word;
    return 0;
}

