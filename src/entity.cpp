#include "entity.hpp"
#include "window.hpp"


Entity::Entity(Window &window, float pos_x, float pos_y)
: shape_{sf::Vector2f(50,50)}
{
    shape_.setPosition(pos_x, pos_y);
    shape_.setFillColor(sf::Color::Red);
}

void
Entity::draw(sf::RenderWindow &render_window)const
{
	
    render_window.draw(shape_);
}

void
Entity::animate(float x=0, float y=0 )
{
    shape_.move(x, y);
}

float
Entity::get_x()
{
    return shape_.getPosition().x;
}

float
Entity::get_y()
{
    return shape_.getPosition().y;
}

sf::Vector2f Entity::get_pos()
{
    return shape_.getPosition();
}