class fraction
{
private:
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << this->numerator << "/" << denominator << endl; //writing this here is optional bcz there is no arguments which have data member name.
    }

    void simpify(){
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for(int i = 1; i <= j; i++){
            if(this->numerator % i == 0 && this->denominator % i == 0){
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }


    void add(fraction f2){

        int lcm = this->denominator * f2.denominator;  //writing this here is optional bcz there is no arguments which have data member name.
        int x = lcm/denominator;
        int y = lcm/f2.denominator;

        int num =  (x * numerator)+(y * f2.numerator);
        numerator = num;
        denominator = lcm;

        //we need to simplify the denominator also
        simpify();
    }

};

