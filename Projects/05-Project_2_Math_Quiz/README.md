# Math Quiz Game (C++)

A simple console-based Math Quiz Game written in C++.

The program generates random math questions based on the difficulty level and operation type selected by the player, then calculates the final score and displays the result.

## Features

- Choose the number of questions (1–10).
- Choose the difficulty level:
  - Easy
  - Medium
  - Hard
  - Mix
- Choose the operation type:
  - Addition
  - Subtraction
  - Multiplication
  - Division
  - Mixed Operations
- Random question generation.
- Instant feedback after each answer.
- Displays the correct answer when the player's answer is wrong.
- Final quiz summary:
  - Number of questions
  - Difficulty level
  - Operation type
  - Correct answers
  - Wrong answers
  - Pass / Fail result
- Option to play again.

## Project Structure

### Enums

- `enQuestionLevel`
- `enOperationType`

### Structures

#### `stQuestionInfo`

Stores information about a single question:

- First number
- Second number
- Operation
- Player answer
- Correct answer
- Whether the answer is correct

#### `stQuizInfo`

Stores the final quiz result:

- Number of questions
- Difficulty level
- Operation type
- Number of correct answers
- Number of wrong answers
- Pass/Fail status

## Main Functions

| Function | Description |
|----------|-------------|
| `randomnumber()` | Generates a random number within a given range. |
| `ReadNumberOfQuestions()` | Reads the number of quiz questions. |
| `ReadQuizLevel()` | Reads the selected difficulty level. |
| `ReadOpType()` | Reads the selected operation type. |
| `GetRandomNumberByLevel()` | Generates numbers according to the selected difficulty. |
| `simpleCalculator()` | Performs the arithmetic operation. |
| `FillQuestionInfo()` | Creates and prepares a quiz question. |
| `PrintQuestionInfo()` | Displays a question. |
| `FillQuiz()` | Builds the final quiz summary. |
| `PrintQuiz()` | Displays the final result. |
| `PlayQuiz()` | Runs the complete quiz. |
| `StartQuiz()` | Allows the user to replay the game. |

## Technologies Used

- C++
- Standard Library
- Console Application

## Sample Output

```text
How many Questions do you want to answer? 5

Enter Question Level:
1 - Easy
2 - Medium
3 - Hard
4 - Mix

Enter Operation Type:
1 - Add
2 - Subtract
3 - Multiply
4 - Divide
5 - Mix

Question [1/5]

7 + 3 = ?

10

Right Answer.
```

## Future Improvements

- Improve division questions to avoid decimal answers.
- Prevent division by zero.
- Color the console output.
- Show the percentage score.
- Display the time taken to complete the quiz.
- Save quiz history to a file.
- Improve the user interface.

## Author

**Omar Atef**
