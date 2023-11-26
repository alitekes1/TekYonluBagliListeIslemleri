/**
 * @file sayi.cpp
 * @description Sayi sınıfının gerekli işlemlerini yapar.
 * @course 1-C
 * @assignment 1
 * @date 20.11.2023
 * @author Ali Tekeş ali.tekes@ogr.sakarya.edu.tr B221210094
 */

#include <iostream>
#include <string>
#include <math.h>
#include "Sayi.hpp"
using namespace std;

Sayi::Sayi(int deger)
{
	this->deger = deger;
	ilkBasamak = 0;
}
void Sayi::basamakEkle(int basamak)
{
	Basamak* basamakYeni = new Basamak(basamak);

	if (ilkBasamak == 0) // eğer daha önce hiç basamak nesnemiz yoksa yenibasamağı ilkbasamak olarak atıyoruz.
	{
		ilkBasamak = basamakYeni;
	}
	else
	{
		Basamak* gecici = ilkBasamak; // ilk basamağa ait verileri kaybetmemek için onu geçici ye atıyoruz.
		while (gecici->sonraki != 0)
		{
			gecici = gecici->sonraki;
		}
		gecici->sonraki = basamakYeni;
	}
}
void Sayi::basamakYazdir()
{
	Basamak* gecici = ilkBasamak;
	while (gecici != 0)
	{
		cout << "basamak adres:" << gecici << "-basamak deger:" << gecici->deger << "--basamak sonraki adres:" << gecici->sonraki << endl;
		gecici = gecici->sonraki;
	}
}
int Sayi::ListedekiBasamakAdetGetir()
{
	Basamak* gecici = ilkBasamak;
	int basamakAdet = 0;
	while (gecici != 0)
	{
		basamakAdet++;
		gecici = gecici->sonraki;
	}
	return basamakAdet;
}

void SayiyiGuncelle(Basamak* ilkbasamak, Sayi* sayi)
{
	Basamak* gecici = ilkbasamak;
	int basamakAdet = sayi->ListedekiBasamakAdetGetir();
	double sayiDegeri = 0;
	while (gecici != 0)
	{
		basamakAdet--;
		sayiDegeri += (gecici->deger * (pow(10, basamakAdet)));
		gecici = gecici->sonraki;
	}
	sayi->deger = sayiDegeri;
}

void Sayi::BasamaklariTersle()
{
	if (ilkBasamak == 0 || ilkBasamak->sonraki == 0)
	{
		return;
	}
	else // sayi birden fazla basamaktan oluşuyorsa
	{
		Basamak* gecici = ilkBasamak;
		Basamak* next = 0;
		Basamak* prev = 0;
		while (gecici != 0)
		{
			next = gecici->sonraki; // next değeri 2. sıradaki dugum oluyor.
			gecici->sonraki = prev; // 2. sıradaki dugume 0 atanıyor. yani sonuncu dugum oluyor.
			prev = gecici;			// ilk sıradaki dugum prev e atanıyor
			gecici = next;			// ilk sıradaki dugum artık 2. sıradaki dugumu gösteriyor
		}
		ilkBasamak = prev;
		SayiyiGuncelle(ilkBasamak, this); // bu işlemden sonra sayının değeri değişeceği için (örn 123 iken 321 olacak) sayının değerini güncelliyoruz.
	}
}

Basamak* SonElemaniGetir(Basamak* ilk)
{
	Basamak* gecici = ilk;
	Basamak* son = 0;
	while (gecici->sonraki != 0)
	{
		gecici = gecici->sonraki;
	}
	son = gecici;
	return son;
}

void Sayi::CiftleriSonaAl() // düğümdeki sayı için bu işlemi yapıyor.
{
	if (ilkBasamak == 0 || ilkBasamak->sonraki == 0)
	{
		return;
	}
	Basamak* gecici = ilkBasamak;
	int basamakAdet = ListedekiBasamakAdetGetir();
	Basamak* tasi = 0;
	Basamak* son = SonElemaniGetir(ilkBasamak);
	while (ilkBasamak != 0 && ilkBasamak->deger % 2 == 0 && basamakAdet > 0) // ilk basamak çiftse
	{
		gecici = ilkBasamak; // gecicinin degerini guncelliyoruz. cunku ilk basamak degisti
		ilkBasamak = ilkBasamak->sonraki;
		son = SonElemaniGetir(gecici); // son u güncelliyoruz çünkü sona alma durumları var
		son->sonraki = gecici;
		gecici->sonraki = 0;
		basamakAdet--;
	}
	son = SonElemaniGetir(ilkBasamak);
	gecici = ilkBasamak;
	for (int i = 0; i < basamakAdet - 1; i++) // artık ilk basamağımız tek sayı bu yüzden sabit kalacak
	{
		if (gecici->sonraki != 0 && gecici->sonraki->deger % 2 == 0) // çiftse eğer
		{
			tasi = gecici->sonraki;
			if (tasi->sonraki != 0) // eğer eleman sonda değilse sona tasiyacak
			{
				gecici->sonraki = tasi->sonraki;
				son->sonraki = tasi; // tasinacak elemanı en sona atmış olduk
				tasi->sonraki = 0;
				son = SonElemaniGetir(ilkBasamak);
			}
		}
		else
		{
			gecici = gecici->sonraki;
		}
	}
	son = SonElemaniGetir(ilkBasamak); // son u güncelliyoruz çünkü sona alma durumları var
	SayiyiGuncelle(ilkBasamak, this);  // bu işlemden sonra sayının değeri değişeceği için (örn 123 iken 132 olacak) sayının değerini güncelliyoruz.
}