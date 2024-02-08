#include<gtk/gtk.h>

void button(GtkWidget *widget, gpointer data) {
	g_print("Clickable!");
}

int main(int argc, char **argv) {
	gtk_init(&argc, &argv);
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget *button = gtk_button_new_with_label("Clickable!");
	gtk_window_set_title(GTK_WINDOW(window), "Hello World!");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(GTK_OBJECT(button), "clicked", G_CALLBACK(button), "button");
	gtk_container_add(GTK_CONTAINER(window), button);
	gtk_widget_show_all(window);
	// gtk_widget_show(button);
	gtk_main();
	
	return 0;
}
