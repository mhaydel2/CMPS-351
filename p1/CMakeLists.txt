cmake_minimum_required(VERSION 3.17)
project(test3)

set(CMAKE_CXX_STANDARD 14)

add_executable(test3 main.cpp Card.cpp Card.h Deck.cpp Deck.h Dealer.cpp Dealer.h Player.cpp Player.h ConvertCard.cpp ConvertCard.h)