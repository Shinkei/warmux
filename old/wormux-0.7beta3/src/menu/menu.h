/******************************************************************************
 *  Wormux, a free clone of the game Worms from Team17.
 *  Copyright (C) 2001-2004 Lawrence Azzoug.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 ******************************************************************************
 * Generic menu
 *****************************************************************************/

#ifndef MENU_H
#define MENU_H

#include <iostream>
//-----------------------------------------------------------------------------
#include "../graphic/sprite.h"
#include "../gui/button.h"
#include "../gui/list_box.h"
#include "../gui/check_box.h"
#include "../gui/spin_button.h"
#include "../gui/box.h"
#include "../gui/question.h"
#include "../gui/label.h"
#include "../gui/null_widget.h"
//-----------------------------------------------------------------------------

class Menu
{
public:
   Menu(char* bg); 
   virtual ~Menu();

   void Run ();

private:
   Sprite *background;
   bool close_menu;

   /* Actions buttons  */
   Button *b_ok;
   Button *b_cancel;
   HBox *actions_buttons;

   void BasicDraw(int mouse_x, int mouse_y);
   bool BasicOnClic(int mouse_x, int mouse_y);

protected:
   void sig_ok();
   void sig_cancel();

   virtual void __sig_ok() = 0;
   virtual void __sig_cancel() = 0;

   virtual void Draw(int mouse_x, int mouse_y) = 0;   
   virtual void OnClic ( int mouse_x, int mouse_y, int button) = 0;
   void SetActionButtonsXY(int x, int y);

};

#endif
