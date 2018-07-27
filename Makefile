##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## This is the Makefile
##

SRC_DIR	=	$(realpath ./SRC)
SRC_DIR_GAME =	$(SRC_DIR)/game

SRC	=	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/Arcade.cpp \
		$(SRC_DIR)/AException.cpp \
		$(SRC_DIR)/AObject.cpp \
		$(SRC_DIR)/Data.cpp \
		$(SRC_DIR)/MainGui.cpp \
		$(SRC_DIR)/LLoader.cpp \
		$(SRC_DIR)/Background.cpp \
		$(SRC_DIR)/GameTitle.cpp \
		$(SRC_DIR)/LibTitle.cpp \
		$(SRC_DIR)/ArcadeTitle.cpp \
		$(SRC_DIR)/GameThumbnail.cpp \
		$(SRC_DIR)/Score.cpp \
		$(SRC_DIR)/LeftArrow.cpp \
		$(SRC_DIR)/RightArrow.cpp \
		$(SRC_DIR)/PlayerName.cpp \
		$(SRC_DIR)/maxScore.cpp \
		$(SRC_DIR)/currentPlayer.cpp

SRC_LIB_SDL	=	$(SRC_DIR)/GUISDL.cpp \
			$(SRC_DIR)/AObject.cpp \
			$(SRC_DIR)/Data.cpp \
			$(SRC_DIR)/AException.cpp

SRC_LIB_NCURSES	=	$(SRC_DIR)/GuiNcurses.cpp \
			$(SRC_DIR)/AObject.cpp \
			$(SRC_DIR)/Data.cpp \
			$(SRC_DIR)/AException.cpp

SRC_LIB_SFML 	=       $(SRC_DIR)/GuiSfml.cpp \
                        $(SRC_DIR)/AObject.cpp \
                        $(SRC_DIR)/Data.cpp \
                        $(SRC_DIR)/AException.cpp

SRC_SOUND_SFML 	=	$(SRC_DIR)/sound/SoundSfml.cpp \
			$(SRC_DIR)/AException.cpp

SRC_LIB_SNAKE =  		$(SRC_DIR_GAME)/snake/Board.cpp \
				$(SRC_DIR_GAME)/snake/Food.cpp \
				$(SRC_DIR_GAME)/snake/SnakeBody.cpp \
				$(SRC_DIR_GAME)/snake/SnakeGame.cpp \
				$(SRC_DIR_GAME)/snake/SnakeHead.cpp \
				$(SRC_DIR_GAME)/snake/GameOver.cpp \
				$(SRC_DIR)/AObject.cpp \
				$(SRC_DIR_GAME)/snake/ScoreNibbler.cpp \
				$(SRC_DIR)/AException.cpp \
				$(SRC_DIR)/Data.cpp

SRC_LIB_PM 	=  		$(SRC_DIR_GAME)/pacman/Ghost.cpp \
				$(SRC_DIR_GAME)/pacman/PacBoard.cpp \
				$(SRC_DIR_GAME)/pacman/PacGame.cpp \
				$(SRC_DIR_GAME)/pacman/Pacman.cpp \
				$(SRC_DIR_GAME)/pacman/Block.cpp \
				$(SRC_DIR_GAME)/pacman/StartGame.cpp \
				$(SRC_DIR)/AObject.cpp \
				$(SRC_DIR)/AException.cpp \
				$(SRC_DIR)/Data.cpp \
				$(SRC_DIR_GAME)/pacman/Score.cpp \
				$(SRC_DIR_GAME)/pacman/Lives.cpp \
				$(SRC_DIR_GAME)/pacman/GameOver.cpp \
				$(SRC_DIR_GAME)/pacman/LivesTxt.cpp \
				$(SRC_DIR_GAME)/pacman/GameWin.cpp

SRC_LIB_QIX	=		$(SRC_DIR_GAME)/qix/Qix.cpp \
				$(SRC_DIR)/AObject.cpp \
				$(SRC_DIR)/Data.cpp \
				$(SRC_DIR)/BackgroundProcess.cpp

SRC_LIB_CENTIPEDE	=	$(SRC_DIR_GAME)/centipede/Centipede.cpp \
				$(SRC_DIR)/AObject.cpp \
				$(SRC_DIR)/Data.cpp \
				$(SRC_DIR)/BackgroundProcess.cpp

SRC_LIB_SOLARFOX	=		$(SRC_DIR_GAME)/solarfox/SolarFox.cpp \
				$(SRC_DIR)/AObject.cpp \
				$(SRC_DIR)/Data.cpp \
				$(SRC_DIR)/BackgroundProcess.cpp



