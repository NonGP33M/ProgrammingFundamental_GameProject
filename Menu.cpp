#include "Menu.h"

Menu::Menu(sf::RenderWindow* window, sf::View view)
{
	font.loadFromFile("Font/Notalot60.ttf");

	buttonTextSize = 30;
	transitionDebounce = 400;

	greyScreen.setSize({ 1440.f, 900.f });
	greyScreen.setFillColor(sf::Color(0.f, 0.f, 0.f, 204.f));
	greyScreen.setOrigin(greyScreen.getSize().x / 2,
		greyScreen.getSize().y / 2);

	//MAIN_MENU
	title.setFont(font);
	title.setCharacterSize(128);
	title.setString("UNTITLED  TITLE");
	title.setFillColor(sf::Color::White);
	title.setOrigin(title.getLocalBounds().width / 2,
		title.getLocalBounds().height);

	playButtonText.setFont(font);
	playButtonText.setCharacterSize(buttonTextSize);
	playButtonText.setString("PLAY");
	playButtonText.setFillColor(sf::Color::White);

	leaderBoardButtonText.setFont(font);
	leaderBoardButtonText.setCharacterSize(buttonTextSize);
	leaderBoardButtonText.setString("LEADERBOARD");
	leaderBoardButtonText.setFillColor(sf::Color::White);

	exitButtonText.setFont(font);
	exitButtonText.setCharacterSize(buttonTextSize);
	exitButtonText.setString("EXIT");
	exitButtonText.setFillColor(sf::Color::White);

	playButton.setSize(buttonSize);
	playButton.setFillColor(sf::Color::Transparent);
	playButton.setOutlineColor(sf::Color::White);
	playButton.setOutlineThickness(1.f);
	playButton.setOrigin(playButton.getLocalBounds().width / 2,
		playButton.getLocalBounds().height / 2);

	leaderBoardButton.setSize(buttonSize);
	leaderBoardButton.setFillColor(sf::Color::Transparent);
	leaderBoardButton.setOutlineColor(sf::Color::White);
	leaderBoardButton.setOutlineThickness(1.f);
	leaderBoardButton.setOrigin(leaderBoardButton.getLocalBounds().width / 2,
		leaderBoardButton.getLocalBounds().height / 2);

	exitButton.setSize(buttonSize);
	exitButton.setFillColor(sf::Color::Transparent);
	exitButton.setOutlineColor(sf::Color::White);
	exitButton.setOutlineThickness(1.f);
	exitButton.setOrigin(exitButton.getLocalBounds().width / 2,
		exitButton.getLocalBounds().height / 2);

	//LEADERBOARD_MENU
	leaderBoardTitle.setFont(font);
	leaderBoardTitle.setCharacterSize(60);
	leaderBoardTitle.setString("LEADERBOARD");
	leaderBoardTitle.setFillColor(sf::Color::White);
	leaderBoardTitle.setOrigin(leaderBoardTitle.getLocalBounds().width / 2,
		leaderBoardTitle.getLocalBounds().height / 2);

	frame.setSize({ 800.f, 400.f });
	frame.setFillColor(sf::Color::Transparent);
	frame.setOutlineColor(sf::Color::White);
	frame.setOutlineThickness(1.f);
	frame.setOrigin(frame.getLocalBounds().width / 2,
		frame.getLocalBounds().top);

	backButtonText.setFont(font);
	backButtonText.setCharacterSize(buttonTextSize);
	backButtonText.setString("Back");
	backButtonText.setFillColor(sf::Color::White);

	backButton.setSize({ 150.f, 75.f });
	backButton.setFillColor(sf::Color::Transparent);
	backButton.setOutlineColor(sf::Color::White);
	backButton.setOutlineThickness(1.f);
	backButton.setOrigin(backButton.getLocalBounds().width / 2,
		backButton.getLocalBounds().height / 2);

	//PAUSE_MENU
	resumeButtonText.setFont(font);
	resumeButtonText.setCharacterSize(buttonTextSize);
	resumeButtonText.setString("Resume");
	resumeButtonText.setFillColor(sf::Color::White);

	mainMenuButtonText.setFont(font);
	mainMenuButtonText.setCharacterSize(buttonTextSize);
	mainMenuButtonText.setString("Main menu");
	mainMenuButtonText.setFillColor(sf::Color::White);

	resumeButton.setSize(buttonSize);
	resumeButton.setFillColor(sf::Color::Transparent);
	resumeButton.setOutlineColor(sf::Color::White);
	resumeButton.setOutlineThickness(1.f);
	resumeButton.setOrigin(resumeButton.getLocalBounds().width / 2,
		resumeButton.getLocalBounds().height / 2);

	mainMenuButton.setSize(buttonSize);
	mainMenuButton.setFillColor(sf::Color::Transparent);
	mainMenuButton.setOutlineColor(sf::Color::White);
	mainMenuButton.setOutlineThickness(1.f);
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
	tryAgainButtonText.setFillColor(sf::Color::White);


	tryAgainButton.setSize(buttonSize);
	tryAgainButton.setFillColor(sf::Color::Transparent);
	tryAgainButton.setOutlineColor(sf::Color::White);
	tryAgainButton.setOutlineThickness(1.f);
	tryAgainButton.setOrigin(tryAgainButton.getLocalBounds().width / 2,
		tryAgainButton.getLocalBounds().height / 2);

	//NAME
	nameFrame.setSize({ 800.f, 250.f });
	nameFrame.setFillColor(sf::Color::Transparent);
	nameFrame.setOutlineColor(sf::Color::White);
	nameFrame.setOutlineThickness(1.f);
	nameFrame.setOrigin(nameFrame.getLocalBounds().width / 2,
		nameFrame.getLocalBounds().height / 2);

	nameFill.setSize({ 700.f, 75.f });
	nameFill.setFillColor(sf::Color::Transparent);
	nameFill.setOutlineColor(sf::Color::White);
	nameFill.setOutlineThickness(1.f);
	nameFill.setOrigin(nameFill.getLocalBounds().width / 2,
		nameFill.getLocalBounds().height / 2);

	confirmButton.setSize({ 275.f, 75.f });
	confirmButton.setFillColor(sf::Color::Transparent);
	confirmButton.setOutlineColor(sf::Color::White);
	confirmButton.setOutlineThickness(1.f);

	confirmButtonText.setFont(font);
	confirmButtonText.setCharacterSize(buttonTextSize);
	confirmButtonText.setString("Confirm");
	confirmButtonText.setFillColor(sf::Color::White);

	name.setFont(font);
	name.setCharacterSize(buttonTextSize);
	name.setFillColor(sf::Color::White);



	this->window = window;
	this->view = view;
}

