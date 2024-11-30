#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    // STRING -> Collection of characters -> Dynamic size
    // INITIALIZE STRING
    string str = "WORD 1";
    char str2[] = "STRING 2";

    // INPUT STRING
    // getline(cin, str);

    cout << str << " " << str[0] << endl;
    cout << str2 << endl;

    // UPDATE STRING
    str[0] = 'A';
    cout << str << endl;

    // ADD STRING
    str += " WORD 2";
    str.append(" WORD 3");
    cout << str << endl;

    // SIZE OF STRING
    str = "WORLD";
    cout << str.size() << endl;
    cout << str.length() << endl;

    // SUBSTRING -> Get part of string
    cout << str.substr(2, 2) << endl;

    // FIND -> Find position of substring
    string substring = "WD";
    // cout << str.find(substring) << endl;
    int index_substring = str.find(substring);
    for (int i = index_substring; i < index_substring + substring.length(); i++) {
        cout << str[i];
    }
    // ERASE -> Remove part of string
    str.erase(1, 2);
    cout << str << endl;

    // INSERT -> Add part of string
    str.insert(1, "ELLO"); // W (ELLO) LD
    cout << str << endl;

    // REPLACE -> Change part of string
    str = "1234567";
    str.replace(1, 3, "99999"); // W(ELL)OLD -> W (ORLD) LD -> WORLDLD
    cout << str << endl;

    // CLEAR -> Remove all characters
    str.clear();

    // EMPTY -> Check if string is empty
    if (str.empty()) {
        cout << "String is empty" << endl;
    } else {
        cout << "String is not empty" << endl;
    }

    // STRING TO INTEGER
    string str_num = "123";
    int num = stoi(str_num);

    // INTEGER TO STRING
    int num2 = 123;
    string str_num2 = to_string(num2);

    // STRING TO DOUBLE
    string str_double = "123.45";
    double num_double = stod(str_double);

    // DOUBLE TO STRING
    double num_double2 = 123.45;
    string str_double2 = to_string(num_double2);

    cout << endl;
    // COMPARE STRING
    string strComp1 = "HELLO";
    string strComp2 = "HELLO";
    string strComp3 = "WORLD";
    cout << strComp1.compare(strComp2) << endl;
    cout << strComp1.compare(strComp3) << endl;

    bool is_equal = strComp1 == strComp2;
    cout << is_equal << endl;

    // STRING TO CHAR ARRAY
    string strChar = "HELLO";
    char charArr[10];
    strcpy(charArr, strChar.c_str());
    cout << charArr << endl;
    return 0;
}