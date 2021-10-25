void genera_pdfproveedor()
{

        const char cabeceras[] = "\\documentclass[a4paper,12pt]{article}\n\\usepackage{longtable}\n\\usepackage{pdflscape}\n\\usepackage{graphicx,booktabs,tabularx}\n\\usepackage[spanish]{babel}\n\\begin{document}\n\\footnotesize  \n\\setlength\\LTleft{-30pt}\n \\setlength\\LTright{-100pt}\n  \\begin{landscape}\n \\thispagestyle{empty}\n\\begin{longtable}{|p{2.5cm}|p{2.5cm}|p{2.5cm}|p{2cm}|p{5cm}|p{1cm}|p{5cm}|}\n\\hline\n\\textbf{Empresa} & \\textbf{Nombre} & \\textbf{Direccion} & \\textbf{Telefono} & \\textbf{RFC} & \\textbf{Estado} & \\textbf{Correo}\\\\ \\hline \\hline ";
        char fin_documento[] = "\\end{longtable}\n\\thispagestyle{empty}\n\\end{landscape}\n\\end{document}";
        conn = mysql_init(NULL);

        servidor();

        if (mysql_query(conn, "select * from Proveedor"))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);

        //==========================================================================================================================================================

        fichero = fopen("Empresa.tex", "wt");
        fputs(cabeceras, fichero);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                fprintf(fichero, "%s & %s & %s & %s & %s & %s & %s \\\\ \\hline \n", row[0], row[1], row[2], row[3], row[6], row[7], row[8]);
        }
        fputs(fin_documento, fichero);
        fclose(fichero);
        system("latexmk -pdf -synctex=1 Empresa.tex && xdg-open Empresa.pdf & ");
        //return ;
        //==========================================================================================================================================================
        mysql_free_result(res);
        mysql_close(conn);

        gtk_label_set_text(lbl_info, "PDF Creado");
        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar), TRUE);
}

