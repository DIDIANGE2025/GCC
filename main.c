<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> da9d43e3771afcb46be65a9d74e901a554c18dc9
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(node_t ** head, int val) {
    node_t *previous, *current;

    if (*head == NULL) {
        return -1;
    }

    if ((*head)->val == val) {
        return pop(head);
    }

    previous = *head;
    current = (*head)->next;
    while (current) {
        if (current->val == val) {
            previous->next = current->next;
            free(current);
            return val;
        }

        previous = current;
        current  = current->next;
    }
    return -1;
}

void delete_list(node_t *head) {
    node_t  *current = head, 
            *next = head;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main(void) {
    node_t * test_list = (node_t *) malloc(sizeof(node_t));

    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
    delete_list(test_list);

    return EXIT_SUCCESS;
<<<<<<< HEAD
=======
#include <raylib.h>
#include <stdlib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define CELL_SIZE 20
#define MAX_SNAKE_LENGTH 1000

typedef struct {
    int x, y;
} Vector2i;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game Custom");
    SetTargetFPS(10);

    // Audio
    InitAudioDevice();
    Music music = LoadMusicStream("omalay.mp3");
    PlayMusicStream(music);

    // Textures
    Texture2D ballTexture = LoadTexture("ball.png");
    Texture2D characterTexture = LoadTexture("character.png");

    // Snake initialization
    Vector2i snake[MAX_SNAKE_LENGTH];
    int snakeLength = 3;
    Vector2i direction = {1, 0};

    for (int i = 0; i < snakeLength; i++) {
        snake[i].x = 10 - i;
        snake[i].y = 10;
    }

    // Fruit (ball)
    Vector2i fruit = {
        GetRandomValue(0, SCREEN_WIDTH / CELL_SIZE - 1),
        GetRandomValue(0, SCREEN_HEIGHT / CELL_SIZE - 1)
    };

    bool gameOver = false;
    bool gameStarted = false;
    int score = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        UpdateMusicStream(music);

        if (!gameStarted) {
            DrawText("SNAKE GAME", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 50, 30, GREEN);
            DrawText("Appuyez sur ENTREE pour commencer", SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2, 20, WHITE);
            if (IsKeyPressed(KEY_ENTER)) {
                gameStarted = true;
            }
            EndDrawing();
            continue;
        }

        if (!gameOver) {
            // Contrôles
            if (IsKeyPressed(KEY_UP) && direction.y == 0) direction = (Vector2i){0, -1};
            if (IsKeyPressed(KEY_DOWN) && direction.y == 0) direction = (Vector2i){0, 1};
            if (IsKeyPressed(KEY_LEFT) && direction.x == 0) direction = (Vector2i){-1, 0};
            if (IsKeyPressed(KEY_RIGHT) && direction.x == 0) direction = (Vector2i){1, 0};

            // Déplacement
            for (int i = snakeLength; i > 0; i--) {
                snake[i] = snake[i - 1];
            }
            snake[0].x += direction.x;
            snake[0].y += direction.y;

            // Collision avec fruit
            if (snake[0].x == fruit.x && snake[0].y == fruit.y) {
                snakeLength++;
                score += 10;
                fruit.x = GetRandomValue(0, SCREEN_WIDTH / CELL_SIZE - 1);
                fruit.y = GetRandomValue(0, SCREEN_HEIGHT / CELL_SIZE - 1);
            }

            // Collision avec mur
            if (snake[0].x < 0 || snake[0].x >= SCREEN_WIDTH / CELL_SIZE ||
                snake[0].y < 0 || snake[0].y >= SCREEN_HEIGHT / CELL_SIZE) {
                gameOver = true;
            }

            // Collision avec soi-même
            for (int i = 1; i < snakeLength; i++) {
                if (snake[i].x == snake[0].x && snake[i].y == snake[0].y) {
                    gameOver = true;
                    break;
                }
            }

            // Dessin ballon
            DrawTexture(ballTexture, fruit.x * CELL_SIZE, fruit.y * CELL_SIZE, WHITE);

            // Dessin bonhomme pour chaque segment
            for (int i = 0; i < snakeLength; i++) {
                DrawTexture(characterTexture, snake[i].x * CELL_SIZE, snake[i].y * CELL_SIZE, WHITE);
            }

            // Score
            DrawText(TextFormat("Score: %d", score), 10, 10, 20, YELLOW);

        } else {
            DrawText("GAME OVER", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 50, 40, RED);
            DrawText(TextFormat("Score: %d", score), SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2, 20, WHITE);
            DrawText("Appuyez sur Echapp pour quitter", SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 40, 20, GRAY);
        }

        EndDrawing();
    }

    // Libération des ressources
    UnloadTexture(ballTexture);
    UnloadTexture(characterTexture);
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();

    return 0;
>>>>>>> 0897f27 (jeux serpent)
=======
>>>>>>> da9d43e3771afcb46be65a9d74e901a554c18dc9
}
