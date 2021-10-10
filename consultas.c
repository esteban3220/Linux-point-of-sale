#include <stdio.h>
#include "pdf.c"

void ver_carrito()
{

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }
        if (mysql_query(conn, "select Producto , P_unitario , count(Producto) as 'No', (P_unitario * count(Producto)) as SubTotal from Carrito_compra group by Producto"))
        {
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
                titulo_POS();

        mysql_free_result(res);
        mysql_close(conn);
}

void on_acercade_clicked()
{
        gtk_widget_show(win_acercade);
}

void on_acercade_response()
{
        gtk_widget_hide_on_delete(win_acercade);
}
void on_btn_Sesion_clicked()
{
        gtk_stack_set_visible_child(GTK_STACK(stack_login), spinner_login);
        conectar();
        contenido_tablas();
        contenido_producto();
        contenido_aud_proveedor();
        contenido_aud_producto();
        contenido_ticket();
        contenido_aud_ticket();
        contenido_inventario_alt();
        ver_carrito();
        gtk_stack_set_visible_child(GTK_STACK(stack_login), img_conect);
}

void on_Entry_Contrasena_activate()
{
        on_btn_Sesion_clicked();
}

void on_btn_cancelar_adver3_clicked()
{
        gtk_widget_hide(g_Dialog_Error);
        gtk_stack_set_visible_child(GTK_STACK(stack_login), img_conect);
}
void cierra_error()
{
        gtk_widget_hide_on_delete(g_Dialog_Error);
}

void on_btn_Rein_Dial_clicked()
{
        gtk_entry_set_text(g_Entry_Usuario, "");
        gtk_entry_set_text(g_Entry_Contrasena, "");
        gtk_widget_hide_on_delete(g_Dialog_Error);
}

void on_cancela_and_factura4_clicked()
{
        gtk_widget_hide(inserta_producto);
}
void reset()
{
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_dia_propro4), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_mes_propro4), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_anio_propro4), 0);
}
void on_cancela_and_factura2_clicked()
{
        gtk_stack_set_visible_child(GTK_STACK(stack_actualiza2), inserta_datos_productos);
        gtk_entry_set_text(ety_cbarra, "");
        gtk_entry_set_text(ety_nombrepro, "");
        gtk_entry_set_text(ety_marcapro, "");
        gtk_entry_set_text(ety_cneto, "");
        gtk_entry_set_text(ety_nlote, "");
        gtk_entry_set_text(GTK_ENTRY(spin_piezas), "0");
        gtk_entry_set_text(GTK_ENTRY(spin_compra), "0.00");
        gtk_entry_set_text(GTK_ENTRY(spin_venta), "0.00");
        gtk_entry_set_text(GTK_ENTRY(ety_cat), "");
        gtk_entry_set_text(GTK_ENTRY(entry_subcat), "");
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_dia_pro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_mes_pro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_anio_pro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_dia_propro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_mes_propro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_anio_propro), 0);
}
void on_btn_cancelar_adver_clicked()
{
        gtk_widget_hide(advertencia_anadir_fac);
}
void on_cancela_and_factura_clicked()
{
        gtk_widget_hide_on_delete(inserta_factura);
}

void on_btn_cambiar_usuario_clicked()
{
        gtk_entry_set_text(g_Entry_Usuario, "");
        gtk_entry_set_text(g_Entry_Contrasena, "");
        gtk_widget_hide_on_delete(window_BD);
        gtk_widget_show(window_login);
        gtk_widget_hide_on_delete(g_Dialog_Error);
        gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_productos_proveedor));
        refresca_busquedapos();
        refresca_datos_emp();
        refresca_datos_fac();
        refresca_datos_pro();
        refresca_pos();
}
void on_inserta_datos_factura_clicked()
{
        gtk_widget_show(advertencia_anadir_fac);
}
void on_inserta_datos_empresa_clicked()
{
        gtk_widget_show(advertencia_anadir_emp);
}

void on_emp_aceptar_anadir_clicked()
{
        user = gtk_entry_get_text(g_Entry_Usuario);
        password = gtk_entry_get_text(g_Entry_Contrasena);
        char anadir_emp[512];

        const char *id_prodi = gtk_entry_get_text(ety_produ_emp);
        const char *id_nom_emp = gtk_entry_get_text(ety_nombreemp);
        const char *direccion = gtk_entry_get_text(ety_direccion);
        const char *telefono = gtk_entry_get_text(ety_telefono);
        const char *region = gtk_entry_get_text(ety_region);
        const char *pais = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_pais_emp));
        const char *rfc_emp = gtk_entry_get_text(ety_rfc);
        const char *estado = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_estado_emp));
        const char *correo = gtk_entry_get_text(ety_correoemp);

        sprintf(anadir_emp, "insert into Proveedor values('%s' , '%s', '%s' , '%s', '%s' , '%s' , '%s' , '%s' , '%s' )", id_prodi, id_nom_emp, direccion, telefono, region, pais, rfc_emp, estado, correo);

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, anadir_emp))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                gtk_widget_hide(advertencia_anadir_fac);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                printf("%s", row[0]);
        }

        gtk_entry_set_text(ety_produ_emp, "");
        gtk_entry_set_text(ety_nombreemp, "");
        gtk_entry_set_text(ety_direccion, "");
        gtk_entry_set_text(ety_telefono, "");
        gtk_entry_set_text(ety_region, "");
        gtk_entry_set_text(ety_pais_emp, "");
        gtk_entry_set_text(ety_estado_emp, "");
        gtk_entry_set_text(ety_rfc, "");
        gtk_entry_set_text(ety_correoemp, "");

        refresca_datos_emp();
        contenido_tablas();
        contenido_aud_proveedor();

        gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_marcapro));
        gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_productos_proveedor));
        consulta_proveedor();
        gtk_widget_hide(advertencia_anadir_emp);
        gtk_label_set_text(lbl_info, "Proveedor Insertado Exitosamente");
        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar), TRUE);
}

