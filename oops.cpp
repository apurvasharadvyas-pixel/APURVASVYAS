#include<iostream>
using namespace std;
class Dog{
    public:
    void bark();
};
void Dog::bark()
{
    cout<<"Dog barks on strangers!"<<endl;
}
int main()
{
    Dog d;
    d.bark()
    return 0;
}