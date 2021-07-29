//
// Diogo Silva - 38716
// Luis Sousa - 39227
//

#include "IAPG.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_NOME 50 //tamanho maximo de char na string macro
#define TAM_VECTOR 50 //num de clentes que podem ser guardadas na memoria

typedef struct destino{
    int id;
    char pais [TAM_NOME];
    char cidade [TAM_NOME];
    int numero;
}DESTINO;

typedef struct cliente{
    DESTINO destino;
    int id;
    char nome[TAM_NOME];
    int numero;
    char genero[TAM_NOME];
    int idade;
    char nacionalidade[TAM_NOME];
}CLIENTE;

typedef struct alojamentos{
    DESTINO destino;
    int id;
    char categoria [TAM_NOME];
    int preco;
    char caracteristicas [TAM_NOME];
    int numero;
    int classificacao;
}ALOJAMENTOS;


int cliente_num =0; // variavel que guarda numero de clientes
int destino_num =0; // variavel que guarda numero de destinos
int alojamentos_num =0; // variavel que guarda numero de alojamentos

struct cliente vec_cliente[TAM_VECTOR]; // inicializa se um vetor de clientes das estrutura acima criada
struct destino vec_destino[TAM_VECTOR];
struct alojamentos vec_alojamentos[TAM_VECTOR];

int mainProjeto()
{
    menu();
    return 0;
}

void menu()
{
    int n;
    do {
        printf("\t\t MENU PROJETO\n\n");
        printf("Escolha uma das Opcoes Seguintes:\n");
        printf("1 - Destino\n");
        printf("2 - Clientes\n");
        printf("3 - Alojamento\n");
        printf("4 - Pesquisa\n");
        printf("5 - Viagens\n");
        printf("0 - Sair\n");
        scanf("%d", &n);
        fflush(stdin);
        switch (n) {
            case 1:
                menuDestino();
                break;
            case 2:
                menuCliente();
                break;
            case 3:
                menuAlojamento();
                break;
            case 4:
                menuProcurar();
                break;
            case 5:
                menuViagens();
                break;
            case 0:
                exit(EXIT_SUCCESS);
            default:
                printf("Opcao Invalida\n");
        }
        if (n!=0){
            printf("\nPrima qualquer tecla para voltar ao menu\n");
            getchar();
        }
    }
    while (n!=0);
}

///CLIENTES

void menuCliente() { //menu cliente
    int n;
    do {
        printf("\nEscolha uma Opcao:\n");
        printf("1 - Adicionar Cliente\n");
        printf("2 - Editar Informacao Cliente\n");
        printf("3 - Remover Cliente\n");
        printf("4 - Listar Cliente\n");
        printf("5 - Gravar Para Ficheiro\n");
        printf("6 - Carregar Do Ficheiro\n");
        printf("0 - Sair\n");
        scanf("%d", &n);
        fflush(stdin);
        switch (n) {
            case 1 :
                printf("\nInserir Cliente\n");
                InserirCliente();
                break;
            case 2 :
                printf("\nEditar Informacao Cliente\n");
                EditarCliente();
                break;
            case 3 :
                printf("\nRemover Cliente\n");
                RemoverCliente();
                break;
            case 4:
                printf("\nListar Cliente\n");
                ListaCliente();
                break;
            case 5:
                printf("\nGravar Para Ficheiro\n");
                ClienteParaFicheiro();
                printf("Parabens, guardou os clientes com sucesso!\n");
                break;
            case 6:
                printf("\nCarregar Do Ficheiro\n");
                ClienteDoFicheiro();
                printf("Parabens, carregou os clientes com sucesso!\n");
                break;
            case 0 :
                menu();
                break;
            default:
                printf("Opcao Invalida\n");
        }
        if (n != 0) {
            printf("\nPrima qualquer tecla para voltar ao menu\n");
            getchar();
        }
    }
    while (n != 0);
}
/**
 * Insere manualmente os clientes
 * usando o vec_cliente e o cliente_num
 */
void InserirCliente() { //introduz informacao acerca dos clientes
    printf("Nome do Cliente:\n");
    gets(vec_cliente[cliente_num].nome);
    fflush(stdin);
    printf("Numero do Cliente:\n");
    scanf("%d", &vec_cliente[cliente_num].numero);
    fflush(stdin);
    printf("Genero do Cliente:\n");
    gets(vec_cliente[cliente_num].genero);
    fflush(stdin);
    printf("Idade do Cliente:\n");
    scanf("%d", &vec_cliente[cliente_num].idade);
    fflush(stdin);
    printf("Nacionalidade do Cliente:\n");
    gets(vec_cliente[cliente_num].nacionalidade);
    fflush(stdin);
    vec_cliente[cliente_num].id = cliente_num +1 ; //o id e igual ao numero de viagens + 1
    cliente_num++;
}
/**
 * funcao que edita os clientes
 */
void EditarCliente() {
    if (cliente_num > 0) { // se o numero de clientes for maior que 0 faz
        int aux, op;
        printf("Qual cliente quer alterar? De 1 a %d\n", cliente_num);
        scanf("%d", &op); //é a opcao do utilizador
        op--;
        if (op > -1 && op < cliente_num) {//se a opcao estiver dentro dos parametros
            back: // caso o utilizador introduza um numero invalido
            printf("\nCliente:\n");
            printf("1-Nome\n");
            printf("2-Numero\n");
            printf("3-Genero\n");
            printf("4-Idade\n");
            printf("5-Nacionalidade\n");
            scanf("%d",&aux);
            switch (aux){
                case 1: //editar o nome
                    getchar(); // so le 1 caracter
                    printf("\nNome:\n");
                    gets(vec_cliente[op].nome);
                    menuCliente();
                    break;
                case 2: //editar o numero
                    getchar();
                    printf("\nNumero:\n");
                    scanf("%d",&vec_cliente[op].numero);
                    menuCliente();
                    break;
                case 3: //editar o genero
                    getchar();
                    printf("\nGenero:\n");
                    gets(vec_cliente[op].genero);
                    menuCliente();
                    break;
                case 4: //editar a idade
                    getchar();
                    printf("\nIdade:\n");
                    scanf("%d",&vec_cliente[op].idade);
                    menuCliente();
                    break;
                case 5: //editar a nacionalidade
                    getchar();
                    printf("\nNacionalidade:\n");
                    gets(vec_cliente[op].nacionalidade);
                    menuCliente();
                    break;
                default: //se introduzir um numero invalido
                    printf("Opcao Invalida\n"); //print opcao invalida
                    goto back; // vai para o back e pede ao utilizador para introduzir outra vez
            }
            if (op !=0){
                printf("Prima qualquer tecla para voltar ao menu");
                getchar();
            }
        }
        while (op!=0);
    }else
        printf("Ainda nao tem nenhum Cliente para usar esta opcao\n");
}
/**
 *funcao que remove os clientes
 */
