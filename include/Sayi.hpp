#ifndef Sayi_HPP
#define Sayi_HPP

#include "Basamak.hpp" 
class Dugum;

class Sayi // basamak listesi
{
public:
	int deger;
	Basamak* ilkBasamak; // sayının basamaklarının bağlı listedeki ilk adresi. bu sayede sayının tüm basamaklarına ulaşacağız.
	Sayi(int deger = 0);
	void basamakEkle(int basamak);
	void basamakYazdir();
	void BasamaklariTersle();
	void CiftleriSonaAl();
	int ListedekiBasamakAdetGetir();
};
#endif