void Menu::nameReset()
{
	if(enteredName != "")
		score.writeFile(enteredName, playerScore);
	enteredName = "";
	playerScore = 0;
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
			debounce.getElapsedTime().asMilliseconds() >= transitionDebounce)
		{
			states = NAME;
			debounce.restart();
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
			debounce.getElapsedTime().asMilliseconds() >= transitionDebounce)
		{
			states = LEADERBOARD;
			debounce.restart();
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
			debounce.getElapsedTime().asMilliseconds() >= transitionDebounce)
			window->close();
	}
	else
	{
		exitButtonText.setCharacterSize(buttonTextSize);
		exitButton.setScale(1.f, 1.f);
	}


	playButtonText.setOrigin(playButtonText.getLocalBounds().width / 2,
		playButtonText.getLocalBounds().height - 8);
	leaderBoardButtonText.setOrigin(leaderBoardButtonText.getLocalBounds().width / 2,
		leaderBoardButtonText.getLocalBounds().height - 8);
	exitButtonText.setOrigin(exitButtonText.getLocalBounds().width / 2,
		exitButtonText.getLocalBounds().height - 8);

	title.setPosition(view.getCenter().x, view.getCenter().y - 200);

	playButton.setPosition(view.getCenter().x, view.getCenter().y + 100);
	leaderBoardButton.setPosition(view.getCenter().x, view.getCenter().y + 200);
	exitButton.setPosition(view.getCenter().x, view.getCenter().y + 300);

	playButtonText.setPosition(playButton.getPosition());
	leaderBoardButtonText.setPosition(leaderBoardButton.getPosition());
	exitButtonText.setPosition(exitButton.getPosition());


}

void Menu::mainMenuRender()
{
	window->clear();
	window->setView(view);

	window->draw(title);
	window->draw(playButtonText);
	window->draw(leaderBoardButtonText);
	window->draw(exitButtonText);
	window->draw(playButton);
	window->draw(leaderBoardButton);
	window->draw(exitButton);

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
			debounce.getElapsedTime().asMilliseconds() >= transitionDebounce)
		{
			states = MENU;
			debounce.restart();
		}
	}
	else
	{
		backButtonText.setCharacterSize(buttonTextSize);
		backButton.setScale(1.f, 1.f);
	}

	backButtonText.setOrigin(backButtonText.getLocalBounds().width / 2,
		backButtonText.getLocalBounds().height - 8);

	backButton.setPosition(view.getCenter().x, view.getCenter().y + 200);
	backButtonText.setPosition(backButton.getPosition());
}

