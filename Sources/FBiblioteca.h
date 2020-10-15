/*************************BIBLIOTECA**************************************/
#include <stdlib.h>
#include <stdio.h>

#include "mysql/mysql.h"

#ifndef _FBIBLIOTECA_H
#define	_FBIBLIOTECA_H

/***FUNCOES GERAIS***/
void conectar(void);
void desconectar(void);
void menuPrincipal(void);
void resultado(char* aux);
int verificaLivro(int livro);

/***FUNCOES DE INCLUIR***/
void menuIncluir(void);
void incluirLivro(void);
void incluirLivraria(void);
void incluirAutor(void);
void incluirAmigo(void);
void incluirEmprestimo(void);
void incluirCompra(void);
void incluirEscreve(void);

/***FUNCOES DE ALTERAR***/
void menuAlterar(void);
void alterarMenuLivro(void);
void alterarMenuLivraria(void);
void alterarMenuAutor(void);
void alterarMenuAmigo(void);
void alterarMenuEmprestimo(void);
      /*ALTERAR LIVRO*/
void livroAlterarCateg(void);
void livroAlterarAno(void);
void livroAlterarEdicao(void);
void livroAlterarTitulo(void);
void livroAlterarNo_pg(void);
void livroAlterarEditora(void);
void livroAlterarStatus(void);
      /*ALTERAR LIVRARIA*/
void livrarAlterarRazSoc(void);
void livrarAlterarNome(void);
void livrarAlterarEndereco(void);
void livrarAlterarTelFixo(void);
void livrarAlterarFax(void);
void livrarAlterarEMail(void);
void livrarAlterarSite(void);
      /*ALTERAR AUTOR*/
void autorAlterarPnome(void);
void autorAlterarMnome(void);
void autorAlterarUnome(void);
      /*ALTERAR AMIGO*/
void amigoAlterarPnome(void);
void amigoAlterarMnome(void);
void amigoAlterarUnome(void);
void amigoAlterarCel(void);
void amigoAlterarTelFixo(void);
void amigoAlterarTelTrab(void);
void amigoAlterarEMail(void);
      /*ALTERAR EMPRESTIMO*/
void emptAlterarDtDevPrev(void);
void emptAlterarDtDev(void);
      /*ALTERAR COMPRA*/
void compraAlterarDtComp(void);
void compraAlterarPreco(void);
void compraAlterarCodLivro(void);
void compraAlterarCodLivrar(void);
    /*ALTERAR ESCREVER*/
void escreveAlterarCodLivro(void);
void escreveAlterarCodAutor(void);

/***FUNCOES DE CONSULTAR***/
void menuConsultar(void);
void menuConsultarEmprestimo(void);
void consultarLivro(void);
void consultarLivraria(void);
void consultarAutor(void);
void consultarAmigo(void);
void consultarEmprestimo(void);
void consultarCompra(void);
void consultarTudoEmprestimo(void);
void consultarTudoLivro(void);
void consultarTudoAmigo(void);
void consultarTudoAutor(void);
void consultarTudoLivraria(void);

/***FUNCOES DE EXCLUIR***/
void menuExcluir(void);
void excluirLivro(void);
void excluirLivraria(void);
void excluirAutor(void);
void excluirAmigo(void);
void excluirEmprestimo(void);
void excluirCompra(void);
    
/***FUNCOES DE RELATÓRIOS***/
void menuRelatorio(void);
void relatorioGastMes(void);
void relatorioTotalGast(void);
void relatorioLivroCat(void);
void relatorioEmptNDevDt(void);
void relatorioLivroNome(void);
    
#endif /* _FBIBLIOTECA_H */





