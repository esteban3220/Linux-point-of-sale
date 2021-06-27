/*
 * BD.c
 * 
 * Copyright 2020 Esteban<esteban@Gigabyte>
 * 
 * This program is free software; you can redistribute it and /or modify
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
 * gcc -Wall -o "%e" "%f" `pkg-config --cflags --libs gtk+-3.0` $(mysql_config --cflags) $(mysql_config --libs)  -rdynamic -lm
 */

#include <stdio.h>
#include <gtk/gtk.h>
#include <mysql.h> 
#include <stdlib.h>

GtkWidget 			*window_login;
GtkWidget 			*bar;
GtkWidget 			*widget_web;
GtkWidget 			*pila_stp;
GtkWidget			*btn_cancelar_stp;
GtkWidget			*btn_actualiza_pro;
GtkButton			*btn_menu_pref;
GtkButton			*btn_menu_pref_devol;
GtkButton				*btn_4cb;
GtkButton				*btn_8cb;
GtkButton				*btn_13cb;
GtkButton			*btn_actualiza_emp;
GtkWidget			*child_menu;
GtkWidget			*child_preferencia;
GtkWidget			*pag_atras;
GtkWidget			*pag_sig;
GtkWidget			*spin_piezas;
GtkWidget			*spin_venta;
GtkWidget			*spin_compra;
GtkWidget 			*bienvenido;
GtkWidget			*btn_menu_pos;
GtkWidget			*pag_proveedor;
GtkWidget			*pag_producto;
GtkWidget			*pag_tickets;
GtkWidget 			*btn_borrar_emp;
GtkWidget				*pro_aceptar_anadir;
GtkWidget 			*switcher;
GtkWidget			*child_sku;
GtkWidget			*cb_cat;
GtkWidget			*cb_bs_cat;
GtkWidget			*cb_subcat;
GtkWidget			*cb_bs_subcat;
GtkWidget			*cb_estado_emp;
GtkWidget			*cb_pais_emp;
GtkWidget			*cb_marcapro;
GtkEntry			*ety_busca_producto;
GtkEntry			*ety_busca_proveedor_producto;
GtkEntry			*ety_busca_categoria;
GtkEntry			*ety_busca_subcategoria;
GtkStack 			*stack_menu_pos;
GtkStack			*stack_sku;
GtkStack			*stack_bus_pos;
GtkStack			*stack_pos;
GtkWidget				*popovermenu1;
GtkStack			*stack_header;
GtkWidget		*ety_busc_producto;
GtkLabel       *lbl_user_bien;
GtkLabel       *lbl_hora;
GtkWidget 			*actualiza_datos_empresa;
GtkWidget			*child_busqueda_pos;
GtkWidget			*child_oculta_bus_pos;
GtkWidget			  *btn_cambiar_usuario;
GtkWidget 			*cancela_and_factura3;
GtkWidget			*btn_Sesion;
GtkWidget			*inserta_datos_productos;
GtkWidget 			*tree_users;
GtkWidget 			*bar;
GtkWidget 			*bar_bien;
GtkWidget			  *btn_aceptar_1;
GtkWidget			  *btn_Rein_Dial;
GtkWidget 			*btn_consulta_emp;
GtkWidget			  *btn_cancelar_adver6;
GtkWidget			  *emp_aceptar_anadir;
GtkWidget	  		*inserta_datos_empresa;
GtkWidget		  	*btn_cancelar_adver3;
GtkWidget 			*pag_usuarios;
GtkWidget 			*pag_bienvenido;
GtkWidget 			*pag_comp;
GtkWidget 			*pag_sumario;
GtkWidget 			*reveal_proveedor;
GtkWidget 			*webview1;
GtkWidget 			*btn_servicios;
GtkWidget			*swchitcher;
GtkWidget			*pop_generar_sku;
GtkWidget			*cb_busca_estado;
GtkEntry        *ety_user_bien;
GtkEntry  			*g_Entry_Usuario;
GtkEntry  			*g_Entry_Contrasena;
GtkEntry 			*ety_emp_bien;
GtkEntry 			*ety_num_bien;
GtkEntry 			*ety_dir_bien;
GtkEntry 			*ety_rfc_bien;
GtkEntry			*ety_contrasena1;
GtkEntry			*ety_contrasena2;
GtkEntry			*ety_pais_emp;
GtkEntry			*ety_estado_emp;

GtkLabel 			*lbl_emp_bien;
GtkLabel 			*lbl_num_bien;
GtkLabel 			*lbl_dir_bien;
GtkLabel 			*lbl_rfc_bien;

GtkStack	  		*pasos;
GtkEntry	  		*entry_buscar;
GtkEntry	  		*ety_idpro;
GtkEntry  			*ety_idemp;
GtkEntry  			*ety_catidad;
GtkEntry  			*ety_precio;
GtkEntry  			*ety_mpago;
GtkEntry  			*ety_desc;
GtkEntry  			*ety_total;
GtkEntry			*ety_busca_proveedor;

GtkWidget			*btn_cancelar_adver1;
GtkWidget			*btn_cancelar_adver2;
GtkWidget			*btn_cancelar_adver4;
GtkWidget			*btn_cancelar_adver5;
GtkWidget			*btn_cancelar_adver6;
GtkWidget			*btn_cancelar_adver7;
GtkWidget			*btn_cancelar_adver8;
GtkWidget			*btn_cancelar_adver9;
GtkWidget			*cb_productos_proveedor;

GtkWidget				*btn_aceptar_a1;

GtkEntry			*id_fac_act;
GtkEntry			*ety_profac_act;
GtkEntry			*ety_empfact_act;
GtkEntry			*ety_cantidafac_act;
GtkEntry			*ety_preci_act;
GtkEntry			*ety_mpago_act;
GtkEntry			*ety_descfac_act1;
GtkEntry			*ety_totalfac_act;

GtkEntry			*ety_produ_emp;
GtkEntry			*ety_nombreemp;
GtkEntry			*ety_direccion;
GtkEntry			*ety_telefono;
GtkEntry			*ety_region;
GtkEntry			*ety_pais;
GtkEntry			*ety_rfc;
GtkEntry			*ety_correoemp;

GtkEntry			*ety_nombrepro;
GtkEntry			*ety_marcapro;
GtkEntry			*ety_nlote;
GtkEntry			*ety_des;
GtkEntry			*ety_cbarra;
GtkEntry			*ety_cneto;

GtkEntry			*ety_id_empresa;
GtkEntry			*ety_id_producto;
GtkEntry			*ety_nombre_act;
GtkEntry			*ety_direccion_act;
GtkEntry			*ety_telefono_act;
GtkEntry			*ety_region_act;
GtkEntry			*ety_pais_act;
GtkEntry			*ety_rfc_act;
GtkEntry			*ety_correo_act;

GtkEntry			*ety_idpro_act;
GtkEntry			*ety_nombrepro_act;
GtkEntry		 	*ety_marcapro_act;
GtkEntry			*ety_nlotepro_act;
GtkEntry			*ety_descpro_act;
GtkEntry			*ety_cbarrapro_act;
GtkEntry			*ety_cnetopro_act;

GtkEntry			*ety_id_fac_borrar;
GtkEntry			*ety_id_emp_borrar;
GtkEntry			*ety_id_pro_borrar;
GtkEntry			*entry_subcat;
GtkWidget 		*g_Dialog_Error;
GtkWidget			*child_tam_sku;
GtkWidget			*window_BD;
GtkWidget 		*reveal_consulta;
GtkWidget			*inserta_factura;
GtkWidget			*inserta_producto;
GtkWidget			*inserta_empresa;	
GtkWidget			*actualiza_factura;
GtkWidget			*actualiza_producto;
GtkWidget			*actualiza_empresa;
GtkWidget 			*info_bar_bien;
GtkWidget 		*pop_delete_fac;
GtkWidget 		*pop_delete_emp;
GtkWidget 		*pop_delete_pro;
GtkWidget 		*box_act_emp;
GtkWidget 		*info_eliminado;
GtkWidget 		*info_ananido;
GtkWidget 		*info_actualizar;

GtkWidget			*win_acercade;
GtkWidget			*source_code;
GtkWidget			*pop_calendario;
GtkLabel			*La_lbl_Titulo_BD;
GtkLabel			*La_Label_Error_ingreso;
GtkWidget			*lbl_no_datos;
GtkLabel			*lbl_anadir_advertencia;
GtkLabel			*lbl_eliminar_advertencia;
GtkLabel			*lbl_error;
GtkLabel			*lbl_info;
GtkLabel 			*lbl_info_bien;
GtkWidget			*cb_anio_fac;
GtkWidget			*cb_mes_fac;
GtkWidget			*cb_dia_fac;
GtkWidget			*cb_anio_pro;
GtkWidget			*cb_mes_pro;
GtkWidget			*cb_dia_pro;
GtkWidget			*cb_anio_propro;
GtkWidget			*cb_mes_propro;
GtkWidget			*cb_dia_propro;
GtkToggleButton		*btn_eliminar_datos;
GtkToggleButton 	*btn_buscar_pos;
GtkToggleButton		*btn_consulta_pos;
GtkToggleButton 	*btn_edit_proveedor;
GtkToggleButton		*btn_edit_productos;
GtkWidget			*reveal_productos;
GtkWidget			*cb_anio_fac_actu;
GtkWidget			*cb_mes_fac_actu;
GtkWidget			*cb_dia_fac_actu;

GtkWidget			*cb_dia_proact;
GtkWidget			*cb_mes_proact;
GtkWidget			*cb_anio_proact;

GtkWidget			*cb_dia_proact2;
GtkWidget			*cb_mes_proact2;
GtkWidget			*cb_anio_proact2;


GtkWidget			*pag_pos;
GtkWidget			*tabla_items;
GtkWidget			*muestra_func;
GtkWidget			*switchgtk;
GtkWidget			*stack_sql;
GtkWidget			*stack_historial;
GtkWidget			*stack_aceptar;
GtkWidget	 		*exportar_pdf;
GtkWidget			*btn_sql_aceptar;
GtkWidget			*ocultar_btn;
GtkWidget     	*view;
GtkWidget    	*view2;
GtkWidget    	*view3;
GtkWidget    	*view4;
GtkWidget    	*view5;
GtkWidget    	*view6;
GtkWidget 		*revel_bucar;
GtkWidget	 		*treeview_pos;
GtkWidget			*dialog_error_datos;
GtkWidget			*view_busc;
GtkWidget			*stack_busqueda;
GtkWidget			*contenedor_historial;
GtkWidget			*contenedor_busqueda;
GtkWidget			*historial_busqueda;
GtkWidget    	*debug;
GtkWidget			*info_bar;
GtkTextBuffer	*textbuffer_main;
GtkTextView		*debug_textview;
GtkWidget    	*advertencia_anadir_fac;
GtkWidget    	*advertencia_anadir_pro;
GtkWidget    	*advertencia_anadir_emp;
GtkWidget 		*advertencia_actualizar_emp;
GtkWidget     *advertencia_actualizar_fac;
GtkWidget     *advertencia_actualizar_pro;
GtkWidget     *advertencia_eliminar_fac;
GtkWidget     *advertencia_eliminar_emp;
GtkWidget     *advertencia_eliminar_pro;
GtkWidget			*contenedor_view;
GtkWidget			*contenedor_view2;
GtkWidget			*contenedor_view3;
GtkWidget			*contenedor_view4;
GtkWidget			*contenedor_view5;
GtkWidget			*contenedor_view6;
GtkWidget			*contenedor_sql;
GtkWidget 			*acerca_de;
GtkWidget     *stackgtk;
GtkWidget			*stack_actualiza;
MYSQL 				*conn;
MYSQL_RES 		*res;
MYSQL_ROW 		  row;
GtkListStore  *store;
GtkTreeIter    iter;
GtkTreeIter    iter2;
GtkTreeIter    iter3;
GtkTreeIter    iter4;
GtkTreeIter    iter5;
GtkTreeIter    iter6;
GtkTreeIter    iter_busqueda;
GtkTreeIter    iter_user;
GtkTreeIter    iter_pos;
GtkCellRenderer     *renderer;
GtkCellRenderer     *renderer_pos;
GtkCellRenderer     *renderer_user;
GtkCellRenderer     *renderer2;
GtkCellRenderer     *renderer3;
GtkCellRenderer     *renderer4;
GtkCellRenderer     *renderer5;
GtkCellRenderer     *renderer6;
GtkTreeModel        *model;
GtkTreeModel        *model_pos;
GtkTreeModel        *model2;
GtkTreeModel        *model3;
GtkTreeModel        *model4;
GtkTreeModel        *model5;
GtkTreeModel        *model6;
GtkTreeModel        *model_busc;
GtkTreeModel        *model_user;
GtkListStore  		*store2;
GtkListStore  		*store_pos;
GtkListStore  		*store_user;
GtkListStore  		*store3;
GtkListStore  		*store4;
GtkListStore  		*store5;
GtkListStore  		*store6;
GtkListStore  		*store_busqueda;

GtkTreeViewColumn 	*column_emp;
GtkTreeViewColumn 	*column_emp2;
GtkTreeViewColumn 	*column_emp3;
GtkTreeViewColumn 	*column_emp4;
GtkTreeViewColumn 	*column_emp5;
GtkTreeViewColumn 	*column_emp6;
GtkTreeViewColumn 	*column_emp7;
GtkTreeViewColumn 	*column_emp8;
GtkTreeViewColumn 	*column_emp9;

GtkTreeViewColumn 	*column_fac;
GtkTreeViewColumn 	*column_fac2;
GtkTreeViewColumn 	*column_fac3;
GtkTreeViewColumn 	*column_fac4;
GtkTreeViewColumn 	*column_fac5;
GtkTreeViewColumn 	*column_fac6;
GtkTreeViewColumn 	*column_fac7;
GtkTreeViewColumn 	*column_fac8;
GtkTreeViewColumn 	*column_fac9;

GtkTreeViewColumn 	*column_pro;
GtkTreeViewColumn 	*column_pro2;
GtkTreeViewColumn 	*column_pro3;
GtkTreeViewColumn 	*column_pro4;
GtkTreeViewColumn 	*column_pro5;
GtkTreeViewColumn 	*column_pro6;
GtkTreeViewColumn 	*column_pro7;
GtkTreeViewColumn 	*column_pro8;
GtkTreeViewColumn 	*column_pro9;
GtkTreeViewColumn 	*column_pro10;
GtkTreeViewColumn 	*column_pro11;
GtkTreeViewColumn 	*column_pro12;

GtkTreeViewColumn 	*column_aud_emp;
GtkTreeViewColumn 	*column_aud_emp2;
GtkTreeViewColumn 	*column_aud_emp3;
GtkTreeViewColumn 	*column_aud_emp4;
GtkTreeViewColumn 	*column_aud_emp5;
GtkTreeViewColumn 	*column_aud_emp6;
GtkTreeViewColumn 	*column_aud_emp7;
GtkTreeViewColumn 	*column_aud_emp8;
GtkTreeViewColumn 	*column_aud_emp9;
GtkTreeViewColumn 	*column_aud_emp10;
GtkTreeViewColumn 	*column_aud_emp11;
GtkTreeViewColumn 	*column_aud_emp12;
GtkTreeViewColumn 	*column_aud_emp13;
GtkTreeViewColumn 	*column_aud_emp14;
GtkTreeViewColumn 	*column_aud_emp15;
GtkTreeViewColumn 	*column_aud_emp16;
GtkTreeViewColumn 	*column_aud_emp17;
GtkTreeViewColumn 	*column_aud_emp18;
GtkTreeViewColumn 	*column_aud_emp19;
GtkTreeViewColumn 	*column_aud_emp20;
GtkTreeViewColumn 	*column_aud_emp21;

GtkTreeViewColumn 	*column_aud_pro;
GtkTreeViewColumn 	*column_aud_pro2;
GtkTreeViewColumn 	*column_aud_pro3;
GtkTreeViewColumn 	*column_aud_pro4;
GtkTreeViewColumn 	*column_aud_pro5;
GtkTreeViewColumn 	*column_aud_pro6;
GtkTreeViewColumn 	*column_aud_pro7;
GtkTreeViewColumn 	*column_aud_pro8;
GtkTreeViewColumn 	*column_aud_pro9;
GtkTreeViewColumn 	*column_aud_pro10;
GtkTreeViewColumn 	*column_aud_pro11;
GtkTreeViewColumn 	*column_aud_pro12;
GtkTreeViewColumn 	*column_aud_pro13;
GtkTreeViewColumn 	*column_aud_pro14;
GtkTreeViewColumn 	*column_aud_pro15;
GtkTreeViewColumn 	*column_aud_pro16;
GtkTreeViewColumn 	*column_aud_pro17;
GtkTreeViewColumn 	*column_aud_pro18;
GtkTreeViewColumn 	*column_aud_pro19;
GtkTreeViewColumn 	*column_aud_pro20;
GtkTreeViewColumn 	*column_aud_pro21;

