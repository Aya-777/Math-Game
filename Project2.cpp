#include<bits/stdc++.h>
using namespace std; 

int ReadPositiveNumber(string msg){

  int n=0;
  do {
    cout << msg << "\n";
    cin>>n;
  } while(n<=0);

  return n;
}

int RandomNumber(int From, int To){

  return (rand() % (To-From+1)+From);
}

int ReadNumber(string msg){

  int n;
  cout << msg << "\n";
  cin>>n;
  return n;

}

enum enComplexity{EASY=1,MED=2,HARD=3,MIX=4};
enum enQuestionType{ADD=1,SUB=2,MUL=3,DIV=4,MIXQ=5};

struct stQuestionInfo{
  int n1=0;
  int n2=0;
  enComplexity cmp;
  enQuestionType op;
  int correctAns;
  int playerAns;
  bool correct = false;
};

struct QuizInfo{
    stQuestionInfo QuestionList[100];
    int numOfQ;
    enComplexity comp;
    enQuestionType type;
    int numberOfRightAnswers=0;
    int numberOfWrongAnswers=0;
    bool Pass = false;
};

char GetOperation(QuizInfo quiz){

    switch (quiz.type)
    {
    case enQuestionType::ADD :
        return '+';
    case enQuestionType::SUB :
        return '-';
    case enQuestionType::MUL :
        return '*';
    case enQuestionType::DIV :
        return '/';
    case enQuestionType::MIXQ :
        return '#';
  }
  return '+';
}
  
void PrintFinalGameResult(QuizInfo quiz){
  
    cout << "-----------------------------------------\n";
    cout << "The Number of Questions: " << quiz.numOfQ << endl;
    cout << "The Complexity of Questions: " << quiz.comp << endl;
    cout << "The operation u chose: " << quiz.type << endl;
    cout << "The number of wrong answers: " << quiz.numberOfWrongAnswers << endl;
    cout << "The number of right answers: " << quiz.numberOfRightAnswers << endl;
    cout <<"---------------------------\n";
    cout << "The Final result is: ";
    if(quiz.Pass){
      cout << "Pass.";
    }else{
      cout << "Fail.";
    }
    cout << endl;
  
  } 

void CalculateResult(QuizInfo& quiz){

    for (stQuestionInfo q : quiz.QuestionList)
    {
      if(q.correct){
        quiz.numberOfRightAnswers++;
      }
    }
    quiz.numberOfWrongAnswers = quiz.numOfQ-quiz.numberOfRightAnswers;

    if(quiz.numberOfRightAnswers>=quiz.numberOfWrongAnswers){
      quiz.Pass = true;
    }
    
    
    
  }

bool CheckAnswer(QuizInfo quiz , stQuestionInfo question){

    char op = GetOperation(quiz);
    switch (op)
    {
    case '+':
        if((question.n1+question.n2) == question.playerAns)
            return true;
    case '-':
        if((question.n1-question.n2) == question.playerAns)
            return true;
    case '*':
        if((question.n1*question.n2) == question.playerAns)
            return true;
    case '/':
        if((question.n1/question.n2) == question.playerAns)
            return true;
    }

    return false;

}

stQuestionInfo PoseQuestion(QuizInfo quiz){

    stQuestionInfo question;
  
      if(quiz.comp == enComplexity::MIX){
        quiz.comp = (enComplexity)RandomNumber(1,3);
      }
      if(quiz.type == enQuestionType::MIXQ){
        quiz.type=(enQuestionType)RandomNumber(1,4);
      }
  
      switch (quiz.comp)
      {
      case enComplexity::EASY :
          question.n1 = RandomNumber(1,9);
          question.n2 = RandomNumber(1,9);
          break;
  
      case enComplexity::MED :
          question.n1 = RandomNumber(10,50);
          question.n2 = RandomNumber(10,50);
          break;
  
      case enComplexity::HARD :
          question.n1 = RandomNumber(50,100);
          question.n2 = RandomNumber(50,100);
          break;
  
      case enComplexity::MIX :
          question.n1 = RandomNumber(1,200);
          question.n2 = RandomNumber(1,200);
          break;
      
      default:
          break;
      }
      
  
      cout << question.n1 << "\n" << question.n2 << "   " << GetOperation(quiz) << "\n";
      cout << "_____________";
  
      question.playerAns = ReadNumber("");
      if(CheckAnswer(quiz,question)){
        question.correct=true;
      }
      return question;
      
  
    }

QuizInfo FillGameInfo(){

  QuizInfo QuizInfo; 

  QuizInfo.numOfQ = ReadPositiveNumber("Enter the number of questions u want to answer.");
  QuizInfo.comp = (enComplexity)ReadPositiveNumber("Enter Question Level:\n[1] Easy, [2] Med, [3] Hard, [4] Mix");
  QuizInfo.type = (enQuestionType)ReadPositiveNumber("Enter Question Type:\n[1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix");

  return QuizInfo;
}

void StartMathGame(){

    QuizInfo quiz = FillGameInfo();
    
    for (int i = 0 ; i < quiz.numOfQ ; i++)
    {
      cout <<"-----------------------------\n";
      cout << "Question["<< i+1 <<"] : \n";
      quiz.QuestionList[i] = PoseQuestion(quiz); 
    }
      
    CalculateResult(quiz);
    PrintFinalGameResult(quiz);

}

void ResetScreen(){
  // system("cls");
  // system("color 0F");
}

void StartGame(){
  char playagain='y';
  do{
    ResetScreen();
    StartMathGame();
    cout << "Do u want to play again?";
    cin >> playagain;

  }  while (playagain=='y' || playagain=='Y');
  
}

int main(){

  StartGame();

}