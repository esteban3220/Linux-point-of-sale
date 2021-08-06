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
 * gcc -Wall -o "%e" "%f" `pkg-config --cflags --libs gtk+-3.0` $(mariadb_config --cflags) $(mariadb_config --libs)  -rdynamic -lm
 */

#include <stdio.h>
#include <gtk/gtk.h>
#include <mysql.h> 
#include <stdlib.h>
#include "coneccion.c"
#include "combobox.c"
#include "refresca_tablas.c"


void ver_carrito(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	if (mysql_query(conn, "select Producto , P_unitario , count(Producto) as 'No', (P_unitario * count(Producto)) as SubTotal from Carrito_compra group by Producto"))
	{
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)titulo_POS();

	mysql_free_result(res);
	mysql_close(conn);
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
void on_btn_Sesion_clicked ( )
{
	conectar();
	contenido_tablas();
	contenido_producto();
	contenido_aud_proveedor();
	contenido_aud_producto();
	contenido_ticket();
	contenido_aud_ticket();
	ver_carrito();
}

void on_Entry_Contrasena_activate()
{	
	conectar();
	contenido_tablas();
	contenido_producto();
	contenido_aud_proveedor();
	contenido_aud_producto();
	contenido_aud_ticket();
	contenido_ticket();
	ver_carrito();
}
	
void on_btn_cancelar_adver3_clicked()
{
	gtk_widget_hide(g_Dialog_Error);
}
void cierra_error()
{
	gtk_widget_hide_on_delete(g_Dialog_Error);
}
		
void on_btn_Rein_Dial_clicked()
	{
		gtk_entry_set_text(g_Entry_Usuario,"");
		gtk_entry_set_text(g_Entry_Contrasena,"");
		gtk_widget_hide_on_delete (g_Dialog_Error);
	}


void on_cancela_and_factura4_clicked(){
		gtk_widget_hide(inserta_producto);
	}
void on_cancela_and_factura2_clicked(){
	gtk_stack_set_visible_child (GTK_STACK(stack_actualiza2),inserta_datos_productos);	
	gtk_entry_set_text(ety_cbarra,"");
	gtk_entry_set_text(ety_nombrepro,"");
	gtk_entry_set_text(ety_marcapro,"");
	gtk_entry_set_text(ety_cneto,"");
	gtk_entry_set_text(ety_nlote,"");
	gtk_entry_set_text(GTK_ENTRY(spin_piezas),"0");
	gtk_entry_set_text(GTK_ENTRY(spin_compra),"0.00");
	gtk_entry_set_text(GTK_ENTRY(spin_venta),"0.00");
	gtk_entry_set_text(GTK_ENTRY(ety_cat),"");
	gtk_entry_set_text(GTK_ENTRY (entry_subcat),"");	
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_dia_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_mes_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_anio_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_dia_propro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_mes_propro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_anio_propro),0);
	}
void on_btn_cancelar_adver_clicked(){
	gtk_widget_hide(advertencia_anadir_fac);
	}
void on_cancela_and_factura_clicked(){
	gtk_widget_hide_on_delete(inserta_factura);
	}

void on_btn_cambiar_usuario_clicked()
{
	gtk_entry_set_text(g_Entry_Usuario,"");
	gtk_entry_set_text(g_Entry_Contrasena,"");
	gtk_widget_hide_on_delete(window_BD);
	gtk_widget_show(window_login);
	gtk_widget_hide_on_delete (g_Dialog_Error);
	refresca_busquedapos();
	refresca_datos_emp();
	refresca_datos_fac();
	refresca_datos_pro();
	refresca_pos();
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
	contenido_aud_proveedor();

	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_marcapro));
	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_productos_proveedor));
	consulta_proveedor();
	gtk_widget_hide(advertencia_anadir_emp);
	gtk_label_set_text(lbl_info,"Proveedor Insertado Exitosamente");
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
	gtk_entry_set_text(GTK_ENTRY(ety_cat),"");
	gtk_entry_set_text(GTK_ENTRY (entry_subcat),"");	
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_dia_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_mes_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_anio_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_dia_propro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_mes_propro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_anio_propro),0);
	
	refresca_datos_pro();
	contenido_producto();
	contenido_aud_producto();
	gtk_widget_hide(advertencia_anadir_pro);
	gtk_label_set_text(lbl_info,"Producto Insertado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
	}
//================================================

void on_btn_aceptar_1_clicked(){
	gtk_widget_hide(dialog_error_datos);
	}
//=========== Actualiza datos ====================================

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
		gtk_widget_hide(advertencia_anadir_emp);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
	}
	
			gtk_entry_set_text(ety_nombreemp,"");
			gtk_entry_set_text(ety_direccion,"");
			gtk_entry_set_text(ety_telefono,"");
			gtk_entry_set_text(ety_region,"");
			gtk_entry_set_text(ety_pais_emp,"");
			gtk_entry_set_text(ety_rfc,"");
			gtk_entry_set_text(ety_estado_emp,"");
			gtk_entry_set_text(ety_correoemp,"");

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_actualizar_emp);	
	
	gtk_label_set_text(lbl_info,"Provedor Actualizado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
	gtk_stack_set_visible_child (GTK_STACK(stack_actualiza),inserta_datos_empresa);
	refresca_datos_emp();
	contenido_aud_proveedor();
	contenido_tablas();
	}
	
void on_actualiza_datos_producto_clicked(){
	gtk_widget_show(advertencia_actualizar_pro);
	}
void on_btn_cancelar_adver5_clicked(){
	gtk_widget_hide(advertencia_actualizar_pro);
	}
//=========== Elimina datos =====================================
void on_btn_borrar_emp_clicked(){
	gtk_widget_show(advertencia_eliminar_emp);
	}
void on_btn_cancelar_adver8_clicked(){
	gtk_widget_hide(advertencia_eliminar_emp);
	}
void on_btn_cancelar_adver9_clicked(){
	gtk_widget_hide(advertencia_eliminar_pro);
	}
void on_btn_aceptar_a1_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char elimina_fac[50];
	
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
		gtk_widget_hide(advertencia_eliminar_emp);
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
	gtk_label_set_text(lbl_info,"Proveedor Eliminado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
	contenido_tablas();
	contenido_producto();
	consulta_proveedor();
	contenido_aud_proveedor();
	gtk_stack_set_visible_child (GTK_STACK(stack_actualiza),inserta_datos_empresa);
}
void on_btn_borrar_pro_clicked(){
	gtk_widget_show(advertencia_eliminar_pro);
	}
