/**
 * @file sayi.cpp
 * @description Dugum sınıfının gerekli işlemlerini yapar.
 * @course 1-C
 * @assignment 1
 * @date 20.11.2023
 * @author Ali Tekeş ali.tekes@ogr.sakarya.edu.tr B221210094
 */
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Dugum.hpp"
#include "SayilarListesi.hpp"
using namespace std;

Dugum::Dugum()
{
	sayi = 0;
	sonrakidugum = 0;
}
int BasamakAdetGetir(int tempSayi)
{
	int basamakAdet = 1;
	while (tempSayi / 10 != 0)
	{
		tempSayi = tempSayi / 10;
		basamakAdet++;
	}
	return basamakAdet;
}
int *BasamaklariGetir(int sayi) // gönderilen sayının basamalarını biz pointer dizisine aktarır ve bu dizini ilk adresini döndürür.
{
	int diziBoyut = BasamakAdetGetir(sayi);
	int *dizi = new int[diziBoyut];

	for (int i = 0; i < diziBoyut - 1; i++)
	{
		int indis = diziBoyut - i - 1;
		if (sayi % 10 == 0)
		{
			dizi[indis] = 0;
		}
		else
		{
			dizi[indis] = sayi % 10;
		}
		sayi = sayi / 10;
	}
	dizi[0] = sayi;

	return dizi;
}
void SayininBasamaklariniBagliListeyeEkle(Sayi *ilgiliSayi)
{
	int *basamakDizisi = BasamaklariGetir(ilgiliSayi->deger); // basamakların bulunduğu dizini ilk adresini döndürür.

	int basamakAdet = BasamakAdetGetir(ilgiliSayi->deger);
	for (int i = 0; i < basamakAdet; i++)
	{
		ilgiliSayi->basamakEkle(basamakDizisi[i]);
	}
}
void Dugum::SayiEkle(int sayidegeri)
{
	Sayi *yenisayi = new Sayi(sayidegeri);
	SayininBasamaklariniBagliListeyeEkle(yenisayi); // verilen sayının her bir basamağı bağlı listeye aktarılacak.
	sayi = yenisayi;
}
