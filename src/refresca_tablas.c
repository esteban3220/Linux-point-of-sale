/*
 * refresca_tablas.c
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

void refresca_datos_fac()
{

	if (gtk_tree_model_get_iter_first(model2, &iter2) == TRUE)
	{
		gtk_list_store_clear(store2);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac2);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac3);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac4);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac5);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac6);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view2), column_fac7);
	}
	if (gtk_tree_model_get_iter_first(model5, &iter5) == TRUE)
	{
		gtk_list_store_clear(store5);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac2);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac3);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac4);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac5);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac6);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac7);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac8);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac9);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac10);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac11);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac12);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac13);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac14);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac15);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac16);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view5), column_aud_fac17);
	}
}

void refresca_datos_emp()
{

	if (gtk_tree_model_get_iter_first(model, &iter) == TRUE)
	{
		gtk_list_store_clear(store);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view), column_emp);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view), column_emp2);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view), column_emp3);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view), column_emp4);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view), column_emp5);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view), column_emp6);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view), column_emp7);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view), column_emp8);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view), column_emp9);
	}
	if (gtk_tree_model_get_iter_first(model4, &iter4) == TRUE)
	{
		gtk_list_store_clear(store4);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp2);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp3);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp4);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp5);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp6);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp7);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp8);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp9);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp10);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp11);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp12);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp13);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp14);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp15);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp16);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp17);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp18);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp19);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp20);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view4), column_aud_emp21);
	}
}

void refresca_datos_pro()
{

	if (gtk_tree_model_get_iter_first(model3, &iter3) == TRUE)
	{
		gtk_list_store_clear(store3);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro2);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro3);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro4);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro5);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro6);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro7);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro8);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro9);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro10);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro11);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view3), column_pro12);
	}
	if (gtk_tree_model_get_iter_first(model6, &iter6) == TRUE)
	{
		gtk_list_store_clear(store6);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro2);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro3);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro4);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro5);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro6);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro7);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro8);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro9);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro10);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro11);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro12);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro13);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro14);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro15);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro16);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro17);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro18);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro19);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro20);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro21);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro22);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro23);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro24);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro25);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro26);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view6), column_aud_pro27);
	}
}
void refresca_busquedapos()
{

	if (gtk_tree_model_get_iter_first(model_busc, &iter_busqueda) == TRUE)
	{
		gtk_list_store_clear(store_busqueda);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_busqueda), column_bus);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_busqueda), column_bus2);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_busqueda), column_bus3);
	}
}

void refresca_pos()
{

	if (gtk_tree_model_get_iter_first(model_pos, &iter_pos) == TRUE)
	{
		gtk_list_store_clear(store_pos);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(treeview_pos), column_pos);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(treeview_pos), column_pos2);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(treeview_pos), column_pos3);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(treeview_pos), column_pos4);
	}
}

void refresca_inve()
{

	if (gtk_tree_model_get_iter_first(model_inventario, &iter_inventario) == TRUE)
	{
		gtk_list_store_clear(store_inve);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_inventario), column_inve);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_inventario), column_inve2);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_inventario), column_inve3);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_inventario), column_inve4);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_inventario), column_inve5);
	}
}
void refresca_venta()
{

	if (gtk_tree_model_get_iter_first(model_venta, &iter_venta) == TRUE)
	{
		gtk_list_store_clear(store_venta);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_venta), column_venta);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_venta), column_venta2);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_venta), column_venta3);
		gtk_tree_view_remove_column(GTK_TREE_VIEW(view_venta), column_venta4);
	}
}
