
#include "requirements.h"
#include "decodage.c"
int main(int argc, char*argv[]){

    FILE *in=NULL;
    FILE *out=NULL;
	

    in = fopen(argv[1], "r");
    //si le fichier dentree n'exist pas
    if( in == NULL )
    {
		fprintf(stderr, "Erreur : fichier d'entree introuvable dans le repertoire courant\n");
        //Exit programme
        return EXIT_FAILURE;
    }

    out = fopen(argv[2], "w");
    //si le fichier de sortie n'exist pas
    if( out == NULL )
    {
		fprintf(stderr, "Erreur : fichier de sortie introuvable dans le repertoire courant\n");
        //Exit programme
        return EXIT_FAILURE;
    }
    decodage(in,out);
    printf("\n");
    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;

}