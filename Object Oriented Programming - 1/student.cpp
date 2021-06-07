class student{
public:
    int rollNumber;

private:
    int age;

public:

    //Default Constructor
    student(){
         cout << "Constructor Called" << endl;
    }

    void display(){
        cout << age << " " << rollNumber << endl;
    }

    int getAge(){
        return age;
    }

    void setAge(int a, int password){
        if (password != 123){
            return;
        }

        if (a < 0){
            return;
        }
        age = a;
    }
};