void RemoverCliente(){
    if (cliente_num>0){ //se o num clientes for maior que 0
        int n,j,op;
        printf("Escolha de 1 a %d qual o Cliente que quer remover:\n",cliente_num);
        remov: // volta para aqui se algo der errado
        scanf("%d",&op); //guarda o que o utilizador introduzir
        n=op;
        op--; // o vetor começa no 0 mas no utilizador começa no 1
        if (op>-1 && op<cliente_num){ // opcao esta nas pretendidas
            for ( j=op; j<cliente_num ; j++) { // percorre todos os clientes
                vec_cliente[j].id = vec_cliente[n].id;
                strcpy(vec_cliente[j].nome, vec_cliente[n].nome);     // escolhe se o q se quer remover
                vec_cliente[j].numero = vec_cliente[n].numero;        // pegamos no q estava na posiçao seguinte
                strcpy(vec_cliente[j].genero, vec_cliente[n].genero); // pomos na posicao anterior, desaparece a que escolhemos
                vec_cliente[j].idade = vec_cliente[n].idade;
                strcpy(vec_cliente[j].nacionalidade, vec_cliente[n].nacionalidade);
                n++;
                cliente_num--; //diminui o numero de clientes
            }
        }
        else {
            printf("Opcao Invalida\n");
            goto remov; //vai remov volta a introduzir
        }
    }
}
/**
 * funcao para listar os clientes
 */
void ListaCliente(){
    if (cliente_num>0){   //  se o numero de clientes for maior do que 0 lista os clientes
        for (int j = 0; j < cliente_num ; j++) {
            printf("\nCliente:\n");
            printf("id: %d\n",vec_cliente[j].id);
            printf("Nome: %s\n",vec_cliente[j].nome);
            printf("Numero: %d\n",vec_cliente[j].numero);
            printf("Genero: %s\n",vec_cliente[j].genero);
            printf("Idade: %d\n",vec_cliente[j].idade);
            printf("Nacionalidade: %s\n",vec_cliente[j].nacionalidade);
        }
    } else  // senao for maior do que 0 da print
        printf("Ainda nao tem nenhum cliente\n");
}
/**
 * grava os clientes para ficheiro de texto
 */
void ClienteParaFicheiro(){
    FILE *lerFicheiroTexto;
    lerFicheiroTexto = fopen("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projetoIAPG\\clientes.txt","w"); // abre o ficheiro
    if (lerFicheiroTexto != NULL){ //verifica se o ficheiro existe
        fprintf(lerFicheiroTexto,"%d\n",cliente_num); //guarda o numero de clientes
        for (int i = 0; i <cliente_num ; i++) {
            fprintf(lerFicheiroTexto,"\n%d\n",vec_cliente[i].id); //guarda o id para o ficheiro e depois os outros
            fprintf(lerFicheiroTexto,"%s\n",vec_cliente[i].nome);
            fprintf(lerFicheiroTexto,"%d\n",vec_cliente[i].numero);
            fprintf(lerFicheiroTexto,"%s\n",vec_cliente[i].genero);
            fprintf(lerFicheiroTexto,"%d\n",vec_cliente[i].idade);
            fprintf(lerFicheiroTexto,"%s\n",vec_cliente[i].nacionalidade);
        }
        fprintf(lerFicheiroTexto, "\n");
        fclose(lerFicheiroTexto); //fecha o ficheiro
    }
}
/**
 * carrega os clientes do ficheiro de texto para o programa
 */
void ClienteDoFicheiro(){
    FILE *lerFicheiroTexto;
    lerFicheiroTexto = fopen("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projetoIAPG\\clientes.txt","r");
    char linha[TAM_NOME];
    if (lerFicheiroTexto !=NULL){ //verifica se o ficheiro existe
        fscanf(lerFicheiroTexto, "%d\n", &cliente_num); //le o numero
        fflush(stdin);
        for (int i = 0; i <cliente_num ; i++) { //carrega informacao dos clientes
            fscanf(lerFicheiroTexto, "%d\n", &vec_cliente[i].id); //guarda o id
            fgets(linha, TAM_NOME, lerFicheiroTexto);       //le a linha
            linha[strlen(linha)-1]=0;                       // retira a quebra de linha
            strcpy(vec_cliente[i].nome, &linha[0]);
            fscanf(lerFicheiroTexto,"%d\n",&vec_cliente[i].numero);
            fgets(linha, TAM_NOME, lerFicheiroTexto);
            linha[strlen(linha)-1]=0;
            strcpy(vec_cliente[i].genero, &linha[0]);
            fscanf(lerFicheiroTexto,"%d\n",&vec_cliente[i].idade);
            fgets(linha, TAM_NOME, lerFicheiroTexto);
            linha[strlen(linha)-1]=0;
            strcpy(vec_cliente[i].nacionalidade, &linha[0]);
        }
        fclose(lerFicheiroTexto); //fecha ficheiro
    }
}

/// DESTINOS

void menuDestino() { //menu cliente
    int n;
    do {
        printf("\nEscolha uma Opcao:\n");
        printf("1 - Adicionar Destino\n");
        printf("2 - Editar Informacao Destino\n");
        printf("3 - Remover Destino\n");
        printf("4 - Listar Destinos\n");
        printf("5 - Gravar Para Ficheiro\n");
        printf("6 - Carregar Do Ficheiro\n");
        printf("0 - Sair\n");
        scanf("%d", &n);
        fflush(stdin);
        switch (n) {
            case 1 :
                printf("\nInserir Destino\n");
                InserirDestino();
                break;
            case 2 :
                printf("\nEditar Informacao Destino\n");
                EditarDestino();
                break;
            case 3 :
                printf("\nRemover Destino\n");
                RemoverDestino();
                break;
            case 4:
                printf("\nListar Destinos\n");
                ListaDestinos();
                break;
            case 5:
                printf("\nGravar Para Ficheiro:\n");
                DestinoParaFicheiro();
                printf("Parabens, guardou os destinos com sucesso!\n");
                //menuDestino();
                break;
            case 6:
                printf("\nCarregar Do Ficheiro:\n");
                DestinoDoFicheiro();
                printf("Parabens, carregou os destinos com sucesso!\n");
                break;
            case 0 :
                menu();
                break;
            default:
                printf("Opcao Invalida\n");
        }
        if (n != 0) {
            printf("\nPrima qualquer tecla para voltar ao menu\n");
            getchar();
        }
    } while (n != 0);
}
/**
 * Insere manualmente os destinos
 * usando o vec_destino e o destino_num
 */
void InserirDestino() { //introduz informacao acerca dos destinos
    printf("Insira o Pais:\n");
    gets(vec_destino[destino_num].pais);
    printf("Insira a Cidade:\n");
    gets(vec_destino[destino_num].cidade);
    printf("Numero:\n");
    scanf("%d", &vec_destino[destino_num].numero);
    fflush(stdin);
    vec_destino[destino_num].id = destino_num +1 ; //o id é igual ao numero de destinos + 1

    destino_num++;
}
/**
 * funcao para editar os destinos
 */
