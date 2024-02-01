#include "window.hpp"
#include "entity.hpp"

Window::Window():
name_{"Default"},width_{800},height_{600},window_{sf::VideoMode(width_, height_), name_}
{
    window_.setFramerateLimit(60);
    window_.setVerticalSyncEnabled(true);
}

Window::Window(std::string name, int width, int height)
: name_{std::move(name)},width_{std::move(width)},height_{std::move(height)},window_{sf::VideoMode(width_, height_), name_}
{
    window_.setFramerateLimit(60);
    window_.setVerticalSyncEnabled(true);
}

bool Window::isOpen()
{
    return window_.isOpen();
}

bool // go on
Window::handle_events_()
{
    sf::Event event;
    while(window_.pollEvent(event)) 
    {
        switch (event.type) 
            {
            case sf::Event::Closed:
            {
                window_.close();
                return false;
            }
            case sf::Event::Resized:
            {
                resize_(event.size.width, event.size.height);
                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                if(event.mouseButton.button==sf::Mouse::Left)
                {
                const auto coord=window_.mapPixelToCoords(
                {event.mouseButton.x, event.mouseButton.y});
                std::cout << '[' << name_ << "] left button at ("
                << coord.x << "," << coord.y << ")\n";
                }
                break;
            }
            case sf::Event::KeyPressed:
            {
                switch(event.key.code)
                    {
                    case sf::Keyboard::Escape:
                    {
                        window_.close();
                        return false;
                    }
                    default:
                    {
                        break;
                    }
                }
            break;
            }
            default:
            {
                break;
            }
            }
    }
    return true;
}
void Window::resize_(int width, int height)
{
    this->width_ = width;
    this->height_ = height;
    window_.setView(sf::View(sf::FloatRect(0, 0, (float)width, (float)height)));
}

void Window::render_()
{
    window_.clear(sf::Color::Black);
    //#ifdef ENTITY_HPP
    for(auto& entity : entities_)
    {
        entity.draw(window_);
    }
    //#endif
    window_.display();
}
//#ifdef ENTITY_HPP
void Window::addEntity_(Entity entity)
{
    entities_.emplace_back(std::move(entity));
}

//#endif

sf::RenderWindow& Window::get_window_()
{
    return window_;
}

double
Window::delta_time_()
{
  const auto clock_now=std::chrono::system_clock::now().time_since_epoch();
  const auto now=1e-3*double(std::chrono::duration_cast
                             <std::chrono::milliseconds>(clock_now).count());
  if(first_time_<=0.0)
  {
    first_time_=last_time_=now;
  }
  const auto dt=now-last_time_;
  last_time_+=dt;
  const auto step=1.0/30.0; // target 30 FPS
  if(dt<step)
  {
    sf::sleep(sf::seconds(float(step-dt)));
  }
  return dt;
}

bool // go on
Window::step()
{
    
    if(!isOpen())
    {
        return false;
    }
    for (auto &e: entities_)
    {
        e.animate(2, 0);
        
    }
    const auto dt=delta_time_();
    render_();
    return handle_events_();

    
}