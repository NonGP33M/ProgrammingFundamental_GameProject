#include "Score.h"

Score::Score()
{
    font.loadFromFile("Font/Retro Gaming.ttf");
    getName();
}

void Score::setScoreBoard()
{
    for (int i = 0; i < 5; i++)
    {
        leaderName[i].setFont(font);
        leaderName[i].setCharacterSize(36);
        leaderName[i].setString(name[i]);
        leaderName[i].setFillColor(sf::Color::White);

        leaderScore[i].setFont(font);
        leaderScore[i].setCharacterSize(36);
        leaderScore[i].setString(std::to_string(score[i]));
        leaderScore[i].setFillColor(sf::Color::White);
        leaderScore[i].setPosition(view.getCenter().x + 300, view.getCenter().y - 100 + i * 50);
    }
}

void Score::getName()
{
	fp = fopen("./Score/Score.txt", "r");
    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s", &temp);
        name[i] = temp;
        fscanf(fp, "%d", &score[i]);
    }
    fclose(fp);
}

void Score::render(sf::RenderTarget& window, sf::View view)
{
    setScoreBoard();
    for (int i = 0; i < 5; i++)
    {
        leaderName[i].setPosition(view.getCenter().x - 300, view.getCenter().y - 150 + i * 50);
        leaderScore[i].setPosition(view.getCenter().x + 200, view.getCenter().y - 150 + i * 50);
        window.draw(leaderName[i]);
        window.draw(leaderScore[i]);
    }
}
