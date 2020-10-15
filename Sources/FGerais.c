/********************BIBLIOTECA*******************************************/
#include "FBiblioteca.h"

#include <stdio.h>
#include <stdlib.h>

#include "mysql/mysql.h"

MYSQL conex;

/*FUNCAO PARA CONECTAR AO SERVIDOR*/
void conectar(void){
   char usuario[10], senha[10];
     
   printf("Digite o nome do usuario:\n");
    scanf(" %11[^\n]",usuario);
    printf("Digite a senha:\n");
    scanf(" %11[^\n]",senha);
   
    mysql_init(&conex); 
  
    if (mysql_real_connect(&conex, "localhost", usuario, senha, "Biblioteca", 0, NULL, 0)) {
       printf("\n============================\n");
       printf("********Conectado!!********\n");
        printf("============================\n");
    }
    else{
       printf("Falha na conexao!\n");
    
      if (mysql_errno(&conex)) {
         printf("Connection error %d: %s\n", mysql_errno(&conex), mysql_error(&conex));
      }
    }
}
/*--------------------------------------------------------------------------*/
/*FUNCAO DESCONECTAR NO SERVIDOR*/
void desconectar(void){
    mysql_close(&conex);
    printf("\n============================\n");
    printf("DESCONECTOU COM SUCESSO!\n");
    printf("============================\n");
}
/*--------------------------------------------------------------------------*/
/*FUNCAO DO MENU PRINCIPAL*/
void menuPrincipal(void){
    int opc;
    while(1){
        printf("\n=================================\n");
        printf("BIBLIOTECA PARTICULAR. BEM VINDO!!\n");
        printf("=================================\n");
        printf("***CONECTAR ANTES DE USAR***!!! \n\n");
        printf("Digite uma opcao:\n");
        printf("[1]CONECTAR AO SERVIDOR MYSQL\n");
        printf("[2]DESCONECTAR\n");
        printf("[3]INCLUIR\n");
        printf("[4]ALTERAR\n");
        printf("[5]EXCLUIR\n");
        printf("[6]CONSULTAR\n");
        printf("[7]RELATÓRIOS\n");
        printf("[8]SAIR\n\n");
        scanf("%d", &opc);
        
        switch (opc){
            case 1: conectar();
                break;
            case 2: desconectar();
                break;
            case 3: menuIncluir();
                break;
            case 4: menuAlterar();
                break;
            case 5: menuExcluir();
                break;
            case 6: menuConsultar();
                break;
            case 7: menuRelatorio();
                break;
            case 8: sair();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }
    
}
/*--------------------------------------------------------------------------*/
void sair(void){
    
    printf("ByeBye!!\n\n\n");
    exit(0);
}
/*--------------------------------------------------------------------------*/
void resultado(char* aux){
   
    int res;
    res = mysql_query(&conex,aux);
    if (!res){
	printf("Linha %lu atualizada!\n", (unsigned long)mysql_affected_rows(&conex));
    }
    else{ 
	printf("Erro na atualização! %d: %s\n", mysql_errno(&conex), mysql_error(&conex));
    }    
}
/*--------------------------------------------------------------------------*/
/*Funcao que verifica se o livro esta disponivel ou emprestado */
int verificaLivro(int livro){
     
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int res, codBook, status; 
    unsigned int row=0;
    char aux[100], teste[500];
    
    codBook = livro;
      
    sprintf(aux,"SELECT Status_2 FROM Livro WHERE CodLivro=%d",codBook);
    res = mysql_query(&conex, aux);
	
    	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
	  res_ptr = mysql_store_result(&conex);
	     if (res_ptr) {
		   while ((sqlrow = mysql_fetch_row(res_ptr))) {
                       for (row=0; row< mysql_field_count(&conex); row++) {
       			     /* printf("%s\n", sqlrow[row]);*/
                               return atoi(sqlrow[row]);
                         }
                        if (mysql_errno(&conex)) 
			  printf("Retrive error: %s\n", mysql_error(&conex));	  
		     }
                }
		mysql_free_result(res_ptr);
	}
}   
/*--------------------------------------------------------------------------*/