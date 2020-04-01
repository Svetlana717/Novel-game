
#include "TXLib.h"
#include "ButtonsWithText.h"
using namespace std;

/*!
	Function for drawing screensavers for the game.
	\param[in] text The main text to be written on the castle wall.
*/
void paintStartingPage(char* text)
{
    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    txLine(450, 20, 100, 100);
    txLine(100, 100, 100, 130);
    txLine(100, 130, 135, 165);
    txLine(135, 165, 135, 565);
    txLine(135, 565, 100, 600);
    txLine(100, 600, 232, 600);
    txLine(232, 600, 197, 565);
    txLine(197, 565, 197, 130);
    txLine(197, 130, 277, 130);
    txLine(277, 130, 277, 565);
    txLine(277, 565, 242, 600);
    txLine(242, 600, 374, 600);
    txLine(374, 600, 339, 565);
    txLine(339, 565, 339, 130);
    txLine(339, 130, 419, 130);
    txLine(419, 130, 419, 565);
    txLine(419, 565, 384, 600);
    txLine(384, 600, 516, 600);
    txLine(516, 600, 481, 565);
    txLine(481, 565, 481, 130);
    txLine(481, 130, 561, 130);
    txLine(561, 130, 561, 565);
    txLine(561, 565, 526, 600);
    txLine(526, 600, 658, 600);
    txLine(658, 600, 623, 565);
    txLine(623, 565, 623, 130);
    txLine(623, 130, 703, 130);
    txLine(703, 130, 703, 565);
    txLine(703, 565, 668, 600);
    txLine(668, 600, 800, 600);
    txLine(800, 600, 765, 565);
    txLine(765, 565, 765, 165);
    txLine(765, 165, 800, 130);
    txLine(800, 130, 800, 100);
    txLine(800, 100, 450, 20);
    txFloodFill(450, 40);
    txSetColor(RGB(217, 170, 2));
    txTextOut(380, 110, text);
    txSetFillColor(RGB(255, 102, 255));
}

/*!
	Function for drawing small stars (decorations for the screensaver).
	\param[in] x Starting coordinate on the OX
	\param[in] y Starting coordinate on the OY
	\param[in] sizeForStar The scale of the star.
*/
void paintAllStar(int x, int y, int sizeForStar)
{
    txSetColor(RGB(217, 170, 2));
    txSetFillColor(RGB(255, 215, 0));
    txLine(x, y, x+3*sizeForStar, y+4*sizeForStar);
    txLine(x+3*sizeForStar, y+4*sizeForStar, x+8*sizeForStar, y+4*sizeForStar);
    txLine(x+8*sizeForStar, y+4*sizeForStar, x+5*sizeForStar, y+7*sizeForStar);
    txLine(x+5*sizeForStar, y+7*sizeForStar, x+7*sizeForStar, y+12*sizeForStar);
    txLine(x+7*sizeForStar, y+12*sizeForStar, x, y+9*sizeForStar);//
    txLine(x, y+9*sizeForStar, x-7*sizeForStar, y+12*sizeForStar);//
    txLine(x-7*sizeForStar, y+12*sizeForStar, x-5*sizeForStar, y+7*sizeForStar);
    txLine(x-5*sizeForStar, y+7*sizeForStar, x-8*sizeForStar, y+4*sizeForStar);
    txLine(x-8*sizeForStar, y+4*sizeForStar, x-3*sizeForStar, y+4*sizeForStar);
    txLine(x-3*sizeForStar, y+4*sizeForStar, x, y);
    txFloodFill(x, y+5);
    txSetFillColor(RGB(255, 102, 255));
}

/*!
	Function for drawing a narrative slide.
	\param[in] line1 The text of the first line in the story.
	\param[in] line2 The text of the second line in the story.
	\param[in] line3 The text of the third line in the story.
	\param[in] line4 The text of the fourth line in the story.
*/
void paintNarrativeMe(char* line1, char* line2, char* line3, char* line4)
{
    txSetFillColor(RGB(255, 102, 255));
    txRectangle(0, 0, 900, 600);
    paintButtonWithShadow(340, 250, 2, RGB(204, 51, 0), RGB(255, 153, 51), RGB(255, 153, 51), " ");
    txSetColor(TX_BLACK);
    txTextOut(345, 260, line1);
    txTextOut(355, 280, line2);
    txTextOut(365, 300, line3);
    txTextOut(385, 320, line4);
    txSetFillColor(RGB(255, 102, 255));
}

