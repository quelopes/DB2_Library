#include "FBiblioteca.h"

MYSQL conex;

void menuRelatorio(void){

    int opc;
    printf("\n******************\n");	
    printf("***RELATÓRIOS***\n");
    printf("******************\n");
    printf("Digite uma opcao:\n");
    printf("[1]GASTOS EM LIVROS POR MÊS\n");
    printf("[2]TOTAL INVESTIDO EM LIVROS\n"); 
    printf("[3]LIVROS SOBRE UMA CATEGORIA\n");
    printf("[4]LISTA DE EMPRESTIMOS NÃO DEVOLVIDOS NA DATA\n");
    printf("[5]CONSULTA A UM DETERMINADO LIVRO\n");
    printf("[6]RETORNAR AO MENU PRINCIPAL\n\n");      
      scanf("%d",&opc);
	   
    switch (opc){
            case 1: relatorioGastMes();
                break;
            case 2: relatorioTotalGast();
                break;
            case 3: relatorioLivroCat();
                break;
            case 4: relatorioEmptNDevDt();
                break;
            case 5: relatorioLivroNome();
                break;
            case 6: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }   
}
/*--------------------------------------------------------------------------*/
/*Gasto em um determinado mês em livros*/                                              
void relatorioGastMes(void){
     
    FILE* ptSaida;
    
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;

    int res; 
    unsigned int row=0;
    char aux[1000], mes[3];
    
    printf("Digite o mês correspondente:\n");
      scanf(" %3[^\n]",mes);
    sprintf(aux,"SELECT SUM(Preco) FROM Compra WHERE MONTH(dtCompra)='%s'",mes);
    res = mysql_query(&conex, aux);
    
    
    /**saida de relatorio em txt**/                
    ptSaida=fopen("investMesLivros.txt","w+t");
     if(ptSaida==NULL){
        printf("\n\n\nErro no arquivo!\n\n");
        exit(1);
     }
       	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
		   printf("|=======================================|\n");
                   printf("|    Gasto no mes: %s em Livros         |\n", mes);
                   printf("|=======================================|\n");	
                   fputs("|=======================================|\n|    Gasto no mes especifico em Livros         |\n|=======================================|\n",ptSaida);
                    while ((sqlrow = mysql_fetch_row(res_ptr))) {
                           for (row=0; row< mysql_field_count(&conex); row++) {
                                fputs(sqlrow[row],ptSaida);                                
       				printf("|%s  ", sqlrow[row]);
                              }
                             printf("\n");
                             fputs("\n",ptSaida); 
                     
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		    }
                   fclose(ptSaida);
                }
		mysql_free_result(res_ptr);
	}
}
/*--------------------------------------------------------------------------*/
/*Total investido em livros*/
void relatorioTotalGast(void){
    
    FILE* ptSaida;
    
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;

    int res; 
    unsigned int row=0;
    char aux[1000];
    
    sprintf(aux,"SELECT SUM(Preco) FROM Compra");
    res = mysql_query(&conex, aux);
    
    
    /**saida de relatorio em txt**/                
    ptSaida=fopen("investTotalLivros.txt","w+t");
     if(ptSaida==NULL){
        printf("\n\n\nErro no arquivo!\n\n");
        exit(1);
     }
       	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
		   printf("|=======================================|\n");
                   printf("|    Valor investido em compra de livros|\n");
                   printf("|=======================================|\n");	
                   fputs("|=======================================|\n|    Valor investido em compra de livros|\n|=======================================|\n",ptSaida);
                    while ((sqlrow = mysql_fetch_row(res_ptr))) {
                           for (row=0; row< mysql_field_count(&conex); row++) {
                                fputs(sqlrow[row],ptSaida);                                
       				printf("|%s  ", sqlrow[row]);
                              }
                             printf("\n");
                             fputs("\n",ptSaida); 
                     
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		    }
                   fclose(ptSaida);
                }
		mysql_free_result(res_ptr);
	}
}
/*--------------------------------------------------------------------------*/
/*Quantidade de livros sobre uma determinada categoria*/
void relatorioLivroCat(void){
    
    FILE* ptSaida;
    
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int res; 
    unsigned int row=0;
    char aux[1000], categoria[20];
    
    printf("Digite a categoria desejada:\n");
      scanf(" %20[^\n]", categoria);
      
    sprintf(aux,"SELECT COUNT(*) FROM Livro WHERE Categoria='%s'",categoria);
    res = mysql_query(&conex, aux);
	
    /**saida de relatorio em txt**/                
    ptSaida=fopen("qtCategLivro.txt","w+t");
     if(ptSaida==NULL){
        printf("\n\n\nErro no arquivo!\n\n");
        return 0;
     }
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
		   printf("|=======================================|\n");
                   printf("|Total de livros da categoria '%s'      |\n", categoria);
                   printf("|=======================================|\n");
                   fputs("|=======================================|\n|Total de livros da categoria solicitada      |\n|=======================================|\n", ptSaida);
                    while ((sqlrow = mysql_fetch_row(res_ptr))) {
                           for (row=0; row< mysql_field_count(&conex); row++) {
       			       fputs(sqlrow[row],ptSaida);     
                               printf("|%s  ", sqlrow[row]);
                              }
                          printf("\n");
                          fputs("\n",ptSaida);      
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                   fclose(ptSaida);
                }
		mysql_free_result(res_ptr);
	}
}
/*--------------------------------------------------------------------------*/
/*Livros com data de emprestimo prevista menores que a data atual*/
void relatorioEmptNDevDt(void){                                                  

    
   /* FILE* ptSaida;*/
    
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int res; 
    unsigned int row=0;
    char aux[1000];
    
    sprintf(aux,"SELECT * FROM Empresta WHERE TO_DAYS(NOW()) - TO_DAYS(DtDevPrevista)>1");
    res = mysql_query(&conex, aux);
	
    /**saida de relatorio em txt**/                
   /* ptSaida=fopen("naoDevolvido.txt","w+t");
     if(ptSaida==NULL){
        printf("\n\n\nErro no arquivo!\n\n");
        return 0;
     }
    */
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
		   printf("\t\tAmigos que ainda não devolveram o livro ou atrasam na devolução:\n");
                    printf("|========|==========|============|===========|==============|\n");
                    printf("|CodAmigo|  CodLivro|DtEmprestimo|DtDevolucao|DtDevPrevista |\n");
                    printf("|========|==========|============|===========|==============|\n");
                   /*fputs("\t\tAmigos que ainda não devolveram o livro:\n|========|==========|============|===========|==============|\n|CodAmigo|  CodLivro|DtEmprestimo|DtDevolucao|DtDevPrevista |\n|========|==========|============|===========|==============|\n", ptSaida);*/
                   while ((sqlrow = mysql_fetch_row(res_ptr))) {
                           for (row=0; row< mysql_field_count(&conex); row++) {
       			       /*fputs(sqlrow[row],ptSaida); */    
                               printf("|%s  ", sqlrow[row]);
                              }
                          printf("\n");
                          /*fputs("\n",ptSaida); */   
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                  /* fclose(ptSaida);*/
                }
		mysql_free_result(res_ptr);
	}
}
/*--------------------------------------------------------------------------*/
/*Tenho um determinado livro?*/                                                  
void relatorioLivroNome(void){                                                    

    FILE* ptSaida;
    
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int res; 
    unsigned int row=0;
    char aux[1000], nomeLivro[45];
    
    printf("Digite o titulo do livro:\n");
      scanf(" %46[^\n]", nomeLivro);
      
    sprintf(aux,"SELECT * FROM Livro WHERE Titulo='%s'",nomeLivro);
    res = mysql_query(&conex, aux);
    
    /****************saida de relatorio em txt*/                
    ptSaida=fopen("TituloLivro.txt","w+t");
     if(ptSaida==NULL){
        printf("\n\n\nErro no arquivo!\n\n");
        return 0;
     }
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));                  
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
                  printf("|========|===========|====|======|================|===|========|========|\n");
                  printf("|CodLivro| Categoria | Ano|Edicao|     Titulo     |npg| Editora| Status |\n");
                  printf("|========|===========|====|======|================|===|========|========|\n");
                  fputs("|========|===========|====|======|================|===|========|========|\n|CodLivro| Categoria | Ano|Edicao|     Titulo     |npg| Editora| Status |\n|========|===========|====|======|================|===|========|========|\n", ptSaida);
                    while ((sqlrow = mysql_fetch_row(res_ptr))) {
                           for (row=0; row< mysql_field_count(&conex); row++) {
       			       fputs(sqlrow[row],ptSaida);     
                               printf("|%s  ", sqlrow[row]);
                              }
                            printf("\n");
                            fputs("\n",ptSaida);    
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                   fclose(ptSaida);
                }
		mysql_free_result(res_ptr);
	}
}
/*--------------------------------------------------------------------------*/