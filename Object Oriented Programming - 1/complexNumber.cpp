class complexNumber
{
private:
    int real;
    int imaginary;

public:
    complexNumber(int real, int imaginary){
        this->real = real;
        this->imaginary= imaginary;
    }

    void print(){
        cout << real << " + " << imaginary << "i" << endl;
    }

    void plus(complexNumber c2){
        real = this->real + c2.real; 
        imaginary = this->imaginary + c2.imaginary;

    }

    void multiply(complexNumber c2){
        int real1 = this->real * c2.real;
        int imaginary1 = this->real * c2.imaginary;
        int imaginary2 = this->imaginary * c2.real;
        int iSqr = -1;
        int realImaginary = this->imaginary * c2.imaginary * iSqr;
        
        real = real1 + (realImaginary);
        imaginary = imaginary1 + imaginary2;
    }
};