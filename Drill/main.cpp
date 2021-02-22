/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

Function sine {sin,0,100,Point{20,150},1000,50,50};					//Sin függvény


int main(){

	using namespace Graph_lib;	
	
	Point tl{200,200};								//Egy pont (x és y kordinátái)
	Simple_window win{tl,1000,600,"My window"};					//Az op-n megjelenő ablak
	
		Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"}; 		//X tengely 
	
		Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};			//Y tengely
			ya.set_color(Color::cyan);					//Y tengely színbeállítása
			ya.label.set_color(Color::dark_red);				//Y tengely string színe
		
		sine.set_color(Color::blue);						//A sin function színének beállítása
		
		Polygon poly;								//Polygon 
			poly.add(Point{300,200});					//Polygon pont hozzáadása
			poly.add(Point{350,100});					//Polygon pont hozzáadása
			poly.add(Point{400,200});					//Polygon pont hozzáadása
			poly.set_color(Color::red);					//Polygon színe
			poly.set_style(Line_style::dash);				//Polygon vonalmintája
			poly.set_style(Line_style(Line_style::dash,4));		//Polygon vonalmintája
		
		Rectangle r{Point{200,200}, 100, 50};					//Téglalap 
			r.set_fill_color(Color::yellow);				//Téglalap kitöltési szine
			
		Closed_polyline poly_rect;						//Zárt polygon
			poly_rect.add(Point{100,50});					//Polygon pont hozzáadása
			poly_rect.add(Point{200,50});					//Polygon pont hozzáadása
			poly_rect.add(Point{200,100});				//Polygon pont hozzáadása
			poly_rect.add(Point{100,100});				//Polygon pont hozzáadása
			poly_rect.add(Point{50,75});					//Polygon pont hozzáadása
			poly_rect.set_style(Line_style(Line_style::dash,2));		//Polygon vonalmintája
			poly_rect.set_fill_color(Color::green);			//Polygon kitöltési színe
			
		Text t{Point{150,150}, "Hello, grapichal world!"};			//Szöveg 
			//t.set_font(Font::times_bold);				//Szöveg stílus (Hiba)
			t.set_font_size(20);						//Szöveg méret
			
		Image ii {Point{100,50},"twitch.jpg"};					//Kép 
		
		win.attach(ii);							//Kép rögzítése az ablakon
		win.attach(t);								//Szöveg rögzítése az ablakon
		win.attach(poly_rect);							//Zárt polygon rögzítése az ablakon
		win.attach(r);								//Téglalap rögzítése az ablakon
		win.attach(poly);							//Polygon rögzítése az ablakon
		win.attach(xa);							//X tengely rögzítése az ablakon
		win.attach(ya);							//Y tenegly rögzítése az ablakon
		win.attach(sine);							//Sin függvény rögzítése az ablakon
		win.wait_for_button();
}
