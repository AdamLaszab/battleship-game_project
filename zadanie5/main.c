#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#define MAX_LEN 1000
const char* uprav(char* uprav) {
    char* p;
    p = strchr(uprav, '\n');
    *p = '\0';
    return uprav;
}
struct Position{
    int x;
    int y;
};
struct menu{
    char meno[MAX_LEN];
    int cena;
};
struct Restaurant{
    char name[MAX_LEN];
    struct Position pos;
    struct menu Jedla[20];
    int pocet;
    int chyba;
};
struct Restaurant radenie[20];

int main(int argc, char *argv[]){

    FILE *subor;
    FILE *subor1;
    int x=1,c=0,m=0,chyba=0;
    char riadok[MAX_LEN];
    char riadok1[MAX_LEN];
    char* nazov=argv[optind];
    subor = fopen(nazov,"r");
    while(1){
        if(fgets(riadok,MAX_LEN,subor)!=NULL){
            subor1=fopen(uprav(riadok),"r");
            //test E1
            if(subor1==NULL||riadok[0]=='.'){
                fprintf(stderr,"E1 %s\n",riadok);
            }else{
                //test E2
                x=1;
                m=0;
                while(1) {
                    if (fgets(riadok1, MAX_LEN, subor1) != NULL) {
                        uprav(riadok1);
                        if(riadok1[0]=='\0'){
                            break;
                        }
                        if(x==1){
                            strcpy(radenie[c].name,riadok1);
                        }
                        if(x==2){
                            if(strchr(riadok1,',')==NULL){
                                fprintf(stderr,"E2 %s\n",riadok);
                                chyba++;
                                radenie[c].chyba=1;
                                break;
                            }
                            if(riadok1[0]==',' || riadok1[strlen(riadok1)-1]==','){
                                fprintf(stderr,"E2 %s\n",riadok);
                                chyba++;
                                radenie[c].chyba=1;
                                break;
                            }
                            char* prve = strtok(riadok1,",");
                            char* druhe = strtok(NULL,",");
                            int flag=0;
                            for(int i=0;prve[i]!= '\0';i++){
                                if(isdigit(prve[i])==0){
                                    fprintf(stderr,"E2 %s\n",riadok);
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==1){
                                chyba++;
                                radenie[c].chyba=1;
                                break;
                            }
                            flag=0;
                            for(int i=0;druhe[i]!= '\0';i++){
                                if(isdigit(druhe[i])==0){
                                    fprintf(stderr,"E2 %s\n",riadok);
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==1){
                                chyba++;
                                radenie[c].chyba=1;
                                break;
                            }
                            radenie[c].pos.x = strtol(prve,NULL,10);
                            radenie[c].pos.y = strtol(druhe,NULL,10);
                        }
                        if(x>2){
                            if(strchr(riadok1,',')==NULL){
                                fprintf(stderr,"E2 %s\n",riadok);
                                chyba++;
                                radenie[c].chyba=1;
                                break;
                            }
                            if(riadok1[0]==',' || riadok1[strlen(riadok1)-1]==','){
                                fprintf(stderr,"E2 %s\n",riadok);
                                chyba++;
                                radenie[c].chyba=1;
                                break;
                            }
                            char* prve = strtok(riadok1,",");
                            char* druhe = strtok(NULL,",");
                            int flag=0;
                            for(int i=0;druhe[i]!= '\0';i++){
                                if(isdigit(druhe[i])==0){
                                    fprintf(stderr,"E2 %s\n",riadok);
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==1){
                                chyba++;
                                radenie[c].chyba=1;
                                break;
                            }
                            strcpy(radenie[c].Jedla[m].meno,prve);
                            radenie[c].Jedla[m].cena= strtol(druhe,NULL,10);
                            m++;
                        }
                        x++;

                    } else {
                        fclose((subor1));
                        break;
                    }
                }
                radenie[c].pocet=m;
                c++;
            }


            fclose((subor1));
        }else{
            break;
        }

    }
    printf("{\n");
    printf("\"Restaurants\":\n");
    printf("[\n");
    int dobre=0;
    for(int k=0;k<c;k++){
        if(radenie[k].chyba==0){
            printf("{\n");
            printf("\"Name\": \"%s\",\n", radenie[k].name);
            printf("\"Position\":\n");
            printf("{\n");
            printf("\"X\": %d,\n", radenie[k].pos.x);
            printf("\"Y\": %d\n", radenie[k].pos.y);
            printf("},\n");
            printf("\"Menu\":\n");
            printf("[\n");
            for(int z=0;z<radenie[k].pocet;z++){
                printf("{\n");
                printf("\"Name\": \"%s\",\n", radenie[k].Jedla[z].meno);
                printf("\"Price\": %d\n", radenie[k].Jedla[z].cena);
                if(z==radenie[k].pocet-1){
                    printf("}\n");
                }else{
                    printf("},\n");
                }
            }
            dobre++;
            printf("]\n");
            if(dobre==c-chyba){
                printf("}\n");
            }else{
                printf("},\n");
            }
        }

    }
    printf("]\n");
    printf("}\n");
    fclose(subor);

    return 0;
}