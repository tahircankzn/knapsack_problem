#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
	int kapaste1 = 0;
	float kapaste;
	float canta_agirligi = 0;
	
	int value[5];
	int value1 = 0;
	
	int weight[5];
	int weight1 = 0;	
   FILE *dosya = fopen("test.txt", "r");
int maxTahminiSatirUzunlugu = 255;
char satir[maxTahminiSatirUzunlugu];
while(fgets(satir, maxTahminiSatirUzunlugu, dosya)) {    
    char * parca;   
    parca = strtok (satir," ");	
	int parcaIndex = 0;	
	while (parca != NULL)
	{
		parcaIndex++;
		int vakaSayisi = atoi(parca);
		
		if(kapaste1 == 0){
			kapaste = (float)vakaSayisi;
			kapaste1++;
		}
		else if(parcaIndex > 1){

			printf("value: %d\n", vakaSayisi);
			value[value1] = vakaSayisi;
			value1 = value1 + 1 ;				
		} 
		else {
			
			printf("weight : %d\n", vakaSayisi);
			weight[weight1] = vakaSayisi;
			weight1 = weight1 + 1 ;			
		}		 
		parca = strtok(NULL, " ");
		
	}    
}
fclose(dosya);
float birim_deger_listesi[4];
cout << "birim degerler " << endl;
float temp;
for(int i = 0;i<4;i++){
	birim_deger_listesi[i] = (float)value[i] / (float)weight[i];
	printf("%d / %d : %.2f\n",value[i],weight[i],birim_deger_listesi[i]);
}
// listeyi sıralama
for(int j=0;j<5;j++){
        for(int i=0;i<5;i++){
            if((float)birim_deger_listesi[i]<(float)birim_deger_listesi[i+1]){
                temp=(float)birim_deger_listesi[i];
                birim_deger_listesi[i]=birim_deger_listesi[i+1];
                birim_deger_listesi[i+1]=temp;
            }
        }
    }   
    
for(int i=0;i<4;i++){
        printf("%.2f\n",birim_deger_listesi[i]);
    }        
printf("----------\n");  
for(int i = 0;i<4;i++){
	for(int a = 0;a<4;a++){	
		if(birim_deger_listesi[i] == (float)value[a] / (float)weight[a]){	
			if(canta_agirligi + (float)weight[a] < kapaste){
				canta_agirligi = (float)weight[a] + canta_agirligi;
				printf("%.2f %.2f \n",(float)weight[a],(float)value[a]);
			}
			else if(canta_agirligi < kapaste){
				float kalan = kapaste - canta_agirligi;				
				if(kalan < (float)weight[a]){
					printf("%.2f %.2f \n",kalan,kalan*birim_deger_listesi[i]);
					goto label;
				}
				
				
			}
			
		}
		
		
		
		}

}      
label:
	printf("son")   ;
}