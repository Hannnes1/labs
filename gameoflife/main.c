/*
 *      *** NOTHING TH DO HERE! ***
 *
 *     GUI for the Game of Life
 *     See : https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life 
 *     
 *     Animation is done using a timer. So no loops needed,
 *     a timer will call function update() at fixed intervals.
 *
 *     You don't need to understand this
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "game_of_life.h"   // Pasting the *.h file here (type and functions we use) 


#define MAX_ROWS 256   // Logical size
#define MAX_COLS 256

#define CELL_SIZE 3
#define UPDATE_SPEED 200

// Surface to draw the world
static cairo_surface_t *surface = NULL;

// Our (logical) world were everything happens
static cell_t world[MAX_ROWS][MAX_COLS];

//------ Initialization (called first of all) -------------

static void init() {
    // Initialize the world with a distribution of cells
    gofl_get_world(MAX_ROWS, MAX_COLS, world, 0.2);
}

//------ The animation loop (called by a timer) -------------

static gboolean update(gpointer widget) {
    GtkWidget *drawing_area = widget;
    cairo_t *cr = cairo_create(surface);

    // For each element in matrix, if ALIVE plot red rectangle
    // else white.
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            if (world[row][col] == ALIVE) {
                cairo_set_source_rgb(cr, 1, 0, 0);  // Red
            } else {
                cairo_set_source_rgb(cr, 1, 1, 1);  // White
            }
            cairo_rectangle(cr, row * CELL_SIZE, col * CELL_SIZE, CELL_SIZE, CELL_SIZE);
            cairo_fill(cr);
        }
    }
    gtk_widget_queue_draw(drawing_area); // Must have!! Why?? Forcing redraw?
    cairo_destroy(cr);

    gofl_next_state(MAX_ROWS, MAX_COLS, world); // Update the world!

    return true;
}


// --------- Graphical stuff. Don't need to understand --------------

static const int window_max_x = CELL_SIZE * MAX_ROWS;    // Graphical size
static const int window_max_y = CELL_SIZE * MAX_COLS;

// Create a new surface of the appropriate size
static gboolean configure_event_cb(GtkWidget *widget,
                                   GdkEventConfigure *event,
                                   gpointer data) {
    if (surface) {
        cairo_surface_destroy(surface);
    }
    surface = gdk_window_create_similar_surface(gtk_widget_get_window(widget),
                                                CAIRO_CONTENT_COLOR,
                                                gtk_widget_get_allocated_width(widget),
                                                gtk_widget_get_allocated_height(widget));

    // We've handled the configure event, no need for further processing.
    return true;
}

/*
 * Redraw the screen from the surface. Note that the ::draw
 * signal receives a ready-to-be-used cairo_t that is already
 * clipped to only draw the exposed areas of the widget
 */
static gboolean draw_cb(GtkWidget *widget,
                        cairo_t *cr,
                        gpointer data) {
    cairo_set_source_surface(cr, surface, 0, 0);
    cairo_paint(cr);  // Must be there
    return false;
}

static void close_window(void) {
    if (surface != NULL)
        cairo_surface_destroy(surface);

}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *frame;
    GtkWidget *drawing_area;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "GAME OF LIFE");

    g_signal_connect (window, "destroy", G_CALLBACK(close_window), NULL);

    gtk_container_set_border_width(GTK_CONTAINER (window), 8);

    frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME (frame), GTK_SHADOW_IN);
    gtk_container_add(GTK_CONTAINER (window), frame);

    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, window_max_x, window_max_y);

    gtk_container_add(GTK_CONTAINER (frame), drawing_area);

    // Signals used to handle the backing surface
    g_signal_connect (drawing_area, "draw",
                      G_CALLBACK(draw_cb), NULL);
    g_signal_connect (drawing_area, "configure-event",
                      G_CALLBACK(configure_event_cb), NULL);

    gtk_widget_show_all(window);

    srand((unsigned) time(NULL));     // For rand()
    init();                           // Create the world
    g_timeout_add(UPDATE_SPEED, update, drawing_area); // Start timer to call the callback
}

int main(int argc, char **argv) {

    GtkApplication *app;
    int status;

    app = gtk_application_new("chl.hajo.snake", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION (app), argc, argv);
    g_object_unref(app);

    return status;
}