#include <stdlib.h>
#include <string.h>

const char *user;
const char *password;
char *database = "Tienda";
char *getKey(char *key);
static void servidor()
{
    FILE *conf;
    user = gtk_entry_get_text(g_Entry_Usuario);
    password = gtk_entry_get_text(g_Entry_Contrasena);
    char cadena[40], *key, *val;
    char variables[4][20] = {"server", "user", "password", "imprimir"}, i;
    char _server[13], _password[50], _user[50], imprimir;
    if ((conf = fopen("config.conf", "rb")) == NULL)
    {
        perror("Error");
        gtk_label_set_text(lbl_error, "No se pudo cargar el archivo de configuracion");
        return gtk_widget_show(dialog_error_datos);
    }
    fgets(cadena, sizeof(cadena), conf);
    do
    {
        key = cadena;
        if ((*key) != '#' && strlen(key) >= 0)
        {
            val = getKey(key);
            for (i = 0; i < 4; i++)
            {
                if (!strcmp(key, variables[i]))
                {
                    switch (i)
                    {
                    case 0:
                        strcpy(_server, val);
                        break;
                    case 1:
                        strcpy(_user, val);
                        break;
                    case 2:
                        strcpy(_password, val);
                        break;
                    case 3:
                        imprimir = atoi(val);
                        break;
                    }
                }
                /* code */

                strtok(_server, "\n");
                strtok(_user, "\n");
                strtok(_password, "\n");
            }
        }
        fgets(cadena, sizeof(cadena), conf);
    } while (!feof(conf));
    if (!mysql_real_connect(conn, _server, user, password, database, 0, NULL, 0))
    {
    }
}

void conf()
{
    FILE *conf;
    char cadena[40], *key, *val;
    char variables[4][30] = {"server", "user", "password", "imprimir"}, i;
    char _server[20], _password[50], imprimir, _user[50];
    if ((conf = fopen("config.conf", "rb")) == NULL)
    {
        perror("Error");
        gtk_label_set_text(lbl_error, "No se puede cargar el archivo de configuracion");
        return gtk_widget_show(dialog_error_datos);
    }
    fgets(cadena, sizeof(cadena), conf);
    do
    {
        key = cadena;
        if ((*key) != '#' && strlen(key) >= 0)
        {
            val = getKey(key);
            for (i = 0; i < 4; i++)
            {
                /* code */
                if (!strcmp(key, variables[i]))
                {
                    switch (i)
                    {
                    case 0:
                        strcpy(_server, val);
                        break;
                    case 1:
                        strcpy(_user, val);
                        break;
                    case 2:
                        strcpy(_password, val);
                        break;
                    case 3:
                        imprimir = atoi(val);
                        break;
                    }
                }
                strtok(_server, "\n");
                strtok(_user, "\n");
                strtok(_password, "\n");
                //strtok(imprimir, "\n");
            }
        }
        fgets(cadena, 40, conf);
    } while (!feof(conf));
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(mark_impresion), imprimir);
    if (!mysql_real_connect(conn, _server, _user, _password, database, 0, NULL, 0))
    {
    }
}

char *getKey(char *key)
{
    char i = 0;
    while (*(key + i) != ' ')
    {
        i++;
    }
    *(key + i) = 0;
    return key + i + 1;
}

void conf_impresion()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(mark_impresion)))
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(mark_impresion), FALSE);
    }
    else
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(mark_impresion), TRUE);
    }
}
void conectar_ini()
{
    FILE *conf;
    conn = mysql_init(NULL);
    user = gtk_entry_get_text(g_Entry_Usuario);
    password = gtk_entry_get_text(g_Entry_Contrasena);
    char cadena[40], *key, *val;
    char variables[4][20] = {"server", "user", "password", "imprimir"}, i;
    char _server[20], _password[50], _user[50], imprimir;
    if ((conf = fopen("config.conf", "rb")) == NULL)
    {
        perror("Error");
        gtk_label_set_text(lbl_error, "No se pudo cargar el archivo de configuracion");
        return gtk_widget_show(dialog_error_datos);
    }
    fgets(cadena, sizeof(cadena), conf);
    do
    {
        key = cadena;
        if ((*key) != '#' && strlen(key) >= 0)
        {
            val = getKey(key);
            for (i = 0; i < 4; i++)
            {
                if (!strcmp(key, variables[i]))
                {
                    switch (i)
                    {
                    case 0:
                        strcpy(_server, val);
                        break;
                    case 1:
                        strcpy(_user, val);
                        break;
                    case 2:
                        strcpy(_password, val);
                        break;
                    case 3:
                        imprimir = atoi(val);
                        break;
                    }
                }
                /* code */

                strtok(_server, "\n");
                strtok(_user, "\n");
                strtok(_password, "\n");
            }
        }
        fgets(cadena, sizeof(cadena), conf);
    } while (!feof(conf));
    g_print("%s\n%s\n%s\n%d\n Servidor", _server, _user, _password, imprimir);
    if (!mysql_real_connect(conn, _server, user, password, database, 0, NULL, 0))
    {
        char tempErr[256];
        sprintf(tempErr, "%s", mysql_error(conn));
        gtk_label_set_text(La_Label_Error_ingreso, tempErr);
        g_print("%s", tempErr);
        gtk_widget_show(g_Dialog_Error);
    }
    else
    {
        gtk_stack_set_visible_child(GTK_STACK(stack_login), spinner_login);
        gtk_widget_hide_on_delete(window_login);
        gtk_widget_show(window_BD);
    }
    if (mysql_query(conn, "select Empresa from Proveedor"))
    {
    }
    res = mysql_use_result(conn);
    while ((row = mysql_fetch_row(res)) != NULL)
    {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_marcapro), row[0]);
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cb_productos_proveedor), row[0]);
        gtk_label_set_text(lbl_usuario, user);
    }
    mysql_free_result(res);
    mysql_close(conn);
}