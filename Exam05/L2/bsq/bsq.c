/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:38:18 by kmaeda            #+#    #+#             */
/*   Updated: 2026/04/27 09:42:18 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min3(int a, int b, int c){ return a < b && a < c ? a : b < c ? b : c; }

int parse_map(FILE *f, int *rows, char *empty, char *obst, char *full, char ***grid, int *cols){
    int r;
    char e, o, x, extra;
    if(fscanf(f, "%d %c %c %c\n", &r, &e, &o, &x) != 4|| r <= 0|| e == o || e == x || o == x || fscanf(f, " %c", &extra) == 1) 
        return -1;
    *rows = r; 
    *empty = e; 
    *obst = o; 
    *full = x;

    *grid = malloc(r * sizeof(char*)); 
    *cols = 0;
    char *line = NULL; 
    size_t capacity = 0;
    for (int i = 0; i < r ; i++) {
        ssize_t len = getline(&line, &capacity, f);
        if (len <= 0) { 
            free(line); 
            return -1;
        }
        if (i == 0) 
            *cols = (int)(len - 1); // exclude newline
        else if((int)(len - 1) != *cols) {
            free(line);
            return -1;
        }
        (*grid)[i] = malloc(*cols + 1);
        for(int j = 0; j < *cols; j++) {
            char c = line[j];
            if(c != *empty && c != *obst) {
                free(line); 
                return -1;
            }
            (*grid)[i][j] = c;
        }
        (*grid)[i][*cols] = '\0';
    }
    free(line);
    return 0;
}

void free_map(char **grid,int rows){ 
    for(int i = 0; i < rows; i++)
        free(grid[i]); 
    free(grid);
}

void solve(char **grid, int rows, int cols, char full, char obst) {
    int **dp = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) 
        dp[i] = calloc(cols, sizeof(int));
    int best = 0, bx = 0, by = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == obst) 
                dp[i][j] = 0;
            else if (i == 0 || j == 0) 
                dp[i][j] = 1;
            else 
                dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            if(dp[i][j] > best) {
                best = dp[i][j]; 
                bx = i;
                by = j;
            }
        }
    }

    for (int i = 0; i < best; i++) { // fill the biggest square
        for (int j = 0; j < best; j++)
            grid[bx - i][by - j] = full;
    }
    for (int i = 0; i < rows; i++) { // print result
        fputs(grid[i], stdout); 
        fputc('\n', stdout);
    }
    for (int i = 0; i < rows; i++)
        free(dp[i]);
    free(dp);
}

int process_file(const char *path) {
    FILE *f = strcmp(path, "-") == 0 ? stdin : fopen(path, "r");
    if (!f) {
        fputs("map error\n", stderr); 
        return -1;
    }
    int row, col; 
    char e, o, x; 
    char **grid;
    if (parse_map(f, &row, &e, &o, &x, &grid, &col) != 0) {
        fputs("map error\n", stderr); 
        if (f != stdin) {
            fclose(f); 
            return -1;
        }
    }
    solve(grid, row, col, x, o);
    free_map(grid, row);
    if(f! = stdin) 
        fclose(f);
    return 0;
}

int main(int argc, char **argv){
    if (argc < 2) {
        process_file("-");
        return 0;
    }
    for (int i = 1; i < argc; i++)
        process_file(argv[i]); 
    return 0;
}
