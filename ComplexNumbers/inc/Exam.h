#ifndef COMPLEX_NUMBER_EXAM_H
#define COMPLEX_NUMBER_EXAM_H
#include "ComplexExp.h"
#include <iostream>
#include <fstream>
#include <sstream>
const char EASY = 'e';
const char HARD = 'h';


class Exam {
private:
    int score;
    int questionNum;
    ComplexExp comExp;
    char difficulty;
public:
    Exam();
    Exam(char difficulty);
    friend bool operator==(const Exam &Exam1, const Exam &Exam2);
    void setScore(int score);
    void setDifficulty(char difficulty);
    void setQuestionNum(int questionNum);
    void setComExp(ComplexExp comExp);
    void examLoop();

};
#endif //COMPLEX_NUMBER_EXAM_H