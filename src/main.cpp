/**
 * @file main.cpp
 * @description Ekrana listeyi bastırır ve kullanıcıdan bir seçim yapmasını ister.Seçime göre işlemler yapar.
 * @course 1-C
 * @assignment 1
 * @date 20.11.2023
 * @author Ali Tekeş ali.tekes@ogr.sakarya.edu.tr B221210094
 */
#include <iostream>
#include <fstream>
#include "SayilarListesi.hpp"
using namespace std;

void MenuSecimiVeSayiYazdirma(int* secim, SayilarListesi* sayilarlistesi)
{
	sayilarlistesi->ListeyiYazdir();

	cout << "1-Tek Basamaklari Basa Al" << endl
		<< "2-Basamaklari Tersle" << endl
		<< "3-En Buyuk Cikar" << endl
		<< "4-Cikis" << endl;
	cin >> *secim;
}

void DosyadanSayiOkuVeListeyeDugumEkle(SayilarListesi* sayiListesi)
{
	int okunacakSayi = 0;

	fstream dosya;
	dosya.open("sayilar.txt", ios::in);
	if (dosya.is_open())
	{
		while (dosya >> okunacakSayi)
		{
			sayiListesi->DugumEkle(okunacakSayi);
		}
	}
	else
	{
		cout << "dosya acilamadi" << endl;
	}
	dosya.close();
}

int main()
{
	SayilarListesi* sayiListesi = new SayilarListesi();

	int secim = 0;

	DosyadanSayiOkuVeListeyeDugumEkle(sayiListesi);

	do
	{
		MenuSecimiVeSayiYazdirma(&secim, sayiListesi);//ekrana listedeki verileri çıkarır ve ardından kullanıcıdan yapmak istediği işlemi seçmesini ister.
		switch (secim)
		{
		case 1:
			sayiListesi->TekBasamaklariBasaAl();
			break;
		case 2:
			sayiListesi->SayininBasamaklariniTersle();
			break;
		case 3:
			sayiListesi->EnBuyukSayiyiCikar();
			break;
		case 4:
			return 0;
		default:
			cout << "****LUTFEN 1-4 ARASINDA DEGER GIRINIZ****" << endl;
			break;
		}
	} while (secim != 4);
}
