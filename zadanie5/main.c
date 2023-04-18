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

int main(int argc, char *argv[]){
    FILE *subor;
    FILE *subor1;
    int x=1;
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
                    while(1) {
                        if (fgets(riadok1, MAX_LEN, subor1) != NULL) {
                            uprav(riadok1);
                            if(riadok1[0]=='\0'){
                                break;
                            }
                            if(x==2){
                                if(strchr(riadok1,',')==NULL){
                                    fprintf(stderr,"E2 %s\n",riadok);
                                    break;
                                }
                                if(riadok1[0]==',' || riadok1[strlen(riadok1)-1]==','){
                                    fprintf(stderr,"E2 %s\n",riadok);
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
                                    break;
                                }

                            }
                            if(x>2){
                                if(strchr(riadok1,',')==NULL){
                                    fprintf(stderr,"E2 %s\n",riadok);
                                    break;
                                }
                                if(riadok1[0]==',' || riadok1[strlen(riadok1)-1]==','){
                                    fprintf(stderr,"E2 %s\n",riadok);
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
                                    break;
                                }

                            }
                            x++;
                        } else {
                            fclose((subor1));
                            break;
                        }
                    }
                }

            fclose((subor1));
        }else{
            break;
        }


    }
    fclose(subor);
    return 0;
}