/*!
	Function for drawing a slide with a conversation of the main character.
	\param[in] line1 The text of the first line in the dialogue.
	\param[in] line2 The text of the second line in the dialogue.
	\param[in] line3 The text of the third line in the dialogue.
	\param[in] line4 The text of the fourth line in the dialogue.
*/
void paintMyDialogueWithSomeone(char* line1, char* line2, char* line3, char* line4)
{
    txSetFillColor(RGB(255, 102, 255));
    txRectangle(0, 0, 900, 600);
    txSetColor(RGB(204, 51, 0));
    txSetFillColor(RGB(255, 153, 51));
    txLine(340, 250, 550, 250);
    txLine(550, 250, 550, 350);
    txLine(550, 350, 360, 350);
    txLine(360, 350, 360, 280);
    txLine(360, 280, 340, 250);
    txFloodFill(350, 255);
    txSetColor(TX_BLACK);
    txTextOut(370, 260, line1);
    txTextOut(370, 280, line2);
    txTextOut(370, 300, line3);
    txTextOut(370, 320, line4);
    txSetFillColor(RGB(255, 102, 255));
}

/*!
	Function for drawing a slide in which someone speaks to the main character.
	\param[in] line1 The text of the first line in the dialogue.
	\param[in] line2 The text of the second line in the dialogue.
	\param[in] line3 The text of the third line in the dialogue.
	\param[in] line4 The text of the fourth line in the dialogue.
*/
void paintSomeoneDialog(char* line1, char* line2, char* line3, char* line4)
{
    txSetFillColor(RGB(255, 102, 255));
    txRectangle(0, 0, 900, 600);
    txSetColor(RGB(204, 51, 0));
    txSetFillColor(RGB(255, 153, 51));
    txLine(340, 250, 550, 250);
    txLine(550, 250, 500, 280);
    txLine(500, 280, 500, 350);
    txLine(500, 350, 340, 350);
    txLine(340, 350, 340, 250);
    txFloodFill(345, 255);
    txSetColor(TX_BLACK);
    txTextOut(350, 260, line1);
    txTextOut(350, 280, line2);
    txTextOut(350, 300, line3);
    txTextOut(350, 320, line4);
    txSetFillColor(RGB(255, 102, 255));
}

/*!
	Function for drawing a slide with a choice that may affect the story.
	\param[in] line1_1 The text of the first line in the dialogue with a question of choice.
	\param[in] line1_2 The text of the second line in the dialogue with a question of choice.
	\param[in] line1_3 The text of the third line in the dialogue with a question of choice.
	\param[in] line1_4 The text of the fourth line in the dialogue with a question of choice.
	\param[in] line2_1 The text of the first line in the first proposed choice.
	\param[in] line2_2 The text of the second line in the first proposed choice.
	\param[in] line2_3 The text of the third line in the first proposed choice.
	\param[in] line2_4 The text of the fourth line in the first proposed choice.
	\param[in] line3_1 The text of the first line in the second proposed choice.
	\param[in] line3_2 The text of the second line in the second proposed choice.
	\param[in] line3_3 The text of the third line in the second proposed choice.
	\param[in] line3_4 The text of the fourth line in the second proposed choice.
*/
void paintChoiceMe(char* line1_1, char* line1_2, char* line1_3, char* line1_4, char* line2_1, char* line2_2, char* line2_3, char* line2_4, char* line3_1,
                 char* line3_2, char* line3_3, char* line3_4)
{
    txSetFillColor(RGB(255, 102, 255));
    txRectangle(0, 0, 900, 600);
    txSetColor(RGB(204, 51, 0));
    txSetFillColor(RGB(255, 153, 51));
    txLine(340, 250, 550, 250);
    txLine(550, 250, 550, 350);
    txLine(550, 350, 360, 350);
    txLine(360, 350, 360, 280);
    txLine(360, 280, 340, 250);
    txFloodFill(350, 255);
    txSetColor(TX_BLACK);
    txTextOut(370, 260, line1_1);
    txTextOut(370, 280, line1_2);
    txTextOut(370, 300, line1_3);
    txTextOut(370, 320, line1_4);
    txSetColor(TX_WHITE);
    paintColorChangingParallelogramButton(340, 360, 2, RGB(102, 0, 51), RGB(102, 0, 51), RGB(153, 0, 102), RGB(153, 0, 102), RGB(255, 255, 255), RGB(255, 255, 255), " ");
    txTextOut(345, 370, line2_1);
    txTextOut(340, 380, line2_2);
    txTextOut(335, 390, line2_3);
    txTextOut(330, 400, line2_4);
    paintColorChangingParallelogramButton(340, 470, 2, RGB(102, 0, 51), RGB(102, 0, 51), RGB(153, 0, 102), RGB(153, 0, 102), RGB(255, 255, 255), RGB(255, 255, 255), " ");
    txTextOut(345, 480, line3_1);
    txTextOut(340, 490, line3_2);
    txTextOut(335, 500, line3_3);
    txTextOut(330, 510, line3_4);
    RECT areaChoice1 = {320, 360, 560, 460};
    RECT areaChoice2 = {320, 470, 560, 570};
    txSetFillColor(RGB(255, 102, 255));
}
