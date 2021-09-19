/*
 * combobox.c
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

void cambia_bs_categoria()
{
  int i;
  gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_bs_subcat));
  const char *categoria = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_bs_cat));
  //const char *sub_categoria = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_subcat));
  g_print("%s\n", categoria);
  if (categoria[1] == 'b')
  {
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

    for (i = 0; i < G_N_ELEMENTS(aba); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), aba[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[11] == 'n')
  {

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
    for (i = 0; i < G_N_ELEMENTS(enlatados); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), enlatados[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[0] == 'L')
  {
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
        "Queso"};

    for (i = 0; i < G_N_ELEMENTS(lacteos); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), lacteos[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[0] == 'C')
  {
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
        "Paletas de dulce"};
    for (i = 0; i < G_N_ELEMENTS(dulces); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), dulces[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[1] == 'a')
  {
    const char *harinas[] = {
        "",
        "Tortillas de harina/maíz",
        "Galletas dulces",
        "Galletas saladas",
        "Pastelillos",
        "Pan de caja",
        "Pan dulce",
        "Pan molido",
        "Pan tostado"};
    for (i = 0; i < G_N_ELEMENTS(harinas); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), harinas[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[2] == 'u')
  {
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
        "Plátanos"};
    for (i = 0; i < G_N_ELEMENTS(verduras); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), verduras[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[11] == 'o')
  {

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
        "Vodka"};
    for (i = 0; i < G_N_ELEMENTS(alcohol); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), alcohol[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[2] == 'b')
  {
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
        "Refrescos"};
    for (i = 0; i < G_N_ELEMENTS(bebidas); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), bebidas[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[1] == 'e')
  {
    const char *helados[] = {
        "",
        "Helados / Paletas"};
    for (i = 0; i < G_N_ELEMENTS(helados); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), helados[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[19] == 's' && categoria[18] == 'o')
  {
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
        "Carne de puerco/res/pollo"};
    for (i = 0; i < G_N_ELEMENTS(preparado); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), preparado[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[1] == 'u')
  {
    const char *automedicacion[] = {
        "",
        "Suero",
        "Agua oxigenada",
        "Preservativos",
        "Alcohol",
        "Gasas",
        "Analgésicos",
        "Antigripales",
        "Antiácidos"};
    for (i = 0; i < G_N_ELEMENTS(automedicacion); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), automedicacion[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[15] == 'l')
  {
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
        "Jabones corporales/tocador"};
    for (i = 0; i < G_N_ELEMENTS(personal); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), personal[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[0] == 'U')
  {
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
        "Detergente para ropa"};
    for (i = 0; i < G_N_ELEMENTS(domestico); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), domestico[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[13] == 'L')
  {
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
        "Mecate/cuerda"};
    for (i = 0; i < G_N_ELEMENTS(limpieza); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), limpieza[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[0] == 'O')
  {
    const char *otros[] = {
        "",
        "Tarjetas telefónicas",
        "Recargas móviles",
        "Hielo",
        "Cigarros"};
    for (i = 0; i < G_N_ELEMENTS(otros); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), otros[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[3] == 'a')
  {
    const char *botanas[] = {
        "",
        "Papas",
        "Palomitas",
        "Frituras de maíz",
        "Cacahuates",
        "Botanas saladas",
        "Barras alimenticias",
        "Nueces y semillas"};
    for (i = 0; i < G_N_ELEMENTS(botanas); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), botanas[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
  else if (categoria[0] == 'C' && categoria[1] == 'a')
  {
    const char *botanas[] = {""};
    for (i = 0; i < G_N_ELEMENTS(botanas); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_bs_subcat), botanas[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb_bs_subcat), 0);
  }
}

void cambia_categoria()
{
  int i;
  gtk_entry_set_text(entry_subcat, "");
  gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(cb_subcat));
  const char *categoria = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb_cat));
  //const char *sub_categoria = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_subcat));
  g_print("%s\n", categoria);
  if (categoria[1] == 'b')
  {
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

    for (i = 0; i < G_N_ELEMENTS(aba); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), aba[i]);
    }
  }
  else if (categoria[11] == 'n')
  {

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
    for (i = 0; i < G_N_ELEMENTS(enlatados); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), enlatados[i]);
    }
  }
  else if (categoria[0] == 'L')
  {
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
        "Queso"};

    for (i = 0; i < G_N_ELEMENTS(lacteos); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), lacteos[i]);
    }
  }
  else if (categoria[0] == 'C')
  {
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
        "Paletas de dulce"};
    for (i = 0; i < G_N_ELEMENTS(dulces); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), dulces[i]);
    }
  }
  else if (categoria[1] == 'a')
  {
    const char *harinas[] = {
        "Tortillas de harina/maíz",
        "Galletas dulces",
        "Galletas saladas",
        "Pastelillos",
        "Pan de caja",
        "Pan dulce",
        "Pan molido",
        "Pan tostado"};
    for (i = 0; i < G_N_ELEMENTS(harinas); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), harinas[i]);
    }
  }
  else if (categoria[2] == 'u')
  {
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
        "Plátanos"};
    for (i = 0; i < G_N_ELEMENTS(verduras); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), verduras[i]);
    }
  }
  else if (categoria[11] == 'o')
  {

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
        "Vodka"};
    for (i = 0; i < G_N_ELEMENTS(alcohol); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), alcohol[i]);
    }
  }
  else if (categoria[2] == 'b')
  {
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
        "Refrescos"};
    for (i = 0; i < G_N_ELEMENTS(bebidas); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), bebidas[i]);
    }
  }
  else if (categoria[1] == 'e')
  {
    const char *helados[] = {
        "Helados / Paletas"};
    for (i = 0; i < G_N_ELEMENTS(helados); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), helados[i]);
    }
  }
  else if (categoria[19] == 's' && categoria[18] == 'o')
  {
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
        "Carne de puerco/res/pollo"};
    for (i = 0; i < G_N_ELEMENTS(preparado); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), preparado[i]);
    }
  }
  else if (categoria[1] == 'u')
  {
    const char *automedicacion[] = {
        "Suero",
        "Agua oxigenada",
        "Preservativos",
        "Alcohol",
        "Gasas",
        "Analgésicos",
        "Antigripales",
        "Antiácidos"};
    for (i = 0; i < G_N_ELEMENTS(automedicacion); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), automedicacion[i]);
    }
  }
  else if (categoria[15] == 'l')
  {
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
        "Jabones corporales/tocador"};
    for (i = 0; i < G_N_ELEMENTS(personal); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), personal[i]);
    }
  }
  else if (categoria[0] == 'U')
  {
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
        "Detergente para ropa"};
    for (i = 0; i < G_N_ELEMENTS(domestico); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), domestico[i]);
    }
  }
  else if (categoria[13] == 'l')
  {
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
        "Mecate/cuerda"};
    for (i = 0; i < G_N_ELEMENTS(limpieza); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), limpieza[i]);
    }
  }
  else if (categoria[0] == 'O')
  {
    const char *otros[] = {
        "Tarjetas telefónicas",
        "Recargas móviles",
        "Hielo",
        "Cigarros"};
    for (i = 0; i < G_N_ELEMENTS(otros); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), otros[i]);
    }
  }
  else if (categoria[3] == 'a')
  {
    const char *botanas[] = {
        "Papas",
        "Palomitas",
        "Frituras de maíz",
        "Cacahuates",
        "Botanas saladas",
        "Barras alimenticias",
        "Nueces y semillas"};
    for (i = 0; i < G_N_ELEMENTS(botanas); i++)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_subcat), botanas[i]);
    }
  }
}
