/** 
* @file sayi.cpp
* @description Basamak sınıfının gerekli işlemlerini yapar.
* @course 1-C
* @assignment 1
* @date 20.11.2023
* @author Ali Tekeş ali.tekes@ogr.sakarya.edu.tr B221210094
*/
#include <iostream>
#include "Basamak.hpp"

using namespace std;

Basamak::Basamak(int deger)
{
	this->deger = deger;
	sonraki = 0;
}
