/******************BIBLIOTECA**********************/
#include "FBiblioteca.h"

MYSQL conex;

void menuExcluir(void){
    int opc;
    while(1){
        
        printf("\n******************\n");	
        printf("***EXCLUIR***\n");
        printf("******************\n");
        printf("Digite uma opção:\n");
        printf("[1]LIVRO\n");
        printf("[2]LIVRARIA\n");
        printf("[3]AUTOR\n");
        printf("[4]AMIGO\n");
        printf("[5]EMPRESTIMO\n");
        printf("[6]COMPRA\n");
        printf("[7]RETORNAR AO MENU PRINCIPAL\n\n\n");
        
        scanf("%d", &opc);
        
        switch (opc){
            case 1: excluirLivro();
                break;
            case 2: excluirLivraria();
                break;
            case 3: excluirAutor();
                break;
            case 4: excluirAmigo();
                break;
            case 5: excluirEmprestimo();
                break;
            case 6: excluirCompra();
                break;
            case 7: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }
    
}
    
/*--------------------------------------------------------------------------*/
void excluirLivro(void){
    
    int res;
    int codLivro;
    
    printf("\n*****EXCLUIR LIVRO*****\n");
    printf("\nDigite o código do Livro:\n");
      scanf("%d",&codLivro);
    char aux[301];
	
   sprintf(aux,"DELETE FROM Livro WHERE Livro.CodLivro=%d",codLivro);
   resultado(aux);
   
   /***EXCLUI TAMBEM EM ESCREVE***/
   sprintf(aux,"DELETE FROM Escreve WHERE Escreve.Livro_CodLivro=%d",codLivro);
   resultado(aux);
   
   /***EXCLUI TAMBEM EM COMPRA***/
   sprintf(aux,"DELETE FROM Compra WHERE Compra.Livro_CodLivro=%d",codLivro);
   resultado(aux);
   
   /***EXCLUI TAMBEM EM EMPRESTA***/
   sprintf(aux,"DELETE FROM Empresta WHERE Empresta.Livro_CodLivro=%d",codLivro);
   resultado(aux);
}
/*--------------------------------------------------------------------------*/
void excluirLivraria(void){
    
    int codLivraria;
    
    printf("\n*****EXCLUIR LIVRARIA*****\n");
    printf("\nDigite o código da Livraria:\n");
      scanf("%d",&codLivraria);
    char aux[301];
	
   sprintf(aux,"DELETE FROM Livraria WHERE Livraria.CodLivraria=%d",codLivraria);
   resultado(aux);
    
   /***EXCLUI TAMBEM EM COMPRA***/
   sprintf(aux,"DELETE FROM Compra WHERE Compra.Livraria_CodLivraria=%d",codLivraria);
   resultado(aux);
}
/*--------------------------------------------------------------------------*/
void excluirAutor(void){

    int codAutor;
    
    printf("\n*****EXCLUIR AUTOR*****\n");
    printf("\nDigite o código do Autor:\n");
      scanf("%d",&codAutor);
    char aux[301];
	
   sprintf(aux,"DELETE FROM Autor WHERE Autor.CodAutor=%d",codAutor);
   resultado(aux);
   
   /***EXCLUI TAMBEM EM ESCREVE***/
   sprintf(aux,"DELETE FROM Escreve WHERE Escreve.Autor_CodAutor=%d",codAutor);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void excluirAmigo(void){
    
    int codAmigo;
    char aux[301];
      
    printf("\n*****EXCLUIR AMIGO*****\n");
    printf("\nDigite o código do Amigo:\n");
      scanf("%d",&codAmigo);
  
   sprintf(aux,"DELETE FROM Amigo WHERE Amigo.CodAmigo=%d",codAmigo);
    resultado(aux);
    
   /***EXCLUI TAMBEM EM EMPRESTA***/
   sprintf(aux,"DELETE FROM Empresta WHERE Empresta.Amigo_CodAmigo=%d",codAmigo);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void excluirEmprestimo(void){
    
    int codEmprest;
    char aux[201]; 
    int opc;
    
    printf("Código do emprestimo:\n");
      scanf("%d",&codEmprest);
 	
   sprintf(aux,"DELETE FROM Empresta WHERE Empresta.CodEmprest= %d",codEmprest);
     resultado(aux);
    printf("Atualização do status. Digite os campos abaixo\n"); 
   /*chama a funcao para alterar status*/
   livroAlterarStatus();
}
/*--------------------------------------------------------------------------*/
void excluirCompra(void){
    
    int codLivro, codLivraria, opc;
    char aux[501]; 
    
    printf("\n*****EXCLUIR COMPRA*****\n");
    printf("Deseja consultar o código do livro(Tecle 1 para sim ou 0 para nao)?\n");
      scanf("%d",&opc);
        if(opc==1)
          consultarTudoLivro(); 
    printf("\n Código do Livro:\n");
    scanf("%d",&codLivro);
    printf("Deseja consultar o código da livraria(Tecle 1 para sim ou 0 para nao)?\n");
      scanf("%d",&opc);
        if(opc==1)
          consultarTudoLivraria(); 
    printf("\n Código da Livraria:\n");
    scanf("%d",&codLivraria);
	
    sprintf(aux,"DELETE FROM Compra WHERE Compra.Livro_CodLivro= %d AND Compra.Livraria_CodLivraria= %d",codLivro, codLivraria);
     resultado(aux);
} 
/*--------------------------------------------------------------------------*/


     
    
    
    
    
    
    
    
    
    
    
    
    
