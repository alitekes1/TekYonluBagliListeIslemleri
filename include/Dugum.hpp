#ifndef Dugum_HPP
#define Dugum_HPP
#include "Sayi.hpp"
class Dugum // sayilar listesi
{
public:
	Sayi* sayi;
	Dugum* sonrakidugum;
	Dugum();
	void SayiEkle(int sayi);
};
#endif