void on_btn_aceptar_a2_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char elimina_fac[50];
	
	const char 	*id = gtk_entry_get_text(ety_cbarra);

	sprintf(elimina_fac,"delete from Producto where SKU=%s",id);
	
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
	
	gtk_entry_set_text(ety_cbarra,"");
	gtk_entry_set_text(ety_nombrepro,"");
	gtk_entry_set_text(ety_marcapro,"");
	gtk_entry_set_text(ety_cneto,"");
	gtk_entry_set_text(ety_nlote,"");
	gtk_entry_set_text(GTK_ENTRY(spin_piezas),"0");
	gtk_entry_set_text(GTK_ENTRY(spin_compra),"0.00");
	gtk_entry_set_text(GTK_ENTRY(spin_venta),"0.00");
	gtk_entry_set_text(GTK_ENTRY(ety_cat),"");
	gtk_entry_set_text(GTK_ENTRY (entry_subcat),"");	
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_dia_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_mes_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_anio_pro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_dia_propro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_mes_propro),0);
	gtk_combo_box_set_active (GTK_COMBO_BOX (cb_anio_propro),0);
	
	gtk_stack_set_visible_child(GTK_STACK(stack_actualiza2),inserta_datos_productos);
	
	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_eliminar_pro);
	gtk_label_set_text(lbl_info,"Producto Eliminado Exitosamente");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
	refresca_datos_pro();
	contenido_producto();
	contenido_aud_producto();
}
	
//================================================
void on_Window_BD_destroy()
{
	const char 		*total = gtk_label_get_text(lbl_totalpos);
	if((strcmp(total,"0.00") == 0) | (strcmp(total,"") == 0)){
    gtk_main_quit();
}else{
	gtk_label_set_text(lbl_error,"La venta no se a concluido");
	gtk_widget_show(dialog_error_datos);
	}
}
void on_btn_cerrar_acd_clicked (){
	gtk_widget_hide (win_acercade);
	}

void cierra_emp(){
	gtk_widget_hide_on_delete(advertencia_anadir_emp);
	}
void cierra_emp_eli(){
	gtk_widget_hide_on_delete(advertencia_eliminar_emp);
	}
void cierra_pro(){
	gtk_widget_hide_on_delete(advertencia_anadir_pro);
	}
void cierra_pro_eli(){
	gtk_widget_hide_on_delete(advertencia_eliminar_pro);
	}
void cierra_error_datos(){
	gtk_widget_hide_on_delete(dialog_error_datos);
	}
void cierra_act(){
	gtk_widget_hide_on_delete(advertencia_actualizar_emp);
	}
void busca_producto_pos(){
	gtk_stack_set_visible_child(GTK_STACK(stack_pop_producto),lbl_nodatos);
	char busqueda_fac[300];
	const char 	*consulta = gtk_entry_get_text(GTK_ENTRY(ety_producto_pos));

	sprintf(busqueda_fac,"select Nombre , Venta from Producto where Nombre LIKE '%%%s%%' or SKU ='%s'",consulta,consulta);

	conn = mysql_init(NULL);
	if (strcmp(consulta,"") == 0){
		gtk_widget_set_visible (pop_busqueda_pos,0);
	}else{
		gtk_widget_set_visible (pop_busqueda_pos,1);
	

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
		refresca_busquedapos();
	while ((row = mysql_fetch_row(res)) != NULL) titulo_bus();
	gtk_stack_set_visible_child(GTK_STACK(stack_pop_producto),cont_view_bus);
	  
	mysql_free_result(res);
	mysql_close(conn);
	}
	}

void busca_proveedor(){

	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char busqueda_fac[300];
	const char 	*consulta = gtk_entry_get_text(ety_busca_proveedor);
	const char 	*consulta2 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_busca_estado));
	
	if (consulta2[0]=='E'){

	sprintf(busqueda_fac,"select * from Proveedor where Empresa LIKE '%%%s%%'",consulta);
}else{
	sprintf(busqueda_fac,"select * from Proveedor where Empresa LIKE '%%%s%%' and Estado ='%s'",consulta,consulta2);
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
	while ((row = mysql_fetch_row(res)) != NULL) titulo_empresa();		  
	mysql_free_result(res);
	mysql_close(conn);

}

void busca_producto(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char busqueda_fac[600];	
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
	while ((row = mysql_fetch_row(res)) != NULL) 					 
	titulo_producto();
	mysql_free_result(res);
	mysql_close(conn);
	
	gtk_entry_set_progress_fraction (ety_busca_producto, 0.0);

}

void on_btn_consulta_emp_clicked(){

	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char busqueda_fac[50];
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

	gtk_entry_set_progress_fraction (ety_produ_emp, 0.0);
}
void on_btn_consulta_fac_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char busqueda_fac[50];
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
void consulta_producto(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	char busqueda_fac[50];
	const char 	*consulta = gtk_entry_get_text(ety_cbarra);

	sprintf(busqueda_fac,"select * from Producto where SKU = %s",consulta);
	
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
		
			gtk_entry_set_text(ety_nombrepro,row[1]);
			gtk_entry_set_text(ety_marcapro,row[2]);
			gtk_entry_set_text(ety_nlote,row[5]);
			gtk_entry_set_text(ety_cneto,row[6]);
			gtk_entry_set_text(GTK_ENTRY(spin_piezas),"");
			gtk_entry_set_text(GTK_ENTRY(spin_compra),row[8]);
			gtk_entry_set_text(GTK_ENTRY(spin_venta),row[9]);
			gtk_entry_set_text(GTK_ENTRY(ety_cat),row[10]);
			gtk_entry_set_text(GTK_ENTRY (entry_subcat),row[11]);
			gtk_stack_set_visible_child (GTK_STACK(stack_actualiza2),box_act_pro);
		}
	
	mysql_free_result(res);
	mysql_close(conn);
}
void genera_pdfproveedor(){
	
const char cabeceras []="\\documentclass[a4paper,12pt]{article}\n\\usepackage{longtable}\n\\usepackage{pdflscape}\n\\usepackage{graphicx,booktabs,tabularx}\n\\usepackage[spanish]{babel}\n\\begin{document}\n\\footnotesize  \n\\setlength\\LTleft{-30pt}\n \\setlength\\LTright{-100pt}\n  \\begin{landscape}\n \\thispagestyle{empty}\n\\begin{longtable}{|p{2.5cm}|p{2.5cm}|p{2.5cm}|p{2cm}|p{5cm}|p{1cm}|p{5cm}|}\n\\hline\n\\textbf{Empresa} & \\textbf{Nombre} & \\textbf{Direccion} & \\textbf{Telefono} & \\textbf{RFC} & \\textbf{Estado} & \\textbf{Correo}\\\\ \\hline \\hline ";
char fin_documento []="\\end{longtable}\n\\thispagestyle{empty}\n\\end{landscape}\n\\end{document}";	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, "select * from Proveedor"))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	
//==========================================================================================================================================================		

		fichero = fopen("Empresa.tex", "wt");
	fputs(cabeceras, fichero);
	while ((row = mysql_fetch_row(res)) != NULL) {
		fprintf(fichero,"%s & %s & %s & %s & %s & %s & %s \\\\ \\hline \n",row[0],row[1],row[2],row[3],row[6],row[7],row[8]);
	}
	fputs(fin_documento, fichero);
	fclose(fichero); 
	system("latexmk -pdf -synctex=1 Empresa.tex ");
    system("xdg-open Empresa.pdf &");
    //return ;
