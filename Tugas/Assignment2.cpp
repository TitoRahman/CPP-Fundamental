#include <iostream>
#include <string>

using namespace std;

string alternatingString(string word_a, string word_b){
    string new_word = "";
    if (word_a.length() > word_b.length()){
        for (int i = 0; i < word_a.length(); i++)
        {
            new_word += word_a[i];
            if (i < word_b.length()){
                new_word += word_b[i];
            }
        }
    } else {
        for (int i = 0; i < word_b.length(); i++)
        {
            new_word += word_b[i];
            if (i < word_a.length()){
                new_word += word_a[i];
            }
        }
    }
    return new_word;
}

int main()
{
    cout << alternatingString("123", "abcdedf" ) << endl;
    return 0;
}