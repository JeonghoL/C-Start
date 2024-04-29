#include <iostream>
#include <cstring>

class Complex {
	private:
		double real, img;
	
	public:
		Complex(double real, double img) : real(real), img(img) {}
		Complex(const Complex& c);

		Complex operator+(const Complex& c);
		Complex operator-(const Complex& c);
		Complex operator*(const Complex& c);
		Complex operator/(const Complex& c);

		Complex& operator=(const Complex& c);

		void println() { std::cout << " ( " << real << " , " << img << " ) " << std::endl; }
};
Complex::Complex(const Complex& c) {
	real = c.real;
	img = c.img;
}
Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real * c.real - img * c.img, real * c.img + c.real * img);
	return temp;
}
Complex Complex::operator/(const Complex& c) {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}
Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}

int main() {
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);
	Complex d(0.0, 0.0);
	Complex c = a * b;

	d = a * b + a / b + a + b;

	d.println();
}