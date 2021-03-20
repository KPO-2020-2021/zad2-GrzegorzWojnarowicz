#include "Exam.h"

Exam::Exam() {
    this -> score = 0;
    this -> questionNum =0;
    this -> comExp = ComplexExp();
    this -> difficulty = EASY;
}

Exam::Exam(char difficulty) {
    this -> score = 0;
    this -> questionNum =0;
    this -> comExp = ComplexExp();
    if(difficulty != EASY && difficulty != HARD){
        throw std::invalid_argument("invalid dificulty");
    }else{
        this -> difficulty = difficulty;
    }
}

void Exam::setScore(int score) {
    this -> score = score;
}

void Exam::setDifficulty(char difficulty) {
    this -> difficulty = difficulty;
}

void Exam::setQuestionNum(int questionNum) {
    this -> questionNum = questionNum;
}

void Exam::setComExp(ComplexExp comExp) {
    this -> comExp = comExp;
}

bool operator==(const Exam &Exam1, const Exam &Exam2) {
    if ((Exam1.score == Exam2.score) && (Exam1.questionNum == Exam2.questionNum) &&
        (Exam1.comExp == Exam2.comExp) && (Exam1.difficulty == Exam2.difficulty)) {
        return true;
    }else{
        return false;
    }
}


void Exam::examLoop() {;
    std::string examFile;

    if(this -> difficulty == EASY){
        examFile = "easy.txt";
    }else if (this -> difficulty == HARD){
        examFile = "hard.txt";
    }else{
        throw std::invalid_argument("no difficulty selected");
    }


    std::stringstream sts;
    std::string tmp;
    std::ifstream myReadFile;
    myReadFile.open(examFile);
    if(myReadFile.is_open()){
        while(std::getline(myReadFile, tmp)){

            sts << tmp;
//            std::cout << tmp;
            sts >> (this -> comExp);
            std::cout << (this -> comExp) << std::endl;
        }
    }
    myReadFile.close();
}