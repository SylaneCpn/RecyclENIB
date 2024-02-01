#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
//#include "kinetics.hpp"

class Window;

class Entity
{
public:
    Entity(Window &window, float pos_x_, float pos_y_);

    void
    draw(sf::RenderWindow &render_window)const;

    void
    animate(float x, float y);

    float
    get_x();

    float
    get_y();

    sf::Vector2f get_pos();

private:
    sf::RectangleShape shape_;
    

};

#endif

