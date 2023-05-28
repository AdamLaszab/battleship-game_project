#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void fun(int pole[],int dlzka){
    int maxi=pole[0];
    int maxi2=pole[0];
    for(int i=0;i<dlzka;i++){
        if(pole[i]>maxi){
            maxi=pole[i];
        }
        if(pole[i]>maxi2 && pole[i]<maxi){
            maxi2=pole[i];
        }
    }
    printf("%d",maxi2);
}

int main() {
  int pole[10]={1,2,3,13,5,6,7,8,9,10};
  int dlzka=10;
  fun(pole,dlzka);


  return 0;
}
