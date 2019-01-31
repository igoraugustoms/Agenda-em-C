#include "stdio.h"
#include "stdlib.h"
//Desafio 3 Igor Augusto - RA 0050481811024 - ADS Manhã 2 ciclo

struct dados{
    char nome[50];
    char endereco[100];
    char cidade[50];
    char estado[3];
    char cep[15];

};
struct dados usuario;
int contador;
FILE *p;


int menu(){
    int opcao;
    do{
        printf("\tMenu\n");
        printf("(1) Entrada de dados\n");
        printf("(2) Listar dados\n");
        printf("(3) Pesquisar dados por nome\n");
        printf("(4) Alterar dados\n");
        printf("(5) Excluir dados\n");
        printf("(6) Sair\n\n");
        scanf("%d", &opcao);
    }while((opcao < 1) || (opcao > 6));
    return opcao;

}

entradaDados(){
    printf("Vamos para a entrada de dados\n");
    if((p = fopen("contatosigor.txt","a"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    printf("Digite o nome\n");
    fflush(stdin);
    gets(usuario.nome);

    printf("Digite o endereco\n");
    gets(usuario.endereco);

    printf("Digite a cidade\n");
    gets(usuario.cidade);

    printf("Digite o estado\n");
    gets(usuario.estado);

    printf("Digite o CEP\n");
    gets(usuario.cep);

    fwrite(&usuario, sizeof(usuario), 1, p);

    fclose(p);
}

listaDados(){
    int x = 0;
    int cont_pesq = 0;
    if((p = fopen("contatosigor.txt","r"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    for(x = 0; x < contador; x++){
        fread(&usuario,sizeof(usuario),1,p);

        if(usuario.nome[0] != '*'){
            printf("Nome: %s\n", usuario.nome);
            printf("Endereco: %s\n", usuario.endereco);
            printf("Cidade: %s\n", usuario.cidade);
            printf("Estado: %s\n", usuario.estado);
            printf("CEP: %s\n\n\n", usuario.cep);
            cont_pesq++;

        }

    }
    if(cont_pesq == 0){
        printf("Nao ha registros a serem exibidos\n");
    }
}

pesquisaDados(){
    int tamanho1 = 0, tamanho2 = 0, y = 0;
    char nomePesquisa[50];
    int r = 0;
    getchar();
    printf("Digite o nome a ser pesquisado\n");
    gets(nomePesquisa);
    if((p = fopen("contatosigor.txt","r"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    for(r = 0; r < contador; r++){
        fread(&usuario, sizeof(usuario), 1, p);
        for(tamanho1 = 0; tamanho1 < 50; tamanho1++){
            if(nomePesquisa[tamanho1] == '\0'){
                break;
            }
        }

        for(tamanho2 = 0; tamanho2 < 50; tamanho2++){

            if(usuario.nome[tamanho2] == '\0'){
                break;
            }
        }
        if(tamanho1 == tamanho2){

            for(y = 0; y < tamanho1; y++){
                if(nomePesquisa[y] != usuario.nome[y]){
                    break;
                }
            }
            if(y == tamanho1){
                printf("Nome: %s\n", usuario.nome);
                printf("Endereco: %s\n", usuario.endereco);
                printf("Cidade: %s\n", usuario.cidade);
                printf("Estado: %s\n", usuario.estado);
                printf("CEP: %s\n\n\n", usuario.cep);
                r + 1;
                break;
            }
        }
    }
    if(r == contador){
        printf("Nao ha esse nome no registro\n");
    }
}

alteraDados(){
    int tamanho1 = 0, tamanho2 = 0, y = 0;
    char nomePesquisa[50];
    int r = 0;
    getchar();
    printf("Digite o nome a ser alterado\n");
    gets(nomePesquisa);
    if((p = fopen("contatosigor.txt","r+"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    for(r = 0; r < contador; r++){
        fread(&usuario, sizeof(usuario), 1, p);
        for(tamanho1 = 0; tamanho1 < 50; tamanho1++){
            if(nomePesquisa[tamanho1] == '\0'){
                break;
            }
        }

        for(tamanho2 = 0; tamanho2 < 50; tamanho2++){

            if(usuario.nome[tamanho2] == '\0'){
                break;
            }
        }
        if(tamanho1 == tamanho2){

            for(y = 0; y < tamanho1; y++){
                if(nomePesquisa[y] != usuario.nome[y]){
                    break;
                }
            }
            if(y == tamanho1){
                fseek(p, r * sizeof(usuario), 0);
                printf("Vamos para a entrada de dados\n");
                printf("Digite o nome\n");
                gets(usuario.nome);

                printf("Digite o endereco\n");
                gets(usuario.endereco);

                printf("Digite a cidade\n");
                gets(usuario.cidade);

                printf("Digite o estado\n");
                gets(usuario.estado);

                printf("Digite o CEP\n");
                gets(usuario.cep);

                fwrite(&usuario, sizeof(usuario), 1, p);
                fclose(p);

                r + 1;
                break;
            }
        }
    }
    if(r == contador){
        printf("Nao ha esse nome no registro\n");
    }
}

apagaDados(){
    int tamanho1 = 0, tamanho2 = 0, y = 0;
    char nomePesquisa[50];
    int r = 0;
    getchar();
    printf("Digite o nome a ser excluido\n");
    gets(nomePesquisa);
    if((p = fopen("contatosigor.txt","r+"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    for(r = 0; r < contador; r++){
        fread(&usuario, sizeof(usuario), 1, p);
        for(tamanho1 = 0; tamanho1 < 50; tamanho1++){
            if(nomePesquisa[tamanho1] == '\0'){
                break;
            }
        }

        for(tamanho2 = 0; tamanho2 < 50; tamanho2++){

            if(usuario.nome[tamanho2] == '\0'){
                break;
            }
        }
        if(tamanho1 == tamanho2){

            for(y = 0; y < tamanho1; y++){
                if(nomePesquisa[y] != usuario.nome[y]){
                    break;
                }
            }
            if(y == tamanho1){
                fseek(p, r * sizeof(usuario), 0);
                printf("Excluindo dado...\n");
                system("pause");

                usuario.nome[0] = '*';
                fwrite(&usuario, sizeof(usuario), 1, p);
                fclose(p);

                r + 1;
                break;
            }
        }
    }
    if(r == contador){
        printf("Nao ha esse nome no registro\n");
    }

}


main(){
    bool sair = false;
    int menuVar;


    char alteraNome[50];
    bool mudarDado = false;
    if((p = fopen("contadorigor.txt","r"))==NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
	}

	fscanf(p, "%d", &contador);

    for( ; ; ){

        menuVar = menu();
        switch(menuVar){
            case 1:
                entradaDados();
                contador++;
                break;
            case 2:
                listaDados();
                break;
            case 3:
                pesquisaDados();
                break;
            case 4:
                alteraDados();
                break;

            case 5:
                apagaDados();
                break;
            case 6:
                printf("Voce escolheu sair\n");

                sair = true;
        }
        if((p = fopen("contadorigor.txt","w"))==NULL){
            printf("erro na abertura do arquivo \n");
            exit(0);
        }
        fprintf(p, "%d", contador);
       fclose(p);
       if(sair){
            break;
       }
    }
}
