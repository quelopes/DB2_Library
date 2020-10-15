#include "FBiblioteca.h"

MYSQL conex;

void menuAlterar(void){
    
    int opc;
    while(1){
        
        printf("\n******************\n");	
        printf("***ALTERAR***\n");
        printf("******************\n");
        printf("Digite uma opção:\n");
        printf("[1]LIVRO\n");
        printf("[2]LIVRARIA\n");
        printf("[3]AUTOR\n");
        printf("[4]AMIGO\n");
        printf("[5]EMPRESTIMO\n");
        printf("[6]COMPRA\n");
        printf("[7]ESCREVE\n");
        printf("[8]RETORNAR AO MENU PRINCIPAL\n");
        
        scanf("%d", &opc);
        
        switch (opc){
            case 1: alterarMenuLivro();
                break;
            case 2: alterarMenuLivraria();
                break;
            case 3: alterarMenuAutor();
                break;
            case 4: alterarMenuAmigo();
                break;
            case 5: alterarMenuEmprestimo();
                break;
            case 6: alterarMenuCompra();
                break;
            case 7: alterarMenuEscreve();
                break;    
            case 8: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }
    
}
/*--------------------------------------------------------------------------*/
void alterarMenuLivro(void){
    
    int opc;
    while(1){
        
        printf("\nDigite o campo que deseja ALTERAR LIVRO:\n");
        printf("[1]Categoria\n"); 
        printf("[2]Ano\n");
        printf("[3]Edicao\n");
        printf("[4]Titulo\n");
        printf("[5]No_pg\n");
        printf("[6]Editora\n");
        printf("[7]Status\n");
        printf("[8]RETORNAR AO MENU ALTERAR\n");
        printf("[9]RETORNAR AO MENU PRINCIPAL\n");
        
        scanf("%d", &opc);
        
        switch (opc){
            case 1: livroAlterarCateg();
                break;
            case 2: livroAlterarAno();
                break;
            case 3: livroAlterarEdicao();
                break;
            case 4: livroAlterarTitulo();
                break;
            case 5: livroAlterarNo_pg();
                break;
            case 6: livroAlterarEditora();
                break;
            case 7: livroAlterarStatus();
                break;
            case 8: menuAlterar();
                break;
            case 9: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }  
}
/*--------------------------------------------------------------------------*/
void alterarMenuLivraria(void){
    
    int opc;
    while(1){
        
        printf("\nDigite o campo que deseja ALTERAR LIVRARIA:\n");
        printf("[1]Razao Social\n");
        printf("[2]Nome\n");        
        printf("[3]Endereço\n");
        printf("[4]Tel Fixo\n");
        printf("[5]Fax\n");
        printf("[6]eMail\n");
        printf("[7]Site\n");
        printf("[8]RETORNAR AO MENU ALTERAR\n");
        printf("[9]RETORNAR AO MENU PRINCIPAL\n");
        
        scanf("%d", &opc);
        
        switch (opc){
            case 1: livrarAlterarRazSoc();
                break;
            case 2: livrarAlterarNome();
                break;
            case 3: livrarAlterarEndereco();
                break;
             case 4: livrarAlterarTelFixo();
                break;
            case 5: livrarAlterarFax();
                break;
            case 6: livrarAlterarEMail();
                break;
            case 7: livrarAlterarSite();
                break;
            case 8: menuAlterar();
                break;
            case 9: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
       }
    }  
}
/*--------------------------------------------------------------------------*/
void alterarMenuAutor(void){
     
    int opc;
    while(1){
        
        printf("\nDigite o campo que deseja ALTERAR AUTOR:\n");
        printf("[1]Primeiro nome\n"); 
        printf("[2]Nome do meio \n");
        printf("[3]Ultimo nome\n");
        printf("[4]RETORNAR AO MENU ALTERAR\n");
        printf("[5]RETORNAR AO MENU PRINCIPAL\n");
        
        scanf("%d", &opc);
        
        switch (opc){
            case 1: autorAlterarPnome();
                break;
            case 2: autorAlterarMnome();
                break;
            case 3: autorAlterarUnome();
                break;
            case 4: menuAlterar();
                break;
            case 5: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }  
       
}
/*--------------------------------------------------------------------------*/
void alterarMenuAmigo(void){
    
    int opc;
    while(1){
        
        printf("\nDigite o campo que deseja ALTERAR AMIGO:\n");
        printf("[1]Primeiro nome\n"); 
        printf("[2]Nome do meio \n");
        printf("[3]Ultimo nome\n");
        printf("[4]Celular\n");
        printf("[5]Tel Fixo\n");
        printf("[6]eMail\n");
        printf("[7]RETORNAR AO MENU ALTERAR\n");
        printf("[8]RETORNAR AO MENU PRINCIPAL\n");
        
        scanf("%d", &opc);
        
        switch (opc){
            case 1: amigoAlterarPnome();
                break;
            case 2: amigoAlterarMnome();
                break;
            case 3: amigoAlterarUnome();
                break;
             case 4: amigoAlterarCel();
                break;
            case 5: amigoAlterarTelFixo();
                break;
            case 6: amigoAlterarEMail();
                break;    
            case 7: menuAlterar();
                break;
            case 8: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }  
}
/*--------------------------------------------------------------------------*/
void alterarMenuEmprestimo(void){
    
    int opc;
    while(1){
        
        printf("\nDigite o campo que deseja ALTERAR EMPRESTIMO:\n");
        printf("[1]Data Devolucao Prevista\n"); 
        printf("[2]Data Devolucao\n");
        printf("[4]RETORNAR AO MENU ALTERAR\n");
        printf("[5]RETORNAR AO MENU PRINCIPAL\n");
        
        scanf("%d", &opc);
        
        switch (opc){
            case 1: emptAlterarDtDevPrev();
                break;
            case 2: emptAlterarDtDev();
                break;
            case 4: menuAlterar();
                break;
            case 5: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }  
}
/*--------------------------------------------------------------------------*/
void alterarMenuCompra(void){
    
    int opc;
    while(1){
        
        printf("\nDigite o campo que deseja ALTERAR COMPRA:\n");
        printf("[1]Data Compra\n");
        printf("[2]Preço\n"); 
        printf("[3]Codigo do Livro\n");
        printf("[4]Codigo da Livraria\n");
        printf("[5]RETORNAR AO MENU ALTERAR\n");
        printf("[6]RETORNAR AO MENU PRINCIPAL\n");
        
        scanf("%d", &opc);
        
        switch (opc){
            case 1: compraAlterarDtComp();
                break;
            case 2: compraAlterarPreco();
                break;
            case 3: compraAlterarCodLivro();
                break;
            case 4: compraAlterarCodLivrar();
                break;
            case 5: menuAlterar();
                break;
            case 6: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }  
}
/*--------------------------------------------------------------------------*/
void alterarMenuEscreve(void){
   
    int opc;
    while(1){
        
        printf("\nDigite o campo que deseja ALTERAR ESCREVE(referente ao autor):\n");
        printf("[1]Codigo Livro\n");
        printf("[2]Codigo Autor\n"); 
        printf("[3]RETORNAR AO MENU ALTERAR\n");
        printf("[4]RETORNAR AO MENU PRINCIPAL\n");
        
        scanf("%d", &opc);
        
        switch (opc){
            case 1: escreveAlterarCodLivro();
                break;
            case 2: escreveAlterarCodAutor();
                break;
            case 3: menuAlterar();
                break;
            case 4: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }  
}
/*--------------------------------------------------------------------------*/
void livroAlterarCateg(void){
        
    int codLivro, opc;
    char categoria[16], aux[120];
    
    printf("Deseja consultar o código do livro? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
        consultarTudoLivro();
      
    printf("Código do livro:\n");
	scanf("%d",&codLivro);
    printf("NOVA Categoria:\n ");
	scanf(" %16[^\n]",categoria);
				
    sprintf(aux,"UPDATE Livro SET Categoria='%s' WHERE CodLivro=%d",categoria, codLivro);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void livroAlterarAno(void){
    
   int codLivro, ano, opc;
   char aux[120];
   
   printf("Deseja consultar o código do livro? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
        consultarTudoLivro();	
      
    printf("Qual o codigo do livro?\n");
      scanf("%d",&codLivro);
    printf("NOVO Ano:\n");
      scanf("%d",&ano);
				
    sprintf(aux,"UPDATE Livro SET Ano=%d WHERE CodLivro=%d",ano, codLivro);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void livroAlterarEdicao(void){

    int codLivro, edicao, opc;
    char aux[120];
    
    printf("Deseja consultar o código do livro? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
        consultarTudoLivro();	
      
    printf("Qual o codigo do livro?\n");
      scanf("%d",&codLivro);
    printf("NOVA Edição:\n");
      scanf("%d",&edicao);
				
    sprintf(aux,"UPDATE Livro SET Edicao=%d WHERE CodLivro=%d",edicao, codLivro);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void livroAlterarTitulo(void){
    
    int codLivro, opc;
    char titulo[46], aux[120];
    
    printf("Deseja consultar o código do livro? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
        consultarTudoLivro();	  
      
    printf("Informe o código do livro:\n");
	scanf("%d",&codLivro);
    printf("NOVO Título:\n ");
	scanf(" %46[^\n]",titulo);
				
    sprintf(aux,"UPDATE Livro SET Titulo='%s' WHERE CodLivro=%d",titulo, codLivro);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void livroAlterarNo_pg(void){
  
    int codLivro, numPg, opc;
    char aux[120];
    
    printf("Deseja consultar o código do livro? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
        consultarTudoLivro();	
      
    printf("Qual o codigo do livro?\n");
      scanf("%d",&codLivro);
    printf("NOVO Número de páginas:\n");
      scanf("%d",&numPg);
				
    sprintf(aux,"UPDATE Livro SET numPg=%d WHERE CodLivro=%d",numPg, codLivro);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void livroAlterarEditora(void){

    int codLivro, opc;
    char editora[46], aux[120];
	    
    printf("Deseja consultar o código do livro? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
        consultarTudoLivro();
      
    printf("Informe o código do livro:\n");
	scanf("%d",&codLivro);
    printf("NOVA Editora:\n ");
	scanf(" %46[^\n]",editora);
				
    sprintf(aux,"UPDATE Livro SET Editora='%s' WHERE CodLivro=%d",editora, codLivro);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void livroAlterarStatus(void){
    
    int status, codLivro, opc;
    char aux[120];
    
    printf("Deseja consultar o código do livro? (Tecle [1]Sim ou [0]Nao):\n");
     scanf("%d",&opc);
        if(opc==1)
        consultarTudoLivro();    
    printf("Informe o código do livro:\n");
      scanf("%d",&codLivro);
    printf("NOVO Status(0 disponivel ou 1 emprestado):\n ");
      scanf("%d", &status);
				
    sprintf(aux,"UPDATE Livro SET Status_2=%d WHERE CodLivro=%d",status, codLivro);
    resultado(aux);
}

/****************************************************************************/

void livrarAlterarRazSoc(void){
    
    int codLivraria;
    float razSoc;
    char aux[120];
	
    printf("Código da livraria:\n");
      scanf("%d",&codLivraria);
    printf("NOVA Razão social(número):\n");
      scanf("%f",&razSoc);
				
    sprintf(aux,"UPDATE Livraria SET RazaoSocial=%f WHERE CodLivraria=%d",razSoc, codLivraria);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void livrarAlterarNome(void){
    
    int codLivraria;
    char nome[46], aux[120];
	    
    printf("Código da livraria:\n");
	scanf("%d",&codLivraria);
    printf("NOVO Nome livraria:\n ");
	scanf(" %46[^\n]",nome);
				
    sprintf(aux,"UPDATE Livraria SET Nome='%s' WHERE CodLivraria=%d",nome, codLivraria);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void livrarAlterarEndereco(void){
   
    int codLivraria, res;
    int num;
    char rua[21],  cidade[21], uf[3];
    char aux1[120],aux2[120],aux3[120],aux4[120];
    int res1, res2, res3, res4;
    
    printf("Código da livraria:\n");
      scanf("%d",&codLivraria);
    printf("NOVA Rua:\n");
      scanf(" %21[^\n]",rua);
    printf("NOVO Numero:\n");
      scanf("%d",&num);
    printf("NOVA Cidade:\n");
      scanf(" %21[^\n]",cidade);
    printf("NOVO Estado:\n");
      scanf(" %3[^\n]",uf);
    
   
    sprintf(aux1,"UPDATE Livraria SET Rua='%s' WHERE CodLivraria=%d",rua,codLivraria);
    sprintf(aux2,"UPDATE Livraria SET Num='%f' WHERE CodLivraria=%d",num,codLivraria);
    sprintf(aux3,"UPDATE Livraria SET Cidade='%s' WHERE CodLivraria=%d",cidade,codLivraria);
    sprintf(aux4,"UPDATE Livraria SET UF='%s' WHERE CodLivraria=%d",uf,codLivraria);
   
    res1 = mysql_query(&conex,aux1);
    res2 = mysql_query(&conex,aux2);
    res3 = mysql_query(&conex,aux3);
    res4 = mysql_query(&conex,aux4);

    if (!res1||!res2||!res3||!res4) 
        printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(&conex));
    else 
	printf("Update error %d: %s\n", mysql_errno(&conex), mysql_error(&conex));
}
/*--------------------------------------------------------------------------*/
void livrarAlterarTelFixo(void){
    
    int codLivraria, teleFixo;
    char aux[120];
	
    printf("Código da livraria:\n");
      scanf("%d",&codLivraria);
    printf("NOVO Telefone Fixo:\n");
      scanf("%d",&teleFixo);
				
    sprintf(aux,"UPDATE Livraria SET TelFixo=%d WHERE CodLivraria=%d",teleFixo, codLivraria);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void livrarAlterarFax(void){
    
    int codLivraria, fax;
    char aux[120];
	
    printf("Código da livraria:\n");
      scanf("%d",&codLivraria);
    printf("NOVO Fax:\n");
      scanf("%d",&fax);
				
    sprintf(aux,"UPDATE Livraria SET Fax=%d WHERE CodLivraria=%d",fax, codLivraria);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void livrarAlterarEMail(void){

    int codLivraria;
    char email[21], aux[120];
	    
    printf("Código da livraria:\n");
	scanf("%d",&codLivraria);
    printf("NOVO E-mail:\n ");
	scanf(" %21[^\n]",email);
				
    sprintf(aux,"UPDATE Livraria SET eMail='%s' WHERE CodLivraria=%d",email, codLivraria);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void livrarAlterarSite(void){

    int codLivraria;
    char site[46], aux[120];
	    
    printf("Código do livro:\n");
	scanf("%d",&codLivraria);
    printf("NOVO Site:\n ");
	scanf(" %46[^\n]",site);
				
    sprintf(aux,"UPDATE Livraria SET Site='%s' WHERE CodLivraria=%d",site, codLivraria);
    resultado(aux);
}

/****************************************************************************/

void autorAlterarPnome(void){
  
    int codAutor;
    char pNome[46], aux[120];
	    
    printf("Código do autor:\n");
	scanf("%d",&codAutor);
    printf("NOVO Primeiro nome:\n ");
	scanf(" %46[^\n]",pNome);
				
    sprintf(aux,"UPDATE Autor SET Pnome='%s' WHERE CodAutor=%d",pNome, codAutor);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void autorAlterarMnome(void){
 
    int codAutor;
    char mNome[3], aux[120];
	    
    printf("Código do autor:\n");
	scanf("%d",&codAutor);
    printf("NOVO Nome do meio:\n ");
	scanf(" %3[^\n]",mNome);
				
    sprintf(aux,"UPDATE Autor SET Mnome='%s' WHERE CodAutor=%d",mNome, codAutor);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void autorAlterarUnome(void){
  
    int codAutor;
    char uNome[46], aux[120];
	    
    printf("Código do autor:\n");
	scanf("%d",&codAutor);
    printf("NOVO Último nome:\n ");
	scanf(" %46[^\n]",uNome);
				
    sprintf(aux,"UPDATE Autor SET Unome='%s' WHERE CodAutor=%d",uNome, codAutor);
    resultado(aux);
}

/****************************************************************************/

void amigoAlterarPnome(void){
    
    int codAmigo;
    char pNome[46], aux[120];
	    
    printf("Código do amigo:\n");
	scanf("%d",&codAmigo);
    printf("NOVO Primeiro nome:\n ");
	scanf(" %46[^\n]",pNome);
				
    sprintf(aux,"UPDATE Amigo SET Pnome='%s' WHERE CodAmigo=%d",pNome, codAmigo);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void amigoAlterarMnome(void){
    
    int codAmigo;
    char mNome[3], aux[120];
	    
    printf("Código do amigo:\n");
	scanf("%d",&codAmigo);
    printf("NOVO Nome do meio:\n ");
	scanf(" %3[^\n]",mNome);
				
    sprintf(aux,"UPDATE Amigo SET Mnome='%s' WHERE CodAmigo=%d",mNome, codAmigo);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void amigoAlterarUnome(void){
    
    int codAmigo;
    char uNome[46], aux[120];
	    
    printf("Código do amigo:\n");
	scanf("%d",&codAmigo);
    printf("NOVO Último nome:\n ");
	scanf(" %46[^\n]",uNome);
				
    sprintf(aux,"UPDATE Amigo SET Unome='%s' WHERE CodAmigo=%d",uNome, codAmigo);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void amigoAlterarCel(void){

    int codAmigo, celular;
    char aux[120];
	
    printf("Código do amigo:\n");
      scanf("%d",&codAmigo);
    printf("NOVO Celular:\n");
      scanf("%d",&celular);
				
    sprintf(aux,"UPDATE Amigo SET Celular=%d WHERE CodAmigo=%d",celular, codAmigo);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void amigoAlterarTelFixo(void){
    
    int codAmigo, teleFixo;
    char aux[120];
	
    printf("Código do amigo:\n");
      scanf("%d",&codAmigo);
    printf("NOVO Telefone Fixo:\n");
      scanf("%d",&teleFixo);
				
    sprintf(aux,"UPDATE Amigo SET TeleFixo=%d WHERE CodAmigo=%d",teleFixo, codAmigo);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void amigoAlterarTelTrab(void){
    
    int codAmigo, teleTrab;
    char aux[120];
	
    printf("Código do amigo?\n");
      scanf("%d",&codAmigo);
    printf("NOVO Telefone do trabalho:\n");
      scanf("%d",&teleTrab);
				
    sprintf(aux,"UPDATE Amigo SET TelTrab=%d WHERE CodAmigo=%d",teleTrab, codAmigo);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void amigoAlterarEMail(void){
    
    int codAmigo;
    char email[46], aux[120];
	    
    printf("Código do amigo:\n");
	scanf("%d",&codAmigo);
    printf("NOVO E-mail:\n ");
	scanf(" %46[^\n]",email);
				
    sprintf(aux,"UPDATE Amigo SET eMail='%s' WHERE CodAmigo=%d",email, codAmigo);
    resultado(aux);
}

/****************************************************************************/

void emptAlterarDtDevPrev(void){
  
    int codEmprest;
    char aux[140], dtDevPrev[10];
	
    printf("Código do Emprestimo:\n");
      scanf("%d",&codEmprest);
    printf("NOVA data de devolução prevista:\n");
      scanf(" %10[^\n]",dtDevPrev);
				
    sprintf(aux,"UPDATE Empresta SET DtDevPrevista='%s' WHERE CodEmprest=%d",dtDevPrev, codEmprest);
    resultado(aux); 
}
/*--------------------------------------------------------------------------*/
void emptAlterarDtDev(void){                                                     
    
    int codEmprest, opc;
    char aux[140], dtDevol[10];
    
    printf("Deseja consultar o código de empréstimo? (Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
        if(opc==1)
        consultarTudoEmprestimo();    
    printf("Código do emprestimo:\n");
      scanf("%d",&codEmprest);
    printf("Devolução (data):\n");
      scanf(" %10[^\n]",dtDevol);
				
    sprintf(aux,"UPDATE Empresta SET DtDevolucao='%s' WHERE CodEmprest=%d",dtDevol, codEmprest);
    resultado(aux);
    
    printf("Atualização do status do livro. Informe os campos abaixo\n");
    /*Alterar tambem o status do livro*/
    livroAlterarStatus();
}

/****************************************************************************/

void compraAlterarDtComp(void){
    
    int codLivro, codLivraria;
    char aux[120], dtCompra[10];
	
    printf("Qual o codigo do livro?\n");
      scanf("%d",&codLivro);
    printf("Qual o codigo da livraria?\n");
      scanf("%d",&codLivraria);
    printf("NOVA data da compra:\n");
      scanf(" %10[^\n]",dtCompra);
				
    sprintf(aux,"UPDATE Compra SET DtCompra='%s' WHERE Livro_CodLivro=%d AND Livraria_CodLivraria=%f",dtCompra, codLivro, codLivraria);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void compraAlterarCodLivro(void){
    
    int codLivro, codLivraria, newcodLivro;
    char aux[120];
	
    printf("Qual o codigo do livro?\n");
      scanf("%d",&codLivro);
    printf("Qual o codigo da livraria?\n");
      scanf("%d",&codLivraria);
    printf("Novo codigo do Livro:\n");
      scanf("%d",&newcodLivro);
				
    sprintf(aux,"UPDATE Compra SET Livro_CodLivro=%d WHERE Livro_CodLivro=%d AND Livraria_CodLivraria=%f",newcodLivro, codLivro, codLivraria);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void compraAlterarPreco(void){
 
    int codLivro, codLivraria;
    float preco;
    char aux[120];
	
    printf("Qual o codigo do livro?\n");
      scanf("%d",&codLivro);
    printf("Qual o codigo da livraria?\n");
      scanf("%d",&codLivraria);
    printf("Preco:\n");
      scanf("%f",&preco);
				
    sprintf(aux,"UPDATE Compra SET Preco=%f WHERE Livro_CodLivro=%d AND Livraria_CodLivraria=%f",preco, codLivro, codLivraria);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void compraAlterarCodLivrar(void){
    
    int codLivro, codLivraria, newcodLivraria;
    char aux[120];
	
    printf("Qual o codigo do livro?\n");
      scanf("%d",&codLivro);
    printf("Qual o codigo da livraria?\n");
      scanf("%d",&codLivraria);
    printf("Novo codigo da Livraria:\n");
      scanf("%d",&newcodLivraria);
				
    sprintf(aux,"UPDATE Compra SET Livraria_CodLivraria=%d WHERE Livro_CodLivro=%d AND Livraria_CodLivraria=%f",newcodLivraria, codLivro, codLivraria);
     resultado(aux);
}

/****************************************************************************/

void escreveAlterarCodLivro(void){
   
    int codLivro, codAutor, newcodLivro;
    char aux[120];
	
    printf("Qual o codigo do livro?\n");
      scanf("%d",&codLivro);
    printf("Qual o codigo do autor?\n");
      scanf("%d",&codAutor);
    printf("Novo codigo do Livro:\n");
      scanf("%d",&newcodLivro);
				
    sprintf(aux,"UPDATE Escreve SET Livro_CodLivro=%d WHERE Autor_CodAutor=%d AND Livro_CodLivro=%d",newcodLivro, codAutor, codLivro);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
void escreveAlterarCodAutor(void){
      
    int codLivro, codAutor, newcodAutor;
    char aux[120];
	
    printf("Qual o codigo do livro?\n");
      scanf("%d",&codLivro);
    printf("Qual o codigo do autor?\n");
      scanf("%d",&codAutor);
    printf("Novo codigo do autor:\n");
      scanf("%d",&newcodAutor);
				
    sprintf(aux,"UPDATE Escreve SET Autor_CodAutor=%d WHERE Autor_CodAutor=%d AND Livro_CodLivro=%d",newcodAutor, codAutor, codLivro);
    resultado(aux);
}
/*--------------------------------------------------------------------------*/
    
