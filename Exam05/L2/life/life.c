/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:22:03 by kmaeda            #+#    #+#             */
/*   Updated: 2026/04/27 20:22:05 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct { int x, y, draw; } Pen;

char **create_board(int w, int h) {
    char **b = malloc(h * sizeof(char*));
    for (int i = 0; i < h; i++) {
        b[i] = malloc(w);
        for (int j = 0; j < w; j++)
            b[i][j] = 0;
    }
    return b;
}

int count_neighbors(char **b, int y, int x, int w, int h) {
    int c = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if ((dx || dy) &&  y + dy >= 0 && x + dx >= 0 && y + dy < h && x + dx < w
                && b[y + dy][x + dx] == 1)
                c++;
        }
    }
    return c;
}

void free_board(char **b, int h) {
    for (int i = 0; i < h; i++)
        free(b[i]);
    free(b);
}

void iter_game(char ***b, int w, int h) {
    char **nb = create_board(w, h);
    for (int  y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int n = count_neighbors(*b, y, x, w, h);
            if ((*b)[y][x] == 1 && (n == 2 || n == 3))
                nb[y][x] = 1;
            else if ((*b)[y][x] == 0 && n == 3)
                nb[y][x] = 1;
        }
    }
    free_board(*b, h);
    *b = nb;
}

void print_board(char **b, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (b[i][j])
                putchar('O');
            else
                putchar(' ');
        }
            
        putchar('\n');
    }
}

int main(int argc, char** argv) {
    if (argc != 4)
        return 1;
    int w = atoi(argv[1]), h = atoi(argv[2]), it = atoi(argv[3]);
    char **b = create_board(w, h), cmd;
    Pen p = {0, 0, 0};
    while (read(0, &cmd, 1) > 0) {
        if (cmd == 'w' && p.y > 0)
            p.y--;
        else if (cmd == 's' && p.y < h - 1)
            p.y++;
        else if (cmd == 'a' && p.x > 0)
            p.x--;
        else if (cmd == 'd' && p.x < w - 1)
            p.x++;
        else if (cmd == 'x')
            p.draw = !p.draw;
        if (p.draw && (cmd == 'w' || cmd == 's' || cmd == 'a' || cmd == 'd' || cmd == 'x'))
            b[p.y][p.x] = 1;
    }
    for (int i = 0; i < it; i++)
        iter_game(&b, w, h);
    print_board(b, w, h);
    free_board(b, h);
    return 0;
}