GtkTreeViewColumn 	*column_aud_fac;
GtkTreeViewColumn 	*column_aud_fac2;
GtkTreeViewColumn 	*column_aud_fac3;
GtkTreeViewColumn 	*column_aud_fac4;
GtkTreeViewColumn 	*column_aud_fac5;
GtkTreeViewColumn 	*column_aud_fac6;
GtkTreeViewColumn 	*column_aud_fac7;
GtkTreeViewColumn 	*column_aud_fac8;
GtkTreeViewColumn 	*column_aud_fac9;
GtkTreeViewColumn 	*column_aud_fac10;
GtkTreeViewColumn 	*column_aud_fac11;
GtkTreeViewColumn 	*column_aud_fac12;
GtkTreeViewColumn 	*column_aud_fac13;
GtkTreeViewColumn 	*column_aud_fac14;
GtkTreeViewColumn 	*column_aud_fac15;
GtkTreeViewColumn 	*column_aud_fac16;
GtkTreeViewColumn 	*column_aud_fac17;
GtkTreeViewColumn 	*column_aud_fac18;
GtkTreeViewColumn 	*column_aud_fac19;
GtkTreeViewColumn 	*column_aud_fac20;
GtkTreeViewColumn 	*column_aud_fac21;

GtkTreeViewColumn 	*column_fac_bus;
GtkTreeViewColumn 	*column_fac2_bus;
GtkTreeViewColumn 	*column_fac3_bus;
GtkTreeViewColumn 	*column_fac4_bus;
GtkTreeViewColumn 	*column_fac5_bus;
GtkTreeViewColumn 	*column_fac6_bus;
GtkTreeViewColumn 	*column_fac7_bus;
GtkTreeViewColumn 	*column_fac8_bus;
GtkTreeViewColumn 	*column_fac9_bus;

GtkTreeViewColumn 	*column_users;

GtkTreeSelection 	*seleccion_view;
GtkTreeSelection 	*seleccion_view2;
GtkTreeSelection 	*selection; 
static guint search_progress_id = 0;
static guint finish_search_id = 0;
gboolean timer_handler();
	
FILE* 			fichero;
FILE* 			fichero2;
FILE* 			fichero3;
const char 		*user;
const char 		*password;
char *database = "Tienda";

enum {
  LIST_ITEM = 0,
  N_COLUMNS_BUS
};

enum
{
	COLid,
	COLidproc,
	COLnombre,
	COLdireccion,
	COLtelefono,
	COLregion,
	COLpais,
	COLrfc,
	COLcorreo,
	NUM_COLS
} ;
enum
{
	COLidfac,
	COLidproduc,
	COLidempresa,
	COLfechaventa,
	COLcantidad,
	COLprecio,
	COLmodopago,
	COLdescuento,
	COLtotal,
	NUM_COLS_fac
} ;
enum
{
	COLidproducto,
	COLnomprod, 
	COLmarca, 
	COLfechaproduccion, 
	COLfechacaducidad, 
	COLnumlote,
	COLneto, 
	COLpiezas, 
	COLcompra, 
	COLventa, 
	COLcategoria, 
	COLsubcategoria, 
	NUM_COLS_pro
} ;
enum
{
	id_aud_emp,
	id_pro_ant_emp,
	nom_ant_emp,
	dir_ant_emp,
	tel_ant_emp,
	reg_ant_emp,
	pais_ant_emp,
	rfc_ant_emp,
	corr_ant_emp,
	id_pro_new_emp,
	nom_new_emp,
	dir_new_emp,
	tel_new_emp,
	reg_new_emp,
	pais_new_emp,
	rfc_new_emp,
	corr_new_emp,
	user_emp_emp,
	modifi_emp_emp,
	accion_emp_emp,
	id_emp_au_emp,
	NUM_COLS_au_emp
} ;

enum
{
	idaud_fac,
	idpro_ant_fac,
	idemp_ant_fac,
	fechaven_ant_fac,
	cantidad_ant_fac,
	precio_ant_fac,
	modopago_ant_fac,
	descue_ant_fac,
	total_ant_fac,
	idpro_new_fac,
	idemp_new_fac,
	fechaven_new_fac,
	cantidad_new_fac,
	precio_new_fac,
	modopago_new_fac,
	descue_new_fac,
	total_new_fac,
	user_fac,
	mod_fac,
	accion_fac,
	idfac_au_fac,
	NUM_COLS_au_fac
} ;

enum
{
	idaud_pro,
	nom_ant_pro,
	marca_ant_pro,
	fechacad_ant_pro,
	fechapro_ant_pro,
	numlote_ant_pro,
	desc_ant_pro,
	codbarra_ant_pro,
	conneto_ant_pro,
	nom_new_pro,
	marca_new_pro,
	fechacad_new_pro,
	fechapro_new_pro,
	numlote_new_pro,
	desc_new_pro,
	codbarra_new_pro,
	conneto_new_pro,
	user_pro,
	mod_pro,
	accion_pro,
	idpro_au_pro,
	NUM_COLS_au_pro
};


enum
{
	cantidad_pos,
	producto_pos,
	punitario_pos,
	precio_pos,
	NUM_COLS_pos
};

enum
{
	COLid_bus,
	COLnomant_bus,
	COLedadant_bus,
	COLapodoant_bus,
	COLpoderes_bus,
	COLsexo_bus,
	COLestatura_bus,
	Colbarra,
	conneto,
	NUM_COLS_bus
};

enum
{
	Col_user,
	NUM_COLS_user
};


   /*
static GtkTreeModel * POS (void)
{
	store_pos = gtk_list_store_new (NUM_COLS_pos, G_TYPE_INT,G_TYPE_STRING,G_TYPE_DOUBLE,G_TYPE_DOUBLE);
	
	gtk_list_store_append (store_pos, &iter_pos);
	gtk_list_store_set (store_pos, &iter_pos,cantidad_pos, row[0],
	producto_pos, row[1],
	punitario_pos, row[2],
	precio_pos,row[3]-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store_pos, &iter_pos);
	gtk_list_store_set (store_pos, &iter_pos,cantidad_pos, row[0],
	producto_pos, row[1],
	punitario_pos, row[2],
	precio_pos,row[3]-1);
}
	return GTK_TREE_MODEL (store_pos);
}
 static GtkWidget *titulo_POS(void)
{	
	renderer_pos = gtk_cell_renderer_text_new ();
	column_emp = gtk_tree_view_column_new_with_attributes  ("Cantidad",renderer_pos,"text", cantidad_pos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (treeview_pos),column_emp);
	renderer_pos = gtk_cell_renderer_text_new ();
	column_emp2 = gtk_tree_view_column_new_with_attributes ("Producto",renderer_pos,"text", producto_pos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (treeview_pos),column_emp2);
	renderer_pos = gtk_cell_renderer_text_new ();
	column_emp3 = gtk_tree_view_column_new_with_attributes  ("P. Unitario",renderer_pos,"text", punitario_pos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (treeview_pos),column_emp3);
	renderer_pos = gtk_cell_renderer_text_new ();
	column_emp4 = gtk_tree_view_column_new_with_attributes  ("Total",renderer_pos,"text", precio_pos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (treeview_pos),column_emp4);
	
	
	model_pos = POS ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_pos), model_pos);
	g_object_unref (model_pos);
	return treeview_pos;
}
	*/
static GtkTreeModel * create_empresa (void)
{
	store = gtk_list_store_new (NUM_COLS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
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
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store2, &iter2);
	gtk_list_store_set (store2, &iter2,
	COLidfac, row[0],
	COLidproduc, row[1],
	COLidempresa, row[2],
	COLfechaventa, row[3],
	COLcantidad, row[4],
	COLprecio, row[5],
	COLmodopago, row[6],
	COLdescuento, row[7],
	COLtotal, row[8],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store2, &iter2);
	gtk_list_store_set (store2, &iter2,
	COLidfac, row[0],
	COLidproduc, row[1],
	COLidempresa, row[2],
	COLfechaventa, row[3],
	COLcantidad, row[4],
	COLprecio, row[5],
	COLmodopago, row[6],
	COLdescuento, row[7],
	COLtotal, row[8],-1);
}
	return GTK_TREE_MODEL (store2);
}
	   
 static GtkWidget *titulo_factura(void)
{	
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac = gtk_tree_view_column_new_with_attributes  ("ID Factura",renderer2,"text", COLidfac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac2 = gtk_tree_view_column_new_with_attributes ("ID Producto",renderer2,"text", COLidproduc,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac2);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac3 = gtk_tree_view_column_new_with_attributes  ("ID Empresa",renderer2,"text", COLidempresa,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac3);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac4 = gtk_tree_view_column_new_with_attributes  ("Fecha de Venta",renderer2,"text", COLfechaventa,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac4);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac5 = gtk_tree_view_column_new_with_attributes  ("Cantidad",renderer2,"text", COLcantidad,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac5);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac6 = gtk_tree_view_column_new_with_attributes ("Precio",renderer2,"text", COLprecio,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac6);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac7 = gtk_tree_view_column_new_with_attributes ("Modo Pago",renderer2,"text", COLmodopago,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac7);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac8 = gtk_tree_view_column_new_with_attributes ("Descuento",renderer2,"text", COLdescuento,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac8);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac9 = gtk_tree_view_column_new_with_attributes ("Total",renderer2,"text", COLtotal,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac9);
	
	model2 = create_factura ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view2), model2);
	g_object_unref (model2);
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
 /*  
static GtkTreeModel *create_empresa_auditoria (void)
{
	store4 = gtk_list_store_new (NUM_COLS_au_emp, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store4, &iter4);
	gtk_list_store_set (store4, &iter4,id_aud_emp,row[0],
	id_pro_ant_emp,row[1],
	nom_ant_emp,row[2],
	dir_ant_emp,row[3],
	tel_ant_emp,row[4],
	reg_ant_emp,row[5],
	pais_ant_emp,row[6],
	rfc_ant_emp,row[7],
	corr_ant_emp,row[8],
	id_pro_new_emp,row[9],
	nom_new_emp,row[10],
	dir_new_emp,row[11],
	tel_new_emp,row[12],
	reg_new_emp,row[13],
	pais_new_emp,row[14],
	rfc_new_emp,row[15],
	corr_new_emp,row[16],
	user_emp_emp,row[17],
	modifi_emp_emp,row[18],
	accion_emp_emp,row[19],
	id_emp_au_emp,row[20],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store4, &iter4);
	gtk_list_store_set (store4, &iter4,id_aud_emp,row[0],
	id_pro_ant_emp,row[1],
	nom_ant_emp,row[2],
	dir_ant_emp,row[3],
	tel_ant_emp,row[4],
	reg_ant_emp,row[5],
	pais_ant_emp,row[6],
	rfc_ant_emp,row[7],
	corr_ant_emp,row[8],
	id_pro_new_emp,row[9],
	nom_new_emp,row[10],
	dir_new_emp,row[11],
	tel_new_emp,row[12],
	reg_new_emp,row[13],
	pais_new_emp,row[14],
	rfc_new_emp,row[15],
	corr_new_emp,row[16],
	user_emp_emp,row[17],
	modifi_emp_emp,row[18],
	accion_emp_emp,row[19],
	id_emp_au_emp,row[20],-1);
}
	return GTK_TREE_MODEL (store4);
}

 static GtkWidget *titulo_empresa_auditoria (void)
{
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp = gtk_tree_view_column_new_with_attributes ("ID",renderer4,"text", id_aud_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp2 = gtk_tree_view_column_new_with_attributes ("ID Producto Ant.",renderer4,"text", id_pro_ant_emp,NULL);
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
	column_aud_emp9 = gtk_tree_view_column_new_with_attributes ("Correo Anterior",renderer4,"text", corr_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp9);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp10 = gtk_tree_view_column_new_with_attributes ("ID Producto Nuevo",renderer4,"text", id_pro_new_emp,NULL);
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
	column_aud_emp17 = gtk_tree_view_column_new_with_attributes ("Correo Nuevo",renderer4,"text", corr_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp17);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp18 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer4,"text", user_emp_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp18);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp19 = gtk_tree_view_column_new_with_attributes ("Modificado",renderer4,"text", modifi_emp_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp19);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp20 = gtk_tree_view_column_new_with_attributes ("Accion",renderer4,"text", accion_emp_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp20);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp21 = gtk_tree_view_column_new_with_attributes ("ID Empresa",renderer4,"text", id_emp_au_emp,NULL);
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
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store5, &iter5);
	gtk_list_store_set (store5, &iter5,idaud_fac,row[0],
	idpro_ant_fac,row[1],
	idemp_ant_fac,row[2],
	fechaven_ant_fac,row[3],
	cantidad_ant_fac,row[4],
	precio_ant_fac,row[5],
	modopago_ant_fac,row[6],
	descue_ant_fac,row[7],
	total_ant_fac,row[8],
	idpro_new_fac,row[9],
	idemp_new_fac,row[10],
	fechaven_new_fac,row[11],
	cantidad_new_fac,row[12],
	precio_new_fac,row[13],
	modopago_new_fac,row[14],
	descue_new_fac,row[15],
	total_new_fac,row[16],
	user_fac,row[17],
	mod_fac,row[18],
	accion_fac,row[19],
	idfac_au_fac,row[20],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store5, &iter5);
	gtk_list_store_set (store5, &iter5,idaud_fac,row[0],
	idpro_ant_fac,row[1],
	idemp_ant_fac,row[2],
	fechaven_ant_fac,row[3],
	cantidad_ant_fac,row[4],
	precio_ant_fac,row[5],
	modopago_ant_fac,row[6],
	descue_ant_fac,row[7],
	total_ant_fac,row[8],
	idpro_new_fac,row[9],
	idemp_new_fac,row[10],
	fechaven_new_fac,row[11],
	cantidad_new_fac,row[12],
	precio_new_fac,row[13],
	modopago_new_fac,row[14],
	descue_new_fac,row[15],
	total_new_fac,row[16],
	user_fac,row[17],
	mod_fac,row[18],
	accion_fac,row[19],
	idfac_au_fac,row[20],-1);
}
	return GTK_TREE_MODEL (store5);
}
 
 static GtkWidget *titulo_factura_auditoria (void)
{
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac = gtk_tree_view_column_new_with_attributes ("ID",renderer5,"text", idaud_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac2 = gtk_tree_view_column_new_with_attributes ("ID Pro. Ant.",renderer5,"text", idpro_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac2);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac3= gtk_tree_view_column_new_with_attributes ("ID Empresa Ant.",renderer5,"text", idemp_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac3);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac4= gtk_tree_view_column_new_with_attributes ("Fecha Venta Ant.",renderer5,"text", fechaven_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac4);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac5= gtk_tree_view_column_new_with_attributes ("Cantidad Ant.",renderer5,"text", cantidad_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac5);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac6 = gtk_tree_view_column_new_with_attributes ("Precio Ant.",renderer5,"text", precio_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac6);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac7 = gtk_tree_view_column_new_with_attributes ("Modo Pago Ant.",renderer5,"text", modopago_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac7);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac8 = gtk_tree_view_column_new_with_attributes ("Descuento Ant.",renderer5,"text", descue_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac8);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac9 = gtk_tree_view_column_new_with_attributes ("Total Ant.",renderer5,"text", total_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac9);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac10 = gtk_tree_view_column_new_with_attributes ("ID Pro. Nuevo",renderer5,"text", idpro_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac10);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac11 = gtk_tree_view_column_new_with_attributes ("ID Empresa Nuevo",renderer5,"text", idemp_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac11);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac12 = gtk_tree_view_column_new_with_attributes ("Fecha Venta Nuevo",renderer5,"text", fechaven_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac12);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac13= gtk_tree_view_column_new_with_attributes ("Cantidad Nuevo.",renderer5,"text", cantidad_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac13);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac14 = gtk_tree_view_column_new_with_attributes ("Precio Nuevo",renderer5,"text", precio_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac14);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac15 = gtk_tree_view_column_new_with_attributes ("Modo Pago Nuevo",renderer5,"text", modopago_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac15);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac16 = gtk_tree_view_column_new_with_attributes ("Descuento Nuevo",renderer5,"text", descue_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac16);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac17 = gtk_tree_view_column_new_with_attributes ("Total Nuevo",renderer5,"text", total_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac17);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac18 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer5,"text", user_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac18);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac19 = gtk_tree_view_column_new_with_attributes ("Modificado",renderer5,"text", mod_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac19);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac20 = gtk_tree_view_column_new_with_attributes ("Accion",renderer5,"text", accion_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac20);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac21 = gtk_tree_view_column_new_with_attributes ("ID Factura",renderer5,"text", idfac_au_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac21);
	
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
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store6, &iter6);
	gtk_list_store_set (store6, &iter6,idaud_pro,row[0],
	nom_ant_pro,row[1],
	marca_ant_pro,row[2],
	fechacad_ant_pro,row[3],
	fechapro_ant_pro,row[4],
	numlote_ant_pro,row[5],
	desc_ant_pro,row[6],
	codbarra_ant_pro,row[7],
	conneto_ant_pro,row[8],
	nom_new_pro,row[9],
	marca_new_pro,row[10],
	fechacad_new_pro,row[11],
	fechapro_new_pro,row[12],
	numlote_new_pro,row[13],
	desc_new_pro,row[14],
	codbarra_new_pro,row[15],
	conneto_new_pro,row[16],
	user_pro,row[17],
	mod_pro,row[18],
	accion_pro,row[19],
	idpro_au_pro,row[20],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store6, &iter6);
	gtk_list_store_set (store6, &iter6,idaud_pro,row[0],
	nom_ant_pro,row[1],
	marca_ant_pro,row[2],
	fechacad_ant_pro,row[3],
	fechapro_ant_pro,row[4],
	numlote_ant_pro,row[5],
	desc_ant_pro,row[6],
	codbarra_ant_pro,row[7],
	conneto_ant_pro,row[8],
	nom_new_pro,row[9],
	marca_new_pro,row[10],
	fechacad_new_pro,row[11],
	fechapro_new_pro,row[12],
	numlote_new_pro,row[13],
	desc_new_pro,row[14],
	codbarra_new_pro,row[15],
	conneto_new_pro,row[16],
	user_pro,row[17],
	mod_pro,row[18],
	accion_pro,row[19],
	idpro_au_pro,row[20],-1);
}
	return GTK_TREE_MODEL (store6);
}
static GtkWidget *titulo_producto_auditoria (void)
{
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro = gtk_tree_view_column_new_with_attributes ("ID",renderer6,"text", idaud_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro2 = gtk_tree_view_column_new_with_attributes ("Nombre Ant.",renderer6,"text", nom_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro2);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro3= gtk_tree_view_column_new_with_attributes ("Marca Ant.",renderer6,"text", marca_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro3);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro4= gtk_tree_view_column_new_with_attributes ("Fecha Cad. Ant.",renderer6,"text", fechacad_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro4);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro5= gtk_tree_view_column_new_with_attributes ("Fecha Prod. Ant.",renderer6,"text", fechapro_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro5);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro6= gtk_tree_view_column_new_with_attributes ("Num. Lote Ant.",renderer6,"text", numlote_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro6);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro7 = gtk_tree_view_column_new_with_attributes ("Descripcion Ant.",renderer6,"text", desc_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro7);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro8 = gtk_tree_view_column_new_with_attributes ("Cod. Barras Ant.",renderer6,"text", codbarra_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro8);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro9 = gtk_tree_view_column_new_with_attributes ("Cont. Neto Ant.",renderer6,"text", conneto_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro9);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro10 = gtk_tree_view_column_new_with_attributes ("Nombre Nuevo",renderer6,"text", nom_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro10);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro11= gtk_tree_view_column_new_with_attributes ("Marca Nuevo",renderer6,"text", marca_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro11);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro12= gtk_tree_view_column_new_with_attributes ("Fecha Cad. Nuevo",renderer6,"text", fechacad_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro12);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro13 = gtk_tree_view_column_new_with_attributes ("Fecha Prod. Nuevo",renderer6,"text", fechapro_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro13);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro14= gtk_tree_view_column_new_with_attributes ("Num. Lote Nuevo",renderer6,"text", numlote_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro14);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro15 = gtk_tree_view_column_new_with_attributes ("Descripcion Ant.",renderer6,"text", desc_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro15);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro16 = gtk_tree_view_column_new_with_attributes ("Cod. Barras Nuevo",renderer6,"text", codbarra_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro16);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro17 = gtk_tree_view_column_new_with_attributes ("Cont. Neto Nuevo",renderer6,"text", conneto_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro17);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro18 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer6,"text", user_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro18);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro19 = gtk_tree_view_column_new_with_attributes ("Modificado",renderer6,"text", mod_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro19);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro20 = gtk_tree_view_column_new_with_attributes ("Accion",renderer6,"text", accion_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro20);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro21 = gtk_tree_view_column_new_with_attributes ("ID Producto",renderer6,"text", idpro_au_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro21);
	
	model6 = create_producto_auditoria();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view6), model6);
	g_object_unref (model6);
	return view6;
}      
static GtkTreeModel * create_and_fill_model_busqueda (void)
{
	store_busqueda = gtk_list_store_new (NUM_COLS_bus, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store_busqueda, &iter_busqueda);
	gtk_list_store_set (store_busqueda, &iter_busqueda,COLid_bus, row[0],
	COLnomant_bus, row[1],
	COLedadant_bus, row[2],
	COLapodoant_bus, row[3],
	COLpoderes_bus, row[4],
	COLsexo_bus, row[5],
	COLestatura_bus, row[6],
	Colbarra, row[7],
	conneto, row[8],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store_busqueda, &iter_busqueda);
	gtk_list_store_set (store_busqueda, &iter_busqueda,COLid_bus, row[0],
	COLnomant_bus, row[1],
	COLedadant_bus, row[2],
	COLapodoant_bus, row[3],
	COLpoderes_bus, row[4],
	COLsexo_bus, row[5],
	COLestatura_bus, row[6],
	Colbarra, row[7],
	conneto, row[8],-1);
}
	return GTK_TREE_MODEL (store_busqueda);
}


 static GtkWidget *titulo_factura_auditoria_busqueda (void)
{	
	renderer = gtk_cell_renderer_text_new ();
	column_fac_bus = gtk_tree_view_column_new_with_attributes  ("ID Pro",renderer,"text", COLid_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac2_bus = gtk_tree_view_column_new_with_attributes ("Nombre",renderer,"text", COLnomant_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac2_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac3_bus = gtk_tree_view_column_new_with_attributes  ("Marca",renderer,"text", COLedadant_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac3_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac4_bus = gtk_tree_view_column_new_with_attributes  ("F. Caducidad",renderer,"text", COLapodoant_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac4_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac5_bus = gtk_tree_view_column_new_with_attributes  ("F. Produccion",renderer,"text", COLpoderes_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac5_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac6_bus = gtk_tree_view_column_new_with_attributes ("N. Lote",renderer,"text", COLsexo_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac6_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac7_bus = gtk_tree_view_column_new_with_attributes ("Descripcion",renderer,"text", COLestatura_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac7_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac8_bus = gtk_tree_view_column_new_with_attributes ("Codigo Barra",renderer,"text", Colbarra,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac8_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac9_bus = gtk_tree_view_column_new_with_attributes ("Con. Neto",renderer,"text", conneto,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac9_bus);
	
	model_busc = create_and_fill_model_busqueda ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view_busc), model_busc);
	g_object_unref (model_busc);
	return view_busc;
}

*/
void contenido_ticket(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char *server = "localhost";
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	if (mysql_query(conn, "select * from Ticket"))
	{ 
	}
	res = mysql_use_result(conn);
while ((row = mysql_fetch_row(res)) != NULL) 
					if (gtk_tree_model_get_iter_first(model2, &iter2) == FALSE) {
						 titulo_factura();
						 return ;
					}
	mysql_free_result(res);
	mysql_close(conn);
}

