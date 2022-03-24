#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char*argv[]){

    FILE *in=NULL;
    FILE *out=NULL;
	int e;
    char r;

    in = fopen(argv[1], "r");
    //si le fichier dentree n'exist pas
    if( in == NULL )
    {
		fprintf(stderr, "Erreur : fichier d'entree introuvable dans le repertoire courant\n");
        //Exit programme
        return EXIT_FAILURE;
    }

    out = fopen(argv[3], "w");
    //si le fichier de sortie n'exist pas
    if( out == NULL )
    {
		fprintf(stderr, "Erreur : fichier de sortie introuvable dans le repertoire courant\n");
        //Exit programme
        return EXIT_FAILURE;
    }
    char *string = argv[2];
    int mdp[strlen(argv[2])];
    for (int i =0; i<strlen(argv[2]);i++) {
        if(string[i]>='a' && string[i]<='z'){
            mdp[i]=string[i]-'a'+1;
        }
        if(string[i]>='A' && string[i]<='Z'){
            mdp[i]=string[i]-'A'+1;
        }
        
    }
    for(int i =0;i<strlen(string);i++){
        printf("%d",mdp[i]);

    }
    printf("\n");

    e=fscanf(in, "%c", &r);

    int compteur=0;
    while(e!=EOF)
    	{
			
        	//si les caractere du text est une lettre alphabetique
        	if((r>='a' && r<= 'z')|| (r>='A' && r<= 'Z'))
        	{
                r = (r-'a'+mdp[compteur]+26)%26 + 'a';
        	    fputc(r,out);
                compteur++;
                if(compteur >= strlen(string))
                    compteur=0;
        	}else{
				// sinon si c'est un caractere special
				
	    		fputc(r,out);
        	}
        e=fscanf(in, "%c", &r);
	    }

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;

}