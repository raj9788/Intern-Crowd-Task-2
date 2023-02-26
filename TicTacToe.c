#include <stdio.h>

#define BOARD_SIZE 3
#define MAX_NAME_LENGTH 15
char board[BOARD_SIZE][BOARD_SIZE];
char player1Name[MAX_NAME_LENGTH], player2Name[MAX_NAME_LENGTH];

void initialize_board()
{

    int k = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = k + '0';
            k++;
        }
    }
}

void print_board()
{
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1)
        {
            printf("-----------\n");
        }
    }
    printf("\n");
}

int check_win(char symbol)
{
    // check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
        {
            return 1;
        }
    }
    // check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
        {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    {
        return 1;
    }
    return 0;
}

int is_board_full()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] != 'X' || board[i][j] != 'O')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int row, col, player = 1;
    char symbol = 'X';
    int input;
    char winner[MAX_NAME_LENGTH];

    printf("Enter Player 1's Name :: ");
    scanf("%s", &player1Name);
    printf("Enter Player 2's Name :: ");
    scanf("%s", &player2Name);

    printf("%s is X\n", player1Name);
    printf("%s is O\n", player2Name);
    initialize_board();

    while (1)
    {
        print_board();

        // get input from current player
        if (symbol == 'X')
        {
            printf("Enter the Matrix number %s :: ", player1Name);
        }
        else
        {
            printf("Enter the Matrix number %s :: ", player2Name);
        }
        scanf("%d", &input);
        // check if input is valid
        if (input > 8 || input < 0)
        {
            printf("Invalid Input\n");
        }
        col = input % 3 + 1;
        row = input / 3 + 1;
        if (board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O')
        {
            printf("Position already occupied, try again.\n");
            continue;
        }

        // set symbol for current player and update board
        if (player == 1)
        {
            player++;
            symbol = 'X';
        }
        else
        {
            player--;
            symbol = 'O';
        }
        board[row - 1][col - 1] = symbol;

        // check for win or tie
        if (check_win(symbol))
        {
            if (symbol == 'X')
            {
                printf("Player %s wins!\n", player1Name);
            }
            else
            {
                printf("Player %s wins!\n", player2Name);
            }
            print_board();
            break;
        }
        else if (is_board_full())
        {
            printf("Its a Tie\n");
            print_board;
            break;
        }
    }
}