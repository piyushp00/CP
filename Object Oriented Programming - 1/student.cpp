class student
{
public:
    int rollNumber;

private:
    int age;

public:

    //Destructor
    ~student()
    {
        cout << "Destructor Called !" << endl;
    }
    //Default Constructor
    student(){
         cout << "Constructor 1 Called !" << endl;
    }

    //Parametrized Constructor
    /* student(int r)
    {
        cout << "Constructor 2 called" << endl;
        rollNumber = r;
    } */

    //For having parameter name same as data member name
    student(int rollNumber)
    {
        cout << "Constructor 2 called" << endl;
        //writing this is here is necessary
        this->rollNumber = rollNumber;
    }

    student(int a, int r)
    {
        cout << "this :" << this << endl;
        cout << "Constructor 3 called" << endl;
        //writing this here is optional
        this->age = a;
        this->rollNumber = r;
    }

    void display()
    {
        cout << age << " " << rollNumber << endl;
    }

    int getAge()
    {
        return age;
    }

    void setAge(int a, int password)
    {
        if (password != 123)
        {
            return;
        }

        if (a < 0)
        {
            return;
        }
        age = a;
    }
};