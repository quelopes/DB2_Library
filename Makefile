BIBLIOTECA: Cliente.o FAlterar.o FExcluir.o FConsultar.o FGerais.o FIncluir.o FRelatorio.o
	gcc -o BIBLIOTECA Cliente.o FAlterar.o FExcluir.o FConsultar.o FGerais.o FIncluir.o FRelatorio.o
FAlterar.o: FAlterar.c FBiblioteca.h
	gcc -c FAlterar.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
FExcluir.o: FExcluir.c FBiblioteca.h
	gcc -c FExcluir.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
FConsultar.o: FConsultar.c FBiblioteca.h
	gcc -c FConsultar.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
FGerais.o: FGerais.c FBiblioteca.h
	gcc -c FGerais.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
FIncluir.o: FIncluir.c FBiblioteca.h
	gcc -c FIncluir.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
FRelatorio.o: FRelatorio.c FBiblioteca.h
	gcc -c FRelatorio.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
Cliente.o: Cliente.c FBiblioteca.h
	gcc -c Cliente.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient

