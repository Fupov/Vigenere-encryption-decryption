//
// Created by tchic on 22/03/2022.
//

#ifndef DECODAGEVIGENERE_REQUIREMENTS_H
#define DECODAGEVIGENERE_REQUIREMENTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
void normaliserFichier(FILE * in, FILE *out){
    int e; char r;
    e=fscanf(in, "%c", &r);
    while(e!=EOF)
    {
        //si les caractere du text est une lettre alphabetique
        if((r>='a' && r<= 'z')|| (r>='A' && r<= 'Z'))
        {
            fputc(tolower(r),out);
        }
        e=fscanf(in, "%c", &r);
    }

}
void decouperFichier(FILE * in, FILE *out, int longueur, int debut){
    int e,compteur=0; char r;
    e=fscanf(in, "%c", &r);
    while(compteur<debut)
    {
        if(((r>='a' && r<= 'z')||(r>='A' && r<= 'Z')))
        {

            compteur++;

        }
        e=fscanf(in, "%c", &r);
    }

    compteur=0;
    while(e!=EOF)
    {

        //si les caractere du text est une lettre alphabetique
        if(((r>='a' && r<= 'z')||(r>='A' && r<= 'Z')))
        {
            if(compteur==0){
                fputc(tolower(r),out);
            }
            compteur++;
            if(compteur>=longueur){
                compteur=0;
            }
        }

        e=fscanf(in, "%c", &r);
    }

}
char prochaineLettre(FILE* in)
{
    int e;
    char r;

    e=fscanf(in,"%c",&r);
    while(e!=EOF){

        if((r>='a' && r<='z')||(r>='A' && r<='Z')){
            return r;
        }
        e=fscanf(in,"%c",&r);
    }
    return EOF;
}
char lettreLaPlusFrequente(FILE* in)
{
    int max=0;
    int T[26]={0};
    int i;
    char r;
    r=prochaineLettre(in);
    while(r!=EOF){

        //       printf("%d\n",r);
        if(r>='a' && r<='z'){
            T[r-'a']++;
        }
        if(r>='A' && r<='Z'){
            T[r-'A']++;
        }
        r=prochaineLettre(in);
    }

    for(i=0;i<26;i++){
        //printf("%d,",T[i]);
        if(T[i]>T[max]){
            max=i;
        }
    }
    return 'a'+max;
}


double IndiceCoincidence(FILE *in){
    int T[26]={0};


    double Sum=0;
    char r;
    double total=0;
    do{
        r=prochaineLettre(in);
        if(r>='a' && r<='z'){
            T[r-'a']++;
            total++;
        }
        if(r>='A' && r<='Z'){
            T[r-'A']++;
            total++;
        }
    }while(r!=EOF);

    //printf("\n");
    for(int i=0;i<26;i++){
        Sum=Sum+(T[i]*(T[i]-1));
    }
    double res=(Sum/(total*(total-1)));
    //printf("%f\n",res);
    return res;

}

int longeurMotPasseVigenere(FILE * in){
    bool cond=true;
    int i=0;
    int res=0;
    FILE *out=NULL;

    while(cond==true)
    {
        out = fopen("out.txt", "w");
        //si le fichier de sortie n'exist pas
        if( out == NULL )
        {
            fprintf(stderr, "Erreur : fichier de sortie introuvable dans le repertoire courant\n");
            //Exit programme
            return EXIT_FAILURE;
        }

        decouperFichier(in,out,i,0);
        rewind(in);
        fclose(out);
        out = fopen("out.txt", "r");
        if((IndiceCoincidence(out)>=0.061)) {
            res=i;
            cond=false;
        }
        i++;
        fclose(out);
        remove("out.txt");
    }
    printf("%d\n",res);
    return res;

}

#endif //DECODAGEVIGENERE_REQUIREMENTS_H
