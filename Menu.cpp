#include "Menu.h"

Menu::Menu(sf::RenderWindow* window, sf::View view)
{
	font.loadFromFile("Font/Notalot60.ttf");
	buttonTexture.loadFromFile("Texture/Button.png");
	mediumButtonTexture.loadFromFile("Texture/Button_2.png");
	shortButtonTexture.loadFromFile("Texture/Button_3.png");
	smallButtonTexture.loadFromFile("Texture/Button_4.png");
	nameFrameTexture.loadFromFile("Texture/NameFrame.png");
	frameTexture.loadFromFile("Texture/Leaderboard.png");
	backgroundTexture.loadFromFile("Texture/MainBackground.png");
	helpTexture.loadFromFile("Texture/Info.png");

	buttonTextSize = 30;

	greyScreen.setSize({ 1440.f, 900.f });
	greyScreen.setFillColor(sf::Color(0.f, 0.f, 0.f, 153.f));
	greyScreen.setOrigin(greyScreen.getSize().x / 2,
		greyScreen.getSize().y / 2);

	//MAIN_MENU
	title.setFont(font);
	title.setCharacterSize(240);
	title.setString("MOOYIMM");
	title.setFillColor(sf::Color::White);
	title.setOutlineThickness(5.f);
	title.setOrigin(title.getLocalBounds().width / 2,
		title.getLocalBounds().height);

	myName.setFont(font);
	myName.setCharacterSize(20);
	myName.setString("64010683  Phumrapee  Sinkeeree");
	myName.setFillColor(sf::Color::White);
	myName.setOrigin(myName.getLocalBounds().width / 2,
		myName.getLocalBounds().height);

	mainBackground.setSize({ 1440.f, 900.f });
	mainBackground.setTexture(&backgroundTexture);
	mainBackground.setOrigin(mainBackground.getLocalBounds().width / 2,
		mainBackground.getLocalBounds().height / 2);

	playButtonText.setFont(font);
	playButtonText.setCharacterSize(buttonTextSize);
	playButtonText.setString("PLAY");
	playButtonText.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));

	leaderBoardButtonText.setFont(font);
	leaderBoardButtonText.setCharacterSize(buttonTextSize);
	leaderBoardButtonText.setString("LEADERBOARD");
	leaderBoardButtonText.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));

	exitButtonText.setFont(font);
	exitButtonText.setCharacterSize(buttonTextSize);
	exitButtonText.setString("EXIT");
	exitButtonText.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));

	helpButtonText.setFont(font);
	helpButtonText.setCharacterSize(36);
	helpButtonText.setString("?");
	helpButtonText.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));

	playButton.setSize(buttonSize);
	playButton.setTexture(&buttonTexture);
	playButton.setOrigin(playButton.getLocalBounds().width / 2,
		playButton.getLocalBounds().height / 2);

	leaderBoardButton.setSize(buttonSize);
	leaderBoardButton.setTexture(&buttonTexture);
	leaderBoardButton.setOrigin(leaderBoardButton.getLocalBounds().width / 2,
		leaderBoardButton.getLocalBounds().height / 2);

	exitButton.setSize(buttonSize);
	exitButton.setTexture(&buttonTexture);
	exitButton.setOrigin(exitButton.getLocalBounds().width / 2,
		exitButton.getLocalBounds().height / 2);

	helpButton.setSize({ 80.f,80.f });
	helpButton.setTexture(&smallButtonTexture);
	helpButton.setOrigin(helpButton.getLocalBounds().width / 2,
		helpButton.getLocalBounds().height / 2);

	//LEADERBOARD_MENU
	leaderBoardTitle.setFont(font);
	leaderBoardTitle.setCharacterSize(90);
	leaderBoardTitle.setString("LEADERBOARD");
	leaderBoardTitle.setFillColor(sf::Color::White);
	leaderBoardTitle.setOrigin(leaderBoardTitle.getLocalBounds().width / 2,
		leaderBoardTitle.getLocalBounds().height / 2);

	leaderboardBackground.setSize({ 1440.f,900.f });
	leaderboardBackground.setTexture(&backgroundTexture);

	frame.setTexture(&frameTexture);
	frame.setSize({ 800.f, 400.f });
	frame.setOrigin(frame.getLocalBounds().width / 2,
		frame.getLocalBounds().top);

	backButtonText.setFont(font);
	backButtonText.setCharacterSize(buttonTextSize);
	backButtonText.setString("Back");
	backButtonText.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));

	backButton.setTexture(&shortButtonTexture);
	backButton.setSize({ 150.f, 75.f });
	backButton.setOrigin(backButton.getLocalBounds().width / 2,
		backButton.getLocalBounds().height / 2);

	//PAUSE_MENU
	resumeButtonText.setFont(font);
	resumeButtonText.setCharacterSize(buttonTextSize);
	resumeButtonText.setString("Resume");
	resumeButtonText.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));

	mainMenuButtonText.setFont(font);
	mainMenuButtonText.setCharacterSize(buttonTextSize);
	mainMenuButtonText.setString("Main menu");
	mainMenuButtonText.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));

	resumeButton.setSize(buttonSize);
	resumeButton.setTexture(&buttonTexture);
	resumeButton.setOrigin(resumeButton.getLocalBounds().width / 2,
		resumeButton.getLocalBounds().height / 2);

	mainMenuButton.setSize(buttonSize);
	mainMenuButton.setTexture(&buttonTexture);
	mainMenuButton.setOrigin(mainMenuButton.getLocalBounds().width / 2,
		mainMenuButton.getLocalBounds().height / 2);


	//GAMEOVER
	gameOverTitle.setFont(font);
	gameOverTitle.setCharacterSize(160);
	gameOverTitle.setString("GAME OVER");
	gameOverTitle.setLetterSpacing(3);
	gameOverTitle.setFillColor(sf::Color::White);
	gameOverTitle.setOrigin(gameOverTitle.getLocalBounds().width / 2,
		gameOverTitle.getLocalBounds().height);

	tryAgainButtonText.setFont(font);
	tryAgainButtonText.setCharacterSize(buttonTextSize);
	tryAgainButtonText.setString("Try again");
	tryAgainButtonText.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));


	tryAgainButton.setSize(buttonSize);
	tryAgainButton.setTexture(&buttonTexture);
	tryAgainButton.setOrigin(tryAgainButton.getLocalBounds().width / 2,
		tryAgainButton.getLocalBounds().height / 2);

	//NAME
	nameFrame.setSize({ 800.f, 250.f });
	nameFrame.setOrigin(nameFrame.getLocalBounds().width / 2,
		nameFrame.getLocalBounds().height / 2);
	nameFrame.setTexture(&nameFrameTexture);

	confirmButton.setSize({ 275.f, 75.f });
	confirmButton.setTexture(&mediumButtonTexture);

	confirmButtonText.setFont(font);
	confirmButtonText.setCharacterSize(buttonTextSize);
	confirmButtonText.setString("Confirm");
	confirmButtonText.setFillColor(sf::Color::White);

	backButtonText_2.setFont(font);
	backButtonText_2.setCharacterSize(buttonTextSize);
	backButtonText_2.setString("Back");
	backButtonText_2.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));

	backButton_2.setSize({ 275.f, 75.f });
	backButton_2.setTexture(&mediumButtonTexture);


	name.setFont(font);
	name.setCharacterSize(buttonTextSize);
	name.setFillColor(sf::Color::White);

	cursor.setFont(font);
	cursor.setCharacterSize(buttonTextSize);
	cursor.setString("  |");

	//INFO
	helpFrame.setSize({ 1152.f,720.f });
	helpFrame.setTexture(&helpTexture);
	helpFrame.setOrigin(helpFrame.getLocalBounds().width / 2,
		helpFrame.getLocalBounds().height / 2);
	this->window = window;
	this->view = view;
}

