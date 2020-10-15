#include "FBiblioteca.h"

MYSQL conex;


void menuConsultar(void){
    int opc;
    while(1){
        
        printf("\n******************\n");	
        printf("***CONSULTAS GERAIS***\n");
        printf("******************\n");
        printf("Digite uma opção:\n");
        printf("[1]LIVRO\n");
        printf("[2]LIVRARIA\n");
        printf("[3]AUTOR\n");
        printf("[4]AMIGO\n");
        printf("[5]EMPRESTIMO\n");
        printf("[6]COMPRA\n");
        printf("[7]RETORNAR AO MENU PRINCIPAL\n");
        
        scanf("%d", &opc);
        
        switch (opc){
            case 1: consultarLivro();
                break;
            case 2: consultarLivraria();
                break;
            case 3: consultarAutor();
                break;
            case 4: consultarAmigo();
                break;
            case 5: menuConsultarEmprestimo();
                break;
            case 6: consultarCompra();
                break;
            case 7: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }
    
}
/*--------------------------------------------------------------------------*/
void menuConsultarEmprestimo(void){
 
    int opc;
    while(1){
        printf("Digite uma opção:\n"); 
        printf("[0]Consultar todos os emprestimos\n");
        printf("[1]Consultar um emprestimo especifico\n");
        printf("[2]Menu de consulta\n");
        printf("[3]Menu incluir\n");
        printf("[4]RETORNAR AO MENU PRINCIPAL\n");
          scanf("%d", &opc);
          
        switch (opc){
           case 0: consultarTudoEmprestimo();
             break;
           case 1: consultarEmprestimo();
             break;
           case 2: menuConsultar();
                break;
           case 3: menuIncluir();
                break;
           case 4: menuPrincipal();
                break;
           default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }
}
/*--------------------------------------------------------------------------*/
void consultarLivro(void){
    
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int codLivro, res, opc; 
    unsigned int row=0;
    char aux[500];
    
    printf("\n*****CONSULTAR LIVRO*****\n");
    printf("Deseja consultar o código do livro(Tecle 1 para sim ou 0 para nao)?\n");
     scanf("%d",&opc);
      if(opc==1)
        consultarTudoLivro();    
    printf("Digite o código do Livro:\n");
        scanf("%d",&codLivro);
      
    sprintf(aux,"SELECT* from Livro where CodLivro=%d", codLivro);
    res = mysql_query(&conex, aux);
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
			while ((sqlrow = mysql_fetch_row(res_ptr))) {
                          printf("|========|===========|====|======|================|===|========|========|\n");
                          printf("|CodLivro| Categoria | Ano|Edicao|     Titulo     |npg| Editora| Status |\n");
                          printf("|========|===========|====|======|================|===|========|========|\n");
                            for (row=0; row< mysql_field_count(&conex); row++) {
       				printf("| %s  ", sqlrow[row]);
                              }
                             printf("\n"); 
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                }
		mysql_free_result(res_ptr);
	}
}
/*--------------------------------------------------------------------------*/
void consultarLivraria(void){
    
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int codLivraria, res, opc; 
    unsigned int row=0;
    char aux[600];
    
    printf("\n*****CONSULTAR LIVRARIA*****\n");
    printf("Deseja consultar o código da livraria? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
          consultarTudoLivraria(); 
    printf("Digite o código da Livraria:\n");
        scanf("%d",&codLivraria);
        
    sprintf(aux,"SELECT* from Livraria where CodLivraria=%d", codLivraria);
    res = mysql_query(&conex, aux);
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
			while ((sqlrow = mysql_fetch_row(res_ptr))) {
                          printf("|=========|=========|======|======|=====|===|========|===|=====|========|======|\n");
                          printf("|CodLivrar| TelFixo | RSoc | Nome |Rua  |num| Cidade | UF| Fax | eMail  |Site  |\n");
                          printf("|=========|=========|======|======|=====|===|========|===|=====|========|======|\n");
                            for (row=0; row< mysql_field_count(&conex); row++) {
       				
                                printf("| %s  ", sqlrow[row]);
                              }
                         printf("\n");     
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                }
		mysql_free_result(res_ptr);
	}
}
/*--------------------------------------------------------------------------*/
void consultarAutor(void){
     
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int codAutor, res, opc; 
    unsigned int row=0;
    char aux[500];
    
    printf("\n*****CONSULTAR AUTOR*****\n");
    printf("Deseja consultar o código do autor? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
          consultarTudoAutor(); 
      printf("Digite o código do Autor:\n");
        scanf("%d",&codAutor);
        
    sprintf(aux,"SELECT* from Autor where CodAutor=%d", codAutor);
    res = mysql_query(&conex, aux);
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
			while ((sqlrow = mysql_fetch_row(res_ptr))) {
                          printf("|========|=========|=====|=======|\n");
                          printf("|CodAutor| Pnome   |Mnome| Unome |\n");
                          printf("|========|=========|=====|=======|\n");
                            for (row=0; row< mysql_field_count(&conex); row++) {
       				
                                printf("| %s  ", sqlrow[row]);
                              }
                         printf("\n");     
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                }
		mysql_free_result(res_ptr);
	}
}
/*--------------------------------------------------------------------------*/
void consultarAmigo(void){

    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int codAmigo, res, opc; 
    unsigned int row=0;
    char aux[500];
    
    printf("\n*****CONSULTAR AMIGO*****\n");
    printf("Deseja consultar o código do amigo? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
          consultarTudoAmigo(); 
    printf("Digite o código do Amigo:\n");
        scanf("%d",&codAmigo);
        
    sprintf(aux,"SELECT* from Amigo where CodAmigo=%d", codAmigo);
    res = mysql_query(&conex, aux);
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
			while ((sqlrow = mysql_fetch_row(res_ptr))) {
                          printf("|========|==========|=====|======|==========|========|======== |========|\n");
                          printf("|CodAmigo|  Pnome   |Mnome| Unome| Celular  |TelFixo | TelTrab | eMail  |\n");
                          printf("|========|==========|=====|======|==========|========|======== |========|\n");
                            for (row=0; row< mysql_field_count(&conex); row++) {
       				
                                printf("| %s  ", sqlrow[row]);
                              }
                        printf("\n");      
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                }
		mysql_free_result(res_ptr);
	}
}
/*--------------------------------------------------------------------------*/
void consultarCompra(void){

    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int codLivraria, codLivro, opc, res; 
    unsigned int row=0;
    char aux[1000];
    
    printf("\n*****CONSULTAR COMPRA*****\n");
    printf("Deseja consultar o código da livraria? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
          consultarTudoLivraria(); 
    printf("Digite o código da Livraria:\n");
        scanf("%d",&codLivraria);
    
    printf("Deseja consultar o código do livro? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
       if(opc==1)
         consultarTudoLivro();    
    printf("Digite o código do Livro:\n");
        scanf("%d",&codLivro);
        
    sprintf(aux,"SELECT* from Compra where Livro_CodLivro=%d AND Livraria_CodLivraria=%d", codLivro, codLivraria);
    res = mysql_query(&conex, aux);
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
			while ((sqlrow = mysql_fetch_row(res_ptr))) {
                          printf("|========|==========|============|======|\n");
                          printf("|CodLivro| CodLivrar|  DtCompra  |Preco |\n");
                          printf("|========|==========|============|======|\n");
                            for (row=0; row< mysql_field_count(&conex); row++) {
       				
                                printf("| %s  ", sqlrow[row]);
                              }
                        printf("\n");      
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                }
		mysql_free_result(res_ptr);
	}    
}
/*--------------------------------------------------------------------------*/

void consultarEmprestimo(void){

    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int codEmprest, res, opc; 
    unsigned int row=0;
    char aux[1500];
     
    printf("\n*****CONSULTAR EMPRÉSTIMO*****\n");
    printf("Deseja consultar o código do emprestimo? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
          consultarTudoEmprestimo(); 
    printf("Código do emprestimo:\n");
      scanf("%d",&codEmprest);
       
    sprintf(aux,"SELECT* from Empresta where codEmprest=%d", codEmprest);
    res = mysql_query(&conex, aux);
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
			while ((sqlrow = mysql_fetch_row(res_ptr))) {
                          printf("|=========|========|==========|============|===========|==============|\n");
                          printf("|CoEmprest|CodAmigo|  CodLivro|DtEmprestimo|DtDevolucao|DtDevPrevista |\n");
                          printf("|=========|========|==========|============|===========|==============|\n");
                            for (row=0; row< mysql_field_count(&conex); row++) {
       				
                                printf("| %s  ", sqlrow[row]);
                              }
                         printf("\n");     
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                }
		mysql_free_result(res_ptr);
	}    
}
/*--------------------------------------------------------------------------*/
void consultarTudoEmprestimo(void){

    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int codEmprest, res; 
    unsigned int row=0;
    char aux[1500];
    
    sprintf(aux,"SELECT * from Empresta");
    res = mysql_query(&conex, aux);
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
			printf("|==========|========|==========|============|===========|==============|\n");
                        printf("|CodEmprest|CodAmigo|  CodLivro|DtEmprestimo|DtDevolucao|DtDevPrevista |\n");
                        printf("|==========|========|==========|============|===========|==============|\n");
                        while ((sqlrow = mysql_fetch_row(res_ptr))) {
                            for (row=0; row< mysql_field_count(&conex); row++) {
       			        printf("| %s  ", sqlrow[row]);
                              }
                         printf("\n");     
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                }
		mysql_free_result(res_ptr);
	}    
}
/*--------------------------------------------------------------------------*/
    void consultarTudoLivro(void){
    
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int res; 
    unsigned int row=0;
    char aux[500];
    
    printf("\n*****CONSULTAR TODOS OS LIVRO*****\n");
          
    sprintf(aux,"SELECT* from Livro");
    res = mysql_query(&conex, aux);
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
		   printf("|========|===========|====|======|================|===|========|========|\n");
                   printf("|CodLivro| Categoria | Ano|Edicao|     Titulo     |npg| Editora| Status |\n");
                   printf("|========|===========|====|======|================|===|========|========|\n");
                    while ((sqlrow = mysql_fetch_row(res_ptr))) {
                       for (row=0; row< mysql_field_count(&conex); row++) {
                            printf("| %s  ", sqlrow[row]);
                        }
                             printf("\n"); 
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		      }
                 }
		mysql_free_result(res_ptr);
	}
}
 /*--------------------------------------------------------------------------*/   