OBJ	=	$(SRC:.cpp=.o)

NAME	=	arcade

LDFLAGS	=	-ldl

CXXFLAGS =	-g -Wall -Wextra -Werror -std=c++17 -I ./include

CC	=	g++

GAME =	lib_game

all:	graphicals games $(NAME)

core:	$(NAME) sound

games:	$(GAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

graphicals: sdl ncurses sfml

sound:
	$(CC) -c -fPIC $(SRC_SOUND_SFML) $(CXXFLAGS)
	$(CC) -shared -o lib_sound_sfml.so *.o -lsfml-system -lsfml-audio
	@rm *.o
	@mv lib_sound_sfml.so ./sound/

sdl:
	$(CC) -c -fPIC $(SRC_LIB_SDL) $(CXXFLAGS)
	@mv *.o ./SRC/
	$(CC) -shared -o lib_arcade_sdl.so $(SRC_LIB_SDL:.cpp=.o) -lSDL -lSDL_image -lSDL_ttf
	@if [ ! -d "lib" ]; then mkdir lib; fi
	@mv lib_arcade_sdl.so ./lib/

ncurses:
	$(CC) -c -fPIC $(SRC_LIB_NCURSES) $(CXXFLAGS)
	@mv *.o ./SRC/
	$(CC) -shared -o lib_arcade_ncurses.so $(SRC_LIB_NCURSES:.cpp=.o) -lncurses
	@if [ ! -d "lib" ]; then mkdir lib; fi
	@mv lib_arcade_ncurses.so ./lib

sfml:
	$(CC) -c -fPIC $(SRC_LIB_SFML) $(CXXFLAGS)
	@mv *.o ./SRC/
	$(CC) -shared -o lib_arcade_sfml.so $(SRC_LIB_SFML:.cpp=.o) -lsfml-window -lsfml-graphics -lsfml-system
	@if [ ! -d "lib" ]; then mkdir lib; fi
	@mv lib_arcade_sfml.so ./lib

snake:
	$(CC) -c -fPIC $(SRC_LIB_SNAKE) $(CXXFLAGS)
	$(CC) -shared -o lib_arcade_nibbler.so *.o
	@if [ ! -d "games" ]; then mkdir games; fi
	@mv lib_arcade_nibbler.so ./games/
	@rm *.o

pacman:
	$(CC) -c -fPIC $(SRC_LIB_PM) $(CXXFLAGS)
	$(CC) -shared -o lib_arcade_pacman.so *.o
	@if [ ! -d "games" ]; then mkdir games; fi
	@mv lib_arcade_pacman.so ./games/
	@rm *.o

qix:
	$(CC) -c -fPIC $(SRC_LIB_QIX) $(CXXFLAGS)
	$(CC) -shared -o lib_arcade_qix.so *.o
	@if [ ! -d "games" ]; then mkdir games; fi
	@mv lib_arcade_qix.so ./games/
	@rm *.o

centipede:
	$(CC) -c -fPIC $(SRC_LIB_CENTIPEDE) $(CXXFLAGS)
	$(CC) -shared -o lib_arcade_centipede.so *.o
	@if [ ! -d "games" ]; then mkdir games; fi
	@mv lib_arcade_centipede.so ./games/
	@rm *.o

solarfox:
	$(CC) -c -fPIC $(SRC_LIB_SOLARFOX) $(CXXFLAGS)
	$(CC) -shared -o lib_arcade_solarfox.so *.o
	@if [ ! -d "games" ]; then mkdir games; fi
	@mv lib_arcade_solarfox.so ./games/
	@rm *.o



$(GAME): snake pacman qix centipede solarfox

.PHONY:	clean	fclean
clean:
	@rm -rf *.o
	@rm -rf *~
	@rm -rf $(SRC_DIR)/*.o
	@rm -rf $(SRC_DIR)/*~
	@rm -rf $(SRC_DIR)/game/*.o
	@rm -rf $(SRC_DIR)/game/*~
	@rm -rf $(SRC_DIR)/sound/*.o
	@rm -rf $(SRC_DIR)/sound/*~
	@rm -rf $(SRC_DIR)/game/snake/*.o
	@rm -rf $(SRC_DIR)/game/snake/*~
	@rm -rf ./include/*~

fclean: clean
	@rm -f $(NAME)
	rm -f ./lib/*.so
	rm -f ./games/*.so

re: fclean all $(NAME)