void Menu::updateScore()
{
	score.writeFile(enteredName, playerScore);
}

void Menu::pauseCheck()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		states = PAUSE;
}

void Menu::mainMenuUpdate()
{
	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);
	if (playButton.getGlobalBounds().contains(screenPos))
	{
		playButtonText.setCharacterSize(buttonTextSize * 1.5);
		playButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3f)
		{
			states = NAME;
			enteredName = "";
			transitionDebounce = 0;
		}
	}
	else
	{
		playButtonText.setCharacterSize(buttonTextSize);
		playButton.setScale(1.f, 1.f);
	}

	if (leaderBoardButton.getGlobalBounds().contains(screenPos))
	{
		leaderBoardButtonText.setCharacterSize(buttonTextSize * 1.5);
		leaderBoardButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3f)
		{
			states = LEADERBOARD;
			transitionDebounce = 0;
		}
	}
	else
	{
		leaderBoardButtonText.setCharacterSize(buttonTextSize);
		leaderBoardButton.setScale(1.f, 1.f);
	}

	if (exitButton.getGlobalBounds().contains(screenPos))
	{
		exitButtonText.setCharacterSize(buttonTextSize * 1.5);
		exitButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3f)
			window->close();
	}
	else
	{
		exitButtonText.setCharacterSize(buttonTextSize);
		exitButton.setScale(1.f, 1.f);
	}

	if (helpButton.getGlobalBounds().contains(screenPos))
	{
		helpButtonText.setCharacterSize(36 * 1.5);
		helpButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3f)
		{
			states = HELP;
			transitionDebounce = 0;
		}
	}
	else
	{
		helpButtonText.setCharacterSize(36);
		helpButton.setScale(1.f, 1.f);
	}

	playButtonText.setOrigin(playButtonText.getLocalBounds().width / 2,
		playButtonText.getLocalBounds().height - 8);
	leaderBoardButtonText.setOrigin(leaderBoardButtonText.getLocalBounds().width / 2,
		leaderBoardButtonText.getLocalBounds().height - 8);
	exitButtonText.setOrigin(exitButtonText.getLocalBounds().width / 2,
		exitButtonText.getLocalBounds().height - 8);
	helpButtonText.setOrigin(helpButtonText.getLocalBounds().width / 2,
		helpButtonText.getLocalBounds().height - 8);

	mainBackground.setPosition(view.getCenter());
	title.setPosition(view.getCenter().x, view.getCenter().y - 50);
	myName.setPosition(view.getCenter().x + 550, view.getCenter().y + 440);

	playButton.setPosition(view.getCenter().x, view.getCenter().y + 100);
	leaderBoardButton.setPosition(view.getCenter().x, view.getCenter().y + 200);
	exitButton.setPosition(view.getCenter().x, view.getCenter().y + 300);
	helpButton.setPosition(view.getCenter().x - 670, view.getCenter().y + 400);

	playButtonText.setPosition(playButton.getPosition());
	leaderBoardButtonText.setPosition(leaderBoardButton.getPosition());
	exitButtonText.setPosition(exitButton.getPosition());
	helpButtonText.setPosition(helpButton.getPosition());


}

