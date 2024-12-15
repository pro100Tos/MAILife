#include <SFML/Graphics.hpp>

using namespace sf;

void draw_table(RenderWindow &window) {
    VertexArray rows(Lines, 30);

    for (int i = 0, y = 0; i < 30; i += 2, y += 40) {
        rows[i].position = Vector2f(0, y);
        rows[i + 1].position = Vector2f(1000, y);
    }

    VertexArray cols(Lines, 50);

    for (int i = 0, x = 0; i < 50; i += 2, x += 40) {
        cols[i].position = Vector2f(x, 0);
        cols[i + 1].position = Vector2f(x, 600);
    }

    window.draw(rows);
    window.draw(cols);

    window.display();
}

void renderingThread(RenderWindow* window)
{
    // activate the window's context
    window->setActive(true);

    // the rendering loop
    while (window->isOpen())
    {
        // draw...

        // end the current frame
        window->display();
    }
}

int main()
{
    RenderWindow window(VideoMode(1000, 600), "Game");
    window.setActive(false);
    Thread thread(&renderingThread, &window);
    thread.launch();

    window.clear(Color::Black);
    window.display();
    draw_table(window);

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {

            switch (event.type)
            {
                case Event::Closed:
                    window.close();

                default:
                    break;
            }
        }
    }

    return 0;
}