void EditarDestino() {
    if (destino_num > 0) { //se num destinos maior que 0
        int aux, op;
        printf("Qual destino quer alterar? De 1 a %d\n", destino_num);
        scanf("%d", &op); //é a opcao do utilizador
        fflush(stdin);
        op--;
        if (op > -1 && op < destino_num) {//verifica se a opcao esta nas pretendidas
            back:
            printf("\nDestino:\n");
            printf("1-Pais\n");
            printf("2-Numero\n");
            printf("3-Cidade\n");
            scanf("%d",&aux); //guarda opcao do utilizador
            switch (aux){
                case 1: //editar o pais
                    getchar();
                    printf("\nPais:\n");
                    gets(vec_destino[op].pais);
                    menuDestino();
                    break;
                case 2: //editar numero
                    getchar();
                    printf("\nNumero:\n");
                    scanf("%d",&vec_destino[op].numero);
                    menuDestino();
                    break;
                case 3: //editar cidade
                    getchar();
                    printf("\nCidade:\n");
                    gets(vec_destino[op].cidade);
                    menuDestino();
                    break;
                default:
                    printf("Opcao Invalida\n");
                    goto back;
            }
            if (op !=0){
                printf("Prima qualquer tecla para voltar ao menu");
                getchar();
            }
        }
        while (op!=0);
    } else
        printf("Ainda nao tem nenhum destino para usar esta opcao\n");
}
/**
 * funcao que remove os destinos
 */
void RemoverDestino(){
    if (destino_num>0){
        int n,j,op;
        remov: // volta para aqui se algo der errado
        printf("Escolha de 1 a %d qual o Destino que quer remover:\n",destino_num);
        fflush(stdin);
        scanf("%d",&op);
        n=op;
        op--; // o vetor começa no 0 mas no utilizador começa no 1
        if (op>-1 && op<destino_num){ // opcao esta nas pretendidas
            for ( j=op; j<destino_num ; j++) { // percorre todos os clientes
                vec_destino[j].id = vec_destino[n].id;
                strcpy(vec_destino[j].pais, vec_destino[n].pais);     // escolhe se o q se quer remover
                vec_destino[j].numero = vec_destino[n].numero;        // pegamos no q estava na posiçao seguinte
                strcpy(vec_destino[j].cidade, vec_destino[n].cidade); // pomos na posicao anterior, desaparece a outra
                n++;
                destino_num--; //diminui o numero de destinos
            }
        }
        else {
            printf("Opcao Invalida\n");
            goto remov;
        }
    }
}
/**
 * funcao para listar os destinos
 */
void ListaDestinos(){
    if (destino_num>0){ //se for maior que 0 lista os destinos
        for (int j = 0; j < destino_num ; j++) {
            printf("\nDestinos:\n");
            printf("id: %d\n",vec_destino[j].id);
            printf("Pais: %s\n",vec_destino[j].pais);
            printf("Numero: %d\n",vec_destino[j].numero);
            printf("Cidade: %s\n",vec_destino[j].cidade);
        }
    } else //senao da print
        printf("Ainda nao tem nenhum destino\n");
}
/**
 * grava os destinos para ficheiro de texto
 */
void DestinoParaFicheiro(){
    FILE *lerFicheiroTexto;
    lerFicheiroTexto = fopen("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projetoIAPG\\destinos.txt","w");
    if (lerFicheiroTexto != NULL){ //verifica se o ficheiro existe
        fprintf(lerFicheiroTexto,"%d\n",destino_num); //guarda o numero de destinos
        for (int i = 0; i <destino_num ; i++) {
            fprintf(lerFicheiroTexto,"\n%d\n",vec_destino[i].id); //guarda para o ficheiro
            fprintf(lerFicheiroTexto,"%s\n",vec_destino[i].pais);
            fprintf(lerFicheiroTexto,"%d\n",vec_destino[i].numero);
            fprintf(lerFicheiroTexto,"%s\n",vec_destino[i].cidade);
        }
        fprintf(lerFicheiroTexto, "\n");
        fclose(lerFicheiroTexto); //fecha o ficheiro
    }
}
/**
 * carrega os destinos do ficheiro de texto para o programa
 */
void DestinoDoFicheiro(){
    FILE *lerFicheiroTexto;
    lerFicheiroTexto = fopen("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projetoIAPG\\destinos.txt","r");
    char linha[TAM_NOME];
    if (lerFicheiroTexto !=NULL){ //verifica se o ficheiro existe
        fscanf(lerFicheiroTexto, "%d\n", &destino_num); //le o numero
        //fflush(stdin);
        for (int i = 0; i <destino_num ; i++) {
            fscanf(lerFicheiroTexto, "%d\n", &vec_destino[i].id);
            fgets(linha, TAM_NOME, lerFicheiroTexto); //le a linha
            linha[strlen(linha)-1]=0;                  // retira a quebta de linha
            strcpy(vec_destino[i].pais, &linha[0]);
            fscanf(lerFicheiroTexto,"%d\n",&vec_destino[i].numero);
            fgets(linha, TAM_NOME, lerFicheiroTexto);
            linha[strlen(linha)-1]=0;
            strcpy(vec_destino[i].cidade, &linha[0]);
        }
        fclose(lerFicheiroTexto);
    }
}

/// ALOJAMENTOS

void menuAlojamento() { //menu alojamento
    int n;
    do {
        printf("\nEscolha uma Opcao:\n");
        printf("1 - Adicionar Alojamento\n");
        printf("2 - Editar Informacao Alojamento\n");
        printf("3 - Remover Alojamento\n");
        printf("4 - Listar Alojamento\n");
        printf("5 - Gravar Para Ficheiro\n");
        printf("6 - Carregar Do Ficheiro\n");
        printf("7 - Categorias\n");
        printf("0 - Sair\n");
        scanf("%d", &n);
        fflush(stdin);
        switch (n) {
            case 1 :
                printf("\nInserir Alojamento\n");
                InserirAlojamento();
                break;
            case 2 :
                printf("\nEditar Informacao Alojamento\n");
                EditarAlojamento();
                break;
            case 3 :
                printf("\nRemover Alojamento\n");
                RemoverAlojamento();
                break;
            case 4:
                printf("\nListar Alojamento\n");
                ListaAlojamento();
                break;
            case 5:
                printf("\nGravar Para Ficheiro:\n");
                AlojamentoParaFicheiro();
                printf("Parabens, guardou os Alojamentos com sucesso!\n");
                break;
            case 6:
                printf("\nCarregar Do Ficheiro:\n");
                AlojamentoDoFicheiro();
                printf("Parabens, carregou os Alojamentos com sucesso!\n");
                break;
            case 7 :
                printf("\nCategorias\n");
                menuCategorias();
                break;
            case 0 :
                menu();
                break;
            default:
                printf("Opcao Invalida\n");
        }
        if (n != 0) {
            printf("\nPrima qualquer tecla para voltar ao menu\n");
            getchar();
        }
    } while (n != 0);
}
/**
 * Insere manualmente os alojamentos
 * usando o vec_alojamentos e o alojamentos_num
 */
void InserirAlojamento() { //introduz informacao acerca dos alojamentos
    printf("Categoria do Alojamento:\n");
    gets(vec_alojamentos[alojamentos_num].categoria);
    printf("Numero do Alojamento:\n");
    scanf("%d", &vec_alojamentos[alojamentos_num].numero);
    fflush(stdin);
    printf("Preco do Alojamento:\n");
    scanf("%d", &vec_alojamentos[alojamentos_num].preco);
    fflush(stdin);
    printf("Caracteristicas do Alojamento:\n");
    gets(vec_alojamentos[destino_num].caracteristicas);
    printf("Classificacao do Alojamento:\n");
    scanf("%d", &vec_alojamentos[alojamentos_num].classificacao);
    fflush(stdin);
    vec_alojamentos[alojamentos_num].id =alojamentos_num +1 ; //o id é igual ao numero de alojamentos + 1

    alojamentos_num++;
}
/**
 * funcao para editar os alojamentos
 */
