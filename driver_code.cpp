#include <iostream>
#include <algorithm>
#include <vector>
#include "vector.h"

int main(){
    vector<int> vect;
    std::cout << "vect.empty() " << vect.empty() << "\n";
    for (int i=0; i<10; i++) vect.push_back(i);
    std::reverse(vect.begin(),vect.end());
    for (int i=0; i<vect.size(); i++) std::cout << vect[i] << ",";
    std::cout << "\nvect.empty() " << vect.empty();
    std::cout << "\nVector size: " << vect.size();
    std::cout << "\nVector memory size: " << vect.capacity();
    std::cout << "\nVector.begin() " << vect.begin() << " : " << *vect.begin();
    std::cout << "\nVector.end() " << vect.end() << " : " << "UB";
    std::cout << "\nVector.back() " << vect.back();
    std::cout << "\nVector.front() " << vect.front();
    std::cout << "\nVector iterator loop:\n";
    vect.push_front(34);
    vect.push_front(56);
    for (vector<int>::iterator i = vect.begin(); i!=vect.end(); i++){
        std::cout << *i << ",";
    } std::cout << std::endl;
    std::cout << "sizeof(vector<int>::size_type) : " << sizeof(vector<int>::size_type) << std::endl;
    std::cout << "sizeof(vector<int>::iterator) : " << sizeof(vector<int>::iterator) << std::endl;
    std::cout << std::endl;


    vector<int> listTest = {1,2,3,4,5};
    listTest.pop_back();
    listTest.push_back(6);
    for (int i=0; i<listTest.size(); i++) std::cout << listTest[i] << ",";
    std::cout << "\nlistTest.capacity(): " << listTest.capacity() << "\n";
    std::cout << "listTest.shrink_to_fit()\n";
    listTest.shrink_to_fit();
    std::cout << "listTest.size(): " << listTest.size() << "\n";
    std::cout << "listTest.capacity(): " << listTest.capacity() << "\n";
    return 0;
}