//==========================================================================================================================================================
	mysql_free_result(res);
	mysql_close(conn);
  

    gtk_label_set_text(lbl_info,"PDF Creado");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
	}
	
void pdf_producto(){
const char cabeceras []="\\documentclass[a4paper,12pt]{article}\n\\usepackage{longtable}\n\\usepackage{pdflscape}\n\\usepackage{graphicx,booktabs,tabularx}\n\\usepackage[spanish]{babel}\n\\begin{document}\n\\footnotesize  \n\\setlength\\LTleft{-50pt} \n\\setlength\\LTright{-100pt}  \n\\begin{landscape} \n\\thispagestyle{empty}\n\\begin{longtable}{|p{4cm}|p{2.5cm}|p{2.5cm}|p{1.8cm}|p{1.8cm}|p{1cm}|p{1cm}|p{3cm}|p{3cm}||}\n\\hline \n\\hline\n\\textbf{SKU} & \\textbf{Nombre} & \\textbf{Empresa} & \\textbf{Fecha de Produccion} & \\textbf{Fecha de Caducidad} & \\textbf{Piezas} & \\textbf{Venta} & \\textbf{Categoria} & \\textbf{Subcategoria}\\\\ \\hline \\hline";
char fin_documento []="\\end{longtable}\n\\thispagestyle{empty}\n\\end{landscape}\n\\end{document}";	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, "select * from Producto"))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	
//==========================================================================================================================================================		

		fichero = fopen("Producto.tex", "wt");
	fputs(cabeceras, fichero);
	while ((row = mysql_fetch_row(res)) != NULL) {
		fprintf(fichero,"%s & %s & %s & %s & %s & %s & %s & %s & %s \\\\ \\hline \n",row[0],row[1],row[2],row[3],row[4],row[7],row[9],row[10],row[11]);
	}
	fputs(fin_documento, fichero);
	fclose(fichero); 
	system("latexmk -pdf -synctex=1 Producto.tex ");
    system("xdg-open Producto.pdf &");
    //return ;
//==========================================================================================================================================================
	mysql_free_result(res);
	mysql_close(conn);
  

    gtk_label_set_text(lbl_info,"PDF Creado");
	gtk_revealer_set_reveal_child (GTK_REVEALER (info_bar),TRUE);
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

 while ((row = mysql_fetch_row(res)) != NULL) gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_usuarios),row[0]);
 
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
		gtk_stack_set_visible_child (GTK_STACK(stack_header),ety_producto_pos);
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
	
void calcula_cambio()
{
	double x,y,z;
	char dif[200];
	char dif2[200];
	const char 		*recibido = gtk_entry_get_text(ety_recibido);
	const char 		*total = gtk_label_get_text(lbl_totalpos);
	
	x = atof(total);
	y = atof(recibido);
	z = x-y;
	
	sprintf(dif,"%9.2f",z);
	sprintf(dif2,"%-f",z);
	gtk_label_set_text(ety_cambio,dif);
	if(total[0] == '0'){
			gtk_label_set_text(lbl_error,"No hay nada en el carrito de compra");
			gtk_entry_set_text(ety_recibido,"0.00");
			return gtk_widget_show(dialog_error_datos);
		}
	if((strcmp(dif,"     0.00") == 0) |(dif2[0] == '-'))
	{
		GdkColor color = {0, 255<<4, 255<<4 ,255<<4};
		gtk_widget_modify_fg (GTK_WIDGET(ety_cambio), GTK_STATE_NORMAL, &color);
		gtk_widget_set_sensitive(btn_venta,TRUE);
	}else
		{
			GdkColor color = {0, 255<<8, 20<<8 ,20<<8};
			gtk_widget_modify_fg (GTK_WIDGET(ety_cambio), GTK_STATE_NORMAL, &color);
			gtk_widget_set_sensitive(btn_venta,FALSE);
		}
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
void cierra_inventario(){
	gtk_widget_hide_on_delete(widget_inventario);
	}
void ver_total(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contrasena);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	if (mysql_query(conn, "select SUM(P_unitario) as Total from Carrito_compra"))
	{
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)gtk_label_set_text(lbl_totalpos,row[0]);

	mysql_free_result(res);
	mysql_close(conn);
	calcula_cambio();
}
void abre_inventario(){
		 gtk_widget_show(widget_inventario);
	}	
		
void anadir_productocarrito(){
	char anadir_pro[200];

	const char 		*sku = gtk_entry_get_text(ety_pos_producto);

	sprintf(anadir_pro,"insert into Carrito_compra(Producto,P_unitario) select  Nombre,Venta from Producto where SKU = '%s'",sku);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_pro))
	{
		gtk_label_set_text(lbl_error,"Producto no Encontrado");
		return gtk_widget_show(dialog_error_datos);
	}

	mysql_close(conn);
	refresca_pos();
	ver_carrito();
	ver_total();
	gtk_entry_set_text(ety_pos_producto,"");
}