void EditarAlojamento() {
    if (alojamentos_num > 0) {
        int aux, op;
        printf("Qual Categoria quer alterar? De 1 a %d\n", alojamentos_num);
        scanf("%d", &op); //é a opcao do utilizador
        fflush(stdin);
        op--;
        if (op > -1 && op < alojamentos_num) {//verifica se a opcao esta nas pretendidas
            back:
            printf("\nAlojamentos:\n");
            printf("1-Categoria\n");
            printf("2-Numero\n");
            printf("3-Preco\n");
            printf("4-Caracteristicas\n");
            printf("5-Classificacao\n");
            scanf("%d",&aux);
            switch (aux){
                case 1: //editar a categoria
                    getchar();
                    printf("\nCategoria:\n");
                    gets(vec_alojamentos[op].categoria);
                    menuAlojamento();
                    break;
                case 2: //edita numero
                    getchar();
                    printf("\nNumero:\n");
                    scanf("%d",&vec_alojamentos[op].numero);
                    menuAlojamento();
                    break;
                case 3: //edita preco
                    getchar();
                    printf("\nPreco:\n");
                    scanf("%d",&vec_alojamentos[op].preco);
                    menuAlojamento();
                    break;
                case 4: //edita caracteristicas
                    getchar();
                    printf("\nCaracteristicas:\n");
                    gets(vec_alojamentos[op].caracteristicas);
                    menuAlojamento();
                    break;
                case 5: //edita classificacao do alojamento
                    getchar();
                    printf("\nClassificacao:\n");
                    scanf("%d",&vec_alojamentos[op].classificacao);
                    menuAlojamento();
                    break;
                default:
                    printf("Opcao Invalida\n");
                    goto back;
            }
            if (op !=0){
                printf("Prima qualquer tecla para voltar ao menu");
            }
        }
        while (op!=0);
    }else
        printf("Ainda nao tem nenhum Alojamento para usar esta opcao\n");
}
/**
 * funcao para remover os alojamnetos
 */
void RemoverAlojamento(){
    if (alojamentos_num>0){
        int n,j,op;
        remov: // volta para aqui se algo der errado
        printf("Escolha de 1 a %d qual o Alojamento que quer remover:\n",alojamentos_num);
        fflush(stdin);
        scanf("%d",&op);
        n=op;
        op--; // o vetor começa no 0 mas no utilizador começa no 1
        if (op>-1 && op<alojamentos_num){ // opcao esta nas pretendidas
            for ( j=op; j<alojamentos_num ; j++) { // percorre todos os clientes
                vec_alojamentos[j].id = vec_alojamentos[n].id;
                strcpy(vec_alojamentos[j].categoria, vec_alojamentos[n].categoria);     // escolhe se o q se quer remover
                vec_alojamentos[j].numero = vec_alojamentos[n].numero;        // pegamos no q estava na posiçao seguinte
                vec_alojamentos[j].preco = vec_alojamentos[n].preco;          // pomos na posicao anterior, desaparece a outra
                strcpy(vec_alojamentos[j].caracteristicas, vec_alojamentos[n].caracteristicas);
                vec_alojamentos[j].classificacao = vec_alojamentos[n].classificacao;
                n++;
                alojamentos_num--; //diminui o numero de alojamentos
            }
        }
        else {
            printf("Opcao Invalida\n");
            goto remov;
        }
    }
}
/**
 * funcao para listar os alojamentos
 */
void ListaAlojamento(){
    if (alojamentos_num>0){ //se num maior que 0 lista os alojamentos
        for (int j = 0; j < alojamentos_num ; j++) {
            printf("\nAlojamentos:\n");
            printf("id: %d\n",vec_alojamentos[j].id);
            printf("Categoria: %s\n",vec_alojamentos[j].categoria);
            printf("Numero: %d\n",vec_alojamentos[j].numero);
            printf("Preco: %d\n",vec_alojamentos[j].preco);
            printf("Caracteristicas: %s\n",vec_alojamentos[j].caracteristicas);
            printf("Classificacao: %d\n",vec_alojamentos[j].classificacao);
        }
    } else
        printf("Ainda nao tem nenhum Alojamento\n");
}
/**
 * grava os alojamentos para ficheiro de texto
 */
void AlojamentoParaFicheiro(){
    FILE *lerFicheiroTexto;
    lerFicheiroTexto = fopen("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projetoIAPG\\alojamentos.txt","w");
    if (lerFicheiroTexto != NULL){ //verifica se o ficheiro existe
        fprintf(lerFicheiroTexto,"%d\n",alojamentos_num); //guarda o numero de clientes
        for (int i = 0; i <alojamentos_num ; i++) {
            fprintf(lerFicheiroTexto,"\n%d\n",vec_alojamentos[i].id); //guarda para o ficheiro
            fprintf(lerFicheiroTexto,"%s\n",vec_alojamentos[i].categoria);
            fprintf(lerFicheiroTexto,"%d\n",vec_alojamentos[i].numero);
            fprintf(lerFicheiroTexto,"%d\n",vec_alojamentos[i].preco);
            fprintf(lerFicheiroTexto,"%s\n",vec_alojamentos[i].caracteristicas);
            fprintf(lerFicheiroTexto,"%d\n",vec_alojamentos[i].classificacao);
        }
        fprintf(lerFicheiroTexto, "\n");
        fclose(lerFicheiroTexto);
    }
}
/**
 * carrega os alojamentos do ficheiro de texto para o programa
 */
void AlojamentoDoFicheiro(){
    FILE *lerFicheiroTexto;
    lerFicheiroTexto = fopen("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projetoIAPG\\alojamentos.txt","r");
    char linha[TAM_NOME];
    if (lerFicheiroTexto !=NULL){ //verifica se o ficheiro existe
        fscanf(lerFicheiroTexto, "%d\n", &alojamentos_num); //le o numero
        fflush(stdin);
        for (int i = 0; i <alojamentos_num ; i++) {
            fscanf(lerFicheiroTexto, "%d\n", &vec_alojamentos[i].id);
            fgets(linha, TAM_NOME, lerFicheiroTexto); //le a linha
            linha[strlen(linha)-1]=0;                 // retira a quebta de linha
            strcpy(vec_alojamentos[i].categoria, &linha[0]);
            fscanf(lerFicheiroTexto,"%d\n",&vec_alojamentos[i].numero);
            fscanf(lerFicheiroTexto,"%d\n",&vec_alojamentos[i].preco);
            fgets(linha, TAM_NOME, lerFicheiroTexto);
            linha[strlen(linha)-1]=0;
            strcpy(vec_alojamentos[i].caracteristicas, &linha[0]);
            fscanf(lerFicheiroTexto,"%d\n",&vec_alojamentos[i].classificacao);
        }
        fclose(lerFicheiroTexto);
    }
}