void on_btn_cancelar_adver6_clicked()
{
        gtk_widget_hide(advertencia_anadir_emp);
}
void on_btn_cancelar_adver7_clicked()
{
        gtk_widget_hide(advertencia_anadir_pro);
}
void on_inserta_datos_empres_clicked()
{
        gtk_widget_show(advertencia_anadir_pro);
}
void on_pro_aceptar_anadir_clicked()
{
        user = gtk_entry_get_text(g_Entry_Usuario);
        password = gtk_entry_get_text(g_Entry_Contrasena);
        char anadir_fac[1024];
        char date[12];
        char date2[12];

        const char *dia = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_dia_pro));
        const char *mes = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_mes_pro));
        const char *anio = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_anio_pro));

        const char *dia2 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_dia_propro));
        const char *mes2 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_mes_propro));
        const char *anio2 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_anio_propro));

        const char *cbarra = gtk_entry_get_text(ety_cbarra);
        const char *nombre = gtk_entry_get_text(ety_nombrepro);
        const char *marca = gtk_entry_get_text(ety_marcapro);
        const char *nlote = gtk_entry_get_text(ety_nlote);
        const char *cneto = gtk_entry_get_text(ety_cneto);
        const char *piezas = gtk_entry_get_text(GTK_ENTRY(spin_piezas));
        const char *compra = gtk_entry_get_text(GTK_ENTRY(spin_compra));
        const char *venta = gtk_entry_get_text(GTK_ENTRY(spin_venta));
        const char *categoria = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_cat));
        const char *subcat = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_subcat));

        sprintf(date, "%s-%s-%s", anio, mes, dia);
        sprintf(date2, "%s-%s-%s", anio2, mes2, dia2);
        sprintf(anadir_fac, "insert into Producto values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s') ON DUPLICATE KEY UPDATE Nombre='%s',Marca='%s',Fecha_proc='%s', Fecha_cad='%s', Numero_lote='%s', Nota='%s', Piezas=Piezas+%s , Compra='%s', Venta='%s', Categoria='%s', Subcategoria='%s'", cbarra, nombre, marca, date, date2, nlote, cneto, piezas, compra, venta, categoria, subcat, nombre, marca, date, date2, nlote, cneto, piezas, compra, venta, categoria, subcat);
        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, anadir_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                gtk_widget_hide(advertencia_anadir_fac);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                printf("%s", row[0]);
        }

        gtk_entry_set_text(ety_cbarra, "");
        gtk_entry_set_text(ety_nombrepro, "");
        gtk_entry_set_text(ety_marcapro, "");
        gtk_entry_set_text(ety_cneto, "");
        gtk_entry_set_text(ety_nlote, "");
        gtk_entry_set_text(GTK_ENTRY(spin_piezas), "0");
        gtk_entry_set_text(GTK_ENTRY(spin_compra), "0.00");
        gtk_entry_set_text(GTK_ENTRY(spin_venta), "0.00");
        gtk_entry_set_text(GTK_ENTRY(ety_cat), "");
        gtk_entry_set_text(GTK_ENTRY(entry_subcat), "");
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_dia_pro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_mes_pro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_anio_pro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_dia_propro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_mes_propro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_anio_propro), 0);

        refresca_datos_pro();
        contenido_producto();
        contenido_aud_producto();
        gtk_widget_hide(advertencia_anadir_pro);
        gtk_label_set_text(lbl_info, "Producto Insertado Exitosamente");
        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar), TRUE);
}
//================================================

void on_btn_aceptar_1_clicked()
{
        gtk_widget_hide(dialog_error_datos);
}
//=========== Actualiza datos ====================================

void on_cancela_and_factura3_clicked()
{
        gtk_stack_set_visible_child(GTK_STACK(stack_actualiza), inserta_datos_empresa);
        gtk_entry_set_text(ety_nombreemp, "");
        gtk_entry_set_text(ety_direccion, "");
        gtk_entry_set_text(ety_telefono, "");
        gtk_entry_set_text(ety_region, "");
        gtk_entry_set_text(ety_pais_emp, "");
        gtk_entry_set_text(ety_rfc, "");
        gtk_entry_set_text(ety_estado_emp, "");
        gtk_entry_set_text(ety_correoemp, "");
}
void on_actualiza_datos_empresa_clicked()
{
        gtk_widget_show(advertencia_actualizar_emp);
}
void on_btn_cancelar_adver4_clicked()
{
        gtk_widget_hide(advertencia_actualizar_emp);
}
void on_btn_actualiza_emp_clicked()
{
        user = gtk_entry_get_text(g_Entry_Usuario);
        password = gtk_entry_get_text(g_Entry_Contrasena);
        char anadir_fac[512];

        const char *proveedor_emp = gtk_entry_get_text(ety_produ_emp);
        const char *nombre2 = gtk_entry_get_text(ety_nombreemp);
        const char *direccion = gtk_entry_get_text(ety_direccion);
        const char *telefono = gtk_entry_get_text(ety_telefono);
        const char *region = gtk_entry_get_text(ety_region);
        const char *pais = gtk_entry_get_text(ety_pais_emp);
        const char *rfc_emp = gtk_entry_get_text(ety_rfc);
        const char *estado = gtk_entry_get_text(ety_estado_emp);
        const char *correo = gtk_entry_get_text(ety_correoemp);

        sprintf(anadir_fac, "update Proveedor set Nombre='%s', Direccion='%s', Telefono=%s, Region='%s', Pais='%s' ,Rfc='%s', Estado='%s',Correo='%s' where Empresa=  '%s'", nombre2, direccion, telefono, region, pais, rfc_emp, estado, correo, proveedor_emp);

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, anadir_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                gtk_widget_hide(advertencia_anadir_emp);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
        }

        gtk_entry_set_text(ety_nombreemp, "");
        gtk_entry_set_text(ety_direccion, "");
        gtk_entry_set_text(ety_telefono, "");
        gtk_entry_set_text(ety_region, "");
        gtk_entry_set_text(ety_pais_emp, "");
        gtk_entry_set_text(ety_rfc, "");
        gtk_entry_set_text(ety_estado_emp, "");
        gtk_entry_set_text(ety_correoemp, "");

        mysql_free_result(res);
        mysql_close(conn);
        gtk_widget_hide(advertencia_actualizar_emp);

        gtk_label_set_text(lbl_info, "Provedor Actualizado Exitosamente");
        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar), TRUE);
        gtk_stack_set_visible_child(GTK_STACK(stack_actualiza), inserta_datos_empresa);
        refresca_datos_emp();
        contenido_aud_proveedor();
        contenido_tablas();
}

