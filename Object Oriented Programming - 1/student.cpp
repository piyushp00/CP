class student
{
public:
    int rollNumber;

private:
    int age;

public:
    void display()
    {
        cout << age  << " " << rollNumber << endl;
    }

    int getAge(){
        return age;
    }

    int setAge(int a) {
        age = a;
        return age;
        
    }
};