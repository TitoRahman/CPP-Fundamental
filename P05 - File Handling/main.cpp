#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void writeToFile(string filename, string words){
    ofstream file;
    file.open("output/"+filename+".txt");
    if (file.is_open())
    {
        file << words << endl;
        file.close();
    } else {
        cout << "File tidak dapat dibuka" << endl;
    }
}

string readFromFile(string filename){
    ifstream file;
    file.open("output/"+filename+".txt");
    string words = "";
    string word;
    while(getline(file, word)){
        words += word + "\n";
    }
    file.close();
    return words;
}

void appendToFile(string filename, string word)
{
    string oldWords = readFromFile(filename);
    writeToFile(filename, oldWords + word);
}
int main(){
    // ofstream => Output File Stream - WRITE TO FILE - Overwrite
    // ifstream => Input File Stream - READ FROM FILE
    // fstream => File Stream - READ AND WRITE TO FILE

    appendToFile("data", "Hello World123\n");
    // string word;
    // ofstream file;
    // file.open("data.txt");
    // if (file.is_open())
    // {
    //     getline(cin, word);
    //     file << word << endl;
    //     file.close();
    // } else {
    //     cout << "File tidak dapat dibuka" << endl;
    // }

    // ifstream file;
    // file.open("data.txt");
    // string words = "";
    // string word;
    // while(getline(file, word)){
    //     words += word + "\n";
    // }
    // file.close();

    // // file.open("data2.txt");
    // // string word_2;
    // // file >> word_2;
    // // file.close();
    // // cout << word_2 << endl;

    // cout << "Old Words: \n" << words << endl;
    // char c;
    // cout << "Apakah kamu ingin menambahkan kata? (y/n): ";
    // cin >> c;
    // cin.ignore();
    
    // if (c == 'y'){
    //     ofstream o_file;
    //     o_file.open("data.txt");
    //     cout << "Masukkan kata yang ingin ditambahkan: ";
    //     getline(cin, word);
    //     o_file << words << word << endl;
    //     o_file.close();
    // }

    vector<int> n_list = {1, 2, 3, 4, 5};
    n_list.pop_back();
    n_list.pop_back();
    n_list.pop_back();

    n_list.push_back(10);
    n_list.insert(n_list.begin()+3, 20);
    n_list.insert(n_list.begin()+3, 20);
    n_list.clear();
    n_list.clear();
    int a = n_list.capacity();
    int b = n_list.size();
    cout << "Capacity: " << a << endl;
    cout << "Size: " << b << endl;
        // int n_arr[5] = {1, 2, 3, 4};
    // n_arr[4] = 10;
    // // n_list[2] = 10;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << n_arr[i] << endl;
    // }
    

    return 0;
}