void on_actualiza_datos_producto_clicked()
{
        gtk_widget_show(advertencia_actualizar_pro);
}
void on_btn_cancelar_adver5_clicked()
{
        gtk_widget_hide(advertencia_actualizar_pro);
}
//=========== Elimina datos =====================================
void on_btn_borrar_emp_clicked()
{
        gtk_widget_show(advertencia_eliminar_emp);
}
void on_btn_cancelar_adver8_clicked()
{
        gtk_widget_hide(advertencia_eliminar_emp);
}
void on_btn_cancelar_adver9_clicked()
{
        gtk_widget_hide(advertencia_eliminar_pro);
}
void on_btn_aceptar_a1_clicked()
{
        user = gtk_entry_get_text(g_Entry_Usuario);
        password = gtk_entry_get_text(g_Entry_Contrasena);
        char elimina_fac[50];

        const char *id = gtk_entry_get_text(ety_produ_emp);

        sprintf(elimina_fac, "delete from Proveedor where Empresa='%s'", id);

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, elimina_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                gtk_widget_hide(advertencia_eliminar_emp);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                //printf("%s",row[0]);
        }
        gtk_entry_set_text(ety_produ_emp, "");
        gtk_entry_set_text(ety_nombreemp, "");
        gtk_entry_set_text(ety_direccion, "");
        gtk_entry_set_text(ety_telefono, "");
        gtk_entry_set_text(ety_region, "");
        gtk_entry_set_text(ety_pais_emp, "");
        gtk_entry_set_text(ety_rfc, "");
        gtk_entry_set_text(ety_estado_emp, "");
        gtk_entry_set_text(ety_correoemp, "");
        gtk_entry_set_text(ety_marcapro, "");

        refresca_datos_pro();
        refresca_datos_emp();
        gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_marcapro));
        gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_productos_proveedor));
        mysql_free_result(res);
        mysql_close(conn);
        gtk_widget_hide(advertencia_eliminar_emp);
        gtk_label_set_text(lbl_info, "Proveedor Eliminado Exitosamente");
        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar), TRUE);
        contenido_tablas();
        contenido_producto();
        consulta_proveedor();
        contenido_aud_proveedor();
        gtk_stack_set_visible_child(GTK_STACK(stack_actualiza), inserta_datos_empresa);
}
void on_btn_borrar_pro_clicked()
{
        gtk_widget_show(advertencia_eliminar_pro);
}
void on_btn_aceptar_a2_clicked()
{
        user = gtk_entry_get_text(g_Entry_Usuario);
        password = gtk_entry_get_text(g_Entry_Contrasena);
        char elimina_fac[50];

        const char *id = gtk_entry_get_text(ety_cbarra);

        sprintf(elimina_fac, "delete from Producto where SKU=%s", id);

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, elimina_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                gtk_widget_hide(advertencia_eliminar_pro);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                //printf("%s",row[0]);
        }

        gtk_entry_set_text(ety_cbarra, "");
        gtk_entry_set_text(ety_nombrepro, "");
        gtk_entry_set_text(ety_marcapro, "");
        gtk_entry_set_text(ety_cneto, "");
        gtk_entry_set_text(ety_nlote, "");
        gtk_entry_set_text(GTK_ENTRY(spin_piezas), "0");
        gtk_entry_set_text(GTK_ENTRY(spin_compra), "0.00");
        gtk_entry_set_text(GTK_ENTRY(spin_venta), "0.00");
        gtk_entry_set_text(GTK_ENTRY(ety_cat), "");
        gtk_entry_set_text(GTK_ENTRY(entry_subcat), "");
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_dia_pro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_mes_pro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_anio_pro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_dia_propro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_mes_propro), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(cb_anio_propro), 0);

        gtk_stack_set_visible_child(GTK_STACK(stack_actualiza2), inserta_datos_productos);

        mysql_free_result(res);
        mysql_close(conn);
        gtk_widget_hide(advertencia_eliminar_pro);
        gtk_label_set_text(lbl_info, "Producto Eliminado Exitosamente");
        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar), TRUE);
        refresca_datos_pro();
        contenido_producto();
        contenido_aud_producto();
}

//================================================
void on_Window_BD_destroy()
{
        const char *total = gtk_label_get_text(lbl_totalpos);
        if ((strcmp(total, "0.00") == 0) | (strcmp(total, "") == 0))
        {
                gtk_main_quit();
        }
        else
        {
                gtk_label_set_text(lbl_error, "La venta no se a concluido");
                gtk_widget_show(dialog_error_datos);
        }
}
void on_btn_cerrar_acd_clicked()
{
        gtk_widget_hide(win_acercade);
}

void cierra_emp()
{
        gtk_widget_hide_on_delete(advertencia_anadir_emp);
}
void cierra_emp_eli()
{
        gtk_widget_hide_on_delete(advertencia_eliminar_emp);
}
void cierra_pro()
{
        gtk_widget_hide_on_delete(advertencia_anadir_pro);
}
void cierra_pro_eli()
{
        gtk_widget_hide_on_delete(advertencia_eliminar_pro);
}
void cierra_error_datos()
{
        gtk_widget_hide_on_delete(dialog_error_datos);
}
void cierra_act()
{
        gtk_widget_hide_on_delete(advertencia_actualizar_emp);
}
void busca_producto_pos()
{

        //gtk_tree_selection_unselect_all(select3);
        char busqueda_fac[300];
        const char *consulta = gtk_entry_get_text(GTK_ENTRY(ety_producto_pos));
        conn = mysql_init(NULL);
        sprintf(busqueda_fac, "select Nombre , Venta from Producto where Nombre LIKE '%%%s%%' or SKU ='%s' limit 30", consulta, consulta);
        if (strcmp(consulta, "") == 0)
        {
                gtk_stack_set_visible_child(GTK_STACK(stack_pop_producto), lbl_nodatos);
        }
        else
        {
                gtk_widget_set_visible(pop_busqueda_pos, 1);

                if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                {
                }
                if (mysql_query(conn, busqueda_fac))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                res = mysql_use_result(conn);
                while ((row = mysql_fetch_row(res)) != NULL)
                {
                        gtk_tree_view_remove_column(GTK_TREE_VIEW(view_busqueda), column_bus);
                        gtk_tree_view_remove_column(GTK_TREE_VIEW(view_busqueda), column_bus2);
                        gtk_tree_view_remove_column(GTK_TREE_VIEW(view_busqueda), column_bus3);
                        titulo_bus();
                }
                if (gtk_tree_model_get_iter_first(model_busc, &iter_busqueda) == TRUE)
                {
                        gtk_stack_set_visible_child(GTK_STACK(stack_pop_producto), cont_view_bus);
                }
                else
                {
                        gtk_stack_set_visible_child(GTK_STACK(stack_pop_producto), lbl_nodatos);
                }
                mysql_free_result(res);
                mysql_close(conn);
        }
}

void busca_proveedor()
{

        user = gtk_entry_get_text(g_Entry_Usuario);
        password = gtk_entry_get_text(g_Entry_Contrasena);
        char busqueda_fac[300];
        char busqueda_fac2[300];
        const char *consulta = gtk_entry_get_text(ety_busca_proveedor);
        const char *consulta2 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_busca_estado));

        if (consulta2[0] == 'E')
        {
                sprintf(busqueda_fac, "select * from Proveedor where Empresa LIKE '%%%s%%'", consulta);
                sprintf(busqueda_fac2, "select count(Empresa) from Proveedor where Empresa LIKE '%%%s%%'", consulta);
        }
        else
        {
                sprintf(busqueda_fac, "select * from Proveedor where Empresa LIKE '%%%s%%' and Estado ='%s'", consulta, consulta2);
                sprintf(busqueda_fac2, "select count(Empresa) from Proveedor where Empresa LIKE '%%%s%%' and Estado ='%s'", consulta, consulta2);
        }
        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, busqueda_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        refresca_datos_emp();
        while ((row = mysql_fetch_row(res)) != NULL)titulo_empresa();
        if (mysql_query(conn, busqueda_fac2))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)gtk_label_set_text(lbl_elepro,row[0]);
        mysql_free_result(res);
        mysql_close(conn);
}