void menuCategorias(){
    int op;
    do{
        printf("\nEscolha uma Opcao das seguintes:\n");
        printf("1 - Adicionar Categorias\n");
        printf("2 - Editar Categorias\n");
        printf("3 - Remover Categorias\n");
        printf("4 - Listar Categorias\n");
        printf("0 - Sair\n");
        scanf("%d", &op); // guarda opcao do utilizador
        fflush(stdin);
        switch (op){
            case 1 :
                printf("\nInserir Categorias:\n");
                InserirCategorias();
                break;
            case 2 :
                printf("\nEditar Categorias:\n");
                EditarCategorias();
                break;
            case 3 :
                printf("\nRemover Categorias:\n");
                RemoverCategorias();
                break;
            case 4 :
                printf("\nListar Categorias:\n");
                ListarCategorias();
                break;
            case 0 :
                menu();
                break;
            default:
                printf("Opcao Invalida\n");
        }
        if (op != 0){
            printf("\nPrima qualquer tecla para voltar ao menu");
            getchar();
        }
    }
    while (op != 0);
}
/**
 * Insere manualmente as categorias
 * usando o vec_alojamento e o alojamentos_num
 */
void InserirCategorias() { //inserir categoria
    printf("Categoria do Alojamento:\n");
    gets(vec_alojamentos[alojamentos_num].categoria);
    vec_alojamentos[alojamentos_num].id =alojamentos_num +1 ; //o id é igual ao numero de alojamentos + 1
    alojamentos_num++;

}
/**
 * funcao para editar as categorias dos alojamentos
 */
void EditarCategorias() {
    if (alojamentos_num > 0) {
        int op;
        printf("Qual Categoria quer alterar? De 1 a %d\n", alojamentos_num);
        scanf("%d", &op); //é a opcao do utilizador
        fflush(stdin);
        op--;
        if (op > -1 && op < alojamentos_num) {//verifica se a opcao esta nas pretendidas
            printf("\nCategoria:\n");
            gets(vec_alojamentos[op].categoria);
            menuCategorias();
        }
        else
            printf("Opcao Invalida\n");
    }
    else
        printf("Ainda nao tem nenhuma Categoria\n");
}
/**
 * funcao para remover as categorias dos alojamentos
 */
void RemoverCategorias(){
    if (alojamentos_num>0){
        int n,j,op;
        remov: // volta para aqui se algo der errado
        printf("Escolha de 1 a %d qual a Categoria que quer remover:\n",alojamentos_num);
        fflush(stdin);
        scanf("%d",&op);
        n=op;
        op--; // o vetor começa no 0 mas no utilizador começa no 1
        if (op>-1 && op<alojamentos_num){ // opcao esta nas pretendidas
            for ( j=op; j<alojamentos_num ; j++) { // percorre todos os clientes
                vec_alojamentos[j].id = vec_alojamentos[n].id; // copia o q esta na posicao da frente para a q eliminou
                strcpy(vec_alojamentos[j].categoria, vec_alojamentos[n].categoria);
                n++;
                alojamentos_num--; //diminui o numero de clientes
            }
        }
        else {
            printf("Opcao Invalida\n");
            goto remov;
        }
    }
}
/**
 * funcao para listar as categorias dos alojamentos
 */
void ListarCategorias(){
    if (alojamentos_num>0){ //se num maior que 0 lista as categorias dos alojamentos
        for (int j = 0; j < alojamentos_num ; j++) {
            printf("\nTodas as Categorias dos Alojamentos:\n");
            printf("id: %d\n",vec_alojamentos[j].id);
            printf("Categoria: %s\n",vec_alojamentos[j].categoria);
        }
    } else
        printf("Ainda nao tem nenhuma Categoria\n");
}

/// PROCURAR

void menuProcurar(){
    int n;
    do{
        printf("\nEscolha uma Opcao das seguintes:\n");
        printf("1 - Pesquisar Nome Cliente\n");
        printf("2 - Pesquisar Categoria Alojamento\n");
        printf("3 - Pesquisar Preco Alojamento\n");
        printf("4 - Pesquisar Caracteristicas Alojamento\n");
        printf("5 - Pesquisar Classificacao Alojamento\n");
        printf("6 - Pesquisar Pais\n");
        printf("7 - Pesquisar Cidade\n");
        printf("0 - Sair\n");
        scanf("%d", &n); // guarda opcao do utilizador
        fflush(stdin);
        switch (n){
            case 1 :
                printf("\nPesquisar Nome Cliente:\n");
                PesquisarNome();
                break;
            case 2 :
                printf("\nPesquisar Categoria Alojamento:\n");
                PesquisarCategoria();
                break;
            case 3 :
                printf("\nPesquisar Preco Alojamento:\n");
                PesquisarPreco();
                break;
            case 4 :
                printf("\nCaracteristicas Alojamento:\n");
                PesquisarCaracteristicasAlojamentos();
                break;
            case 5 :
                printf("\nPesquisar Classificacao Alojamento\n");
                PesquisarClassificacaoAlojamento();
                break;
            case 6 :
                printf("\nPesquisar Pais\n");
                PesquisarPais();
                break;
            case 7 :
                printf("\nPesquisar Cidade\n");
                PesquisarCidade();
                break;
            case 0 :
                menu();
                break;
            default:
                printf("Opcao Invalida\n");
        }
        if (n != 0){
            printf("\nPrima qualquer tecla para voltar ao menu");
            getchar();
        }
    }
    while (n != 0);
}
/**
 * funcao para pesquisar pelo nome do cliente
 * aparece toda a informaçao encontrada acerca desse cliente e o seu destino
 */
void PesquisarNome(){ //pesquisa atraves de informacao relevante
    int n=0;
    char pesquisa[TAM_NOME];
    printf("Nome do Cliente que quer pesquisar:\n");
    gets(pesquisa);
    for (int i = 0; i < cliente_num; i++) {
        if (strcmp(pesquisa, vec_cliente[i].nome)==0) { //compara a string pesquisa com a outra
            printf("ID: %d\n", vec_cliente[i].id); //para ver se corresponde com o que o utilizador introduzio
            printf("Nome: %s\n", vec_cliente[i].nome); //se coincidir lista toda a informacao acerca do que encontrou
            printf("Numero: %d\n",vec_cliente[i].numero);
            printf("Genero: %s\n",vec_cliente[i].genero);
            printf("Idade: %d\n",vec_cliente[i].idade);
            printf("Nacionalidade: %s\n\n",vec_cliente[i].nacionalidade);

            /*printf("Destino: \n");
            printf("idDestino: %d\n", vec_destino[i].idDestino); //FUNCIONA PARA TODOS DIREITO
            printf("Pais: %s\n", vec_destino[i].pais);           //SO E DIFERENTE NA MANEIRA DE ASSOCIAR
            printf("Cidade: %s\n\n", vec_destino[i].cidade);*/

            //Destino
            if (vec_cliente[i].id == vec_destino[n].id)
                strcpy(vec_cliente[i].destino.pais, vec_destino[n].pais);
                strcpy(vec_cliente[i].destino.cidade, vec_destino[n].cidade);
                printf("Destino: \n");
                printf("Pais: %s\n", vec_cliente[n].destino.pais);
                printf("Cidade: %s\n", vec_cliente[n].destino.cidade);
        }
        n++;
    }
}
/**
 * funcao para pesquisar pela categoria do alojamento
 * aparece toda a informaçao encontrada acerca desse alojamento e o seu destino
 */
