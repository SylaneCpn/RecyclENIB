#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <chrono>


class Entity;

class Window
{
    public:
        Window();
        Window(std::string name
        , int width
        , int height);
        bool isOpen();
        bool handle_events_();
        void render_();
        sf::RenderWindow& get_window_();
        void addEntity_(Entity entity);
        bool // go on
        step();
    
    private:
        std::string name_;
        int width_;
        int height_;
        sf::RenderWindow window_;
        //#ifdef ENTITY_HPP
        std::vector<Entity> entities_;
        
        
        //#endif
        double
        delta_time_();
        double
        first_time_, last_time_;
        void resize_(int width, int height);
        
};

#endif