void pdf_producto()
{
        const char cabeceras[] = "\\documentclass[a4paper,12pt]{article}\n\\usepackage{longtable}\n\\usepackage{pdflscape}\n\\usepackage{graphicx,booktabs,tabularx}\n\\usepackage[spanish]{babel}\n\\begin{document}\n\\footnotesize  \n\\setlength\\LTleft{-50pt} \n\\setlength\\LTright{-100pt}  \n\\begin{landscape} \n\\thispagestyle{empty}\n\\begin{longtable}{|p{4cm}|p{2.5cm}|p{2.5cm}|p{1.8cm}|p{1.8cm}|p{1cm}|p{1cm}|p{3cm}|p{3cm}||}\n\\hline \n\\hline\n\\textbf{SKU} & \\textbf{Nombre} & \\textbf{Empresa} & \\textbf{Fecha de Produccion} & \\textbf{Fecha de Caducidad} & \\textbf{Piezas} & \\textbf{Venta} & \\textbf{Categoria} & \\textbf{Subcategoria}\\\\ \\hline \\hline";
        char fin_documento[] = "\\end{longtable}\n\\thispagestyle{empty}\n\\end{landscape}\n\\end{document}";
        conn = mysql_init(NULL);

        servidor();

        if (mysql_query(conn, "select * from Producto"))
        {
                char tempErr[60];
                sprintf(tempErr, "%s", mysql_error(conn));
                gtk_label_set_text(lbl_error, tempErr);
                return gtk_widget_show(dialog_error_datos);
        }
        res = mysql_use_result(conn);

        //==========================================================================================================================================================

        fichero = fopen("Producto.tex", "wt");
        fputs(cabeceras, fichero);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                fprintf(fichero, "%s & %s & %s & %s & %s & %s & %s & %s & %s \\\\ \\hline \n", row[0], row[1], row[2], row[3], row[4], row[7], row[9], row[10], row[11]);
        }
        fputs(fin_documento, fichero);
        fclose(fichero);
        system("latexmk -pdf -synctex=1 Producto.tex && xdg-open Producto.pdf & ");
        //return ;
        //==========================================================================================================================================================
        mysql_free_result(res);
        mysql_close(conn);

        gtk_label_set_text(lbl_info, "PDF Creado");
        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar), TRUE);
}
void imprime_ticket()
{
        const char *usuario = gtk_label_get_text(lbl_usuario);
        char cabecera[] = "\\documentclass{letter}\n"
                          "\\usepackage[utf8]{inputenc}\n"
                          "\\usepackage[colorlinks]{hyperref}\n"
                          "\\usepackage[left=1in,top=1in,right=1in,bottom=1in]{geometry} %% Document margins\n"
                          "\\usepackage{graphicx}\n"
                          "\\usepackage{tabularx}\n"
                          "\\usepackage{longtable}\n"
                          "\\usepackage{multirow}\n"
                          "\\usepackage{ragged2e}\n"
                          "\\usepackage{hhline}\n"
                          "\\usepackage{array}\n"
                          "\\hypersetup{"
                          "urlcolor=blue}\n"
                          "\\newcolumntype{R}[1]{>{\\raggedleft\\let\\newline\\\\\\arraybackslash\\hspace{0pt}}m{#1}}"
                          "\\begin{document}\n\\thispagestyle{empty}\n"
                          "\\begin{tabularx}{\\textwidth}{l X l}\n"
                          "\\hspace{-8pt} \\multirow{5}{*}{\\includegraphics[height=1.98cm]{logo.png}} & ";

        char cabecera2[] = "\\footnotesize \\MakeUppercase{\\today} \\\\[-0.4ex] \\footnotesize\\bf Le Atendio \\\\[-0.8ex]";
        char cabecera3[] = "\n& Tienda de Abarrotes & \\\\ \n"
                           "& Av. Tezozomoc Mz. 12 Lt.30 Loc. 4 San Miguel Xico 2a Seccion Valle de Chalco C.P. 56613 & \\\\ \n"
                           "& 2645-4025 & \\\\ \n"
                           "& tienda-de-abarrotes@gmail.com & \\\\ \n"
                           "\\end{tabularx} \n\n\\vspace{1 cm}"
                           "\\Large\\textbf{Copia de Cliente}\\normalsize\n"
                           "\\begin{longtable}{p{7cm} c c c l}\n"
                           "\\hline\n"
                           "& & & &\\\\[0.25ex]\n"
                           "{\\bf{Producto}} & \\centering{\\bf{Precio}} & \\centering{\\bf{Cantidad}} & \\bf SubTotal\\\\[2.5ex]\\hline\n"
                           "& & & &\\\\ \n";
        char consu[200];
        fichero3 = fopen("Ticket.tex", "wt");
        fputs(cabecera, fichero3);
        conn = mysql_init(NULL);

        servidor();

        if (mysql_query(conn, "select nombre from Tienda"))
        {
        }
        res = mysql_use_result(conn);

        while ((row = mysql_fetch_row(res)) != NULL)
        {
                fprintf(fichero3, "\\textbf{%s} & \\hskip12pt\\multirow{5}{*}{\\begin{tabular}{r}\\footnotesize\\bf No. de\n", row[0]);
        }
        if (mysql_query(conn, "select Id_ticket  from Ticket order by Id_ticket desc limit 1"))
        {
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                fprintf(fichero3, "Venta \\\\[-0.8ex] \\footnotesize %s \\\\[-0.4ex] \\footnotesize\\bf Fecha \\\\[-0.8ex] ", row[0]);
        }
        fputs(cabecera2, fichero3);
        fprintf(fichero3, "\\footnotesize %s \\end{tabular}}\\hspace{-6pt} \\\\", usuario);
        fputs(cabecera3, fichero3);
        mysql_free_result(res);
        mysql_close(conn);
        ///(////////////////////////////////////////////////////////////////////////////////////////)
        conn = mysql_init(NULL);

        servidor();
        if (mysql_query(conn, "select Query from Ticket order by Id_ticket desc limit 1"))
        {
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                sprintf(consu, "select * from %s", row[0]);
        }
        g_print(consu);
        if (mysql_query(conn, consu))
        {
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                fprintf(fichero3, "%s & \\centering\\$%s & \\centering %s &  \\$%s\\\\[2.5ex]\\hline\n  & & & &\\\\ \n", row[0], row[1], row[2], row[3]);
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (mysql_query(conn, "select Total,Recibido,Cambio from Ticket order by Id_ticket desc limit 1"))
        {
        }
        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
                fprintf(fichero3, "& & & \\bf Total & \\$%s\\\\[2.5ex]\\hhline{~~~--}\n"
                                  "& & & & \\\\"
                                  "& & & \\bf Recibido & \\$%s\\\\[2.5ex]\\hhline{~~~--}\n"
                                  "& & & & \\\\"
                                  "& & & \\bf Cambio & \\$%s\\\\[2.5ex]\\hhline{~~~==}\n \\end{longtable} \\end{document}",row[0], row[1], row[2]);
        }
        mysql_free_result(res);
        mysql_close(conn);
        fclose(fichero3);
        system("latexmk -pdf -synctex=1 Ticket.tex ");
        system("lpr Ticket.pdf && rm Ticket.*");

        gtk_label_set_text(lbl_info, "Ticket Creado");
        gtk_revealer_set_reveal_child(GTK_REVEALER(info_bar), TRUE);
}