/*
 * coneccion.c
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
#include "tablas.c"


gboolean 		timer_handler();
FILE* 			fichero;
FILE* 			fichero2;
FILE* 			fichero3;
const char 		*user;
const char 		*password;
char 			*server = "192.168.0.45";
char 			*database = "Tienda";


void contenido_ticket(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	if (mysql_query(conn, "select * from Ticket ORDER BY Id_ticket DESC"))
	{ 
	}
	res = mysql_use_result(conn);
while ((row = mysql_fetch_row(res)) != NULL)titulo_factura();
	mysql_free_result(res);
	mysql_close(conn);
}

void contenido_producto(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	if (mysql_query(conn, "select * from Producto"))
	{ 
	}
	res = mysql_use_result(conn);
	 while ((row = mysql_fetch_row(res)) != NULL)titulo_producto();
	mysql_free_result(res);
	mysql_close(conn);
}
void conectar(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
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
 if (mysql_query(conn, "select Empresa from Proveedor")) 
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
	 gtk_label_set_text(lbl_usuario,user);
 }
 mysql_free_result(res);
 mysql_close(conn);

}	

void consulta_proveedor(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
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
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	
	if (mysql_query(conn, "select * from Proveedor"))
	{ 
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) titulo_empresa();
	mysql_free_result(res);
	mysql_close(conn);
	
	}

void contenido_aud_proveedor(){
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	
	if (mysql_query(conn, "select * from Aud_proveedor ORDER BY Id DESC"))
	{ 
	}
	res = mysql_use_result(conn);
while ((row = mysql_fetch_row(res)) != NULL) titulo_empresa_auditoria();
	mysql_free_result(res);
	mysql_close(conn);
	
	}

void contenido_aud_ticket(){
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	
	if (mysql_query(conn, "select * from Aud_ticket ORDER BY Id DESC"))
	{ 
	}
	res = mysql_use_result(conn);
while ((row = mysql_fetch_row(res)) != NULL) titulo_factura_auditoria();
	mysql_free_result(res);
	mysql_close(conn);
	
	}

void contenido_aud_producto(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	
	if (mysql_query(conn, "select * from Aud_producto ORDER BY Id DESC"))
	{ 
	}
	res = mysql_use_result(conn);
//==================================================================================================================
while ((row = mysql_fetch_row(res)) != NULL) titulo_producto_auditoria();
	mysql_free_result(res);
	mysql_close(conn);
}