void busca_producto()
{
        char busqueda_fac[600];
        char busqueda_fac2[600];
        const char *consulta = gtk_entry_get_text(ety_busca_producto);
        const char *consulta2 = gtk_entry_get_text(ety_busca_proveedor_producto);
        const char *consulta3 = gtk_entry_get_text(ety_busca_categoria);
        const char *consulta4 = gtk_entry_get_text(ety_busca_subcategoria);

        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(mark_bajostck)))
        {
                gtk_widget_set_sensitive(GTK_WIDGET(ety_busca_producto), FALSE);
                gtk_widget_set_sensitive(GTK_WIDGET(cb_productos_proveedor), FALSE);
                gtk_widget_set_sensitive(GTK_WIDGET(cb_bs_cat), FALSE);
                gtk_widget_set_sensitive(GTK_WIDGET(cb_bs_subcat), FALSE);
                sprintf(busqueda_fac, "select * from Producto where Piezas <=10");
                sprintf(busqueda_fac2, "select count(SKU) from Producto where Piezas <=10");
        }
        else
        {
                gtk_widget_set_sensitive(GTK_WIDGET(ety_busca_producto), TRUE);
                gtk_widget_set_sensitive(GTK_WIDGET(cb_productos_proveedor), TRUE);
                gtk_widget_set_sensitive(GTK_WIDGET(cb_bs_cat), TRUE);
                gtk_widget_set_sensitive(GTK_WIDGET(cb_bs_subcat), TRUE);
                sprintf(busqueda_fac, "select * from Producto where Nombre LIKE '%s%%' and Marca LIKE '%s%%' and Categoria LIKE '%s%%' and Subcategoria LIKE '%s%%'", consulta, consulta2, consulta3, consulta4);
                sprintf(busqueda_fac2, "select count(SKU) from Producto where Nombre LIKE '%s%%' and Marca LIKE '%s%%' and Categoria LIKE '%s%%' and Subcategoria LIKE '%s%%'", consulta, consulta2, consulta3, consulta4);

        }
        if (strcmp(consulta2, "") != 0)
        {
                gtk_entry_set_icon_from_icon_name(ety_busca_proveedor_producto, GTK_ENTRY_ICON_SECONDARY, "edit-clear-symbolic");
                gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto, GTK_ENTRY_ICON_SECONDARY, 1);
        }
        if (strcmp(consulta3, "") != 0)
        {
                gtk_entry_set_icon_from_icon_name(ety_busca_categoria, GTK_ENTRY_ICON_SECONDARY, "edit-clear-symbolic");
                gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto, GTK_ENTRY_ICON_SECONDARY, 1);
        }
        if (strcmp(consulta4, "") != 0)
        {
                gtk_entry_set_icon_from_icon_name(ety_busca_subcategoria, GTK_ENTRY_ICON_SECONDARY, "edit-clear-symbolic");
                gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto, GTK_ENTRY_ICON_SECONDARY, 1);
        }

        if (strcmp(consulta2, "") == 0)
        {
                gtk_entry_set_icon_from_icon_name(ety_busca_proveedor_producto, GTK_ENTRY_ICON_SECONDARY, NULL);
                gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto, GTK_ENTRY_ICON_SECONDARY, 1);
        }
        if (strcmp(consulta3, "") == 0)
        {
                gtk_entry_set_icon_from_icon_name(ety_busca_categoria, GTK_ENTRY_ICON_SECONDARY, NULL);
                gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto, GTK_ENTRY_ICON_SECONDARY, 1);
        }
        if (strcmp(consulta4, "") == 0)
        {
                gtk_entry_set_icon_from_icon_name(ety_busca_subcategoria, GTK_ENTRY_ICON_SECONDARY, NULL);
                gtk_entry_set_icon_sensitive(ety_busca_proveedor_producto, GTK_ENTRY_ICON_SECONDARY, 1);
        }

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, busqueda_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        refresca_datos_pro();
        while ((row = mysql_fetch_row(res)) != NULL)titulo_producto();
        if (mysql_query(conn, busqueda_fac2))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)gtk_label_set_text(lbl_elementos_pro,row[0]);
        mysql_free_result(res);
        mysql_close(conn);

        gtk_entry_set_progress_fraction(ety_busca_producto, 0.0);
}

void on_btn_consulta_emp_clicked()
{
        char busqueda_fac[50];
        const char *consulta = gtk_entry_get_text(ety_produ_emp);

        sprintf(busqueda_fac, "select * from Proveedor where Empresa = '%s'", consulta);

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, busqueda_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                gtk_entry_set_text(ety_nombreemp, row[1]);
                gtk_entry_set_text(ety_direccion, row[2]);
                gtk_entry_set_text(ety_telefono, row[3]);
                gtk_entry_set_text(ety_region, row[4]);
                gtk_entry_set_text(ety_pais_emp, row[5]);
                gtk_entry_set_text(ety_rfc, row[6]);
                gtk_entry_set_text(ety_estado_emp, row[7]);
                gtk_entry_set_text(ety_correoemp, row[8]);
                gtk_stack_set_visible_child(GTK_STACK(stack_actualiza), box_act_emp);
        }

        mysql_free_result(res);
        mysql_close(conn);

        gtk_entry_set_progress_fraction(ety_produ_emp, 0.0);
}

void consulta_producto()
{
        user = gtk_entry_get_text(g_Entry_Usuario);
        password = gtk_entry_get_text(g_Entry_Contrasena);
        char busqueda_fac[50];
        const char *consulta = gtk_entry_get_text(ety_cbarra);

        sprintf(busqueda_fac, "select * from Producto where SKU = '%s'", consulta);

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, busqueda_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {

                gtk_entry_set_text(ety_nombrepro, row[1]);
                gtk_entry_set_text(ety_marcapro, row[2]);
                gtk_entry_set_text(ety_nlote, row[5]);
                gtk_entry_set_text(ety_cneto, row[6]);
                gtk_entry_set_text(GTK_ENTRY(spin_piezas), "");
                gtk_entry_set_text(GTK_ENTRY(spin_compra), row[8]);
                gtk_entry_set_text(GTK_ENTRY(spin_venta), row[9]);
                gtk_entry_set_text(GTK_ENTRY(ety_cat), row[10]);
                gtk_entry_set_text(GTK_ENTRY(entry_subcat), row[11]);
                gtk_stack_set_visible_child(GTK_STACK(stack_actualiza2), box_act_pro);
        }

        mysql_free_result(res);
        mysql_close(conn);
}

void on_acercade_close()
{
        gtk_dialog_run(GTK_DIALOG(win_acercade));
        gtk_widget_hide_on_delete(win_acercade);
}
void on_cerrar_acercade_clicked()
{
        gtk_widget_hide_on_delete(win_acercade);
}
void on_acercade_destroy()
{
        gtk_widget_hide(win_acercade);
}
void on_info_close()
{
        gtk_label_set_text(lbl_info, "");
        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar), FALSE);
}
void on_info_close2()
{
        gtk_label_set_text(lbl_info_bien, "");
        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar_bien), FALSE);
}
void abre_preferencias()
{
        gtk_stack_set_visible_child(stack_menu_pos, child_preferencia);
}
void regresa_menu()
{
        gtk_stack_set_visible_child(stack_menu_pos, child_menu);
}
void consulta_usuarios()
{
        gtk_stack_set_visible_child(GTK_STACK(stack_login), spinner_login);
        char *user = "esteban";
        password = "junomava3842";
        conn = mysql_init(NULL);
        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        else
        {
        }

        if (mysql_query(conn, "select user from mysql.db where db='Tienda'"))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);

        while ((row = mysql_fetch_row(res)) != NULL)
                gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_usuarios), row[0]);

        mysql_free_result(res);
        mysql_close(conn);
        if (strcmp(gtk_entry_get_text(ety_can_inve), "0") == 0)
        {
                gtk_entry_set_text(ety_can_inve, "");
        }
        gtk_stack_set_visible_child(GTK_STACK(stack_login), img_conect);
}