void Menu::mainMenuRender()
{
	window->clear();
	window->setView(view);

	window->draw(mainBackground);
	window->draw(title);
	window->draw(myName);

	window->draw(playButton);
	window->draw(leaderBoardButton);
	window->draw(exitButton);
	window->draw(helpButton);

	window->draw(playButtonText);
	window->draw(leaderBoardButtonText);
	window->draw(exitButtonText);
	window->draw(helpButtonText);

	window->display();
}

void Menu::leaderBoardMenuUpdate()
{
	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	leaderBoardTitle.setPosition(view.getCenter().x, view.getCenter().y - 300);

	frame.setPosition(view.getCenter().x, view.getCenter().y - 220);

	if (backButton.getGlobalBounds().contains(screenPos))
	{
		backButtonText.setCharacterSize(buttonTextSize * 1.5);
		backButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3)
		{
			states = MENU;
			transitionDebounce = 0;
		}
	}
	else
	{
		backButtonText.setCharacterSize(buttonTextSize);
		backButton.setScale(1.f, 1.f);
	}

	leaderboardBackground.setOrigin(leaderboardBackground.getLocalBounds().width / 2,
		leaderboardBackground.getLocalBounds().height / 2);
	leaderboardBackground.setPosition(view.getCenter());

	backButtonText.setOrigin(backButtonText.getLocalBounds().width / 2,
		backButtonText.getLocalBounds().height - 8);

	backButton.setPosition(view.getCenter().x, view.getCenter().y + 250);
	backButtonText.setPosition(backButton.getPosition());

	score.readFile();
	for (int i = 0; i < 5; i++)
	{
		showingName[i].setFont(font);
		showingName[i].setCharacterSize(36);
		showingName[i].setString(score.getName()[i].second);
		showingName[i].setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));

		showingScore[i].setFont(font);
		showingScore[i].setCharacterSize(36);
		showingScore[i].setString(std::to_string(score.getName()[i].first));
		showingScore[i].setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));

		showingName[i].setPosition(view.getCenter().x - 300, view.getCenter().y - 180 + i * 50);
		showingScore[i].setPosition(view.getCenter().x + 200, view.getCenter().y - 180 + i * 50);
	}
	score.clearScore();
}