void contenido_producto(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char *server = "localhost";
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	if (mysql_query(conn, "select * from Producto"))
	{ 
	}
	res = mysql_use_result(conn);
while ((row = mysql_fetch_row(res)) != NULL) 
					if (gtk_tree_model_get_iter_first(model3, &iter3) == FALSE) {
						 titulo_producto();
						 return ;
					} 
	mysql_free_result(res);
	mysql_close(conn);
}
void conectar(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char *server = "localhost";
	conn = mysql_init(NULL);
 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) 
 {
     char tempErr[60];
	 sprintf(tempErr,"%s", mysql_error(conn));
	 gtk_label_set_text(La_Label_Error_ingreso,tempErr);
     return gtk_widget_show(g_Dialog_Error);
 }else
 {
	 gtk_widget_hide_on_delete (window_login);
	 gtk_widget_show(window_BD);	 
}
	 
 if (mysql_query(conn, "select Empresa from Proveedor;")) 
 {
     char tempErr[60];
	 sprintf(tempErr,"%s", mysql_error(conn));
	 gtk_label_set_text(La_Label_Error_ingreso,tempErr);
     return gtk_widget_show(g_Dialog_Error);
 }
 res = mysql_use_result(conn); 

 while ((row = mysql_fetch_row(res)) != NULL){
	 gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_marcapro),row[0]);
	 gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_productos_proveedor),row[0]);
 }
 mysql_free_result(res);
 mysql_close(conn);
 
}

void consulta_proveedor(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char *server = "localhost";
	conn = mysql_init(NULL);
 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) 
 {
}
	 
 if (mysql_query(conn, "select Empresa from Proveedor;")) 
 {
 }
 res = mysql_use_result(conn); 

 while ((row = mysql_fetch_row(res)) != NULL){
 gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_marcapro),row[0]);
 gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_productos_proveedor),row[0]);
}
 mysql_free_result(res);
 mysql_close(conn); 
}

void contenido_tablas(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char *server = "localhost";
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	
	if (mysql_query(conn, "select * from Proveedor"))
	{ 
	}
	res = mysql_use_result(conn);
//==================================================================================================================
while ((row = mysql_fetch_row(res)) != NULL) 
					if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
						 titulo_empresa();
						 return ;
					}  
	mysql_free_result(res);
	mysql_close(conn);
	
	}

void on_btn_cambiar_usuario_clicked()
{
	gtk_entry_set_text(g_Entry_Usuario,"");
	gtk_entry_set_text(g_Entry_Contrasena,"");
	gtk_widget_hide_on_delete(window_BD);
	gtk_widget_show(window_login);
	gtk_widget_hide_on_delete (g_Dialog_Error);
}

void on_acercade_clicked(){
	gtk_widget_show (win_acercade); 
	}
	
void on_acercade_response(){
	gtk_widget_hide_on_delete(win_acercade);
	}
void on_web_response(){
	gtk_widget_hide_on_delete(widget_web);
	}
void on_btn_Sesion_clicked ( gpointer  user_data)
{
	conectar();
	contenido_tablas();
}

void on_Entry_Contrasena_activate(gpointer  user_data)
{	
	conectar();
	contenido_tablas();
	contenido_producto();
	contenido_ticket();
}
	
void on_btn_cancelar_adver3_clicked()
{
	gtk_widget_hide(g_Dialog_Error);
}
	
void on_btn_Rein_Dial_clicked()
	{
		gtk_entry_set_text(g_Entry_Usuario,"");
		gtk_entry_set_text(g_Entry_Contrasena,"");
		gtk_widget_hide_on_delete (g_Dialog_Error);
	}
void refresca_datos_fac(){
	
	if (gtk_tree_model_get_iter_first(model2, &iter2) == TRUE) {
		gtk_list_store_clear(store2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac9);
}
	if (gtk_tree_model_get_iter_first(model5, &iter5) == TRUE) {
		gtk_list_store_clear(store5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac9);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac10);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac11);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac12);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac13);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac14);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac15);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac16);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac17);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac18);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac19);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac20);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac21);
}
	
}
void refresca_datos_emp(){
	
	if (gtk_tree_model_get_iter_first(model, &iter) == TRUE) {
		gtk_list_store_clear(store);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp9);
} /*
	if (gtk_tree_model_get_iter_first(model4, &iter4) == TRUE) {
		gtk_list_store_clear(store4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp9);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp10);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp11);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp12);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp13);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp14);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp15);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp16);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp17);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp18);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp19);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp20);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp21); */

}
void refresca_datos_pro(){
	
	if (gtk_tree_model_get_iter_first(model3, &iter3) == TRUE) {
		gtk_list_store_clear(store3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro9);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro10);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro11);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro12);
}
	/*if (gtk_tree_model_get_iter_first(model6, &iter6) == TRUE) {
		gtk_list_store_clear(store6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro9);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro10);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro11);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro12);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro13);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro14);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro15);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro16);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro17);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro18);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro19);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro20);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro21);
}*/
}
void refresca_busqueda(){
	gtk_list_store_clear(store_busqueda);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac2_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac3_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac4_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac5_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac6_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac7_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac8_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac9_bus);
	}

void on_cancela_and_factura4_clicked(){
		gtk_widget_hide(inserta_producto);
	}
void on_cancela_and_factura2_clicked(){
		gtk_widget_hide(inserta_empresa);
	}
void on_btn_cancelar_adver_clicked(){
	gtk_widget_hide(advertencia_anadir_fac);
	}
void on_cancela_and_factura_clicked(){
	gtk_widget_hide_on_delete(inserta_factura);
	}
	
void on_fac_aceptar_anadir_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char anadir_fac[512];
	char date[12];
	char *server = "localhost";

	const char 		*dia = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_fac));
	const char 		*mes = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_fac));
	const char 		*anio = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_fac));
	const char 		*id_pro = gtk_entry_get_text(ety_idpro);
	const char 		*id_emp = gtk_entry_get_text(ety_idemp);
	const char		*cantidad = gtk_entry_get_text(ety_catidad);
	const char		*precio = gtk_entry_get_text(ety_precio);
	const char		*mpago = gtk_entry_get_text(ety_mpago);
	const char		*descuento = gtk_entry_get_text(ety_desc);
	const char		*total = gtk_entry_get_text(ety_total);
	
	
	sprintf(date,"%s-%s-%s",anio,mes,dia);
	sprintf(anadir_fac,"insert into Factura (Idfactura,Idproducto,Idempresa,Fechadeventa,cantidad,precio,ModoPago,Descuento,Total) values(null,%s,%s,'%s',%s,%s,'%s',%s,%s)",id_pro,id_emp,date,cantidad,precio,mpago,descuento,total);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_anadir_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_idpro,"");
	gtk_entry_set_text(ety_idemp,"");
	gtk_entry_set_text(ety_catidad,"");
	gtk_entry_set_text(ety_precio,"");
	gtk_entry_set_text(ety_mpago,"");
	gtk_entry_set_text(ety_desc,"");
	gtk_entry_set_text(ety_total,"");
	
	refresca_datos_fac();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_anadir_fac);
	gtk_label_set_text(lbl_info,"Dato Insertado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
	}
void on_inserta_datos_factura_clicked(){
		gtk_widget_show(advertencia_anadir_fac);
	}
void on_inserta_datos_empresa_clicked(){
		gtk_widget_show(advertencia_anadir_emp);
	}
	

void on_emp_aceptar_anadir_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char anadir_emp[512];
	char *server = "localhost";

	const char 		*id_prodi = gtk_entry_get_text(ety_produ_emp);
	const char 		*id_nom_emp = gtk_entry_get_text(ety_nombreemp);
	const char		*direccion = gtk_entry_get_text(ety_direccion);
	const char		*telefono = gtk_entry_get_text(ety_telefono);
	const char		*region = gtk_entry_get_text(ety_region);
	const char		*pais = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT (cb_pais_emp));
	const char		*rfc_emp = gtk_entry_get_text(ety_rfc);
	const char		*estado = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT (cb_estado_emp));
	const char		*correo = gtk_entry_get_text(ety_correoemp);
	
	sprintf(anadir_emp,"insert into Proveedor values('%s' , '%s', '%s' , '%s', '%s' , '%s' , '%s' , '%s' , '%s' )",id_prodi,id_nom_emp,direccion,telefono,region,pais,rfc_emp,estado,correo);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_emp))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_anadir_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_produ_emp,"");
	gtk_entry_set_text(ety_nombreemp,"");
	gtk_entry_set_text(ety_direccion,"");
	gtk_entry_set_text(ety_telefono,"");
	gtk_entry_set_text(ety_region,"");
	gtk_entry_set_text(ety_pais_emp,"");
	gtk_entry_set_text(ety_estado_emp,"");
	gtk_entry_set_text(ety_rfc,"");
	gtk_entry_set_text(ety_correoemp,"");
	
	refresca_datos_emp();
	contenido_tablas();

	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_marcapro));
	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_productos_proveedor));
	consulta_proveedor();
	gtk_widget_hide(advertencia_anadir_emp);
	gtk_label_set_text(lbl_info,"Dato Insertado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
}

void on_btn_cancelar_adver6_clicked(){
		gtk_widget_hide(advertencia_anadir_emp);
	}
void on_btn_cancelar_adver7_clicked(){
		gtk_widget_hide(advertencia_anadir_pro);
	}
void on_inserta_datos_empres_clicked(){
		gtk_widget_show(advertencia_anadir_pro);
	}
	
	
