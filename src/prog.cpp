#include "window.hpp"
#include "menu.hpp"
#include "entity.hpp"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Window window("RecyclENIB", 800, 600);
    Entity e(window, 100, 100);
    window.addEntity_(e);
while(window.get_window_().isOpen()) {
    switch (menu(window))
					{
					case 0:
						while(window.step()){ }
						break;

					case 1:
                        std::cout << "Non implémenté" << std::endl;
						break;
					case 2:{
						int rules=1;
						auto r=sf::Text();
						

						auto font=sf::Font();
						if (!font.loadFromFile("../Fonts/Freedom-10eM.ttf"))
							{
								std::cout<<"Error , unable to load font";
							}

						r.setCharacterSize(14);
						r.setFont(font);
						r.setFillColor(sf::Color::White);
						r.setString("Jouer");
						r.setPosition(sf::Vector2f(((float)window.get_window_().getSize().x) * 0.2f,((float)window.get_window_().getSize().x) *0.2f ));
						
						while(rules && window.get_window_().isOpen()){

						sf::Event event;

						while (window.get_window_().pollEvent(event))
						{
							switch (event.type)
								{
									case sf::Event::KeyReleased:
										switch (event.key.code)
											{
												case sf::Keyboard::Return:
													rules=0;
													break;

												default:
													break;
											}
										break;

									case sf::Event::Closed:
										window.get_window_().close();
										break;

									default:
										break;


								}

						}

						window.get_window_().clear();
						window.get_window_().draw(r);
						window.get_window_().display();

						}



					break;
					}



					case 3:
						window.get_window_().close();
						break;


					default:
						break;
					}
}
}