void Menu::leaderBoardMenuRender()
{
	window->clear();

	window->setView(view);

	window->draw(leaderboardBackground);
	window->draw(leaderBoardTitle);
	window->draw(frame);
	window->draw(backButton);
	window->draw(backButtonText);

	for (int i = 0; i < 5; i++)
	{
		window->draw(showingName[i]);
		window->draw(showingScore[i]);
	}

	window->display();
}

void Menu::pauseMenuUpdate()
{
	greyScreen.setPosition(view.getCenter());

	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	if (resumeButton.getGlobalBounds().contains(screenPos))
	{
		resumeButtonText.setCharacterSize(buttonTextSize * 1.5);
		resumeButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3f)
		{
			states = PLAY;
			transitionDebounce = 0;
		}
	}
	else
	{
		resumeButtonText.setCharacterSize(buttonTextSize);
		resumeButton.setScale(1.f, 1.f);
	}

	if (mainMenuButton.getGlobalBounds().contains(screenPos))
	{
		mainMenuButtonText.setCharacterSize(buttonTextSize * 1.5);
		mainMenuButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3f)
		{
			states = MENU;
			updateScore();
			score.clearScore();
			transitionDebounce = 0;
		}
	}
	else
	{
		mainMenuButtonText.setCharacterSize(buttonTextSize);
		mainMenuButton.setScale(1.f, 1.f);
	}

	resumeButtonText.setOrigin(resumeButtonText.getLocalBounds().width / 2,
		resumeButtonText.getLocalBounds().height / 2 + 8);
	mainMenuButtonText.setOrigin(mainMenuButtonText.getLocalBounds().width / 2,
		mainMenuButtonText.getLocalBounds().height / 2 + 8);

	resumeButton.setPosition(view.getCenter().x, view.getCenter().y - 50);
	mainMenuButton.setPosition(view.getCenter().x, view.getCenter().y + 50);

	resumeButtonText.setPosition(resumeButton.getPosition());
	mainMenuButtonText.setPosition(mainMenuButton.getPosition());
}

void Menu::pauseMenuRender()
{
	window->setView(view);

	window->draw(greyScreen);
	window->draw(resumeButton);
	window->draw(mainMenuButton);
	window->draw(mainMenuButtonText);
	window->draw(resumeButtonText);


	window->display();
}

