#include <iostream>
using namespace std;

class Imaginary{

    int re_, im_;

public:

    Imaginary(int re=0, int im=0){
        re_=re;
        im_=im;
    }

    int getRe(){
        return re_;
    }

    int getIm(){
        return im_;
    }


    void setRe(int re){
        re_=re;
    }

    void setIm(int im){
        im_=im;
    }

    Imaginary operator+(const Imaginary &x){
        Imaginary result;
        result.re_ = re_ + x.re_;
        result.im_ = im_ + x.im_;
        return result;
    }

    Imaginary operator-(const Imaginary &x){
        Imaginary result;
        result.re_ = re_ - x.re_;
        result.im_ = im_ - x.im_;
        return result;
    }

    Imaginary operator*(int q){
        Imaginary result;
        result.re_ = re_ * q;
        result.im_ = im_ * q;
        return result;
    }
    //void display(){
    //cout << re_ << "+" << im_<<"i"<<endl;
    //}
};

int main(){

    int re1, re2, im1, im2, operation, liczba;

    cout << "Podaj część rzeczywistą liczby zespolonej 1: ";
    cin >> re1;
    cout << endl;
    cout << "Podaj część zespoloną liczby zespolonej 1: ";
    cin >> im1;
    cout << endl;
    cout << "Podaj część rzeczywistą liczby zespolonej 2: ";
    cin >> re2;
    cout << endl;
    cout << "Podaj część zespoloną liczby zespolonej 2: ";
    cin >> im2;
    cout << endl;
    cout << "Wpisz 1 jeśli chcesz, aby funkcja wykonała dodawanie lub 2, jeśli odejmowanie lub 3, jeśli mnożenie przez stałą: ";
    cin >> operation;
    cout << endl;

    Imaginary a{re1, im1};
    Imaginary b{re2, im2};
    Imaginary c = a + b;
    Imaginary d = a - b;

    if(operation==1){
        cout << c.getRe() << " + " << c.getIm() << "i" << endl;
    }
    else if(operation==2){
        cout << d.getRe() << " - " << d.getIm() << "i" << endl;
    }
    else if(operation==3){
        cout << "Podaj stałą całkowitą przez którą chcesz pomnożyć liczby zespolone: ";
        cin >> liczba;
        cout << endl;
        Imaginary e = a * liczba;
        Imaginary f = b * liczba;
        //f.display();
        cout << e.getRe() << " + " << e.getIm() << "i" << endl;
        cout << f.getRe() << " + " << f.getIm() << "i" << endl;
    }
    else {
        cout << "Nie posiadam jeszcze takich działań" << endl;
    }
    return 0;
}