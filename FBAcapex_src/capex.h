/*  CAPEX for GP2X

    Copyright (C) 2007  JyCet

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

//#define SNES_TR_MASK        (1 << 4)
//#define SNES_TL_MASK        (1 << 5)
//#define SNES_X_MASK     (1 << 6)
//#define SNES_A_MASK     (1 << 7)
//#define SNES_RIGHT_MASK     (1 << 8)
//#define SNES_LEFT_MASK      (1 << 9)
//#define SNES_DOWN_MASK      (1 << 10)
//#define SNES_UP_MASK        (1 << 11)
//#define SNES_START_MASK     (1 << 12)
//#define SNES_SELECT_MASK    (1 << 13)
//#define SNES_Y_MASK     (1 << 14)
//#define SNES_B_MASK     (1 << 15)


//#ifdef GP2X
//#define GP2X_BUTTON_UP              (0)
//#define GP2X_BUTTON_DOWN            (4)
//#define GP2X_BUTTON_LEFT            (2)
//#define GP2X_BUTTON_RIGHT           (6)
//#define GP2X_BUTTON_UPLEFT          (1)
//#define GP2X_BUTTON_UPRIGHT         (7)
//#define GP2X_BUTTON_DOWNLEFT        (3)
//#define GP2X_BUTTON_DOWNRIGHT       (5)
//#define GP2X_BUTTON_CLICK           (18)
//#define GP2X_BUTTON_A               (12)
//#define GP2X_BUTTON_B               (13)
//#define GP2X_BUTTON_X               (14)
//#define GP2X_BUTTON_Y               (15)
//#define GP2X_BUTTON_L               (10)
//#define GP2X_BUTTON_R               (11)
//#define GP2X_BUTTON_START           (8)
//#define GP2X_BUTTON_SELECT          (9)
//#define GP2X_BUTTON_VOLUP           (16)
//#define GP2X_BUTTON_VOLDOWN         (17)
//#else
#define GP2X_BUTTON_UP              16
#define GP2X_BUTTON_DOWN            17
#define GP2X_BUTTON_LEFT            18
#define GP2X_BUTTON_RIGHT           19
#define GP2X_BUTTON_UPLEFT          55
#define GP2X_BUTTON_UPRIGHT         55
#define GP2X_BUTTON_DOWNLEFT        55
#define GP2X_BUTTON_DOWNRIGHT       55
#define GP2X_BUTTON_CLICK           56
#define GP2X_BUTTON_A               0
#define GP2X_BUTTON_B               1
#define GP2X_BUTTON_X               2
#define GP2X_BUTTON_Y               3
#define GP2X_BUTTON_L               4
#define GP2X_BUTTON_R               5
#define GP2X_BUTTON_START           12
#define GP2X_BUTTON_SELECT          13
#define GP2X_BUTTON_VOLUP           60
#define GP2X_BUTTON_VOLDOWN         60
//#endif

#define START_X	8
#define START_Y	120

#define NB_FILTRE	4
#define NB_MAX_GAMES	2048

#define WHITE  0
#define RED    9
#define ORANGE 18
#define YELLOW 27
#define GREEN  36
#define BLUE   45

//#define OPTION_NUM_FBA2X_CPU		0
//#define OPTION_NUM_FBA2X_68K		91
//#define OPTION_NUM_FBA2X_Z80		92
//#define OPTION_NUM_FBA2X_SOUND		1
//#define OPTION_NUM_FBA2X_SAMPLERATE	2
//#define OPTION_NUM_FBA2X_RESCALE	3
//#define OPTION_NUM_FBA2X_SHOWFPS	96
//#define OPTION_NUM_FBA2X_LINESCROLL	97
//#define OPTION_NUM_FBA2X_FRONTEND	4
//#define OPTION_NUM_FBA2X_SHOWTITLE	99
//#define OPTION_NUM_FBA2X_SCREENPOSITION	910
//#define OPTION_NUM_FBA2X_FULLCACHE	911
//
//#define OPTION_NUM_FBA2X_EXTINPUT	 912
//#define OPTION_NUM_FBA2X_XORROM		913
//#define OPTION_NUM_FBA2X_TWEAK		5
//#define OPTION_NUM_FBA2X_HISCORE	915

#define OPTION_NUM_FBA2X_SHOWFPS	0
#define OPTION_NUM_CAPEX_LIST       1

#define OPTION_NUM_RETURN			6


#define NOMBRE_OPTIONS				OPTION_NUM_RETURN

unsigned char joy_speed[4]={0,1,3,7};

static char *abreviation_cf[3][4]={
	{"Disable","Enable","",""},
	{"No","Soft","Hard FR","Hard HR"},
	{"Hide","Show","",""}
};

void ligneH(SDL_Surface* screenSurface, int x, int y, int w, Uint32 coul)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = w;
  r.h = 1;

  SDL_FillRect(screenSurface, &r, coul);
}

void ligneV(SDL_Surface* screenSurface, int x, int y, int h, Uint32 coul)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = 1;
  r.h = h;

  SDL_FillRect(screenSurface, &r, coul);
}

void carre_plein(SDL_Surface* screenSurface, int x, int y, int w, int h, Uint32 coul)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = w;
  r.h = h;

  SDL_FillRect(screenSurface, &r, coul);
}

void drawSprite(SDL_Surface* imageSurface, SDL_Surface* screenSurface, int srcX, int srcY, int dstX, int dstY, int width, int height)
{
	SDL_Rect srcRect;
	srcRect.x = srcX;
	srcRect.y = srcY;
	srcRect.w = width;
	srcRect.h = height;

	SDL_Rect dstRect;
	dstRect.x = dstX;
	dstRect.y = dstY;
	dstRect.w = width;
	dstRect.h = height;

	SDL_BlitSurface(imageSurface, &srcRect, screenSurface, &dstRect);
}

void preparation_fenetre(SDL_Surface *src, SDL_Surface *dest, int win_x , int win_y , int win_l , int win_h)
{
	Uint32 Pnoir = SDL_MapRGB(dest->format, 0, 0, 0);
	//preparation surface
	drawSprite( src , dest , win_x , win_y , win_x , win_y , win_l , win_h );
	ligneV( dest , win_x-1 , win_y , win_h , Pnoir );
	ligneV( dest , win_x+win_l , win_y , win_h , Pnoir );
	ligneH( dest , win_x , win_y-1 , win_l , Pnoir);
	ligneH( dest , win_x , win_y+win_h , win_l , Pnoir);	
}