void PesquisarCategoria(){
    int n=0;
    char pesquisa[TAM_NOME];
    printf("Categoria que pretende pesquisar:\n");
    gets(pesquisa);
    for (int i = 0; i < alojamentos_num; i++) {
        if (strcmp(pesquisa, vec_alojamentos[i].categoria)==0) { //compara a string pesquisa com a outra
            printf("ID: %d\n", vec_alojamentos[i].id); //para ver se corresponde com o que o utilizador introduzio
            printf("Categoria %s\n", vec_alojamentos[i].categoria); //se coincidir lista toda a informacao acerca do q foi encontrado
            printf("Preco: %d\n", vec_alojamentos[i].preco);
            printf("Numero: %d\n", vec_alojamentos[i].numero);
            printf("Caracteristica: %s\n", vec_alojamentos[i].caracteristicas);
            printf("Classificacao: %d\n\n", vec_alojamentos[i].classificacao);

            /*printf("Destino: \n");
            printf("idDestino: %d\n", vec_destino[i].idDestino); //FUNCIONA PARA TODOS DIREITO
            printf("Pais: %s\n", vec_destino[i].pais);           //SO E DIFERENTE NA MANEIRA DE ASSOCIAR
            printf("Cidade: %s\n\n", vec_destino[i].cidade);*/

            //Destino
            if (vec_alojamentos[i].id == vec_destino[n].id)
                strcpy(vec_alojamentos[i].destino.pais, vec_destino[n].pais);
                strcpy(vec_alojamentos[i].destino.cidade, vec_destino[n].cidade);
                printf("Destino: \n");
                printf("Pais: %s\n", vec_alojamentos[n].destino.pais);
                printf("Cidade: %s\n", vec_alojamentos[n].destino.cidade);
        }
        n++;
    }
}
/**
 * funcao para pesquisar pelo preco do alojamento
 * aparece toda a informaçao encontrada acerca desse alojamento e o seu destino
 */
void PesquisarPreco(){
    int n=0;
    int pesquisa;
    printf("Preco que pretende pesquisar:\n");
    scanf("%d", &pesquisa);
    fflush(stdin);
    for (int i = 0; i < alojamentos_num; i++) {
        if (pesquisa == vec_alojamentos[i].preco) { //compara o int pesquisa com o int do preço
            printf("ID: %d\n", vec_alojamentos[i].id); //para ver se corresponde com o que o utilizador introduzio
            printf("Categoria %s\n", vec_alojamentos[i].categoria); //se coincidir lista toda a informacao acerca do q foi encontrado
            printf("Preco: %d\n", vec_alojamentos[i].preco);
            printf("Numero: %d\n", vec_alojamentos[i].numero);
            printf("Caracteristica: %s\n", vec_alojamentos[i].caracteristicas);
            printf("Classificacao: %d\n\n", vec_alojamentos[i].classificacao);

            /*printf("Destino: \n");
            printf("idDestino: %d\n", vec_destino[i].idDestino); //FUNCIONA PARA TODOS DIREITO
            printf("Pais: %s\n", vec_destino[i].pais);           //SO E DIFERENTE NA MANEIRA DE ASSOCIAR
            printf("Cidade: %s\n\n", vec_destino[i].cidade);*/

            //Destino
            if (vec_alojamentos[i].id == vec_destino[n].id)
                strcpy(vec_alojamentos[i].destino.pais, vec_destino[n].pais);
                strcpy(vec_alojamentos[i].destino.cidade, vec_destino[n].cidade);
                printf("Destino: \n");
                printf("Pais: %s\n", vec_alojamentos[n].destino.pais);
                printf("Cidade: %s\n", vec_alojamentos[n].destino.cidade);
        }
        n++;
    }
}
/**
 * funcao para pesquisar pelas caracteristicas do alojamento
 * aparece toda a informaçao encontrada acerca desse alojamento e o seu destino
 */
void PesquisarCaracteristicasAlojamentos(){
    int n=0;
    char pesquisa[TAM_NOME];
    printf("Caracteristica do Alojamentos que pretende pesquisar:\n");
    gets(pesquisa);
    for (int i = 0; i < alojamentos_num; i++) {
        if (strcmp(pesquisa, vec_alojamentos[i].caracteristicas)==0) { //compara a string pesquisa com a outra
            printf("ID: %d\n", vec_alojamentos[i].id);        //para ver se corresponde com o que o utilizador introduzio
            printf("Categoria %s\n", vec_alojamentos[i].categoria); //se coincidir lista toda a informacao acerca do q foi encontrado
            printf("Preco: %d\n", vec_alojamentos[i].preco);
            printf("Numero: %d\n", vec_alojamentos[i].numero);
            printf("Caracteristica: %s\n", vec_alojamentos[i].caracteristicas);
            printf("Classificacao: %d\n\n", vec_alojamentos[i].classificacao);

            /*printf("Destino: \n");
            printf("idDestino: %d\n", vec_destino[i].idDestino); //FUNCIONA PARA TODOS DIREITO
            printf("Pais: %s\n", vec_destino[i].pais);           //SO E DIFERENTE NA MANEIRA DE ASSOCIAR
            printf("Cidade: %s\n\n", vec_destino[i].cidade);*/

            //Destino
            if (vec_alojamentos[i].id == vec_destino[n].id)
                strcpy(vec_alojamentos[i].destino.pais, vec_destino[n].pais);
                strcpy(vec_alojamentos[i].destino.cidade, vec_destino[n].cidade);
                printf("Destino: \n");
                printf("Pais: %s\n", vec_alojamentos[n].destino.pais);
                printf("Cidade: %s\n", vec_alojamentos[n].destino.cidade);
        }
        n++;
    }
}
/**
 * funcao para pesquisar pela classificacao em estrelas do alojamento
 * aparece toda a informaçao encontrada acerca desse alojamento e o seu destino
 */
void PesquisarClassificacaoAlojamento(){
    int n=0;
    int pesquisa;
    printf("Classificacao do Alojamentos que pretende pesquisar:\n");
    scanf("%d", &pesquisa);
    fflush(stdin);
    for (int i = 0; i < alojamentos_num; i++) {
        if (pesquisa == vec_alojamentos[i].classificacao) { //compara a string pesquisa com a outra
            printf("ID: %d\n", vec_alojamentos[i].id);        //para ver se corresponde com o que o utilizador introduzio
            printf("Categoria %s\n", vec_alojamentos[i].categoria); //se coincidir lista toda a informacao acerca do q foi encontrado
            printf("Preco: %d\n", vec_alojamentos[i].preco);
            printf("Numero: %d\n", vec_alojamentos[i].numero);
            printf("Caracteristica: %s\n", vec_alojamentos[i].caracteristicas);
            printf("Classificacao: %d\n\n", vec_alojamentos[i].classificacao);

            /*printf("Destino: \n");
            printf("idDestino: %d\n", vec_destino[i].idDestino); //FUNCIONA PARA TODOS DIREITO
            printf("Pais: %s\n", vec_destino[i].pais);           //SO E DIFERENTE NA MANEIRA DE ASSOCIAR
            printf("Cidade: %s\n\n", vec_destino[i].cidade);*/

            //Destino
            if (vec_alojamentos[i].id == vec_destino[n].id)
                strcpy(vec_alojamentos[i].destino.pais, vec_destino[n].pais);
                strcpy(vec_alojamentos[i].destino.cidade, vec_destino[n].cidade);
                printf("Destino: \n");
                printf("Pais: %s\n", vec_alojamentos[n].destino.pais);
                printf("Cidade: %s\n", vec_alojamentos[n].destino.cidade);
        }
        n++;
    }
}
/**
 * funcao para pesquisar pelo pais de destino
 * aparece toda a informaçao encontrada acerca destino
 */
