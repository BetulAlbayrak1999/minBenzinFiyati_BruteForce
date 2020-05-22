/*
 Proje odevi: bruteForce
*/

#include <stdio.h>
#include <stdlib.h>

#define k 50//arac en az k km kadar gider
#define f 100//arac bir depo benzin ile max f km kadar gidebiliyor
#define yol 200//menzile olan toplam yol
int main(void) {
    int istasyonSayisi = 5;
	struct benzin{
		int m; //artan uzaklikta benzin istasyonu
		int p; //benzin istasyondaki bir depo benzinin ucrteti
	}istasyon[5];
	int globalFiyat = 0;
	int benzinAlindi = 0;
	int localFiyat;
    //degerleri belirleme
	istasyon[0].m = 0;
	istasyon[0].p = 3;
    istasyon[1].m = 30;
   	istasyon[1].p = 5;
    istasyon[2].m = 70;
   	istasyon[2].p = 4;
    istasyon[3].m = 130;
    istasyon[3].p = 3;
    istasyon[4].m = 180;
   	istasyon[4].p = 6;


   	int j= 0, i = 0;
   	while(j < istasyonSayisi && i < istasyonSayisi){
    	while(istasyon[i].m - benzinAlindi < k){
    	   	i++;
    	   	j = i + 1;
    	}
    	if(istasyon[i].m - benzinAlindi <= f && istasyon[j].m - benzinAlindi > f){
    		localFiyat = istasyon[i].p;
    		benzinAlindi = istasyon[i].m;
    	}
    	else if(istasyon[i].m - benzinAlindi <= f && istasyon[j].m - benzinAlindi <= f){
    		if(istasyon[j].p < istasyon[i].p){
    			localFiyat = istasyon[j].p;
    			benzinAlindi = istasyon[j].m;
    		}
    		else if(istasyon[j].p > istasyon[i].p ){
    			localFiyat = istasyon[i].p;
    			benzinAlindi = istasyon[i].m;
    		}
    	}
    	i++;
    	j = i + 1;
    	globalFiyat = globalFiyat + localFiyat;
    }

   	printf("gereken en az benzin ucreti: %d", globalFiyat);

    return 0;
}