void yoshiiiiii(){
	char anadir_pro[200];

	const char 		*sku = gtk_entry_get_text(ety_inve);

	sprintf(anadir_pro,"insert into Inventario_temp(SKU,Nombre,Piezas,Valor) select  SKU,Nombre,Piezas,Venta from Producto where SKU = '%s'",sku);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_pro))
	{
		gtk_label_set_text(lbl_error,"El Producto ya fue añadido");
		return gtk_widget_show(dialog_error_datos);
	}
	refresca_inve();
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) titulo_inventario();

	if (mysql_query(conn, "select * from Inventario_temp"))
	{
		gtk_label_set_text(lbl_error,"Producto no Encontrado");
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) titulo_inventario();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_entry_set_text(ety_inve,"");
}
void elimina_ticket(){	
	char consu[200];
	char consu2[200];
	char consu3[200];
	char consu4[200];
    gchar *id;

        if (gtk_tree_selection_get_selected (select1, &model2, &iter2))
        {
                gtk_tree_model_get (model2, &iter2, COLidfac, &id, -1);
                sprintf(consu,"select Query from Ticket where Id_ticket = %s",id);
                sprintf(consu3,"delete from Ticket where Id_ticket = %s",id);
					conn = mysql_init(NULL);
					if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
					{
						char tempErr[60];
						sprintf(tempErr,"%s", mysql_error(conn));
						gtk_label_set_text(lbl_error,tempErr);
						return gtk_widget_show(dialog_error_datos);	 
					}
					if (mysql_query(conn, consu ))
					{
					char tempErr[60];
					sprintf(tempErr,"%s", mysql_error(conn));
					gtk_label_set_text(lbl_error,tempErr);
					return gtk_widget_show(dialog_error_datos);
					}
					res = mysql_use_result(conn);
					while ((row = mysql_fetch_row(res)) != NULL){
					sprintf(consu2,"update Producto inner join `%s` on Producto.Nombre = `%s`.Producto set Producto.Piezas=Producto.Piezas+`%s`.No",row[0],row[0],row[0]);
					sprintf(consu4,"drop table %s",row[0]);
					}
					mysql_free_result(res);
					mysql_close(conn);
//===============================================================================================================================
					conn = mysql_init(NULL);
					if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
					{
						char tempErr[60];
					sprintf(tempErr,"%s", mysql_error(conn));
					gtk_label_set_text(lbl_error,tempErr);
					return gtk_widget_show(dialog_error_datos);
					}
					if (mysql_query(conn, consu2 ))
					{
						char tempErr[60];
					sprintf(tempErr,"%s", mysql_error(conn));
					gtk_label_set_text(lbl_error,tempErr);
					return gtk_widget_show(dialog_error_datos);
					}

					if (mysql_query(conn, consu3 ))
					{
					char tempErr[60];
					sprintf(tempErr,"%s", mysql_error(conn));
					gtk_label_set_text(lbl_error,tempErr);
					return gtk_widget_show(dialog_error_datos);
					}
					if (mysql_query(conn, consu4 ))
					{
					char tempErr[60];
					sprintf(tempErr,"%s", mysql_error(conn));
					gtk_label_set_text(lbl_error,tempErr);
					return gtk_widget_show(dialog_error_datos);
					}
					gtk_label_set_text(lbl_ticketcambio,"0.00");
					gtk_label_set_text(lbl_ticketrecibido,"0.00");
					gtk_label_set_text(lbl_tickettotal,"0.00");
					res = mysql_use_result(conn);
					refresca_datos_fac();
					refresca_datos_pro();
					contenido_ticket();
					contenido_producto();
        }	
	}
 void ingresa_venta(){
	GDateTime *date_time;
    gchar *dt_format;

    date_time = g_date_time_new_now_local();
    dt_format = g_date_time_format(date_time, "Ticket_%d%m%y%H%M%S");
	char anadir_pro[200];
	char anadir_pro2[200];
	char anadir_pro3[200];
	const char 		*recibido = gtk_entry_get_text(ety_recibido);
	const char 		*total = gtk_label_get_text(lbl_totalpos);
	const char 		*cambio = gtk_label_get_text(ety_cambio);
		
	
		if(total[0] == '0'){
			gtk_label_set_text(lbl_error,"No hay nada en el carrito de compra");
			gtk_entry_set_text(ety_recibido,"0.00");
			return gtk_widget_show(dialog_error_datos);
		}else{
	conn = mysql_init(NULL);
	
	sprintf(anadir_pro,"CREATE TABLE `%s` AS  (select Producto , P_unitario , count(Producto) as 'No', (P_unitario * count(Producto)) as SubTotal from Carrito_compra group by Producto)",dt_format);
	sprintf(anadir_pro2,"insert into Ticket (Usuario,Total,Recibido,Cambio,Query,Fecha_hora) values (USER(),'%s','%s','%s','%s',NOW())",total,recibido,cambio,dt_format);
	sprintf(anadir_pro3,"update Producto inner join `%s` on Producto.Nombre = `%s`.Producto set Producto.Piezas=Producto.Piezas-`%s`.No;",dt_format,dt_format,dt_format);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}
	if (mysql_query(conn, anadir_pro2))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	if (mysql_query(conn, anadir_pro))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
		if (mysql_query(conn,anadir_pro3 ))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	if (mysql_query(conn, "DELETE FROM Carrito_compra"))
	{

	}

		res = mysql_use_result(conn);
		refresca_datos_fac();
		while ((row = mysql_fetch_row(res)) != NULL);
		refresca_pos();
		refresca_datos_pro();
		ver_carrito();
		contenido_ticket();
		contenido_producto();
		contenido_aud_producto();
		gtk_entry_set_text(ety_recibido,"0.00");
		gtk_label_set_text(lbl_totalpos,"0.00");
		gtk_label_set_text(ety_cambio,"0.00");
		GdkColor color = {0, 255<<4, 255<<4 ,255<<4};
		gtk_widget_modify_fg (GTK_WIDGET(ety_cambio), GTK_STATE_NORMAL, &color);
		gtk_widget_set_sensitive(btn_venta,TRUE);
	}
}
void selection_buscar(gpointer data){
	  char consu[200];
	  gchar  *holi;
	  if (gtk_tree_selection_get_selected (select3, &model_busc, &iter_busqueda))
        {
                gtk_tree_model_get (model_busc, &iter_busqueda, COLproducto_pos, &holi, -1);
                sprintf(consu,"insert into Carrito_compra(Producto,P_unitario) select  Nombre,Venta from Producto where Nombre = '%s'",holi);
					conn = mysql_init(NULL);
					if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
					{
						char tempErr[60];
						sprintf(tempErr,"%s", mysql_error(conn));
						gtk_label_set_text(lbl_error,tempErr);
						return gtk_widget_show(dialog_error_datos);	 
					}
					if (mysql_query(conn, consu ))
					{
						char tempErr[60];
						sprintf(tempErr,"%s", mysql_error(conn));
						gtk_label_set_text(lbl_error,tempErr);
						return gtk_widget_show(dialog_error_datos);
					}
					//mysql_free_result(res);
					//res = mysql_use_result(conn);
			refresca_pos();
			ver_carrito();
			ver_total();
        }
gtk_tree_selection_unselect_all (select3);	
}


