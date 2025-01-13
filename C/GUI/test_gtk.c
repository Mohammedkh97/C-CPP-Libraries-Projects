#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>      // Include the GTK header (GTK is part of the GNOME project) it refers to GNOME Tool Kit
#include <gdk/gdk.h>      // Include the GTK header (GTK is part of the GNOME project) it refers to GNOME Drawing Kit
#include <glib.h>         // Include the GLib header (GLib is a utility library used by GTK)  it refers to GNOME Library
#include <glib/galloca.h> // Include the GLib header (GLib is a utility library used by GTK)  it refers to GNOME Library

void on_button_clicked(GtkWidget *button, gpointer data) // Callback function for button click
{
    printf("%s clicked\n", (char *)data); // Print the button label
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv); // Initialize GTK

    // Create a new top-level window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Set window properties
    gtk_window_set_title(GTK_WINDOW(window), "GTK Test with Buttons");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Create two buttons
    GtkWidget *button1 = gtk_button_new_with_label("Button 1");
    GtkWidget *button2 = gtk_button_new_with_label("Button 2");

    // Connect the "clicked" signal of the buttons to the callback function
    g_signal_connect(button1, "clicked", G_CALLBACK(on_button_clicked), "Button 1");
    g_signal_connect(button2, "clicked", G_CALLBACK(on_button_clicked), "Button 2");

    // Create a vertical box to pack the buttons
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // Add buttons to the box
    gtk_box_pack_start(GTK_BOX(vbox), button1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button2, TRUE, TRUE, 0);

    // Add the box to the window
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Connect the "destroy" event to gtk_main_quit, which exits the GTK main loop
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show the window and buttons
    gtk_widget_show_all(window);

    // Enter the GTK main loop
    gtk_main();

    return 0;
}