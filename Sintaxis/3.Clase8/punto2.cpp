int titulo_valido(char *titulo){
    int resultado = 1;
    
    while (*titulo) {
        char c = *titulo; //Según tabla ASCII
        if (!(titulo >= 65 and titulo <= 90) or (titulo >= 97 and titulo <= 122) or (titulo >= 40 and titulo <= 63) or (titulo >= 32 and titulo <= 34)) {
            resultado = 0;
            break;
        }
        titulo++;
    }    

    int longitud = strlen(titulo);

    return longitud > 0 && longitud < 41 && (resultado == 1);
}

void ingresa_valida_titulo(char *titulo){
    do {
        printf("\n Titulo: ");
        getchar();
        gets(titulo);
        if (titulo_valido(titulo)) break;
        printf("\n Titulo no valido \n");
    } while (1); 
}