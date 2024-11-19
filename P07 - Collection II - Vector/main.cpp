#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // VECTOR -> Collection of similar data types with dynamic size
    // INITIALIZE VECTOR
    vector<int> vec;
    vector<int> vec2(26, 0);
    vector<int> vec3 = {10, 20, 30, 40, 50}; 
    vector<string> vecStr = {"Hello", "World"};
    vector<vector<int>> vec2D = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };

    // ADD ELEMENTS TO VECTOR
    vec.push_back(10);
    // vec2D.push_back(
    //     {10, 20, 30}
    //     );
    
    // ACCESS ELEMENTS
    cout << vec[0] << endl;
    cout << vec2D[0][0] << endl;

    // UPDATE ELEMENTS
    vec2[0] = 10;
    vec2[1] = 20;
    // vec2D[0][2] = 30;

    // DELETE ELEMENTS
    vec2.pop_back();
    vec2.erase(vec2.begin() + 0);

    // OUTPUT VECTOR
    for (int i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << " ";
    }
    cout << endl;

    // OUTPUT 2D VECTOR
    cout << vec2D[0][0] << endl;
    for (int y = 0; y < vec2D.size(); y++) {
        vector<int> vec2D_val = vec2D[y];

        for (int x = 0; x < vec2D_val.size(); x++) {
            cout << "{" << y << "," << x << "}"<< " ";
        }
        cout << endl;
    }

    // create 3d vector
    vector<vector<vector<int>>> vec3D = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 20, 30},
            {40, 50, 60},
            {70, 80, 90}
        }
    };
    // output 3d vector
    cout << vec3D[0][1][2] << endl;
    for (int z = 0; z < vec3D.size(); z++) {
        vector<vector<int>> vec3D_val = vec3D[z];
        for (int y = 0; y < vec3D_val.size(); y++) {
            vector<int> vec3D_val2 = vec3D_val[y];
            for (int x = 0; x < vec3D_val2.size(); x++) {
                cout << "{" << z << "," << y << "," << x << "}"<< " ";
            }
            cout << endl;
        }
    }
    // cout << endl;
    // for (auto i = vec2.begin(); i != vec2.end(); i++) {
    //     cout << *i << " ";
    // }
    // cout << endl;

    // for (auto i : vec2) {
    //     cout << i << " ";
    // }
    return 0;
}