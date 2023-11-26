#ifndef SayilarListesi_hpp
#define SayilarListesi_hpp

using namespace std;
#include "Dugum.hpp"

class SayilarListesi // tüm sayılara ulaşmak için düğümlerden oluşan sayılar listesi
{
public:
	Dugum* ilkdugum;
	SayilarListesi();
	void ListeyiYazdir();
	void TekBasamaklariBasaAl();
	void SayininBasamaklariniTersle();
	void EnBuyukSayiyiCikar();
	void DugumEkle(int sayi);
};
#endif