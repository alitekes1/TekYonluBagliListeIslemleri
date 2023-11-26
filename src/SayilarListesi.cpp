/**
 * @file sayi.cpp
 * @description SayilarListesi sınıfının gerekli işlemlerini yapar.
 * @course 1-C
 * @assignment 1
 * @date 20.11.2023
 * @author Ali Tekeş ali.tekes@ogr.sakarya.edu.tr B221210094
 */

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "SayilarListesi.hpp"

using namespace std;

SayilarListesi::SayilarListesi()
{
	ilkdugum = 0;
}
string AdresinSonUcBasDondur(Basamak* adres)
{
	uintptr_t hexValue = reinterpret_cast<uintptr_t>(adres);
	stringstream ss;
	ss << hex << hexValue;
	string hexString = ss.str();

	hexString = hexString.substr(hexString.length() - 3); // değerin son 3 basamağını döndürür.

	return hexString;
}
void SayilarListesi::ListeyiYazdir()
{
	Dugum* geciciDugum = ilkdugum;
	while (geciciDugum != 0)
	{
		Sayi* geciciSayi = geciciDugum->sayi;
		Basamak* geciciBasamak = geciciSayi->ilkBasamak;

		int basamakAdet = geciciSayi->ListedekiBasamakAdetGetir();

		cout << "###########   ";
		for (int i = 0; i < basamakAdet; i++)
		{
			cout << "******* ";
		}

		cout << endl;
		cout << "#" << setw(9) << geciciSayi << "#   "; // sayinin adresi
		
		geciciBasamak = geciciSayi->ilkBasamak;			// ilk while sonucunda gecicibasamak 0 ı gösteriyordu. yeni bir değişken oluşturmak yerine tekrar varolan değişkene ilkbasamağı atadık.
		
		while (geciciBasamak != 0)
		{
			string basamakAdres = AdresinSonUcBasDondur(geciciBasamak);
			cout << "*" << setw(4) << basamakAdres << " * ";
			geciciBasamak = geciciBasamak->sonraki;
		}
		
		cout << endl;
		cout << "#---------#   ";
		
		for (int i = 0; i < basamakAdet; i++)
		{
			cout << setw(3) << "******* ";
		}
		
		cout << endl;
		cout << "#" << setw(9) << geciciSayi->deger << "#" << setw(4); // sayinin değeri

		geciciBasamak = geciciSayi->ilkBasamak;
		cout << setw(4);
		
		while (geciciBasamak != 0)
		{
			cout << " *" << setw(3) << geciciBasamak->deger << setw(3) << "*"; // basamak değeri
			geciciBasamak = geciciBasamak->sonraki;
		}
		
		cout << endl;
		cout << "###########   " << setw(5);
		
		for (int i = 0; i < basamakAdet; i++)
		{
			cout << setw(3) << "******* ";
		}
		cout << endl;
		cout << endl;
		cout << endl;
		geciciDugum = geciciDugum->sonrakidugum;
	}
}

void SayilarListesi::EnBuyukSayiyiCikar() // Sayılar listesindeki her düğümün sayi değeri en buyuk olanı çıkarıyoruz.
{
	if (ilkdugum == 0)
	{
		cout << endl
			<< "*****LISTEDE ELEMAN YOK!*****" << endl;
		return;
	}
	Dugum* gecici = ilkdugum;
	Dugum* enBuyukSayi = ilkdugum;
	Dugum* silinecekdenOnceki = 0;
	while (gecici->sonrakidugum != 0)
	{
		if (gecici->sonrakidugum->sayi->deger >= enBuyukSayi->sayi->deger)
		{
			silinecekdenOnceki = gecici;
			enBuyukSayi = gecici->sonrakidugum;
		}
		gecici = gecici->sonrakidugum;
	}
	if (silinecekdenOnceki != 0)
	{
		silinecekdenOnceki->sonrakidugum = enBuyukSayi->sonrakidugum;
	}
	else // ilk sayi en buyuk sayiysa eger
	{
		ilkdugum = ilkdugum->sonrakidugum;
	}
	delete enBuyukSayi;
}

void SayilarListesi::SayininBasamaklariniTersle() // Sayılar listesindeki her düğümün sayi değeri için basamakları tersliyoruz
{
	Dugum* gecici = ilkdugum;
	while (gecici != 0)
	{
		gecici->sayi->BasamaklariTersle();
		gecici = gecici->sonrakidugum;
	}
}
void SayilarListesi::TekBasamaklariBasaAl() // Sayılar listesindeki her düğümün sayi değeri için tek basamakları başa alıyoruz
{
	Dugum* gecici = ilkdugum;
	while (gecici != 0)
	{
		gecici->sayi->CiftleriSonaAl();
		gecici = gecici->sonrakidugum;
	}
}
void SayilarListesi::DugumEkle(int sayi)
{
	Dugum* yeniDugum = new Dugum();
	if (ilkdugum == 0)
	{
		yeniDugum->SayiEkle(sayi);
		ilkdugum = yeniDugum;
	}
	else
	{
		yeniDugum->SayiEkle(sayi); // sayinin basamaklarini ekleyecek
		Dugum* gecici = ilkdugum;

		while (gecici->sonrakidugum != 0) // sayilar listesi nin sonuna gidiyoruz.
		{
			gecici = gecici->sonrakidugum;
		}
		gecici->sonrakidugum = yeniDugum;
	}
}