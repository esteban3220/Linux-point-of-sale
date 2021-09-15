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


#include <mysql.h>
#include <stdlib.h>
#include "coneccion.c"
#include "combobox.c"
#include "refresca_tablas.c"
#include "consultas.c"

int main(int argc, char *argv[])
        {
                GtkBuilder              *builder;
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
                ety_filtraprov = GTK_ENTRY(gtk_builder_get_object(builder,"ety_filtraprov"));

                ety_busca_producto = GTK_ENTRY(gtk_builder_get_object(builder,"ety_busca_producto"));
                ety_busca_proveedor_producto = GTK_ENTRY(gtk_builder_get_object(builder,"ety_busca_proveedor_producto"));
                ety_busca_categoria = GTK_ENTRY(gtk_builder_get_object(builder,"ety_busca_categoria"));
                ety_busca_subcategoria = GTK_ENTRY(gtk_builder_get_object(builder,"ety_busca_subcategoria"));

                La_Label_Error_ingreso = GTK_LABEL(gtk_builder_get_object(builder,"Label_Error_ingreso"));
                cb_anio_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_fac"));
                cb_estado_emp = GTK_WIDGET(gtk_builder_get_object(builder,"cb_estado_emp"));
                cb_filtroprod = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder,"cb_filtroprod"));
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
                ety_cat = GTK_WIDGET(gtk_builder_get_object(builder,"ety_cat"));
                stack_actualiza2 = GTK_STACK(gtk_builder_get_object(builder,"stack_actualiza2"));
                stack_actualiza = GTK_WIDGET(gtk_builder_get_object(builder,"stack_actualiza"));
                muestra_func = GTK_WIDGET(gtk_builder_get_object(builder,"muestra_func"));
                reveal_consulta = GTK_WIDGET(gtk_builder_get_object(builder,"reveal_consulta"));
                btn_sql_aceptar = GTK_WIDGET(gtk_builder_get_object(builder,"btn_sql_aceptar"));
                btn_actualiza_emp = GTK_BUTTON(gtk_builder_get_object(builder,"btn_actualiza_emp"));
                ocultar_btn = GTK_WIDGET(gtk_builder_get_object(builder,"ocultar_btn"));
                box_act_pro = GTK_WIDGET(gtk_builder_get_object(builder,"box_act_pro"));
                win_acercade = GTK_WIDGET(gtk_builder_get_object(builder,"acercade"));
                switchgtk = GTK_WIDGET(gtk_builder_get_object(builder,"activador_sql"));
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
                ety_filtroprod = GTK_ENTRY(gtk_builder_get_object(builder,"ety_filtroprod"));

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
                cb_filtraprov = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder,"cb_filtraprov"));
                view_venta = GTK_WIDGET(gtk_builder_get_object(builder,"view_venta"));
                view_inventario = GTK_WIDGET(gtk_builder_get_object(builder,"view_inventario"));
                widget_inventario = GTK_WIDGET(gtk_builder_get_object(builder,"widget_inventario"));
                btn_proveedorpdf = GTK_BUTTON(gtk_builder_get_object(builder,"btn_proveedorpdf"));
                btn_exportaproductopdf = GTK_BUTTON(gtk_builder_get_object(builder,"btn_exportaproductopdf"));
                btn_eliminaticket = GTK_BUTTON(gtk_builder_get_object(builder,"btn_eliminaticket"));
                ety_cantidadtick = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cantidadtick"));
                cb_filtraudticket = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder,"cb_filtraudticket"));
                ety_busquedatick = GTK_ENTRY(gtk_builder_get_object(builder,"ety_busquedatick"));
                ety_cantidadtick2 = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cantidadtick2"));
                mark_bajostck = GTK_WIDGET(gtk_builder_get_object(builder,"mark_bajostck"));
                btn_resetfrcha = GTK_BUTTON(gtk_builder_get_object(builder,"btn_resetfrcha"));

                btn_cancelar_adver8 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver8"));
                btn_cancelar_adver2 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver2"));
                btn_cancelar_adver9 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver9"));
                btn_cancelar_adver7 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver7"));
                btn_cancelar_adver5 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver5"));
                btn_cancelar_adver1 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver1"));
                btn_cancelar_adver4 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver4"));
                btn_cancelar_adver6 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancelar_adver6"));
                cb_anio_propro4 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_propro4")); 
                cb_dia_propro4 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_propro4"));
                cb_mes_propro4 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_propro4"));

                for(i=2030;i>=2020;i--){
                        sprintf(anio,"%d",i);
                        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_pro),anio);
                        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_propro),anio);
                        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_propro4),anio);
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
                g_signal_connect(G_OBJECT(ety_filtroprod),"changed",G_CALLBACK(filtrar_productos),NULL);
                g_signal_connect(G_OBJECT(cb_filtraudticket),"changed",G_CALLBACK(filtrar_ticketR),NULL);
                g_signal_connect(G_OBJECT(ety_cantidadtick),"changed",G_CALLBACK(filtrar_ticketR),NULL);
                g_signal_connect(G_OBJECT(ety_busquedatick),"changed",G_CALLBACK(filtrar_ticket),NULL);
                g_signal_connect(G_OBJECT(ety_cantidadtick2),"changed",G_CALLBACK(filtrar_ticket),NULL);

                g_signal_connect(G_OBJECT(ety_cbarra),"focus-out-event",G_CALLBACK(hide_gensku),NULL);
                g_signal_connect(G_OBJECT(child_sku),"clicked",G_CALLBACK(show_gensku_child),NULL);
                g_signal_connect(G_OBJECT(btn_actualiza_emp),"clicked",G_CALLBACK(on_btn_actualiza_emp_clicked),NULL);
                g_signal_connect(G_OBJECT(btn_aceptar_a1),"clicked",G_CALLBACK(on_btn_aceptar_a1_clicked),NULL);
                g_signal_connect(G_OBJECT(cancela_and_factura2),"clicked",G_CALLBACK(on_cancela_and_factura2_clicked),NULL);
                g_signal_connect(G_OBJECT(btn_borrar_pro),"clicked",G_CALLBACK(on_btn_borrar_pro_clicked),NULL);

                g_signal_connect(G_OBJECT(cb_cat),"changed",G_CALLBACK(cambia_categoria),NULL);
                g_signal_connect(G_OBJECT(cb_filtraprov),"changed",G_CALLBACK(filtra_proveedor),NULL);
                g_signal_connect(G_OBJECT(cb_bs_cat),"changed",G_CALLBACK(cambia_bs_categoria),NULL);
                
                g_signal_connect(G_OBJECT(cb_mes_propro4),"changed",G_CALLBACK(filtrar_ticket),NULL);
                g_signal_connect(G_OBJECT(cb_dia_propro4),"changed",G_CALLBACK(filtrar_ticket),NULL);
                g_signal_connect(G_OBJECT(cb_anio_propro4),"changed",G_CALLBACK(filtrar_ticket),NULL);
                
                g_signal_connect(G_OBJECT(ety_busca_proveedor),"changed",G_CALLBACK(busca_proveedor),NULL);
                g_signal_connect(G_OBJECT(ety_producto_pos),"changed",G_CALLBACK(busca_producto_pos),NULL);
                g_signal_connect(G_OBJECT(ety_filtraprov),"changed",G_CALLBACK(filtra_proveedor),NULL);

                g_signal_connect(G_OBJECT(cb_busca_estado),"changed",G_CALLBACK(busca_proveedor),NULL);
                g_signal_connect(G_OBJECT(cb_filtroprod),"changed",G_CALLBACK(filtrar_productos),NULL);
                g_signal_connect(G_OBJECT(inserta_datos_productos),"clicked",G_CALLBACK(on_inserta_datos_empres_clicked),NULL);
                g_signal_connect(G_OBJECT(pro_aceptar_anadir),"clicked",G_CALLBACK(on_pro_aceptar_anadir_clicked),NULL);
                g_signal_connect(G_OBJECT(ety_busca_producto),"changed",G_CALLBACK(busca_producto),NULL);
                g_signal_connect(G_OBJECT(btn_aceptar_a2),"clicked",G_CALLBACK(on_btn_aceptar_a2_clicked),NULL);
                g_signal_connect(G_OBJECT(btn_cancelar_adver3),"clicked",G_CALLBACK(on_btn_cancelar_adver3_clicked),NULL);
                

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
                g_signal_connect(G_OBJECT(btn_resetfrcha),"clicked",G_CALLBACK(reset),NULL);
                g_signal_connect(G_OBJECT(btn_exportaproductopdf),"clicked",G_CALLBACK(pdf_producto),NULL);
                g_signal_connect(G_OBJECT(btn_inventario),"clicked",G_CALLBACK(abre_inventario),NULL);
                g_signal_connect(G_OBJECT(select1),"changed",G_CALLBACK(tree_selection_changed_cb),NULL);
                g_signal_connect(G_OBJECT(select3),"changed",G_CALLBACK(selection_buscar),NULL);
                g_signal_connect(treeview_pos, "key-release-event", G_CALLBACK(key_event), NULL);
		g_signal_connect(G_OBJECT(mark_bajostck), "toggled", G_CALLBACK(busca_producto), NULL);

                //GdkColor color = {0, 255<<8, 255<<8 ,255<<8};
		//gtk_widget_modify_bg (GTK_WIDGET(g_Entry_Usuario), GTK_STATE_NORMAL, &color);
		//gtk_widget_modify_bg (GTK_WIDGET(g_Entry_Contrasena), GTK_STATE_NORMAL, &color);

                gtk_builder_connect_signals(builder, NULL);
                g_timeout_add_seconds(1, (GSourceFunc)timer_handler, NULL);
                gtk_button_set_image (GTK_BUTTON (btn_menu_pos), gtk_image_new_from_icon_name ("open-menu-symbolic", GTK_ICON_SIZE_BUTTON));
                consulta_usuarios();
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