void Menu::gameOverMenuUpdate()
{
	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	if (tryAgainButton.getGlobalBounds().contains(screenPos))
	{
		tryAgainButtonText.setCharacterSize(buttonTextSize * 1.5);
		tryAgainButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3f)
		{
			tryAgainClick = true;
			updateScore();
			score.clearScore();
			transitionDebounce = 0;
		}
	}
	else
	{
		tryAgainButtonText.setCharacterSize(buttonTextSize);
		tryAgainButton.setScale(1.f, 1.f);
	}

	if (mainMenuButton.getGlobalBounds().contains(screenPos))
	{
		mainMenuButtonText.setCharacterSize(buttonTextSize * 1.5);
		mainMenuButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3f)
		{
			states = MENU;
			updateScore();
			score.clearScore();
			transitionDebounce = 0;
		}
	}
	else
	{
		mainMenuButtonText.setCharacterSize(buttonTextSize);
		mainMenuButton.setScale(1.f, 1.f);
	}

	mainMenuButtonText.setOrigin(mainMenuButtonText.getLocalBounds().width / 2,
		mainMenuButtonText.getLocalBounds().height / 2 + 8);
	tryAgainButtonText.setOrigin(tryAgainButtonText.getLocalBounds().width / 2,
		tryAgainButtonText.getLocalBounds().height / 2 + 8);

	gameOverTitle.setPosition(view.getCenter().x, view.getCenter().y);

	greyScreen.setPosition(view.getCenter().x, view.getCenter().y);

	tryAgainButton.setPosition(view.getCenter().x - 200, view.getCenter().y + 100);
	mainMenuButton.setPosition(view.getCenter().x + 200, view.getCenter().y + 100);

	tryAgainButtonText.setPosition(tryAgainButton.getPosition());
	mainMenuButtonText.setPosition(mainMenuButton.getPosition());
}

void Menu::gameOverMenuRender()
{
	window->setView(view);

	window->draw(greyScreen);
	window->draw(gameOverTitle);
	window->draw(tryAgainButton);
	window->draw(mainMenuButton);
	window->draw(tryAgainButtonText);
	window->draw(mainMenuButtonText);


	window->display();
}

