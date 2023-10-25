//
// Created by Jim Osei on 10/17/23.
//

#ifndef _COMPLEX_H
#define _COMPLEX_H

#include<math.h>
#include<iostream>
using namespace  std;

class complex{
public:
    complex(): re(0.0),im(0.0){}

    complex(double a){
        re = a;
        im =0.0;
    }

    complex(double a,double b){
        re = a,
        im = b;
    }

    complex(const complex& c){
        re = c.re;
        im = c.im;
    }

    complex& operator=(const complex& rhs){//assignment operator
        if(this != &rhs){
            re = rhs.re;
            im = rhs.im;
        }
        return *this;
    }
    complex& operator+=(const complex& z){//addition operator
            re += z.re;
            im += z.im;

            return *this;
    }
    complex& operator-=(const complex& z){
        re -= z.re;
        im -= z.im;

        return *this;
    }
    complex& operator*=(const complex& z){
        double temp_re = re *z.re - im * z.im;
        double temp_im = re * z.im + im * z.re;

        re = temp_re;
        im = temp_im;
         return *this;
    }
    complex& operator/=(const complex& z) {
       double denominator = z.re * z.re + z.im * z.im;
       double temp_re = (re * z.re + im * z.im)/denominator;
       double temp_im = (im * z.re - re * z.im)/denominator;

       re = temp_re;
       im = temp_im;
       
        return *this;
    }

    complex& operator+=(const double& x){
        re += x;
        return *this;
    }

    complex& operator-=(const double& z){
        re -= z;

        return *this;


    }
    complex& operator*=(const double& z){
        re *= z;
        im *= z;

        return *this;


    }
    complex& operator/=(const double& z) {
        re /= z;
        im /= z;

        return *this;

    }

    double real()const{return re;}
    double imag()const{return im;}



    double magnitude()const{
        return sqrt(re * re + im * im);
    }

private:
    double re,im;
};

//Addition Arithmetic
complex operator+(const complex& z1,const complex& z2){
        return complex(z1.real() + z2.real(),z1.imag() + z2.imag());
}
complex operator+(const complex&z1,const double x){
        return complex(z1.real() + x, z1.imag());
}
 complex operator+(const double x, const complex& z){
    return complex(x + z.real(), z.imag());
}

//Subtraction Arithmetic
complex operator-(const complex& z1,const complex& z2){
    return complex(z1.real() - z2.real(),z1.imag() - z2.imag());
}
complex operator-(const complex&z1,const double x){
    return complex(z1.real() - x, z1.imag());
}
complex operator-(const double x, const complex& z){
    return complex(x - z.real(), z.imag());
}

//Multiplication Arithmetic
complex operator*(const complex& z1,const complex& z2){
    double real,imag;
    real = z1.real() * z2.real();
    imag = z1.real() * z2.imag();
    imag += z1.imag() * z2.real();
    real -= z1.imag() * z2.imag();

    complex other(real,imag);

    return other;

}
complex operator*(const complex&z1,const double x){
    return complex(z1.real() * x, z1.imag() * x);
}

complex operator*(const double x, const complex& z) {
    return complex(x * z.real(), x * z.imag());
}
complex conj(const complex& z) { // Returns the conjugate of complex number
        return complex(z.real(),-1* z.imag());
    }

//Division Arithmetic
    complex operator/(const complex&z1,const double x){
    return complex(z1.real()/x,z1.imag()/x);
    }

    complex operator/(const complex& z1,const complex& z2) {
    complex num = z1 * conj(z2);
    double dem = pow(z2.real(),2) + pow(z2.imag(),2);

    complex other(num.real()/dem,num.imag()/dem);
    return other;
    }

    complex operator/(const double x, const complex& z){
        return complex(x/z.real(),x/z.imag());

    }


    //Unary Arithmetic Helper Function
    complex operator+(const complex& z){
        complex addComplex;
        return complex(addComplex.real() + z.real(),addComplex.imag() + z.imag());
}


complex operator-(const complex& z){
    complex subComplex;
    return complex(subComplex.real() - z.real(),subComplex.imag() - z.imag());
}

bool operator==(const complex& z1,const complex& z2){
    return z1.real() == z2.real() && z1.imag() == z2.imag();
}

bool operator!=(const complex& z1,complex& z2){
    return z1.real() != z2.real() || z1.imag() != z2.imag();
}

istream& operator>>(istream& is, complex& x){

    char ch;
    double realPart,imagPart;
//    is >> x.real();
//    is>>ch;
//    is >> x.imag();
//    is>> ch;

    is>> ch >>realPart >> ch >>imagPart>>ch;
    complex other(realPart,imagPart);
    x = other;

    return is;

}

ostream& operator<<(ostream& os, const complex& z){
    os <<"("<< z.real() << "," << z.imag()<< ")" <<endl;

    return os;
}


double magnitude(const complex& z) { // also known as absolute value
    return sqrt(z.real()  * z.real() + z.imag() *  z.imag());

}
double real(const complex& z){
    return z.real();
}
 double imag(const complex& z){
    return z.imag();
}
complex polar(const double r, const double theta) { // Constructs a complex via polar coords. o complex polar(const doubler);
        return complex(r *cos(theta),r * sin(theta));

}

 double norm(const complex& z) {
    return z.real() * z.real() + z.imag() * z.imag();
 }

double arg(const complex& z) {
    return atan2(z.imag(), z.real());
}

#endif //P03318OSEIJ_COMPLEX_H
