#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

// 단어 목록
std::vector<std::string> words = {"HELLO", "WORLD", "COMPUTER", "PROGRAMMING", "GAMES"};

// 랜덤으로 단어 선택
std::string getRandomWord() {
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

// 행맨 게임 함수
void playHangman() {
    std::string targetWord = getRandomWord(); // 선택된 단어
    std::string guessedLetters(targetWord.length(), '_'); // 사용자에게 보여질 단어

    int attempts = 0;
    const int maxAttempts = 6; // 최대 시도 횟수

    while (attempts < maxAttempts) {
        std::cout << "Guess the word: " << guessedLetters << std::endl;
        char guess;
        std::cout << "Enter a letter: ";
        std::cin >> guess;

        bool found = false;
        for (size_t i = 0; i < targetWord.length(); ++i) {
            if (targetWord[i] == toupper(guess)) {
                guessedLetters[i] = targetWord[i];
                found = true;
            }
        }

        if (!found) {
            attempts++;
            std::cout << "Incorrect guess. Attempts left: " << maxAttempts - attempts << std::endl;
        }

        // 모든 글자를 맞췄는지 확인
        if (guessedLetters == targetWord) {
            std::cout << "Congratulations! You guessed the word: " << targetWord << std::endl;
            return;
        }
    }

    std::cout << "Out of attempts! The word was: " << targetWord << std::endl;
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        playHangman();

        std::cout << "Play Again? (y/n): ";
        std::cin >> playAgain;
    }

    return 0;
}
