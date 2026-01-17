
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_log.h>
#include <bn_vector.h>
int main()
{
    bn::core::init();
    // setting the background color as a variable
    bn::color bg_color(24, 18, 31);
    bn::vector<bn::sprite_ptr, 10> circles = {};

    // adding sprites to screen
    // bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(0, 0);
    // bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(45, -45);
    // bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(-45, 45);
    // bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(75, -75);
    // bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(-60, 60);
    // bn::sprite_ptr myCircle6 = bn::sprite_items::dot.create_sprite(60, -50);
    // bn::sprite_ptr myCircle7 = bn::sprite_items::dot.create_sprite(50, -59);
    // // bn::sprite_ptr myCircle8 = bn::sprite_items::dot.create_sprite(50, -55);
    // // bn::sprite_ptr myCircle9 = bn::sprite_items::dot.create_sprite(55, -55);
    // // bn::sprite_ptr myCircle10 = bn::sprite_items::dot.create_sprite(55, -55);
    // // bn::sprite_ptr myCircle11 = bn::sprite_items::dot.create_sprite(55, -55);
    for (int x = -40; x <= 40; x += 10)
    {
        BN_LOG("x value", x);
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(x, 40);
        circles.push_back(myCircle);
    }

    // trying to make it so when a button is held it shows the color instead of pressed
    while (true)
    {
        bn::color current_color = bg_color;
        if (bn::keypad::a_held())
        {
            current_color = bn::color(0, 28, 0);
        }
        if (bn::keypad::b_held())
        {
            current_color = bn::color(24, 0, 10);
        }
        bn::backdrop::set_color(current_color);

        bn::core::update();
    }
}
