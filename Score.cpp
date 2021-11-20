#include "Score.h"

Score::Score()
{
    font.loadFromFile("Font/Notalot60.ttf");
}

bool Score::sortDes(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b)
{
    return (a > b);
}

void Score::clearScore()
{
    for (int i = 0; i < 5; i++)
    {
        scorePair.erase(scorePair.begin());
    }
}

void Score::readFile()
{
    fp = fopen("./Score/Score.txt", "r");
    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %d\n", &temp, &score[i]);
        name[i] = temp;
        scorePair.push_back(make_pair(score[i], name[i]));
    }
    std::sort(scorePair.begin(), scorePair.end(), sortDes);
    fclose(fp);
}

void Score::writeFile(std::string playerName, int playerScore)
{
    readFile();
    scorePair.push_back(make_pair(playerScore, playerName));
    std::sort(scorePair.begin(), scorePair.end(),sortDes);

    fp = fopen("./Score/Score.txt", "w");

    for (int i = 0; i < 5; i++)
    {
        strcpy(temp, scorePair[i].second.c_str());
        fprintf(fp, "%s %d\n", temp, scorePair[i].first);
    }

    fclose(fp);
}