void cerrar_setup()
{
        gtk_widget_hide(bienvenido);
        //agregar funcion para refrescar usuarios
        gtk_widget_show(window_login);
}
void consulta_pos()
{
        gboolean button_state;
        button_state = gtk_toggle_button_get_active(btn_consulta_pos);
        if (button_state)
        {
                // button is active
                gtk_revealer_set_reveal_child(GTK_REVEALER(reveal_consulta), TRUE);
        }
        else
        {
                // button is inactive
                gtk_revealer_set_reveal_child(GTK_REVEALER(reveal_consulta), FALSE);
        }
}
void modifica_productos()
{
        gboolean button_state;
        button_state = gtk_toggle_button_get_active(btn_edit_productos);
        if (button_state)
        {
                // button is active
                gtk_revealer_set_reveal_child(GTK_REVEALER(reveal_productos), TRUE);
        }
        else
        {
                // button is inactive
                gtk_revealer_set_reveal_child(GTK_REVEALER(reveal_productos), FALSE);
        }
}

void modifica_proveedor()
{
        gboolean button_state;
        button_state = gtk_toggle_button_get_active(btn_edit_proveedor);
        if (button_state)
        {
                // button is active
                gtk_revealer_set_reveal_child(GTK_REVEALER(reveal_proveedor), TRUE);
        }
        else
        {
                // button is inactive
                gtk_revealer_set_reveal_child(GTK_REVEALER(reveal_proveedor), FALSE);
        }
}

void abre_busca()
{
        gtk_tree_selection_unselect_all(select3);
        gboolean button_state = gtk_toggle_button_get_active(btn_buscar_pos);
        if (button_state)
        {
                // button is active
                gtk_stack_set_visible_child(GTK_STACK(stack_header), ety_producto_pos);
        }
        else
        {
                // button is inactive
                gtk_tree_selection_unselect_all(select3);
                gtk_stack_set_visible_child(GTK_STACK(stack_header), swchitcher);
                gtk_entry_set_text(GTK_ENTRY(ety_producto_pos), "");
        }
}

void siguiente()
{
        const char *comp_user = gtk_entry_get_text(ety_user_bien);

        const char *con1 = gtk_entry_get_text(ety_contrasena1);
        const char *con2 = gtk_entry_get_text(ety_contrasena2);
        if (gtk_stack_get_visible_child(GTK_STACK(pasos)) == pag_bienvenido)
        {
                gtk_stack_set_visible_child(GTK_STACK(pasos), pag_usuarios);
                gtk_widget_set_sensitive(GTK_WIDGET(pag_atras), TRUE);
        }
        else if (gtk_stack_get_visible_child(GTK_STACK(pasos)) == pag_usuarios)
        {
                if (strcmp(comp_user, "") == 0)
                {
                        gtk_label_set_text(lbl_info_bien, "El Usuario no Puede ir en Blanco");
                        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar_bien), TRUE);
                }
                else if (strcmp(con1, con2) == 0 && strcmp(con2, "") != 0)
                {
                        gtk_stack_set_visible_child(GTK_STACK(pasos), pag_comp);
                        gtk_widget_set_sensitive(GTK_WIDGET(pag_atras), TRUE);
                        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar_bien), FALSE);
                }
                else
                {
                        gtk_label_set_text(lbl_info_bien, " Las Contrasena no coinciden o estan vacias");
                        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar_bien), TRUE);
                }
        }
        else if (gtk_stack_get_visible_child(GTK_STACK(pasos)) == pag_comp)
        {
                gtk_stack_set_visible_child(GTK_STACK(pasos), pag_sumario);
                gtk_widget_set_sensitive(GTK_WIDGET(pag_atras), TRUE);
                gtk_widget_set_sensitive(GTK_WIDGET(pag_sig), FALSE);
        }
}
void atras()
{
        if (gtk_stack_get_visible_child(GTK_STACK(pasos)) == pag_sumario)
        {
                gtk_stack_set_visible_child(GTK_STACK(pasos), pag_comp);
                gtk_widget_set_sensitive(GTK_WIDGET(pag_sig), TRUE);
        }
        else if (gtk_stack_get_visible_child(GTK_STACK(pasos)) == pag_comp)
        {
                gtk_stack_set_visible_child(GTK_STACK(pasos), pag_usuarios);
                gtk_widget_set_sensitive(GTK_WIDGET(pag_sig), TRUE);
        }
        else if (gtk_stack_get_visible_child(GTK_STACK(pasos)) == pag_usuarios)
        {
                gtk_stack_set_visible_child(GTK_STACK(pasos), pag_bienvenido);
                gtk_widget_set_sensitive(GTK_WIDGET(pag_sig), TRUE);
                gtk_widget_set_sensitive(GTK_WIDGET(pag_atras), FALSE);
        }
}
void pagar_servicios()
{
        system("epiphany &");
}

void show_gensku()
{
        const char *temp = gtk_entry_get_text(ety_cbarra);
        if (strcmp(temp, "") == 0)
        {
                gtk_widget_set_visible(pop_generar_sku, 1);
        }
        else
        {
                gtk_widget_hide(pop_generar_sku);
                gtk_stack_set_visible_child(stack_sku, child_sku);
        }
}
void hide_gensku()
{
        gtk_stack_set_visible_child(stack_sku, child_sku);
}
void header_busqueda()
{
        if (gtk_stack_get_visible_child(stack_pos) == pag_pos)
        {
                gtk_stack_set_visible_child(stack_bus_pos, child_busqueda_pos);
        }
        else
        {
                gtk_stack_set_visible_child(stack_bus_pos, child_oculta_bus_pos);
        }
}
void show_gensku_child()
{
        gtk_stack_set_visible_child(stack_sku, child_tam_sku);
}
void consigue_datos()
{
        const gchar *usuario = gtk_entry_get_text(ety_user_bien);
        gtk_label_set_text(GTK_LABEL(lbl_user_bien), usuario);
}
void consigue_datos2()
{
        const gchar *empresa = gtk_entry_get_text(ety_emp_bien);
        const gchar *telefono = gtk_entry_get_text(ety_num_bien);
        const gchar *direccion = gtk_entry_get_text(ety_dir_bien);

        gtk_label_set_text(GTK_LABEL(lbl_emp_bien), empresa);
        gtk_label_set_text(GTK_LABEL(lbl_num_bien), telefono);
        gtk_label_set_text(GTK_LABEL(lbl_dir_bien), direccion);
}
void consigue_datos3()
{
        const gchar *rfc = gtk_entry_get_text(ety_rfc_bien);
        gtk_label_set_text(GTK_LABEL(lbl_rfc_bien), rfc);
}
void borra_busqueda1()
{
        gtk_entry_set_text(ety_busca_proveedor_producto, "");
}
void borra_busqueda2()
{
        gtk_entry_set_text(ety_busca_categoria, "");
}
void borra_busqueda3()
{
        gtk_entry_set_text(ety_busca_subcategoria, "");
}