void Menu::nameUpdate(std::vector<sf::Event> events)
{
	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	if (confirmButton.getGlobalBounds().contains(screenPos) &&
		enteredName != "")
	{
		confirmButtonText.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));
		confirmButtonText.setCharacterSize(buttonTextSize * 1.5);
		confirmButton.setScale(1.2f, 1.2f);
		confirmButton.setFillColor(sf::Color::White);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3f)
		{
			start = true;
			states = PLAY;
			transitionDebounce = 0;
		}
	}
	else
	{
		if (enteredName == "")
		{
			confirmButtonText.setFillColor(sf::Color(191.25f, 191.25f, 191.25f, 255.f));
			confirmButton.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
		}
		else
		{
			confirmButtonText.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));
			confirmButton.setFillColor(sf::Color::White);
		}

		confirmButtonText.setCharacterSize(buttonTextSize);
		confirmButton.setScale(1.f, 1.f);
	}

	if (backButton_2.getGlobalBounds().contains(screenPos))
	{
		backButtonText_2.setCharacterSize(buttonTextSize * 1.5);
		backButton_2.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3f)
		{
			states = MENU;
			transitionDebounce = 0;
		}
	}
	else
	{
		backButtonText_2.setCharacterSize(buttonTextSize);
		backButton_2.setScale(1.f, 1.f);
	}

	//NAME TYPING
	for (int i = 0; i < events.size(); i++)
	{
		if (events[i].type == sf::Event::TextEntered &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (events[i].text.unicode == 32 && enteredName.length() < 10)
			{
				enteredName += static_cast<char>(95);
			}
			if (events[i].text.unicode == 8 && enteredName.length() > 0)
			{
				enteredName.erase(enteredName.length() - 1);
			}
			else if (events[i].text.unicode < 128 && enteredName.length() < 10 &&
				events[i].text.unicode != 8 && (events[i].text.unicode < 48 ||
					events[i].text.unicode > 57))
			{
				name.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));
				enteredName += static_cast<char>(events[i].text.unicode);
			}
		}
	}
	if (enteredName == "")
	{
		name.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));
		cursor.setFillColor(sf::Color::Transparent);
		name.setString("ENTER  YOUR  NAME");
	}
	if (cursorBlinking < 0.75f &&
		enteredName.length() < 8)
	{
		name.setString(enteredName);
		cursor.setFillColor(sf::Color::Transparent);
	}
	if (cursorBlinking >= 0.75f &&
		enteredName.length() < 15)
	{
		name.setString(enteredName);
		cursor.setFillColor(sf::Color(140.f, 100.f, 54.f, 255.f));
	}
	if (cursorBlinking >= 1.5f)
		cursorBlinking = 0;


	backButton_2.setSize({ 275.f, 75.f });
	backButton_2.setOrigin(backButton_2.getLocalBounds().width / 2,
		backButton_2.getLocalBounds().height / 2);

	backButtonText_2.setOrigin(backButtonText_2.getLocalBounds().width / 2,
		backButtonText_2.getLocalBounds().height - 8);


	confirmButton.setOrigin(confirmButton.getLocalBounds().width / 2,
		confirmButton.getLocalBounds().height / 2);
	confirmButtonText.setOrigin(confirmButtonText.getLocalBounds().width / 2,
		confirmButtonText.getLocalBounds().height - 8);

	name.setOrigin(name.getLocalBounds().width / 2,
		0);
	name.setPosition(view.getCenter().x, view.getCenter().y - 70);
	cursor.setPosition(view.getCenter().x + name.getLocalBounds().width / 2, view.getCenter().y - 70);

	nameFrame.setPosition(view.getCenter());
	confirmButton.setPosition(view.getCenter().x - 160, view.getCenter().y + 50);
	backButton_2.setPosition(view.getCenter().x + 160, view.getCenter().y + 50);
	backButtonText_2.setPosition(backButton_2.getPosition());
	confirmButtonText.setPosition(confirmButton.getPosition());
}

void Menu::nameRender()
{
	window->setView(view);

	window->draw(greyScreen);
	window->draw(nameFrame);

	window->draw(confirmButton);
	window->draw(confirmButtonText);
	window->draw(backButton_2);
	window->draw(backButtonText_2);

	window->draw(name);
	window->draw(cursor);

	window->display();
}

void Menu::helpUpdate()
{
	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	if (backButton.getGlobalBounds().contains(screenPos))
	{
		backButtonText.setCharacterSize(buttonTextSize * 1.5);
		backButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			transitionDebounce >= 0.3)
		{
			states = MENU;
			transitionDebounce = 0;
		}
	}
	else
	{
		backButtonText.setCharacterSize(buttonTextSize);
		backButton.setScale(1.f, 1.f);
	}

	backButtonText.setOrigin(backButtonText.getLocalBounds().width / 2,
		backButtonText.getLocalBounds().height - 8);

	backButton.setPosition(view.getCenter().x, view.getCenter().y + 350);
	backButtonText.setPosition(backButton.getPosition());

	helpFrame.setPosition(view.getCenter().x, view.getCenter().y - 80);
}

void Menu::helpRender()
{
	window->draw(greyScreen);
	window->draw(helpFrame);
	window->draw(backButton);
	window->draw(backButtonText);

	window->display();
}

void Menu::mainMenuRenderComponent()
{
	window->clear();
	window->setView(view);

	window->draw(mainBackground);
	window->draw(myName);
	window->draw(title);

	window->draw(playButton);
	window->draw(leaderBoardButton);
	window->draw(exitButton);

	window->draw(playButtonText);
	window->draw(leaderBoardButtonText);
	window->draw(exitButtonText);
}
