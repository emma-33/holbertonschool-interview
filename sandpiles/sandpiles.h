#ifndef SANDPILES_H
#define SANDPILES_H

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
static void print_grid_sum(int grid1[3][3], int grid2[3][3]);
int helper_verify(int grid[3][3]);

#endif/* SANDPILES_H */