void tree_selection_changed_cb(GtkTreeSelection *selection, gpointer data){
	refresca_venta();
	char consu[200];
	char consu2[200];
	char consu3[200];
    gchar *id;

        if (gtk_tree_selection_get_selected (selection, &model2, &iter2))
        {
                gtk_tree_model_get (model2, &iter2, COLidfac, &id, -1);
                sprintf(consu,"select Query from Ticket where Id_ticket = %s",id);
                sprintf(consu3,"select Total,Recibido,Cambio from Ticket where Id_ticket = %s",id);
					conn = mysql_init(NULL);
					if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
					{
						char tempErr[60];
						sprintf(tempErr,"%s", mysql_error(conn));
						gtk_label_set_text(lbl_error,tempErr);
						return gtk_widget_show(dialog_error_datos);	 
					}
					if (mysql_query(conn, consu ))
					{
					char tempErr[60];
					sprintf(tempErr,"%s", mysql_error(conn));
					gtk_label_set_text(lbl_error,tempErr);
					return gtk_widget_show(dialog_error_datos);
					}
					res = mysql_use_result(conn);
					while ((row = mysql_fetch_row(res)) != NULL)sprintf(consu2,"select * from %s",row[0]);
					mysql_free_result(res);
					mysql_close(conn);
//===============================================================================================================================
					conn = mysql_init(NULL);
					if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
					{
					char tempErr[60];
					sprintf(tempErr,"%s", mysql_error(conn));
					gtk_label_set_text(lbl_error,tempErr);
					return gtk_widget_show(dialog_error_datos);	 
					}
					if (mysql_query(conn, consu2 ))
					{
					char tempErr[60];
					sprintf(tempErr,"%s", mysql_error(conn));
					gtk_label_set_text(lbl_error,tempErr);
					return gtk_widget_show(dialog_error_datos);
					}
					res = mysql_use_result(conn);
					while ((row = mysql_fetch_row(res)) != NULL)titulo_venta();

					if (mysql_query(conn, consu3 ))
					{
					char tempErr[60];
					sprintf(tempErr,"%s", mysql_error(conn));
					gtk_label_set_text(lbl_error,tempErr);
					return gtk_widget_show(dialog_error_datos);
					}
					res = mysql_use_result(conn);
					while ((row = mysql_fetch_row(res)) != NULL){
						gtk_label_set_text(lbl_tickettotal,row[0]);
						gtk_label_set_text(lbl_ticketrecibido,row[1]);
						gtk_label_set_text(lbl_ticketcambio,row[2]);
						}
					
					mysql_close(conn);
					g_free(id);
        }	
	}