void calcula_cambio()
{
        double x, y, z;
        char dif[200];
        char dif2[200];
        const char *recibido = gtk_entry_get_text(ety_recibido);
        const char *total = gtk_label_get_text(lbl_totalpos);

        x = atof(total);
        y = atof(recibido);
        z = x - y;

        sprintf(dif, "%9.2f", z);
        sprintf(dif2, "%-f", z);
        gtk_label_set_text(ety_cambio, dif);
        if (total[0] == '0')
        {
                gtk_label_set_text(lbl_error, "No hay nada en el carrito de compra");
                gtk_entry_set_text(ety_recibido, "0.00");
                return gtk_widget_show(dialog_error_datos);
        }
        if ((strcmp(dif, "     0.00") == 0) | (dif2[0] == '-'))
        {
                GdkColor color = {0, 255 << 4, 255 << 4, 255 << 4};
                gtk_widget_modify_fg(GTK_WIDGET(ety_cambio), GTK_STATE_NORMAL, &color);
                gtk_widget_set_sensitive(btn_venta, TRUE);
        }
        else
        {
                GdkColor color = {0, 255 << 8, 20 << 8, 20 << 8};
                gtk_widget_modify_fg(GTK_WIDGET(ety_cambio), GTK_STATE_NORMAL, &color);
                gtk_widget_set_sensitive(btn_venta, FALSE);
        }
}
void cucb()
{
        char ra[4];
        srand(time(NULL)); //El mayordomo pone a girar la diana
        int test = rand() % 9999;
        sprintf(ra, "%d", test);
        gtk_entry_set_text(ety_cbarra, ra);
}
void occb()
{
        char ra[9];
        srand(time(NULL)); //El mayordomo pone a girar la diana
        int test = rand() % 100000000;
        sprintf(ra, "%d", test);
        gtk_entry_set_text(ety_cbarra, ra);
}
void trecb()
{
        char ra[19];
        srand(time(NULL)); //El mayordomo pone a girar la diana
        long int test = rand() % 99999999999999999;
        sprintf(ra, "%ld", test);
        gtk_entry_set_text(ety_cbarra, ra);
}
void cierra_inventario()
{
        gtk_widget_hide_on_delete(widget_inventario);
}
void ver_total()
{
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
        while ((row = mysql_fetch_row(res)) != NULL)
                gtk_label_set_text(lbl_totalpos, row[0]);

        mysql_free_result(res);
        mysql_close(conn);
        calcula_cambio();
}
void abre_inventario()
{
        gtk_widget_show(widget_inventario);
}

void anadir_productocarrito()
{
        char anadir_pro[200];

        const char *sku = gtk_entry_get_text(ety_pos_producto);

        sprintf(anadir_pro, "insert into Carrito_compra(Producto,P_unitario) select  Nombre,Venta from Producto where SKU = '%s'", sku);

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, anadir_pro))
        {
                gtk_label_set_text(lbl_error, "Producto no Encontrado");
                return gtk_widget_show(dialog_error_datos);
        }

        mysql_close(conn);
        refresca_pos();
        ver_carrito();
        ver_total();
        gtk_entry_set_text(ety_pos_producto, "");
}
void contenido_inventario()
{
        refresca_inve();
        conn = mysql_init(NULL);
        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }
        if (mysql_query(conn, "select * from Inventario_temp"))
        {
                gtk_label_set_text(lbl_error, "Producto no Encontrado");
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
                titulo_inventario();

        mysql_free_result(res);
        mysql_close(conn);
}

void yoshiiiiii()
{
        refresca_inve();
        char anadir_pro[200];

        const char *sku = gtk_entry_get_text(ety_inve);

        sprintf(anadir_pro, "insert into Inventario_temp(SKU,Nombre,Piezas,Valor) select  SKU,Nombre,Piezas,Venta from Producto where SKU = '%s'", sku);

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, anadir_pro))
        {
                gtk_label_set_text(lbl_error, "El Producto ya fue añadido");
                return gtk_widget_show(dialog_error_datos);
        }
        contenido_inventario();
        gtk_entry_set_text(ety_inve, "");
        gtk_tree_selection_unselect_all(select4);
}
void elimina_ticket()
{
        char consu[200];
        char consu2[200];
        char consu3[200];
        char consu4[200];
        gchar *id;

        if (gtk_tree_selection_get_selected(select1, &model2, &iter2))
        {
                gtk_tree_model_get(model2, &iter2, COLidfac, &id, -1);
                sprintf(consu, "select Query from Ticket where Id_ticket = %s", id);
                sprintf(consu3, "delete from Ticket where Id_ticket = %s", id);
                conn = mysql_init(NULL);
                if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                if (mysql_query(conn, consu))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                res = mysql_use_result(conn);
                while ((row = mysql_fetch_row(res)) != NULL)
                {
                        sprintf(consu2, "update Producto inner join `%s` on Producto.Nombre = `%s`.Producto set Producto.Piezas=Producto.Piezas+`%s`.No", row[0], row[0], row[0]);
                        sprintf(consu4, "drop table %s", row[0]);
                }
                mysql_free_result(res);
                mysql_close(conn);
                //===============================================================================================================================
                conn = mysql_init(NULL);
                if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                if (mysql_query(conn, consu2))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }

                if (mysql_query(conn, consu3))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                if (mysql_query(conn, consu4))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                gtk_label_set_text(lbl_ticketcambio, "0.00");
                gtk_label_set_text(lbl_ticketrecibido, "0.00");
                gtk_label_set_text(lbl_tickettotal, "0.00");
                res = mysql_use_result(conn);
                refresca_datos_fac();
                refresca_datos_pro();
                contenido_ticket();
                contenido_producto();
        }
}
void ingresa_venta()
{
        GDateTime *date_time;
        gchar *dt_format;

        date_time = g_date_time_new_now_local();
        dt_format = g_date_time_format(date_time, "Ticket_%d%m%y%H%M%S");
        char anadir_pro[200];
        char anadir_pro2[200];
        char anadir_pro3[200];
        const char *recibido = gtk_entry_get_text(ety_recibido);
        const char *total = gtk_label_get_text(lbl_totalpos);
        const char *cambio = gtk_label_get_text(ety_cambio);

        if (total[0] == '0')
        {
                gtk_label_set_text(lbl_error, "No hay nada en el carrito de compra");
                gtk_entry_set_text(ety_recibido, "0.00");
                return gtk_widget_show(dialog_error_datos);
        }
        else
        {
                conn = mysql_init(NULL);

                sprintf(anadir_pro, "CREATE TABLE `%s` AS  (select Producto , P_unitario , count(Producto) as 'No', (P_unitario * count(Producto)) as SubTotal from Carrito_compra group by Producto)", dt_format);
                sprintf(anadir_pro2, "insert into Ticket (Usuario,Total,Recibido,Cambio,Query,Fecha_hora) values (USER(),'%s','%s','%s','%s',NOW())", total, recibido, cambio, dt_format);
                sprintf(anadir_pro3, "update Producto inner join `%s` on Producto.Nombre = `%s`.Producto set Producto.Piezas=Producto.Piezas-`%s`.No;", dt_format, dt_format, dt_format);

                if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                {
                }
                if (mysql_query(conn, anadir_pro2))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                if (mysql_query(conn, anadir_pro))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                if (mysql_query(conn, anadir_pro3))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                if (mysql_query(conn, "DELETE FROM Carrito_compra"))
                {
                }
                refresca_datos_fac();
                refresca_pos();
                refresca_datos_pro();
                ver_carrito();
                contenido_ticket();
                contenido_producto();
                contenido_aud_producto();
                gtk_entry_set_text(ety_recibido, "0.00");
                gtk_label_set_text(lbl_totalpos, "0.00");
                gtk_label_set_text(ety_cambio, "0.00");
                GdkColor color = {0, 255 << 4, 255 << 4, 255 << 4};
                gtk_widget_modify_fg(GTK_WIDGET(ety_cambio), GTK_STATE_NORMAL, &color);
                gtk_widget_set_sensitive(btn_venta, TRUE);
                imprime_ticket();
        }
}
void selection_buscar(gpointer data)
{
        char consu[200];
        gchar *holi;
        if (gtk_tree_selection_get_selected(select3, &model_busc, &iter_busqueda))
        {
                gtk_tree_model_get(model_busc, &iter_busqueda, COLproducto_pos, &holi, -1);
                sprintf(consu, "insert into Carrito_compra(Producto,P_unitario) select  Nombre,Venta from Producto where Nombre = '%s'", holi);
                conn = mysql_init(NULL);
                if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                if (mysql_query(conn, consu))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                //mysql_free_result(res);
                //res = mysql_use_result(conn);
                refresca_pos();
                ver_carrito();
                ver_total();
        }
        gtk_tree_selection_unselect_all(select3);
}
void filtra_proveedor()
{
        char busqueda_fac[300];
        const char *consulta = gtk_entry_get_text(ety_filtraprov);
        const char *consulta2 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_filtraprov));

        if (consulta2[0] == 'S')
        {

                sprintf(busqueda_fac, "select * from Aud_proveedor where Empresa LIKE '%%%s%%'", consulta);
        }
        else
        {
                sprintf(busqueda_fac, "select * from Aud_proveedor where Empresa LIKE '%%%s%%' and Accion ='%s'", consulta, consulta2);
        }
        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, busqueda_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        refresca_datos_emp();
        while ((row = mysql_fetch_row(res)) != NULL)titulo_empresa_auditoria();
        mysql_free_result(res);
        mysql_close(conn);
        contenido_tablas();
}
void filtrar_productos()
{
        char busqueda_fac[300];
        const char *consulta = gtk_entry_get_text(ety_filtroprod);
        const char *consulta2 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_filtroprod));

        if (consulta2[0] == 'S')
        {

                sprintf(busqueda_fac, "select * from Aud_producto where Cod_barra LIKE '%%%s%%'", consulta);
        }
        else
        {
                sprintf(busqueda_fac, "select * from Aud_producto where Cod_barra LIKE '%%%s%%' and Accion ='%s'", consulta, consulta2);
        }
        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, busqueda_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        refresca_datos_pro();
        while ((row = mysql_fetch_row(res)) != NULL)
                titulo_producto_auditoria();
        mysql_free_result(res);
        mysql_close(conn);
        contenido_producto();
}

