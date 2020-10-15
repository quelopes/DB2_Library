-- MySQL dump 10.11
--
-- Host: localhost    Database: Biblioteca
-- ------------------------------------------------------
-- Server version	5.0.51a-3ubuntu5.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Amigo`
--

DROP TABLE IF EXISTS `Amigo`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `Amigo` (
  `CodAmigo` int(10) unsigned NOT NULL auto_increment,
  `Pnome` varchar(45) NOT NULL,
  `Mnome` varchar(3) default NULL,
  `Unome` varchar(20) NOT NULL,
  `Celular` int(10) unsigned default NULL,
  `TeleFixo` int(10) unsigned default NULL,
  `TelTrab` int(10) unsigned default NULL,
  `eMail` varchar(45) NOT NULL,
  PRIMARY KEY  (`CodAmigo`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `Amigo`
--

LOCK TABLES `Amigo` WRITE;
/*!40000 ALTER TABLE `Amigo` DISABLE KEYS */;
INSERT INTO `Amigo` VALUES (1,'Marcio','S','Filho',123456789,987654321,258963147,'marciofilho@gmail.com'),(2,'Mirian','S','Coelho',123456789,936852741,258963147,'miriancoelho@gmail.com'),(3,'Joao','S','Pereira',321456987,978456321,258963147,'joaop@gmail.com'),(4,'Jose','S','Lopes',147896325,985236741,248963147,'lopesjose_s@gmail.com'),(5,'Artur','S','Almeida',147852741,987654321,208963147,'artur56_almeida@gmail.com'),(6,'Marta','L','Barretos',123456789,974856321,258963147,'marta_b@gmail.com');
/*!40000 ALTER TABLE `Amigo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Autor`
--

DROP TABLE IF EXISTS `Autor`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `Autor` (
  `CodAutor` int(10) unsigned NOT NULL auto_increment,
  `Pnome` varchar(45) NOT NULL,
  `Mnome` varchar(3) default NULL,
  `Unome` varchar(45) NOT NULL,
  PRIMARY KEY  (`CodAutor`)
) ENGINE=MyISAM AUTO_INCREMENT=15 DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `Autor`
--

LOCK TABLES `Autor` WRITE;
/*!40000 ALTER TABLE `Autor` DISABLE KEYS */;
INSERT INTO `Autor` VALUES (1,'HECTOR','G','ARANGO'),(2,'DOUGLAS','P','DOWNING'),(3,'MURRAY','R','SPIEGEL'),(4,'BONATO','M','MOLDES'),(5,'KAYSHAV','D','DATTATRI'),(6,'BJARNES','S','STROUSTRUP'),(7,'BRUCE','W','ECKEL'),(8,'FERNANDO','S','MONTENEGRO'),(9,'JARROD','H','HOLLINGWORTH'),(10,'RICHARD','B','JONES'),(11,'BERTRAND','C','MEYER'),(12,'MEILIR','P','JONES'),(13,'BERNARD','V','RUMBAUGH'),(14,'pedro','M','Lima');
/*!40000 ALTER TABLE `Autor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Compra`
--

DROP TABLE IF EXISTS `Compra`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `Compra` (
  `Livro_CodLivro` int(10) unsigned NOT NULL,
  `Livraria_CodLivraria` int(10) unsigned NOT NULL,
  `DtCompra` date NOT NULL,
  `Preco` float default NULL,
  PRIMARY KEY  (`Livro_CodLivro`,`Livraria_CodLivraria`),
  KEY `Livraria_CodLivraria` (`Livraria_CodLivraria`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `Compra`
--

LOCK TABLES `Compra` WRITE;
/*!40000 ALTER TABLE `Compra` DISABLE KEYS */;
INSERT INTO `Compra` VALUES (1,1,'1999-06-17',150),(2,2,'1999-07-17',70),(3,3,'1999-05-10',80),(4,4,'1999-01-07',98),(5,1,'1999-01-17',450),(6,2,'1999-04-17',30),(7,3,'1999-03-17',140),(8,3,'1999-02-06',110),(9,1,'1999-09-13',90),(10,4,'1999-10-10',70),(11,1,'1999-04-17',60),(12,3,'1999-05-17',120),(13,4,'1999-11-17',200),(14,2,'1999-06-14',15),(15,4,'1999-12-17',350);
/*!40000 ALTER TABLE `Compra` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Empresta`
--