void on_pro_aceptar_anadir_clicked (){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char anadir_fac[512];
	char date[12];
	char date2[12];
	char *server = "localhost";

	
	const char 		*dia = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_pro));
	const char 		*mes = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_pro));
	const char 		*anio = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_pro));
	
	const char 		*dia2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_propro));
	const char 		*mes2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_propro));
	const char 		*anio2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_propro));
	
	const char		*cbarra = gtk_entry_get_text(ety_cbarra);
	const char 		*nombre = gtk_entry_get_text(ety_nombrepro);
	const char 		*marca = gtk_entry_get_text(ety_marcapro);
	const char		*nlote = gtk_entry_get_text(ety_nlote);
	const char		*cneto = gtk_entry_get_text(ety_cneto);
	const char		*piezas = gtk_entry_get_text(GTK_ENTRY(spin_piezas));
	const char		*compra = gtk_entry_get_text(GTK_ENTRY(spin_compra));
	const char		*venta = gtk_entry_get_text(GTK_ENTRY(spin_venta));
	const char		*categoria = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_cat));
	const char		*subcat = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_subcat));
	
	
	
	sprintf(date,"%s-%s-%s",anio,mes,dia);
	sprintf(date2,"%s-%s-%s",anio2,mes2,dia2);
	sprintf(anadir_fac,"insert into Producto values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s') ON DUPLICATE KEY UPDATE Nombre='%s',Marca='%s',Fecha_proc='%s',Fecha_cad='%s',Numero_lote='%s',Nota='%s', Piezas=Piezas+%s ,Compra='%s',Venta='%s',Categoria='%s',Subcategoria='%s'",cbarra,nombre,marca,date,date2,nlote,cneto,piezas,compra,venta,categoria,subcat,nombre,marca,date,date2,nlote,cneto,piezas,compra,venta,categoria,subcat);
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_anadir_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_cbarra,"");
	gtk_entry_set_text(ety_nombrepro,"");
	gtk_entry_set_text(ety_marcapro,"");
	gtk_entry_set_text(ety_cneto,"");
	gtk_entry_set_text(ety_nlote,"");
	gtk_entry_set_text(GTK_ENTRY(spin_piezas),"0");
	gtk_entry_set_text(GTK_ENTRY(spin_compra),"0.00");
	gtk_entry_set_text(GTK_ENTRY(spin_venta),"0.00");
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_cat),0);
	gtk_entry_set_text(GTK_ENTRY (entry_subcat),"");	
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_dia_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_mes_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_anio_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_dia_propro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_mes_propro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_anio_propro),0);
	
	refresca_datos_pro();
	contenido_producto();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_anadir_pro);
	gtk_label_set_text(lbl_info,"Dato Insertado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
	}
//================================================

void on_btn_aceptar_1_clicked(){
	gtk_widget_hide(dialog_error_datos);
	}
//=========== Actualiza datos ====================================
void on_btn_aceptar__clicked(){

	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char date[13];
	char actualiza_fac[512];
	char *server = "localhost";
	
	const char 		*id = gtk_entry_get_text(id_fac_act);
	const char 		*idpro = gtk_entry_get_text(ety_profac_act);
	const char 		*idemp = gtk_entry_get_text(ety_empfact_act);
	const char		*cantidad = gtk_entry_get_text(ety_cantidafac_act);
	const char		*precio = gtk_entry_get_text(ety_preci_act);
	const char		*mpago = gtk_entry_get_text(ety_mpago_act);
	const char		*descuento = gtk_entry_get_text(ety_descfac_act1);
	const char		*total = gtk_entry_get_text(ety_totalfac_act);
	
	const char 		*dia = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_fac_actu));
	const char 		*mes = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_fac_actu));
	const char 		*anio2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_fac_actu));

	sprintf(date,"'%s-%s-%s'",anio2,mes,dia);
	sprintf(actualiza_fac,"update Factura set Idproducto=%s, Idempresa=%s, Fechadeventa=%s, cantidad=%s, precio='%s', ModoPago='%s',Descuento=%s,Total=%s where idfactura=%s",idpro,idemp,date,cantidad,precio,mpago,descuento,total,id);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, actualiza_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_actualizar_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	
	gtk_entry_set_text(id_fac_act,"");
	gtk_entry_set_text(ety_profac_act,"");
	gtk_entry_set_text(ety_empfact_act,"");
	gtk_entry_set_text(ety_cantidafac_act,"");
	gtk_entry_set_text(ety_preci_act,"");
	gtk_entry_set_text(ety_mpago_act,"");
	gtk_entry_set_text(ety_descfac_act1,"");
	gtk_entry_set_text(ety_totalfac_act,"");
	
	refresca_datos_fac();
	contenido_tablas();
	
	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_actualizar_fac);
	gtk_label_set_text(lbl_info,"Dato Actualizado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
	}
void on_actualiza_datos_factura_clicked(){
		gtk_widget_show(advertencia_actualizar_fac);
	}
void on_cancela_and_factura1_clicked(){
		gtk_widget_hide(actualiza_factura);
	}
void on_btn_cancelar_adver1_clicked(){
	gtk_widget_hide(advertencia_actualizar_fac);
	}
void on_cancela_and_factura5_clicked(){
	gtk_widget_hide(actualiza_producto);
	}
void on_cancela_and_factura3_clicked(){
	gtk_stack_set_visible_child (GTK_STACK(stack_actualiza),inserta_datos_empresa);
			gtk_entry_set_text(ety_nombreemp,"");
			gtk_entry_set_text(ety_direccion,"");
			gtk_entry_set_text(ety_telefono,"");
			gtk_entry_set_text(ety_region,"");
			gtk_entry_set_text(ety_pais_emp,"");
			gtk_entry_set_text(ety_rfc,"");
			gtk_entry_set_text(ety_estado_emp,"");
			gtk_entry_set_text(ety_correoemp,"");
	}
void on_actualiza_datos_empresa_clicked(){
	gtk_widget_show(advertencia_actualizar_emp);
	}
void on_btn_cancelar_adver4_clicked(){
	gtk_widget_hide(advertencia_actualizar_emp);
	}
void on_btn_actualiza_emp_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char anadir_fac[512];
	char *server = "localhost";

	const char 		*proveedor_emp = gtk_entry_get_text(ety_produ_emp);
	const char 		*nombre2 = gtk_entry_get_text(ety_nombreemp);
	const char		*direccion = gtk_entry_get_text(ety_direccion);
	const char		*telefono = gtk_entry_get_text(ety_telefono);
	const char		*region = gtk_entry_get_text(ety_region);
	const char		*pais = gtk_entry_get_text(ety_pais_emp);
	const char		*rfc_emp = gtk_entry_get_text(ety_rfc);
	const char		*estado = gtk_entry_get_text(ety_estado_emp);
	const char		*correo = gtk_entry_get_text(ety_correoemp);
	
	
	sprintf(anadir_fac,"update Proveedor set Nombre='%s', Direccion='%s', Telefono=%s, Region='%s', Pais='%s' ,Rfc='%s', Estado='%s',Correo='%s' where Empresa=  '%s'",nombre2,direccion,telefono,region,pais,rfc_emp,estado,correo,proveedor_emp);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_anadir_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	
			gtk_entry_set_text(ety_nombreemp,"");
			gtk_entry_set_text(ety_direccion,"");
			gtk_entry_set_text(ety_telefono,"");
			gtk_entry_set_text(ety_region,"");
			gtk_entry_set_text(ety_pais_emp,"");
			gtk_entry_set_text(ety_rfc,"");
			gtk_entry_set_text(ety_estado_emp,"");
			gtk_entry_set_text(ety_correoemp,"");
	
	refresca_datos_emp();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_actualizar_emp);	
	
	gtk_label_set_text(lbl_info,"Dato Actualizado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
gtk_stack_set_visible_child (GTK_STACK(stack_actualiza),inserta_datos_empresa);
	}
	
void on_actualiza_datos_producto_clicked(){
	gtk_widget_show(advertencia_actualizar_pro);
	}
void on_btn_cancelar_adver5_clicked(){
	gtk_widget_hide(advertencia_actualizar_pro);
	}
void on_btn_actualiza_pro_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char date[12];
	char date2[13];
	char anadir_fac[512];
	char *server = "localhost";

	
	const char 		*id_pro = gtk_entry_get_text(ety_idpro_act);
	const char		*nombre = gtk_entry_get_text(ety_nombrepro_act);
	const char		*marca = gtk_entry_get_text(ety_marcapro_act);
	const char		*nlote = gtk_entry_get_text(ety_nlotepro_act);
	const char		*desc = gtk_entry_get_text(ety_descpro_act);
	const char		*cbarra = gtk_entry_get_text(ety_cbarrapro_act);
	const char		*cneto = gtk_entry_get_text(ety_cnetopro_act);
	
	const char 		*dia = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_proact));
	const char 		*mes = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_proact));
	const char 		*anio = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_proact));
	
	const char 		*dia2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_proact2));
	const char 		*mes2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_proact2));
	const char 		*anio2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_proact2));
	
	sprintf(date,"%s-%s-%s",anio,mes,dia);
	sprintf(date2,"%s-%s-%s",anio2,mes2,dia2);
	sprintf(anadir_fac,"update Producto set Nombre= '%s' , Marca='%s' , Fechacaducidad='%s' , Fechaproduccion= '%s' , Numerolote= %s , Descripcion= '%s' ,Codigobarras= %s ,Contenidoneto= '%s' where Idproducto = %s",nombre,marca,date,date2,nlote,desc,cbarra,cneto,id_pro);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_anadir_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	gtk_entry_set_text(ety_idpro_act,"");
	gtk_entry_set_text(ety_nombrepro_act,"");
	gtk_entry_set_text(ety_marcapro_act,"");
	gtk_entry_set_text(ety_nlotepro_act,"");
	gtk_entry_set_text(ety_descpro_act,"");
	gtk_entry_set_text(ety_cbarrapro_act,"");
	gtk_entry_set_text(ety_cnetopro_act,"");

	refresca_datos_pro();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_actualizar_pro);
	gtk_label_set_text(lbl_info,"Dato Actualizado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
	
}
//================================================
//=========== Elimina datos =====================================
void on_btn_borrar_fac_clicked(){
	gtk_widget_show(advertencia_eliminar_fac);
}
void on_ety_id_fac_borrar_activate(){
	gtk_widget_show(advertencia_eliminar_fac);
}
void on_btn_aceptar_a_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char elimina_fac[50];
	char *server = "localhost";
	
	const char 	*id = gtk_entry_get_text(ety_id_fac_borrar);

	sprintf(elimina_fac,"delete from Factura where idfactura=%s",id);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, elimina_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_eliminar_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		//printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_id_fac_borrar,"");
	
	if (gtk_tree_model_get_iter_first(model2, &iter2) == TRUE) {
		refresca_datos_fac();
		if (gtk_tree_model_get_iter_first(model2, &iter2) == FALSE) {
		gtk_stack_set_visible_child (GTK_STACK(stackgtk),lbl_no_datos);	
		}else{
	contenido_tablas();
}
}
	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_eliminar_fac);
	gtk_label_set_text(lbl_info,"Dato Eliminado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
}
void on_btn_cancelar_adver2_clicked(){
	gtk_widget_hide(advertencia_eliminar_fac);
	}
void on_btn_borrar_emp_clicked(){
	gtk_widget_show(advertencia_eliminar_emp);
	}
void on_btn_cancelar_adver8_clicked(){
	gtk_widget_hide(advertencia_eliminar_emp);
	}
void on_btn_aceptar_a1_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char elimina_fac[50];
	char *server = "localhost";
	
	const char 	*id = gtk_entry_get_text(ety_produ_emp);

	sprintf(elimina_fac,"delete from Proveedor where Empresa='%s'",id);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, elimina_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_eliminar_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		//printf("%s",row[0]);
	}
			gtk_entry_set_text(ety_produ_emp,"");
			gtk_entry_set_text(ety_nombreemp,"");
			gtk_entry_set_text(ety_direccion,"");
			gtk_entry_set_text(ety_telefono,"");
			gtk_entry_set_text(ety_region,"");
			gtk_entry_set_text(ety_pais_emp,"");
			gtk_entry_set_text(ety_rfc,"");
			gtk_entry_set_text(ety_estado_emp,"");
			gtk_entry_set_text(ety_correoemp,"");
			gtk_entry_set_text(ety_marcapro,"");
			
	refresca_datos_pro();	
	refresca_datos_emp();
	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_marcapro));
	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_productos_proveedor));
	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_eliminar_emp);
	gtk_label_set_text(lbl_info,"Dato Eliminado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
	contenido_tablas();
	contenido_producto();
	consulta_proveedor();
	gtk_stack_set_visible_child (GTK_STACK(stack_actualiza),inserta_datos_empresa);
}
void on_btn_borrar_pro_clicked(){
	gtk_widget_show(advertencia_eliminar_pro);
	}
void on_btn_aceptar_a2_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char elimina_fac[50];
	char *server = "localhost";
	
	const char 	*id = gtk_entry_get_text(ety_id_pro_borrar);

	sprintf(elimina_fac,"delete from Producto where Idproducto=%s",id);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, elimina_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_eliminar_pro);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		//printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_id_pro_borrar,"");
	
	refresca_datos_pro();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_eliminar_pro);
	gtk_label_set_text(lbl_info,"Dato Eliminado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
}
	
//================================================
void on_Window_BD_destroy()
{
	gtk_main_quit();
	}
void on_window_main_destroy()
{
    gtk_main_quit();
}
void on_btn_cerrar_acd_clicked (){
	gtk_widget_hide (win_acercade);
	}
void on_activador_sql_state_set(){
	if (gtk_switch_get_active (GTK_SWITCH (switchgtk))){
		gtk_stack_set_visible_child (GTK_STACK(stack_aceptar),btn_sql_aceptar);
		gtk_stack_set_visible_child (GTK_STACK(stack_sql),contenedor_sql);
	}else{
		gtk_stack_set_visible_child (GTK_STACK(stack_aceptar),ocultar_btn);
		gtk_stack_set_visible_child (GTK_STACK(stack_sql),debug);
	}
}
void remove_item() {
    
  GtkListStore *store_bus;
  GtkTreeIter iter_bus;
  GtkTreeModel *model_bus;

  store_bus = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(historial_busqueda)));
  model_bus = gtk_tree_view_get_model(GTK_TREE_VIEW(historial_busqueda));

  if (gtk_tree_model_get_iter_first(model_bus, &iter_bus) == FALSE) {
      return;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), &model_bus, &iter_bus)) {
    gtk_list_store_remove(store_bus, &iter_bus);
  }
}
void remove_all() {
    
  GtkListStore *store_bus;
  GtkTreeModel *model_bus;
  GtkTreeIter  iter_bus;

  store_bus = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(historial_busqueda)));
  model_bus = gtk_tree_view_get_model(GTK_TREE_VIEW(historial_busqueda));

  if (gtk_tree_model_get_iter_first(model_bus, &iter_bus) == TRUE) {
	  gtk_list_store_clear(store_bus);
      return;
  }
  gtk_list_store_clear(store_bus);
  
}

void meter_historial(){
	GtkListStore 	*store_bus;
	GtkTreeIter 	iter_bus;

	const gchar *str = gtk_entry_get_text(entry_buscar); 

	store_bus = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(historial_busqueda)));

	gtk_list_store_append(store_bus, &iter_bus);
	gtk_list_store_set(store_bus, &iter_bus, LIST_ITEM, str, -1);
	
	gtk_stack_set_visible_child (GTK_STACK(stack_historial),contenedor_historial);
	gtk_entry_set_text(entry_buscar,"");
}

static void
search_progress_done (GtkEntry *entry)
{
  gtk_entry_set_progress_fraction (entry, 0.0);
}
static gboolean
search_progress (gpointer data)
{
  gtk_entry_progress_pulse (GTK_ENTRY (data));

  return TRUE;
}
static gboolean
start_search_feedback (gpointer data)
{
  search_progress_id = g_timeout_add_full (G_PRIORITY_DEFAULT, 100,(GSourceFunc)search_progress, data, (GDestroyNotify)search_progress_done);
  return FALSE;
}

void busca_proveedor(){
	search_progress_id = g_timeout_add_seconds (0, (GSourceFunc)start_search_feedback, ety_busca_proveedor);
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char busqueda_fac[300];
	char *server = "localhost";
	
	const char 	*consulta = gtk_entry_get_text(ety_busca_proveedor);
	const char 	*consulta2 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_busca_estado));
	
	if (consulta2[0]=='E'){

	sprintf(busqueda_fac,"select * from Proveedor where Empresa LIKE '%s%%'",consulta);
}else{
	sprintf(busqueda_fac,"select * from Proveedor where Empresa LIKE '%s%%' and Estado ='%s'",consulta,consulta2);
	}
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, busqueda_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	refresca_datos_emp();
	while ((row = mysql_fetch_row(res)) != NULL) {
		if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {						 
						 titulo_empresa();
						 return ;
					}	
		}
		  
	mysql_free_result(res);
	mysql_close(conn);

}

