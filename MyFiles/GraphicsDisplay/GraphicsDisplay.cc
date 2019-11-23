#include "subject.h"
#include "grid.h"
#include "GraphicsDisplay.h"
#include <string>
using namespace std;

/*
class GraphicsDisplay: public Observer<Info, State> {
    Xwindow xw;
    const int gridSize;
    void drawCell(int r, int c, Colour colour);

public:
    GraphicsDisplay(int n);
    void notify(Subject<Info, State> &whoNotified) override;

};
*/
void GraphicsDisplay::drawCell(int r, int c, int colour) {
    xw.fillRectangle(r * 400 / size + 50, c * 400 / size + 50, 400 / size - 5, 400 / size - 5, colour);
}

GraphicsDisplay::GraphicsDisplay(int n) : size{n} {
    // Fill in background colour
    xw.fillRectangle(0, 0, 500, 500, 4);

    // Add Welcome Text
    xw.drawString(195, 25, "Welcome to Reversii");

    // Fill in cell colour
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; c++) {
            drawCell(r, c, 5);
            }
        }

    // Print cell coordinates
    if (n <= 12){
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; c++) {
                
                // prints out coordinates
                if (r >= 0 || c >= 0) {
                    string coord = to_string(c) + "," + to_string(r);
                    xw.drawString(r * 400 / size + 50 + 1 , c * 400 / size + 50 + 400 / size - 5 -1, coord);
                    // xw.drawString(c * 400 / size + 50, r * 400 / size + 50, coord);
                }
            }
        }
    }
}

// Observer Pattern
void GraphicsDisplay::notify(Subject<Info, State> &whoNotified) {
    int roww = whoNotified.getInfo().row;
    int coll = whoNotified.getInfo().col;
    Colour colourr = whoNotified.getInfo().colour;

    if (colourr == Colour::Black){
        drawCell(coll,roww,1);
        xw.fillRectangle(400, 450, 100, 50, 4);
        xw.drawString(400,490, "White's Turn");
    }
    if (colourr == Colour::White){
        drawCell(coll,roww,0);
        xw.fillRectangle(400, 450, 100, 50, 4);
        xw.drawString(400,490, "Black's Turn");
    }
}


