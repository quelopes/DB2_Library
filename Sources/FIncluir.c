/**********************BIBLIOTECA************************/
#include "FBiblioteca.h"

MYSQL conex;

void menuIncluir(void){
    
  int opc;
  while(1){
    printf("\n******************\n");	
    printf("***INCLUIR***\n");
    printf("******************\n");
    printf("Digite uma opcao:\n");
    printf("[1]LIVRO\n");
    printf("[2]LIVRARIA\n");
    printf("[3]AUTOR\n");
    printf("[4]AMIGO\n");
    printf("[5]EMPRESTIMO\n");
    printf("[6]COMPRA\n");
    printf("[7]DEVOLUÇÃO\n");
    printf("[8]RETORNAR AO MENU PRINCIPAL\n\n");
      scanf("%d", &opc);
        
        switch (opc){
            case 1: incluirLivro();
                break;
            case 2: incluirLivraria();
                break;
            case 3: incluirAutor();
                break;
            case 4: incluirAmigo();
                break;
            case 5: incluirEmprestimo();
                break;
            case 6: incluirCompra();
                break;
            case 7: emptAlterarDtDev();
                break;
            case 8: menuPrincipal();
                break;
            default : printf("\n Opcao invalida! Tente novamente\n");
             break;
        }
    }
}
/*--------------------------------------------------------------------------*/
void incluirLivro(void){
  
    char aux[350], categoria[16], titulo[46], editora[46];
    int ano, numEd, numPg, status; 
    int codLivro, opc;
    char s, n;
    
    printf("\n****INCLUIR NOVO LIVRO****\n");
    printf("\nCampos com * são obrigatórios!!\n");
    printf("\n Categoria do livro*:\n ");
      scanf(" %16[^\n]",categoria);
    printf("\n Ano de publicação*:\n ");
      scanf("%d",&ano);
    printf("\n Edição(número)*:\n ");
      scanf("%d",&numEd);  
    printf("\n Título*:\n ");
      scanf(" %46[^\n]",titulo); 
    printf("\n Número de páginas:\n ");
      scanf("%d",&numPg);  
    printf("\n Editora*:\n ");
      scanf(" %46[^\n]",editora);
    printf("\n Status do livro (0 disponivel 1 emprestado)*:\n ");
      scanf("%d",&status); 
          
    sprintf(aux,"INSERT INTO Livro (Categoria, Ano, Edicao, Titulo, numPg, Editora, Status_2) VALUES ('%s', %d, %d, '%s', %d, '%s', %d)",categoria, ano, numEd, titulo, numPg, editora, status);
    resultado(aux);
     /*uso de uma funcao que retorna o numero anterior gerado*/                 
        codLivro= mysql_insert_id(&conex);
        printf("\n O codigo do livro gerado foi %d \n\n", codLivro);
        
    /***AUTORES, LIVRARIA E O LIVRO****/
    while(1){
        
        printf("Digite uma opcao nos relacionamentos.\n");
        printf("[1]AUTOR JÁ EXISTENTE(relacionar codigo)\n");
        printf("[2]AUTOR(ES) NOVO(S)\n");
        printf("[3]LIVRARIA JÁ EXISTENTE(relacionar codigo)\n");
        printf("[4]LIVRARIA NOVA\n");
        printf("[5]RETORNAR AO MENU INCLUIR\n\n");
         scanf("%d", &opc);
        switch (opc){
            case 1: incluirEscreve();
                break;
            case 2: incluirAutor();
                break;
            case 3: incluirCompra();
                break;
            case 4: incluirLivraria();
                break;
            case 5: menuIncluir();
                break;   
            default : printf("\n Opcao invalida! Tente novamente\n");
                break;
         }
    }
}
/*--------------------------------------------------------------------------*/
void incluirLivraria(void){
    
    char aux[500], nome[21], rua[21], cidade[21], UF[3], eMail[21], site[46];
    int res, telFixo, fax, codLivraria, num;
    float razSoc;
    
    printf("\n****INCLUIR NOVA LIVRARIA****\n");
    printf("\nCampos com * são obrigatórios!!\n");
    printf("\n Telefone fixo*:\n ");
      scanf("%d",&telFixo);
    printf("\n Razão Social(número):\n");
      scanf("%f",&razSoc);
    printf("\n Nome da livraria*:\n");
      scanf(" %21[^\n]",nome); 
    printf("\n Rua:\n");
      scanf(" %21[^\n]",rua);
    printf("\n Numero:\n");
      scanf("%d",&num);  
    printf("\n Cidade*:\n");
      scanf(" %21[^\n]",cidade);   
    printf("\n Estado(UF):\n");
      scanf(" %3[^\n]",UF);         
    printf("\n Fax:\n ");
      scanf("%d",&fax); 
    printf("\n E-mail:\n");
      scanf(" %21[^\n]",eMail);   
    printf("\n Site:\n");
      scanf(" %46[^\n]",site); 
      
    sprintf(aux,"INSERT INTO Livraria (TelFixo,RazaoSocial,Nome,Rua,Num,Cidade,UF,Fax,eMail,Site) VALUES (%d, %f,'%s','%s',%d,'%s','%s',%d,'%s','%s')",telFixo,razSoc, nome, rua, num,cidade,UF,fax,eMail,site);
    resultado(aux);
    /*uso de uma funcao que retorna o numero anterior gerado*/
        codLivraria= mysql_insert_id(&conex);
        printf("\n O codigo da livraria gerado: %d \n\n", codLivraria);
}
/*--------------------------------------------------------------------------*/
void incluirAutor(void){
     
    char aux[200], pNome[46], mNome[3], uNome[46];
    int codAutor;
    
    printf("\n****INCLUIR NOVO AUTOR****\n");
    printf("\nCampos com * são obrigatórios!!\n");
    printf("\n Primeiro nome do autor*:\n");
      scanf(" %46[^\n]",pNome);
    printf("\n Nome do meio(um caractere):\n");
      scanf(" %3[^\n]",mNome);        
    printf("\n Último nome do autor*:\n");
      scanf(" %46[^\n]",uNome);
       
    sprintf(aux,"INSERT INTO Autor(Pnome,Mnome,Unome) VALUES ('%s','%s','%s')",pNome,mNome,uNome);
    resultado(aux);
    
    /*uso de uma funcao que retorna o numero anterior gerado*/
    codAutor= mysql_insert_id(&conex);
    printf("\n O codigo do autor gerado foi %d \n\n", codAutor);    
}
/*--------------------------------------------------------------------------*/
void incluirAmigo(void){
    
    char aux[200], pNome[46], mNome[3], uNome[46], eMail[46];
    int codAmigo, celular, telFixo, telTrab;
    
    printf("\n****INCLUIR NOVO AMIGO****\n");
    printf("\nCampos com * são obrigatórios!!\n");
    printf("\n Primeiro nome do amigo*:\n");
      scanf(" %46[^\n]",pNome);
    printf("\n Nome do meio(um caractere):\n");
      scanf(" %3[^\n]",mNome);        
    printf("\n Último nome do amigo*:\n");
      scanf(" %46[^\n]",uNome);
    printf("\n Celular:\n ");
      scanf("%d",&celular);
    printf("\n Telefone fixo:\n ");
      scanf("%d",&telFixo);  
    printf("\n Telefone do trabalho:\n ");
      scanf("%d",&telTrab); 
    printf("\n E-mail*:\n");
      scanf(" %21[^\n]",eMail);   
      
       
    sprintf(aux,"INSERT INTO Amigo(Pnome,Mnome,Unome,Celular,TeleFixo,TelTrab,eMail) VALUES ('%s','%s','%s',%d,%d,%d,'%s')",pNome,mNome,uNome,celular,telFixo,telTrab,eMail);
    resultado(aux);
    
    /*uso de uma funcao que retorna o numero anterior gerado*/
        codAmigo= mysql_insert_id(&conex);
        printf("\n O codigo do amigo gerado foi %d \n\n", codAmigo);
    
}
/*--------------------------------------------------------------------------*/
void incluirEmprestimo(void){
    
    int codEmprest, opc;
    char aux[200], dtEmpres[9], dtDevPrev[9];
    char dtDev[9];
    int codAmigo, codLivro;
    int verifica;
    
    printf("\n****INCLUIR NOVO EMPRESTIMO****\n");
    printf("\nCampos com * são obrigatórios!!\n");
    
    printf("Deseja consultar o código do amigo(Tecle 1 para sim ou 0 para nao)?\n");
      scanf("%d",&opc);
        if(opc==1)
          consultarTudoAmigo(); 
    printf("\n Código do amigo(já existente)*:\n");                                
      scanf("%d",&codAmigo);
    printf("Deseja consultar o código do livro?(Tecle [1]Sim ou [0]Nao):\n");
       scanf("%d",&opc);
       if(opc==1)
         consultarTudoLivro();    
    printf("\n Código do Livro (já existente)*:\n");
      scanf("%d",&codLivro); 
      
    /*VERIFICA SE O LIVRO JA ESTA EMPRESTADO*/
     
      verifica= verificaLivro(codLivro);
      if(verifica==1){
          printf("Livro já emprestado\n");
          menuIncluir();
      }
      else
          printf("OK! Livro disponível!\n");
           
   /*----------------------------------------*/       
    printf("\n Data do emprestimo(aaaa/mm/dd)*:\n");
      scanf(" %9[^\n]",dtEmpres);
    printf("\n Data de devolucao (aaaa/mm/dd)(**DIGITE null**):\n");
      scanf(" %9[^\n]",dtDev);
    printf("\n Data de devolucao prevista(aaaa/mm/dd)*:\n");
      scanf(" %9[^\n]",dtDevPrev);
          
    sprintf(aux,"INSERT INTO Empresta(Amigo_CodAmigo,Livro_CodLivro,DtEmprestimo,DtDevolucao,DtDevPrevista) VALUES (%d, %d,'%s','%s',' %s')",codAmigo,codLivro,dtEmpres,dtDev,dtDevPrev);
    resultado(aux);
    
    
   /*uso de uma funcao que retorna o numero anterior gerado*/
    codEmprest= mysql_insert_id(&conex);
    printf("\n O codigo do emprestimo gerado foi %d \n\n", codEmprest);
   printf("Atualização do status do livro! Por favor informe os campos abaixos.\n");
   /*chama a funcao para alterar status*/
   livroAlterarStatus();
       
}
/*--------------------------------------------------------------------------*/
void incluirCompra(void){
    
    char aux[300], dtCompra[9];
    int codLivraria, codLivro, opc;
    float preco;
    
    printf("\n****RELACIONAMENTO****\n");
    printf("\nCampos com * são obrigatórios!!\n");
    printf("Deseja consultar o código do livro? (Tecle [1]Sim ou [0]nao):\n");
     scanf("%d",&opc);
      if(opc==1)
        consultarTudoLivro();    
    printf("\n Código do livro(já existente)*:\n");
      scanf("%d",&codLivro);
    printf("Deseja consultar o código do livraria?(Tecle [1]Sim ou [0]Nao):\n");
      scanf("%d",&opc);
      if(opc==1)
        consultarTudoLivraria();    
    printf("\n Código da Livraria(já existente)*:\n");
      scanf("%d",&codLivraria);
    printf("\n Data da compra(aaaa/mm/dd)*:\n");
      scanf(" %9[^\n]",dtCompra);
    printf("\n Preço:\n");
      scanf("%f",&preco);
              
    sprintf(aux,"INSERT INTO Compra(Livro_CodLivro, Livraria_CodLivraria,DtCompra,Preco) VALUES (%d, %d,'%s',%f)",codLivro,codLivraria,dtCompra,preco);
     resultado(aux); 
}
/*--------------------------------------------------------------------------*/
void incluirEscreve(void){
    
    char aux[300], dtCompra[9];
    int codAutor, codLivro, opc;
    float preco;
    
   printf("\n****RELACIONAMENTO****\n");
   printf("\nCampos com * são obrigatórios!!\n");
   printf("Deseja consultar o código do autor?(Tecle [1]Sim ou [0]Nao):\n");
     scanf("%d",&opc);
        if(opc==1)
        consultarTudoAutor();    
   printf("\n Código do Autor(já existente)*:\n");
     scanf("%d",&codAutor);
   printf("Deseja consultar o código do livro?(Tecle [1]Sim ou [0]Nao):\n");
     scanf("%d",&opc);
        if(opc==1)
        consultarTudoLivro();    
   printf("\n Código do Livro(já existente)*:\n");
      scanf("%d",&codLivro);
              
    sprintf(aux,"INSERT INTO Escreve(Autor_CodAutor, Livro_CodLivro) VALUES (%d, %d)",codAutor,codLivro);
    resultado(aux);   
}

/*--------------------------------------------------------------------------*/
