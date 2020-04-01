#include <string>
#include "TXLib.h"
//#include "special.h"
#include "ButtonsWithText.h"
using namespace std;

void clearConsole();
void paintStartPage(char* text);
void paintStar(int x, int y, int sizeForStar);
void paintHomePage();
void paintNarrative(char* line1, char* line2, char* line3, char* line4);
void paintMyDialogue(char* line1, char* line2, char* line3, char* line4);
void paintOtherDialog(char*line1, char* line2, char* line3, char* line4);
void paintChoice(int x, int y, char*line1, char* line2, char* line3, char* line4);
void paintName(int x, int y, const char* nameCharacter);

int main()
{
    txCreateWindow(900, 600);

    enum Condition {Begin=0, MainSlide, Slide1, Slide2, Slide3, Slide4, Slide5, Slide6, Slide7, Slide8, Slide9, Slide10, Slide11, Slide12, Slide13, Slide14, Slide15, Slide16, End, Star};
    Condition cond = Begin;

    int starY=300;
    int starSize=1;
    string nameTemp;

    HDC mainCharacter  = txLoadImage ("mainCharacter.bmp");
    HDC mother  = txLoadImage ("Mother.bmp");

    cout << "Enter the name of your main character.\n";
    cin >> nameTemp;
    cout << "Your name is\n" << nameTemp;
    txSleep(100);
    clearConsole();
    const char* name = nameTemp.c_str();
    paintHomePage();
    txSetColor(RGB(204, 204, 204));
    txTextOut(410, 500, "Click on the screen to continue ...");
    RECT areaScreen = {0, 0, 900, 600};

    while(txMouseButtons() != 3)
    {
        if((txMouseButtons() & 1) && (cond == Begin))
        {
            if (In (txMousePos(), areaScreen))
            {
                txClear();
                cond=MainSlide;
                txSleep(100);
            }
        }

        while(cond == MainSlide)
        {
            txBegin();
            txClear();
            paintHomePage();
            txSetColor(RGB(204, 204, 204));
            paintStartPage("THE GOLDEN ACADEMY");
            txSleep(700);
            paintStar(45, 19, 1);
            paintStar(520, 5, 1);
            paintStar(100, 78, 1);
            paintStar(850, 103, 1);
            paintStar(108, 189, 1);
            paintStar(15, 430, 1);
            paintStar(781, 430, 1);
            paintStar(880, 189, 1);
            paintStar(237, 390, 1);
            paintStar(379, 148, 1);
            paintStar(521, 148, 1);
            paintStar(663, 390, 1);
            txSleep(400);
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide1;
                    txSleep(300);
                }
            }
            txEnd();
        }

        while(cond == Slide1)
        {
            txBegin();
            paintHomePage();
            paintNarrative("You opened your eyes", "and looked at watch.", "*07.48*", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            paintName(50, 470, name);
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide2;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide2)
        {
            txBegin();
            paintHomePage();
            paintMyDialogue("*What should I do?*", " ", " ", " ");
            paintChoice(340, 360, "Get out of bed", "and tidy", "yourself up.", " ");
            paintChoice(340, 470, "Lie down a little", "more in bed.", " ", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            paintName(50, 470, name);
            RECT areaGet = {320, 360, 560, 460};
            RECT areaSleep = {320, 470, 560, 570};
            if((txMouseButtons() & 1) && (cond == Slide2))
            {
                if (In (txMousePos(), areaGet))
                {
                    txClear();
                    cond=Slide3;
                    txSleep(100);
                }
            }
            if((txMouseButtons() & 1) && (cond == Slide2))
            {
                if (In (txMousePos(), areaSleep))
                {
                    txClear();
                    cond=Slide6;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide3)
        {
            txBegin();
            paintHomePage();
            paintNarrative("You left the room and", "went to wash. In the", "hallway you met mom.", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            paintName(50, 470, name);
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide4;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide4)
        {
            txBegin();
            paintHomePage();
            paintOtherDialog("Oh, you already", "got up.", "Good morning,", "my dear!");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            txBitBlt(txDC(), 600, 0, 300, 600, mother, 0, 0);
            paintName(50, 470, name);
            paintName(650, 470, "Mother");
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide5;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide5)
        {
            txBegin();
            paintHomePage();
            paintMyDialogue("Yes.", "Good morning mommy!", " ", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            txBitBlt(txDC(), 600, 0, 300, 600, mother, 0, 0);
            paintName(50, 470, name);
            paintName(650, 470, "Mother");
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide10;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide6)
        {
            txBegin();
            paintHomePage();
            paintNarrative("You lay in bed and", "thought about the", "upcoming trip.", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            paintName(50, 470, name);
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide7;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide7)
        {
            txBegin();
            paintHomePage();
            paintNarrative("There was a knock", "on the door and", "my mother went", "into the room.");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            paintName(50, 470, name);
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide8;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide8)
        {
            txBegin();
            paintHomePage();
            paintOtherDialog("Good morning,", "daughter! It’s time", "for you to get up.", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            txBitBlt(txDC(), 600, 0, 300, 600, mother, 0, 0);
            paintName(50, 470, name);
            paintName(650, 470, "Mother");
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide9;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond==Slide9)
        {
            txBegin();
            paintHomePage();
            paintMyDialogue("Good morning, Mom!", "Yes, I get up already.", " ", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            txBitBlt(txDC(), 600, 0, 300, 600, mother, 0, 0);
            paintName(50, 470, name);
            paintName(650, 470, "Mother");
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide10;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide10)
        {
            txBegin();
            paintHomePage();
            paintOtherDialog("Do you remember ", "what day it is?", " ", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            txBitBlt(txDC(), 600, 0, 300, 600, mother, 0, 0);
            paintName(50, 470, name);
            paintName(650, 470, "Mother");
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide11;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide11)
        {
            txBegin();
            paintHomePage();
            paintMyDialogue("Of course!", "Today I’m going to enter", "the most elite academy", "in our country.");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            txBitBlt(txDC(), 600, 0, 300, 600, mother, 0, 0);
            paintName(50, 470, name);
            paintName(650, 470, "Mother");
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide12;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide12)
        {
            txBegin();
            paintHomePage();
            paintOtherDialog("I'm sure you will", "do it.", "Good luck dear!", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            txBitBlt(txDC(), 600, 0, 300, 600, mother, 0, 0);
            paintName(50, 470, name);
            paintName(650, 470, "Mother");
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide13;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide13)
        {
            txBegin();
            paintHomePage();
            paintMyDialogue("Thanks for ", "the support,", "mommy!", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            txBitBlt(txDC(), 600, 0, 300, 600, mother, 0, 0);
            paintName(50, 470, name);
            paintName(650, 470, "Mother");
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide14;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide14)
        {
            txBegin();
            paintHomePage();
            paintNarrative("You washed and", "dressed.", " ", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            paintName(50, 470, name);
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide15;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide15)
        {
            txBegin();
            paintHomePage();
            paintNarrative("A taxi drove up", "to the house.", " ", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            paintName(50, 470, name);
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Slide16;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Slide16)
        {
            txBegin();
            paintHomePage();
            paintNarrative("You took the suitcases,", "said goodbye to your mom", "and went to the Academy.", " ");
            txBitBlt(txDC(), 0, 0, 300, 600, mainCharacter, 0, 0);
            paintName(50, 470, name);
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=End;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == End)
        {
            txBegin();
            txClear();
            paintHomePage();
            txSetColor(RGB(204, 204, 204));
            paintStartPage("  *THE END*");
            txSleep(700);
            paintStar(45, 19, 1);
            paintStar(520, 5, 1);
            paintStar(100, 78, 1);
            paintStar(850, 103, 1);
            paintStar(108, 189, 1);
            paintStar(15, 430, 1);
            paintStar(781, 430, 1);
            paintStar(880, 189, 1);
            paintStar(237, 390, 1);
            paintStar(379, 148, 1);
            paintStar(521, 148, 1);
            paintStar(663, 390, 1);
            txDeleteDC (mainCharacter);
            txDeleteDC (mother);
            txSleep(700);
            if(txMouseButtons() & 1)
            {
                if (In (txMousePos(), areaScreen))
                {
                    txClear();
                    cond=Star;
                    txSleep(100);
                }
            }
            txEnd();
        }

        while(cond == Star)
        {
            txBegin();
            paintHomePage();
            while(starSize<=50)
            {
                txBegin();
                paintStar(450, starY, starSize);
                txSleep(50);
                starY=starY-11;
                starSize=starSize+2;
                txEnd();
            }
            txSetFillColour(RGB(255, 215, 0));
            txRectangle(0, 0, 900, 600);
            txSetColor(RGB(26, 0, 4));
            txTextOut(400, 295, "To be continued...");
            txEnd();
        }
    }
    return 0;
}

void clearConsole()
{
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

void paintStartPage(char* text)
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

void paintStar(int x, int y, int sizeForStar)
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

void paintHomePage()
{
    txSetFillColor(RGB(255, 102, 255));
    txRectangle(0, 0, 900, 600);
}

void paintNarrative(char* line1, char* line2, char* line3, char* line4)
{
    paintButtonWithShadow(340, 250, 2, RGB(204, 51, 0), RGB(255, 153, 51), RGB(255, 153, 51), " ");
    txSetColor(TX_BLACK);
    txTextOut(345, 260, line1);
    txTextOut(355, 280, line2);
    txTextOut(365, 300, line3);
    txTextOut(385, 320, line4);
    txSetFillColor(RGB(255, 102, 255));
}

void paintMyDialogue(char* line1, char* line2, char* line3, char* line4)
{
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

void paintOtherDialog(char* line1, char* line2, char* line3, char* line4)
{
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

void paintChoice(int x, int y, char* line1, char* line2, char* line3, char* line4)
{
    txSetColor(TX_WHITE);
    paintColorChangingParallelogramButton(x, y, 2, RGB(102, 0, 51), RGB(102, 0, 51), RGB(153, 0, 102), RGB(153, 0, 102), RGB(255, 255, 255), RGB(255, 255, 255), " ");
    txTextOut(x+5, y+10, line1);
    txTextOut(x, y+20, line2);
    txTextOut(x-5, y+30, line3);
    txTextOut(x-10, y+40, line4);
    txSetFillColor(RGB(255, 102, 255));
}

void paintName(int x, int y, const char* nameCharacter)
{
    paintBeautifulButtonEllipse(x, y, 1, RGB(102, 51, 51), RGB(255, 204, 51), RGB(0, 0, 0), nameCharacter);
    txSetFillColor(RGB(255, 102, 255));
}