void filtrar_ticketR()
{
        char busqueda_fac[300];
        const char *consulta2 = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_filtraudticket));
        const char *consulta3 = gtk_entry_get_text(ety_cantidadtick);

        if (consulta2[0] == 'S')
        {

                sprintf(busqueda_fac, "select * from Aud_ticket where Ant_total LIKE '%s%%' or New_total LIKE '%s%%' ORDER BY Id DESC", consulta3, consulta3);
        }
        else
        {
                sprintf(busqueda_fac, "select * from Aud_ticket where (Ant_total LIKE '%s%%' or New_total LIKE '%s%%') and Accion ='%s' ORDER BY Id DESC", consulta3, consulta3, consulta2);
        }
        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, busqueda_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        refresca_datos_fac();
        while ((row = mysql_fetch_row(res)) != NULL)titulo_factura_auditoria();
        mysql_free_result(res);
        mysql_close(conn);
        contenido_ticket();
}

void filtrar_ticket()
{
        char busqueda_fac[500];
        const char *consulta = gtk_entry_get_text(ety_busquedatick);
        const char *consulta2 = gtk_entry_get_text(ety_cantidadtick2);

        const char *dia = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_dia_propro4));
        const char *mes = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_mes_propro4));
        const char *anio = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_anio_propro4));

        if (strcmp(consulta2, "0.00") == 0)
                gtk_entry_set_text(ety_cantidadtick2, "");
        if (dia[0] == 'D' && mes[0] == 'M' && anio[0] == 'A')
        {
                sprintf(busqueda_fac, "select * from Ticket where Id_ticket LIKE '%s%%' and Total LIKE '%s%%' ORDER BY Id_ticket DESC", consulta, consulta2);
        }
        else
        {

                sprintf(busqueda_fac, "select * from Ticket where Id_ticket LIKE '%s%%' and Total LIKE '%s%%' and year(Fecha_hora) = '%s' and month(Fecha_hora) = '%s' and day(Fecha_hora) = '%s' ORDER BY Id_ticket DESC", consulta, consulta2, anio, mes, dia);
        }
        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }

        if (mysql_query(conn, busqueda_fac))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac);
                gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac2);
                gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac3);
                gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac4);
                gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac5);
                gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac6);
                gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac7);
                refresca_venta();
                titulo_factura();
        }
        mysql_free_result(res);
        mysql_close(conn);
        contenido_aud_ticket();
}

void tree_selection_changed_cb()
{

        gchar *id;
        if (gtk_tree_selection_get_selected(select1, &model2, &iter2) == TRUE)
        {
                char consu[200];
                char consu2[200];
                char consu3[200];

                gtk_tree_model_get(model2, &iter2, COLidfac, &id, -1);
                sprintf(consu, "select Query from Ticket where Id_ticket = %s", id);
                sprintf(consu3, "select Total,Recibido,Cambio from Ticket where Id_ticket = %s", id);
                conn = mysql_init(NULL);
                if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                if (mysql_query(conn, consu))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                res = mysql_use_result(conn);
                while ((row = mysql_fetch_row(res)) != NULL)
                        sprintf(consu2, "select * from %s", row[0]);
                mysql_free_result(res);
                mysql_close(conn);
                //===============================================================================================================================
                conn = mysql_init(NULL);
                if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                if (mysql_query(conn, consu2))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                res = mysql_use_result(conn);
                refresca_venta();
                while ((row = mysql_fetch_row(res)) != NULL)
                {
                        refresca_venta();
                        titulo_venta();
                }

                if (mysql_query(conn, consu3))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                res = mysql_use_result(conn);
                while ((row = mysql_fetch_row(res)) != NULL)
                {
                        gtk_label_set_text(lbl_tickettotal, row[0]);
                        gtk_label_set_text(lbl_ticketrecibido, row[1]);
                        gtk_label_set_text(lbl_ticketcambio, row[2]);
                }

                mysql_close(conn);
                g_free(id);
        }
}