DROP TABLE IF EXISTS `Empresta`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `Empresta` (
  `CodEmprest` int(10) unsigned NOT NULL auto_increment,
  `Amigo_CodAmigo` int(10) unsigned NOT NULL,
  `Livro_CodLivro` int(10) unsigned NOT NULL,
  `DtEmprestimo` date NOT NULL,
  `DtDevolucao` date default NULL,
  `DtDevPrevista` date NOT NULL,
  PRIMARY KEY  (`CodEmprest`),
  KEY `Amigo_CodAmigo` (`Amigo_CodAmigo`),
  KEY `Livro_CodLivro` (`Livro_CodLivro`)
) ENGINE=MyISAM AUTO_INCREMENT=1024 DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `Empresta`
--

LOCK TABLES `Empresta` WRITE;
/*!40000 ALTER TABLE `Empresta` DISABLE KEYS */;
INSERT INTO `Empresta` VALUES (1012,6,5,'2007-04-12','2008-07-14','2007-12-01'),(1011,3,2,'2007-02-15','0000-00-00','2007-10-30'),(1010,2,12,'2007-01-03','2008-01-14','2008-09-18'),(1013,1,3,'2007-02-16','0000-00-00','2008-09-30'),(1015,6,4,'2007-11-04','2008-04-04','2008-10-12'),(1016,5,16,'2008-09-12','0000-00-00','2009-01-01'),(1017,1,17,'2008-09-20','0000-00-00','2009-01-04'),(1023,4,7,'2008-07-04','0000-00-00','2009-07-06'),(1021,4,1,'2004-02-18','2008-03-02','2005-05-13');
/*!40000 ALTER TABLE `Empresta` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Escreve`
--

DROP TABLE IF EXISTS `Escreve`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `Escreve` (
  `Autor_CodAutor` int(10) unsigned NOT NULL,
  `Livro_CodLivro` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`Autor_CodAutor`,`Livro_CodLivro`),
  KEY `Livro_CodLivro` (`Livro_CodLivro`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `Escreve`
--

LOCK TABLES `Escreve` WRITE;
/*!40000 ALTER TABLE `Escreve` DISABLE KEYS */;
INSERT INTO `Escreve` VALUES (1,15),(2,10),(3,5),(3,12),(4,1),(5,7),(6,2),(7,4),(7,14),(8,13),(9,11),(10,8),(11,6),(12,3),(13,9);
/*!40000 ALTER TABLE `Escreve` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Livraria`
--

DROP TABLE IF EXISTS `Livraria`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `Livraria` (
  `CodLivraria` int(10) unsigned NOT NULL auto_increment,
  `TelFixo` int(10) unsigned NOT NULL,
  `RazaoSocial` float default NULL,
  `Nome` varchar(20) NOT NULL,
  `Rua` varchar(20) default NULL,
  `Num` int(10) unsigned default NULL,
  `Cidade` varchar(20) NOT NULL,
  `UF` varchar(3) default NULL,
  `Fax` int(10) unsigned default NULL,
  `eMail` varchar(20) default NULL,
  `Site` varchar(45) default NULL,
  PRIMARY KEY  (`CodLivraria`)
) ENGINE=MyISAM AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `Livraria`
--

LOCK TABLES `Livraria` WRITE;
/*!40000 ALTER TABLE `Livraria` DISABLE KEYS */;
INSERT INTO `Livraria` VALUES (1,123456789,147852,'SARAIVA','Ipatinga',25,'Petropolis','RJ',36985214,'saraiva@livros.com.b','www.saraiva.com.br'),(2,123456789,147852,'CULTURA','raul soares',455,'Teresopolis','RJ',30985214,'cultura@livros.com.b','www.cultura.com.br'),(3,123456789,147852,'DA VINCI','imperador',314,'Rio de Janeiro','RJ',36985214,'davinci@livros.com.b','www.davinci.com.br'),(4,123456789,147852,'LEITURA','1marÃ§o',995,'Petropolis','RJ',36985214,'leitura@livros.com.b','www.leitura.com.br'),(5,2578956,1.47854e+06,'magalhaes','pedro II ',2547,'rio de janeiro','RJ',545444,'mag@info.br','www.magalhaes.info.br'),(6,5454584,545454,'mendes','idsjfosaijf',54,'betim','mg',54564,'qjdfh@jdfhsa','www.kdjfakjf'),(7,32412341,3.41324e+06,'LABERGUE','VIEIRA SOUTO',234,'','RJ',231312,'labergue@livros.com.','r');
/*!40000 ALTER TABLE `Livraria` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Livro`
--

DROP TABLE IF EXISTS `Livro`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `Livro` (
  `CodLivro` int(10) unsigned NOT NULL auto_increment,
  `Categoria` varchar(15) NOT NULL,
  `Ano` int(10) unsigned NOT NULL,
  `Edicao` int(10) unsigned NOT NULL,
  `Titulo` varchar(45) NOT NULL,
  `numPg` int(10) unsigned default NULL,
  `Editora` varchar(45) NOT NULL,
  `Status_2` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`CodLivro`)
) ENGINE=MyISAM AUTO_INCREMENT=19 DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `Livro`
--

LOCK TABLES `Livro` WRITE;
/*!40000 ALTER TABLE `Livro` DISABLE KEYS */;
INSERT INTO `Livro` VALUES (8,'ESTATISTICA',2007,7,'EstatÃ­stica Aplicada',234,'Saraiva',0),(9,'BIOINFORMATICA',2008,5,'Introduction to Computational Molecular',451,'PWS Publishing',0),(10,'PROGRAMACAO',1985,3,'OrientaÃ§Ã£o a objetos em C++',475,'CiÃªncia Moderna',0),(11,'ECOLOGIA',2001,1,'fundamentos em ecologia',452,'Artmed',0),(12,'ESTATISTICA',2002,4,'EstatÃ­stica: 383 Problemas Resolvidos',350,'Murray',0),(13,'BIOINFORMATICA',2003,4,'Machine Learning',457,'McGraw Hill',0),(7,'ECOLOGIA',2004,3,'Vida a ciencia da biologia',745,'Artmed',1),(6,'PROGRAMACAO',2000,2,'Thinking in C++',547,'Prentice Hall',0),(5,'BIOINFORMATICA',1999,4,'Bioinformatics: the Machine Learning Approach',540,'MIT Press',1),(4,'ESTATISTICA',2004,1,'BioestatÃ­stica TeÃ³rica e Computacional',350,'Guanabara',0),(3,'ECOLOGIA',2003,5,'Economia da Natureza',450,'Guanabara',1),(1,'BIOINFORMATICA',2001,6,'introducao a Bioinformatica',253,'Artmed',1),(2,'PROGRAMACAO',2002,4,'C++: effective object-oriented software',874,'Prentice Hall',1),(14,'PROGRAMACAO',2003,5,'Modelagem e projetos baseados em objetos',35,'Campus',0),(15,'ECOLOGIA',2006,1,'Introduction EcologyII',784,'Breker',0),(16,'bioinformatica',2008,7,'primavera',257,'artmed',1),(17,'estatistica',2004,4,'viagem',5478,'abril',0);
/*!40000 ALTER TABLE `Livro` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2008-09-14 14:31:28
