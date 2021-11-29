-- MariaDB dump 10.19  Distrib 10.6.4-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: Tienda
-- ------------------------------------------------------
-- Server version	10.6.4-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Aud_producto`
--

DROP TABLE IF EXISTS `Aud_producto`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Aud_producto` (
  `Id` bigint(20) NOT NULL AUTO_INCREMENT,
  `Cod_barra` bigint(20) DEFAULT NULL,
  `Nombre_ant` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Marca_ant` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Fecha_proc_ant` date DEFAULT NULL,
  `Fecha_cad_ant` date DEFAULT NULL,
  `Numero_lote_ant` int(11) DEFAULT NULL,
  `Nota_ant` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Piezas_ant` bigint(20) DEFAULT NULL,
  `Compra_ant` double(9,2) DEFAULT NULL,
  `Venta_ant` double(9,2) DEFAULT NULL,
  `Categoria_ant` varchar(30) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Subcategoria_ant` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Nombre_new` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Marca_new` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Fecha_proc_new` date DEFAULT NULL,
  `Fecha_cad_new` date DEFAULT NULL,
  `Numero_lote_new` int(11) DEFAULT NULL,
  `Nota_new` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Piezas_new` bigint(20) DEFAULT NULL,
  `Compra_new` double(9,2) DEFAULT NULL,
  `Venta_new` double(9,2) DEFAULT NULL,
  `Categoria_new` varchar(30) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Subcategoria_new` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Usuario` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Fecha_mod` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `Accion` varchar(30) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=7017 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Aud_producto`
--

LOCK TABLES `Aud_producto` WRITE;
/*!40000 ALTER TABLE `Aud_producto` DISABLE KEYS */;
/*!40000 ALTER TABLE `Aud_producto` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Aud_proveedor`
--

DROP TABLE IF EXISTS `Aud_proveedor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Aud_proveedor` (
  `Id` bigint(20) NOT NULL AUTO_INCREMENT,
  `Empresa` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Nombre_ant` varchar(60) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Direccion_ant` varchar(90) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Telefono_ant` bigint(20) DEFAULT NULL,
  `Region_ant` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Pais_ant` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `RFC_ant` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Estado_ant` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Correo_ant` varchar(60) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Nombre_new` varchar(60) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Direccion_new` varchar(90) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Telefono_new` bigint(20) DEFAULT NULL,
  `Region_new` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Pais_new` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `RFC_new` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Estado_new` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Correo_new` varchar(60) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Usuario` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Fecha_mod` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `Accion` varchar(30) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=176 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Aud_proveedor`
--

LOCK TABLES `Aud_proveedor` WRITE;
/*!40000 ALTER TABLE `Aud_proveedor` DISABLE KEYS */;
/*!40000 ALTER TABLE `Aud_proveedor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Aud_ticket`
--

DROP TABLE IF EXISTS `Aud_ticket`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Aud_ticket` (
  `Id` bigint(20) NOT NULL AUTO_INCREMENT,
  `Id_ticket` bigint(20) DEFAULT NULL,
  `Ant_usuario` varchar(80) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Ant_total` double(9,2) DEFAULT NULL,
  `Ant_recibido` double(9,2) DEFAULT NULL,
  `Ant_cambio` double(9,2) DEFAULT NULL,
  `Ant_pago` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT 'Efectivo',
  `Ant_hora` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `New_usuario` varchar(80) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `New_total` double(9,2) DEFAULT NULL,
  `New_recibido` double(9,2) DEFAULT NULL,
  `New_cambio` double(9,2) DEFAULT NULL,
  `New_pago` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT 'Efectivo',
  `New_hora` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Usuario` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Fecha_mod` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `Accion` varchar(30) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=415 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Aud_ticket`
--

LOCK TABLES `Aud_ticket` WRITE;
/*!40000 ALTER TABLE `Aud_ticket` DISABLE KEYS */;
/*!40000 ALTER TABLE `Aud_ticket` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Carrito_compra`
--

DROP TABLE IF EXISTS `Carrito_compra`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Carrito_compra` (
  `No` double(9,3) DEFAULT NULL,
  `Producto` varchar(80) COLLATE utf8mb4_unicode_ci NOT NULL,
  `P_unitario` double(9,2) DEFAULT NULL,
  `Subtotal` double(9,2) DEFAULT NULL,
  `SKU` bigint(20) NOT NULL,
  PRIMARY KEY (`SKU`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Carrito_compra`
--

LOCK TABLES `Carrito_compra` WRITE;
/*!40000 ALTER TABLE `Carrito_compra` DISABLE KEYS */;
/*!40000 ALTER TABLE `Carrito_compra` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Corte_z`
--

DROP TABLE IF EXISTS `Corte_z`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Corte_z` (
  `Id` bigint(20) NOT NULL AUTO_INCREMENT,
  `Gerente` varchar(99) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Cajero` varchar(99) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Ingreso` double(9,2) DEFAULT NULL,
  `Balance` double(9,2) DEFAULT NULL,
  `Status` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Fecha` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `F_pago` varchar(30) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Corte_z`
--

LOCK TABLES `Corte_z` WRITE;
/*!40000 ALTER TABLE `Corte_z` DISABLE KEYS */;
/*!40000 ALTER TABLE `Corte_z` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Inventario`
--

DROP TABLE IF EXISTS `Inventario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Inventario` (
  `Cantidad` bigint(20) DEFAULT NULL,
  `Balance_f` int(11) DEFAULT NULL,
  `Balance` double(9,2) DEFAULT NULL,
  `Usuario` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Fecha` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `Query` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Inventario`
--

LOCK TABLES `Inventario` WRITE;
/*!40000 ALTER TABLE `Inventario` DISABLE KEYS */;
/*!40000 ALTER TABLE `Inventario` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Inventario_temp`
--

DROP TABLE IF EXISTS `Inventario_temp`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Inventario_temp` (
  `SKU` bigint(20) NOT NULL,
  `Nombre` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Piezas` double(9,3) DEFAULT NULL,
  `Valor` double(9,2) DEFAULT NULL,
  `Ingreso` double(9,3) DEFAULT NULL,
  `Fisico` double(9,3) DEFAULT NULL,
  `Balance` double(9,3) DEFAULT NULL,
  PRIMARY KEY (`SKU`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Inventario_temp`
--

LOCK TABLES `Inventario_temp` WRITE;
/*!40000 ALTER TABLE `Inventario_temp` DISABLE KEYS */;
/*!40000 ALTER TABLE `Inventario_temp` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Producto`
--

DROP TABLE IF EXISTS `Producto`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Producto` (
  `SKU` bigint(20) NOT NULL,
  `Nombre` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Marca` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Fecha_proc` date DEFAULT NULL,
  `Fecha_cad` date DEFAULT NULL,
  `Numero_lote` int(11) DEFAULT NULL,
  `Nota` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Piezas` double(9,3) DEFAULT NULL,
  `Compra` double(9,2) DEFAULT NULL,
  `Venta` double(9,2) DEFAULT NULL,
  `Categoria` varchar(30) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Subcategoria` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`SKU`),
  KEY `Marca` (`Marca`),
  CONSTRAINT `Producto_ibfk_1` FOREIGN KEY (`Marca`) REFERENCES `Proveedor` (`Empresa`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Producto`
--

LOCK TABLES `Producto` WRITE;
/*!40000 ALTER TABLE `Producto` DISABLE KEYS */;
/*!40000 ALTER TABLE `Producto` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb3 */ ;
/*!50003 SET character_set_results = utf8mb3 */ ;
/*!50003 SET collation_connection  = utf8mb3_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger inserta_producto
     after insert on Producto for each row insert into Aud_producto
     (Cod_barra, 
     Nombre_new, Marca_new, Fecha_proc_new, Fecha_cad_new ,Numero_lote_new,Nota_new,Piezas_new,Compra_new,Venta_new,Categoria_new,Subcategoria_new,
     Usuario,Fecha_mod,Accion 
     )
     values 
     (NEW.SKU,
     NEW.Nombre, NEW.Marca, NEW.Fecha_proc , NEW.Fecha_cad, NEW.Numero_lote, NEW.Nota, NEW.Piezas, NEW.Compra, NEW.Venta, NEW.Categoria, NEW.Subcategoria,
     USER(),NOW(),'Producto Nuevo') */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb3 */ ;
/*!50003 SET character_set_results = utf8mb3 */ ;
/*!50003 SET collation_connection  = utf8mb3_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger modifica_producto
     after update on Producto for each row insert into Aud_producto
     (Cod_barra, 
     Nombre_ant, Marca_ant, Fecha_proc_ant, Fecha_cad_ant, Numero_lote_ant,Nota_ant,Piezas_ant,Compra_ant,Venta_ant,Categoria_ant,Subcategoria_ant,
     Nombre_new, Marca_new, Fecha_proc_new, Fecha_cad_new ,Numero_lote_new,Nota_new,Piezas_new,Compra_new,Venta_new,Categoria_new,Subcategoria_new,
     Usuario,Fecha_mod,Accion 
     )
     values 
     (NEW.SKU,
     OLD.Nombre, OLD.Marca, OLD.Fecha_proc , OLD.Fecha_cad, OLD.Numero_lote, OLD.Nota, OLD.Piezas, OLD.Compra, OLD.Venta, OLD.Categoria, OLD.Subcategoria,
     NEW.Nombre, NEW.Marca, NEW.Fecha_proc , NEW.Fecha_cad, NEW.Numero_lote, NEW.Nota, NEW.Piezas, NEW.Compra, NEW.Venta, NEW.Categoria, NEW.Subcategoria,
      USER(),NOW(),'Producto Recibido') */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb3 */ ;
/*!50003 SET character_set_results = utf8mb3 */ ;
/*!50003 SET collation_connection  = utf8mb3_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger elimina_producto
     after delete on Producto for each row insert into Aud_producto
     (Cod_barra, 
     Nombre_ant, Marca_ant, Fecha_proc_ant, Fecha_cad_ant, Numero_lote_ant,Nota_ant,Piezas_ant,Compra_ant,Venta_ant,Categoria_ant,Subcategoria_ant,
     Usuario,Fecha_mod,Accion 
     )
     values 
     (OLD.SKU,
     OLD.Nombre, OLD.Marca, OLD.Fecha_proc , OLD.Fecha_cad, OLD.Numero_lote, OLD.Nota, OLD.Piezas, OLD.Compra, OLD.Venta, OLD.Categoria, OLD.Subcategoria,
     USER(),NOW(),'Producto Eliminado') */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `Proveedor`
--

DROP TABLE IF EXISTS `Proveedor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Proveedor` (
  `Empresa` varchar(45) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Nombre` varchar(60) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Direccion` varchar(90) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Telefono` bigint(20) DEFAULT NULL,
  `Region` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Pais` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `RFC` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Estado` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Correo` varchar(60) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`Empresa`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Proveedor`
--

LOCK TABLES `Proveedor` WRITE;
/*!40000 ALTER TABLE `Proveedor` DISABLE KEYS */;
/*!40000 ALTER TABLE `Proveedor` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb3 */ ;
/*!50003 SET character_set_results = utf8mb3 */ ;
/*!50003 SET collation_connection  = utf8mb3_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger inserta_vendedor
     after insert on Proveedor for each row insert into Aud_proveedor
     (Empresa,
     Nombre_new, Direccion_new, Telefono_new, Region_new, Pais_new, RFC_new, Estado_new, Correo_new,
     Usuario,Fecha_mod,Accion 
     )
     values 
     (NEW.Empresa,
     NEW.Nombre, NEW.Direccion, NEW.Telefono , NEW.Region, NEW.Pais, NEW.RFC, NEW.Estado, NEW.Direccion,
     USER(),NOW(),'Proveedor Nuevo') */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb3 */ ;
/*!50003 SET character_set_results = utf8mb3 */ ;
/*!50003 SET collation_connection  = utf8mb3_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger modifica_vendedor
     after update on Proveedor for each row insert into Aud_proveedor
     (Empresa, 
     Nombre_ant, Direccion_ant, Telefono_ant, Region_ant, Pais_ant, RFC_ant, Estado_ant, Correo_ant,
     Nombre_new, Direccion_new, Telefono_new, Region_new, Pais_new, RFC_new, Estado_new, Correo_new,
     Usuario,Fecha_mod,Accion 
     )
     values 
     (NEW.Empresa,
     OLD.Nombre, OLD.Direccion, OLD.Telefono , OLD.Region, OLD.Pais, OLD.RFC, OLD.Estado, OLD.Direccion,
     NEW.Nombre, NEW.Direccion, NEW.Telefono , NEW.Region, NEW.Pais, NEW.RFC, NEW.Estado, NEW.Direccion,
     USER(),NOW(),'Proveedor Actualizado') */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb3 */ ;
/*!50003 SET character_set_results = utf8mb3 */ ;
/*!50003 SET collation_connection  = utf8mb3_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger elimina_vendedor
     after delete on Proveedor for each row insert into Aud_proveedor
     (Empresa, 
     Nombre_ant, Direccion_ant, Telefono_ant, Region_ant, Pais_ant, RFC_ant, Estado_ant, Correo_ant,
     Usuario,Fecha_mod,Accion 
     )
     values 
     (OLD.Empresa,
     OLD.Nombre, OLD.Direccion, OLD.Telefono , OLD.Region, OLD.Pais, OLD.RFC, OLD.Estado, OLD.Direccion,
     USER(),NOW(),'Proveedor Eliminado') */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `Ticket`
--

DROP TABLE IF EXISTS `Ticket`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Ticket` (
  `Id_ticket` bigint(20) unsigned zerofill NOT NULL AUTO_INCREMENT,
  `Usuario` varchar(80) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Total` double(9,2) DEFAULT NULL,
  `Recibido` double(9,2) DEFAULT NULL,
  `Cambio` double(9,2) DEFAULT NULL,
  `Tipo_pago` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT 'Efectivo',
  `Query` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Fecha_hora` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  PRIMARY KEY (`Id_ticket`)
) ENGINE=InnoDB AUTO_INCREMENT=267 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Ticket`
--

LOCK TABLES `Ticket` WRITE;
/*!40000 ALTER TABLE `Ticket` DISABLE KEYS */;
/*!40000 ALTER TABLE `Ticket` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb3 */ ;
/*!50003 SET character_set_results = utf8mb3 */ ;
/*!50003 SET collation_connection  = utf8mb3_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger inserta_ticket 
     after insert on Ticket for each row insert into Aud_ticket
     (Id_ticket, 
     New_usuario, New_total, New_recibido, New_cambio, New_pago ,New_hora,
     Usuario,Fecha_mod,Accion 
     )
     values 
     (NEW.Id_ticket,
     NEW.Usuario, NEW.Total, NEW.Recibido , NEW.Cambio, NEW.Tipo_pago, NEW.Fecha_hora,
     USER(),NOW(),'Ticket Modificado') */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb3 */ ;
/*!50003 SET character_set_results = utf8mb3 */ ;
/*!50003 SET collation_connection  = utf8mb3_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger modifica_ticket after update on Ticket for each row insert into Aud_ticket      (Id_ticket,       Ant_usuario, Ant_total, Ant_recibido, Ant_cambio, Ant_pago, Ant_hora,      New_usuario, New_total, New_recibido, New_cambio, New_pago ,New_hora,      Usuario,Fecha_mod,Accion       )      values       (NEW.Id_ticket,      OLD.Usuario, OLD.Total, OLD.Recibido , OLD.Cambio, OLD.Tipo_pago, OLD.Fecha_hora,      NEW.Usuario, NEW.Total, NEW.Recibido , NEW.Cambio, NEW.Tipo_pago, NEW.Fecha_hora,      USER(),NOW(),'Ticket Modificado') */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb3 */ ;
/*!50003 SET character_set_results = utf8mb3 */ ;
/*!50003 SET collation_connection  = utf8mb3_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger elimina_ticket after delete on Ticket for each row insert into Aud_ticket      (Id_ticket,       Ant_usuario, Ant_total, Ant_recibido, Ant_cambio, Ant_pago, Ant_hora,      Usuario,Fecha_mod,Accion       )      values       (OLD.Id_ticket,      OLD.Usuario, OLD.Total, OLD.Recibido , OLD.Cambio, OLD.Tipo_pago, OLD.Fecha_hora,      USER(),NOW(),'Ticket Eliminado') */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `Tienda`
--

DROP TABLE IF EXISTS `Tienda`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Tienda` (
  `Id_tienda` int(3) unsigned zerofill NOT NULL AUTO_INCREMENT,
  `Nombre` varchar(80) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `RFC` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Telefono` bigint(20) DEFAULT NULL,
  `icono` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`Id_tienda`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Tienda`
--

LOCK TABLES `Tienda` WRITE;
/*!40000 ALTER TABLE `Tienda` DISABLE KEYS */;
/*!40000 ALTER TABLE `Tienda` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Venta_ini`
--

DROP TABLE IF EXISTS `Venta_ini`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Venta_ini` (
  `V_dia` double(9,2) DEFAULT NULL,
  `User` varchar(126) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`User`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Venta_ini`
--

LOCK TABLES `Venta_ini` WRITE;
/*!40000 ALTER TABLE `Venta_ini` DISABLE KEYS */;
/*!40000 ALTER TABLE `Venta_ini` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Venta_total`
--

DROP TABLE IF EXISTS `Venta_total`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Venta_total` (
  `V_dia` double(9,2) DEFAULT NULL,
  `fecha` date NOT NULL,
  PRIMARY KEY (`fecha`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Venta_total`
--

LOCK TABLES `Venta_total` WRITE;
/*!40000 ALTER TABLE `Venta_total` DISABLE KEYS */;
/*!40000 ALTER TABLE `Venta_total` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-11-04 18:46:04