void key_event(GtkWidget *widget,GdkEventKey *event, gpointer data){
	//g_printerr("%s\n\n",gdk_keyval_name (event->keyval));
	gchar *produc;
	char consu[200];
	if((strcmp(gdk_keyval_name (event->keyval),"minus") == 0 )|(strcmp(gdk_keyval_name (event->keyval),"KP_Subtract") == 0 )){
		if (gtk_tree_selection_get_selected (select2, &model_pos, &iter_pos)){
					gtk_tree_model_get (model_pos, &iter_pos,producto_pos, &produc, -1);
					sprintf(consu,"delete from Carrito_compra where Producto ='%s' limit 1",produc);
                
					conn = mysql_init(NULL);
					if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
					{
						char tempErr[60];
						sprintf(tempErr,"%s", mysql_error(conn));
						gtk_label_set_text(lbl_error,tempErr);
						gtk_widget_show(dialog_error_datos);	 
					}
					if (mysql_query(conn, consu ))
					{
						char tempErr[60];
						sprintf(tempErr,"%s", mysql_error(conn));
						gtk_label_set_text(lbl_error,tempErr);
						gtk_widget_show(dialog_error_datos);
					}
					res = mysql_use_result(conn);
					mysql_free_result(res);
					mysql_close(conn);					
					refresca_pos();
					ver_carrito();
					ver_total();
					g_free(produc);    
					}		
	}
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
		btn_inventario = GTK_BUTTON(gtk_builder_get_object(builder,"btn_inventario"));
		
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
		view_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"view_busqueda"));
		contenedor_view = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view"));
		contenedor_view2 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view2"));
		contenedor_view3 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view3"));
		contenedor_view4 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view4"));
		contenedor_view5 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view5"));
		contenedor_view6 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view6"));
		contenedor_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_busqueda"));
		contenedor_sql = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_sql"));
		stackgtk = GTK_WIDGET(gtk_builder_get_object(builder,"stack"));
		ety_cat = GTK_WIDGET(gtk_builder_get_object(builder,"ety_cat"));
		stack_actualiza2 = GTK_STACK(gtk_builder_get_object(builder,"stack_actualiza2"));
		stack_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"stack_busqueda"));
		stack_actualiza = GTK_WIDGET(gtk_builder_get_object(builder,"stack_actualiza"));
		exportar_pdf = GTK_WIDGET(gtk_builder_get_object(builder,"exportar_pdf"));
		muestra_func = GTK_WIDGET(gtk_builder_get_object(builder,"muestra_func"));
		reveal_consulta = GTK_WIDGET(gtk_builder_get_object(builder,"reveal_consulta"));
		btn_sql_aceptar = GTK_WIDGET(gtk_builder_get_object(builder,"btn_sql_aceptar"));
		btn_actualiza_emp = GTK_BUTTON(gtk_builder_get_object(builder,"btn_actualiza_emp"));
		ocultar_btn = GTK_WIDGET(gtk_builder_get_object(builder,"ocultar_btn"));
		box_act_pro = GTK_WIDGET(gtk_builder_get_object(builder,"box_act_pro"));
		win_acercade = GTK_WIDGET(gtk_builder_get_object(builder,"acercade"));
		switchgtk = GTK_WIDGET(gtk_builder_get_object(builder,"activador_sql"));
		source_code = GTK_WIDGET(gtk_builder_get_object(builder,"Codigo_sql"));
		lbl_anadir_advertencia = GTK_LABEL(gtk_builder_get_object(builder,"lbl_anadir_advertencia"));
		lbl_eliminar_advertencia = GTK_LABEL(gtk_builder_get_object(builder,"lbl_eliminar_advertencia"));
		lbl_info = GTK_LABEL(gtk_builder_get_object(builder,"lbl_info"));
		lbl_user_bien = GTK_LABEL(gtk_builder_get_object(builder,"lbl_user_bien"));
		lbl_usuario = GTK_LABEL(gtk_builder_get_object(builder,"lbl_usuario"));
		advertencia_anadir_fac = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_anadir_fac"));
		advertencia_anadir_emp = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_anadir_emp"));
		advertencia_anadir_pro = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_anadir_pro"));
		advertencia_actualizar_emp = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_actualizar_emp"));
		advertencia_actualizar_pro = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_actualizar_pro"));
		advertencia_eliminar_fac = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_eliminar_fac"));
		advertencia_eliminar_pro = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_eliminar_pro"));
		advertencia_eliminar_emp = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_eliminar_emp"));
		swchitcher = GTK_WIDGET(gtk_builder_get_object(builder,"swchitcher"));
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
		cont_view_bus = GTK_WIDGET(gtk_builder_get_object(builder,"cont_view_bus"));
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
		lbl_totalpos = GTK_LABEL(gtk_builder_get_object(builder,"lbl_totalpos"));
	
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
		ety_inve = GTK_ENTRY(gtk_builder_get_object(builder,"ety_inve"));
				
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
		ety_pos_producto = GTK_ENTRY(gtk_builder_get_object(builder,"ety_pos_producto"));
		
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
		
		ety_recibido = GTK_ENTRY(gtk_builder_get_object(builder,"ety_recibido"));
		ety_cambio = GTK_LABEL(gtk_builder_get_object(builder,"ety_cambio"));
		lbl_tickettotal = GTK_LABEL(gtk_builder_get_object(builder,"lbl_tickettotal"));
		lbl_ticketrecibido  = GTK_LABEL(gtk_builder_get_object(builder,"lbl_ticketrecibido"));
		lbl_ticketcambio  = GTK_LABEL(gtk_builder_get_object(builder,"lbl_ticketcambio"));
		
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
		btn_act = GTK_WIDGET(gtk_builder_get_object(builder,"btn_act"));
		btn_borrar_pro = GTK_WIDGET(gtk_builder_get_object(builder,"btn_borrar_pro"));
		btn_venta = GTK_WIDGET(gtk_builder_get_object(builder,"btn_venta"));
		
		cb_dia_proact2 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_proact2"));
		cb_mes_proact2 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_proact2"));
		cb_anio_proact2 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_proact2"));
		cb_marcapro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_marcapro"));
		btn_cancelar_adver3 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver3"));
		cancela_and_factura3= GTK_WIDGET(gtk_builder_get_object(builder,"cancela_and_factura3"));
		ety_producto_pos = GTK_WIDGET(gtk_builder_get_object(builder,"ety_producto_pos"));
		
		stack_pop_producto = GTK_WIDGET(gtk_builder_get_object(builder,"stack_pop_producto"));
		lbl_nodatos = GTK_WIDGET(gtk_builder_get_object(builder,"lbl_nodatos"));
		revel_bucar = GTK_WIDGET(gtk_builder_get_object(builder,"revel_bucar"));
		treeview_pos = GTK_WIDGET(gtk_builder_get_object(builder,"treeview_pos"));
		inserta_datos_empresa = GTK_WIDGET(gtk_builder_get_object(builder,"inserta_datos_empresa"));
		btn_cancelar_stp = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_stp"));
		pag_atras = GTK_WIDGET(gtk_builder_get_object(builder,"pag_atras"));
		pag_sig = GTK_WIDGET(gtk_builder_get_object(builder,"pag_sig"));
		acerca_de  = GTK_WIDGET(gtk_builder_get_object(builder,"acerca_de"));
		stack_menu_pos = GTK_STACK(gtk_builder_get_object(builder,"stack_menu_pos"));
		child_sku = GTK_WIDGET(gtk_builder_get_object(builder,"child_sku"));
		spin_compra = GTK_WIDGET(gtk_builder_get_object(builder,"spin_compra"));
		spin_piezas = GTK_WIDGET(gtk_builder_get_object(builder,"spin_piezas"));
		spin_venta = GTK_WIDGET(gtk_builder_get_object(builder,"spin_venta"));
		btn_aceptar_a2 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_aceptar_a2"));
		cancela_and_factura2 = GTK_WIDGET(gtk_builder_get_object(builder,"cancela_and_factura2"));
		pop_busqueda_pos = GTK_WIDGET(gtk_builder_get_object(builder,"pop_busqueda_pos"));
		btn_servicios = GTK_WIDGET(gtk_builder_get_object(builder,"btn_servicios"));
		btn_borrar_emp = GTK_WIDGET(gtk_builder_get_object(builder,"btn_borrar_emp"));
		btn_consulta_emp = GTK_WIDGET(gtk_builder_get_object(builder,"btn_consulta_emp"));
		cb_usuarios = GTK_WIDGET(gtk_builder_get_object(builder,"cb_usuarios"));
		view_venta = GTK_WIDGET(gtk_builder_get_object(builder,"view_venta"));
		view_inventario = GTK_WIDGET(gtk_builder_get_object(builder,"view_inventario"));
		widget_inventario = GTK_WIDGET(gtk_builder_get_object(builder,"widget_inventario")); 
		btn_proveedorpdf = GTK_BUTTON(gtk_builder_get_object(builder,"btn_proveedorpdf"));
		btn_exportaproductopdf = GTK_BUTTON(gtk_builder_get_object(builder,"btn_exportaproductopdf"));
		btn_eliminaticket = GTK_BUTTON(gtk_builder_get_object(builder,"btn_eliminaticket"));
		
		btn_cancelar_adver8 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver8"));
		btn_cancelar_adver2 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver2"));
		btn_cancelar_adver9 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver9"));
		btn_cancelar_adver7 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver7"));
		btn_cancelar_adver5 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver5"));
		btn_cancelar_adver1 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver1"));
		btn_cancelar_adver4 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver4"));
		btn_cancelar_adver6 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver6"));
				
		for(i=2051;i>=1950;i--){ 
			sprintf(anio,"%d",i);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_pro),anio);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_propro),anio);
		}
		select1 = gtk_tree_view_get_selection (GTK_TREE_VIEW (view2));
		gtk_tree_selection_set_mode (select1, GTK_SELECTION_SINGLE);		
		select2 = gtk_tree_view_get_selection (GTK_TREE_VIEW (treeview_pos));
		gtk_tree_selection_set_mode (select2, GTK_SELECTION_SINGLE);		
		select3 = gtk_tree_view_get_selection (GTK_TREE_VIEW (view_busqueda));
		gtk_tree_selection_set_mode (select3, GTK_SELECTION_SINGLE);
		
		
		g_signal_connect(G_OBJECT(btn_cancelar_adver9),"clicked",G_CALLBACK(on_btn_cancelar_adver9_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver8),"clicked",G_CALLBACK(on_btn_cancelar_adver8_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver7),"clicked",G_CALLBACK(on_btn_cancelar_adver7_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver5),"clicked",G_CALLBACK(on_btn_cancelar_adver5_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver4),"clicked",G_CALLBACK(on_btn_cancelar_adver4_clicked),NULL);

		g_signal_connect(G_OBJECT(btn_Sesion),"clicked",G_CALLBACK(on_btn_Sesion_clicked),NULL);
		g_signal_connect(G_OBJECT(g_Entry_Contrasena),"activate",G_CALLBACK(on_Entry_Contrasena_activate),NULL);
		g_signal_connect(G_OBJECT(g_Dialog_Error),"delete-event",G_CALLBACK(cierra_error),NULL);
		g_signal_connect(G_OBJECT(advertencia_actualizar_emp),"delete-event",G_CALLBACK(cierra_act),NULL);
		g_signal_connect(G_OBJECT(advertencia_anadir_emp),"delete-event",G_CALLBACK(cierra_emp),NULL);
		g_signal_connect(G_OBJECT(advertencia_anadir_pro),"delete-event",G_CALLBACK(cierra_pro),NULL);
		g_signal_connect(G_OBJECT(advertencia_eliminar_emp),"delete-event",G_CALLBACK(cierra_emp_eli),NULL);
		g_signal_connect(G_OBJECT(advertencia_eliminar_pro),"delete-event",G_CALLBACK(cierra_pro_eli),NULL);
		g_signal_connect(G_OBJECT(dialog_error_datos),"delete-event",G_CALLBACK(cierra_error_datos),NULL);
		g_signal_connect(G_OBJECT(window_login),"delete-event",G_CALLBACK(on_Window_BD_destroy),NULL);
		g_signal_connect(G_OBJECT(window_BD),"delete-event",G_CALLBACK(on_Window_BD_destroy),NULL);
		g_signal_connect(G_OBJECT(widget_inventario),"delete-event",G_CALLBACK(cierra_inventario),NULL);
		g_signal_connect(G_OBJECT(btn_Rein_Dial),"clicked",G_CALLBACK(on_btn_Rein_Dial_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver3),"clicked",G_CALLBACK(on_btn_cancelar_adver3_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cancelar_adver6),"clicked",G_CALLBACK(on_btn_cancelar_adver6_clicked),NULL);
		g_signal_connect(G_OBJECT(inserta_datos_empresa),"clicked",G_CALLBACK(on_inserta_datos_empresa_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_consulta_emp),"clicked",G_CALLBACK(on_btn_consulta_emp_clicked),NULL);
		g_signal_connect(G_OBJECT(emp_aceptar_anadir),"clicked",G_CALLBACK(on_emp_aceptar_anadir_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_aceptar_1),"clicked",G_CALLBACK(on_btn_aceptar_1_clicked),NULL);
		g_signal_connect(G_OBJECT(cancela_and_factura3),"clicked",G_CALLBACK(on_cancela_and_factura3_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_cambiar_usuario),"clicked",G_CALLBACK(on_btn_cambiar_usuario_clicked),NULL);
		g_signal_connect(G_OBJECT(actualiza_datos_empresa),"clicked",G_CALLBACK(on_actualiza_datos_empresa_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_borrar_emp),"clicked",G_CALLBACK(on_btn_borrar_emp_clicked),NULL);		
		g_signal_connect(G_OBJECT(btn_cancelar_stp),"clicked",G_CALLBACK(cerrar_setup),NULL);
		g_signal_connect(G_OBJECT(pag_sig),"clicked",G_CALLBACK(siguiente),NULL);
		g_signal_connect(G_OBJECT(pag_atras),"clicked",G_CALLBACK(atras),NULL);		
		g_signal_connect(G_OBJECT(btn_eliminaticket),"clicked",G_CALLBACK(elimina_ticket),NULL);			
		g_signal_connect(G_OBJECT(btn_servicios),"clicked",G_CALLBACK(pagar_servicios),NULL);
		g_signal_connect(G_OBJECT(ety_user_bien),"changed",G_CALLBACK(consigue_datos),NULL);
		g_signal_connect(G_OBJECT(ety_dir_bien),"changed",G_CALLBACK(consigue_datos2),NULL);
		g_signal_connect(G_OBJECT(ety_rfc_bien),"changed",G_CALLBACK(consigue_datos3),NULL);
		g_signal_connect(G_OBJECT(bar),"response",G_CALLBACK(on_info_close),NULL);
		g_signal_connect(G_OBJECT(bar_bien),"response",G_CALLBACK(on_info_close2),NULL);
		g_signal_connect(G_OBJECT(win_acercade),"delete-event",G_CALLBACK(on_acercade_response),NULL);
		g_signal_connect(G_OBJECT(win_acercade),"response",G_CALLBACK(on_acercade_response),NULL);
		g_signal_connect(G_OBJECT(btn_buscar_pos),"toggled",G_CALLBACK(abre_busca),NULL);
		g_signal_connect(G_OBJECT(btn_consulta_pos),"toggled",G_CALLBACK(consulta_pos),NULL);
		g_signal_connect(G_OBJECT(btn_edit_proveedor),"toggled",G_CALLBACK(modifica_proveedor),NULL);
		g_signal_connect(G_OBJECT(btn_edit_productos),"toggled",G_CALLBACK(modifica_productos),NULL);
		g_signal_connect(G_OBJECT(acerca_de),"clicked",G_CALLBACK(on_acercade_clicked),NULL);		
		g_signal_connect(G_OBJECT(btn_menu_pref),"clicked",G_CALLBACK(abre_preferencias),NULL);
		g_signal_connect(G_OBJECT(btn_proveedorpdf),"clicked",G_CALLBACK(genera_pdfproveedor),NULL);
		g_signal_connect(G_OBJECT(btn_menu_pref_devol),"clicked",G_CALLBACK(regresa_menu),NULL);		
		g_signal_connect(G_OBJECT(ety_produ_emp),"activate",G_CALLBACK(on_btn_consulta_emp_clicked),NULL);
		g_signal_connect(G_OBJECT(ety_cbarra),"focus-in-event",G_CALLBACK(show_gensku),NULL);
		g_signal_connect(G_OBJECT(ety_cbarra),"activate",G_CALLBACK(consulta_producto),NULL);
		g_signal_connect(G_OBJECT(ety_inve),"activate",G_CALLBACK(yoshiiiiii),NULL);
		g_signal_connect(G_OBJECT(ety_pos_producto),"activate",G_CALLBACK(anadir_productocarrito),NULL);
		g_signal_connect(G_OBJECT(ety_recibido),"changed",G_CALLBACK(calcula_cambio),NULL);
		
		g_signal_connect(G_OBJECT(ety_cbarra),"focus-out-event",G_CALLBACK(hide_gensku),NULL);
		g_signal_connect(G_OBJECT(child_sku),"clicked",G_CALLBACK(show_gensku_child),NULL);
		g_signal_connect(G_OBJECT(btn_actualiza_emp),"clicked",G_CALLBACK(on_btn_actualiza_emp_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_aceptar_a1),"clicked",G_CALLBACK(on_btn_aceptar_a1_clicked),NULL);
		g_signal_connect(G_OBJECT(cancela_and_factura2),"clicked",G_CALLBACK(on_cancela_and_factura2_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_borrar_pro),"clicked",G_CALLBACK(on_btn_borrar_pro_clicked),NULL);		
		
		g_signal_connect(G_OBJECT(cb_cat),"changed",G_CALLBACK(cambia_categoria),NULL);
		g_signal_connect(G_OBJECT(cb_bs_cat),"changed",G_CALLBACK(cambia_bs_categoria),NULL);
		g_signal_connect(G_OBJECT(ety_busca_proveedor),"changed",G_CALLBACK(busca_proveedor),NULL);
		g_signal_connect(G_OBJECT(ety_producto_pos),"changed",G_CALLBACK(busca_producto_pos),NULL);
		
		g_signal_connect(G_OBJECT(cb_busca_estado),"changed",G_CALLBACK(busca_proveedor),NULL);
		g_signal_connect(G_OBJECT(inserta_datos_productos),"clicked",G_CALLBACK(on_inserta_datos_empres_clicked),NULL);
		g_signal_connect(G_OBJECT(pro_aceptar_anadir),"clicked",G_CALLBACK(on_pro_aceptar_anadir_clicked),NULL);
		g_signal_connect(G_OBJECT(ety_busca_producto),"changed",G_CALLBACK(busca_producto),NULL);
		g_signal_connect(G_OBJECT(btn_aceptar_a2),"clicked",G_CALLBACK(on_btn_aceptar_a2_clicked),NULL);
		
		g_signal_connect(G_OBJECT(ety_busca_proveedor_producto),"changed",G_CALLBACK(busca_producto),NULL);
		g_signal_connect(G_OBJECT(ety_busca_categoria),"changed",G_CALLBACK(busca_producto),NULL);
		g_signal_connect(G_OBJECT(ety_busca_subcategoria),"changed",G_CALLBACK(busca_producto),NULL);
		
		g_signal_connect(G_OBJECT(ety_busca_proveedor_producto),"icon-press",G_CALLBACK(borra_busqueda1),NULL);
		g_signal_connect(G_OBJECT(ety_busca_categoria),"icon-press",G_CALLBACK(borra_busqueda2),NULL);
		g_signal_connect(G_OBJECT(ety_busca_subcategoria),"icon-press",G_CALLBACK(borra_busqueda3),NULL);
		
		g_signal_connect(G_OBJECT(btn_4cb),"clicked",G_CALLBACK(cucb),NULL);
		g_signal_connect(G_OBJECT(btn_8cb),"clicked",G_CALLBACK(occb),NULL);
		g_signal_connect(G_OBJECT(btn_13cb),"clicked",G_CALLBACK(trecb),NULL);		
		g_signal_connect(G_OBJECT(btn_act),"clicked",G_CALLBACK(on_inserta_datos_empres_clicked),NULL);
		g_signal_connect(G_OBJECT(btn_venta),"clicked",G_CALLBACK(ingresa_venta),NULL);
		g_signal_connect(G_OBJECT(btn_exportaproductopdf),"clicked",G_CALLBACK(pdf_producto),NULL);
		g_signal_connect(G_OBJECT(btn_inventario),"clicked",G_CALLBACK(abre_inventario),NULL);
		g_signal_connect(G_OBJECT(select1),"changed",G_CALLBACK(tree_selection_changed_cb),NULL);
		g_signal_connect(G_OBJECT(select3),"changed",G_CALLBACK(selection_buscar),NULL);
		g_signal_connect(treeview_pos, "key-release-event", G_CALLBACK(key_event), NULL);
			
		
		GdkColor color = {0, 255<<8, 255<<8 ,255<<8};
		gtk_widget_modify_bg (GTK_WIDGET(g_Entry_Usuario), GTK_STATE_NORMAL, &color);
		gtk_widget_modify_bg (GTK_WIDGET(g_Entry_Contrasena), GTK_STATE_NORMAL, &color);
		
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

    date_time = g_date_time_new_now_local();             
    dt_format = g_date_time_format(date_time, "%d/%m/%y %H:%M:%S");       
    gtk_label_set_text(lbl_hora, dt_format);  
    g_free (dt_format);
    
    return TRUE;
}
