#include "splashkit.h"

int main()
{
    window w = open_window("Mini Animation", 400, 400);

    // Load image and set its cell details
    bitmap boom = load_bitmap("Explodebmp", "explosion.png");
    bitmap_set_cell_details(boom, 100, 100, 9, 9, 74); // cell width, height, cols, rows, count

    bitmap tick = load_bitmap("Tickingbmp", "tickingbomb.png");
    bitmap_set_cell_details(tick, 124, 136, 8, 7, 56);

    // Load the animation script
    animation_script explode_script = load_animation_script("ExplodingScript", "explosion.txt");
    animation_script tick_script = load_animation_script("tickingScript", "tick.txt");

    // Create the animation
    animation explode = create_animation(explode_script, "explosion");
    animation ticktock = create_animation(tick_script, "tick");

    // Create a drawing option
    drawing_options opt;
    opt = option_with_animation(explode);

    drawing_options optb;
    optb = option_with_animation(ticktock);

    // Basic event loop
    while( not quit_requested() )
    {
        
        for(size_t i = 0; i < 72; i++)
        {
             // Draw the bitmap - using opt to link to animation
            clear_screen(COLOR_GRAY);
            draw_bitmap(tick, 150, 150, optb);
            refresh_screen(60);
            update_animation(ticktock);
        }
        
        delay(500);

         for(size_t i = 0; i < 300; i++)
        {
            clear_screen(COLOR_GRAY);
            draw_bitmap(boom, 150, 150, opt);
            refresh_screen(60);
             // Update the animation
            update_animation(explode);
        }

        delay(2000);
        clear_screen(COLOR_BLACK);
        refresh_screen();
        delay(2000);

    }
}