void consultarTudoAmigo(void){

    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int res; 
    unsigned int row=0;
    char aux[500];
    
    printf("\n*****CONSULTAR TODOS OS AMIGOS*****\n");
            
    sprintf(aux,"SELECT* from Amigo");
    res = mysql_query(&conex, aux);
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
		  printf("|========|==========|=====|======|==========|========|======== |========|\n");
                  printf("|CodAmigo|  Pnome   |Mnome| Unome| Celular  |TelFixo | TelTrab | eMail  |\n");
                  printf("|========|==========|=====|======|==========|========|======== |========|\n");	
                      while ((sqlrow = mysql_fetch_row(res_ptr))) {
                          for (row=0; row< mysql_field_count(&conex); row++) {
       			    printf("| %s  ", sqlrow[row]);
                              }
                        printf("\n");      
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                }
		mysql_free_result(res_ptr);
	}
}
 /*--------------------------------------------------------------------------*/
void consultarTudoAutor(void){
     
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int res; 
    unsigned int row=0;
    char aux[500];
    
    printf("\n*****CONSULTAR TODOS OS AUTORES*****\n");
        
    sprintf(aux,"SELECT* from Autor");
    res = mysql_query(&conex, aux);
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
		   printf("|========|=========|=====|=======|\n");
                   printf("|CodAutor| Pnome   |Mnome| Unome |\n");
                   printf("|========|=========|=====|=======|\n");	
                    while ((sqlrow = mysql_fetch_row(res_ptr))) {
                         for (row=0; row< mysql_field_count(&conex); row++) {
       				printf("| %s  ", sqlrow[row]);
                              }
                         printf("\n");     
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                }
		mysql_free_result(res_ptr);
	}
}
/*--------------------------------------------------------------------------*/
void consultarTudoLivraria(void){
    
    MYSQL_RES* res_ptr;
    MYSQL_ROW sqlrow;
    
    int res; 
    unsigned int row=0;
    char aux[600];
    
    printf("\n*****CONSULTAR TODAS AS LIVRARIAS*****\n");
         
    sprintf(aux,"SELECT* from Livraria");
    res = mysql_query(&conex, aux);
	
	if (res) 
		printf("SELECT error: %s\n", mysql_error(&conex));
	else {
		res_ptr = mysql_store_result(&conex);
		if (res_ptr) {
		  printf("|=========|=========|======|======|=====|===|========|===|=====|========|======|\n");
                  printf("|CodLivrar| TelFixo | RSoc | Nome |Rua  |num| Cidade | UF| Fax | eMail  |Site  |\n");
                  printf("|=========|=========|======|======|=====|===|========|===|=====|========|======|\n");
                          while ((sqlrow = mysql_fetch_row(res_ptr))) {
                            for (row=0; row< mysql_field_count(&conex); row++) {
       			      printf("| %s  ", sqlrow[row]);
                              }
                         printf("\n");     
			if (mysql_errno(&conex)) 
				printf("Retrive error: %s\n", mysql_error(&conex));	  
		         }
                }
		mysql_free_result(res_ptr);
	}
}
/*--------------------------------------------------------------------------*/