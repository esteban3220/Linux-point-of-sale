/*
 * tablas.c
 * 
 * Copyright 2021 Esteban <esteban@WarMachine>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <gtk/gtk.h>
#include <mysql.h> 
#include <stdlib.h>
#include "widgets.h"
#include "columnas.h"


void celdas_editables(
             const gchar         *path_string,
             const gchar         *new_text,
             gpointer             data){

		GtkTreePath *path = gtk_tree_path_new_from_string (path_string);		 
        gchar *old_text;
		gint i;

        gtk_tree_model_get (model_inventario, &iter_inventario, COLinveajuste, &old_text, -1);
        g_free (old_text);

		i = gtk_tree_path_get_indices (path)[0];

        gtk_list_store_set (GTK_LIST_STORE (model_inventario), &iter_inventario
		,COLinveingreso,"h"
		,COLinveajuste,"h",-1);
		
        gtk_widget_show(g_Dialog_Error);		 
	 }
	 	 
static GtkTreeModel * inve (void)
{
	store_inve = gtk_list_store_new (N_COLUMNS_inve ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store_inve, &iter_inventario);
	gtk_list_store_set (store_inve, &iter_inventario,
	 COLinvenombre , row[1],
	 COLinvepiezas , row[2],
	 COLinvevalor , row[3],
	 COLinveingreso,"",
	 COLinveajuste  , "0",-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store_inve, &iter_inventario);
	gtk_list_store_set (store_inve, &iter_inventario,
	 COLinvenombre , row[1],
	 COLinvepiezas , row[2],
	 COLinvevalor , row[3],
	 COLinveingreso,"",
	 COLinveajuste  , "0",-1);
}
	return GTK_TREE_MODEL (store_inve);
	g_signal_connect (renderer_inventario, "edited", G_CALLBACK (celdas_editables), model_inventario);
}

 static GtkWidget *titulo_inventario(void)
{	
	renderer_inventario = gtk_cell_renderer_text_new ();
	column_inve = gtk_tree_view_column_new_with_attributes  ("Nombre",renderer_inventario,"text", COLinvenombre,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_inventario),column_inve);
	renderer_inventario = gtk_cell_renderer_text_new ();
	column_inve2 = gtk_tree_view_column_new_with_attributes ("Piezas",renderer_inventario,"text", COLinvepiezas,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_inventario),column_inve2);
	renderer_inventario = gtk_cell_renderer_text_new ();
	column_inve3 = gtk_tree_view_column_new_with_attributes  ("Valor",renderer_inventario,"text", COLinvevalor,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_inventario),column_inve3);
	renderer_inventario = gtk_cell_renderer_text_new ();
	g_object_set(renderer_inventario, "editable", TRUE, NULL);
	column_inve4 = gtk_tree_view_column_new_with_attributes  ("Ingreso",renderer_inventario,"text", COLinveingreso,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_inventario),column_inve4);
	renderer_inventario = gtk_cell_renderer_text_new ();
	g_object_set(renderer_inventario, "editable", TRUE, NULL);
	column_inve5 = gtk_tree_view_column_new_with_attributes  ("Balance",renderer_inventario,"text", COLinveajuste,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_inventario),column_inve5);	
	model_inventario = inve ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view_inventario), model_inventario);
	g_object_unref (model_inventario);
	
	return view_inventario;
}


static GtkTreeModel * POS (void)
{
	store_pos = gtk_list_store_new (NUM_COLS_pos, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store_pos, &iter_pos);
	gtk_list_store_set (store_pos, &iter_pos,
	cantidad_pos, row[2],
	producto_pos, row[0],
	punitario_pos, row[1],
	precio_pos,row[3],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store_pos, &iter_pos);
	gtk_list_store_set (store_pos, &iter_pos,
	cantidad_pos, row[2],
	producto_pos, row[0],
	punitario_pos, row[1],
	precio_pos,row[3],-1);
}
	return GTK_TREE_MODEL (store_pos);
}
 static GtkWidget *titulo_POS(void)
{	
	renderer_pos = gtk_cell_renderer_text_new ();
	column_pos = gtk_tree_view_column_new_with_attributes  ("Cantidad",renderer_pos,"text", cantidad_pos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (treeview_pos),column_pos);
	renderer_pos = gtk_cell_renderer_text_new ();
	column_pos2 = gtk_tree_view_column_new_with_attributes ("Producto",renderer_pos,"text", producto_pos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (treeview_pos),column_pos2);
	renderer_pos = gtk_cell_renderer_text_new ();
	column_pos3 = gtk_tree_view_column_new_with_attributes  ("P. Unitario",renderer_pos,"text", punitario_pos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (treeview_pos),column_pos3);
	renderer_pos = gtk_cell_renderer_text_new ();
	column_pos4 = gtk_tree_view_column_new_with_attributes  ("Subtotal",renderer_pos,"text", precio_pos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (treeview_pos),column_pos4);
	
	
	model_pos = POS ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_pos), model_pos);
	g_object_unref (model_pos);
	return treeview_pos;
}
	

static GtkTreeModel *bus (void)
{
	file_pixbuf = gdk_pixbuf_new_from_file  ("img/shopping-cart-insert256_24820.png", NULL);
	
	store_busqueda = gtk_list_store_new (N_COLUMNS_BUS, G_TYPE_STRING,G_TYPE_STRING,GDK_TYPE_PIXBUF);
	
	gtk_list_store_append (store_busqueda, &iter_busqueda);
	gtk_list_store_set (store_busqueda, &iter_busqueda,
	COLproducto_pos, row[0],
	COLventa_pos, row[1],
	COL_PIXBUF,file_pixbuf,-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store_busqueda, &iter_busqueda);
	gtk_list_store_set (store_busqueda, &iter_busqueda,
	COLproducto_pos, row[0],
	COLventa_pos, row[1],
	COL_PIXBUF,file_pixbuf,-1);
}
	return GTK_TREE_MODEL (store_busqueda);
}
 static GtkWidget *titulo_bus(void)
{	
	renderer_bus = gtk_cell_renderer_text_new ();
	column_bus = gtk_tree_view_column_new_with_attributes  ("Producto",renderer_bus,"text", COLproducto_pos ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busqueda),column_bus);
	
	renderer_bus = gtk_cell_renderer_text_new ();
	column_bus2 = gtk_tree_view_column_new_with_attributes ("Precío",renderer_bus,"markup", COLventa_pos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busqueda),column_bus2);
	
	renderer_bus = gtk_cell_renderer_pixbuf_new();
	column_bus3 = gtk_tree_view_column_new_with_attributes ("Añadir al carrito",renderer_bus,"pixbuf", COL_PIXBUF,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busqueda),column_bus3);
	
	model_busc = bus();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view_busqueda), model_busc);
	//g_object_unref (model_busc);
	return view_busqueda;
}

static GtkTreeModel *venta_ticket (void)
{	
	store_venta = gtk_list_store_new (NUM_COLS_venta, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store_venta, &iter_venta);
	gtk_list_store_set (store_venta, &iter_venta,
	producto_venta, row[0],
	punitario_venta, row[1],
	nop_venta, row[2],
	subtotal_venta, row[3],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store_venta, &iter_venta);
	gtk_list_store_set (store_venta, &iter_venta,
	producto_venta, row[0],
	punitario_venta, row[1],
	nop_venta, row[2],
	subtotal_venta, row[3],-1);
}
	return GTK_TREE_MODEL (store_venta);
}
 static GtkWidget *titulo_venta(void)
{	
	renderer_venta = gtk_cell_renderer_text_new ();
	column_venta = gtk_tree_view_column_new_with_attributes  ("No. Articulos",renderer_venta,"text", nop_venta ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_venta),column_venta);
	
	renderer_venta = gtk_cell_renderer_text_new ();
	column_venta2 = gtk_tree_view_column_new_with_attributes ("Producto",renderer_venta,"text", producto_venta,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_venta),column_venta2);
	
	renderer_venta = gtk_cell_renderer_text_new ();
	column_venta3 = gtk_tree_view_column_new_with_attributes ("Precio Unitario",renderer_venta,"text", punitario_venta,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_venta),column_venta3);
	
	renderer_venta = gtk_cell_renderer_text_new ();
	column_venta4 = gtk_tree_view_column_new_with_attributes ("Subtotal",renderer_venta,"text", subtotal_venta,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_venta),column_venta4);
	
	model_venta = venta_ticket();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view_venta), model_venta);
	return view_venta;
}

static GtkTreeModel * create_empresa (void)
{
	store = gtk_list_store_new (NUM_COLS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,
	COLid, row[0],
	COLidproc, row[1],
	COLnombre, row[2],
	COLdireccion, row[3],
	COLtelefono, row[4],
	COLregion, row[5],
	COLpais, row[6],
	COLrfc, row[7],
	COLcorreo, row[8],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,COLid, row[0],
	COLidproc, row[1],
	COLnombre, row[2],
	COLdireccion, row[3],
	COLtelefono, row[4],
	COLregion, row[5],
	COLpais, row[6],
	COLrfc, row[7],
	COLcorreo, row[8],-1);
}
	return GTK_TREE_MODEL (store);
}


 static GtkWidget *titulo_empresa(void)
{	
	renderer = gtk_cell_renderer_text_new ();
	column_emp = gtk_tree_view_column_new_with_attributes  ("Empresa",renderer,"text", COLid,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp);
	renderer = gtk_cell_renderer_text_new ();
	column_emp2 = gtk_tree_view_column_new_with_attributes ("Nombre",renderer,"text", COLidproc,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp2);
	renderer = gtk_cell_renderer_text_new ();
	column_emp3 = gtk_tree_view_column_new_with_attributes ("Direccion",renderer,"text", COLnombre,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp3);
	renderer = gtk_cell_renderer_text_new ();
	column_emp4 = gtk_tree_view_column_new_with_attributes ("Telefono",renderer,"text", COLdireccion,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp4);
	renderer = gtk_cell_renderer_text_new ();
	column_emp5 = gtk_tree_view_column_new_with_attributes ("Region",renderer,"text", COLtelefono,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp5);
	renderer = gtk_cell_renderer_text_new ();
	column_emp6 = gtk_tree_view_column_new_with_attributes ("Pais",renderer,"text", COLregion,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp6);
	renderer = gtk_cell_renderer_text_new ();
	column_emp7 = gtk_tree_view_column_new_with_attributes ("RFC",renderer,"text", COLpais,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp7);
	renderer = gtk_cell_renderer_text_new ();
	column_emp8 = gtk_tree_view_column_new_with_attributes ("Estado",renderer,"text", COLrfc,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp8);
	renderer = gtk_cell_renderer_text_new ();
	column_emp9 = gtk_tree_view_column_new_with_attributes ("Correo",renderer,"text", COLcorreo,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp9);
	
	model = create_empresa ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view), model);
	g_object_unref (model);
	return view;
}

 
static GtkTreeModel * create_factura (void)
{
	store2 = gtk_list_store_new (NUM_COLS_fac, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store2, &iter2);
	gtk_list_store_set (store2, &iter2,
	COLidfac, row[0],
	COLuser, row[1],
	COLtotal, row[2],
	COLrecibido, row[3],
	COLcambio, row[4],
	COLtipago, row[5],
	COLfechahora, row[7],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store2, &iter2);
	gtk_list_store_set (store2, &iter2,
	COLidfac, row[0],
	COLuser, row[1],
	COLtotal, row[2],
	COLrecibido, row[3],
	COLcambio, row[4],
	COLtipago, row[5],
	COLfechahora, row[7],-1);
}
	return GTK_TREE_MODEL (store2);
}
	   
 static GtkWidget *titulo_factura(void)
{	
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac = gtk_tree_view_column_new_with_attributes  ("ID Factura",renderer2,"text", COLidfac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac2 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer2,"text", COLuser,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac2);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac3 = gtk_tree_view_column_new_with_attributes  ("Total",renderer2,"text", COLtotal,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac3);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac4 = gtk_tree_view_column_new_with_attributes  ("Recibido",renderer2,"text", COLrecibido,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac4);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac5 = gtk_tree_view_column_new_with_attributes  ("Cambio",renderer2,"text", COLcambio,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac5);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac6 = gtk_tree_view_column_new_with_attributes ("T. Pago",renderer2,"text", COLtipago,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac6);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac7 = gtk_tree_view_column_new_with_attributes ("Fecha y Hora",renderer2,"text", COLfechahora,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac7);
	
	model2 = create_factura ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view2), model2);
	//g_object_unref (model2);
	return view2;
}
static GtkTreeModel *create_producto (void)
{
	store3 = gtk_list_store_new (NUM_COLS_pro, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store3, &iter3);
	gtk_list_store_set (store3, &iter3,COLidproducto, row[0],
	COLnomprod, row[1],
	COLmarca, row[2],
	COLfechaproduccion, row[3],
	COLfechacaducidad, row[4],	
	COLnumlote, row[5],
	COLneto, row[6],
	COLpiezas, row[7],
	COLcompra, row[8],
	COLventa, row[9],
	COLcategoria, row[10],
	COLsubcategoria, row[11],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store3, &iter3);
	gtk_list_store_set (store3, &iter3,COLidproducto, row[0],
	COLnomprod, row[1],
	COLmarca, row[2],
	COLfechaproduccion, row[3],
	COLfechacaducidad, row[4],	
	COLnumlote, row[5],
	COLneto, row[6],
	COLpiezas, row[7],
	COLcompra, row[8],
	COLventa, row[9],
	COLcategoria, row[10],
	COLsubcategoria, row[11],-1);
}
	return GTK_TREE_MODEL (store3);
}
	
 static GtkWidget *titulo_producto(void)
{	
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro = gtk_tree_view_column_new_with_attributes  ("Codigo de Barra",renderer3,"text", COLidproducto,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro2 = gtk_tree_view_column_new_with_attributes ("Nombre y Descripcion",renderer3,"text", COLnomprod,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro2);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro3 = gtk_tree_view_column_new_with_attributes  ("Marca",renderer3,"text", COLmarca,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro3);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro4 = gtk_tree_view_column_new_with_attributes  ("Fecha Produccion",renderer3,"text", COLfechaproduccion,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro4);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro5 = gtk_tree_view_column_new_with_attributes  ("Fecha Caducidad",renderer3,"text", COLfechacaducidad,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro5);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro6 = gtk_tree_view_column_new_with_attributes ("Numero Lote",renderer3,"text", COLnumlote,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro6);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro7 = gtk_tree_view_column_new_with_attributes ("Nota",renderer3,"text", COLneto,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro7);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro8 = gtk_tree_view_column_new_with_attributes ("Piezas",renderer3,"text", COLpiezas,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro8);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro9 = gtk_tree_view_column_new_with_attributes ("Compra",renderer3,"text", COLcompra,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro9);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro10 = gtk_tree_view_column_new_with_attributes ("Venta",renderer3,"text", COLventa,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro10);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro11 = gtk_tree_view_column_new_with_attributes ("Categoria",renderer3,"text", COLcategoria,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro11);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro12 = gtk_tree_view_column_new_with_attributes ("Subcategoria",renderer3,"text", COLsubcategoria,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro12);
	
	model3 = create_producto();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view3), model3);
	g_object_unref (model3);
	return view3;
}
 
static GtkTreeModel *create_empresa_auditoria (void){
	store4 = gtk_list_store_new (NUM_COLS_au_emp, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store4, &iter4);
	gtk_list_store_set (store4, &iter4,id_aud_emp,row[0],
	emp_ant_emp,row[1],
	nom_ant_emp,row[2],
	dir_ant_emp,row[3],
	tel_ant_emp,row[4],
	reg_ant_emp,row[5],
	pais_ant_emp,row[6],
	rfc_ant_emp,row[7],
	estado_ant_emp,row[8],
	corr_ant_emp,row[9],
	nom_new_emp,row[10],
	dir_new_emp,row[11],
	tel_new_emp,row[12],
	reg_new_emp,row[13],
	pais_new_emp,row[14],
	rfc_new_emp,row[15],
	estado_new_emp,row[16],
	corr_new_emp,row[17],
	user_emp_emp,row[18],
	modifi_emp_emp,row[19],
	accion_emp_emp,row[20],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store4, &iter4);
	gtk_list_store_set (store4, &iter4,id_aud_emp,row[0],
	emp_ant_emp,row[1],
	nom_ant_emp,row[2],
	dir_ant_emp,row[3],
	tel_ant_emp,row[4],
	reg_ant_emp,row[5],
	pais_ant_emp,row[6],
	rfc_ant_emp,row[7],
	estado_ant_emp,row[8],
	corr_ant_emp,row[9],
	nom_new_emp,row[10],
	dir_new_emp,row[11],
	tel_new_emp,row[12],
	reg_new_emp,row[13],
	pais_new_emp,row[14],
	rfc_new_emp,row[15],
	estado_new_emp,row[16],
	corr_new_emp,row[17],
	user_emp_emp,row[18],
	modifi_emp_emp,row[19],
	accion_emp_emp,row[20],-1);
}
	return GTK_TREE_MODEL (store4);
}

 static GtkWidget *titulo_empresa_auditoria (void)
{
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp = gtk_tree_view_column_new_with_attributes ("ID",renderer4,"text", id_aud_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp2 = gtk_tree_view_column_new_with_attributes ("Empresa",renderer4,"text", emp_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp2);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp3= gtk_tree_view_column_new_with_attributes ("Nombre Anterior",renderer4,"text", nom_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp3);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp4= gtk_tree_view_column_new_with_attributes ("Direccion Anterior",renderer4,"text", dir_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp4);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp5 = gtk_tree_view_column_new_with_attributes ("Telefono Anterior",renderer4,"text", tel_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp5);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp6 = gtk_tree_view_column_new_with_attributes ("Region Anterior",renderer4,"text", reg_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp6);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp7 = gtk_tree_view_column_new_with_attributes ("Pais Anterior",renderer4,"text", pais_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp7);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp8 = gtk_tree_view_column_new_with_attributes ("RFC Anterior",renderer4,"text", rfc_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp8);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp9 = gtk_tree_view_column_new_with_attributes ("Estado Anterior",renderer4,"text", estado_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp9);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp10 = gtk_tree_view_column_new_with_attributes ("Correo Anterior",renderer4,"text", corr_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp10);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp11 = gtk_tree_view_column_new_with_attributes ("Nombre Nuevo",renderer4,"text", nom_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp11);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp12 = gtk_tree_view_column_new_with_attributes ("Direccion Nuevo",renderer4,"text", dir_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp12);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp13 = gtk_tree_view_column_new_with_attributes ("Telefono Nuevo",renderer4,"text",tel_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp13);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp14 = gtk_tree_view_column_new_with_attributes ("Region Nuevo",renderer4,"text", reg_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp14);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp15 = gtk_tree_view_column_new_with_attributes ("Pais Nuevo",renderer4,"text", pais_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp15);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp16 = gtk_tree_view_column_new_with_attributes ("RFC Nuevo",renderer4,"text", rfc_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp16);
	renderer = gtk_cell_renderer_text_new ();
	column_aud_emp17 = gtk_tree_view_column_new_with_attributes ("Estado Nuevo",renderer4,"text", estado_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp17);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp18 = gtk_tree_view_column_new_with_attributes ("Correo Nuevo",renderer4,"text", corr_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp18);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp19 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer4,"text", user_emp_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp19);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp20 = gtk_tree_view_column_new_with_attributes ("Fecha",renderer4,"text", modifi_emp_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp20);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp21 = gtk_tree_view_column_new_with_attributes ("Accion",renderer4,"text", accion_emp_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp21);
	
	model4 = create_empresa_auditoria();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view4), model4);
	g_object_unref (model4);
	return view4;
}

static GtkTreeModel *create_factura_auditoria (void)
{
	store5 = gtk_list_store_new (NUM_COLS_au_fac, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store5, &iter5);
	gtk_list_store_set (store5, &iter5,
	idaud_fac,row[0],
	id_ticket,row[1],
	ant_user,row[2],
	ant_total,row[3],
	ant_recibido,row[4],
	ant_cambio,row[5],
	ant_pago,row[6],
	ant_hora,row[7],
	new_user,row[8],
	new_total,row[9],
	new_recibido,row[10],
	new_cambio,row[11],
	new_pago,row[12],
	new_hora,row[13],
	user_fac,row[14],
	mod_fac,row[15],
	accion_fac,row[16],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store5, &iter5);
	gtk_list_store_set (store5, &iter5,
	idaud_fac,row[0],
	id_ticket,row[1],
	ant_user,row[2],
	ant_total,row[3],
	ant_recibido,row[4],
	ant_cambio,row[5],
	ant_pago,row[6],
	ant_hora,row[7],
	new_user,row[8],
	new_total,row[9],
	new_recibido,row[10],
	new_cambio,row[11],
	new_pago,row[12],
	new_hora,row[13],
	user_fac,row[14],
	mod_fac,row[15],
	accion_fac,row[16],-1);
}
	return GTK_TREE_MODEL (store5);
}
 
 static GtkWidget *titulo_factura_auditoria (void)
{
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac = gtk_tree_view_column_new_with_attributes ("ID",renderer5,"text", idaud_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac2 = gtk_tree_view_column_new_with_attributes ("ID Ticket",renderer5,"text", id_ticket,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac2);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac3= gtk_tree_view_column_new_with_attributes ("Usuario Anterior",renderer5,"text", ant_user,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac3);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac4= gtk_tree_view_column_new_with_attributes ("Total Anterior",renderer5,"text", ant_total,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac4);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac5= gtk_tree_view_column_new_with_attributes ("Recibido Anterior",renderer5,"text", ant_recibido,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac5);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac6 = gtk_tree_view_column_new_with_attributes ("Cambio Anterior",renderer5,"text", ant_cambio,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac6);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac7 = gtk_tree_view_column_new_with_attributes ("Modo Pago Ant.",renderer5,"text", ant_pago,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac7);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac8 = gtk_tree_view_column_new_with_attributes ("Fecha Anterior",renderer5,"text", ant_hora,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac8);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac9 = gtk_tree_view_column_new_with_attributes ("Usuario Nuevo",renderer5,"text", new_user,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac9);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac10 = gtk_tree_view_column_new_with_attributes ("Total Nuevo",renderer5,"text", new_total,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac10);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac11 = gtk_tree_view_column_new_with_attributes ("Recibido Nuevo",renderer5,"text", new_recibido,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac11);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac12 = gtk_tree_view_column_new_with_attributes ("Cambio Nuevo",renderer5,"text", new_cambio,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac12);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac13= gtk_tree_view_column_new_with_attributes ("Tipo Pago Nuevo.",renderer5,"text", new_pago,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac13);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac14 = gtk_tree_view_column_new_with_attributes ("Hora Nuevo",renderer5,"text", new_hora,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac14);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac15 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer5,"text", user_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac15);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac16 = gtk_tree_view_column_new_with_attributes ("Fecha",renderer5,"text", mod_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac16);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac17 = gtk_tree_view_column_new_with_attributes ("Accion",renderer5,"text", accion_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac17);
	
	
	model5 = create_factura_auditoria();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view5), model5);
	g_object_unref (model5);
	return view5;
}
   
static GtkTreeModel *create_producto_auditoria (void)
{
	store6 = gtk_list_store_new (NUM_COLS_au_pro, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store6, &iter6);
	gtk_list_store_set (store6, &iter6,
		Id,row[0],              
		Cod_barra,row[1],
		Nombre_ant,row[2],      
		Marca_ant,row[3],       
		Fecha_proc_ant,row[4],  
		Fecha_cad_ant,row[5],   
		Numero_lote_ant,row[6], 
		Nota_ant ,row[7],       
		Piezas_ant,row[8],      
		Compra_ant,row[9],      
		Venta_ant,row[10],       
		Categoria_ant,row[11],   
		Subcategoria_ant,row[12],
		Nombre_new,row[13],      
		Marca_new,row[14],       
		Fecha_proc_new,row[15],  
		Fecha_cad_new ,row[16],  
		Numero_lote_new ,row[17],
		Nota_new,row[18],        
		Piezas_new,row[19],      
		Compra_new ,row[20],     
		Venta_new,row[21],       
		Categoria_new,row[22],   
		Subcategoria_new,row[23],
		Usuario,row[24],         
		Fecha_mod,row[25],       
		Accion,row[26] ,-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store6, &iter6);
	gtk_list_store_set (store6, &iter6,
		Id,row[0],              
		Cod_barra,row[1],
		Nombre_ant,row[2],      
		Marca_ant,row[3],       
		Fecha_proc_ant,row[4],  
		Fecha_cad_ant,row[5],   
		Numero_lote_ant,row[6], 
		Nota_ant ,row[7],       
		Piezas_ant,row[8],      
		Compra_ant,row[9],      
		Venta_ant,row[10],       
		Categoria_ant,row[11],   
		Subcategoria_ant,row[12],
		Nombre_new,row[13],      
		Marca_new,row[14],       
		Fecha_proc_new,row[15],  
		Fecha_cad_new ,row[16],  
		Numero_lote_new ,row[17],
		Nota_new,row[18],        
		Piezas_new,row[19],      
		Compra_new ,row[20],     
		Venta_new,row[21],       
		Categoria_new,row[22],   
		Subcategoria_new,row[23],
		Usuario,row[24],         
		Fecha_mod,row[25],       
		Accion,row[26] ,-1);
}
	return GTK_TREE_MODEL (store6);
}

static GtkWidget *titulo_producto_auditoria (void)
{
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro = gtk_tree_view_column_new_with_attributes ("ID",renderer6,"text", Id,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro2 = gtk_tree_view_column_new_with_attributes ("SKU",renderer6,"text", Cod_barra,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro2);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro3= gtk_tree_view_column_new_with_attributes ("Nombre y Descripcion Ant.",renderer6,"text", Nombre_ant,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro3);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro4= gtk_tree_view_column_new_with_attributes ("Marca Ant.",renderer6,"text", Marca_ant ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro4);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro5= gtk_tree_view_column_new_with_attributes ("Fecha Produccion Ant.",renderer6,"text", Fecha_proc_ant ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro5);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro6= gtk_tree_view_column_new_with_attributes ("Fecha Caducidad Ant.",renderer6,"text", Fecha_cad_ant ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro6);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro7 = gtk_tree_view_column_new_with_attributes ("Numero de Lote Ant",renderer6,"text",Numero_lote_ant,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro7);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro8 = gtk_tree_view_column_new_with_attributes ("Nota Anterior",renderer6,"text",Nota_ant ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro8);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro9 = gtk_tree_view_column_new_with_attributes ("Piezas Anteriores",renderer6,"text", Piezas_ant ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro9);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro10 = gtk_tree_view_column_new_with_attributes ("Compra Ant.",renderer6,"text", Compra_ant,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro10);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro11= gtk_tree_view_column_new_with_attributes ("Venta Ant.",renderer6,"text",Venta_ant,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro11);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro12= gtk_tree_view_column_new_with_attributes ("Categoria Ant.",renderer6,"text",Categoria_ant,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro12);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro13 = gtk_tree_view_column_new_with_attributes ("Subcategoria Ant.",renderer6,"text", Subcategoria_ant,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro13);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro14= gtk_tree_view_column_new_with_attributes ("Nombre Nuevo",renderer6,"text",Nombre_new,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro14);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro15 = gtk_tree_view_column_new_with_attributes ("Marca Nuevo",renderer6,"text",Marca_new,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro15);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro16 = gtk_tree_view_column_new_with_attributes ("Fecha Produccion Nuevo",renderer6,"text",Fecha_proc_new ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro16);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro17 = gtk_tree_view_column_new_with_attributes ("Fecha Caducidad Nuevo",renderer6,"text", Fecha_cad_new,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro17);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro18 = gtk_tree_view_column_new_with_attributes ("Numero de lote Nuevo",renderer6,"text",Numero_lote_new ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro18);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro19 = gtk_tree_view_column_new_with_attributes ("Nota Nuevo",renderer6,"text",Nota_new,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro19);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro20 = gtk_tree_view_column_new_with_attributes ("Piezas Nuevo",renderer6,"text",Piezas_new,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro20);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro21 = gtk_tree_view_column_new_with_attributes ("Compra Nueva",renderer6,"text",Compra_new,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro21);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro22 = gtk_tree_view_column_new_with_attributes ("Venta Nueva",renderer6,"text",Venta_new,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro22);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro23 = gtk_tree_view_column_new_with_attributes ("Categoria Nueva",renderer6,"text",Categoria_new,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro23);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro24 = gtk_tree_view_column_new_with_attributes ("Subcategoria Nueva",renderer6,"text",Subcategoria_new,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro24);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro25 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer6,"text",Usuario ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro25);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro26 = gtk_tree_view_column_new_with_attributes ("Fecha y Hora",renderer6,"text",Fecha_mod,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro26);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro27 = gtk_tree_view_column_new_with_attributes ("Accion",renderer6,"text",Accion,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro27);
				
	
	model6 = create_producto_auditoria();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view6), model6);
	g_object_unref (model6);
	return view6;
} 