void key_event(GtkWidget *widget, GdkEventKey *event, gpointer data)
{
        g_printerr("%s\n\n", gdk_keyval_name(event->keyval));
        gchar *produc;
        char consu[200];
        if ((strcmp(gdk_keyval_name(event->keyval), "minus") == 0) | (strcmp(gdk_keyval_name(event->keyval), "KP_Subtract") == 0))
        {
                if (gtk_tree_selection_get_selected(select2, &model_pos, &iter_pos))
                {
                        gtk_tree_model_get(model_pos, &iter_pos, producto_pos, &produc, -1);
                        sprintf(consu, "delete from Carrito_compra where Producto ='%s' limit 1", produc);

                        conn = mysql_init(NULL);
                        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                        {
                                char tempErr[60];
                                sprintf(tempErr, "%s", mysql_error(conn));
                                gtk_label_set_text(lbl_error, tempErr);
                                gtk_widget_show(dialog_error_datos);
                        }
                        if (mysql_query(conn, consu))
                        {
                                char tempErr[60];
                                sprintf(tempErr, "%s", mysql_error(conn));
                                gtk_label_set_text(lbl_error, tempErr);
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
        if (strcmp(gdk_keyval_name(event->keyval), "Escape") == 0)
        {
                if (gtk_tree_selection_get_selected(select2, &model_pos, &iter_pos))
                {
                        conn = mysql_init(NULL);
                        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                        {
                                char tempErr[60];
                                sprintf(tempErr, "%s", mysql_error(conn));
                                gtk_label_set_text(lbl_error, tempErr);
                                gtk_widget_show(dialog_error_datos);
                        }
                        if (mysql_query(conn, "delete from Carrito_compra"))
                        {
                                char tempErr[60];
                                sprintf(tempErr, "%s", mysql_error(conn));
                                gtk_label_set_text(lbl_error, tempErr);
                                gtk_widget_show(dialog_error_datos);
                        }
                        res = mysql_use_result(conn);
                        mysql_free_result(res);
                        mysql_close(conn);
                        refresca_pos();
                        ver_carrito();
                        ver_total();
                }
        }
}

void select_inve()
{
        gchar *sku;
        if (gtk_tree_selection_get_selected(select4, &model_inventario, &iter_inventario) == TRUE)
        {
                char consu[200];
                gtk_tree_model_get(model_inventario, &iter_inventario, COLinvesku, &sku, -1);
                sprintf(consu, "select SKU from Inventario_temp where SKU = %s", sku);
                conn = mysql_init(NULL);
                if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                if (mysql_query(conn, consu))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                res = mysql_use_result(conn);
                while ((row = mysql_fetch_row(res)) != NULL)
                        gtk_label_set_text(lbl_inventario, row[0]);
                mysql_free_result(res);
                mysql_close(conn);
                g_free(sku);
        }
}

void inserta_datosinve()
{

        const char *cantidad = gtk_entry_get_text(ety_can_inve);
        const char *sku = gtk_label_get_text(lbl_inventario);

        char consu[256];
        sprintf(consu, "update Inventario_temp set Ingreso=%s , Balance=((Piezas-%s)*Valor)*-1 ,Fisico=%s-Piezas  where Inventario_temp.SKU=%s ", cantidad, cantidad, cantidad, sku);
        conn = mysql_init(NULL);
        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }
        if (mysql_query(conn, consu))
        {
                gtk_label_set_text(lbl_error, "No se ah seleccionado ningun articulo");
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);
        mysql_free_result(res);
        mysql_close(conn);
        refresca_inve();
        contenido_inventario();        
        gtk_entry_set_text(ety_can_inve, "");
        gtk_label_set_text(lbl_inventario, "");
        gtk_tree_selection_unselect_all(select4);
}
void elimina_inventario()
{
        const char *sku = gtk_label_get_text(lbl_inventario);

        char consu[200];
        sprintf(consu, "delete from  Inventario_temp where SKU=%s", sku);
        conn = mysql_init(NULL);
        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }
        if (mysql_query(conn, consu))
        {
        }
        res = mysql_use_result(conn);
        mysql_free_result(res);
        mysql_close(conn);
        refresca_inve();
        contenido_inventario();
        gtk_entry_set_text(ety_can_inve, "");
        gtk_tree_selection_unselect_all(select4);
        gtk_label_set_text(lbl_inventario, "");
}
void todo_nada_inve()
{
        if (!gtk_switch_get_state(switch_inve))
        {
                refresca_inve();
                conn = mysql_init(NULL);
                if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                {
                }
                if (mysql_query(conn, "delete from Inventario_temp"))
                {
                }
                if (mysql_query(conn, "insert into Inventario_temp(SKU,Nombre,Piezas,Valor) select SKU,Nombre,Piezas,Venta from Producto"))
                {
                }
                res = mysql_use_result(conn);
                mysql_free_result(res);
                mysql_close(conn);
                contenido_inventario();
        }
        else
        {
                refresca_inve();
                conn = mysql_init(NULL);
                if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                {
                }
                if (mysql_query(conn, "delete from Inventario_temp"))
                {
                }
                mysql_free_result(res);
                mysql_close(conn);
                contenido_inventario();
        }
}

void exporta_inventario()
{
        char anadir_inve[200];
        char anadir_inve2[200];
        const char *fecha = gtk_label_get_text(lbl_hora);
        sprintf(anadir_inve, "CREATE TABLE `Inve_%s` AS  (select * from Inventario_temp)", fecha);
        sprintf(anadir_inve2, "insert into Inventario select count(SKU) , sum(Fisico), sum(Balance),USER(),now(),'Inve_%s' from Inventario_temp", fecha);
        conn = mysql_init(NULL);
        if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
        {
        }
        if (mysql_query(conn, anadir_inve))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        if (mysql_query(conn, anadir_inve2))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        if (mysql_query(conn, "DELETE FROM Inventario_temp"))
        {
        }
        res = mysql_use_result(conn);

        while ((row = mysql_fetch_row(res)) != NULL);
        mysql_free_result(res);
        mysql_close(conn);
        refresca_inve();
        refresca_inve_alt();
        contenido_inventario();
        contenido_inventario_alt();
}

void select_query()
{
        gchar *query;
        if (gtk_tree_selection_get_selected(select5, &model_inventario_alt, &iter_inventario_alt) == TRUE)
        {
                refresca_inve_desc();
                char consu[200];
                gtk_tree_model_get(model_inventario_alt, &iter_inventario_alt, colquery, &query, -1);
                sprintf(consu, "select * from `%s` ", query);
                conn = mysql_init(NULL);
                if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                if (mysql_query(conn, consu))
                {
                        char tempErr[60];
                        sprintf(tempErr, "%s", mysql_error(conn));
                        gtk_label_set_text(lbl_error, tempErr);
                        return gtk_widget_show(dialog_error_datos);
                }
                res = mysql_use_result(conn);
                while ((row = mysql_fetch_row(res)) != NULL)titulo_inventario_desc();
                mysql_free_result(res);
                mysql_close(conn);
                g_free(query);
        }
}