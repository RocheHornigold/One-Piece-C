/**********************************************************************************************************************************
* Copyright (c) 2017-2018 El F. Percy
* Standard Header. 
*
* This project is One Piece: Gigant Battle! 2 New World almost copy. 
* I do not take any advantages of this project and resources taken from OP: GB! 2 are for learning purposes. 
* Under this message I list all people, companies or organization which materials I've used in this project:
* - Hopson97: Structure of this game is based on his structures of games. Link:
* - Bandai Namco Entertainment and Shūeisha published One Piece: Gigant Battle! 2 New World. 
*   I used many features of their product (including texture, sound etc.) 
*
* MIT License
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
**********************************************************************************************************************************/

#include "States/Play_state.hpp"

#include "Game.hpp"
#include "States/Menu_state.hpp"
#include "Utility.hpp"

Play_state::Play_state(Game* game)
        :State{game},
         m_background{m_resource_manager,"marineford_bay.png"}
{   
        player_first = std::make_unique<Luffy>(m_resource_manager);
        player_second = std::make_unique<Zoro>(m_resource_manager);
        m_background.get_sprite().setScale(3.0f,3.0f);

        m_p1_box.setFillColor(sf::Color::Transparent);
        m_p2_box.setFillColor(sf::Color::Transparent);
        m_p1_box.setOutlineThickness(5);
        m_p2_box.setOutlineThickness(5);
        m_p1_box.setOutlineColor(sf::Color::Red);
        m_p2_box.setOutlineColor(sf::Color::Red);

        //player_first->get_sprite().setPosition(100f,m_floor);
        //player_second->get_sprite().setPosition(100f,m_floor);
}

void Play_state::input(float dt, float clocked_time)
{
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
                m_game->change_state(new Menu_state(m_game));
}

void Play_state::set_rectangles()
{
        sf::FloatRect f = player_first->get_sprite().getGlobalBounds();
        m_p1_box.setPosition(f.left, f.top);
        m_p1_box.setSize(sf::Vector2f{f.width, f.height});


        f = player_second->get_sprite().getGlobalBounds();
        m_p2_box.setPosition(f.left, f.top);
        m_p2_box.setSize(sf::Vector2f{f.width, f.height});
}

void Play_state::update(float dt, float clocked_time)
{
        player_first->logic_first(dt,clocked_time);
        player_second->logic_second(dt,clocked_time);
        player_second->logic_second(dt,clocked_time);
        
        // if (aabb_intersection(player_first->get_sprite().getGlobalBounds(), 
        //         player_second->get_sprite().getGlobalBounds()))
        if (player_first->get_sprite().getGlobalBounds()
                .intersects(player_second->get_sprite().getGlobalBounds()))
                        clocked_msg("Intersection beetween characters");
        
        
        set_rectangles();
}

void Play_state::draw()
{
        m_background.draw(m_game->get_render_window());
        player_first->draw(m_game->get_render_window());
        player_second->draw(m_game->get_render_window());
        m_game->get_render_window().draw(m_p1_box);
        m_game->get_render_window().draw(m_p2_box);
}