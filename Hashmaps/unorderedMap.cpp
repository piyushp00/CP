#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string, int> ourMap;

    //insert(1st way)
    pair<string, int> p("abc", 1);
    ourMap.insert(p);

    //insert(2nd way)
    ourMap["def"] = 2;

    //find or access
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;

    
    //cout << ourMap.at("ghi") << endl; //it will give error
    cout << "Size: " << ourMap.size() << endl;
    cout << ourMap["ghi"] << endl; //it will not give error but,if it dont exist ,it will insert default value of zero
     cout << "Size: " << ourMap.size() << endl;

    //To check if key is present or not we will use count fn, it will return 0 or 1 ncz one key exist only once

    if(ourMap.count("ghi") > 0){ //it will give true bcz we tried to access "ghi" using sqr brackets above
        cout << "ghi is present" << endl;
    }

    //erase
    ourMap.erase("ghi");
     cout << "Size: " << ourMap.size() << endl;
    if(ourMap.count("ghi") > 0){ //it will give true bcz we tried to access "ghi" using sqr brackets above
        cout << "ghi is present" << endl;
    } else {
        cout << "ghi is not present" << endl;
    }
}    