void PesquisarPais(){
    char pesquisa[TAM_NOME];
    printf("Pais por que pretende pesquisar:\n");
    gets(pesquisa);
    for (int i = 0; i < destino_num; i++) {
        if (strcmp(pesquisa, vec_destino[i].pais)==0) { //compara a string pesquisa com a outra
            printf("ID: %d\n", vec_destino[i].id);        //para ver se corresponde com o que o utilizador introduzio
            printf("Pais %s\n", vec_destino[i].pais); //se coincidir lista toda a informacao acerca do q foi encontrado
            printf("Cidade: %s\n", vec_destino[i].cidade);
            printf("Numero: %d\n", vec_destino[i].numero);

        }
    }
}
/**
 * funcao para pesquisar pela cidade de destino
 * aparece toda a informaçao encontrada acerca destino
 */
void PesquisarCidade(){
    char pesquisa[TAM_NOME];
    printf("Pais por que pretende pesquisar:\n");
    gets(pesquisa);
    for (int i = 0; i < destino_num; i++) {
        if (strcmp(pesquisa, vec_destino[i].cidade)==0) { //compara a string pesquisa com a outra
            printf("ID: %d\n", vec_destino[i].id);        //para ver se corresponde com o que o utilizador introduzio
            printf("Pais %s\n", vec_destino[i].pais); //se coincidir lista toda a informacao acerca do q foi encontrado
            printf("Cidade: %s\n", vec_destino[i].cidade);
            printf("Numero: %d\n", vec_destino[i].numero);

        }
    }
}

/// VIAGENS

void menuViagens(){
    int op;
    do{
        printf("\nEscolha uma Opcao das seguintes:\n");
        printf("1 - Listar Viagem\n");
        printf("2 - Listar Todas as Viagens\n");
        printf("3 - Remover Viagem\n");
        printf("4 - Gravar para Ficheiro\n");
        printf("5 - Carregar do Ficheiro\n");
        printf("0 - Sair\n");
        scanf("%d", &op); // guarda opcao do utilizador
        fflush(stdin);
        switch (op){
            case 1 :
                printf("\nListar Viagem:\n");
                listarViagem();
                break;
            case 2 :
                printf("\nListar Todas as Viagens:\n");
                listarTodasViagens();
                break;
            case 3 :
                printf("\nRemover Viagem:\n");
                RemoverViagem();
                break;
            case 4 :
                printf("\nGravar para Ficheiro:\n");
                ViagensParaFicheiro();
                printf("Parabens, guardou as viagens com sucesso!\n");
                break;
            case 5 :
                printf("\nCarregar do Ficheiro\n");
                ViagensDoFicheiro();
                printf("Parabens, carregou as viagens com sucesso!\n");
                break;
            case 0 :
                menu();
                break;
            default:
                printf("Opcao Invalida\n");
        }
        if (op != 0){
            printf("\nPrima qualquer tecla para voltar ao menu");
            getchar();
        }
    }
    while (op != 0);
}
/**
 * funcao para listar uma viagem a nossa escolha
 */
void listarViagem() {
    int n = 0;
    int tudo=((cliente_num + destino_num + alojamentos_num)/3);
    if (tudo>0) {
        printf("De 1 a %d qual a viagem que deseja listar?\n",tudo);
        erro:
        scanf("%d",&n);
        n--;
        if (n > -1 && n < tudo) {
            printf("\tCLIENTE\t\n"); //lista informacao do cliente
            printf("id: %d\n",vec_cliente[n].id);
            printf("Cliente: %s\n", vec_cliente[n].nome);
            printf("Nacionalidade: %s\n", vec_cliente[n].nacionalidade);
            printf("Idade: %d\n", vec_cliente[n].idade);
            printf("Genero: %s\n", vec_cliente[n].genero);
            printf("Numero: %d\n\n",vec_cliente[n].numero);

            printf("\tDESTINO\t\n"); //lista informacao do destino
            printf("Pais: %s\n", vec_destino[n].pais);
            printf("Cidade: %s\n", vec_destino[n].cidade);
            printf("Numero: %d\n\n",vec_destino[n].numero);

            printf("\tALOJAMENTO\t\n"); //lista informacao dos alojamentos
            printf("Categoria: %s\n", vec_alojamentos[n].categoria);
            printf("Numero: %d\n",vec_alojamentos[n].numero);
            printf("Preco: %d\n", vec_alojamentos[n].preco);
            printf("Caracteristicas: %s\n", vec_alojamentos[n].caracteristicas);
            printf("Classificacao: %d\n", vec_alojamentos[n].classificacao);

        } else {
            printf("Opcao Invalida\n");
            printf("Insira novamente!\n");
            getchar();
            goto erro;
        }
    } else  printf("Ainda nao foi inserida nenhuma viagem\n");
}
/**
 * funcao que lista todas as viagens do programa
 */
void listarTodasViagens() {
    int i;
    int tudo=((cliente_num + destino_num + alojamentos_num)/3);
    if (tudo > 0) {// caso nao tenha introduzido nenhuma viagem
        for (i = 0; i < tudo; i++) {//for para percorrer todas as viagens

            printf("\tCLIENTE\t\n"); //lista informacao de todos os clientes
            printf("id: %d\n",vec_cliente[i].id);
            printf("Cliente: %s\n", vec_cliente[i].nome);
            printf("Nacionalidade: %s\n", vec_cliente[i].nacionalidade);
            printf("Idade: %d\n", vec_cliente[i].idade);
            printf("Genero: %s\n", vec_cliente[i].genero);
            printf("Numero: %d\n\n",vec_cliente[i].numero);

            printf("\tDESTINO\t\n"); //lista informacao de todos os destinos
            printf("Pais: %s\n", vec_destino[i].pais);
            printf("Cidade: %s\n", vec_destino[i].cidade);
            printf("Numero: %d\n\n",vec_destino[i].numero);

            printf("\tALOJAMENTO\t\n"); //lista informacao de todos os alojamentos
            printf("Categoria: %s\n", vec_alojamentos[i].categoria);
            printf("Numero: %d\n",vec_alojamentos[i].numero);
            printf("Preco: %d\n", vec_alojamentos[i].preco);
            printf("Caracteristicas: %s\n", vec_alojamentos[i].caracteristicas);
            printf("Classificacao: %d\n\n", vec_alojamentos[i].classificacao);
        }
    } else
        printf("Ainda nao foi inserida nenhuma viagem\n");
}
/**
 * grava as viagens para um ficheiro de texto
 */
