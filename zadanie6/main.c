#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int K = 10;

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
            if(hraciaPlocha[j][z]%2!=0 && hraciaPlocha[j][z]>2 ){
                red();
                printf("[*]");
            }
            if(hraciaPlocha[j][z]%2==0 && hraciaPlocha[j][z]>=2){
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
                blue();
                printf("[~]");
            }
            if(hraciaPlochaProtivnik[j][z]%2!=0 && hraciaPlochaProtivnik[j][z]>2 ){
                red();
                printf("[*]");
            }
            if(hraciaPlochaProtivnik[j][z]%2==0 && hraciaPlochaProtivnik[j][z]>=2){
                yellow();
                printf("[~]");
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
    char riadok[100];
    char pismeno;
    int stlpec;
    char orientacia;
    scanf("%s",riadok);
    pismeno=riadok[0];
    orientacia=riadok[2];
    if(strlen(riadok)==3){
        stlpec = atoi(&riadok[1]);
    }else if(strlen(riadok)==4 && atoi(&riadok[1])==10 && atoi(&riadok[2])==0){
        stlpec=10;
        orientacia=riadok[3];
    }else{
        printf("1:%d\n",atoi(&riadok[1]));
        printf("2:%d\n",atoi(&riadok[2]));
        printf("Zly format skus znova.\n");
        return 0;
    }
    if(pismeno>74){
        printf("Prve pismeno nesedi\n");
        return 0;
    }
    if(pismeno<65){
        printf("Prve pismeno nesedi\n");
        return 0;
    }
    if(stlpec>10){
        printf("Cislo nesedi\n");
        return 0;
    }
    if(stlpec<0){
        printf("Cislo nesedi\n");
        return 0;
    }
    if(orientacia!='r' && orientacia!='v'){
        printf("Chybna orientacia\n");
        return 0;
    }


    int rad = pismeno-65;
    stlpec=stlpec-1;
    if(orientacia=='r'){
        if((stlpec-1)+velkost>=K){
            printf("Lod konci mimo hracej plochy\n");
            return 0;
        }
        for(int i=0;i<velkost;i++){
            if(hraciaPlocha[rad][stlpec+i]==1){
                printf("Lod sa prekryva s inou lodou\n");
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
            printf("Lod konci mimo hracej plochy\n");
            return 0;
        }
        for(int i=0;i<velkost;i++){
            if(hraciaPlocha[(rad)+i][(stlpec)]==1){
                printf("Lod sa prekryva s inou lodou\n");
                return 0;
            }
        }
        for(int i=0;i<velkost;i++){
            hraciaPlocha[rad+i][stlpec]=1;
            lode[priebeh+i]=&hraciaPlocha[rad+i][(stlpec)];
        }
    }
    priebeh=velkost;
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
int zautoc(int hraciaPlocha[K][K]){
    char riadok[100];
    char pismeno;
    int stlpec;
    scanf("%s",riadok);
    pismeno=riadok[0];
    if(strlen(riadok)==2){
        stlpec = atoi(&riadok[1]);
    }else if(strlen(riadok)==3 && atoi(&riadok[1])==10 && atoi(&riadok[2])==0){
        stlpec=10;
    }else{
        printf("1:%d\n",atoi(&riadok[1]));
        printf("2:%d\n",atoi(&riadok[2]));
        printf("Zly format skus znova.\n");
        return 0;
    }
    if(pismeno>74){
        printf("Prve pismeno nesedi\n");
        return 0;
    }
    if(pismeno<65){
        printf("Prve pismeno nesedi\n");
        return 0;
    }
    if(stlpec>10){
        printf("Cislo nesedi\n");
        return 0;
    }
    if(stlpec<1){
        printf("Cislo nesedi\n");
        return 0;
    }
    int rad = pismeno-65;
    stlpec=stlpec-1;
    hraciaPlocha[rad][stlpec]+=2;
    return 1;
}
int main() {
    int hraciaPlocha[K][K];
    int hraciaPlochaProtivnik[K][K];
    int* lode[17];
    int* lodeProtivnik[17];
    int x=0;
    int priebeh=0;
    int utok=0;
    int flag=1;
    int stavy[]={1,1,1,1,1};
    int stavyProtivnik[]={1,1,1,1,1};
    naplnPlochu(hraciaPlocha);
    naplnPlochu(hraciaPlochaProtivnik);
    while(1) {
        if(x==0) {
            tlacPlochu(hraciaPlocha, hraciaPlochaProtivnik, stavy, stavyProtivnik);
            while(priebeh==0) {
                priebeh += zadajLod(hraciaPlocha, 5, lode, priebeh);
            }
            while(priebeh==5) {
                priebeh += zadajLod(hraciaPlocha, 4, lode, priebeh);
            }
            while(priebeh==9) {
                priebeh += zadajLod(hraciaPlocha, 3, lode, priebeh);
            }
            while(priebeh==12) {
                priebeh += zadajLod(hraciaPlocha, 3, lode, priebeh);
            }
            while(priebeh==15) {
                priebeh += zadajLod(hraciaPlocha, 2, lode, priebeh);
            }
            priebeh=0;
            tlacPlochu(hraciaPlochaProtivnik, hraciaPlocha, stavyProtivnik, stavy);
            while(priebeh==0) {
                priebeh += zadajLod(hraciaPlochaProtivnik, 5, lodeProtivnik, priebeh);
            }
            while(priebeh==5) {
                priebeh += zadajLod(hraciaPlochaProtivnik, 4, lodeProtivnik, priebeh);
            }
            while(priebeh==9) {
                priebeh += zadajLod(hraciaPlochaProtivnik, 3, lodeProtivnik, priebeh);
            }
            while(priebeh==12) {
                priebeh += zadajLod(hraciaPlochaProtivnik, 3, lodeProtivnik, priebeh);
            }
            while(priebeh==15) {
                priebeh += zadajLod(hraciaPlochaProtivnik, 2, lodeProtivnik, priebeh);
            }

        }
        if(x>0){
            printf("Hrac 1:\n");
            stavLodi(lode,stavy);
            stavLodi(lodeProtivnik,stavyProtivnik);
            tlacPlochu(hraciaPlocha, hraciaPlochaProtivnik, stavy, stavyProtivnik);
            while(utok==0) {
                utok=zautoc(hraciaPlochaProtivnik);
            }
            stavLodi(lodeProtivnik,stavyProtivnik);
            for(int i=0;i<5;i++){
                flag=1;
                if(stavyProtivnik[i]==1){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                printf("Vyhral hrac 1\n");
                tlacPlochu(hraciaPlocha, hraciaPlochaProtivnik, stavy, stavyProtivnik);
                return 0;
            }
            utok=0;
            printf("Hrac 2:\n");
            stavLodi(lode,stavy);
            stavLodi(lodeProtivnik,stavyProtivnik);
            tlacPlochu(hraciaPlochaProtivnik, hraciaPlocha, stavyProtivnik, stavy);
            while(utok==0) {
                utok=zautoc(hraciaPlocha);
            }
            stavLodi(lode,stavy);
            for(int i=0;i<5;i++){
                flag=1;
                if(stavy[i]==1){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                printf("Vyhral hrac 2\n");
                tlacPlochu(hraciaPlochaProtivnik, hraciaPlocha, stavyProtivnik, stavy);
                return 0;
            }
            utok=0;
        }

        x++;
    }

    return 0;
}