void busca_producto(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char busqueda_fac[600];
	char *server = "localhost";
	
	const char 	*consulta = gtk_entry_get_text(ety_busca_producto);
	const char 	*consulta2 = gtk_entry_get_text(ety_busca_proveedor_producto);
	const char 	*consulta3 = gtk_entry_get_text(ety_busca_categoria);
	const char 	*consulta4 = gtk_entry_get_text(ety_busca_subcategoria);
	
	sprintf(busqueda_fac,"select * from Producto where Nombre LIKE '%s%%' and Marca LIKE '%s%%' and Categoria LIKE '%s%%' and Subcategoria LIKE '%s%%'",consulta,consulta2,consulta3,consulta4);
	
	if(strcmp(consulta2,"")!=0){
		gtk_entry_set_icon_from_icon_name (ety_busca_proveedor_producto,GTK_ENTRY_ICON_SECONDARY,"edit-clear-symbolic");
		gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto,GTK_ENTRY_ICON_SECONDARY,1);
			}if(strcmp(consulta3,"")!=0){
				gtk_entry_set_icon_from_icon_name (ety_busca_categoria,GTK_ENTRY_ICON_SECONDARY,"edit-clear-symbolic");
				gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto,GTK_ENTRY_ICON_SECONDARY,1);
		}if(strcmp(consulta4,"")!=0){
			gtk_entry_set_icon_from_icon_name (ety_busca_subcategoria,GTK_ENTRY_ICON_SECONDARY,"edit-clear-symbolic");
			gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto,GTK_ENTRY_ICON_SECONDARY,1);
			}

	if(strcmp(consulta2,"")==0){
		gtk_entry_set_icon_from_icon_name (ety_busca_proveedor_producto,GTK_ENTRY_ICON_SECONDARY,NULL);
		gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto,GTK_ENTRY_ICON_SECONDARY,1);
			}if(strcmp(consulta3,"")==0){
				gtk_entry_set_icon_from_icon_name (ety_busca_categoria,GTK_ENTRY_ICON_SECONDARY,NULL);
				gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto,GTK_ENTRY_ICON_SECONDARY,1);
		}if(strcmp(consulta4,"")==0){
			gtk_entry_set_icon_from_icon_name (ety_busca_subcategoria,GTK_ENTRY_ICON_SECONDARY,NULL);
			gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto,GTK_ENTRY_ICON_SECONDARY,1);
			}		
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, busqueda_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	refresca_datos_pro();
	while ((row = mysql_fetch_row(res)) != NULL) {
		if (gtk_tree_model_get_iter_first(model3, &iter3) == FALSE) {						 
						 titulo_producto();
						 return ;
					}	
		}
		  
	mysql_free_result(res);
	mysql_close(conn);
	

	search_progress_done(ety_busca_producto);
	g_source_remove (finish_search_id);
	gtk_entry_set_progress_fraction (ety_busca_producto, 0.0);

}

void on_btn_consulta_emp_clicked(){
	search_progress_id = g_timeout_add_seconds (0, (GSourceFunc)start_search_feedback, ety_produ_emp);
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char busqueda_fac[50];
	char *server = "localhost";
	
	const char 	*consulta = gtk_entry_get_text(ety_produ_emp);

	sprintf(busqueda_fac,"select * from Proveedor where Empresa = '%s'",consulta);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, busqueda_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {			
			gtk_entry_set_text(ety_nombreemp,row[1]);
			gtk_entry_set_text(ety_direccion,row[2]);
			gtk_entry_set_text(ety_telefono,row[3]);
			gtk_entry_set_text(ety_region,row[4]);
			gtk_entry_set_text(ety_pais_emp,row[5]);
			gtk_entry_set_text(ety_rfc,row[6]);
			gtk_entry_set_text(ety_estado_emp,row[7]);
			gtk_entry_set_text(ety_correoemp,row[8]);
			gtk_stack_set_visible_child (GTK_STACK(stack_actualiza),box_act_emp);
		}
		  
	mysql_free_result(res);
	mysql_close(conn);

	search_progress_done(ety_produ_emp);
	g_source_remove (finish_search_id);
	gtk_entry_set_progress_fraction (ety_produ_emp, 0.0);
}
void on_btn_consulta_fac_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char busqueda_fac[50];
	char *server = "localhost";
	
	const char 	*consulta = gtk_entry_get_text(id_fac_act);

	sprintf(busqueda_fac,"select * from Factura where Idfactura = %s",consulta);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, busqueda_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		
			gtk_entry_set_text(ety_profac_act,row[1]);
			gtk_entry_set_text(ety_empfact_act,row[2]);
			gtk_entry_set_text(ety_cantidafac_act,row[4]);
			gtk_entry_set_text(ety_preci_act,row[5]);
			gtk_entry_set_text(ety_mpago_act,row[6]);
			gtk_entry_set_text(ety_descfac_act1,row[7]);
			gtk_entry_set_text(ety_totalfac_act,row[8]);
		}
	
	mysql_free_result(res);
	mysql_close(conn);
	
}
void on_btn_consulta_pro_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char busqueda_fac[50];
	char *server = "localhost";
	
	const char 	*consulta = gtk_entry_get_text(ety_idpro_act);

	sprintf(busqueda_fac,"select * from Producto where Idproducto = %s",consulta);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, busqueda_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		
			gtk_entry_set_text(ety_nombrepro_act,row[1]);
			gtk_entry_set_text(ety_marcapro_act,row[2]);
			gtk_entry_set_text(ety_nlotepro_act,row[5]);
			gtk_entry_set_text(ety_descpro_act,row[6]);
			gtk_entry_set_text(ety_cbarrapro_act,row[7]);
			gtk_entry_set_text(ety_cnetopro_act,row[8]);
		}
	
	mysql_free_result(res);
	mysql_close(conn);
}
void on_exportar_pdf_clicked(){
	const char *tabla = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(tabla_items));
	char exporta [40];
	sprintf(exporta,"select * from %s",tabla);
	
	const char cabeceras []="\\documentclass[a4paper,6pt]{report}\n\\usepackage[T1]{fontenc}\n \\usepackage[utf8]{inputenc}\n\\usepackage{lmodern}\n\\usepackage[spanish]{babel}\n\\usepackage{pdflscape}\n";
	char init_document [] = "\\begin{document}\n\\begin{landscape}\n \\setlength{\\textwidth}{10mm}\n\\setlength{\\textheight}{10mm}\n \\setlength{\\oddsidemargin}{-70mm} \n\\setlength{\\evensidemargin}{100mm}\n\\setlength{\\topmargin}{35mm}\n";
	char campos [] = "ID & ID Pro. Ant. & Nombre Ant. & Direccion Ant. & Tel. Ant. & Region Ant. & Pais Ant. & RFC Ant. & Correo Ant. & ID Pro. New & Nombre New & Direcc. New & Telefono New & Region New & Pais New & RFC New & Correo New & User & Modificado & Accion & Id Empresa\\\\ \\hline \\hline\n";
	char campos2 [] = "ID & ID Pro. Ant. & ID Emp. Ant. & Fecha Ven. Ant. & Can. Ant. & Precio Ant. & M.Pago Ant. & Desc. Ant. & Total Ant. & ID Pro. New & ID Emp New & F. Ven. New & Cant. New & Precio New & MPago New & Desc. New & Total New & User & Modificado & Accion & Id Fac.\\\\ \\hline \\hline\n";
	char campos3 [] = "ID & Nombre Ant. & Marca Ant. & FCaducidad Ant. & FProduccion Ant. & Num. Lote Ant. & Desc. Ant. & CBarra Ant. & Con. Neto Ant. & Nombre New & Marca New & FCaducidad New & FProd. New & Num. Lote New & Desc. New & CBarra New & Con. Neto & User & Modificado & Accion & Id Pro.\\\\ \\hline \\hline\n";

	char inicia_tabla [] = "\\begin{table}\n\\label{tab:}\n\\begin{center}\n \\resizebox{27cm}{!} { \n\\begin{tabular}{| c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | }\n";
	char fin_tabla [] = "\\end{tabular}\n }\\end{center}\n\\end{table}\n";
	char fin_documento [] = "\n\\end{landscape}\n\\end{document}";
	char hline[]= "\\hline\n";

	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char *server = "localhost";
	
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, exporta))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	
//==========================================================================================================================================================		
	if(tabla[10]== 'e'){
		fichero = fopen("Empresa.tex", "wt");
	fputs(cabeceras, fichero);
	fputs(init_document, fichero);
	fputs(inicia_tabla, fichero);
	fputs(hline,fichero);
	fputs(campos, fichero);
	while ((row = mysql_fetch_row(res)) != NULL) {
		fprintf(fichero,"%s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s \\\\ \\hline\n",row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8],row[9],row[10],row[11],row[12],row[13],row[14],row[15],row[16],row[17],row[18],row[19],row[20]);
	}
	fputs(hline,fichero);
	fputs(fin_tabla,fichero);
	fputs(fin_documento, fichero);
	fclose(fichero); 
	system("latexmk -pdf -synctex=1 Empresa.tex ");
    system("evince Empresa.pdf &");
    //return ;
//==========================================================================================================================================================    
	}else if(tabla[10]== 'f'){
	fichero2 = fopen("Factura.tex", "wt");
	fputs(cabeceras, fichero2);
	fputs(init_document, fichero2);
	fputs(inicia_tabla, fichero2);
	fputs(hline,fichero2);
	fputs(campos2, fichero2);
	while ((row = mysql_fetch_row(res)) != NULL) {
		fprintf(fichero2,"%s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s \\\\ \\hline\n",row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8],row[9],row[10],row[11],row[12],row[13],row[14],row[15],row[16],row[17],row[18],row[19],row[20]);
	}
	fputs(hline,fichero2);
	fputs(fin_tabla,fichero2);
	fputs(fin_documento, fichero2);
	fclose(fichero2); 
	system("latexmk -pdf -synctex=1 Factura.tex ");
    system("evince Factura.pdf &");
   // return ;
//==========================================================================================================================================================   
		}else if(tabla[10]== 'p'){
	fichero3 = fopen("Producto.tex", "wt");
	fputs(cabeceras, fichero3);
	fputs(init_document, fichero3);
	fputs(inicia_tabla, fichero3);
	fputs(hline,fichero3);
	fputs(campos3, fichero3);
	while ((row = mysql_fetch_row(res)) != NULL) {
		fprintf(fichero3,"%s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s \\\\ \\hline\n",row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8],row[9],row[10],row[11],row[12],row[13],row[14],row[15],row[16],row[17],row[18],row[19],row[20]);
	}
	fputs(hline,fichero3);
	fputs(fin_tabla,fichero3);
	fputs(fin_documento, fichero3);
	fclose(fichero3); 
	system("latexmk -pdf -synctex=1 Producto.tex ");
    system("evince Producto.pdf &");
    //return ;
}
//==========================================================================================================================================================
	mysql_free_result(res);
	mysql_close(conn);
  

    gtk_label_set_text(lbl_info,"PDF Creado");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
	}
void on_remover_item_clicked(){
	remove_item();
	}
void on_remover_todos_items_clicked(){
	remove_all();
	}
void on_acercade_close (){
	gtk_dialog_run (GTK_DIALOG (win_acercade));
	gtk_widget_hide_on_delete(win_acercade);
	}
void on_cerrar_acercade_clicked(){
	gtk_widget_hide_on_delete(win_acercade);
	}
void on_acercade_destroy(){
	gtk_widget_hide(win_acercade);
		}	
void on_info_close(){
	gtk_label_set_text(lbl_info,"");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),FALSE);
	}
void on_info_close2(){
	gtk_label_set_text(lbl_info_bien,"");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar_bien),FALSE);
	}
void abre_preferencias(){
	gtk_stack_set_visible_child(stack_menu_pos,child_preferencia);	
	}
void regresa_menu(){
	gtk_stack_set_visible_child(stack_menu_pos,child_menu);	
	}
void consulta_usuarios(){
	char *user = "root";
	password = "junomava3842";
	char *server = "localhost";
	conn = mysql_init(NULL);
 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) 
 {
     char tempErr[60];
	 sprintf(tempErr,"%s", mysql_error(conn));
	 gtk_label_set_text(lbl_error,tempErr);
     return gtk_widget_show(dialog_error_datos);
 }else
 {	 
}
	 
 if (mysql_query(conn, "select user,host,select_priv from mysql.db where db='Tienda'")) 
 {
	 char tempErr[60];
     sprintf(tempErr,"%s", mysql_error(conn));
	 gtk_label_set_text(lbl_error,tempErr);
     return gtk_widget_show(dialog_error_datos);

 }
 res = mysql_use_result(conn); 

 while ((row = mysql_fetch_row(res)) != NULL) ;
 
 mysql_free_result(res);
 mysql_close(conn);
 
}

void cerrar_setup(){
    gtk_widget_hide(bienvenido);
//agregar funcion para refrescar usuarios
    gtk_widget_show(window_login);
}
void consulta_pos(){
	gboolean button_state;
	button_state = gtk_toggle_button_get_active(btn_consulta_pos);
	  if (button_state) {
		// button is active
		gtk_revealer_set_reveal_child (GTK_REVEALER (reveal_consulta),TRUE);
	}
	else {
		// button is inactive
		gtk_revealer_set_reveal_child (GTK_REVEALER (reveal_consulta),FALSE);
}
	}
void modifica_productos(){
	gboolean button_state;
	button_state = gtk_toggle_button_get_active(btn_edit_productos);
	if (button_state) {
		// button is active
		gtk_revealer_set_reveal_child (GTK_REVEALER (reveal_productos),TRUE);
	}
	else {
		// button is inactive
		gtk_revealer_set_reveal_child (GTK_REVEALER (reveal_productos),FALSE);
}
}
	
void modifica_proveedor(){
	gboolean button_state;
	button_state = gtk_toggle_button_get_active(btn_edit_proveedor);
	if (button_state) {
		// button is active
		gtk_revealer_set_reveal_child (GTK_REVEALER (reveal_proveedor),TRUE);
	}
	else {
		// button is inactive
		gtk_revealer_set_reveal_child (GTK_REVEALER (reveal_proveedor),FALSE);
}
}

void abre_busca(){
	gboolean button_state = gtk_toggle_button_get_active(btn_buscar_pos);
	if (button_state) {
		// button is active
		gtk_stack_set_visible_child (GTK_STACK(stack_header),ety_busc_producto);
	}
	else{
		// button is inactive
		gtk_stack_set_visible_child (GTK_STACK(stack_header),swchitcher);		
	}
}

void siguiente(){
    const char *comp_user = gtk_entry_get_text (ety_user_bien);
    
    const char *con1 = gtk_entry_get_text (ety_contrasena1);
    const char *con2 = gtk_entry_get_text (ety_contrasena2);
    if(gtk_stack_get_visible_child (GTK_STACK(pasos))==pag_bienvenido){
	gtk_stack_set_visible_child(GTK_STACK(pasos),pag_usuarios);
	gtk_widget_set_sensitive (GTK_WIDGET(pag_atras) ,TRUE);
    }else if(gtk_stack_get_visible_child (GTK_STACK(pasos))==pag_usuarios){
	if (strcmp(comp_user,"") == 0)
	{
		gtk_label_set_text(lbl_info_bien,"El Usuario no Puede ir en Blanco");
		gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar_bien),TRUE);
	}else if (strcmp(con1,con2) == 0 && strcmp(con2,"" )!=0)
	{
		gtk_stack_set_visible_child(GTK_STACK(pasos),pag_comp);
		gtk_widget_set_sensitive (GTK_WIDGET(pag_atras) ,TRUE);
		gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar_bien),FALSE);
	}else{
		gtk_label_set_text(lbl_info_bien," Las Contrasena no coinciden o estan vacias");
		gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar_bien),TRUE);
		
		}
	}else if(gtk_stack_get_visible_child (GTK_STACK(pasos))==pag_comp){
	gtk_stack_set_visible_child(GTK_STACK(pasos),pag_sumario);
	gtk_widget_set_sensitive (GTK_WIDGET(pag_atras) ,TRUE);
	gtk_widget_set_sensitive (GTK_WIDGET(pag_sig) ,FALSE);
    }

}
void atras(){
    if(gtk_stack_get_visible_child (GTK_STACK(pasos))==pag_sumario){
	gtk_stack_set_visible_child(GTK_STACK(pasos),pag_comp);
	gtk_widget_set_sensitive (GTK_WIDGET(pag_sig) ,TRUE);
    }else if(gtk_stack_get_visible_child (GTK_STACK(pasos))==pag_comp){
	gtk_stack_set_visible_child(GTK_STACK(pasos),pag_usuarios);
	gtk_widget_set_sensitive (GTK_WIDGET(pag_sig) ,TRUE);
    }else if(gtk_stack_get_visible_child (GTK_STACK(pasos))==pag_usuarios){
	gtk_stack_set_visible_child(GTK_STACK(pasos),pag_bienvenido);
	gtk_widget_set_sensitive (GTK_WIDGET(pag_sig) ,TRUE);
	gtk_widget_set_sensitive (GTK_WIDGET(pag_atras) ,FALSE);
    }
    
}
void pagar_servicios(){
	system("epiphany &");
}
void cambia_bs_categoria(){
	int i;
	gtk_combo_box_text_remove_all (GTK_COMBO_BOX_TEXT (cb_bs_subcat));	
	const char *categoria = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_bs_cat));
	//const char *sub_categoria = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_subcat));
	g_print("%s\n",categoria);
	if(categoria[1]== 'b'){
const char *aba[] = {
"",	
"Aceite comestibles",
"Aderezos",
"Consome",
"Crema de cacahuate",
"Crema para café",
"Pure de tomate",
"Alimento para bebe",
"Alimento para mascotas",
"Atole",
"Avena",
"Azúcar",
"Café",
"Cereales",
"Chile piquín",
"Especias",
"Flan en polvo",
"Formulas infantiles",
"Gelatinas en polvo/Grenetina",
"Harina",
"Harina preparada",
"Mole",
"Sal",
"Salsas envasadas",
"Sazonadores",
"Sopas en sobre",
"Cajeta",
"Catsup",
"Mayonesa",
"Mermelada",
"Miel",
"Te",
"Vinagre",
"Huevo",
"Pastas"};
    
 for (i = 0; i < G_N_ELEMENTS(aba); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), aba[i]);
  }		
gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);					    
  }else if(categoria[11]== 'n'){
	  
	  const char *enlatados[] = {
		  "",
    "Aceitunas",
 "Chícharo con zanahoria",
    "Chícharos enlatados",
    "Frijoles enlatados",
    "Frutas en almíbar",
    "Sardinas",
    "Atún en agua/aceite",
    "Chiles enlatados",
    "Chiles envasados",
    "Ensaladas enlatadas",
    "Granos de elote enlatados",
    "Sopa en lata",
    "Vegetales en conserva",
};
	  for (i = 0; i < G_N_ELEMENTS(enlatados); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), enlatados[i]);
  }
  gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);
	  } else if  (categoria[0]== 'L'){
const char *lacteos[] = {
	"",
"Leche condensada",
"Leche deslactosada",
"Leche en polvo",
"Leche evaporada",
"Leche Light",
"Leche pasteurizada",
"Leche saborizada",
"Leche semidescremada",
"Crema",
"Yoghurt",
"Mantequilla",
"Margarina",
"Media crema",
"Queso"
};

for (i = 0; i < G_N_ELEMENTS(lacteos); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), lacteos[i]);
  }		  
gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);	  
		  
	  }else if  (categoria[0]== 'C'){
const char *dulces[] = {
	"",
"Caramelos",
"Dulces enchilados",
"Chocolate de mesa",
"Chocolate en polvo",
"Chocolates",
"Gomas de mascar",
"Mazapán",
"Malvaviscos",
"Pulpa de tamarindo",
"Pastillas de dulce",
"Paletas de dulce"
};		  
for (i = 0; i < G_N_ELEMENTS(dulces); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), dulces[i]);
  }
 gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);		 
	  }else if  (categoria[1]== 'a'){
const char *harinas[] = {
	"",
"Tortillas de harina/maíz",
"Galletas dulces",
"Galletas saladas",
"Pastelillos",
"Pan de caja",
"Pan dulce",
"Pan molido",
"Pan tostado"
};	
for (i = 0; i < G_N_ELEMENTS(harinas); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), harinas[i]);
  }	  
gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);
	  }else if  (categoria[2]== 'u'){
const char *verduras[] = {
	"",
"Aguacates",
"Ajos",
"Cebollas",
"Chiles",
"Cilantro/Perejil",
"Jitomate",
"Papas",
"Limones",
"Manzanas",
"Naranjas",
"Plátanos"
};		  
for (i = 0; i < G_N_ELEMENTS(verduras); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), verduras[i]);
  }
  gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);	
}else if  (categoria[11]== 'o'){

const char *alcohol[] = {
	"",
"Bebidas preparadas",
"Cerveza",
"Anís",
"Brandy",
"Ginebra",
"Cordiales",
"Mezcal",
"Jerez",
"Ron",
"Tequila",
"Sidra",
"Whiskey",
"Vodka"
};
for (i = 0; i < G_N_ELEMENTS(alcohol); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), alcohol[i]);
  }
  gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);	  	  
	   }else if  (categoria[2]== 'b'){
const char *bebidas[] = {
	"",
"Agua mineral",
"Agua natural",
"Agua saborizada",
"Jarabes",
"Jugos/Néctares",
"Naranjadas",
"Bebidas de soya",
"Bebidas en polvo",
"Bebidas infantiles",
"Bebidas isotónicas",
"Energetizantes",
"Isotónicos",
"Refrescos"
};
for (i = 0; i < G_N_ELEMENTS(bebidas); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), bebidas[i]);
  }
  gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);
  }else if  (categoria[1]== 'e'){
const char *helados[] = {
	"",
"Helados / Paletas"
};
for (i = 0; i < G_N_ELEMENTS(helados); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), helados[i]);
 }
 gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0); 		   	  
}else if  (categoria[19]== 's' && categoria[18]== 'o'){
	const char *preparado[] = {
		"",
"Pastas listas para comer",
"Sopas en vaso",
"Carnes y Embutidos",
"Salchicha",
"Mortadela",
"Tocino",
"Jamón",
"Manteca",
"Chorizo",
"Carne de puerco/res/pollo"
};
for (i = 0; i < G_N_ELEMENTS(preparado); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), preparado[i]);
  }
  gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);
	}else if  (categoria[1]== 'u'){
		const char *automedicacion[] = {
			"",
"Suero",
"Agua oxigenada",
"Preservativos",
"Alcohol",
"Gasas",
"Analgésicos",
"Antigripales",
"Antiácidos"
};
for (i = 0; i < G_N_ELEMENTS(automedicacion); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), automedicacion[i]);
  }	
  gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);	
		}else if  (categoria[15]== 'l'){
			const char *personal[] = {
				"",
"Toallas húmedas",
"Aceite para bebe",
"Toallas femeninas",
"Algodón",
"Tinte para el cabello",
"Biberones",
"Talco",
"Cepillo de dientes",
"Shampoo/ Acondicionador",
"Cotonetes",
"Rastrillos",
"Crema corporal/facial",
"Papel higiénico",
"Crema para afeitar",
"Pañuelos faciales",
"Dentífricos",
"Pañuelos desechables",
"Desodorantes en barra/aerosol",
"Maquillaje",
"Enjuague bucal",
"Lubricantes para labios",
"Gel/spray",
"Loción hidratante",
"Jabones corporales/tocador"
};
for (i = 0; i < G_N_ELEMENTS(personal); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), personal[i]);
  }
  gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);
			}else if  (categoria[0]== 'U'){
const char *domestico[] = {
	"",
"Suavizante de telas",
    "Ácido muriático",
    "Sosa caustica",
    "Aluminio",
    "Pilas",
    "Shampoo para ropa",
    "Servilletas",
    "Servitoallas",
    "Aromatizantes",
    "Cera para automóvil",
    "Cera para calzados",
    "Pastillas sanitarias",
    "Limpiadores líquidos",
    "Limpiadores para pisos",
    "Jabón de barra",
    "Cerillos",
    "Cloro/Blanqueador",
    "Cloro para ropa",
    "Insecticidas",
    "Fibras limpiadoras",
    "Desinfectantes",
    "Detergentes para trastes",
    "Detergente para ropa"
};
for (i = 0; i < G_N_ELEMENTS(domestico); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), domestico[i]);
  }				
gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);
				}else if  (categoria[13]== 'L'){
const char *limpieza[] = {
	"",
    "Veladoras/Velas",
    "Cepillo de plástico",
    "Vasos desechables",
    "Cinta adhesiva",
    "Cucharas de plástico",
    "Escobas/Trapeadores/Mechudos",
    "Trampas para ratas",
    "Tenedores de plástico",
    "Extensiones/Multicontacto",
    "Recogedor de metal/plástico",
    "Popotes",
    "Platos desechables",
    "Focos",
    "Fusibles",
    "Jergas/Franelas",
    "Matamoscas",
    "Pegamento",
    "Mecate/cuerda"
};
for (i = 0; i < G_N_ELEMENTS(limpieza); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), limpieza[i]);
  }
  gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);	
} else if  (categoria[0]== 'O'){
const char *otros[] = {
	"",
    "Tarjetas telefónicas",
    "Recargas móviles",
    "Hielo",
    "Cigarros"
};
for (i = 0; i < G_N_ELEMENTS(otros); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), otros[i]);
  }
  gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);						
				} else if  (categoria[3]== 'a'){
const char *botanas[] = {
	"",
"Papas",
"Palomitas",
"Frituras de maíz",
"Cacahuates",
"Botanas saladas",
"Barras alimenticias",
"Nueces y semillas"
};
for (i = 0; i < G_N_ELEMENTS(botanas); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), botanas[i]);
  }
gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);
			}else if  (categoria[0]== 'C' && categoria[1]== 'a'){
const char *botanas[] = {
	"",
};
for (i = 0; i < G_N_ELEMENTS(botanas); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_bs_subcat), botanas[i]);
  }
gtk_combo_box_set_active (GTK_COMBO_BOX (cb_bs_subcat),0);
			}
		}
		
		
void cambia_categoria(){
	int i;
	gtk_entry_set_text(entry_subcat,"");
	gtk_combo_box_text_remove_all (GTK_COMBO_BOX_TEXT (cb_subcat));	
	const char *categoria = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_cat));
	//const char *sub_categoria = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_subcat));
	g_print("%s\n",categoria);
	if(categoria[1]== 'b'){
const char *aba[] = {
"Aceite comestibles",
"Aderezos",
"Consome",
"Crema de cacahuate",
"Crema para café",
"Pure de tomate",
"Alimento para bebe",
"Alimento para mascotas",
"Atole",
"Avena",
"Azúcar",
"Café",
"Cereales",
"Chile piquín",
"Especias",
"Flan en polvo",
"Formulas infantiles",
"Gelatinas en polvo/Grenetina",
"Harina",
"Harina preparada",
"Mole",
"Sal",
"Salsas envasadas",
"Sazonadores",
"Sopas en sobre",
"Cajeta",
"Catsup",
"Mayonesa",
"Mermelada",
"Miel",
"Te",
"Vinagre",
"Huevo",
"Pastas"};
    
 for (i = 0; i < G_N_ELEMENTS(aba); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), aba[i]);
  }		
					    
  }else if(categoria[11]== 'n'){
	  
	  const char *enlatados[] = {
    "Aceitunas",
 "Chícharo con zanahoria",
    "Chícharos enlatados",
    "Frijoles enlatados",
    "Frutas en almíbar",
    "Sardinas",
    "Atún en agua/aceite",
    "Chiles enlatados",
    "Chiles envasados",
    "Ensaladas enlatadas",
    "Granos de elote enlatados",
    "Sopa en lata",
    "Vegetales en conserva",
};
	  for (i = 0; i < G_N_ELEMENTS(enlatados); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), enlatados[i]);
  }
	  } else if  (categoria[0]== 'L'){
const char *lacteos[] = {
"Leche condensada",
"Leche deslactosada",
"Leche en polvo",
"Leche evaporada",
"Leche Light",
"Leche pasteurizada",
"Leche saborizada",
"Leche semidescremada",
"Crema",
"Yoghurt",
"Mantequilla",
"Margarina",
"Media crema",
"Queso"
};

for (i = 0; i < G_N_ELEMENTS(lacteos); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), lacteos[i]);
  }		  
	  
		  
	  }else if  (categoria[0]== 'C'){
const char *dulces[] = {
"Caramelos",
"Dulces enchilados",
"Chocolate de mesa",
"Chocolate en polvo",
"Chocolates",
"Gomas de mascar",
"Mazapán",
"Malvaviscos",
"Pulpa de tamarindo",
"Pastillas de dulce",
"Paletas de dulce"
};		  
for (i = 0; i < G_N_ELEMENTS(dulces); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), dulces[i]);
  }		 
	  }else if  (categoria[1]== 'a'){
const char *harinas[] = {
"Tortillas de harina/maíz",
"Galletas dulces",
"Galletas saladas",
"Pastelillos",
"Pan de caja",
"Pan dulce",
"Pan molido",
"Pan tostado"
};	
for (i = 0; i < G_N_ELEMENTS(harinas); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), harinas[i]);
  }	  

	  }else if  (categoria[2]== 'u'){
const char *verduras[] = {
"Aguacates",
"Ajos",
"Cebollas",
"Chiles",
"Cilantro/Perejil",
"Jitomate",
"Papas",
"Limones",
"Manzanas",
"Naranjas",
"Plátanos"
};		  
for (i = 0; i < G_N_ELEMENTS(verduras); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), verduras[i]);
  }	
}else if  (categoria[11]== 'o'){

const char *alcohol[] = {
"Bebidas preparadas",
"Cerveza",
"Anís",
"Brandy",
"Ginebra",
"Cordiales",
"Mezcal",
"Jerez",
"Ron",
"Tequila",
"Sidra",
"Whiskey",
"Vodka"
};
for (i = 0; i < G_N_ELEMENTS(alcohol); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), alcohol[i]);
  }	  	  
	   }else if  (categoria[2]== 'b'){
const char *bebidas[] = {
"Agua mineral",
"Agua natural",
"Agua saborizada",
"Jarabes",
"Jugos/Néctares",
"Naranjadas",
"Bebidas de soya",
"Bebidas en polvo",
"Bebidas infantiles",
"Bebidas isotónicas",
"Energetizantes",
"Isotónicos",
"Refrescos"
};
for (i = 0; i < G_N_ELEMENTS(bebidas); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), bebidas[i]);
  }
  }else if  (categoria[1]== 'e'){
const char *helados[] = {
"Helados / Paletas"
};
for (i = 0; i < G_N_ELEMENTS(helados); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), helados[i]);
 } 		   	  
}else if  (categoria[19]== 's' && categoria[18]== 'o'){
	const char *preparado[] = {
"Pastas listas para comer",
"Sopas en vaso",
"Carnes y Embutidos",
"Salchicha",
"Mortadela",
"Tocino",
"Jamón",
"Manteca",
"Chorizo",
"Carne de puerco/res/pollo"
};
for (i = 0; i < G_N_ELEMENTS(preparado); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), preparado[i]);
  }
	}else if  (categoria[1]== 'u'){
		const char *automedicacion[] = {
"Suero",
"Agua oxigenada",
"Preservativos",
"Alcohol",
"Gasas",
"Analgésicos",
"Antigripales",
"Antiácidos"
};
for (i = 0; i < G_N_ELEMENTS(automedicacion); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), automedicacion[i]);
  }		
		}else if  (categoria[15]== 'l'){
			const char *personal[] = {
"Toallas húmedas",
"Aceite para bebe",
"Toallas femeninas",
"Algodón",
"Tinte para el cabello",
"Biberones",
"Talco",
"Cepillo de dientes",
"Shampoo/ Acondicionador",
"Cotonetes",
"Rastrillos",
"Crema corporal/facial",
"Papel higiénico",
"Crema para afeitar",
"Pañuelos faciales",
"Dentífricos",
"Pañuelos desechables",
"Desodorantes en barra/aerosol",
"Maquillaje",
"Enjuague bucal",
"Lubricantes para labios",
"Gel/spray",
"Loción hidratante",
"Jabones corporales/tocador"
};
for (i = 0; i < G_N_ELEMENTS(personal); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), personal[i]);
  }
			}else if  (categoria[0]== 'U'){
const char *domestico[] = {
"Suavizante de telas",
    "Ácido muriático",
    "Sosa caustica",
    "Aluminio",
    "Pilas",
    "Shampoo para ropa",
    "Servilletas",
    "Servitoallas",
    "Aromatizantes",
    "Cera para automóvil",
    "Cera para calzados",
    "Pastillas sanitarias",
    "Limpiadores líquidos",
    "Limpiadores para pisos",
    "Jabón de barra",
    "Cerillos",
    "Cloro/Blanqueador",
    "Cloro para ropa",
    "Insecticidas",
    "Fibras limpiadoras",
    "Desinfectantes",
    "Detergentes para trastes",
    "Detergente para ropa"
};
for (i = 0; i < G_N_ELEMENTS(domestico); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), domestico[i]);
  }				

				}else if  (categoria[13]== 'l'){
const char *limpieza[] = {
    "Veladoras/Velas",
    "Cepillo de plástico",
    "Vasos desechables",
    "Cinta adhesiva",
    "Cucharas de plástico",
    "Escobas/Trapeadores/Mechudos",
    "Trampas para ratas",
    "Tenedores de plástico",
    "Extensiones/Multicontacto",
    "Recogedor de metal/plástico",
    "Popotes",
    "Platos desechables",
    "Focos",
    "Fusibles",
    "Jergas/Franelas",
    "Matamoscas",
    "Pegamento",
    "Mecate/cuerda"
};
for (i = 0; i < G_N_ELEMENTS(limpieza); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), limpieza[i]);
  }	
} else if  (categoria[0]== 'O'){
const char *otros[] = {
    "Tarjetas telefónicas",
    "Recargas móviles",
    "Hielo",
    "Cigarros"
};
for (i = 0; i < G_N_ELEMENTS(otros); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), otros[i]);
  }						
				} else if  (categoria[3]== 'a'){
const char *botanas[] = {
"Papas",
"Palomitas",
"Frituras de maíz",
"Cacahuates",
"Botanas saladas",
"Barras alimenticias",
"Nueces y semillas"
};
for (i = 0; i < G_N_ELEMENTS(botanas); i++){
  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_subcat), botanas[i]);
  }
			}
		}