void Menu::leaderBoardMenuRender()
{
	window->clear();

	window->setView(view);

	window->draw(leaderBoardTitle);
	window->draw(frame);
	window->draw(backButton);
	window->draw(backButtonText);

	score.render(*window, view);

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
			debounce.getElapsedTime().asMilliseconds() >= transitionDebounce)
		{
			states = PLAY;
			debounce.restart();
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
			debounce.getElapsedTime().asMilliseconds() >= transitionDebounce)
		{
			states = MENU;
			nameReset();
			debounce.restart();
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
	window->draw(mainMenuButtonText);
	window->draw(resumeButtonText);
	window->draw(resumeButton);
	window->draw(mainMenuButton);

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
			debounce.getElapsedTime().asMilliseconds() >= transitionDebounce)
		{
			tryAgainClick = true;
			debounce.restart();
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
			debounce.getElapsedTime().asMilliseconds() >= transitionDebounce)
		{
			states = MENU;
			nameReset();
			debounce.restart();
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
	window->draw(tryAgainButtonText);
	window->draw(tryAgainButton);
	window->draw(mainMenuButtonText);
	window->draw(mainMenuButton);

	window->display();
}

void Menu::nameUpdate(sf::Event& event)
{
	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	if (confirmButton.getGlobalBounds().contains(screenPos) && 
		enteredName != "")
	{
		confirmButtonText.setCharacterSize(buttonTextSize * 1.5);
		confirmButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			debounce.getElapsedTime().asMilliseconds() >= transitionDebounce)
		{
			states = PLAY;
			debounce.restart();
		}
	}
	else
	{
		if (enteredName == "")
			confirmButtonText.setFillColor(sf::Color( 128.f, 128.f, 128.f, 255.f ));
		else
			confirmButtonText.setFillColor(sf::Color::White);

			confirmButtonText.setCharacterSize(buttonTextSize);
			confirmButton.setScale(1.f, 1.f);
	}

	if (backButton.getGlobalBounds().contains(screenPos))
	{
		backButtonText.setCharacterSize(buttonTextSize * 1.5);
		backButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			debounce.getElapsedTime().asMilliseconds() >= transitionDebounce)
		{
			states = MENU;
			enteredName = "";
			debounce.restart();
		}
	}
	else
	{
		backButtonText.setCharacterSize(buttonTextSize);
		backButton.setScale(1.f, 1.f);
	}

	//NAME TYPING

	if (event.type == sf::Event::KeyReleased)
		enableToType = true;
	if (event.type == sf::Event::TextEntered &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) &&
		event.text.unicode != 32)
	{
		if (event.text.unicode == 8 && enteredName.length() > 0 &&
			enableToType)
		{
			enteredName.erase(enteredName.length() - 1);
			enableToType = false;
		}
		else if (event.text.unicode < 128 && enteredName.length() < 15 &&
			event.text.unicode != 8 && enableToType && (event.text.unicode < 48 ||
			event.text.unicode > 57))
		{
			enteredName += static_cast<char>(event.text.unicode);
			enableToType = false;
		}
	}
	if (enteredName == "")
		name.setString("ENTER  YOUR  NAME");
	else if (static_cast<int>(KeyClock.getElapsedTime().asMilliseconds()) % 1500 <= 750 &&
		enteredName.length() < 15)
		name.setString(enteredName + "|");
	else
		name.setString(enteredName);

	backButton.setSize({ 275.f, 75.f });
	backButton.setOrigin(backButton.getLocalBounds().width / 2,
		backButton.getLocalBounds().height / 2);
	backButtonText.setOrigin(backButtonText.getLocalBounds().width / 2,
		backButtonText.getLocalBounds().height - 8);

	confirmButton.setOrigin(confirmButton.getLocalBounds().width / 2,
		confirmButton.getLocalBounds().height / 2);
	confirmButtonText.setOrigin(confirmButtonText.getLocalBounds().width / 2,
		confirmButtonText.getLocalBounds().height - 8);

	name.setOrigin(name.getLocalBounds().width / 2,
		0);
	name.setPosition(view.getCenter().x, view.getCenter().y - 70);

	nameFrame.setPosition(view.getCenter());
	nameFill.setPosition(view.getCenter().x, view.getCenter().y - 50);
	confirmButton.setPosition(view.getCenter().x - 160, view.getCenter().y + 60);
	backButton.setPosition(view.getCenter().x + 160, view.getCenter().y + 60);
	backButtonText.setPosition(backButton.getPosition());
	confirmButtonText.setPosition(confirmButton.getPosition());
}

void Menu::nameRender()
{
	window->setView(view);

	window->draw(greyScreen);
	window->draw(nameFrame);
	window->draw(nameFill);

	window->draw(confirmButton);
	window->draw(confirmButtonText);
	window->draw(backButton);
	window->draw(backButtonText);

	window->draw(name);

	window->display();
}

void Menu::mainMenuRenderComponent()
{
	window->clear();
	window->setView(view);

	window->draw(title);
	window->draw(playButtonText);
	window->draw(leaderBoardButtonText);
	window->draw(exitButtonText);
	window->draw(playButton);
	window->draw(leaderBoardButton);
	window->draw(exitButton);
}
