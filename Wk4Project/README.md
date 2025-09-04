The Week 4 project is creating a game of 21. 21 is a popular card game where all players try to have a higher point value than the dealer without going over 21. Please don't hesitate with questions or comments. 

 

Functional Requirements

Each class interface and implementation must be in its own file.

Your program must meet the requirements defined below:

The program has a deck of cards that the dealer controls

Five players not including the dealer

The game must shuffle the deck of cards when the program starts and between each game

After each game the option is offered to play again or quit

At the start of each game each player, including the dealer, gets two cards.

Each player is asked if they want a card.

     If the player wants another card:

                 The card is moved from the top of the card deck into the player’s hand

     If the player’s hand is below 21:

          The player returns to “if player wants another card”

     If the player’s hand is 21 or above the dealer moves to the next player

     If the player does not want another card the dealer moves to the next player

After all five players have their hands the dealer will take the next card from the top of the deck until:

     The dealer has five cards in their hand that total 15 or less

     The dealer has 21 or greater

After the dealer gets their hand each player is evaluated for win loose or draw

     A player wins if:        

          They have more points than the dealer without going over 21

          The dealer goes over 21 any player that has 21 or less wins

     A player draws if:

          They have equal points as the dealer and has 21 or less

          If both the player and dealer have more than 21

     A player looses:

          If the dealer has five cards with a total of 15 or less

          If they go over 21 and the dealer has 21 or less

          If the player has less than the dealer and both are below 21   

 

Design Requirements

Class - card

            String – suit

            String – Face

            Decimal – value 

Class - CardDeck

     Has a one to many with type card

     52 total cards

     Suites: Diamonds, hearts, clubs and spades

     Face: Each suite will have cards 1 - 10, jack, queen, king and ace

     Value: The value of each card will be the same as the face with jack, queen, and king having a value of 10 and each ace can have a value of 1 or 11 

Class - Player

     String Name

     Array Hand – can hold up to ten cards

     Boolean - Canhit – This value is true until the value in PlayerCards for this player goes above 21

     Decimal - HandValue – totals the value of the cards in this player hand

Class Dealer – is a player

            This is the only player that can access CardDeck (e.g. has functions to deal and shuffle deck)

            The Boolean Canhit for dealer goes false if they have five cards with a total less than 15 or 21or above

Class Table

     Has a one to many with Players

     Has a Card Deck

     Has a Dealer