void show_gensku(){	
	const char *temp = gtk_entry_get_text (ety_cbarra);
	if (strcmp(temp,"") == 0 ){
		gtk_widget_set_visible (pop_generar_sku,1);
	}else{
	gtk_widget_hide(pop_generar_sku);
	gtk_stack_set_visible_child(stack_sku,child_sku);
}
}
void hide_gensku(){
	 gtk_stack_set_visible_child(stack_sku,child_sku);
	}
void header_busqueda(){
	if(gtk_stack_get_visible_child (stack_pos)==pag_pos){
			gtk_stack_set_visible_child(stack_bus_pos,child_busqueda_pos);
		}else{
			gtk_stack_set_visible_child(stack_bus_pos,child_oculta_bus_pos);
		}
	}
void show_gensku_child(){
	gtk_stack_set_visible_child(stack_sku,child_tam_sku);
}
void consigue_datos(){
const gchar *usuario = gtk_entry_get_text (ety_user_bien);
gtk_label_set_text (GTK_LABEL(lbl_user_bien),usuario);
}
void consigue_datos2(){
	const gchar *empresa = gtk_entry_get_text (ety_emp_bien);
	const gchar *telefono = gtk_entry_get_text (ety_num_bien);
	const gchar *direccion = gtk_entry_get_text (ety_dir_bien);
	
	gtk_label_set_text (GTK_LABEL(lbl_emp_bien),empresa);
	gtk_label_set_text (GTK_LABEL(lbl_num_bien),telefono);
	gtk_label_set_text (GTK_LABEL(lbl_dir_bien),direccion);
	
}
void consigue_datos3(){
	const gchar *rfc = gtk_entry_get_text (ety_rfc_bien);
	gtk_label_set_text (GTK_LABEL(lbl_rfc_bien),rfc);
}
void borra_busqueda1(){
	gtk_entry_set_text(ety_busca_proveedor_producto,"");
	}
void borra_busqueda2(){
	gtk_entry_set_text(ety_busca_categoria,"");
	}
void borra_busqueda3(){
	gtk_entry_set_text(ety_busca_subcategoria,"");
	}
void cucb(){
	char ra[4];
	srand(time(NULL)); //El mayordomo pone a girar la diana
	int test = rand() %9999;
	sprintf(ra,"%d",test);
	gtk_entry_set_text(ety_cbarra,ra);
	}
void occb(){
	char ra[9];
	srand(time(NULL)); //El mayordomo pone a girar la diana
	int test = rand() %100000000;
	sprintf(ra,"%d",test);
	gtk_entry_set_text(ety_cbarra,ra);
	}
void trecb(){
	char ra[19];
	srand(time(NULL)); //El mayordomo pone a girar la diana
	long int test = rand() %99999999999999999;
	sprintf(ra,"%ld",test);
	gtk_entry_set_text(ety_cbarra,ra);
	}
