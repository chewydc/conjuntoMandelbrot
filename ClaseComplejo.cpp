/******************************************************************************************/
/*                                      TPO2 DPOO                                         */
/*  ALUMNO: Damian del Campo                                                              */
/*  LU: 1027477                                                                           */
/*  CARRERA: Ingenieria en Telecomunicaciones                                             */
/*  FECHA: 28/11/2015                                                                     */
/*  ARCHIVO: ClaseComplejo.cpp                                                            */
/*                                                                                        */
/******************************************************************************************/

#include "ClaseComplejo.h"

complejo::complejo() : re_(0), im_(0) {}
complejo::complejo(float x, float y) : re_(x), im_(y) {}
complejo::complejo(const complejo &Z) : re_(Z.re_), im_(Z.im_) {}

bool complejo::operator ==(const complejo &x)
{
	if (re_ == x.re_ && im_ == x.im_) return true;
	return false;

}

complejo const & complejo::operator=(complejo const &Z)
{
	re_ = Z.Re();
	im_ = Z.Im();
	return *this;
}

float complejo::Re() const
{
	return re_;
}

float complejo::Im() const
{
	return im_;
}

complejo::~complejo() {}

float complejo::m2() const
{
	return re_ * re_ + im_ * im_;
}

complejo const & complejo::conjugar()
{
	im_ *= -1;
	return *this;
}

complejo const complejo::conjugado() const
{
	return complejo(re_, -im_);
}

complejo const operator+(complejo const &x, complejo const &y) //Sobrecarga operador suma
{
	complejo z(x.Re() + y.Re(), x.Im() + y.Im());
	return z;
}

complejo const operator-(complejo const &x, complejo const &y) //Sobrecarga operador resta
{
	complejo z(x.Re() - y.Re(), x.Im() - y.Im());
	return z;
}

complejo const operator*(complejo const &x, complejo const &y) //Sobrecarga operador multiplicacion
{
	complejo r(x.Re() * y.Re() - x.Im() * y.Im(),
		x.Re() * y.Im() + x.Im() * y.Re());
	return r;
}
complejo const operator/(complejo const &x, complejo const &y)
{
	return x * y.conjugado() / y.m2();
}
complejo const operator/(complejo const &x, float const &y)
{
	complejo c(x.Re() / y, x.Im() / y);
	return c;
}

ostream & operator<<(ostream &os, const complejo &c)
{
	return os << "("
		<< c.Re()
		<< ", "
		<< c.Im()
		<< ")";
}

istream &
operator>>(istream &is, complejo &c)
{
	float re = 0;
	float im = 0;
	int okay = 0;
	char ch = 0;

	if (is >> ch
		&& ch == '(') {
		if (is >> re
			&& is >> ch
			&& ch == ','
			&& is >> im
			&& is >> ch
			&& ch == ')')
			okay = 1;
	}
	else {
		is.putback(ch);
		if (is >> re)
			okay = 1;
	}

	if (okay)
		c.re_ = re, c.im_ = im;
	else
		is.clear(ios::badbit);

	return is;
}

