#include <easyx.h>
#include <stdio.h>
#include <windows.h>
#include <graphics.h>

class Button
{
private:
	int x, y, x_length, y_length;//Start x,start y,x 's length,y 's length
	char* text;//Button 's text
	int textcolor;
	void press(void)
	{//This function is draw this Button
		setlinestyle(0, 4);
		setlinecolor(0xbababa);
		rectangle(x, y, x + x_length, y + y_length);
		setlinecolor(0x8d8d8d);
		line(x + x_length - 3, y + 3, x + x_length - 3, y + y_length - 3);
		line(x + 3, y + 3, x + x_length - 3, y + 3);
	}
	void init(void)
	{
		setlinestyle(0, 4);
		setlinecolor(0x8d8d8d);
		rectangle(x, y, x + x_length, y + y_length);
		setlinecolor(0xbababa);
		line(x + x_length - 3, y + 3, x + x_length - 3, y + y_length - 3);
		line(x + 3, y + 3, x + x_length - 3, y + 3);
		settextcolor(textcolor);
		outtextxy(x + 3, y + (y_length / 2) - 7, text);
	}
public:
	bool push = false;
	void testpress(void)
	{
		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				if (msg.x > x && msg.x < x + x_length && msg.y>y && msg.y < y + y_length)
				{
					press();
					push = true;
					while (msg.uMsg != WM_LBUTTONUP)
					{
						msg = GetMouseMsg();
					}
				}
				else if (push == true)init(), push = false;
			}
			else if (push == true)init(), push = false;
		}
		else if (push == true)init(), push = false;
	}
	Button(int x, int y, int x_length, int y_length, char* text, int textcolor)
	{//This function is init this button
		this->x = x;
		this->y = y;
		this->x_length = x_length;
		this->y_length = y_length;
		this->text = text;
		this->textcolor = textcolor;
		init();
	}
	~Button() {}
};