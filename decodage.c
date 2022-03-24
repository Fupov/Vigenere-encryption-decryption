#include "requirements.h"

void decodage(FILE *in, FILE *out){

    int longeur=longeurMotPasseVigenere(in);
    char res[longeur];
    FILE *files[longeur];
    for (int i = 0; i < longeur; i++)
    {
        char filename[20];
        sprintf(filename, "decoupage%d.txt", i);
        files[i] = fopen(filename, "w");
    }
    for( int i=0; i<longeur; i++){
        decouperFichier(in,files[i],longeur,i);
        rewind(in);
    }

    for(int i=0; i<longeur;i++){
        fclose(files[i]);
    }

    for(int i=0;i<longeur;i++){
        char filename[25];
        sprintf(filename, "decoupage%d.txt", i);
        files[i] = fopen(filename, "r");
        if(files[i]==NULL){
            printf("erreur\n");
        }
        res[i]=lettreLaPlusFrequente(files[i]);


    }
    for (int i = 0; i < longeur; i++)
    {
        char filename[20];
        sprintf(filename, "decoupage%d.txt", i);
        fclose(files[i]);
        remove(filename);
    }


    int int_mdp[longeur];
    for(int i=0; i<longeur;i++){
        int_mdp[i]=((res[i]-'a')-('e'-'a')+26)%26;
        printf("%c",int_mdp[i]+'a');
    }
    printf("\n");

    printf("\n");


    int compteur=0;
    int decalage;
    char r;
    int e;
    rewind(in);
    e=fscanf(in, "%c", &r);
    while(e!=EOF)
    {
        decalage = int_mdp[compteur%longeur];
        //si les caractere du text est une lettre alphabetique
        if((r>='a' && r<= 'z')||(r>='A' && r<= 'Z'))
        {
            r = (tolower(r)-'a'-decalage+26)%26 + 'a';
            fputc(r,out);
            compteur++;
        }else{
            fputc(r,out);

            //si le fichier de sortie n'exist pas

        }

        e=fscanf(in, "%c", &r);
    }

}