void ViagensParaFicheiro(){
    int tudo=((cliente_num + destino_num + alojamentos_num)/3);
    FILE *lerFicheiroTexto;
    lerFicheiroTexto = fopen("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projetoIAPG\\viagens.txt","w");
    if (lerFicheiroTexto != NULL){ //verifica se o ficheiro existe
        fprintf(lerFicheiroTexto,"%d\n",tudo); //guarda o numero de clientes
        for (int i = 0; i< tudo ; i++) {
            //cliente
            fprintf(lerFicheiroTexto,"\n%d\n",vec_cliente[i].id); //guarda para o ficheiro
            fprintf(lerFicheiroTexto,"%s\n",vec_cliente[i].nome);
            fprintf(lerFicheiroTexto,"%s\n",vec_cliente[i].nacionalidade);
            fprintf(lerFicheiroTexto,"%d\n",vec_cliente[i].idade);
            fprintf(lerFicheiroTexto,"%s\n",vec_cliente[i].genero);
            fprintf(lerFicheiroTexto,"%d\n",vec_cliente[i].numero);

            //destino
            fprintf(lerFicheiroTexto,"%s\n",vec_destino[i].pais);
            fprintf(lerFicheiroTexto,"%s\n",vec_destino[i].cidade);
            fprintf(lerFicheiroTexto,"%d\n",vec_destino[i].numero);

            //alojamento
            fprintf(lerFicheiroTexto,"%s\n",vec_alojamentos[i].categoria);
            fprintf(lerFicheiroTexto,"%d\n",vec_alojamentos[i].numero);
            fprintf(lerFicheiroTexto,"%d\n",vec_alojamentos[i].preco);
            fprintf(lerFicheiroTexto,"%s\n",vec_alojamentos[i].caracteristicas);
            fprintf(lerFicheiroTexto,"%d\n",vec_alojamentos[i].classificacao);
        }
        fprintf(lerFicheiroTexto, "\n");
        fclose(lerFicheiroTexto);
    }
}
/**
 * carrega as viagens de um ficheiro de texto para o programa
 */
void ViagensDoFicheiro(){
    int tudo=((cliente_num + destino_num + alojamentos_num)/3);
    FILE *lerFicheiroTexto;
    lerFicheiroTexto = fopen("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projetoIAPG\\viagens.txt","r");
    char linha[TAM_NOME];
    if (lerFicheiroTexto !=NULL){ //verifica se o ficheiro existe
        fscanf(lerFicheiroTexto, "%d\n", &tudo); //le o numero
        fflush(stdin);
        for (int i = 0; i <tudo ; i++) {
            //Cliente
            fscanf(lerFicheiroTexto, "%d\n", &vec_cliente[i].id); //guarda o id
            fgets(linha, TAM_NOME, lerFicheiroTexto); //le a linha
            linha[strlen(linha)-1]=0; // retira a quebra de linha
            strcpy(vec_cliente[i].nome, &linha[0]);
            fgets(linha, TAM_NOME, lerFicheiroTexto);
            linha[strlen(linha)-1]=0;
            strcpy(vec_cliente[i].nacionalidade, &linha[0]);
            fscanf(lerFicheiroTexto,"%d\n",&vec_cliente[i].idade);
            fgets(linha, TAM_NOME, lerFicheiroTexto);
            linha[strlen(linha)-1]=0;
            strcpy(vec_cliente[i].genero, &linha[0]);
            fscanf(lerFicheiroTexto,"%d\n",&vec_cliente[i].numero);

            //destino
            //fscanf(lerFicheiroTexto, "%d\n", &vec_destino[i].idDestino);
            fgets(linha, TAM_NOME, lerFicheiroTexto); //le a linha
            linha[strlen(linha)-1]=0; // retira a quebta de linha
            strcpy(vec_destino[i].pais, &linha[0]);
            fgets(linha, TAM_NOME, lerFicheiroTexto);
            linha[strlen(linha)-1]=0;
            strcpy(vec_destino[i].cidade, &linha[0]);
            fscanf(lerFicheiroTexto,"%d\n",&vec_destino[i].numero);

            //alojamento
            //fscanf(lerFicheiroTexto, "%d\n", &vec_alojamentos[i].id);
            fgets(linha, TAM_NOME, lerFicheiroTexto); //le a linha
            linha[strlen(linha)-1]=0; // retira a quebta de linha
            strcpy(vec_alojamentos[i].categoria, &linha[0]);
            fscanf(lerFicheiroTexto,"%d\n",&vec_alojamentos[i].numero);
            fscanf(lerFicheiroTexto,"%d\n",&vec_alojamentos[i].preco);
            fgets(linha, TAM_NOME, lerFicheiroTexto);
            linha[strlen(linha)-1]=0;
            strcpy(vec_alojamentos[i].caracteristicas, &linha[0]);
            fscanf(lerFicheiroTexto,"%d\n",&vec_alojamentos[i].classificacao);
        }
        fclose(lerFicheiroTexto);
    }
}
/**
 * funcao para remover uma viagem
 */
void RemoverViagem() {// funcao para eliminar viagens
    int tudo=((cliente_num + destino_num + alojamentos_num)/3);
    if (tudo > 0) {
        int i, opr;
        printf("De 1 a %d qual a Viagem que quer remover?\n", tudo);
        remove:
        scanf("%d", &opr);
        i=opr;
        opr--;
        if (opr > -1 && opr < tudo) {// verificar se a opcao esta entre as opcoes
            for (int j = opr; j < tudo; j++) {//for para percorrer todas as viagens
                vec_cliente[j].id = vec_cliente[i].id;
                strcpy(vec_cliente[j].nome, vec_cliente[i].nome);     // escolhe se o q se quer remover
                vec_cliente[j].numero = vec_cliente[i].numero;        // pegamos no q estava na posiçao seguinte
                strcpy(vec_cliente[j].genero, vec_cliente[i].genero); // pomos na posicao anterior, desaparece a que escolhemos
                vec_cliente[j].idade = vec_cliente[i].idade;
                strcpy(vec_cliente[j].nacionalidade, vec_cliente[i].nacionalidade);

                vec_destino[j].id = vec_destino[i].id;
                strcpy(vec_destino[j].pais, vec_destino[i].pais);     // escolhe se o q se quer remover
                vec_destino[j].numero = vec_destino[i].numero;        // pegamos no q estava na posiçao seguinte
                strcpy(vec_destino[j].cidade, vec_destino[i].cidade); // pomos na posicao anterior, desaparece a que escolhemos

                vec_alojamentos[j].id = vec_alojamentos[i].id;
                strcpy(vec_alojamentos[j].categoria, vec_alojamentos[i].categoria);     // escolhe se o q se quer remover
                vec_alojamentos[j].numero = vec_alojamentos[i].numero;        // pegamos no q estava na posiçao seguinte
                vec_alojamentos[j].preco = vec_alojamentos[i].preco;          // pomos na posicao anterior, desaparece a outra
                strcpy(vec_alojamentos[j].caracteristicas, vec_alojamentos[i].caracteristicas);
                vec_alojamentos[j].classificacao = vec_alojamentos[i].classificacao;
                i++;
                tudo--;
            }
        } else {
            printf("Opcao Invalida\n");
            printf("Insira novamente\n");
            goto remove;
        }
    }
}
