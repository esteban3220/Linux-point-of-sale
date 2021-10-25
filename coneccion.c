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

#include "tablas.c"
#include "config.c"

gboolean timer_handler();
FILE *fichero;
FILE *fichero2;
FILE *fichero3;
FILE *ticket;

void contenido_ticket()
{

	conn = mysql_init(NULL);
	servidor();
	if (mysql_query(conn, "select * from Ticket ORDER BY Id_ticket DESC"))
	{
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)
		titulo_factura();
	mysql_free_result(res);
	mysql_close(conn);
}

void contenido_producto()
{
	conn = mysql_init(NULL);

	servidor();
	if (mysql_query(conn, "select * from Producto"))
	{
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)
		titulo_producto();
	if (mysql_query(conn, "select count(SKU) from Producto"))
	{
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)
		gtk_label_set_text(lbl_elementos_pro, row[0]);
	mysql_free_result(res);
	mysql_close(conn);
}
void conectar()
{
	conectar_ini();
}

void consulta_proveedor()
{

	conn = mysql_init(NULL);
	servidor();

	if (mysql_query(conn, "select Empresa from Proveedor;"))
	{
	}
	res = mysql_use_result(conn);

	while ((row = mysql_fetch_row(res)) != NULL)
	{
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_marcapro), row[0]);
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_productos_proveedor), row[0]);
	}
	mysql_free_result(res);
	mysql_close(conn);
}

void contenido_tablas()
{

	conn = mysql_init(NULL);

	servidor();

	if (mysql_query(conn, "select * from Proveedor"))
	{
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)
		titulo_empresa();
	if (mysql_query(conn, "select count(Empresa) from Proveedor"))
	{
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)
		gtk_label_set_text(lbl_elepro, row[0]);
	mysql_free_result(res);
	mysql_close(conn);
}

void contenido_aud_proveedor()
{

	conn = mysql_init(NULL);

	servidor();

	if (mysql_query(conn, "select * from Aud_proveedor ORDER BY Id DESC"))
	{
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)
		titulo_empresa_auditoria();
	mysql_free_result(res);
	mysql_close(conn);
}

void contenido_aud_ticket()
{

	conn = mysql_init(NULL);

	servidor();

	if (mysql_query(conn, "select * from Aud_ticket ORDER BY Id DESC"))
	{
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)
		titulo_factura_auditoria();
	mysql_free_result(res);
	mysql_close(conn);
}

void contenido_aud_producto()
{

	conn = mysql_init(NULL);

	servidor();

	if (mysql_query(conn, "select * from Aud_producto ORDER BY Id DESC"))
	{
	}
	res = mysql_use_result(conn);
	//==================================================================================================================
	while ((row = mysql_fetch_row(res)) != NULL)
		titulo_producto_auditoria();
	mysql_free_result(res);
	mysql_close(conn);
}

void contenido_inventario_alt()
{

	conn = mysql_init(NULL);
	servidor();
	if (mysql_query(conn, "select * from Inventario ORDER BY Fecha DESC"))
	{
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)
		titulo_inventario_alt();

	mysql_free_result(res);
	mysql_close(conn);
}
