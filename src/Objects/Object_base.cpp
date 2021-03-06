/**********************************************************************************************************************************
* Copyright (c) 2017-2018 Maciej Falkowski  
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
* 
**********************************************************************************************************************************/

#include "Objects/Object_base.hpp"

// draws an object to window 
void Object_base::draw(sf::RenderWindow& window)
{
        window.draw(m_sprite);
}

// set object position to the center 
void Object_base::center_origin()
{
        m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2,m_sprite.getLocalBounds().height / 2);
}

// returns reference to sprite
sf::Sprite& Object_base::get_sprite()
{
        return m_sprite;
}

// Character_base is an abstract class, copying prevented. Constructor is innaccessible outside the class 
Object_base::Object_base(Resource_manager& resource_manager, std::string texture_name)
{
        m_sprite.setTexture(resource_manager.get_texture(texture_name));
}

// set up is main function. It calls set_up_animations() and unique_set_up()
void Object_base::set_up(Resource_manager& resource_manager)
{
        unique_set_up(resource_manager);
        set_up_animations();
}