#include "Score.h"

Score::Score()
{
    font.loadFromFile("Font/Notalot60.ttf");
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
        leaderScore[i].setPosition(view.getCenter().x + 300, view.getCenter().y - 100);
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
        scorePair.push_back(make_pair(score[i], name[i]));
    }
    fclose(fp);
}

void Score::writeFile(std::string playerName, int playerScore)
{
    getName();

    name[5] = playerName;
    score[5] = playerScore;
    strcpy(temp, playerName.c_str());
    scorePair.push_back(make_pair(score[5], name[5]));
    std::sort(scorePair.begin(), scorePair.end());
    fclose(fp);
    
    fp = fopen("./Score/Score.txt", "w");

    for (int i = 1; i <= 5; i++)
    {
        std::cout << scorePair[0].second.c_str() << std::endl;
        strcpy(temp, scorePair[i].second.c_str());
        fprintf(fp, "%s %d\n", temp, scorePair[i].first);
    }

    fclose(fp);
}

void Score::render(sf::RenderTarget& window, sf::View view)
{
    getName();
    setScoreBoard();
    for (int i = 0; i < 5; i++)
    {
        leaderName[i].setPosition(view.getCenter().x - 300, view.getCenter().y + 50 - i * 50);
        leaderScore[i].setPosition(view.getCenter().x + 200, view.getCenter().y + 50 - i * 50);
        window.draw(leaderName[i]);
        window.draw(leaderScore[i]);
    }
}
