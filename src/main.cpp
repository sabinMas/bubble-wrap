
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
int main()
{
    bn::core::init();
    // setting the background color as a variable
    bn::color bg_color(12, 8, 19);

    // adding sprites to screen
    bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(10, 40);

    // trying to make it so when a button is held it shows the color instead of pressed
    while (true)
    {
        bn::color current_color = bg_color;
        if (bn::keypad::a_held())
        {
            current_color = bn::color(0, 18, 0);
        }
        if (bn::keypad::b_held())
        {
            current_color = (bn::color(12, 0, 3));
        }
        bn::backdrop::set_color(current_color);

        bn::core::update();
    }
}
