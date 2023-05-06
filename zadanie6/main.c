#include <stdio.h>
#include <stdlib.h>
const int K = 10;
void reset() {
    printf("\033[0m");
}
void white(){
    printf("\033[97m");
}
void red() {
    printf("\033[31m");
}
void yellow(){
    printf("\033[33m");
}
void green() {
    printf("\033[32m");
}

void blue() {
    printf("\033[34m");
}

void naplnPlochu(int hraciaPlocha[K][K]){
    for (int i = 0; i < K; i++){
        for (int j = 0;j < K;j++){
            hraciaPlocha[i][j]=0;
        }
    }
}
void tlacPlochu(int hraciaPlocha[K][K],int hraciaPlochaProtivnik[K][K],int stav[5],int stav1[5]){
    white();
    printf("[ ]");
    for(int i=1;i<=10;i++){
        white();
        printf("[%d]",i);
    }
    printf("\t\t\t\t");
    printf("[ ]");
    for(int i=1;i<=10;i++){
        white();
        printf("[%d]",i);
    }
    printf("\n");
    for(int j=0;j<10;j++){
        white();
        printf("[%c]",'A'+j);
        for(int z=0;z<10;z++){
            if(hraciaPlocha[j][z]==0){
                blue();
                printf("[~]");
            }
            if(hraciaPlocha[j][z]==1){
                green();
                printf("[0]");
            }
            if(hraciaPlocha[j][z]==2){
                red();
                printf("[*]");
            }
            if(hraciaPlocha[j][z]==3){
                yellow();
                printf("[~]");
            }
        }
        if(j==0){
            white();
            printf("Indicator:\t\t");
        }
        else if(j==1){
            if(stav[0]==0){
                red();
            }else{
                green();
            }
            printf("Carrier:[5]\t");
        }
        else if(j==2){
            if(stav[1]==0){
                red();
            }else{
                green();
            }
            printf("Battleship:[4]\t");
        }
        else if(j==3){
            if(stav[2]==0){
                red();
            }else{
                green();
            }
            printf("Destroyer:[3]\t");
        }
        else if(j==4){
            if(stav[3]==0){
                red();
            }else{
                green();
            }
            printf("Submarine:[3]\t");
        }
        else if(j==5){
            if(stav[4]==0){
                red();
            }else{
                green();
            }
            printf("PatrolBoat:[2]\t");
        }else{
            printf("\t\t\t\t");
        }
        white();
        printf("[%c]",'A'+j);
        for(int z=0;z<10;z++){
            if(hraciaPlochaProtivnik[j][z]==0){
                blue();
                printf("[~]");
            }
            if(hraciaPlochaProtivnik[j][z]==1){
                green();
                printf("[0]");
            }
            if(hraciaPlochaProtivnik[j][z]==2){
                red();
                printf("[*]");
            }
        }
        if(j==0){
            white();
            printf("Indicator:\t\t");
        }
        else if(j==1){
            if(stav1[0]==0){
                red();
            }else{
                green();
            }
            printf("Carrier:[5]\t");
        }
        else if(j==2){
            if(stav1[1]==0){
                red();
            }else{
                green();
            }
            printf("Battleship:[4]\t");
        }
        else if(j==3){
            if(stav1[2]==0){
                red();
            }else{
                green();
            }
            printf("Destroyer:[3]\t");
        }
        else if(j==4){
            if(stav1[3]==0){
                red();
            }else{
                green();
            }
            printf("Submarine:[3]\t");
        }
        else if(j==5){
            if(stav1[4]==0){
                red();
            }else{
                green();
            }
            printf("PatrolBoat:[2]\t");
        }else{
            printf("\t\t\t\t");
        }
        printf("\n");
    }
}
int zadajLod(int hraciaPlocha[K][K],int velkost,int* lode[17],int priebeh){
    char pismeno;
    int stlpec;
    char orientacia;
    int rad = pismeno-65;
    stlpec=stlpec-1;
    if(orientacia=='r'){
        if((stlpec-1)+velkost>=K){
            return 0;
        }
        for(int i=0;i<velkost;i++){
            if(hraciaPlocha[rad][stlpec+i]==1){
                return 0;
            }
        }
        for(int i=0;i<velkost;i++){
            hraciaPlocha[rad][(stlpec)+i]=1;
            lode[priebeh+i]=&hraciaPlocha[rad][(stlpec)+i];
        }
    }
    if(orientacia=='v'){
        if((rad-1)+velkost>=K){
            return 0;
        }
        for(int i=0;i<velkost;i++){
            if(hraciaPlocha[(rad)+i][(stlpec)]==1){
                return 0;
            }
        }
        for(int i=0;i<velkost;i++){
            hraciaPlocha[rad+i][stlpec]=1;
            lode[priebeh+i]=&hraciaPlocha[rad+i][(stlpec)];
        }
    }
    priebeh+=velkost;
    return priebeh;
}
void stavLodi(int* lode[17],int stavy[5]){
    int flag=0;
    for(int i=0;i<5;i++){
        if(*lode[i]==1){
            flag=1;
        }
    }
    stavy[0]=flag;
    flag=0;
    for(int i=5;i<9;i++){
        if(*lode[i]==1){
            flag=1;
        }
    }
    stavy[1]=flag;
    flag=0;
    for(int i=9;i<12;i++){
        if(*lode[i]==1){
            flag=1;
        }
    }
    stavy[2]=flag;
    flag=0;
    for(int i=12;i<15;i++){
        if(*lode[i]==1){
            flag=1;
        }
    }
    stavy[3]=flag;
    flag=0;
    for(int i=15;i<17;i++){
        if(*lode[i]==1){
            flag=1;
        }
    }
    stavy[4]=flag;
    flag=0;

}
int main() {
    int hraciaPlocha[K][K];
    int hraciaPlochaProtivnik[K][K];
    int* lode[17];
    int x=0;
    int priebeh=0;
    int stavy[]={1,1,1,1,1};
    int stavy1[]={1,1,1,1,1};
    naplnPlochu(hraciaPlocha);
    naplnPlochu(hraciaPlochaProtivnik);
    while(x<2) {
        if(x==0) {
            tlacPlochu(hraciaPlocha, hraciaPlochaProtivnik, stavy, stavy1);
            priebeh = zadajLod(hraciaPlocha, 5, 'A', 3, 'v', lode, priebeh);
            priebeh = zadajLod(hraciaPlocha, 4, 'A', 4, 'v', lode, priebeh);
            priebeh = zadajLod(hraciaPlocha, 3, 'A', 5, 'v', lode, priebeh);
            priebeh = zadajLod(hraciaPlocha, 3, 'A', 6, 'v', lode, priebeh);
            priebeh = zadajLod(hraciaPlocha, 2, 'A', 7, 'v', lode, priebeh);
        }

        x++;
    }

    return 0;
}