int main(int argc, char *argv[])
	{
		GtkBuilder      	*builder; 
		
		char anio[256];
		int i;
		gtk_init(&argc, &argv);
		
		
		
		builder = gtk_builder_new();
		gtk_builder_add_from_file (builder, "window_main.glade", NULL);
		pila_stp = GTK_WIDGET(gtk_builder_get_object(builder, "pila_stp"));
		lbl_hora = GTK_LABEL(gtk_builder_get_object(builder, "lbl_hora"));
		pag_bienvenido = GTK_WIDGET(gtk_builder_get_object(builder, "pag_bienvenido"));
		pag_usuarios = GTK_WIDGET(gtk_builder_get_object(builder, "pag_usuarios"));
		pag_comp = GTK_WIDGET(gtk_builder_get_object(builder, "pag_comp"));
		pag_sumario = GTK_WIDGET(gtk_builder_get_object(builder, "pag_sumario"));
		btn_menu_pref = GTK_BUTTON(gtk_builder_get_object(builder, "btn_menu_pref"));
		actualiza_datos_empresa = GTK_WIDGET(gtk_builder_get_object(builder, "actualiza_datos_empresa"));
		btn_cambiar_usuario = GTK_WIDGET(gtk_builder_get_object(builder, "btn_cambiar_usuario"));
		child_menu = GTK_WIDGET(gtk_builder_get_object(builder, "child_menu"));
		child_preferencia = GTK_WIDGET(gtk_builder_get_object(builder, "child_preferencia"));
		window_login = GTK_WIDGET(gtk_builder_get_object(builder, "Login_main"));
		btn_menu_pos = GTK_WIDGET(gtk_builder_get_object(builder, "btn_menu_pos"));
		btn_Sesion = GTK_WIDGET(gtk_builder_get_object(builder, "btn_Sesion"));
		pasos = GTK_STACK(gtk_builder_get_object(builder, "pasos"));
		ety_user_bien= GTK_ENTRY(gtk_builder_get_object(builder, "ety_user_bien"));
		window_BD = GTK_WIDGET(gtk_builder_get_object(builder,"Window_BD"));
		bienvenido = GTK_WIDGET(gtk_builder_get_object(builder,"bienvenido"));
		actualiza_factura = GTK_WIDGET(gtk_builder_get_object(builder,"actualiza_factura"));
		actualiza_empresa = GTK_WIDGET(gtk_builder_get_object(builder,"actualiza_empresa"));
		actualiza_producto = GTK_WIDGET(gtk_builder_get_object(builder,"actualiza_producto"));
		info_bar = GTK_WIDGET(gtk_builder_get_object(builder,"info_bar"));
		info_bar_bien = GTK_WIDGET(gtk_builder_get_object(builder,"info_bar_bien"));
		g_Entry_Usuario = GTK_ENTRY(gtk_builder_get_object(builder,"Entry_Usuario"));
		g_Entry_Contrasena = GTK_ENTRY(gtk_builder_get_object(builder,"Entry_Contrasena"));
		g_Dialog_Error = GTK_WIDGET(gtk_builder_get_object(builder,"Dialog_Error"));
		lbl_error = GTK_LABEL(gtk_builder_get_object(builder,"lbl_error"));
		inserta_factura = GTK_WIDGET(gtk_builder_get_object(builder,"inserta_factura"));
		inserta_producto = GTK_WIDGET(gtk_builder_get_object(builder,"inserta_producto"));
		inserta_empresa = GTK_WIDGET(gtk_builder_get_object(builder,"inserta_empresa"));
		info_actualizar = GTK_WIDGET(gtk_builder_get_object(builder,"info_actualizar"));
		info_ananido = GTK_WIDGET(gtk_builder_get_object(builder,"info_ananido"));
		info_eliminado = GTK_WIDGET(gtk_builder_get_object(builder,"info_eliminado"));
		
		ety_busca_producto = GTK_ENTRY(gtk_builder_get_object(builder,"ety_busca_producto"));
		ety_busca_proveedor_producto = GTK_ENTRY(gtk_builder_get_object(builder,"ety_busca_proveedor_producto"));
		ety_busca_categoria = GTK_ENTRY(gtk_builder_get_object(builder,"ety_busca_categoria"));
		ety_busca_subcategoria = GTK_ENTRY(gtk_builder_get_object(builder,"ety_busca_subcategoria"));
		
		La_lbl_Titulo_BD = GTK_LABEL(gtk_builder_get_object(builder,"lbl_Titulo_BD"));
		La_Label_Error_ingreso = GTK_LABEL(gtk_builder_get_object(builder,"Label_Error_ingreso"));
		cb_anio_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_fac"));
		cb_estado_emp = GTK_WIDGET(gtk_builder_get_object(builder,"cb_estado_emp"));
		dialog_error_datos = GTK_WIDGET(gtk_builder_get_object(builder,"dialog_error_datos"));
		btn_menu_pref_devol = GTK_BUTTON(gtk_builder_get_object(builder,"btn_menu_pref_devol"));
		tree_users = GTK_WIDGET(gtk_builder_get_object(builder,"tree_users"));
		view = GTK_WIDGET(gtk_builder_get_object(builder,"view"));
		view2 = GTK_WIDGET(gtk_builder_get_object(builder,"view2"));
		view3 = GTK_WIDGET(gtk_builder_get_object(builder,"view3"));
		view4 = GTK_WIDGET(gtk_builder_get_object(builder,"view4"));
		view5 = GTK_WIDGET(gtk_builder_get_object(builder,"view5"));
		view6 = GTK_WIDGET(gtk_builder_get_object(builder,"view6"));
		inserta_datos_productos = GTK_WIDGET(gtk_builder_get_object(builder,"inserta_datos_productos"));
		view_busc = GTK_WIDGET(gtk_builder_get_object(builder,"view_busc"));
		contenedor_view = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view"));
		contenedor_view2 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view2"));
		contenedor_view3 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view3"));
		contenedor_view4 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view4"));
		contenedor_view5 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view5"));
		contenedor_view6 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view6"));
		contenedor_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_busqueda"));
		contenedor_sql = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_sql"));
		stackgtk = GTK_WIDGET(gtk_builder_get_object(builder,"stack"));
		stack_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"stack_busqueda"));
		stack_actualiza = GTK_WIDGET(gtk_builder_get_object(builder,"stack_actualiza"));
		exportar_pdf = GTK_WIDGET(gtk_builder_get_object(builder,"exportar_pdf"));
		muestra_func = GTK_WIDGET(gtk_builder_get_object(builder,"muestra_func"));
		reveal_consulta = GTK_WIDGET(gtk_builder_get_object(builder,"reveal_consulta"));
		btn_sql_aceptar = GTK_WIDGET(gtk_builder_get_object(builder,"btn_sql_aceptar"));
		btn_actualiza_emp = GTK_BUTTON(gtk_builder_get_object(builder,"btn_actualiza_emp"));
		ocultar_btn = GTK_WIDGET(gtk_builder_get_object(builder,"ocultar_btn"));
		win_acercade = GTK_WIDGET(gtk_builder_get_object(builder,"acercade"));
		switchgtk = GTK_WIDGET(gtk_builder_get_object(builder,"activador_sql"));
		source_code = GTK_WIDGET(gtk_builder_get_object(builder,"Codigo_sql"));
		lbl_no_datos = GTK_WIDGET(gtk_builder_get_object(builder,"lbl_no_datos"));
		lbl_anadir_advertencia = GTK_LABEL(gtk_builder_get_object(builder,"lbl_anadir_advertencia"));
		lbl_eliminar_advertencia = GTK_LABEL(gtk_builder_get_object(builder,"lbl_eliminar_advertencia"));
		lbl_info = GTK_LABEL(gtk_builder_get_object(builder,"lbl_info"));
		lbl_user_bien = GTK_LABEL(gtk_builder_get_object(builder,"lbl_user_bien"));
		advertencia_anadir_fac = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_anadir_fac"));
		advertencia_anadir_emp = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_anadir_emp"));
		advertencia_anadir_pro = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_anadir_pro"));
		advertencia_actualizar_emp = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_actualizar_emp"));
		advertencia_actualizar_fac = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_actualizar_fac"));
		advertencia_actualizar_pro = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_actualizar_pro"));
		advertencia_eliminar_fac = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_eliminar_fac"));
		advertencia_eliminar_pro = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_eliminar_pro"));
		advertencia_eliminar_emp = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_eliminar_emp"));
		seleccion_view = GTK_TREE_SELECTION(gtk_builder_get_object(builder,"seleccion_view"));
		seleccion_view2 = GTK_TREE_SELECTION(gtk_builder_get_object(builder,"seleccion_view2"));
		debug_textview = GTK_TEXT_VIEW(gtk_builder_get_object(builder,"debug_textview"));
		swchitcher = GTK_WIDGET(gtk_builder_get_object(builder,"swchitcher"));
		debug = GTK_WIDGET(gtk_builder_get_object(builder,"debug"));
		textbuffer_main = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "textbuffer_main"));
		entry_buscar = GTK_ENTRY(gtk_builder_get_object(builder,"entry_buscar"));
		historial_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"historial_busqueda"));
		stack_historial = GTK_WIDGET(gtk_builder_get_object(builder,"stack_historial"));
		contenedor_historial = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_historial"));
		box_act_emp = GTK_WIDGET(gtk_builder_get_object(builder,"box_act_emp"));
		bar = GTK_WIDGET(gtk_builder_get_object(builder,"bar"));
		bar_bien = GTK_WIDGET(gtk_builder_get_object(builder,"bar_bien"));
		popovermenu1 = GTK_WIDGET(gtk_builder_get_object(builder,"popovermenu1"));
		btn_aceptar_a1 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_aceptar_a1"));
		cb_productos_proveedor = GTK_WIDGET(gtk_builder_get_object(builder,"cb_productos_proveedor"));
		pro_aceptar_anadir = GTK_WIDGET(gtk_builder_get_object(builder,"pro_aceptar_anadir"));
		btn_actualiza_pro = GTK_WIDGET(gtk_builder_get_object(builder,"btn_actualiza_pro"));
		reveal_proveedor =  GTK_WIDGET(gtk_builder_get_object(builder,"reveal_proveedor"));
		btn_aceptar_1 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_aceptar_1"));
		emp_aceptar_anadir = GTK_WIDGET(gtk_builder_get_object(builder,"emp_aceptar_anadir"));
		reveal_productos = GTK_WIDGET(gtk_builder_get_object(builder,"reveal_productos"));
		stack_header = GTK_STACK(gtk_builder_get_object(builder,"stack_header"));
		stack_sku = GTK_STACK(gtk_builder_get_object(builder,"stack_sku"));
		ety_emp_bien = GTK_ENTRY(gtk_builder_get_object(builder,"ety_emp_bien"));
		ety_num_bien = GTK_ENTRY(gtk_builder_get_object(builder,"ety_num_bien"));
		ety_dir_bien = GTK_ENTRY(gtk_builder_get_object(builder,"ety_dir_bien"));
		ety_rfc_bien = GTK_ENTRY(gtk_builder_get_object(builder,"ety_rfc_bien"));
		ety_busc_producto = GTK_WIDGET(gtk_builder_get_object(builder,"ety_busc_producto"));
		child_busqueda_pos = GTK_WIDGET(gtk_builder_get_object(builder,"child_busqueda_pos"));
		child_oculta_bus_pos = GTK_WIDGET(gtk_builder_get_object(builder,"child_oculta_bus_pos"));
		stack_pos = GTK_STACK(gtk_builder_get_object(builder,"stack_pos"));
		stack_bus_pos = GTK_STACK(gtk_builder_get_object(builder,"stack_bus_pos"));
		pag_pos = GTK_WIDGET(gtk_builder_get_object(builder,"pag_pos"));
		pag_proveedor = GTK_WIDGET(gtk_builder_get_object(builder,"pag_proveedor"));
		pag_producto = GTK_WIDGET(gtk_builder_get_object(builder,"pag_producto"));
		pag_tickets = GTK_WIDGET(gtk_builder_get_object(builder,"pag_tickets"));
		
		btn_4cb = GTK_BUTTON(gtk_builder_get_object(builder,"btn_4cb"));
		btn_8cb = GTK_BUTTON(gtk_builder_get_object(builder,"btn_8cb"));
		btn_13cb = GTK_BUTTON(gtk_builder_get_object(builder,"btn_13cb"));

		lbl_emp_bien = GTK_LABEL(gtk_builder_get_object(builder,"lbl_emp_bien"));
		lbl_num_bien = GTK_LABEL(gtk_builder_get_object(builder,"lbl_num_bien"));
		lbl_dir_bien = GTK_LABEL(gtk_builder_get_object(builder,"lbl_dir_bien"));
		lbl_rfc_bien = GTK_LABEL(gtk_builder_get_object(builder,"lbl_rfc_bien"));		
		lbl_info_bien = GTK_LABEL(gtk_builder_get_object(builder,"lbl_info_bien"));
	
		ety_idpro = GTK_ENTRY(gtk_builder_get_object(builder,"ety_idpro"));
		ety_idemp = GTK_ENTRY(gtk_builder_get_object(builder,"ety_idemp"));
		ety_catidad = GTK_ENTRY(gtk_builder_get_object(builder,"ety_catidad"));
		ety_precio = GTK_ENTRY(gtk_builder_get_object(builder,"ety_precio"));
		ety_mpago = GTK_ENTRY(gtk_builder_get_object(builder,"ety_mpago"));
		ety_desc = GTK_ENTRY(gtk_builder_get_object(builder,"ety_desc"));
		ety_total = GTK_ENTRY(gtk_builder_get_object(builder,"ety_total"));
		
		ety_contrasena1 = GTK_ENTRY(gtk_builder_get_object(builder,"ety_contrasena1"));
		ety_contrasena2 = GTK_ENTRY(gtk_builder_get_object(builder,"ety_contrasena2"));
		btn_buscar_pos = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"btn_buscar_pos"));	
		btn_edit_proveedor = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"btn_edit_proveedor"));
		btn_edit_productos = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"btn_edit_productos"));	
		ety_produ_emp = GTK_ENTRY(gtk_builder_get_object(builder,"ety_produ_emp"));
		ety_nombreemp = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nombreemp"));
		ety_direccion = GTK_ENTRY(gtk_builder_get_object(builder,"ety_direccion"));
		ety_telefono = GTK_ENTRY(gtk_builder_get_object(builder,"ety_telefono"));
		ety_region = GTK_ENTRY(gtk_builder_get_object(builder,"ety_region"));
		ety_pais = GTK_ENTRY(gtk_builder_get_object(builder,"ety_pais"));
		ety_rfc = GTK_ENTRY(gtk_builder_get_object(builder,"ety_rfc"));
		ety_correoemp = GTK_ENTRY(gtk_builder_get_object(builder,"ety_correoemp"));
		ety_pais_emp = GTK_ENTRY(gtk_builder_get_object(builder,"ety_pais_emp"));
		ety_estado_emp = GTK_ENTRY(gtk_builder_get_object(builder,"ety_estado_emp"));
		ety_busca_proveedor = GTK_ENTRY(gtk_builder_get_object(builder,"ety_busca_proveedor"));
		
		
		ety_nombrepro = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nombrepro"));
		ety_marcapro = GTK_ENTRY(gtk_builder_get_object(builder,"ety_marcapro"));
		ety_nlote = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nlote"));
		ety_des = GTK_ENTRY(gtk_builder_get_object(builder,"ety_des"));
		ety_cbarra = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cbarra"));
		ety_cneto = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cneto"));
		ety_id_empresa = GTK_ENTRY(gtk_builder_get_object(builder,"ety_id_empresa"));
		ety_id_producto = GTK_ENTRY(gtk_builder_get_object(builder,"ety_id_producto"));
		ety_nombre_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nombre_act"));
		ety_direccion_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_direccion_act"));
		ety_telefono_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_telefono_act"));
		ety_region_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_region_act"));
		ety_pais_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_pais_act"));
		ety_rfc_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_rfc_act"));
		ety_correo_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_correo_act"));
		
		id_fac_act = GTK_ENTRY(gtk_builder_get_object(builder,"id_fac_act"));
		ety_profac_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_profac_act"));
		ety_empfact_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_empfact_act"));
		ety_cantidafac_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cantidafac_act"));
		ety_preci_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_preci_act"));
		ety_mpago_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_mpago_act"));
		ety_descfac_act1 = GTK_ENTRY(gtk_builder_get_object(builder,"ety_descfac_act1"));
		ety_totalfac_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_totalfac_act"));
		
		ety_idpro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_idpro_act"));
		ety_nombrepro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nombrepro_act"));
		ety_marcapro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_marcapro_act"));
		ety_nlotepro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nlotepro_act"));
		ety_descpro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_descpro_act"));
		ety_cbarrapro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cbarrapro_act"));
		ety_cnetopro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cnetopro_act"));
		
		ety_id_fac_borrar = GTK_ENTRY(gtk_builder_get_object(builder,"ety_id_fac_borrar"));
		ety_id_emp_borrar = GTK_ENTRY(gtk_builder_get_object(builder,"ety_id_emp_borrar"));
		ety_id_pro_borrar = GTK_ENTRY(gtk_builder_get_object(builder,"ety_id_pro_borrar"));
		
		entry_subcat = GTK_ENTRY(gtk_builder_get_object(builder,"entry_subcat"));
		cb_dia_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_fac"));
		cb_mes_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_fac"));
		cb_anio_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_fac"));
		cb_dia_pro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_pro"));
		cb_mes_pro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_pro"));
		cb_anio_pro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_pro"));
		cb_dia_propro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_propro"));
		cb_mes_propro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_propro"));
		cb_anio_propro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_propro"));
		cb_dia_fac_actu = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_fac_actu"));
		cb_mes_fac_actu = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_fac_actu"));
		cb_anio_fac_actu = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_fac_actu"));
		cb_cat = GTK_WIDGET(gtk_builder_get_object(builder,"cb_cat"));
		cb_subcat = GTK_WIDGET(gtk_builder_get_object(builder,"cb_subcat"));
		cb_pais_emp = GTK_WIDGET(gtk_builder_get_object(builder,"cb_pais_emp"));
		child_tam_sku = GTK_WIDGET(gtk_builder_get_object(builder,"child_tam_sku"));
		btn_consulta_pos = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"btn_consulta_pos"));
		cb_dia_proact = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_proact"));
		cb_mes_proact = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_proact"));
		cb_anio_proact = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_proact"));
		cb_bs_cat = GTK_WIDGET(gtk_builder_get_object(builder,"cb_bs_cat"));
		cb_bs_subcat = GTK_WIDGET(gtk_builder_get_object(builder,"cb_bs_subcat"));
		cb_busca_estado = GTK_WIDGET(gtk_builder_get_object(builder,"cb_busca_estado"));
		switcher = GTK_WIDGET(gtk_builder_get_object(builder,"switcher"));
		pop_generar_sku = GTK_WIDGET(gtk_builder_get_object(builder,"pop_generar_sku"));
		
		cb_dia_proact2 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_proact2"));
		cb_mes_proact2 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_proact2"));
		cb_anio_proact2 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_proact2"));
		cb_marcapro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_marcapro"));
		btn_cancelar_adver3 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver3"));
		cancela_and_factura3= GTK_WIDGET(gtk_builder_get_object(builder,"cancela_and_factura3"));
		
		revel_bucar = GTK_WIDGET(gtk_builder_get_object(builder,"revel_bucar"));
		treeview_pos = GTK_WIDGET(gtk_builder_get_object(builder,"treeview_pos"));
		inserta_datos_empresa = GTK_WIDGET(gtk_builder_get_object(builder,"inserta_datos_empresa"));
		selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(historial_busqueda));
		btn_cancelar_stp = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_stp"));
		pag_atras = GTK_WIDGET(gtk_builder_get_object(builder,"pag_atras"));
		pag_sig = GTK_WIDGET(gtk_builder_get_object(builder,"pag_sig"));
		acerca_de  = GTK_WIDGET(gtk_builder_get_object(builder,"acerca_de"));
		stack_menu_pos = GTK_STACK(gtk_builder_get_object(builder,"stack_menu_pos"));
		child_sku = GTK_WIDGET(gtk_builder_get_object(builder,"child_sku"));
		spin_compra = GTK_WIDGET(gtk_builder_get_object(builder,"spin_compra"));
		spin_piezas = GTK_WIDGET(gtk_builder_get_object(builder,"spin_piezas"));
		spin_venta = GTK_WIDGET(gtk_builder_get_object(builder,"spin_venta"));
		
		for(i=2051;i>=1950;i--){ 
			sprintf(anio,"%d",i);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_pro),anio);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_propro),anio);
		}
		
		
		btn_borrar_emp = GTK_WIDGET(gtk_builder_get_object(builder,"btn_borrar_emp"));
		btn_consulta_emp = GTK_WIDGET(gtk_builder_get_object(builder,"btn_consulta_emp"));
		btn_cancelar_adver8 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver8"));
		btn_cancelar_adver2 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver2"));
		btn_cancelar_adver9 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver9"));
		btn_cancelar_adver7 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver7"));
		btn_cancelar_adver5 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver5"));
		btn_cancelar_adver1 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver1"));
		btn_cancelar_adver4 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver4"));
		btn_cancelar_adver6 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver6"));
		
		btn_servicios = GTK_WIDGET(gtk_builder_get_object(builder,"btn_servicios"));
		
		g_signal_connect(G_OBJECT(btn_cancelar_adver8),"clicked",G_CALLBACK(on_btn_cancelar_adver8_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver2),"clicked",G_CALLBACK(on_btn_cancelar_adver2_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver7),"clicked",G_CALLBACK(on_btn_cancelar_adver7_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver5),"clicked",G_CALLBACK(on_btn_cancelar_adver5_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver1),"clicked",G_CALLBACK(on_btn_cancelar_adver1_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver4),"clicked",G_CALLBACK(on_btn_cancelar_adver4_clicked),NULL);

		g_signal_connect(G_OBJECT(btn_Sesion),"clicked",G_CALLBACK(on_btn_Sesion_clicked),NULL);
		g_signal_connect(G_OBJECT(g_Entry_Contrasena),"activate",G_CALLBACK(on_Entry_Contrasena_activate),NULL);
		g_signal_connect(G_OBJECT(btn_Rein_Dial),"clicked",G_CALLBACK(on_btn_Rein_Dial_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver3),"clicked",G_CALLBACK(on_btn_cancelar_adver3_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver6),"clicked",G_CALLBACK(on_btn_cancelar_adver6_clicked),NULL);
		g_signal_connect(G_OBJECT(inserta_datos_empresa),"clicked",G_CALLBACK(on_inserta_datos_empresa_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_consulta_emp),"clicked",G_CALLBACK(on_btn_consulta_emp_clicked),NULL);
		g_signal_connect(G_OBJECT(emp_aceptar_anadir),"clicked",G_CALLBACK(on_emp_aceptar_anadir_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_aceptar_1),"clicked",G_CALLBACK(on_btn_aceptar_1_clicked),NULL);
		g_signal_connect(G_OBJECT(bar),"clicked",G_CALLBACK(on_info_close),NULL);
		g_signal_connect(G_OBJECT(cancela_and_factura3),"clicked",G_CALLBACK(on_cancela_and_factura3_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cambiar_usuario),"clicked",G_CALLBACK(on_btn_cambiar_usuario_clicked),NULL);
		g_signal_connect(G_OBJECT(actualiza_datos_empresa),"clicked",G_CALLBACK(on_actualiza_datos_empresa_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_borrar_emp),"clicked",G_CALLBACK(on_btn_borrar_emp_clicked),NULL);		
		g_signal_connect(G_OBJECT(btn_cancelar_stp),"clicked",G_CALLBACK(cerrar_setup),NULL);	
		g_signal_connect(G_OBJECT(pag_sig),"clicked",G_CALLBACK(siguiente),NULL);
		g_signal_connect(G_OBJECT(pag_atras),"clicked",G_CALLBACK(atras),NULL);	
		g_signal_connect(G_OBJECT(btn_servicios),"clicked",G_CALLBACK(pagar_servicios),NULL);
		g_signal_connect(G_OBJECT(ety_user_bien),"changed",G_CALLBACK(consigue_datos),NULL);
		g_signal_connect(G_OBJECT(ety_dir_bien),"changed",G_CALLBACK(consigue_datos2),NULL);
		g_signal_connect(G_OBJECT(ety_rfc_bien),"changed",G_CALLBACK(consigue_datos3),NULL);
		g_signal_connect(G_OBJECT(bar),"response",G_CALLBACK(on_info_close),NULL);
		g_signal_connect(G_OBJECT(bar_bien),"response",G_CALLBACK(on_info_close2),NULL);
		g_signal_connect(G_OBJECT(win_acercade),"delete-event",G_CALLBACK(on_acercade_response),NULL);
		g_signal_connect(G_OBJECT(widget_web),"delete-event",G_CALLBACK(on_web_response),NULL);
		g_signal_connect(G_OBJECT(win_acercade),"response",G_CALLBACK(on_acercade_response),NULL);
		g_signal_connect(G_OBJECT(btn_buscar_pos),"toggled",G_CALLBACK(abre_busca),NULL);
		g_signal_connect(G_OBJECT(btn_consulta_pos),"toggled",G_CALLBACK(consulta_pos),NULL);
		g_signal_connect(G_OBJECT(btn_edit_proveedor),"toggled",G_CALLBACK(modifica_proveedor),NULL);
		g_signal_connect(G_OBJECT(btn_edit_productos),"toggled",G_CALLBACK(modifica_productos),NULL);
		g_signal_connect(G_OBJECT(acerca_de),"clicked",G_CALLBACK(on_acercade_clicked),NULL);		
		g_signal_connect(G_OBJECT(btn_menu_pref),"clicked",G_CALLBACK(abre_preferencias),NULL);
		g_signal_connect(G_OBJECT(btn_menu_pref_devol),"clicked",G_CALLBACK(regresa_menu),NULL);		
		g_signal_connect(G_OBJECT(ety_produ_emp),"activate",G_CALLBACK(on_btn_consulta_emp_clicked),NULL);
		g_signal_connect(G_OBJECT(ety_cbarra),"focus-in-event",G_CALLBACK(show_gensku),NULL);
		g_signal_connect(G_OBJECT(ety_cbarra),"focus-out-event",G_CALLBACK(hide_gensku),NULL);
		g_signal_connect(G_OBJECT(child_sku),"clicked",G_CALLBACK(show_gensku_child),NULL);
		g_signal_connect(G_OBJECT(btn_actualiza_emp),"clicked",G_CALLBACK(on_btn_actualiza_emp_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_aceptar_a1),"clicked",G_CALLBACK(on_btn_aceptar_a1_clicked),NULL);
		
		
		g_signal_connect(G_OBJECT(swchitcher),"touch-event",G_CALLBACK(header_busqueda),NULL);
		g_signal_connect(G_OBJECT(cb_cat),"changed",G_CALLBACK(cambia_categoria),NULL);
		g_signal_connect(G_OBJECT(cb_bs_cat),"changed",G_CALLBACK(cambia_bs_categoria),NULL);
		g_signal_connect(G_OBJECT(ety_busca_proveedor),"changed",G_CALLBACK(busca_proveedor),NULL);
		g_signal_connect(G_OBJECT(cb_busca_estado),"changed",G_CALLBACK(busca_proveedor),NULL);
		g_signal_connect(G_OBJECT(inserta_datos_productos),"clicked",G_CALLBACK(on_inserta_datos_empres_clicked),NULL);
		g_signal_connect(G_OBJECT(pro_aceptar_anadir),"clicked",G_CALLBACK(on_pro_aceptar_anadir_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_actualiza_pro),"clicked",G_CALLBACK(on_btn_actualiza_pro_clicked),NULL);	
		g_signal_connect(G_OBJECT(ety_busca_producto),"changed",G_CALLBACK(busca_producto),NULL);
		g_signal_connect(G_OBJECT(ety_busca_proveedor_producto),"changed",G_CALLBACK(busca_producto),NULL);
		g_signal_connect(G_OBJECT(ety_busca_categoria),"changed",G_CALLBACK(busca_producto),NULL);
		g_signal_connect(G_OBJECT(ety_busca_subcategoria),"changed",G_CALLBACK(busca_producto),NULL);
		
		g_signal_connect(G_OBJECT(ety_busca_proveedor_producto),"icon-press",G_CALLBACK(borra_busqueda1),NULL);
		g_signal_connect(G_OBJECT(ety_busca_categoria),"icon-press",G_CALLBACK(borra_busqueda2),NULL);
		g_signal_connect(G_OBJECT(ety_busca_subcategoria),"icon-press",G_CALLBACK(borra_busqueda3),NULL);
		
		g_signal_connect(G_OBJECT(btn_4cb),"clicked",G_CALLBACK(cucb),NULL);
		g_signal_connect(G_OBJECT(btn_8cb),"clicked",G_CALLBACK(occb),NULL);
		g_signal_connect(G_OBJECT(btn_13cb),"clicked",G_CALLBACK(trecb),NULL);
		
		gtk_builder_connect_signals(builder, NULL);
		g_timeout_add_seconds(1, (GSourceFunc)timer_handler, NULL);
		gtk_button_set_image (GTK_BUTTON (btn_menu_pos), gtk_image_new_from_icon_name ("open-menu-symbolic", GTK_ICON_SIZE_BUTTON));
		//consulta_usuarios();
		gtk_widget_show(window_login);
		gtk_main();			
		
	}
gboolean timer_handler()
{
    GDateTime *date_time;
    gchar *dt_format;

    date_time = g_date_time_new_now_local();                        // get local time
    dt_format = g_date_time_format(date_time, "%d/%m/%y %H:%M:%S");            // 24hr time format
    gtk_label_set_text(lbl_hora, dt_format);    // update label
    g_free (dt_format);
    
    return TRUE;
}
